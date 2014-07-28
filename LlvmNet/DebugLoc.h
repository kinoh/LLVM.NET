#pragma once
#include "llvm/Support/DebugLoc.h"

namespace LLVM
{

ref class MDNode;
ref class LLVMContext;

public ref class DebugLoc
{
private:
	bool constructed;
internal:
	llvm::DebugLoc *base;
	DebugLoc(llvm::DebugLoc *base);

public:
	!DebugLoc();
	virtual ~DebugLoc();
	DebugLoc();
	static DebugLoc ^get(unsigned Line, unsigned Col, MDNode ^Scope);
	static DebugLoc ^get(unsigned Line, unsigned Col, MDNode ^Scope, MDNode ^InlinedAt);
	static DebugLoc ^getFromDILocation(MDNode ^N);
	static DebugLoc ^getFromDILexicalBlock(MDNode ^N);
	bool isUnknown();
	unsigned getLine();
	unsigned getCol();
	MDNode ^getScope(LLVMContext ^Ctx);
	MDNode ^getInlinedAt(LLVMContext ^Ctx);
	// void getScopeAndInlinedAt(MDNode *&Scope, MDNode *&IA, const LLVMContext &Ctx);
	MDNode ^getAsMDNode(LLVMContext ^Ctx);
	// bool operator==(const DebugLoc &DL);
	// bool operator!=(const DebugLoc &DL);
	void dump(LLVMContext ^Ctx);
};

}
