#include "IntrinsicInst.h"
#include "Instructions.h"
#include "Value.h"
#include "IntrinsicInst.h"
#include "Metadata.h"
#include "Constants.h"
#include "Constant.h"
#include "Type.h"

using namespace LLVM;

IntrinsicInst::IntrinsicInst(llvm::IntrinsicInst *base)
	: base(base)
	, CallInst(base)
{
}
IntrinsicInst::!IntrinsicInst()
{
}
IntrinsicInst::~IntrinsicInst()
{
	this->!IntrinsicInst();
}
Intrinsic::ID IntrinsicInst::getIntrinsicID()
{
	return safe_cast<Intrinsic::ID>(base->getIntrinsicID());
}
inline bool IntrinsicInst::classof(CallInst ^I)
{
	return llvm::IntrinsicInst::classof(I->base);
}
inline bool IntrinsicInst::classof(Value ^V)
{
	return llvm::IntrinsicInst::classof(V->base);
}


DbgInfoIntrinsic::DbgInfoIntrinsic(llvm::DbgInfoIntrinsic *base)
	: base(base)
	, IntrinsicInst(base)
{
}
DbgInfoIntrinsic::!DbgInfoIntrinsic()
{
}
DbgInfoIntrinsic::~DbgInfoIntrinsic()
{
	this->!DbgInfoIntrinsic();
}
inline bool DbgInfoIntrinsic::classof(IntrinsicInst ^I)
{
	return llvm::DbgInfoIntrinsic::classof(I->base);
}
inline bool DbgInfoIntrinsic::classof(Value ^V)
{
	return llvm::DbgInfoIntrinsic::classof(V->base);
}
Value ^DbgInfoIntrinsic::StripCast(Value ^C)
{
	return gcnew Value(llvm::DbgInfoIntrinsic::StripCast(C->base));
}


DbgDeclareInst::DbgDeclareInst(llvm::DbgDeclareInst *base)
	: base(base)
	, DbgInfoIntrinsic(base)
{
}
DbgDeclareInst::!DbgDeclareInst()
{
}
DbgDeclareInst::~DbgDeclareInst()
{
	this->!DbgDeclareInst();
}
Value ^DbgDeclareInst::getAddress()
{
	return gcnew Value(base->getAddress());
}
MDNode ^DbgDeclareInst::getVariable()
{
	return gcnew MDNode(base->getVariable());
}
inline bool DbgDeclareInst::classof(IntrinsicInst ^I)
{
	return llvm::DbgDeclareInst::classof(I->base);
}
inline bool DbgDeclareInst::classof(Value ^V)
{
	return llvm::DbgDeclareInst::classof(V->base);
}


DbgValueInst::DbgValueInst(llvm::DbgValueInst *base)
	: base(base)
	, DbgInfoIntrinsic(base)
{
}
DbgValueInst::!DbgValueInst()
{
}
DbgValueInst::~DbgValueInst()
{
	this->!DbgValueInst();
}
Value ^DbgValueInst::getValue()
{
	return gcnew Value(base->getValue());
}
uint64_t DbgValueInst::getOffset()
{
	return base->getOffset();
}
MDNode ^DbgValueInst::getVariable()
{
	return gcnew MDNode(base->getVariable());
}
inline bool DbgValueInst::classof(IntrinsicInst ^I)
{
	return llvm::DbgValueInst::classof(I->base);
}
inline bool DbgValueInst::classof(Value ^V)
{
	return llvm::DbgValueInst::classof(V->base);
}


MemIntrinsic::MemIntrinsic(llvm::MemIntrinsic *base)
	: base(base)
	, IntrinsicInst(base)
{
}
MemIntrinsic::!MemIntrinsic()
{
}
MemIntrinsic::~MemIntrinsic()
{
	this->!MemIntrinsic();
}
Value ^MemIntrinsic::getRawDest()
{
	return gcnew Value(base->getRawDest());
}
Value ^MemIntrinsic::getLength()
{
	return gcnew Value(base->getLength());
}
ConstantInt ^MemIntrinsic::getAlignmentCst()
{
	return gcnew ConstantInt(base->getAlignmentCst());
}
unsigned MemIntrinsic::getAlignment()
{
	return base->getAlignment();
}
ConstantInt ^MemIntrinsic::getVolatileCst()
{
	return gcnew ConstantInt(base->getVolatileCst());
}
bool MemIntrinsic::isVolatile()
{
	return base->isVolatile();
}
unsigned MemIntrinsic::getDestAddressSpace()
{
	return base->getDestAddressSpace();
}
Value ^MemIntrinsic::getDest()
{
	return gcnew Value(base->getDest());
}
void MemIntrinsic::setDest(Value ^Ptr)
{
	base->setDest(Ptr->base);
}
void MemIntrinsic::setLength(Value ^L)
{
	base->setLength(L->base);
}
void MemIntrinsic::setAlignment(Constant ^A)
{
	base->setAlignment(A->base);
}
void MemIntrinsic::setVolatile(Constant ^V)
{
	base->setVolatile(V->base);
}
Type ^MemIntrinsic::getAlignmentType()
{
	return gcnew Type(base->getAlignmentType());
}
inline bool MemIntrinsic::classof(IntrinsicInst ^I)
{
	return llvm::MemIntrinsic::classof(I->base);
}
inline bool MemIntrinsic::classof(Value ^V)
{
	return llvm::MemIntrinsic::classof(V->base);
}


