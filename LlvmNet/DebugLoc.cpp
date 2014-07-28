#include "DebugLoc.h"
#include "Metadata.h"
#include "LLVMContext.h"

using namespace LLVM;

DebugLoc::DebugLoc(llvm::DebugLoc *base)
	: base(base)
	, constructed(false)
{
}
DebugLoc::!DebugLoc()
{
	if (constructed)
	{
		delete base;
	}
}
DebugLoc::~DebugLoc()
{
	this->!DebugLoc();
}
DebugLoc::DebugLoc()
	: base(new llvm::DebugLoc())
	, constructed(true)
{
}
DebugLoc ^DebugLoc::get(unsigned Line, unsigned Col, MDNode ^Scope)
{
	return gcnew DebugLoc(&llvm::DebugLoc::get(Line, Col, Scope->base));
}
DebugLoc ^DebugLoc::get(unsigned Line, unsigned Col, MDNode ^Scope, MDNode ^InlinedAt)
{
	return gcnew DebugLoc(&llvm::DebugLoc::get(Line, Col, Scope->base, InlinedAt->base));
}
DebugLoc ^DebugLoc::getFromDILocation(MDNode ^N)
{
	return gcnew DebugLoc(&llvm::DebugLoc::getFromDILocation(N->base));
}
DebugLoc ^DebugLoc::getFromDILexicalBlock(MDNode ^N)
{
	return gcnew DebugLoc(&llvm::DebugLoc::getFromDILexicalBlock(N->base));
}
bool DebugLoc::isUnknown()
{
	return base->isUnknown();
}
unsigned DebugLoc::getLine()
{
	return base->getLine();
}
unsigned DebugLoc::getCol()
{
	return base->getCol();
}
MDNode ^DebugLoc::getScope(LLVMContext ^Ctx)
{
	return gcnew MDNode(base->getScope(*Ctx->base));
}
MDNode ^DebugLoc::getInlinedAt(LLVMContext ^Ctx)
{
	return gcnew MDNode(base->getInlinedAt(*Ctx->base));
}
MDNode ^DebugLoc::getAsMDNode(LLVMContext ^Ctx)
{
	return gcnew MDNode(base->getAsMDNode(*Ctx->base));
}
void DebugLoc::dump(LLVMContext ^Ctx)
{
	base->dump(*Ctx->base);
}
