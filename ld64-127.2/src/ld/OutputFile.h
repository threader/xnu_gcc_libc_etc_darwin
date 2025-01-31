/* -*- mode: C++; c-basic-offset: 4; tab-width: 4 -*-*
 *
 * Copyright (c) 2009 Apple Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_LICENSE_HEADER_END@
 */

#ifndef __OUTPUT_FILE_H__
#define __OUTPUT_FILE_H__

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/sysctl.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include <mach/mach_time.h>
#include <mach/vm_statistics.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>
#include <dlfcn.h>
#include <mach-o/dyld.h>

#include <vector>

#include "Options.h"
#include "ld.hpp"

namespace ld {
namespace tool {

class OutputFile
{
public:
								OutputFile(const Options& opts);

	
	// iterates all atoms in initial files
	void						write(ld::Internal&);
	bool						findSegment(ld::Internal& state, uint64_t addr, uint64_t* start, uint64_t* end, uint32_t* index);
	void						setLazyBindingInfoOffset(uint64_t lpAddress, uint32_t lpInfoOffset);
	uint32_t					dylibCount();
	const ld::dylib::File*		dylibByOrdinal(unsigned int ordinal);
	uint32_t					dylibToOrdinal(const ld::dylib::File*);
	uint32_t					encryptedTextStartOffset()	{ return _encryptedTEXTstartOffset; }
	uint32_t					encryptedTextEndOffset()	{ return _encryptedTEXTendOffset; }
	int							compressedOrdinalForAtom(const ld::Atom* target);
	
	
	
	bool						hasWeakExternalSymbols;
	bool						usesWeakExternalSymbols;
	bool						overridesWeakExternalSymbols;
	bool						_noReExportedDylibs;
	bool						hasThreadLocalVariableDefinitions;
	bool						pieDisabled;
	ld::Internal::FinalSection*	headerAndLoadCommandsSection;
	ld::Internal::FinalSection*	rebaseSection;
	ld::Internal::FinalSection*	bindingSection;
	ld::Internal::FinalSection*	weakBindingSection;
	ld::Internal::FinalSection*	lazyBindingSection;
	ld::Internal::FinalSection*	exportSection;
	ld::Internal::FinalSection*	splitSegInfoSection;
	ld::Internal::FinalSection*	functionStartsSection;
	ld::Internal::FinalSection*	symbolTableSection;
	ld::Internal::FinalSection*	stringPoolSection;
	ld::Internal::FinalSection*	localRelocationsSection;
	ld::Internal::FinalSection*	externalRelocationsSection;
	ld::Internal::FinalSection*	sectionRelocationsSection;
	ld::Internal::FinalSection*	indirectSymbolTableSection;
	
	struct RebaseInfo {
						RebaseInfo(uint8_t t, uint64_t addr) : _type(t), _address(addr) {}
		uint8_t			_type;
		uint64_t		_address;
		// for sorting
		int operator<(const RebaseInfo& rhs) const {
			// sort by type, then address
			if ( this->_type != rhs._type )
				return  (this->_type < rhs._type );
			return  (this->_address < rhs._address );
		}
	};

	struct BindingInfo {
						BindingInfo(uint8_t t, int ord, const char* sym, bool weak_import, uint64_t addr, int64_t add) 
							: _type(t), _flags(weak_import ? BIND_SYMBOL_FLAGS_WEAK_IMPORT : 0 ), _libraryOrdinal(ord), 
								_symbolName(sym), _address(addr), _addend(add) {}
						BindingInfo(uint8_t t, const char* sym, bool non_weak_definition, uint64_t addr, int64_t add) 
							: _type(t), _flags(non_weak_definition ? BIND_SYMBOL_FLAGS_NON_WEAK_DEFINITION : 0 ), 
							 _libraryOrdinal(0), _symbolName(sym), _address(addr), _addend(add) {}
		uint8_t			_type;
		uint8_t			_flags;
		int				_libraryOrdinal;
		const char*		_symbolName;
		uint64_t		_address;
		int64_t			_addend;
		
		// for sorting
		int operator<(const BindingInfo& rhs) const {
			// sort by library, symbol, type, then address
			if ( this->_libraryOrdinal != rhs._libraryOrdinal )
				return  (this->_libraryOrdinal < rhs._libraryOrdinal );
			if ( this->_symbolName != rhs._symbolName )
				return ( strcmp(this->_symbolName, rhs._symbolName) < 0 );
			if ( this->_type != rhs._type )
				return  (this->_type < rhs._type );
			return  (this->_address < rhs._address );
		}
	};
	