MemSetInst::MemSetInst(llvm::MemSetInst *base)
	: base(base)
	, MemIntrinsic(base)
{
}
MemSetInst::!MemSetInst()
{
}
MemSetInst::~MemSetInst()
{
	this->!MemSetInst();
}
Value ^MemSetInst::getValue()
{
	return gcnew Value(base->getValue());
}
void MemSetInst::setValue(Value ^Val)
{
	base->setValue(Val->base);
}
inline bool MemSetInst::classof(IntrinsicInst ^I)
{
	return llvm::MemSetInst::classof(I->base);
}
inline bool MemSetInst::classof(Value ^V)
{
	return llvm::MemSetInst::classof(V->base);
}


MemTransferInst::MemTransferInst(llvm::MemTransferInst *base)
	: base(base)
	, MemIntrinsic(base)
{
}
MemTransferInst::!MemTransferInst()
{
}
MemTransferInst::~MemTransferInst()
{
	this->!MemTransferInst();
}
Value ^MemTransferInst::getRawSource()
{
	return gcnew Value(base->getRawSource());
}
Value ^MemTransferInst::getSource()
{
	return gcnew Value(base->getSource());
}
unsigned MemTransferInst::getSourceAddressSpace()
{
	return base->getSourceAddressSpace();
}
void MemTransferInst::setSource(Value ^Ptr)
{
	base->setSource(Ptr->base);
}
inline bool MemTransferInst::classof(IntrinsicInst ^I)
{
	return llvm::MemTransferInst::classof(I->base);
}
inline bool MemTransferInst::classof(Value ^V)
{
	return llvm::MemTransferInst::classof(V->base);
}


MemCpyInst::MemCpyInst(llvm::MemCpyInst *base)
	: base(base)
	, MemTransferInst(base)
{
}
MemCpyInst::!MemCpyInst()
{
}
MemCpyInst::~MemCpyInst()
{
	this->!MemCpyInst();
}
inline bool MemCpyInst::classof(IntrinsicInst ^I)
{
	return llvm::MemCpyInst::classof(I->base);
}
inline bool MemCpyInst::classof(Value ^V)
{
	return llvm::MemCpyInst::classof(V->base);
}


MemMoveInst::MemMoveInst(llvm::MemMoveInst *base)
	: base(base)
	, MemTransferInst(base)
{
}
MemMoveInst::!MemMoveInst()
{
}
MemMoveInst::~MemMoveInst()
{
	this->!MemMoveInst();
}
inline bool MemMoveInst::classof(IntrinsicInst ^I)
{
	return llvm::MemMoveInst::classof(I->base);
}
inline bool MemMoveInst::classof(Value ^V)
{
	return llvm::MemMoveInst::classof(V->base);
}


VAStartInst::VAStartInst(llvm::VAStartInst *base)
	: base(base)
	, IntrinsicInst(base)
{
}
VAStartInst::!VAStartInst()
{
}
VAStartInst::~VAStartInst()
{
	this->!VAStartInst();
}
inline bool VAStartInst::classof(IntrinsicInst ^I)
{
	return llvm::VAStartInst::classof(I->base);
}
inline bool VAStartInst::classof(Value ^V)
{
	return llvm::VAStartInst::classof(V->base);
}
Value ^VAStartInst::getArgList()
{
	return gcnew Value(base->getArgList());
}


VAEndInst::VAEndInst(llvm::VAEndInst *base)
	: base(base)
	, IntrinsicInst(base)
{
}
VAEndInst::!VAEndInst()
{
}
VAEndInst::~VAEndInst()
{
	this->!VAEndInst();
}
inline bool VAEndInst::classof(IntrinsicInst ^I)
{
	return llvm::VAEndInst::classof(I->base);
}
inline bool VAEndInst::classof(Value ^V)
{
	return llvm::VAEndInst::classof(V->base);
}
Value ^VAEndInst::getArgList()
{
	return gcnew Value(base->getArgList());
}


VACopyInst::VACopyInst(llvm::VACopyInst *base)
	: base(base)
	, IntrinsicInst(base)
{
}
VACopyInst::!VACopyInst()
{
}
VACopyInst::~VACopyInst()
{
	this->!VACopyInst();
}
inline bool VACopyInst::classof(IntrinsicInst ^I)
{
	return llvm::VACopyInst::classof(I->base);
}
inline bool VACopyInst::classof(Value ^V)
{
	return llvm::VACopyInst::classof(V->base);
}
Value ^VACopyInst::getDest()
{
	return gcnew Value(base->getDest());
}
Value ^VACopyInst::getSrc()
{
	return gcnew Value(base->getSrc());
}
