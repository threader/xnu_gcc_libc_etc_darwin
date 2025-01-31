// Methods for type_info for -*- C++ -*- Run Time Type Identification.
// Copyright (C) 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002,
// 2003, 2004, 2005, 2006, 2007
// Free Software Foundation
//
// This file is part of GCC.
//
// GCC is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.

// GCC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with GCC; see the file COPYING.  If not, write to
// the Free Software Foundation, 51 Franklin Street, Fifth Floor,
// Boston, MA 02110-1301, USA. 

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

#include <stddef.h>
#include <typeinfo>
#include <cxxabi.h>

std::type_info::~type_info () { }

std::bad_cast::~bad_cast() throw() { }
std::bad_typeid::~bad_typeid() throw() { }

const char* 
std::bad_cast::what() const throw()
{
  return "std::bad_cast";
}

const char* 
std::bad_typeid::what() const throw()
{
  return "std::bad_typeid";
}


void __cxxabiv1::__cxa_bad_typeid()
{
	throw std::bad_typeid();
}

void __cxxabiv1::__cxa_bad_cast()
{
	throw std::bad_cast();
}



