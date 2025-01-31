/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#pragma ident	"@(#)dt_module.c	1.13	07/08/07 SMI"

#if !defined(__APPLE__)
#include <sys/types.h>
#include <sys/modctl.h>
#include <sys/kobj.h>
#include <sys/kobj_impl.h>
#include <sys/sysmacros.h>
#include <sys/elf.h>
#include <sys/task.h>

#include <unistd.h>
#include <project.h>
#include <strings.h>
#include <stdlib.h>
#include <libelf.h>
#include <limits.h>
#include <assert.h>
#include <errno.h>
#include <dirent.h>

#else /* is Apple Mac OS X */
#include <sys/types.h>
/* NOTHING */ /* In lieu of Solaris <sys/modctl.h> */
/* NOTHING */ /* In lieu of Solaris <sys/kobj.h> */
/* NOTHING */ /* In lieu of Solaris <sys/kobj_impl.h> */
/* NOTHING */ /* In lieu of Solaris <sys/sysmacros.h> */

#include <sys/stat.h>

#include "darwin_shim.h"
#include "elf.h" /* In lieu of Solaris <sys/elf.h> */
#include "decl.h"
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <mach-o/stab.h>

#include <fcntl.h>
#define stat64 stat
#define OBJFS_ROOT "/system/object"
	
/* NOTHING */ /* In lieu of Solaris <sys/task.h> */
#include <unistd.h>
/* NOTHING */ /* In lieu of Solaris <project.h> */
#include <strings.h>
#include <stdlib.h>
#include <libelf.h>
#include <limits.h>
#include <assert.h>
#include <errno.h>
#include <dirent.h>

#include <dtrace.h>

#endif /* __APPLE__ */

#include <dt_strtab.h>
#include <dt_module.h>
#include <dt_impl.h>

static const char *dt_module_strtab; /* active strtab for qsort callbacks */

static void
dt_module_symhash_insert(dt_module_t *dmp, const char *name, uint_t id)
{
	dt_sym_t *dsp = &dmp->dm_symchains[dmp->dm_symfree];
	uint_t h;

	assert(dmp->dm_symfree < dmp->dm_nsymelems + 1);

	dsp->ds_symid = id;
	h = dt_strtab_hash(name, NULL) % dmp->dm_nsymbuckets;
	dsp->ds_next = dmp->dm_symbuckets[h];
	dmp->dm_symbuckets[h] = dmp->dm_symfree++;
}

static uint_t
dt_module_syminit32(dt_module_t *dmp)
{
	const Elf32_Sym *sym = dmp->dm_symtab.cts_data;
	const char *base = dmp->dm_strtab.cts_data;
	size_t ss_size = dmp->dm_strtab.cts_size;
	uint_t i, n = dmp->dm_nsymelems;
	uint_t asrsv = 0;

	for (i = 0; i < n; i++, sym++) {
		const char *name = base + sym->st_name;
		uchar_t type = ELF32_ST_TYPE(sym->st_info);

		if (type >= STT_NUM || type == STT_SECTION)
			continue; /* skip sections and unknown types */

		if (sym->st_name == 0 || sym->st_name >= ss_size)
			continue; /* skip null or invalid names */

		if (sym->st_value != 0 &&
		    (ELF32_ST_BIND(sym->st_info) != STB_LOCAL || sym->st_size))
			asrsv++; /* reserve space in the address map */

		dt_module_symhash_insert(dmp, name, i);
	}

	return (asrsv);
}

static uint_t
dt_module_syminit64(dt_module_t *dmp)
{
	const Elf64_Sym *sym = dmp->dm_symtab.cts_data;
	const char *base = dmp->dm_strtab.cts_data;
	size_t ss_size = dmp->dm_strtab.cts_size;
	uint_t i, n = dmp->dm_nsymelems;
	uint_t asrsv = 0;

	for (i = 0; i < n; i++, sym++) {
		const char *name = base + sym->st_name;
		uchar_t type = ELF64_ST_TYPE(sym->st_info);

		if (type >= STT_NUM || type == STT_SECTION)
			continue; /* skip sections and unknown types */

		if (sym->st_name == 0 || sym->st_name >= ss_size)
			continue; /* skip null or invalid names */

		if (sym->st_value != 0 &&
		    (ELF64_ST_BIND(sym->st_info) != STB_LOCAL || sym->st_size))
			asrsv++; /* reserve space in the address map */

		dt_module_symhash_insert(dmp, name, i);
	}

	return (asrsv);
}

/*
 * Sort comparison function for 32-bit symbol address-to-name lookups.  We sort
 * symbols by value.  If values are equal, we prefer the symbol that is
 * non-zero sized, typed, not weak, or lexically first, in that order.
 */
static int
dt_module_symcomp32(const void *lp, const void *rp)
{
	Elf32_Sym *lhs = *((Elf32_Sym **)lp);
	Elf32_Sym *rhs = *((Elf32_Sym **)rp);

	if (lhs->st_value != rhs->st_value)
		return (lhs->st_value > rhs->st_value ? 1 : -1);

	if ((lhs->st_size == 0) != (rhs->st_size == 0))
		return (lhs->st_size == 0 ? 1 : -1);

	if ((ELF32_ST_TYPE(lhs->st_info) == STT_NOTYPE) !=
	    (ELF32_ST_TYPE(rhs->st_info) == STT_NOTYPE))
		return (ELF32_ST_TYPE(lhs->st_info) == STT_NOTYPE ? 1 : -1);

	if ((ELF32_ST_BIND(lhs->st_info) == STB_WEAK) !=
	    (ELF32_ST_BIND(rhs->st_info) == STB_WEAK))
		return (ELF32_ST_BIND(lhs->st_info) == STB_WEAK ? 1 : -1);

	return (strcmp(dt_module_strtab + lhs->st_name,
	    dt_module_strtab + rhs->st_name));
}

/*
 * Sort comparison function for 64-bit symbol address-to-name lookups.  We sort
 * symbols by value.  If values are equal, we prefer the symbol that is
 * non-zero sized, typed, not weak, or lexically first, in that order.
 */
static int
dt_module_symcomp64(const void *lp, const void *rp)
{
	Elf64_Sym *lhs = *((Elf64_Sym **)lp);
	Elf64_Sym *rhs = *((Elf64_Sym **)rp);

	if (lhs->st_value != rhs->st_value)
		return (lhs->st_value > rhs->st_value ? 1 : -1);

	if ((lhs->st_size == 0) != (rhs->st_size == 0))
		return (lhs->st_size == 0 ? 1 : -1);

	if ((ELF64_ST_TYPE(lhs->st_info) == STT_NOTYPE) !=
	    (ELF64_ST_TYPE(rhs->st_info) == STT_NOTYPE))
		return (ELF64_ST_TYPE(lhs->st_info) == STT_NOTYPE ? 1 : -1);

	if ((ELF64_ST_BIND(lhs->st_info) == STB_WEAK) !=
	    (ELF64_ST_BIND(rhs->st_info) == STB_WEAK))
		return (ELF64_ST_BIND(lhs->st_info) == STB_WEAK ? 1 : -1);

	return (strcmp(dt_module_strtab + lhs->st_name,
	    dt_module_strtab + rhs->st_name));
}

static void
dt_module_symsort32(dt_module_t *dmp)
{
	Elf32_Sym *symtab = (Elf32_Sym *)dmp->dm_symtab.cts_data;
	Elf32_Sym **sympp = (Elf32_Sym **)dmp->dm_asmap;
	const dt_sym_t *dsp = dmp->dm_symchains + 1;
	uint_t i, n = dmp->dm_symfree;

	for (i = 1; i < n; i++, dsp++) {
		Elf32_Sym *sym = symtab + dsp->ds_symid;
		if (sym->st_value != 0 &&
		    (ELF32_ST_BIND(sym->st_info) != STB_LOCAL || sym->st_size))
			*sympp++ = sym;
	}

	dmp->dm_aslen = (uint_t)(sympp - (Elf32_Sym **)dmp->dm_asmap);
	assert(dmp->dm_aslen <= dmp->dm_asrsv);

	dt_module_strtab = dmp->dm_strtab.cts_data;
	qsort(dmp->dm_asmap, dmp->dm_aslen,
	    sizeof (Elf32_Sym *), dt_module_symcomp32);
	dt_module_strtab = NULL;
}

