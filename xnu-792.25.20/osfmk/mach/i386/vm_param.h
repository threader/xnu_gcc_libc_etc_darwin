/*
 * Copyright (c) 2000-2004 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
/*
 * @OSF_COPYRIGHT@
 */
/* 
 * Mach Operating System
 * Copyright (c) 1991,1990,1989,1988 Carnegie Mellon University
 * All Rights Reserved.
 * 
 * Permission to use, copy, modify and distribute this software and its
 * documentation is hereby granted, provided that both the copyright
 * notice and this permission notice appear in all copies of the
 * software, derivative works or modified versions, and any portions
 * thereof, and that both notices appear in supporting documentation.
 * 
 * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"
 * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR
 * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.
 * 
 * Carnegie Mellon requests users of this software to return to
 * 
 *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU
 *  School of Computer Science
 *  Carnegie Mellon University
 *  Pittsburgh PA 15213-3890
 * 
 * any improvements or extensions that they make and grant Carnegie Mellon
 * the rights to redistribute these changes.
 */

/* 
 * Copyright (c) 1994 The University of Utah and
 * the Computer Systems Laboratory at the University of Utah (CSL).
 * All rights reserved.
 *
 * Permission to use, copy, modify and distribute this software is hereby
 * granted provided that (1) source code retains these copyright, permission,
 * and disclaimer notices, and (2) redistributions including binaries
 * reproduce the notices in supporting documentation, and (3) all advertising
 * materials mentioning features or use of this software display the following
 * acknowledgement: ``This product includes software developed by the
 * Computer Systems Laboratory at the University of Utah.''
 *
 * THE UNIVERSITY OF UTAH AND CSL ALLOW FREE USE OF THIS SOFTWARE IN ITS "AS
 * IS" CONDITION.  THE UNIVERSITY OF UTAH AND CSL DISCLAIM ANY LIABILITY OF
 * ANY KIND FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.
 *
 * CSL requests users of this software to return to csl-dist@cs.utah.edu any
 * improvements that they make and grant CSL redistribution rights.
 *
 */

/*
 *	File:	vm_param.h
 *	Author:	Avadis Tevanian, Jr.
 *	Date:	1985
 *
 *	I386 machine dependent virtual memory parameters.
 *	Most of the declarations are preceeded by I386_ (or i386_)
 *	which is OK because only I386 specific code will be using
 *	them.
 */

#ifndef	_MACH_I386_VM_PARAM_H_
#define _MACH_I386_VM_PARAM_H_

#define BYTE_SIZE		8		/* byte size in bits */

#define I386_PGBYTES	4096	/* bytes per 80386 page */
#define I386_PGSHIFT	12		/* number of bits to shift for pages */

#define	PAGE_SIZE		I386_PGBYTES
#define	PAGE_SHIFT		I386_PGSHIFT
#define	PAGE_MASK		(PAGE_SIZE - 1)

/*
 *	Convert bytes to pages and convert pages to bytes.
 *	No rounding is used.
 */

#define i386_btop(x)		(((pmap_paddr_t)(x)) >> I386_PGSHIFT)
#define machine_btop(x)		i386_btop(x)
#define i386_ptob(x)		(((pmap_paddr_t)(x)) << I386_PGSHIFT)

/*
 *	Round off or truncate to the nearest page.  These will work
 *	for either addresses or counts.  (i.e. 1 byte rounds to 1 page
 *	bytes.
 */

#define i386_round_page(x)	((((pmap_paddr_t)(x)) + I386_PGBYTES - 1) & \
					~(I386_PGBYTES-1))
#define i386_trunc_page(x)	(((pmap_paddr_t)(x)) & ~(I386_PGBYTES-1))



#define VM_MIN_ADDRESS64	((user_addr_t) 0x0000000000000000ULL)
/*
 * default top of user stack... it grows down from here
 */
#define VM_USRSTACK64		((user_addr_t) 0x00007FFF5FC00000ULL)
#define VM_DYLD64		((user_addr_t) 0x00007FFF5FC00000ULL)
#define VM_LIB64_SHR_DATA	((user_addr_t) 0x00007FFF60000000ULL)
#define VM_LIB64_SHR_TEXT	((user_addr_t) 0x00007FFF80000000ULL)
/*
 * the end of the usable user address space , for now about 47 bits.
 * the 64 bit commpage is past the end of this
 */
