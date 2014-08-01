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
inline IntrinsicInst ^IntrinsicInst::_wrap(llvm::IntrinsicInst *base)
{
	return base ? gcnew IntrinsicInst(base) : nullptr;
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
inline DbgInfoIntrinsic ^DbgInfoIntrinsic::_wrap(llvm::DbgInfoIntrinsic *base)
{
	return base ? gcnew DbgInfoIntrinsic(base) : nullptr;
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
	return Value::_wrap(llvm::DbgInfoIntrinsic::StripCast(C->base));
}


DbgDeclareInst::DbgDeclareInst(llvm::DbgDeclareInst *base)
	: base(base)
	, DbgInfoIntrinsic(base)
{
}
inline DbgDeclareInst ^DbgDeclareInst::_wrap(llvm::DbgDeclareInst *base)
{
	return base ? gcnew DbgDeclareInst(base) : nullptr;
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
	return Value::_wrap(base->getAddress());
}
MDNode ^DbgDeclareInst::getVariable()
{
	return MDNode::_wrap(base->getVariable());
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
inline DbgValueInst ^DbgValueInst::_wrap(llvm::DbgValueInst *base)
{
	return base ? gcnew DbgValueInst(base) : nullptr;
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
	return Value::_wrap(base->getValue());
}
uint64_t DbgValueInst::getOffset()
{
	return base->getOffset();
}
MDNode ^DbgValueInst::getVariable()
{
	return MDNode::_wrap(base->getVariable());
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
inline MemIntrinsic ^MemIntrinsic::_wrap(llvm::MemIntrinsic *base)
{
	return base ? gcnew MemIntrinsic(base) : nullptr;
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
	return Value::_wrap(base->getRawDest());
}
Value ^MemIntrinsic::getLength()
{
	return Value::_wrap(base->getLength());
}
ConstantInt ^MemIntrinsic::getAlignmentCst()
{
	return ConstantInt::_wrap(base->getAlignmentCst());
}
unsigned MemIntrinsic::getAlignment()
{
	return base->getAlignment();
}
ConstantInt ^MemIntrinsic::getVolatileCst()
{
	return ConstantInt::_wrap(base->getVolatileCst());
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
	return Value::_wrap(base->getDest());
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
	return Type::_wrap(base->getAlignmentType());
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
inline MemSetInst ^MemSetInst::_wrap(llvm::MemSetInst *base)
{
	return base ? gcnew MemSetInst(base) : nullptr;
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
	return Value::_wrap(base->getValue());
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
inline MemTransferInst ^MemTransferInst::_wrap(llvm::MemTransferInst *base)
{
	return base ? gcnew MemTransferInst(base) : nullptr;
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
	return Value::_wrap(base->getRawSource());
}
Value ^MemTransferInst::getSource()
{
	return Value::_wrap(base->getSource());
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
inline MemCpyInst ^MemCpyInst::_wrap(llvm::MemCpyInst *base)
{
	return base ? gcnew MemCpyInst(base) : nullptr;
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
inline MemMoveInst ^MemMoveInst::_wrap(llvm::MemMoveInst *base)
{
	return base ? gcnew MemMoveInst(base) : nullptr;
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
inline VAStartInst ^VAStartInst::_wrap(llvm::VAStartInst *base)
{
	return base ? gcnew VAStartInst(base) : nullptr;
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
	return Value::_wrap(base->getArgList());
}


VAEndInst::VAEndInst(llvm::VAEndInst *base)
	: base(base)
	, IntrinsicInst(base)
{
}
inline VAEndInst ^VAEndInst::_wrap(llvm::VAEndInst *base)
{
	return base ? gcnew VAEndInst(base) : nullptr;
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
	return Value::_wrap(base->getArgList());
}


VACopyInst::VACopyInst(llvm::VACopyInst *base)
	: base(base)
	, IntrinsicInst(base)
{
}
inline VACopyInst ^VACopyInst::_wrap(llvm::VACopyInst *base)
{
	return base ? gcnew VACopyInst(base) : nullptr;
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
	return Value::_wrap(base->getDest());
}
Value ^VACopyInst::getSrc()
{
	return Value::_wrap(base->getSrc());
}