static void
dt_module_symsort64(dt_module_t *dmp)
{
	Elf64_Sym *symtab = (Elf64_Sym *)dmp->dm_symtab.cts_data;
	Elf64_Sym **sympp = (Elf64_Sym **)dmp->dm_asmap;
	const dt_sym_t *dsp = dmp->dm_symchains + 1;
	uint_t i, n = dmp->dm_symfree;

	for (i = 1; i < n; i++, dsp++) {
		Elf64_Sym *sym = symtab + dsp->ds_symid;
		if (sym->st_value != 0 &&
		    (ELF64_ST_BIND(sym->st_info) != STB_LOCAL || sym->st_size))
			*sympp++ = sym;
	}

	dmp->dm_aslen = (uint_t)(sympp - (Elf64_Sym **)dmp->dm_asmap);
	assert(dmp->dm_aslen <= dmp->dm_asrsv);

	dt_module_strtab = dmp->dm_strtab.cts_data;
	qsort(dmp->dm_asmap, dmp->dm_aslen,
	    sizeof (Elf64_Sym *), dt_module_symcomp64);
	dt_module_strtab = NULL;
}

static GElf_Sym *
dt_module_symgelf32(const Elf32_Sym *src, GElf_Sym *dst)
{
	if (dst != NULL) {
		dst->st_name = src->st_name;
		dst->st_info = src->st_info;
		dst->st_other = src->st_other;
		dst->st_shndx = src->st_shndx;
		dst->st_value = src->st_value;
		dst->st_size = src->st_size;
	}

	return (dst);
}

static GElf_Sym *
dt_module_symgelf64(const Elf64_Sym *src, GElf_Sym *dst)
{
	if (dst != NULL)
		bcopy(src, dst, sizeof (GElf_Sym));

	return (dst);
}

static GElf_Sym *
dt_module_symname32(dt_module_t *dmp, const char *name,
    GElf_Sym *symp, uint_t *idp)
{
	const Elf32_Sym *symtab = dmp->dm_symtab.cts_data;
	const char *strtab = dmp->dm_strtab.cts_data;

	const Elf32_Sym *sym;
	const dt_sym_t *dsp;
	uint_t i, h;

	if (dmp->dm_nsymelems == 0)
		return (NULL);

	h = dt_strtab_hash(name, NULL) % dmp->dm_nsymbuckets;

	for (i = dmp->dm_symbuckets[h]; i != 0; i = dsp->ds_next) {
		dsp = &dmp->dm_symchains[i];
		sym = symtab + dsp->ds_symid;

		if (strcmp(name, strtab + sym->st_name) == 0) {
			if (idp != NULL)
				*idp = dsp->ds_symid;
			return (dt_module_symgelf32(sym, symp));
		}
	}

	return (NULL);
}

static GElf_Sym *
dt_module_symname64(dt_module_t *dmp, const char *name,
    GElf_Sym *symp, uint_t *idp)
{
	const Elf64_Sym *symtab = dmp->dm_symtab.cts_data;
	const char *strtab = dmp->dm_strtab.cts_data;

	const Elf64_Sym *sym;
	const dt_sym_t *dsp;
	uint_t i, h;

	if (dmp->dm_nsymelems == 0)
		return (NULL);

	h = dt_strtab_hash(name, NULL) % dmp->dm_nsymbuckets;

	for (i = dmp->dm_symbuckets[h]; i != 0; i = dsp->ds_next) {
		dsp = &dmp->dm_symchains[i];
		sym = symtab + dsp->ds_symid;

		if (strcmp(name, strtab + sym->st_name) == 0) {
			if (idp != NULL)
				*idp = dsp->ds_symid;
			return (dt_module_symgelf64(sym, symp));
		}
	}

	return (NULL);
}

static GElf_Sym *
dt_module_symaddr32(dt_module_t *dmp, GElf_Addr addr,
    GElf_Sym *symp, uint_t *idp)
{
	const Elf32_Sym **asmap = (const Elf32_Sym **)dmp->dm_asmap;
	const Elf32_Sym *symtab = dmp->dm_symtab.cts_data;
	const Elf32_Sym *sym;

	uint_t i, mid, lo = 0, hi = dmp->dm_aslen - 1;
	Elf32_Addr v;

	if (dmp->dm_aslen == 0)
		return (NULL);

	while (hi - lo > 1) {
		mid = (lo + hi) / 2;
		if (addr >= asmap[mid]->st_value)
			lo = mid;
		else
			hi = mid;
	}

	i = addr < asmap[hi]->st_value ? lo : hi;
	sym = asmap[i];
	v = sym->st_value;

	/*
	 * If the previous entry has the same value, improve our choice.  The
	 * order of equal-valued symbols is determined by the comparison func.
	 */
	while (i-- != 0 && asmap[i]->st_value == v)
		sym = asmap[i];

	if (addr - sym->st_value < MAX(sym->st_size, 1)) {
		if (idp != NULL)
			*idp = (uint_t)(sym - symtab);
		return (dt_module_symgelf32(sym, symp));
	}

	return (NULL);
}

static GElf_Sym *
dt_module_symaddr64(dt_module_t *dmp, GElf_Addr addr,
    GElf_Sym *symp, uint_t *idp)
{
	const Elf64_Sym **asmap = (const Elf64_Sym **)dmp->dm_asmap;
	const Elf64_Sym *symtab = dmp->dm_symtab.cts_data;
	const Elf64_Sym *sym;

	uint_t i, mid, lo = 0, hi = dmp->dm_aslen - 1;
	Elf64_Addr v;

	if (dmp->dm_aslen == 0)
		return (NULL);

	while (hi - lo > 1) {
		mid = (lo + hi) / 2;
		if (addr >= asmap[mid]->st_value)
			lo = mid;
		else
			hi = mid;
	}

	i = addr < asmap[hi]->st_value ? lo : hi;
	sym = asmap[i];
	v = sym->st_value;

	/*
	 * If the previous entry has the same value, improve our choice.  The
	 * order of equal-valued symbols is determined by the comparison func.
	 */
	while (i-- != 0 && asmap[i]->st_value == v)
		sym = asmap[i];

	if (addr - sym->st_value < MAX(sym->st_size, 1)) {
		if (idp != NULL)
			*idp = (uint_t)(sym - symtab);
		return (dt_module_symgelf64(sym, symp));
	}

	return (NULL);
}

static const dt_modops_t dt_modops_32 = {
	dt_module_syminit32,
	dt_module_symsort32,
	dt_module_symname32,
	dt_module_symaddr32
};

static const dt_modops_t dt_modops_64 = {
	dt_module_syminit64,
	dt_module_symsort64,
	dt_module_symname64,
	dt_module_symaddr64
};

#if defined(__APPLE__)
#include <libiberty/demangle.h>
__private_extern__ char * environ = ""; /* libiberty.a xmalloc wants this */

char 
*demangleSymbolCString(const char *mangled)
 {
     if(mangled[0]!='_') return NULL;
     if(mangled[1]=='_') mangled++; // allow either __Z or _Z prefix
     if(mangled[1]!='Z') return NULL;
     return cplus_demangle(mangled, 0);
 }

static uint_t
dt_module_syminit_macho(dt_module_t *dmp)
{
	const struct nlist *sym = (const struct nlist *)(dmp->dm_symtab.cts_data);
	const char *base = (const char *)dmp->dm_strtab.cts_data;
	uint_t i, n = dmp->dm_nsymelems;
	uint_t asrsv = 0;
	char *tmp;

	for (i = 0; i < n; i++, sym++) {
		const char *name = base + sym->n_un.n_strx;
		uchar_t type = sym->n_type & (N_TYPE | N_EXT);

        // Check that the symbol is a global and that it has a name.
        if (((N_SECT | N_EXT) != type && (N_ABS | N_EXT) != type))
            continue;
			
		if (STT_FUNC != sym->n_desc && STT_OBJECT != sym->n_desc)
			continue;
			
		if (0 == sym->n_un.n_strx) // iff a null, "", name.
			continue;

		if ((tmp = demangleSymbolCString(name)))
			name = tmp;

		if ('_' == name[0])
			name++; // Lop off omnipresent underscore to match DWARF convention
		
		if (sym->n_value != 0)
			asrsv++; /* reserve space in the address map */

		dt_module_symhash_insert(dmp, name, i);
	}

	return (asrsv);
}

static int
dt_module_symcomp_macho(const void *lp, const void *rp)
{
	struct nlist *lhs = *((struct nlist **)lp);
	struct nlist *rhs = *((struct nlist **)rp);

	if (lhs->n_value != rhs->n_value)
		return (lhs->n_value > rhs->n_value ? 1 : -1);

	if ((lhs->n_desc & N_WEAK_REF) != (rhs->n_desc & N_WEAK_REF))
		return ((lhs->n_desc & N_WEAK_REF) ? 1 : -1);

	return (strcmp(dt_module_strtab + lhs->n_un.n_strx,
	    dt_module_strtab + rhs->n_un.n_strx)); // Leading underscores compare equal so leave them be
}