	struct SplitSegInfoEntry {
						SplitSegInfoEntry(uint64_t a, ld::Fixup::Kind k, uint32_t e=0) : address(a), kind(k), extra(e) {}
		uint64_t		address;
		ld::Fixup::Kind	kind;
        uint32_t        extra;
	};
	
private:
	void						buildDylibOrdinalMapping(ld::Internal&);
	bool						hasOrdinalForInstallPath(const char* path, int* ordinal);
	void						addLoadCommands(ld::Internal& state);
	void						addLinkEdit(ld::Internal& state);
	void						addPreloadLinkEdit(ld::Internal& state);
	void						generateLinkEditInfo(ld::Internal& state);
	void						buildSymbolTable(ld::Internal& state);
	void						writeOutputFile(ld::Internal& state);
	void						assignFileOffsets(ld::Internal& state);
	void						setSectionSizesAndAlignments(ld::Internal& state);
	void						addSectionRelocs(ld::Internal& state, ld::Internal::FinalSection* sect,  
												const ld::Atom* atom, ld::Fixup* fixupWithTarget, 
												ld::Fixup* fixupWithMinusTarget, ld::Fixup* fixupWithStore,
												const ld::Atom* target, const ld::Atom* minusTarget, 
												uint64_t targetAddend, uint64_t minusTargetAddend);
	void						addDyldInfo(ld::Internal& state, ld::Internal::FinalSection* sect,  
												const ld::Atom* atom, ld::Fixup* fixupWithTarget,
												ld::Fixup* fixupWithMinusTarget, ld::Fixup* fixupWithStore,
												const ld::Atom* target, const ld::Atom* minusTarget, 
												uint64_t targetAddend, uint64_t minusTargetAddend);
	void						addClassicRelocs(ld::Internal& state, ld::Internal::FinalSection* sect,  
												const ld::Atom* atom, ld::Fixup* fixupWithTarget, 
												ld::Fixup* fixupWithMinusTarget, ld::Fixup* fixupWithStore,
												const ld::Atom* target, const ld::Atom* minusTarget, 
												uint64_t targetAddend, uint64_t minusTargetAddend);
	bool						useExternalSectionReloc(const ld::Atom* atom, const ld::Atom* target, 
															ld::Fixup* fixupWithTarget);
	uint64_t					pageAlign(uint64_t addr);
	uint64_t					pageAlign(uint64_t addr, uint64_t pageSize);
	void						setLoadCommandsPadding(ld::Internal& state);
	void						assignAtomAddresses(ld::Internal& state);
	void						addRebaseInfo(const ld::Atom* atom, const ld::Fixup* fixup, const ld::Atom* target);
	void						makeRebasingInfo(ld::Internal& state);
	void						makeBindingInfo(ld::Internal& state);
	void						updateLINKEDITAddresses(ld::Internal& state);
	void						applyFixUps(ld::Internal& state, uint64_t mhAddress, const ld::Atom*  atom, uint8_t* buffer);
	uint64_t					addressOf(const ld::Internal& state, const ld::Fixup* fixup, const ld::Atom** target);
	bool						targetIsThumb(ld::Internal& state, const ld::Fixup* fixup);
	uint32_t					lazyBindingInfoOffsetForLazyPointerAddress(uint64_t lpAddress);
	void						copyNoOps(uint8_t* from, uint8_t* to, bool thumb);
	bool						isPointerToTarget(ld::Fixup::Kind kind);
	bool						isPointerFromTarget(ld::Fixup::Kind kind);
	bool						isPcRelStore(ld::Fixup::Kind kind);
	bool						isStore(ld::Fixup::Kind kind);
	bool						storeAddendOnly(const ld::Atom* inAtom, const ld::Atom* target, bool pcRel=false);
	bool						setsTarget(ld::Fixup::Kind kind);
	void						addFixupOutInfo(ld::Internal& state);
	void						makeRelocations(ld::Internal& state);
	void						makeSectionRelocations(ld::Internal& state);
	void						makeDyldInfo(ld::Internal& state);
	void						makeSplitSegInfo(ld::Internal& state);
	void						writeMapFile(ld::Internal& state);
	uint64_t					lookBackAddend(ld::Fixup::iterator fit);
	bool						takesNoDiskSpace(const ld::Section* sect);
	bool						hasZeroForFileOffset(const ld::Section* sect);
	