#define VM_MAX_PAGE_ADDRESS	((user_addr_t) 0x00007FFFFFE00000ULL)
/*
 * canonical end of user address space for limits checking
 */
#define VM_MAX_USER_PAGE_ADDRESS ((user_addr_t)0x00007FFFFFFFF000ULL)



/* system-wide values */
#define MACH_VM_MIN_ADDRESS		((mach_vm_offset_t) 0)
#define MACH_VM_MAX_ADDRESS		((mach_vm_offset_t) VM_MAX_PAGE_ADDRESS)

/* process-relative values (all 32-bit legacy only for now) */
#define VM_MIN_ADDRESS		((vm_offset_t) 0)
#define VM_USRSTACK32		((vm_offset_t) 0xC0000000)
#define VM_MAX_ADDRESS		((vm_offset_t) 0xFFE00000)




#ifdef	KERNEL_PRIVATE 

/* Kernel-wide values */
#define VM_MIN_KERNEL_ADDRESS	((vm_offset_t) 0x00001000U)
/*
 * XXX
 * The kernel max VM address is limited to 0xFF3FFFFF for now because
 * some data structures are explicitly allocated at 0xFF400000 without
 * VM's knowledge (see osfmk/i386/locore.s for the allocation of PTmap and co.).
 * We can't let VM allocate memory from there.
 */

#define VM_MAX_KERNEL_ADDRESS	((vm_offset_t) 0xFE7FFFFF)
#define KERNEL_STACK_SIZE		(I386_PGBYTES*4)

#define VM_MAP_MIN_ADDRESS	MACH_VM_MIN_ADDRESS
#define VM_MAP_MAX_ADDRESS	MACH_VM_MAX_ADDRESS

/* FIXME  - always leave like this? */
#define	INTSTACK_SIZE	(I386_PGBYTES*4)

#ifdef	MACH_KERNEL_PRIVATE

/* For implementing legacy 32-bit interfaces */
#define VM32_SUPPORT
#define VM32_MIN_ADDRESS		((vm32_offset_t) 0)
#define VM32_MAX_ADDRESS		((vm32_offset_t) (VM_MAX_PAGE_ADDRESS & 0xFFFFFFFF))

#define LINEAR_KERNEL_ADDRESS	((vm_offset_t) 0x00000000)

#define VM_MIN_KERNEL_LOADED_ADDRESS	((vm_offset_t) 0x00000000U)
#define VM_MAX_KERNEL_LOADED_ADDRESS	((vm_offset_t) 0x1fffffffU)

#define NCOPY_WINDOWS	4

/*
 *	Conversion between 80386 pages and VM pages
 */

#define trunc_i386_to_vm(p)	(atop(trunc_page(i386_ptob(p))))
#define round_i386_to_vm(p)	(atop(round_page(i386_ptob(p))))
#define vm_to_i386(p)		(i386_btop(ptoa(p)))

#define PMAP_ENTER(pmap, virtual_address, page, protection, flags, wired) \
	MACRO_BEGIN					\
	pmap_t __pmap = (pmap);				\
	vm_page_t __page = (page);			\
	vm_prot_t __prot__ =				\
		(protection) & ~(page)->page_lock;	\
							\
	if (__pmap == kernel_pmap) {			\
		__prot__ |= VM_PROT_WRITE;		\
	} else {					\
		assert(!__page->encrypted);		\
	}						\
							\
	pmap_enter(					\
		__pmap,					\
		(virtual_address),			\
		__page->phys_page,			\
		__prot__,				\
		flags,					\
		(wired)					\
	 );						\
	MACRO_END

#define IS_USERADDR64_CANONICAL(addr)			\
	((addr) < (VM_MAX_USER_PAGE_ADDRESS + PAGE_SIZE))

#endif	/* MACH_KERNEL_PRIVATE */

#endif	/* KERNEL_PRIVATE */

#endif	/* _MACH_I386_VM_PARAM_H_ */