static void
dt_module_symsort_macho(dt_module_t *dmp)
{
	struct nlist *symtab = (struct nlist *)(dmp->dm_symtab.cts_data);
	struct nlist **sympp = (struct nlist **)dmp->dm_asmap;
	const dt_sym_t *dsp = dmp->dm_symchains + 1;
	uint_t i, n = dmp->dm_symfree;

	for (i = 1; i < n; i++, dsp++) {
		struct nlist *sym = symtab + dsp->ds_symid;
		if (sym->n_value != 0)
			*sympp++ = sym;
	}

	dmp->dm_aslen = (uint_t)(sympp - (struct nlist **)dmp->dm_asmap);
	assert(dmp->dm_aslen <= dmp->dm_asrsv);

	dt_module_strtab = ((char *)(dmp->dm_symtab.cts_data)) + dmp->dm_symtab.cts_size;
	qsort(dmp->dm_asmap, dmp->dm_aslen,
	    sizeof (struct nlist *), dt_module_symcomp_macho);
	dt_module_strtab = NULL;
}

static GElf_Sym *
dt_module_symname_macho(dt_module_t *dmp, const char *name,
    GElf_Sym *symp, uint_t *idp)
{
	const struct nlist *symtab = (const struct nlist *)(dmp->dm_symtab.cts_data);
	const char *strtab = (const char *)dmp->dm_strtab.cts_data;

	const struct nlist *sym;
	const dt_sym_t *dsp;
	uint_t i, h;

	if (dmp->dm_nsymelems == 0)
		return (NULL);

	h = dt_strtab_hash(name, NULL) % dmp->dm_nsymbuckets;

	for (i = dmp->dm_symbuckets[h]; i != 0; i = dsp->ds_next) {
		dsp = &dmp->dm_symchains[i];
		sym = symtab + dsp->ds_symid;
		const char *sname = strtab + sym->n_un.n_strx;
		char *tmp;

		if ((tmp = demangleSymbolCString(sname)))
			sname = tmp;

		if ('_' == sname[0])
			sname++; // Lop off omnipresent underscore
			
		if (strcmp(name, sname) == 0) {
			if (idp != NULL)
				*idp = dsp->ds_symid;

			symp->st_name = (GElf_Sxword)(sname - strtab);
			symp->st_info = STT_NOTYPE; 
			symp->st_other = 0;
			symp->st_shndx = sym->n_sect;
			symp->st_value = sym->n_value;
			symp->st_size = 0;
			
			if (sym->n_type & N_STAB) { /* Detect C++ methods */
	
				switch(sym->n_type) { 
				case N_FUN:
					symp->st_info = GELF_ST_INFO((STB_GLOBAL), (STT_FUNC));
					break;
				case N_GSYM:
					symp->st_info = GELF_ST_INFO((STB_GLOBAL), (STT_OBJECT));
					break;
				default:
					break;
				}
		
			} else if ((N_ABS | N_EXT) == (sym->n_type & (N_TYPE | N_EXT)) ||
				(N_SECT | N_EXT) == (sym->n_type & (N_TYPE | N_EXT))) {

				symp->st_info = GELF_ST_INFO((STB_GLOBAL), (sym->n_desc)); 
			} else if ((N_UNDF | N_EXT) == (sym->n_type & (N_TYPE | N_EXT)) &&
						sym->n_sect == NO_SECT) {
				symp->st_info = GELF_ST_INFO((STB_GLOBAL), (STT_OBJECT)); /* Common */
			}
		
			return symp;
		}
	}

	return (NULL);
}

static GElf_Sym *
dt_module_symaddr_macho(dt_module_t *dmp, GElf_Addr addr,
    GElf_Sym *symp, uint_t *idp)
{
	const struct nlist **asmap = (const struct nlist **)dmp->dm_asmap;
	const struct nlist *symtab = (const struct nlist *)(dmp->dm_symtab.cts_data);
	const char *strtab = (const char *)dmp->dm_strtab.cts_data;
	const struct nlist *sym;

	uint_t i, mid, lo = 0, hi = dmp->dm_aslen - 1;
	Elf32_Addr v;

	if (dmp->dm_aslen == 0)
		return (NULL);

	while (hi - lo > 1) {
		mid = (lo + hi) / 2;
		if (addr >= asmap[mid]->n_value)
			lo = mid;
		else
			hi = mid;
	}

	i = addr < asmap[hi]->n_value ? lo : hi;
	sym = asmap[i];
	v = sym->n_value;

	/*
	 * If the previous entry has the same value, improve our choice.  The
	 * order of equal-valued symbols is determined by the comparison func.
	 */
	while (i-- != 0 && asmap[i]->n_value == v)
		sym = asmap[i];

	/*
	 * Either addr < asmap[0]->n_value (in which case i is zero), or
	 * i is the smallest index s.t. asmap[i]->n_value <= addr <= asmap[i+1]->n_value.
	 * We'd like a st_size bounds check: if (addr - sym->n_value < MAX(sym->st_size, 1)),
	 * but Mach-o nlist entries don't capture the size attribute, sigh.
	 * At least make sure addr isn't too small.
	 */
	if (sym->n_value <= addr) {
		const char *name = strtab + sym->n_un.n_strx;
		char *tmp;

		if ((tmp = demangleSymbolCString(name)))
			name = tmp;

		if ('_' == name[0])
			name++; // Lop off omnipresent underscore

		symp->st_name = (GElf_Sxword)(name - strtab);
		symp->st_info = STT_NOTYPE;
		symp->st_other = 0;
		symp->st_shndx = sym->n_sect;
		symp->st_value = sym->n_value;
		symp->st_size = 0;

		if (sym->n_type & N_STAB) { /* Detect C++ methods */
	
			switch(sym->n_type) {
			case N_FUN:
				symp->st_info = GELF_ST_INFO((STB_GLOBAL), (STT_FUNC));
				break;
			case N_GSYM:
				symp->st_info = GELF_ST_INFO((STB_GLOBAL), (STT_OBJECT));
				break;
			default:
				break;
			}
		
		} else if ((N_ABS | N_EXT) == (sym->n_type & (N_TYPE | N_EXT)) ||
			(N_SECT | N_EXT) == (sym->n_type & (N_TYPE | N_EXT))) {

			symp->st_info = GELF_ST_INFO((STB_GLOBAL), (sym->n_desc)); 
		} else if ((N_UNDF | N_EXT) == (sym->n_type & (N_TYPE | N_EXT)) &&
					sym->n_sect == NO_SECT) {
			symp->st_info = GELF_ST_INFO((STB_GLOBAL), (STT_OBJECT)); /* Common */
		}
		
		if (idp != NULL) {
			*idp = (uint_t)(sym - symtab);
		}

		return symp;
	}

	return (NULL);
}

static const dt_modops_t dt_modops_macho_32 = {
	dt_module_syminit_macho,
	dt_module_symsort_macho,
	dt_module_symname_macho,
	dt_module_symaddr_macho
};

static uint_t
dt_module_syminit_macho_64(dt_module_t *dmp)
{
	const struct nlist_64 *sym = (const struct nlist_64 *)(dmp->dm_symtab.cts_data);
	const char *base = (const char *)dmp->dm_strtab.cts_data;
	uint_t i, n = dmp->dm_nsymelems;
	uint_t asrsv = 0;
	char *tmp;

	for (i = 0; i < n; i++, sym++) {
		const char *name = base + sym->n_un.n_strx;
		uchar_t type = sym->n_type & (N_TYPE | N_EXT);

        // Check that the symbol is a global and that it has a name.
        if (((N_SECT | N_EXT) != type && (N_ABS | N_EXT) != type))
            continue;
			
		if (STT_FUNC != sym->n_desc && STT_OBJECT != sym->n_desc)
			continue;
			
		if (0 == sym->n_un.n_strx) // iff a null, "", name.
			continue;

		if ((tmp = demangleSymbolCString(name)))
			name = tmp;

		if ('_' == name[0])
			name++; // Lop off omnipresent underscore to match DWARF convention
		
		if (sym->n_value != 0)
			asrsv++; /* reserve space in the address map */

		dt_module_symhash_insert(dmp, name, i);
	}

	return (asrsv);
}

static int
dt_module_symcomp_macho_64(const void *lp, const void *rp)
{
	struct nlist_64 *lhs = *((struct nlist_64 **)lp);
	struct nlist_64 *rhs = *((struct nlist_64 **)rp);

	if (lhs->n_value != rhs->n_value)
		return (lhs->n_value > rhs->n_value ? 1 : -1);

	if ((lhs->n_desc & N_WEAK_REF) != (rhs->n_desc & N_WEAK_REF))
		return ((lhs->n_desc & N_WEAK_REF) ? 1 : -1);

	return (strcmp(dt_module_strtab + lhs->n_un.n_strx,
	    dt_module_strtab + rhs->n_un.n_strx)); // Leading underscores compare equal so leave them be
}

