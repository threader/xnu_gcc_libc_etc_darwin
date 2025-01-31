/*
 * Copyright (c) 2000-2005 Apple Computer, Inc. All rights reserved.
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

#ifndef	_I386_MACHINE_ROUTINES_H_
#define	_I386_MACHINE_ROUTINES_H_

#include <mach/mach_types.h>
#include <mach/boolean.h>
#include <kern/kern_types.h>
#include <pexpert/pexpert.h>

#include <sys/cdefs.h>
#include <sys/appleapiopts.h>

__BEGIN_DECLS

/* are we a 64 bit platform ? */

boolean_t ml_is64bit(void);

/* is this a 64bit thread? */

boolean_t ml_thread_is64bit(thread_t);

/* is this a 64bit thread? */

boolean_t ml_state_is64bit(void *);

/* set state of fpu save area for signal handling */

void	ml_fp_setvalid(boolean_t);

void	ml_cpu_set_ldt(int);

/* Interrupt handling */

/* Initialize Interrupts */
void    ml_init_interrupt(void);

/* Get Interrupts Enabled */
boolean_t ml_get_interrupts_enabled(void);

/* Set Interrupts Enabled */
boolean_t ml_set_interrupts_enabled(boolean_t enable);

/* Check if running at interrupt context */
boolean_t ml_at_interrupt_context(void);

/* Generate a fake interrupt */
void ml_cause_interrupt(void);

void ml_get_timebase(unsigned long long *timestamp);
void ml_init_lock_timeout(void); 

/* Type for the Time Base Enable function */
typedef void (*time_base_enable_t)(cpu_id_t cpu_id, boolean_t enable);

/* Type for the IPI Hander */
typedef void (*ipi_handler_t)(void);

/* Struct for ml_processor_register */
struct ml_processor_info {
	cpu_id_t			cpu_id;
	boolean_t			boot_cpu;
	vm_offset_t			start_paddr;
	boolean_t			supports_nap;
	unsigned long		l2cr_value;
	time_base_enable_t	time_base_enable;
};

typedef struct ml_processor_info ml_processor_info_t;


/* Register a processor */
kern_return_t ml_processor_register(
        cpu_id_t cpu_id,
	uint32_t lapic_id,
        processor_t *processor,
        ipi_handler_t *ipi_handler,
	boolean_t boot_cpu);

/* Initialize Interrupts */
void ml_install_interrupt_handler(
    void *nub,
    int source,
    void *target,
    IOInterruptHandler handler,
    void *refCon);

#ifdef __APPLE_API_UNSTABLE
vm_offset_t
ml_static_ptovirt(
	vm_offset_t);

#ifdef	XNU_KERNEL_PRIVATE
vm_offset_t
ml_boot_ptovirt(
	vm_offset_t);
#endif

/* PCI config cycle probing */
boolean_t ml_probe_read(
	vm_offset_t paddr,
	unsigned int *val);
boolean_t ml_probe_read_64(
	addr64_t paddr,
	unsigned int *val);

/* Read physical address byte */
unsigned int ml_phys_read_byte(
	vm_offset_t paddr);
unsigned int ml_phys_read_byte_64(
	addr64_t paddr);

/* Read physical address half word */
unsigned int ml_phys_read_half(
	vm_offset_t paddr);
unsigned int ml_phys_read_half_64(
	addr64_t paddr);

/* Read physical address word*/
unsigned int ml_phys_read(
	vm_offset_t paddr);
unsigned int ml_phys_read_64(
	addr64_t paddr);
unsigned int ml_phys_read_word(
	vm_offset_t paddr);
unsigned int ml_phys_read_word_64(
	addr64_t paddr);

/* Read physical address double word */
unsigned long long ml_phys_read_double(
	vm_offset_t paddr);
unsigned long long ml_phys_read_double_64(
	addr64_t paddr);

/* Write physical address byte */
void ml_phys_write_byte(
	vm_offset_t paddr, unsigned int data);
void ml_phys_write_byte_64(
	addr64_t paddr, unsigned int data);

/* Write physical address half word */
void ml_phys_write_half(
	vm_offset_t paddr, unsigned int data);
void ml_phys_write_half_64(
	addr64_t paddr, unsigned int data);

/* Write physical address word */
void ml_phys_write(
	vm_offset_t paddr, unsigned int data);
void ml_phys_write_64(
	addr64_t paddr, unsigned int data);
void ml_phys_write_word(
	vm_offset_t paddr, unsigned int data);
void ml_phys_write_word_64(
	addr64_t paddr, unsigned int data);

/* Write physical address double word */
void ml_phys_write_double(
	vm_offset_t paddr, unsigned long long data);
void ml_phys_write_double_64(
	addr64_t paddr, unsigned long long data);

void ml_static_mfree(
	vm_offset_t,
	vm_size_t);

/* virtual to physical on wired pages */
vm_offset_t ml_vtophys(
	vm_offset_t vaddr);

/* Struct for ml_cpu_get_info */
struct ml_cpu_info {
	unsigned long		vector_unit;
	unsigned long		cache_line_size;
	unsigned long		l1_icache_size;
	unsigned long		l1_dcache_size;
	unsigned long		l2_settings;
	unsigned long		l2_cache_size;
	unsigned long		l3_settings;
	unsigned long		l3_cache_size;
};

typedef struct ml_cpu_info ml_cpu_info_t;

/* Get processor info */
void ml_cpu_get_info(ml_cpu_info_t *ml_cpu_info);

#endif /* __APPLE_API_UNSTABLE */

#ifdef __APPLE_API_PRIVATE
#if	defined(PEXPERT_KERNEL_PRIVATE) || defined(MACH_KERNEL_PRIVATE)
/* IO memory map services */

/* Map memory map IO space */
vm_offset_t ml_io_map(
	vm_offset_t phys_addr, 
	vm_size_t size);

/* boot memory allocation */
vm_offset_t ml_static_malloc(
	vm_size_t size);


extern uint32_t	bounce_pool_base;
extern uint32_t	bounce_pool_size;

void	ml_get_bouncepool_info(
			       vm_offset_t *phys_addr,
			       vm_size_t   *size);


#endif /* PEXPERT_KERNEL_PRIVATE || MACH_KERNEL_PRIVATE  */

/* Zero bytes starting at a physical address */
void bzero_phys(
	addr64_t phys_address,
	uint32_t length);

void ml_thread_policy(
	thread_t thread,
	unsigned policy_id,
	unsigned policy_info);

#define MACHINE_GROUP					0x00000001
#define MACHINE_NETWORK_GROUP			0x10000000
#define MACHINE_NETWORK_WORKLOOP		0x00000001
#define MACHINE_NETWORK_NETISR			0x00000002

/* Initialize the maximum number of CPUs */
void ml_init_max_cpus(
	unsigned long max_cpus);

/* Return the maximum number of CPUs set by ml_init_max_cpus() */
int ml_get_max_cpus(
	void);

extern void	ml_cpu_up(void);
extern void	ml_cpu_down(void);

extern int	set_be_bit(void);
extern int	clr_be_bit(void);
extern int	be_tracing(void);

extern void ml_set_maxsnoop(uint32_t maxdelay);
extern unsigned ml_get_maxsnoop(void);
extern void ml_set_maxbusdelay(uint32_t mdelay);
extern uint32_t ml_get_maxbusdelay(void);
extern void ml_hpet_cfg(uint32_t cpu, uint32_t hpetVect);

extern uint64_t tmrCvt(uint64_t time, uint64_t conversion);

#endif /* __APPLE_API_PRIVATE */

__END_DECLS

#endif /* _I386_MACHINE_ROUTINES_H_ */