	void						printSectionLayout(ld::Internal& state);
	void						rangeCheck8(int64_t delta, ld::Internal& state, const ld::Atom* atom, 
																							const ld::Fixup* fixup);
	void						rangeCheck16(int64_t delta, ld::Internal& state, const ld::Atom* atom, 
																							const ld::Fixup* fixup);
	void						rangeCheckBranch32(int64_t delta, ld::Internal& state, const ld::Atom* atom, 
																							const ld::Fixup* fixup);
	void						rangeCheckAbsolute32(int64_t delta, ld::Internal& state, const ld::Atom* atom, 
																							const ld::Fixup* fixup);
	void						rangeCheckRIP32(int64_t delta, ld::Internal& state, const ld::Atom* atom, 
																							const ld::Fixup* fixup);
	void						rangeCheckARM12(int64_t delta, ld::Internal& state, const ld::Atom* atom, 
																							const ld::Fixup* fixup);
	void						rangeCheckARMBranch24(int64_t delta, ld::Internal& state, const ld::Atom* atom, 
																							const ld::Fixup* fixup);
	void						rangeCheckThumbBranch22(int64_t delta, ld::Internal& state, const ld::Atom* atom, 
																							const ld::Fixup* fixup);
	void						rangeCheckPPCBranch24(int64_t delta, ld::Internal& state, const ld::Atom* atom, 
																							const ld::Fixup* fixup);
	void						rangeCheckPPCBranch14(int64_t delta, ld::Internal& state, const ld::Atom* atom, 
																							const ld::Fixup* fixup);
	uint64_t					sectionOffsetOf(const ld::Internal& state, const ld::Fixup* fixup);
	uint64_t					tlvTemplateOffsetOf(const ld::Internal& state, const ld::Fixup* fixup);
	void						dumpAtomsBySection(ld::Internal& state, bool);
	void						synthesizeDebugNotes(ld::Internal& state);
	const char*					assureFullPath(const char* path);
	void						noteTextReloc(const ld::Atom* atom, const ld::Atom* target);

	
	static uint16_t				get16LE(uint8_t* loc);
	static void					set16LE(uint8_t* loc, uint16_t value);
	static uint32_t				get32LE(uint8_t* loc);
	static void					set32LE(uint8_t* loc, uint32_t value);
	static uint64_t				get64LE(uint8_t* loc);
	static void					set64LE(uint8_t* loc, uint64_t value);

	static uint16_t				get16BE(uint8_t* loc);
	static void					set16BE(uint8_t* loc, uint16_t value);
	static uint32_t				get32BE(uint8_t* loc);
	static void					set32BE(uint8_t* loc, uint32_t value);
	static uint64_t				get64BE(uint8_t* loc);
	static void					set64BE(uint8_t* loc, uint64_t value);



	const Options&							_options;
	std::map<const ld::dylib::File*, int>	_dylibToOrdinal;
	std::vector<const ld::dylib::File*>		_dylibsToLoad;
	std::vector<const char*>				_dylibOrdinalPaths;
	const bool								_hasDyldInfo;
	const bool								_hasSymbolTable;
	const bool								_hasSectionRelocations;
	const bool								_hasSplitSegInfo;
	const bool								_hasFunctionStartsInfo;
		  bool								_hasDynamicSymbolTable;
		  bool								_hasLocalRelocations;
		  bool								_hasExternalRelocations;
	uint64_t								_fileSize;
	std::map<uint64_t, uint32_t>			_lazyPointerAddressToInfoOffset;
	uint32_t								_encryptedTEXTstartOffset;
	uint32_t								_encryptedTEXTendOffset;
public:
	std::vector<const ld::Atom*>			_localAtoms;
	std::vector<const ld::Atom*>			_exportedAtoms;
	std::vector<const ld::Atom*>			_importedAtoms;
	uint32_t								_localSymbolsStartIndex;
	uint32_t								_localSymbolsCount;
	uint32_t								_globalSymbolsStartIndex;
	uint32_t								_globalSymbolsCount;
	uint32_t								_importSymbolsStartIndex;
	uint32_t								_importSymbolsCount;
	std::map<const ld::Atom*, uint32_t>		_atomToSymbolIndex;
	std::vector<RebaseInfo>					_rebaseInfo;
	std::vector<BindingInfo>				_bindingInfo;
	std::vector<BindingInfo>				_lazyBindingInfo;
	std::vector<BindingInfo>				_weakBindingInfo;
	std::vector<SplitSegInfoEntry>			_splitSegInfos;
	class HeaderAndLoadCommandsAbtract*		_headersAndLoadCommandAtom;
	class RelocationsAtomAbstract*			_sectionsRelocationsAtom;
	class RelocationsAtomAbstract*			_localRelocsAtom;
	class RelocationsAtomAbstract*			_externalRelocsAtom;
	class ClassicLinkEditAtom*				_symbolTableAtom;
	class ClassicLinkEditAtom*				_indirectSymbolTableAtom;
	class StringPoolAtom*					_stringPoolAtom;
	class LinkEditAtom*						_rebasingInfoAtom;
	class LinkEditAtom*						_bindingInfoAtom;
	class LinkEditAtom*						_lazyBindingInfoAtom;
	class LinkEditAtom*						_weakBindingInfoAtom;
	class LinkEditAtom*						_exportInfoAtom;
	class LinkEditAtom*						_splitSegInfoAtom;
	class LinkEditAtom*						_functionStartsAtom;
};

} // namespace tool 
} // namespace ld 

#endif // __OUTPUT_FILE_H__