static void
dt_module_symsort_macho_64(dt_module_t *dmp)
{
	struct nlist_64 *symtab = (struct nlist_64 *)(dmp->dm_symtab.cts_data);
	struct nlist_64 **sympp = (struct nlist_64 **)dmp->dm_asmap;
	const dt_sym_t *dsp = dmp->dm_symchains + 1;
	uint_t i, n = dmp->dm_symfree;

	for (i = 1; i < n; i++, dsp++) {
		struct nlist_64 *sym = symtab + dsp->ds_symid;
		if (sym->n_value != 0)
			*sympp++ = sym;
	}

	dmp->dm_aslen = (uint_t)(sympp - (struct nlist_64 **)dmp->dm_asmap);
	assert(dmp->dm_aslen <= dmp->dm_asrsv);

	dt_module_strtab = ((char *)(dmp->dm_symtab.cts_data)) + dmp->dm_symtab.cts_size;
	qsort(dmp->dm_asmap, dmp->dm_aslen,
	    sizeof (struct nlist_64 *), dt_module_symcomp_macho_64);
	dt_module_strtab = NULL;
}

static GElf_Sym *
dt_module_symname_macho_64(dt_module_t *dmp, const char *name,
    GElf_Sym *symp, uint_t *idp)
{
	const struct nlist_64 *symtab = (const struct nlist_64 *)(dmp->dm_symtab.cts_data);
	const char *strtab = (const char *)dmp->dm_strtab.cts_data;

	const struct nlist_64 *sym;
	const dt_sym_t *dsp;
	uint_t i, h;

	if (dmp->dm_nsymelems == 0)
		return (NULL);

	h = dt_strtab_hash(name, NULL) % dmp->dm_nsymbuckets;

	for (i = dmp->dm_symbuckets[h]; i != 0; i = dsp->ds_next) {
		dsp = &dmp->dm_symchains[i];
		sym = symtab + dsp->ds_symid;
		const char *sname = strtab + sym->n_un.n_strx;
		char *tmp;

		if ((tmp = demangleSymbolCString(sname)))
			sname = tmp;

		if ('_' == sname[0])
			sname++; // Lop off omnipresent underscore
			
		if (strcmp(name, sname) == 0) {
			if (idp != NULL)
				*idp = dsp->ds_symid;

			symp->st_name = (GElf_Sxword)(sname - strtab);
			symp->st_info = STT_NOTYPE; 
			symp->st_other = 0;
			symp->st_shndx = sym->n_sect;
			symp->st_value = sym->n_value;
			symp->st_size = 0;
			
			if (sym->n_type & N_STAB) { /* Detect C++ methods */
	
				switch(sym->n_type) { 
				case N_FUN:
					symp->st_info = GELF_ST_INFO((STB_GLOBAL), (STT_FUNC));
					break;
				case N_GSYM:
					symp->st_info = GELF_ST_INFO((STB_GLOBAL), (STT_OBJECT));
					break;
				default:
					break;
				}
		
			} else if ((N_ABS | N_EXT) == (sym->n_type & (N_TYPE | N_EXT)) ||
				(N_SECT | N_EXT) == (sym->n_type & (N_TYPE | N_EXT))) {

				symp->st_info = GELF_ST_INFO((STB_GLOBAL), (sym->n_desc)); 
			} else if ((N_UNDF | N_EXT) == (sym->n_type & (N_TYPE | N_EXT)) &&
						sym->n_sect == NO_SECT) {
				symp->st_info = GELF_ST_INFO((STB_GLOBAL), (STT_OBJECT)); /* Common */
			}
		
			return symp;
		}
	}

	return (NULL);
}

static GElf_Sym *
dt_module_symaddr_macho_64(dt_module_t *dmp, GElf_Addr addr,
    GElf_Sym *symp, uint_t *idp)
{
	const struct nlist_64 **asmap = (const struct nlist_64 **)dmp->dm_asmap;
	const struct nlist_64 *symtab = (const struct nlist_64 *)(dmp->dm_symtab.cts_data);
	const char *strtab = (const char *)dmp->dm_strtab.cts_data;
	const struct nlist_64 *sym;

	uint_t i, mid, lo = 0, hi = dmp->dm_aslen - 1;
	Elf32_Addr v;

	if (dmp->dm_aslen == 0)
		return (NULL);

	while (hi - lo > 1) {
		mid = (lo + hi) / 2;
		if (addr >= asmap[mid]->n_value)
			lo = mid;
		else
			hi = mid;
	}

	i = addr < asmap[hi]->n_value ? lo : hi;
	sym = asmap[i];
	v = sym->n_value;

	/*
	 * If the previous entry has the same value, improve our choice.  The
	 * order of equal-valued symbols is determined by the comparison func.
	 */
	while (i-- != 0 && asmap[i]->n_value == v)
		sym = asmap[i];

	/*
	 * Either addr < asmap[0]->n_value (in which case i is zero), or
	 * i is the smallest index s.t. asmap[i]->n_value <= addr <= asmap[i+1]->n_value.
	 * We'd like a st_size bounds check: if (addr - sym->n_value < MAX(sym->st_size, 1)),
	 * but Mach-o nlist entries don't capture the size attribute, sigh.
	 * At least make sure addr isn't too small.
	 */
	if (sym->n_value <= addr) {
		const char *name = strtab + sym->n_un.n_strx;
		char *tmp;

		if ((tmp = demangleSymbolCString(name)))
			name = tmp;

		if ('_' == name[0])
			name++; // Lop off omnipresent underscore

		symp->st_name = (GElf_Sxword)(name - strtab);
		symp->st_info = STT_NOTYPE;
		symp->st_other = 0;
		symp->st_shndx = sym->n_sect;
		symp->st_value = sym->n_value;
		symp->st_size = 0;

		if (sym->n_type & N_STAB) { /* Detect C++ methods */
	
			switch(sym->n_type) {
			case N_FUN:
				symp->st_info = GELF_ST_INFO((STB_GLOBAL), (STT_FUNC));
				break;
			case N_GSYM:
				symp->st_info = GELF_ST_INFO((STB_GLOBAL), (STT_OBJECT));
				break;
			default:
				break;
			}
		
		} else if ((N_ABS | N_EXT) == (sym->n_type & (N_TYPE | N_EXT)) ||
			(N_SECT | N_EXT) == (sym->n_type & (N_TYPE | N_EXT))) {

			symp->st_info = GELF_ST_INFO((STB_GLOBAL), (sym->n_desc)); 
		} else if ((N_UNDF | N_EXT) == (sym->n_type & (N_TYPE | N_EXT)) &&
					sym->n_sect == NO_SECT) {
			symp->st_info = GELF_ST_INFO((STB_GLOBAL), (STT_OBJECT)); /* Common */
		}
		
		if (idp != NULL) {
			*idp = (uint_t)(sym - symtab);
		}

		return symp;
	}

	return (NULL);
}

static const dt_modops_t dt_modops_macho_64 = {
	dt_module_syminit_macho_64,
	dt_module_symsort_macho_64,
	dt_module_symname_macho_64,
	dt_module_symaddr_macho_64
};
#endif /* __APPLE__ */

dt_module_t *
dt_module_create(dtrace_hdl_t *dtp, const char *name)
{
	uint_t h = dt_strtab_hash(name, NULL) % dtp->dt_modbuckets;
	dt_module_t *dmp;

	for (dmp = dtp->dt_mods[h]; dmp != NULL; dmp = dmp->dm_next) {
		if (strcmp(dmp->dm_name, name) == 0)
			return (dmp);
	}

	if ((dmp = malloc(sizeof (dt_module_t))) == NULL)
		return (NULL); /* caller must handle allocation failure */

	bzero(dmp, sizeof (dt_module_t));
	(void) strlcpy(dmp->dm_name, name, sizeof (dmp->dm_name));
	dt_list_append(&dtp->dt_modlist, dmp);
	dmp->dm_next = dtp->dt_mods[h];
	dtp->dt_mods[h] = dmp;
	dtp->dt_nmods++;

#if !defined(__APPLE__)
	if (dtp->dt_conf.dtc_ctfmodel == CTF_MODEL_LP64)
		dmp->dm_ops = &dt_modops_64;
	else
		dmp->dm_ops = &dt_modops_32;
#else
	if (dtp->dt_conf.dtc_ctfmodel == CTF_MODEL_LP64)
		dmp->dm_ops = &dt_modops_macho_64;
	else
		dmp->dm_ops = &dt_modops_macho_32;
#endif /* __APPLE__ */

	return (dmp);
}

dt_module_t *
dt_module_lookup_by_name(dtrace_hdl_t *dtp, const char *name)
{
	uint_t h = dt_strtab_hash(name, NULL) % dtp->dt_modbuckets;
	dt_module_t *dmp;

	for (dmp = dtp->dt_mods[h]; dmp != NULL; dmp = dmp->dm_next) {
		if (strcmp(dmp->dm_name, name) == 0)
			return (dmp);
	}

	return (NULL);
}

