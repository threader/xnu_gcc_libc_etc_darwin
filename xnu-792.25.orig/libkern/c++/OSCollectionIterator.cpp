/*
 * Copyright (c) 2000 Apple Computer, Inc. All rights reserved.
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
/* IOArray.h created by rsulack on Thu 11-Sep-1997 */

#include <libkern/c++/OSCollectionIterator.h>
#include <libkern/c++/OSCollection.h>
#include <libkern/c++/OSArray.h>
#include <libkern/c++/OSLib.h>

#define super OSIterator

OSDefineMetaClassAndStructors(OSCollectionIterator, OSIterator)

#if OSALLOCDEBUG
extern "C" {
    extern int debug_container_malloc_size;
};
#define ACCUMSIZE(s) do { debug_container_malloc_size += (s); } while(0)
#else
#define ACCUMSIZE(s)
#endif

bool OSCollectionIterator::initWithCollection(const OSCollection *inColl)
{
    if ( !super::init() || !inColl)
        return false;

    inColl->retain();
    collection = inColl;
    collIterator = 0;
    initialUpdateStamp = 0;
    valid = false;

    return this;
}

OSCollectionIterator *
OSCollectionIterator::withCollection(const OSCollection *inColl)
{

    OSCollectionIterator *me = new OSCollectionIterator;

    if (me && !me->initWithCollection(inColl)) {
        me->release();
        return 0;
    }

    return me;
}

void OSCollectionIterator::free()
{
    if (collIterator) {
        kfree(collIterator, collection->iteratorSize());
	ACCUMSIZE(-(collection->iteratorSize()));
        collIterator = 0;
    }

    if (collection) {
        collection->release();
        collection = 0;
    }

    super::free();
}

void OSCollectionIterator::reset()
{
    valid = false;

    if (!collIterator) {
        collIterator = (void *)kalloc(collection->iteratorSize());
	ACCUMSIZE(collection->iteratorSize());
        if (!collIterator)
            return;
    }

    if (!collection->initIterator(collIterator))
        return;

    initialUpdateStamp = collection->updateStamp;
    valid = true;
}

bool OSCollectionIterator::isValid()
{
    if (!collIterator) {
        collIterator = (void *)kalloc(collection->iteratorSize());
	ACCUMSIZE(collection->iteratorSize());
        if (!collection->initIterator(collIterator))
            return false;
        initialUpdateStamp = collection->updateStamp;
        valid = true;
    }
    else if (!valid || collection->updateStamp != initialUpdateStamp)
        return false;
    
    return true;
}

OSObject *OSCollectionIterator::getNextObject()
{
    OSObject *retObj;
    bool retVal;

    if (!isValid())
        return 0;

    retVal = collection->getNextObjectForIterator(collIterator, &retObj);
    return (retVal)? retObj : 0;
}

