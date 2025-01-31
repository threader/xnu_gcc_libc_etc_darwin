#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <mach/machine.h>
#include <mach-o/arch.h>
#include <mach-o/fat.h>
#include <mach-o/loader.h>
#include <architecture/byte_order.h>


/*
 * cpusubtype_findbestarch() is passed a cputype and cpusubtype and a set of
 * fat_arch structs and selects the best one that matches (if any) and returns
 * a pointer to that fat_arch struct (or NULL).  The fat_arch structs must be
 * in the host byte sex and correct such that the fat_archs really points to
 * enough memory for nfat_arch structs.  It is possible that this routine could
 * fail if new cputypes or cpusubtypes are added and an old version of this
 * routine is used.  But if there is an exact match between the cputype and
 * cpusubtype and one of the fat_arch structs this routine will always succeed.
 */
static
struct fat_arch *
cpusubtype_findbestarch(
    cpu_type_t cputype,
    cpu_subtype_t cpusubtype,
    struct fat_header *fat,
    off_t size)
{
    unsigned long archi;
    struct fat_arch *first_arch, *arch, *found_arch;
    int nfat_archs;

    nfat_archs = NXSwapBigLongToHost(fat->nfat_arch);
    arch = (struct fat_arch *)((char *)fat + sizeof(struct fat_header));
    if ( (u_int8_t *) fat + size < (u_int8_t *)  &arch[nfat_archs])
        return NULL;

    first_arch = malloc(nfat_archs * sizeof(struct fat_arch));
    memcpy(first_arch, arch, nfat_archs * sizeof(struct fat_arch));
	
    /*
      * Also convert to host endianness as we go through the list
     */
    for (archi = 0, arch = first_arch; archi < nfat_archs; archi++, arch++) {
        arch->cputype = NXSwapBigIntToHost(arch->cputype);
        arch->cpusubtype = NXSwapBigIntToHost(arch->cpusubtype);
     }

	found_arch = NXFindBestFatArch(cputype, cpusubtype, first_arch, nfat_archs);

	free(first_arch);
	if(found_arch)
	{
		//found_arch points into the temporary host endian copy that we just freed...
		//calculate the location in the original array and return that.
		arch = (struct fat_arch *)((char *)fat + sizeof(struct fat_header));
		return &arch[found_arch - first_arch];
	}
	return NULL;
}

__private_extern__ void
find_arch(
    u_int8_t **dataP,
    off_t *sizeP,
    cpu_type_t cputype,
    cpu_subtype_t cpusubtype,
    u_int8_t *data_ptr,
    off_t filesize)
{
    struct fat_header *fat_hdr;
    struct mach_header *mach_hdr;
    struct fat_arch *best_arch;
    struct {
        struct fat_header hdr;
        struct fat_arch arch;
    } fakeHeader;
    int is_fat;
    int is_mh;
    int is_hm;

    fat_hdr = (struct fat_header *) data_ptr;
    is_fat = (FAT_MAGIC == fat_hdr->magic || FAT_CIGAM == fat_hdr->magic);

    mach_hdr = (struct mach_header *) data_ptr;
    is_hm = (MH_CIGAM == mach_hdr->magic);
    is_mh = (MH_MAGIC == mach_hdr->magic) || is_hm;

    // If it is full fat or not an executable then return unchanged.
    if (cputype == CPU_TYPE_ANY || !(is_mh || is_fat)) {
        if (sizeP) *sizeP = filesize;
        if (dataP) *dataP = data_ptr;
        return;
    }

    if (is_mh) {
        fat_hdr = &fakeHeader.hdr;
        fakeHeader.hdr.magic = FAT_MAGIC;
        fakeHeader.hdr.nfat_arch = NXSwapHostLongToBig(1);
        fakeHeader.arch.offset = NXSwapHostIntToBig(0);
        fakeHeader.arch.size = NXSwapHostLongToBig((long) filesize);
	if (is_hm) {
	    fakeHeader.arch.cputype = NXSwapHostLongToLittle(mach_hdr->cputype);
	    fakeHeader.arch.cpusubtype = NXSwapHostLongToLittle(mach_hdr->cpusubtype);
	} else {
	    fakeHeader.arch.cputype = NXSwapHostIntToBig(mach_hdr->cputype);
	    fakeHeader.arch.cpusubtype = NXSwapHostIntToBig(mach_hdr->cpusubtype);
	}
    }

    /*
     *  Map portion that must be accessible directly into
     *  kernel's map.
     */
    best_arch = cpusubtype_findbestarch(cputype, cpusubtype, fat_hdr, filesize);

    /* Return our results. */
    if (best_arch) {
        if (sizeP) *sizeP = NXSwapBigLongToHost(best_arch->size);
        if (dataP) *dataP = data_ptr + NXSwapBigLongToHost(best_arch->offset);
    } else {
        if (sizeP) *sizeP = 0;
        if (dataP) *dataP = 0;
    }
}