/*ARGSUSED*/
dt_module_t *
dt_module_lookup_by_ctf(dtrace_hdl_t *dtp, ctf_file_t *ctfp)
{
	return (ctfp ? ctf_getspecific(ctfp) : NULL);
}

static int
dt_module_load_sect(dtrace_hdl_t *dtp, dt_module_t *dmp, ctf_sect_t *ctsp)
{
	const char *s;
	size_t shstrs;
	GElf_Shdr sh;
	Elf_Data *dp;
	Elf_Scn *sp;

	if (elf_getshstrndx(dmp->dm_elf, &shstrs) == 0)
		return (dt_set_errno(dtp, EDT_NOTLOADED));

	for (sp = NULL; (sp = elf_nextscn(dmp->dm_elf, sp)) != NULL; ) {
		if (gelf_getshdr(sp, &sh) == NULL || sh.sh_type == SHT_NULL ||
		    (s = elf_strptr(dmp->dm_elf, shstrs, sh.sh_name)) == NULL)
			continue; /* skip any malformed sections */

		if (sh.sh_type == ctsp->cts_type &&
		    sh.sh_entsize == ctsp->cts_entsize &&
		    strcmp(s, ctsp->cts_name) == 0)
			break; /* section matches specification */
	}

	/*
	 * If the section isn't found, return success but leave cts_data set
	 * to NULL and cts_size set to zero for our caller.
	 */
	if (sp == NULL || (dp = elf_getdata(sp, NULL)) == NULL)
		return (0);

	ctsp->cts_data = dp->d_buf;
	ctsp->cts_size = dp->d_size;

	dt_dprintf("loaded %s [%s] (%lu bytes)\n",
	    dmp->dm_name, ctsp->cts_name, (ulong_t)ctsp->cts_size);

	return (0);
}

int
dt_module_load(dtrace_hdl_t *dtp, dt_module_t *dmp)
{
	if (dmp->dm_flags & DT_DM_LOADED)
		return (0); /* module is already loaded */

	dmp->dm_ctdata.cts_name = ".SUNW_ctf";
#if !defined(__APPLE__)
	dmp->dm_ctdata.cts_type = SHT_PROGBITS;
#else
	dmp->dm_ctdata.cts_type = SHT_UNKNOWN12;
#endif /* __APPLE__ */
	dmp->dm_ctdata.cts_flags = 0;
	dmp->dm_ctdata.cts_data = NULL;
	dmp->dm_ctdata.cts_size = 0;
	dmp->dm_ctdata.cts_entsize = 0;
	dmp->dm_ctdata.cts_offset = 0;

	dmp->dm_symtab.cts_name = ".symtab";
#if !defined(__APPLE__)
	dmp->dm_symtab.cts_type = SHT_SYMTAB;
#else
	dmp->dm_symtab.cts_type = SHT_STRTAB;
#endif /* __APPLE__ */
	dmp->dm_symtab.cts_flags = 0;
	dmp->dm_symtab.cts_data = NULL;
	dmp->dm_symtab.cts_size = 0;
#if !defined(__APPLE__)
	dmp->dm_symtab.cts_entsize = dmp->dm_ops == &dt_modops_64 ?
	    sizeof (Elf64_Sym) : sizeof (Elf32_Sym);
#else
	dmp->dm_symtab.cts_entsize = 
		dmp->dm_ops == &dt_modops_macho_32 ? sizeof(struct nlist) : 
		dmp->dm_ops == &dt_modops_macho_64 ? sizeof(struct nlist_64) : 
		(dmp->dm_ops == &dt_modops_64 ? sizeof (Elf64_Sym) : sizeof (Elf32_Sym));
#endif /* __APPLE__ */
	dmp->dm_symtab.cts_offset = 0;

#if !defined(__APPLE__)
	dmp->dm_strtab.cts_name = ".strtab";
#else
	dmp->dm_strtab.cts_name = ".dir_str_table";
#endif /* __APPLE__ */
	dmp->dm_strtab.cts_type = SHT_STRTAB;
	dmp->dm_strtab.cts_flags = 0;
	dmp->dm_strtab.cts_data = NULL;
	dmp->dm_strtab.cts_size = 0;
	dmp->dm_strtab.cts_entsize = 0;
	dmp->dm_strtab.cts_offset = 0;

	/*
	 * Attempt to load the module's CTF section, symbol table section, and
	 * string table section.  Note that modules may not contain CTF data:
	 * this will result in a successful load_sect but data of size zero.
	 * We will then fail if dt_module_getctf() is called, as shown below.
	 */
	if (dt_module_load_sect(dtp, dmp, &dmp->dm_ctdata) == -1 ||
	    dt_module_load_sect(dtp, dmp, &dmp->dm_symtab) == -1 ||
	    dt_module_load_sect(dtp, dmp, &dmp->dm_strtab) == -1) {
		dt_module_unload(dtp, dmp);
		return (-1); /* dt_errno is set for us */
	}

	/*
	 * Allocate the hash chains and hash buckets for symbol name lookup.
	 * This is relatively simple since the symbol table is of fixed size
	 * and is known in advance.  We allocate one extra element since we
	 * use element indices instead of pointers and zero is our sentinel.
	 */
	dmp->dm_nsymelems =
	    dmp->dm_symtab.cts_size / dmp->dm_symtab.cts_entsize;

	dmp->dm_nsymbuckets = _dtrace_strbuckets;
	dmp->dm_symfree = 1;		/* first free element is index 1 */

	dmp->dm_symbuckets = malloc(sizeof (uint_t) * dmp->dm_nsymbuckets);
	dmp->dm_symchains = malloc(sizeof (dt_sym_t) * dmp->dm_nsymelems + 1);

	if (dmp->dm_symbuckets == NULL || dmp->dm_symchains == NULL) {
		dt_module_unload(dtp, dmp);
		return (dt_set_errno(dtp, EDT_NOMEM));
	}

	bzero(dmp->dm_symbuckets, sizeof (uint_t) * dmp->dm_nsymbuckets);
	bzero(dmp->dm_symchains, sizeof (dt_sym_t) * dmp->dm_nsymelems + 1);

	/*
	 * Iterate over the symbol table data buffer and insert each symbol
	 * name into the name hash if the name and type are valid.  Then
	 * allocate the address map, fill it in, and sort it.
	 */
	dmp->dm_asrsv = dmp->dm_ops->do_syminit(dmp);

	dt_dprintf("hashed %s [%s] (%u symbols)\n",
	    dmp->dm_name, dmp->dm_symtab.cts_name, dmp->dm_symfree - 1);

	if ((dmp->dm_asmap = malloc(sizeof (void *) * dmp->dm_asrsv)) == NULL) {
		dt_module_unload(dtp, dmp);
		return (dt_set_errno(dtp, EDT_NOMEM));
	}

	dmp->dm_ops->do_symsort(dmp);

	dt_dprintf("sorted %s [%s] (%u symbols)\n",
	    dmp->dm_name, dmp->dm_symtab.cts_name, dmp->dm_aslen);

	dmp->dm_flags |= DT_DM_LOADED;
	return (0);
}

ctf_file_t *
dt_module_getctf(dtrace_hdl_t *dtp, dt_module_t *dmp)
{
	const char *parent;
	dt_module_t *pmp;
	ctf_file_t *pfp;
	int model;

	if (dmp->dm_ctfp != NULL || dt_module_load(dtp, dmp) != 0)
		return (dmp->dm_ctfp);

#if defined(__APPLE__)
	if (dmp->dm_ops == &dt_modops_macho_64)
		model = CTF_MODEL_LP64;
	else if (dmp->dm_ops == &dt_modops_macho_32)
		model = CTF_MODEL_ILP32;
	else
#endif /* __APPLE__ */
	if (dmp->dm_ops == &dt_modops_64)
		model = CTF_MODEL_LP64;
	else
		model = CTF_MODEL_ILP32;

	/*
	 * If the data model of the module does not match our program data
	 * model, then do not permit CTF from this module to be opened and
	 * returned to the compiler.  If we support mixed data models in the
	 * future for combined kernel/user tracing, this can be removed.
	 */
	/*
	 * APPLE NOTE: We are forced to support mixed models now. Xnu is
	 * currently always CTF_MODEL_ILP32, even when user programs are
	 * CTF_MODEL_LP64. 
	 */
#if !defined(__APPLE__)
	if (dtp->dt_conf.dtc_ctfmodel != model) {
		(void) dt_set_errno(dtp, EDT_DATAMODEL);
		return (NULL);
	}
#endif
	
	if (dmp->dm_ctdata.cts_size == 0) {
		(void) dt_set_errno(dtp, EDT_NOCTF);
		return (NULL);
	}

	dmp->dm_ctfp = ctf_bufopen(&dmp->dm_ctdata,
	    &dmp->dm_symtab, &dmp->dm_strtab, &dtp->dt_ctferr);

	if (dmp->dm_ctfp == NULL) {
		(void) dt_set_errno(dtp, EDT_CTF);
		return (NULL);
	}

	(void) ctf_setmodel(dmp->dm_ctfp, model);
	ctf_setspecific(dmp->dm_ctfp, dmp);

	if ((parent = ctf_parent_name(dmp->dm_ctfp)) != NULL) {
		if ((pmp = dt_module_create(dtp, parent)) == NULL ||
		    (pfp = dt_module_getctf(dtp, pmp)) == NULL) {
			if (pmp == NULL)
				(void) dt_set_errno(dtp, EDT_NOMEM);
			goto err;
		}

		if (ctf_import(dmp->dm_ctfp, pfp) == CTF_ERR) {
			dtp->dt_ctferr = ctf_errno(dmp->dm_ctfp);
			(void) dt_set_errno(dtp, EDT_CTF);
			goto err;
		}
	}

	dt_dprintf("loaded CTF container for %s (%p)\n",
	    dmp->dm_name, (void *)dmp->dm_ctfp);

	return (dmp->dm_ctfp);

err:
	ctf_close(dmp->dm_ctfp);
	dmp->dm_ctfp = NULL;
	return (NULL);
}

