/*
 * Copyright (c) 1998-2004 Apple Computer, Inc. All rights reserved.
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
 * Copyright (c) 1998 Apple Computer, Inc.  All rights reserved. 
 *
 * HISTORY
 *
 */

#ifndef	__IOKIT_IOTYPES_H
#define __IOKIT_IOTYPES_H

#ifndef IOKIT
#define IOKIT 1
#endif /* !IOKIT */

#if KERNEL
#include <IOKit/system.h>
#else
#include <mach/message.h>
#include <mach/vm_types.h>
#endif

#include <IOKit/IOReturn.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef	NULL
#define	NULL	0
#endif
	
/*
 * Simple data types.
 */
#ifndef __MACTYPES__	/* CF MacTypes.h */
#ifndef __TYPES__	/* guess... Mac Types.h */

#include <stdbool.h>
#include <libkern/OSTypes.h>

#endif /* __TYPES__ */
#endif /* __MACTYPES__ */

typedef UInt32		IOOptionBits;
typedef SInt32		IOFixed;
typedef UInt32		IOVersion;
typedef UInt32		IOItemCount;
typedef UInt32  	IOCacheMode;

typedef UInt32	 	IOByteCount;

  /* LP64todo - these will need to expand to mach_vm_address_t */
typedef vm_address_t	 IOVirtualAddress;
typedef IOVirtualAddress IOLogicalAddress;

#if 0

typedef UInt64	IOPhysicalAddress;
typedef UInt64	IOPhysicalLength;
#define IOPhysical32( hi, lo )		((UInt64) lo + ((UInt64)(hi) << 32))
#define IOPhysSize	64

#else

typedef UInt32	IOPhysicalAddress;
typedef UInt32	IOPhysicalLength;
#define IOPhysical32( hi, lo )		(lo)
#define IOPhysSize	32

#endif

#if __cplusplus
struct IOVirtualRange
{
    IOVirtualAddress	address;
    IOByteCount		length;
};
struct IOAddressRange
{
    mach_vm_address_t	address;
    mach_vm_size_t	length;
};
#else
typedef struct 
{
    IOVirtualAddress	address;
    IOByteCount		length;
} IOVirtualRange;

struct IOAddressRange
{
    mach_vm_address_t	address;
    mach_vm_size_t	length;
};
#endif

/*
 * Map between #defined or enum'd constants and text description.
 */
typedef struct {
	int value;
	const char *name;
} IONamedValue;


/*
 * Memory alignment -- specified as a power of two.
 */
typedef unsigned int	IOAlignment;

#define IO_NULL_VM_TASK		((vm_task_t)0)


/*
 * Pull in machine specific stuff.
 */

//#include <IOKit/machine/IOTypes.h>

#ifndef MACH_KERNEL

#ifndef __IOKIT_PORTS_DEFINED__
#define __IOKIT_PORTS_DEFINED__
#ifdef KERNEL
typedef struct OSObject * io_object_t;
#else /* KERNEL */
typedef mach_port_t	io_object_t;
#endif /* KERNEL */
#endif /* __IOKIT_PORTS_DEFINED__ */

#include <device/device_types.h>

typedef io_object_t	io_connect_t;
typedef io_object_t	io_enumerator_t;
typedef io_object_t	io_iterator_t;
typedef io_object_t	io_registry_entry_t;
typedef io_object_t	io_service_t;

#define	IO_OBJECT_NULL	((io_object_t) 0)

#endif /* MACH_KERNEL */

// IOConnectMapMemory memoryTypes
enum {
    kIODefaultMemoryType	= 0
};

enum {
    kIODefaultCache		= 0,
    kIOInhibitCache		= 1,
    kIOWriteThruCache		= 2,
    kIOCopybackCache		= 3,
    kIOWriteCombineCache	= 4
};

// IOMemory mapping options
enum {
    kIOMapAnywhere		= 0x00000001,

    kIOMapCacheMask		= 0x00000700,
    kIOMapCacheShift		= 8,
    kIOMapDefaultCache		= kIODefaultCache      << kIOMapCacheShift,
    kIOMapInhibitCache		= kIOInhibitCache      << kIOMapCacheShift,
    kIOMapWriteThruCache	= kIOWriteThruCache    << kIOMapCacheShift,
    kIOMapCopybackCache		= kIOCopybackCache     << kIOMapCacheShift,
    kIOMapWriteCombineCache	= kIOWriteCombineCache << kIOMapCacheShift,

    kIOMapUserOptionsMask	= 0x00000fff,

    kIOMapReadOnly		= 0x00001000,

    kIOMapStatic		= 0x01000000,
    kIOMapReference		= 0x02000000,
    kIOMapUnique		= 0x04000000
};

/*! @enum Scale Factors
    @discussion Used when a scale_factor parameter is required to define a unit of time.
    @constant kNanosecondScale Scale factor for nanosecond based times.
    @constant kMicrosecondScale Scale factor for microsecond based times.
    @constant kMillisecondScale Scale factor for millisecond based times.
    @constant kTickScale Scale factor for the standard (100Hz) tick.
    @constant kSecondScale Scale factor for second based times. */

enum {
    kNanosecondScale  = 1,
    kMicrosecondScale = 1000,
    kMillisecondScale = 1000 * 1000,
    kSecondScale      = 1000 * 1000 * 1000,
    kTickScale        = (kSecondScale / 100)
};

/* compatibility types */

#ifndef KERNEL
/*
 * Machine-independent caching specification.
 */
typedef enum {
        IO_CacheOff,                    // cache inhibit
        IO_WriteThrough,
        IO_CopyBack
} IOCache;

//typedef char OSString[64];
typedef unsigned int IODeviceNumber;
typedef unsigned int IOObjectNumber;

#endif

#ifdef __cplusplus
}
#endif

#endif /* ! __IOKIT_IOTYPES_H */