/*ARGSUSED*/
void
dt_module_unload(dtrace_hdl_t *dtp, dt_module_t *dmp)
{
	ctf_close(dmp->dm_ctfp);
	dmp->dm_ctfp = NULL;

	bzero(&dmp->dm_ctdata, sizeof (ctf_sect_t));
	bzero(&dmp->dm_symtab, sizeof (ctf_sect_t));
	bzero(&dmp->dm_strtab, sizeof (ctf_sect_t));

	if (dmp->dm_symbuckets != NULL) {
		free(dmp->dm_symbuckets);
		dmp->dm_symbuckets = NULL;
	}

	if (dmp->dm_symchains != NULL) {
		free(dmp->dm_symchains);
		dmp->dm_symchains = NULL;
	}

	if (dmp->dm_asmap != NULL) {
		free(dmp->dm_asmap);
		dmp->dm_asmap = NULL;
	}

	dmp->dm_symfree = 0;
	dmp->dm_nsymbuckets = 0;
	dmp->dm_nsymelems = 0;
	dmp->dm_asrsv = 0;
	dmp->dm_aslen = 0;

	dmp->dm_text_va = (GElf_Addr)0;
	dmp->dm_text_size = 0;
	dmp->dm_data_va = (GElf_Addr)0;
	dmp->dm_data_size = 0;
	dmp->dm_bss_va = (GElf_Addr)0;
	dmp->dm_bss_size = 0;

	if (dmp->dm_extern != NULL) {
		dt_idhash_destroy(dmp->dm_extern);
		dmp->dm_extern = NULL;
	}

	(void) elf_end(dmp->dm_elf);
	dmp->dm_elf = NULL;

	dmp->dm_flags &= ~DT_DM_LOADED;
}

void
dt_module_destroy(dtrace_hdl_t *dtp, dt_module_t *dmp)
{
	dt_list_delete(&dtp->dt_modlist, dmp);
	assert(dtp->dt_nmods != 0);
	dtp->dt_nmods--;

	dt_module_unload(dtp, dmp);
	free(dmp);
}

/*
 * Insert a new external symbol reference into the specified module.  The new
 * symbol will be marked as undefined and is assigned a symbol index beyond
 * any existing cached symbols from this module.  We use the ident's di_data
 * field to store a pointer to a copy of the dtrace_syminfo_t for this symbol.
 */
dt_ident_t *
dt_module_extern(dtrace_hdl_t *dtp, dt_module_t *dmp,
    const char *name, const dtrace_typeinfo_t *tip)
{
	dtrace_syminfo_t *sip;
	dt_ident_t *idp;
	uint_t id;

	if (dmp->dm_extern == NULL && (dmp->dm_extern = dt_idhash_create(
	    "extern", NULL, dmp->dm_nsymelems, UINT_MAX)) == NULL) {
		(void) dt_set_errno(dtp, EDT_NOMEM);
		return (NULL);
	}

	if (dt_idhash_nextid(dmp->dm_extern, &id) == -1) {
		(void) dt_set_errno(dtp, EDT_SYMOFLOW);
		return (NULL);
	}

	if ((sip = malloc(sizeof (dtrace_syminfo_t))) == NULL) {
		(void) dt_set_errno(dtp, EDT_NOMEM);
		return (NULL);
	}

	idp = dt_idhash_insert(dmp->dm_extern, name, DT_IDENT_SYMBOL, 0, id,
	    _dtrace_symattr, 0, &dt_idops_thaw, NULL, dtp->dt_gen);

	if (idp == NULL) {
		(void) dt_set_errno(dtp, EDT_NOMEM);
		free(sip);
		return (NULL);
	}

	sip->dts_object = dmp->dm_name;
	sip->dts_name = idp->di_name;
	sip->dts_id = idp->di_id;

	idp->di_data = sip;
	idp->di_ctfp = tip->dtt_ctfp;
	idp->di_type = tip->dtt_type;

	return (idp);
}

const char *
dt_module_modelname(dt_module_t *dmp)
{
#if defined(__APPLE__)
	if (dmp->dm_ops == &dt_modops_macho_64)
		return ("64-bit");
	else if (dmp->dm_ops == &dt_modops_32)
		return ("32-bit");
	else
#endif /* __APPLE__ */
	if (dmp->dm_ops == &dt_modops_64)
		return ("64-bit");
	else
		return ("32-bit");
}

/*
 * Update our module cache by adding an entry for the specified module 'name'.
 * We create the dt_module_t and populate it using /system/object/<name>/.
 */
static void
dt_module_update(dtrace_hdl_t *dtp, const char *name)
{
	char fname[MAXPATHLEN];
	struct stat64 st;
	int fd, err, bits;

	dt_module_t *dmp;
	const char *s;
	size_t shstrs;
	GElf_Shdr sh;
	Elf_Data *dp;
	Elf_Scn *sp;

#if !defined(__APPLE__)
	(void) snprintf(fname, sizeof (fname),
	    "%s/%s/object", OBJFS_ROOT, name);
#else
	unsigned read_cmd = ELF_C_READ;
	
	if (0 == strcmp("mach_kernel", name)) {
		strncpy(fname, "/mach_kernel.ctfsys", sizeof (fname)); // Look for module "mach_kernel"
		
		 // pre-flight /mach_kernel.ctfsys
		if ((fd = open(fname, O_RDONLY)) == -1)
			strncpy(fname, "/mach_kernel", sizeof (fname)); // fallback to /mach_kernel
		else
			(void) close(fd); // close successful pre-flight of /mach_kernel.ctfsys
			
		read_cmd = ELF_C_RDKERNTYPE;
	} else {
	(void) snprintf(fname, sizeof (fname),
	    "%s/%s/object", OBJFS_ROOT, name);
	}
#endif /* __APPLE__ */


	if ((fd = open(fname, O_RDONLY)) == -1 || fstat64(fd, &st) == -1 ||
	    (dmp = dt_module_create(dtp, name)) == NULL) {
		dt_dprintf("failed to open %s: %s\n", fname, strerror(errno));
		(void) close(fd);
		return;
	}

	/*
	 * Since the module can unload out from under us (and /system/object
	 * will return ENOENT), tell libelf to cook the entire file now and
	 * then close the underlying file descriptor immediately.  If this
	 * succeeds, we know that we can continue safely using dmp->dm_elf.
	 */
#if !defined(__APPLE__)
	dmp->dm_elf = elf_begin(fd, ELF_C_READ, NULL);
#else
	dmp->dm_elf = elf_begin(fd, read_cmd, NULL);
#endif /* __APPLE__ */
	err = elf_cntl(dmp->dm_elf, ELF_C_FDREAD);
	(void) close(fd);

	if (dmp->dm_elf == NULL || err == -1 ||
	    elf_getshstrndx(dmp->dm_elf, &shstrs) == 0) {
		dt_dprintf("failed to load %s: %s\n",
		    fname, elf_errmsg(elf_errno()));
		dt_module_destroy(dtp, dmp);
		return;
	}

	switch (gelf_getclass(dmp->dm_elf)) {
#if !defined(__APPLE__)
	case ELFCLASS32:
		dmp->dm_ops = &dt_modops_32;
		bits = 32;
		break;
	case ELFCLASS64:
		dmp->dm_ops = &dt_modops_64;
		bits = 64;
		break;
#else
	case ELFCLASS32:
		dmp->dm_ops = (dmp->dm_elf->ed_kind == ELF_K_MACHO ? &dt_modops_macho_32 : &dt_modops_32);
		bits = 32;
		break;
	case ELFCLASS64:
		dmp->dm_ops = (dmp->dm_elf->ed_kind == ELF_K_MACHO ? &dt_modops_macho_64 : &dt_modops_64);
		bits = 64;
		break;
#endif /* __APPLE__ */
	default:
		dt_dprintf("failed to load %s: unknown ELF class\n", fname);
		dt_module_destroy(dtp, dmp);
		return;
	}

	/*
	 * Iterate over the section headers locating various sections of
	 * interest and use their attributes to flesh out the dt_module_t.
	 */
	for (sp = NULL; (sp = elf_nextscn(dmp->dm_elf, sp)) != NULL; ) {
		if (gelf_getshdr(sp, &sh) == NULL || sh.sh_type == SHT_NULL ||
		    (s = elf_strptr(dmp->dm_elf, shstrs, sh.sh_name)) == NULL)
			continue; /* skip any malformed sections */

		if (strcmp(s, ".text") == 0) {
			dmp->dm_text_size = sh.sh_size;
			dmp->dm_text_va = sh.sh_addr;
		} else if (strcmp(s, ".data") == 0) {
			dmp->dm_data_size = sh.sh_size;
			dmp->dm_data_va = sh.sh_addr;
		} else if (strcmp(s, ".bss") == 0) {
			dmp->dm_bss_size = sh.sh_size;
			dmp->dm_bss_va = sh.sh_addr;
		} else if (strcmp(s, ".info") == 0 &&
		    (dp = elf_getdata(sp, NULL)) != NULL) {
			bcopy(dp->d_buf, &dmp->dm_info,
			    MIN(sh.sh_size, sizeof (dmp->dm_info)));
		} else if (strcmp(s, ".filename") == 0 &&
		    (dp = elf_getdata(sp, NULL)) != NULL) {
			(void) strlcpy(dmp->dm_file,
			    dp->d_buf, sizeof (dmp->dm_file));
		}
	}

	dmp->dm_flags |= DT_DM_KERNEL;
	dmp->dm_modid = (int)OBJFS_MODID(st.st_ino);

	if (dmp->dm_info.objfs_info_primary)
		dmp->dm_flags |= DT_DM_PRIMARY;

	dt_dprintf("opened %d-bit module %s (%s) [%d]\n",
	    bits, dmp->dm_name, dmp->dm_file, dmp->dm_modid);
}

/*
 * Unload all the loaded modules and then refresh the module cache with the
 * latest list of loaded modules and their address ranges.
 */
void
dtrace_update(dtrace_hdl_t *dtp)
{
	dt_module_t *dmp;
	DIR *dirp;

	for (dmp = dt_list_next(&dtp->dt_modlist);
	    dmp != NULL; dmp = dt_list_next(dmp))
		dt_module_unload(dtp, dmp);

#if !defined(__APPLE__)
	/*
	 * Open /system/object and attempt to create a libdtrace module for
	 * each kernel module that is loaded on the current system.
	 */
	if (!(dtp->dt_oflags & DTRACE_O_NOSYS) &&
	    (dirp = opendir(OBJFS_ROOT)) != NULL) {
		struct dirent *dp;

		while ((dp = readdir(dirp)) != NULL) {
			if (dp->d_name[0] != '.')
				dt_module_update(dtp, dp->d_name);
		}

		(void) closedir(dirp);
	}
#else
	if (!(dtp->dt_oflags & DTRACE_O_NOSYS)) {
		dt_module_update(dtp, "mach_kernel");
	}
#endif /* __APPLE__ */

	/*
	 * Look up all the macro identifiers and set di_id to the latest value.
	 * This code collaborates with dt_lex.l on the use of di_id.  We will
	 * need to implement something fancier if we need to support non-ints.
	 */
	dt_idhash_lookup(dtp->dt_macros, "egid")->di_id = getegid();
	dt_idhash_lookup(dtp->dt_macros, "euid")->di_id = geteuid();
	dt_idhash_lookup(dtp->dt_macros, "gid")->di_id = getgid();
	dt_idhash_lookup(dtp->dt_macros, "pid")->di_id = getpid();
	dt_idhash_lookup(dtp->dt_macros, "pgid")->di_id = getpgid(0);
	dt_idhash_lookup(dtp->dt_macros, "ppid")->di_id = getppid();
	dt_idhash_lookup(dtp->dt_macros, "projid")->di_id = getprojid();
	dt_idhash_lookup(dtp->dt_macros, "sid")->di_id = getsid(0);
	dt_idhash_lookup(dtp->dt_macros, "taskid")->di_id = gettaskid();
	dt_idhash_lookup(dtp->dt_macros, "uid")->di_id = getuid();

	/*
	 * Cache the pointers to the modules representing the base executable
	 * and the run-time linker in the dtrace client handle. Note that on
	 * x86 krtld is folded into unix, so if we don't find it, use unix
	 * instead.
	 */
#if !defined(__APPLE__)
	dtp->dt_exec = dt_module_lookup_by_name(dtp, "genunix");
	dtp->dt_rtld = dt_module_lookup_by_name(dtp, "krtld");
	if (dtp->dt_rtld == NULL)
		dtp->dt_rtld = dt_module_lookup_by_name(dtp, "unix");
#else
	dtp->dt_exec = dt_module_lookup_by_name(dtp, "mach_kernel");
	dtp->dt_rtld = dt_module_lookup_by_name(dtp, "dyld"); /* XXX to what purpose? */
#endif /* __APPLE__ */
	/*
	 * If this is the first time we are initializing the module list,
	 * remove the module for genunix from the module list and then move it
	 * to the front of the module list.  We do this so that type and symbol
	 * queries encounter genunix and thereby optimize for the common case
	 * in dtrace_lookup_by_name() and dtrace_lookup_by_type(), below.
	 */
	if (dtp->dt_exec != NULL &&
	    dtp->dt_cdefs == NULL && dtp->dt_ddefs == NULL) {
		dt_list_delete(&dtp->dt_modlist, dtp->dt_exec);
		dt_list_prepend(&dtp->dt_modlist, dtp->dt_exec);
	}
}

static dt_module_t *
dt_module_from_object(dtrace_hdl_t *dtp, const char *object)
{
	int err = EDT_NOMOD;
	dt_module_t *dmp;

	switch ((uintptr_t)object) {
	case (uintptr_t)DTRACE_OBJ_EXEC:
		dmp = dtp->dt_exec;
		break;
	case (uintptr_t)DTRACE_OBJ_RTLD:
		dmp = dtp->dt_rtld;
		break;
	case (uintptr_t)DTRACE_OBJ_CDEFS:
		dmp = dtp->dt_cdefs;
		break;
	case (uintptr_t)DTRACE_OBJ_DDEFS:
		dmp = dtp->dt_ddefs;
		break;
	default:
		dmp = dt_module_create(dtp, object);
		err = EDT_NOMEM;
	}

	if (dmp == NULL)
		(void) dt_set_errno(dtp, err);

	return (dmp);
}

/*
 * Exported interface to look up a symbol by name.  We return the GElf_Sym and
 * complete symbol information for the matching symbol.
 */
int
dtrace_lookup_by_name(dtrace_hdl_t *dtp, const char *object, const char *name,
    GElf_Sym *symp, dtrace_syminfo_t *sip)
{
	dt_module_t *dmp;
	dt_ident_t *idp;
	uint_t n, id;
	GElf_Sym sym;

	uint_t mask = 0; /* mask of dt_module flags to match */
	uint_t bits = 0; /* flag bits that must be present */

	if (object != DTRACE_OBJ_EVERY &&
	    object != DTRACE_OBJ_KMODS &&
	    object != DTRACE_OBJ_UMODS) {
		if ((dmp = dt_module_from_object(dtp, object)) == NULL)
			return (-1); /* dt_errno is set for us */

		if (dt_module_load(dtp, dmp) == -1)
			return (-1); /* dt_errno is set for us */
		n = 1;

	} else {
		if (object == DTRACE_OBJ_KMODS)
			mask = bits = DT_DM_KERNEL;
		else if (object == DTRACE_OBJ_UMODS)
			mask = DT_DM_KERNEL;

		dmp = dt_list_next(&dtp->dt_modlist);
		n = dtp->dt_nmods;
	}

	if (symp == NULL)
		symp = &sym;

	for (; n > 0; n--, dmp = dt_list_next(dmp)) {
		if ((dmp->dm_flags & mask) != bits)
			continue; /* failed to match required attributes */

		if (dt_module_load(dtp, dmp) == -1)
			continue; /* failed to load symbol table */

		if (dmp->dm_ops->do_symname(dmp, name, symp, &id) != NULL) {
			if (sip != NULL) {
				sip->dts_object = dmp->dm_name;
				sip->dts_name = (const char *)
				    dmp->dm_strtab.cts_data + symp->st_name;
				sip->dts_id = id;
			}
			return (0);
		}

		if (dmp->dm_extern != NULL &&
		    (idp = dt_idhash_lookup(dmp->dm_extern, name)) != NULL) {
			if (symp != &sym) {
				symp->st_name = (uintptr_t)idp->di_name;
				symp->st_info =
				    GELF_ST_INFO(STB_GLOBAL, STT_NOTYPE);
				symp->st_other = 0;
				symp->st_shndx = SHN_UNDEF;
				symp->st_value = 0;
				symp->st_size =
				    ctf_type_size(idp->di_ctfp, idp->di_type);
			}

			if (sip != NULL) {
				sip->dts_object = dmp->dm_name;
				sip->dts_name = idp->di_name;
				sip->dts_id = idp->di_id;
			}

			return (0);
		}
	}

	return (dt_set_errno(dtp, EDT_NOSYM));
}

/*
 * Exported interface to look up a symbol by address.  We return the GElf_Sym
 * and complete symbol information for the matching symbol.
 */
int
dtrace_lookup_by_addr(dtrace_hdl_t *dtp, GElf_Addr addr,
    GElf_Sym *symp, dtrace_syminfo_t *sip)
{
	dt_module_t *dmp;
	uint_t id;
	const dtrace_vector_t *v = dtp->dt_vector;

	if (v != NULL)
		return (v->dtv_lookup_by_addr(dtp->dt_varg, addr, symp, sip));

	for (dmp = dt_list_next(&dtp->dt_modlist); dmp != NULL;
	    dmp = dt_list_next(dmp)) {
		if (addr - dmp->dm_text_va < dmp->dm_text_size ||
		    addr - dmp->dm_data_va < dmp->dm_data_size ||
		    addr - dmp->dm_bss_va < dmp->dm_bss_size)
			break;
	}

	if (dmp == NULL)
		return (dt_set_errno(dtp, EDT_NOSYMADDR));

	if (dt_module_load(dtp, dmp) == -1)
		return (-1); /* dt_errno is set for us */

	if (symp != NULL) {
		if (dmp->dm_ops->do_symaddr(dmp, addr, symp, &id) == NULL)
			return (dt_set_errno(dtp, EDT_NOSYMADDR));
	}

	if (sip != NULL) {
		sip->dts_object = dmp->dm_name;

		if (symp != NULL) {
			sip->dts_name = (const char *)
			    dmp->dm_strtab.cts_data + symp->st_name;
			sip->dts_id = id;
		} else {
			sip->dts_name = NULL;
			sip->dts_id = 0;
		}
	}

	return (0);
}

int
dtrace_lookup_by_type(dtrace_hdl_t *dtp, const char *object, const char *name,
    dtrace_typeinfo_t *tip)
{
	dtrace_typeinfo_t ti;
	dt_module_t *dmp;
	int found = 0;
	ctf_id_t id;
	uint_t n;
	int justone;

	uint_t mask = 0; /* mask of dt_module flags to match */
	uint_t bits = 0; /* flag bits that must be present */

	if (object != DTRACE_OBJ_EVERY &&
	    object != DTRACE_OBJ_KMODS &&
	    object != DTRACE_OBJ_UMODS) {
		if ((dmp = dt_module_from_object(dtp, object)) == NULL)
			return (-1); /* dt_errno is set for us */

		if (dt_module_load(dtp, dmp) == -1)
			return (-1); /* dt_errno is set for us */
		n = 1;
		justone = 1;

	} else {
		if (object == DTRACE_OBJ_KMODS)
			mask = bits = DT_DM_KERNEL;
		else if (object == DTRACE_OBJ_UMODS)
			mask = DT_DM_KERNEL;

		dmp = dt_list_next(&dtp->dt_modlist);
		n = dtp->dt_nmods;
		justone = 0;
	}

	if (tip == NULL)
		tip = &ti;

	for (; n > 0; n--, dmp = dt_list_next(dmp)) {
		if ((dmp->dm_flags & mask) != bits)
			continue; /* failed to match required attributes */

		/*
		 * If we can't load the CTF container, continue on to the next
		 * module.  If our search was scoped to only one module then
		 * return immediately leaving dt_errno unmodified.
		 */
		if (dt_module_getctf(dtp, dmp) == NULL) {
			if (justone)
				return (-1);
			continue;
		}

		/*
		 * Look up the type in the module's CTF container.  If our
		 * match is a forward declaration tag, save this choice in
		 * 'tip' and keep going in the hope that we will locate the
		 * underlying structure definition.  Otherwise just return.
		 */
		if ((id = ctf_lookup_by_name(dmp->dm_ctfp, name)) != CTF_ERR) {
			tip->dtt_object = dmp->dm_name;
			tip->dtt_ctfp = dmp->dm_ctfp;
			tip->dtt_type = id;

			if (ctf_type_kind(dmp->dm_ctfp, ctf_type_resolve(
			    dmp->dm_ctfp, id)) != CTF_K_FORWARD)
				return (0);

			found++;
		}
	}

	if (found == 0)
		return (dt_set_errno(dtp, EDT_NOTYPE));

	return (0);
}

int
dtrace_symbol_type(dtrace_hdl_t *dtp, const GElf_Sym *symp,
    const dtrace_syminfo_t *sip, dtrace_typeinfo_t *tip)
{
	dt_module_t *dmp;

	tip->dtt_object = NULL;
	tip->dtt_ctfp = NULL;
	tip->dtt_type = CTF_ERR;

	if ((dmp = dt_module_lookup_by_name(dtp, sip->dts_object)) == NULL)
		return (dt_set_errno(dtp, EDT_NOMOD));

	if (symp->st_shndx == SHN_UNDEF && dmp->dm_extern != NULL) {
		dt_ident_t *idp =
		    dt_idhash_lookup(dmp->dm_extern, sip->dts_name);

		if (idp == NULL)
			return (dt_set_errno(dtp, EDT_NOSYM));

		tip->dtt_ctfp = idp->di_ctfp;
		tip->dtt_type = idp->di_type;

	} else if (GELF_ST_TYPE(symp->st_info) != STT_FUNC) {
		if (dt_module_getctf(dtp, dmp) == NULL)
			return (-1); /* errno is set for us */

		tip->dtt_ctfp = dmp->dm_ctfp;
		tip->dtt_type = ctf_lookup_by_symbol(dmp->dm_ctfp, sip->dts_id);

		if (tip->dtt_type == CTF_ERR) {
			dtp->dt_ctferr = ctf_errno(tip->dtt_ctfp);
			return (dt_set_errno(dtp, EDT_CTF));
		}

	} else {
		tip->dtt_ctfp = DT_FPTR_CTFP(dtp);
		tip->dtt_type = DT_FPTR_TYPE(dtp);
	}

	tip->dtt_object = dmp->dm_name;
	return (0);
}

static dtrace_objinfo_t *
dt_module_info(const dt_module_t *dmp, dtrace_objinfo_t *dto)
{
	dto->dto_name = dmp->dm_name;
	dto->dto_file = dmp->dm_file;
	dto->dto_id = dmp->dm_modid;
	dto->dto_flags = 0;

	if (dmp->dm_flags & DT_DM_KERNEL)
		dto->dto_flags |= DTRACE_OBJ_F_KERNEL;
	if (dmp->dm_flags & DT_DM_PRIMARY)
		dto->dto_flags |= DTRACE_OBJ_F_PRIMARY;

	dto->dto_text_va = dmp->dm_text_va;
	dto->dto_text_size = dmp->dm_text_size;
	dto->dto_data_va = dmp->dm_data_va;
	dto->dto_data_size = dmp->dm_data_size;
	dto->dto_bss_va = dmp->dm_bss_va;
	dto->dto_bss_size = dmp->dm_bss_size;

	return (dto);
}

int
dtrace_object_iter(dtrace_hdl_t *dtp, dtrace_obj_f *func, void *data)
{
	const dt_module_t *dmp = dt_list_next(&dtp->dt_modlist);
	dtrace_objinfo_t dto;
	int rv;

	for (; dmp != NULL; dmp = dt_list_next(dmp)) {
		if ((rv = (*func)(dtp, dt_module_info(dmp, &dto), data)) != 0)
			return (rv);
	}

	return (0);
}

int
dtrace_object_info(dtrace_hdl_t *dtp, const char *object, dtrace_objinfo_t *dto)
{
	dt_module_t *dmp;

	if (object == DTRACE_OBJ_EVERY || object == DTRACE_OBJ_KMODS ||
	    object == DTRACE_OBJ_UMODS || dto == NULL)
		return (dt_set_errno(dtp, EINVAL));

	if ((dmp = dt_module_from_object(dtp, object)) == NULL)
		return (-1); /* dt_errno is set for us */

	if (dt_module_load(dtp, dmp) == -1)
		return (-1); /* dt_errno is set for us */

	(void) dt_module_info(dmp, dto);
	return (0);
}
