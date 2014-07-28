#include "Instructions.h"
#include "llvm/ADT/Twine.h"
#include "InstrTypes.h"
#include "Instruction.h"
#include "llvm/ADT/ArrayRef.h"
#include "CallingConv.h"
#include "Attributes.h"
#include "llvm/ADT/SmallVector.h"
#include "Type.h"
#include "Value.h"
#include "Instruction.h"
#include "BasicBlock.h"
#include "DerivedTypes.h"
#include "LLVMContext.h"
#include "Constant.h"
#include "Function.h"
#include "Attributes.h"
#include "Use.h"
#include "Constants.h"
#include "Instructions.h"
#include <msclr/marshal.h>
#include "utils.h"

using namespace LLVM;

AllocaInst::AllocaInst(llvm::AllocaInst *base)
	: base(base)
	, UnaryInstruction(base)
	, constructed(false)
{
}
AllocaInst::!AllocaInst()
{
	if (constructed)
	{
		delete base;
	}
}
AllocaInst::~AllocaInst()
{
	this->!AllocaInst();
}
AllocaInst::AllocaInst(Type ^Ty)
	: base(new llvm::AllocaInst(Ty->base))
	, UnaryInstruction(base)
	, constructed(true)
{
}
AllocaInst::AllocaInst(Type ^Ty, Value ^ArraySize)
	: base(new llvm::AllocaInst(Ty->base, ArraySize->base))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::AllocaInst *AllocaInst::_construct(Type ^Ty, Value ^ArraySize, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return new llvm::AllocaInst(Ty->base, ArraySize->base, ctx.marshal_as<const char *>(Name));
}
AllocaInst::AllocaInst(Type ^Ty, Value ^ArraySize, System::String ^Name)
	: base(_construct(Ty, ArraySize, Name))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::AllocaInst *AllocaInst::_construct(Type ^Ty, Value ^ArraySize, System::String ^Name, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::AllocaInst(Ty->base, ArraySize->base, ctx.marshal_as<const char *>(Name), InsertBefore->base);
}
AllocaInst::AllocaInst(Type ^Ty, Value ^ArraySize, System::String ^Name, Instruction ^InsertBefore)
	: base(_construct(Ty, ArraySize, Name, InsertBefore))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::AllocaInst *AllocaInst::_construct(Type ^Ty, Value ^ArraySize, System::String ^Name, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::AllocaInst(Ty->base, ArraySize->base, ctx.marshal_as<const char *>(Name), InsertAtEnd->base);
}
AllocaInst::AllocaInst(Type ^Ty, Value ^ArraySize, System::String ^Name, BasicBlock ^InsertAtEnd)
	: base(_construct(Ty, ArraySize, Name, InsertAtEnd))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::AllocaInst *AllocaInst::_construct(Type ^Ty, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return new llvm::AllocaInst(Ty->base, ctx.marshal_as<const char *>(Name));
}
AllocaInst::AllocaInst(Type ^Ty, System::String ^Name)
	: base(_construct(Ty, Name))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::AllocaInst *AllocaInst::_construct(Type ^Ty, System::String ^Name, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::AllocaInst(Ty->base, ctx.marshal_as<const char *>(Name), InsertBefore->base);
}
AllocaInst::AllocaInst(Type ^Ty, System::String ^Name, Instruction ^InsertBefore)
	: base(_construct(Ty, Name, InsertBefore))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::AllocaInst *AllocaInst::_construct(Type ^Ty, System::String ^Name, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::AllocaInst(Ty->base, ctx.marshal_as<const char *>(Name), InsertAtEnd->base);
}
AllocaInst::AllocaInst(Type ^Ty, System::String ^Name, BasicBlock ^InsertAtEnd)
	: base(_construct(Ty, Name, InsertAtEnd))
	, UnaryInstruction(base)
	, constructed(true)
{
}
AllocaInst::AllocaInst(Type ^Ty, Value ^ArraySize, unsigned Align)
	: base(new llvm::AllocaInst(Ty->base, ArraySize->base, Align))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::AllocaInst *AllocaInst::_construct(Type ^Ty, Value ^ArraySize, unsigned Align, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return new llvm::AllocaInst(Ty->base, ArraySize->base, Align, ctx.marshal_as<const char *>(Name));
}
AllocaInst::AllocaInst(Type ^Ty, Value ^ArraySize, unsigned Align, System::String ^Name)
	: base(_construct(Ty, ArraySize, Align, Name))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::AllocaInst *AllocaInst::_construct(Type ^Ty, Value ^ArraySize, unsigned Align, System::String ^Name, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::AllocaInst(Ty->base, ArraySize->base, Align, ctx.marshal_as<const char *>(Name), InsertBefore->base);
}
AllocaInst::AllocaInst(Type ^Ty, Value ^ArraySize, unsigned Align, System::String ^Name, Instruction ^InsertBefore)
	: base(_construct(Ty, ArraySize, Align, Name, InsertBefore))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::AllocaInst *AllocaInst::_construct(Type ^Ty, Value ^ArraySize, unsigned Align, System::String ^Name, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::AllocaInst(Ty->base, ArraySize->base, Align, ctx.marshal_as<const char *>(Name), InsertAtEnd->base);
}
AllocaInst::AllocaInst(Type ^Ty, Value ^ArraySize, unsigned Align, System::String ^Name, BasicBlock ^InsertAtEnd)
	: base(_construct(Ty, ArraySize, Align, Name, InsertAtEnd))
	, UnaryInstruction(base)
	, constructed(true)
{
}
bool AllocaInst::isArrayAllocation()
{
	return base->isArrayAllocation();
}
Value ^AllocaInst::getArraySize()
{
	return gcnew Value(base->getArraySize());
}
PointerType ^AllocaInst::getType()
{
	return gcnew PointerType(base->getType());
}
Type ^AllocaInst::getAllocatedType()
{
	return gcnew Type(base->getAllocatedType());
}
unsigned AllocaInst::getAlignment()
{
	return base->getAlignment();
}
void AllocaInst::setAlignment(unsigned Align)
{
	base->setAlignment(Align);
}
bool AllocaInst::isStaticAlloca()
{
	return base->isStaticAlloca();
}
inline bool AllocaInst::classof(Instruction ^I)
{
	return llvm::AllocaInst::classof(I->base);
}
inline bool AllocaInst::classof(Value ^V)
{
	return llvm::AllocaInst::classof(V->base);
}


LoadInst::LoadInst(llvm::LoadInst *base)
	: base(base)
	, UnaryInstruction(base)
	, constructed(false)
{
}
LoadInst::!LoadInst()
{
	if (constructed)
	{
		delete base;
	}
}
LoadInst::~LoadInst()
{
	this->!LoadInst();
}
llvm::LoadInst *LoadInst::_construct(Value ^Ptr, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::LoadInst(Ptr->base, ctx.marshal_as<const char *>(NameStr), InsertBefore->base);
}
LoadInst::LoadInst(Value ^Ptr, System::String ^NameStr, Instruction ^InsertBefore)
	: base(_construct(Ptr, NameStr, InsertBefore))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::LoadInst *LoadInst::_construct(Value ^Ptr, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::LoadInst(Ptr->base, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base);
}
LoadInst::LoadInst(Value ^Ptr, System::String ^NameStr, BasicBlock ^InsertAtEnd)
	: base(_construct(Ptr, NameStr, InsertAtEnd))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::LoadInst *LoadInst::_construct(Value ^Ptr, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::LoadInst(Ptr->base, ctx.marshal_as<const char *>(NameStr));
}
LoadInst::LoadInst(Value ^Ptr, System::String ^NameStr)
	: base(_construct(Ptr, NameStr))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::LoadInst *LoadInst::_construct(Value ^Ptr, System::String ^NameStr, bool isVolatile)
{
	msclr::interop::marshal_context ctx;
	return new llvm::LoadInst(Ptr->base, ctx.marshal_as<const char *>(NameStr), isVolatile);
}
LoadInst::LoadInst(Value ^Ptr, System::String ^NameStr, bool isVolatile)
	: base(_construct(Ptr, NameStr, isVolatile))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::LoadInst *LoadInst::_construct(Value ^Ptr, System::String ^NameStr, bool isVolatile, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::LoadInst(Ptr->base, ctx.marshal_as<const char *>(NameStr), isVolatile, InsertBefore->base);
}
LoadInst::LoadInst(Value ^Ptr, System::String ^NameStr, bool isVolatile, Instruction ^InsertBefore)
	: base(_construct(Ptr, NameStr, isVolatile, InsertBefore))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::LoadInst *LoadInst::_construct(Value ^Ptr, System::String ^NameStr, bool isVolatile, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::LoadInst(Ptr->base, ctx.marshal_as<const char *>(NameStr), isVolatile, InsertAtEnd->base);
}
LoadInst::LoadInst(Value ^Ptr, System::String ^NameStr, bool isVolatile, BasicBlock ^InsertAtEnd)
	: base(_construct(Ptr, NameStr, isVolatile, InsertAtEnd))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::LoadInst *LoadInst::_construct(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align)
{
	msclr::interop::marshal_context ctx;
	return new llvm::LoadInst(Ptr->base, ctx.marshal_as<const char *>(NameStr), isVolatile, Align);
}
LoadInst::LoadInst(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align)
	: base(_construct(Ptr, NameStr, isVolatile, Align))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::LoadInst *LoadInst::_construct(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::LoadInst(Ptr->base, ctx.marshal_as<const char *>(NameStr), isVolatile, Align, InsertBefore->base);
}
LoadInst::LoadInst(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, Instruction ^InsertBefore)
	: base(_construct(Ptr, NameStr, isVolatile, Align, InsertBefore))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::LoadInst *LoadInst::_construct(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::LoadInst(Ptr->base, ctx.marshal_as<const char *>(NameStr), isVolatile, Align, InsertAtEnd->base);
}
LoadInst::LoadInst(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, BasicBlock ^InsertAtEnd)
	: base(_construct(Ptr, NameStr, isVolatile, Align, InsertAtEnd))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::LoadInst *LoadInst::_construct(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, AtomicOrdering Order)
{
	msclr::interop::marshal_context ctx;
	return new llvm::LoadInst(Ptr->base, ctx.marshal_as<const char *>(NameStr), isVolatile, Align, safe_cast<llvm::AtomicOrdering>(Order));
}
LoadInst::LoadInst(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, AtomicOrdering Order)
	: base(_construct(Ptr, NameStr, isVolatile, Align, Order))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::LoadInst *LoadInst::_construct(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, AtomicOrdering Order, SynchronizationScope SynchScope)
{
	msclr::interop::marshal_context ctx;
	return new llvm::LoadInst(Ptr->base, ctx.marshal_as<const char *>(NameStr), isVolatile, Align, safe_cast<llvm::AtomicOrdering>(Order), safe_cast<llvm::SynchronizationScope>(SynchScope));
}
LoadInst::LoadInst(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, AtomicOrdering Order, SynchronizationScope SynchScope)
	: base(_construct(Ptr, NameStr, isVolatile, Align, Order, SynchScope))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::LoadInst *LoadInst::_construct(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, AtomicOrdering Order, SynchronizationScope SynchScope, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::LoadInst(Ptr->base, ctx.marshal_as<const char *>(NameStr), isVolatile, Align, safe_cast<llvm::AtomicOrdering>(Order), safe_cast<llvm::SynchronizationScope>(SynchScope), InsertBefore->base);
}
LoadInst::LoadInst(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, AtomicOrdering Order, SynchronizationScope SynchScope, Instruction ^InsertBefore)
	: base(_construct(Ptr, NameStr, isVolatile, Align, Order, SynchScope, InsertBefore))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::LoadInst *LoadInst::_construct(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, AtomicOrdering Order, SynchronizationScope SynchScope, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::LoadInst(Ptr->base, ctx.marshal_as<const char *>(NameStr), isVolatile, Align, safe_cast<llvm::AtomicOrdering>(Order), safe_cast<llvm::SynchronizationScope>(SynchScope), InsertAtEnd->base);
}
LoadInst::LoadInst(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, AtomicOrdering Order, SynchronizationScope SynchScope, BasicBlock ^InsertAtEnd)
	: base(_construct(Ptr, NameStr, isVolatile, Align, Order, SynchScope, InsertAtEnd))
	, UnaryInstruction(base)
	, constructed(true)
{
}
LoadInst::LoadInst(Value ^Ptr)
	: base(new llvm::LoadInst(Ptr->base))
	, UnaryInstruction(base)
	, constructed(true)
{
}
bool LoadInst::isVolatile()
{
	return base->isVolatile();
}
void LoadInst::setVolatile(bool V)
{
	base->setVolatile(V);
}
unsigned LoadInst::getAlignment()
{
	return base->getAlignment();
}
void LoadInst::setAlignment(unsigned Align)
{
	base->setAlignment(Align);
}
AtomicOrdering LoadInst::getOrdering()
{
	return safe_cast<AtomicOrdering>(base->getOrdering());
}
void LoadInst::setOrdering(AtomicOrdering Ordering)
{
	base->setOrdering(safe_cast<llvm::AtomicOrdering>(Ordering));
}
SynchronizationScope LoadInst::getSynchScope()
{
	return safe_cast<SynchronizationScope>(base->getSynchScope());
}
void LoadInst::setSynchScope(SynchronizationScope xthread)
{
	base->setSynchScope(safe_cast<llvm::SynchronizationScope>(xthread));
}
bool LoadInst::isAtomic()
{
	return base->isAtomic();
}
void LoadInst::setAtomic(AtomicOrdering Ordering)
{
	base->setAtomic(safe_cast<llvm::AtomicOrdering>(Ordering));
}
void LoadInst::setAtomic(AtomicOrdering Ordering, SynchronizationScope SynchScope)
{
	base->setAtomic(safe_cast<llvm::AtomicOrdering>(Ordering), safe_cast<llvm::SynchronizationScope>(SynchScope));
}
bool LoadInst::isSimple()
{
	return base->isSimple();
}
bool LoadInst::isUnordered()
{
	return base->isUnordered();
}
Value ^LoadInst::getPointerOperand()
{
	return gcnew Value(base->getPointerOperand());
}
unsigned LoadInst::getPointerOperandIndex()
{
	return llvm::LoadInst::getPointerOperandIndex();
}
unsigned LoadInst::getPointerAddressSpace()
{
	return base->getPointerAddressSpace();
}
inline bool LoadInst::classof(Instruction ^I)
{
	return llvm::LoadInst::classof(I->base);
}
inline bool LoadInst::classof(Value ^V)
{
	return llvm::LoadInst::classof(V->base);
}


StoreInst::StoreInst(llvm::StoreInst *base)
	: base(base)
	, Instruction(base)
	, constructed(false)
{
}
StoreInst::!StoreInst()
{
	if (constructed)
	{
		delete base;
	}
}
StoreInst::~StoreInst()
{
	this->!StoreInst();
}
StoreInst::StoreInst(Value ^Val, Value ^Ptr, Instruction ^InsertBefore)
	: base(new llvm::StoreInst(Val->base, Ptr->base, InsertBefore->base))
	, Instruction(base)
	, constructed(true)
{
}
StoreInst::StoreInst(Value ^Val, Value ^Ptr, BasicBlock ^InsertAtEnd)
	: base(new llvm::StoreInst(Val->base, Ptr->base, InsertAtEnd->base))
	, Instruction(base)
	, constructed(true)
{
}
StoreInst::StoreInst(Value ^Val, Value ^Ptr)
	: base(new llvm::StoreInst(Val->base, Ptr->base))
	, Instruction(base)
	, constructed(true)
{
}
StoreInst::StoreInst(Value ^Val, Value ^Ptr, bool isVolatile)
	: base(new llvm::StoreInst(Val->base, Ptr->base, isVolatile))
	, Instruction(base)
	, constructed(true)
{
}
StoreInst::StoreInst(Value ^Val, Value ^Ptr, bool isVolatile, Instruction ^InsertBefore)
	: base(new llvm::StoreInst(Val->base, Ptr->base, isVolatile, InsertBefore->base))
	, Instruction(base)
	, constructed(true)
{
}
StoreInst::StoreInst(Value ^Val, Value ^Ptr, bool isVolatile, BasicBlock ^InsertAtEnd)
	: base(new llvm::StoreInst(Val->base, Ptr->base, isVolatile, InsertAtEnd->base))
	, Instruction(base)
	, constructed(true)
{
}
StoreInst::StoreInst(Value ^Val, Value ^Ptr, bool isVolatile, unsigned Align)
	: base(new llvm::StoreInst(Val->base, Ptr->base, isVolatile, Align))
	, Instruction(base)
	, constructed(true)
{
}
StoreInst::StoreInst(Value ^Val, Value ^Ptr, bool isVolatile, unsigned Align, Instruction ^InsertBefore)
	: base(new llvm::StoreInst(Val->base, Ptr->base, isVolatile, Align, InsertBefore->base))
	, Instruction(base)
	, constructed(true)
{
}
StoreInst::StoreInst(Value ^Val, Value ^Ptr, bool isVolatile, unsigned Align, BasicBlock ^InsertAtEnd)
	: base(new llvm::StoreInst(Val->base, Ptr->base, isVolatile, Align, InsertAtEnd->base))
	, Instruction(base)
	, constructed(true)
{
}
StoreInst::StoreInst(Value ^Val, Value ^Ptr, bool isVolatile, unsigned Align, AtomicOrdering Order)
	: base(new llvm::StoreInst(Val->base, Ptr->base, isVolatile, Align, safe_cast<llvm::AtomicOrdering>(Order)))
	, Instruction(base)
	, constructed(true)
{
}
StoreInst::StoreInst(Value ^Val, Value ^Ptr, bool isVolatile, unsigned Align, AtomicOrdering Order, SynchronizationScope SynchScope)
	: base(new llvm::StoreInst(Val->base, Ptr->base, isVolatile, Align, safe_cast<llvm::AtomicOrdering>(Order), safe_cast<llvm::SynchronizationScope>(SynchScope)))
	, Instruction(base)
	, constructed(true)
{
}
StoreInst::StoreInst(Value ^Val, Value ^Ptr, bool isVolatile, unsigned Align, AtomicOrdering Order, SynchronizationScope SynchScope, Instruction ^InsertBefore)
	: base(new llvm::StoreInst(Val->base, Ptr->base, isVolatile, Align, safe_cast<llvm::AtomicOrdering>(Order), safe_cast<llvm::SynchronizationScope>(SynchScope), InsertBefore->base))
	, Instruction(base)
	, constructed(true)
{
}
StoreInst::StoreInst(Value ^Val, Value ^Ptr, bool isVolatile, unsigned Align, AtomicOrdering Order, SynchronizationScope SynchScope, BasicBlock ^InsertAtEnd)
	: base(new llvm::StoreInst(Val->base, Ptr->base, isVolatile, Align, safe_cast<llvm::AtomicOrdering>(Order), safe_cast<llvm::SynchronizationScope>(SynchScope), InsertAtEnd->base))
	, Instruction(base)
	, constructed(true)
{
}
bool StoreInst::isVolatile()
{
	return base->isVolatile();
}
void StoreInst::setVolatile(bool V)
{
	base->setVolatile(V);
}
unsigned StoreInst::getAlignment()
{
	return base->getAlignment();
}
void StoreInst::setAlignment(unsigned Align)
{
	base->setAlignment(Align);
}
AtomicOrdering StoreInst::getOrdering()
{
	return safe_cast<AtomicOrdering>(base->getOrdering());
}
void StoreInst::setOrdering(AtomicOrdering Ordering)
{
	base->setOrdering(safe_cast<llvm::AtomicOrdering>(Ordering));
}
SynchronizationScope StoreInst::getSynchScope()
{
	return safe_cast<SynchronizationScope>(base->getSynchScope());
}
void StoreInst::setSynchScope(SynchronizationScope xthread)
{
	base->setSynchScope(safe_cast<llvm::SynchronizationScope>(xthread));
}
bool StoreInst::isAtomic()
{
	return base->isAtomic();
}
void StoreInst::setAtomic(AtomicOrdering Ordering)
{
	base->setAtomic(safe_cast<llvm::AtomicOrdering>(Ordering));
}
void StoreInst::setAtomic(AtomicOrdering Ordering, SynchronizationScope SynchScope)
{
	base->setAtomic(safe_cast<llvm::AtomicOrdering>(Ordering), safe_cast<llvm::SynchronizationScope>(SynchScope));
}
bool StoreInst::isSimple()
{
	return base->isSimple();
}
bool StoreInst::isUnordered()
{
	return base->isUnordered();
}
Value ^StoreInst::getValueOperand()
{
	return gcnew Value(base->getValueOperand());
}
Value ^StoreInst::getPointerOperand()
{
	return gcnew Value(base->getPointerOperand());
}
unsigned StoreInst::getPointerOperandIndex()
{
	return llvm::StoreInst::getPointerOperandIndex();
}
unsigned StoreInst::getPointerAddressSpace()
{
	return base->getPointerAddressSpace();
}
inline bool StoreInst::classof(Instruction ^I)
{
	return llvm::StoreInst::classof(I->base);
}
inline bool StoreInst::classof(Value ^V)
{
	return llvm::StoreInst::classof(V->base);
}


FenceInst::FenceInst(llvm::FenceInst *base)
	: base(base)
	, Instruction(base)
	, constructed(false)
{
}
FenceInst::!FenceInst()
{
	if (constructed)
	{
		delete base;
	}
}
FenceInst::~FenceInst()
{
	this->!FenceInst();
}
FenceInst::FenceInst(LLVMContext ^C, AtomicOrdering Ordering)
	: base(new llvm::FenceInst(*C->base, safe_cast<llvm::AtomicOrdering>(Ordering)))
	, Instruction(base)
	, constructed(true)
{
}
FenceInst::FenceInst(LLVMContext ^C, AtomicOrdering Ordering, SynchronizationScope SynchScope)
	: base(new llvm::FenceInst(*C->base, safe_cast<llvm::AtomicOrdering>(Ordering), safe_cast<llvm::SynchronizationScope>(SynchScope)))
	, Instruction(base)
	, constructed(true)
{
}
FenceInst::FenceInst(LLVMContext ^C, AtomicOrdering Ordering, SynchronizationScope SynchScope, Instruction ^InsertBefore)
	: base(new llvm::FenceInst(*C->base, safe_cast<llvm::AtomicOrdering>(Ordering), safe_cast<llvm::SynchronizationScope>(SynchScope), InsertBefore->base))
	, Instruction(base)
	, constructed(true)
{
}
FenceInst::FenceInst(LLVMContext ^C, AtomicOrdering Ordering, SynchronizationScope SynchScope, BasicBlock ^InsertAtEnd)
	: base(new llvm::FenceInst(*C->base, safe_cast<llvm::AtomicOrdering>(Ordering), safe_cast<llvm::SynchronizationScope>(SynchScope), InsertAtEnd->base))
	, Instruction(base)
	, constructed(true)
{
}
AtomicOrdering FenceInst::getOrdering()
{
	return safe_cast<AtomicOrdering>(base->getOrdering());
}
void FenceInst::setOrdering(AtomicOrdering Ordering)
{
	base->setOrdering(safe_cast<llvm::AtomicOrdering>(Ordering));
}
SynchronizationScope FenceInst::getSynchScope()
{
	return safe_cast<SynchronizationScope>(base->getSynchScope());
}
void FenceInst::setSynchScope(SynchronizationScope xthread)
{
	base->setSynchScope(safe_cast<llvm::SynchronizationScope>(xthread));
}
inline bool FenceInst::classof(Instruction ^I)
{
	return llvm::FenceInst::classof(I->base);
}
inline bool FenceInst::classof(Value ^V)
{
	return llvm::FenceInst::classof(V->base);
}


AtomicCmpXchgInst::AtomicCmpXchgInst(llvm::AtomicCmpXchgInst *base)
	: base(base)
	, Instruction(base)
	, constructed(false)
{
}
AtomicCmpXchgInst::!AtomicCmpXchgInst()
{
	if (constructed)
	{
		delete base;
	}
}
AtomicCmpXchgInst::~AtomicCmpXchgInst()
{
	this->!AtomicCmpXchgInst();
}
AtomicCmpXchgInst::AtomicCmpXchgInst(Value ^Ptr, Value ^Cmp, Value ^NewVal, AtomicOrdering Ordering, SynchronizationScope SynchScope)
	: base(new llvm::AtomicCmpXchgInst(Ptr->base, Cmp->base, NewVal->base, safe_cast<llvm::AtomicOrdering>(Ordering), safe_cast<llvm::SynchronizationScope>(SynchScope)))
	, Instruction(base)
	, constructed(true)
{
}
AtomicCmpXchgInst::AtomicCmpXchgInst(Value ^Ptr, Value ^Cmp, Value ^NewVal, AtomicOrdering Ordering, SynchronizationScope SynchScope, Instruction ^InsertBefore)
	: base(new llvm::AtomicCmpXchgInst(Ptr->base, Cmp->base, NewVal->base, safe_cast<llvm::AtomicOrdering>(Ordering), safe_cast<llvm::SynchronizationScope>(SynchScope), InsertBefore->base))
	, Instruction(base)
	, constructed(true)
{
}
AtomicCmpXchgInst::AtomicCmpXchgInst(Value ^Ptr, Value ^Cmp, Value ^NewVal, AtomicOrdering Ordering, SynchronizationScope SynchScope, BasicBlock ^InsertAtEnd)
	: base(new llvm::AtomicCmpXchgInst(Ptr->base, Cmp->base, NewVal->base, safe_cast<llvm::AtomicOrdering>(Ordering), safe_cast<llvm::SynchronizationScope>(SynchScope), InsertAtEnd->base))
	, Instruction(base)
	, constructed(true)
{
}
bool AtomicCmpXchgInst::isVolatile()
{
	return base->isVolatile();
}
void AtomicCmpXchgInst::setVolatile(bool V)
{
	base->setVolatile(V);
}
void AtomicCmpXchgInst::setOrdering(AtomicOrdering Ordering)
{
	base->setOrdering(safe_cast<llvm::AtomicOrdering>(Ordering));
}
void AtomicCmpXchgInst::setSynchScope(SynchronizationScope SynchScope)
{
	base->setSynchScope(safe_cast<llvm::SynchronizationScope>(SynchScope));
}
AtomicOrdering AtomicCmpXchgInst::getOrdering()
{
	return safe_cast<AtomicOrdering>(base->getOrdering());
}
SynchronizationScope AtomicCmpXchgInst::getSynchScope()
{
	return safe_cast<SynchronizationScope>(base->getSynchScope());
}
Value ^AtomicCmpXchgInst::getPointerOperand()
{
	return gcnew Value(base->getPointerOperand());
}
unsigned AtomicCmpXchgInst::getPointerOperandIndex()
{
	return llvm::AtomicCmpXchgInst::getPointerOperandIndex();
}
Value ^AtomicCmpXchgInst::getCompareOperand()
{
	return gcnew Value(base->getCompareOperand());
}
Value ^AtomicCmpXchgInst::getNewValOperand()
{
	return gcnew Value(base->getNewValOperand());
}
unsigned AtomicCmpXchgInst::getPointerAddressSpace()
{
	return base->getPointerAddressSpace();
}
inline bool AtomicCmpXchgInst::classof(Instruction ^I)
{
	return llvm::AtomicCmpXchgInst::classof(I->base);
}
inline bool AtomicCmpXchgInst::classof(Value ^V)
{
	return llvm::AtomicCmpXchgInst::classof(V->base);
}


AtomicRMWInst::AtomicRMWInst(llvm::AtomicRMWInst *base)
	: base(base)
	, Instruction(base)
	, constructed(false)
{
}
AtomicRMWInst::!AtomicRMWInst()
{
	if (constructed)
	{
		delete base;
	}
}
AtomicRMWInst::~AtomicRMWInst()
{
	this->!AtomicRMWInst();
}
AtomicRMWInst::AtomicRMWInst(BinOp Operation, Value ^Ptr, Value ^Val, AtomicOrdering Ordering, SynchronizationScope SynchScope)
	: base(new llvm::AtomicRMWInst(safe_cast<llvm::AtomicRMWInst::BinOp>(Operation), Ptr->base, Val->base, safe_cast<llvm::AtomicOrdering>(Ordering), safe_cast<llvm::SynchronizationScope>(SynchScope)))
	, Instruction(base)
	, constructed(true)
{
}
AtomicRMWInst::AtomicRMWInst(BinOp Operation, Value ^Ptr, Value ^Val, AtomicOrdering Ordering, SynchronizationScope SynchScope, Instruction ^InsertBefore)
	: base(new llvm::AtomicRMWInst(safe_cast<llvm::AtomicRMWInst::BinOp>(Operation), Ptr->base, Val->base, safe_cast<llvm::AtomicOrdering>(Ordering), safe_cast<llvm::SynchronizationScope>(SynchScope), InsertBefore->base))
	, Instruction(base)
	, constructed(true)
{
}
AtomicRMWInst::AtomicRMWInst(BinOp Operation, Value ^Ptr, Value ^Val, AtomicOrdering Ordering, SynchronizationScope SynchScope, BasicBlock ^InsertAtEnd)
	: base(new llvm::AtomicRMWInst(safe_cast<llvm::AtomicRMWInst::BinOp>(Operation), Ptr->base, Val->base, safe_cast<llvm::AtomicOrdering>(Ordering), safe_cast<llvm::SynchronizationScope>(SynchScope), InsertAtEnd->base))
	, Instruction(base)
	, constructed(true)
{
}
AtomicRMWInst::BinOp AtomicRMWInst::getOperation()
{
	return safe_cast<AtomicRMWInst::BinOp>(base->getOperation());
}
void AtomicRMWInst::setOperation(BinOp Operation)
{
	base->setOperation(safe_cast<llvm::AtomicRMWInst::BinOp>(Operation));
}
bool AtomicRMWInst::isVolatile()
{
	return base->isVolatile();
}
void AtomicRMWInst::setVolatile(bool V)
{
	base->setVolatile(V);
}
void AtomicRMWInst::setOrdering(AtomicOrdering Ordering)
{
	base->setOrdering(safe_cast<llvm::AtomicOrdering>(Ordering));
}
void AtomicRMWInst::setSynchScope(SynchronizationScope SynchScope)
{
	base->setSynchScope(safe_cast<llvm::SynchronizationScope>(SynchScope));
}
AtomicOrdering AtomicRMWInst::getOrdering()
{
	return safe_cast<AtomicOrdering>(base->getOrdering());
}
SynchronizationScope AtomicRMWInst::getSynchScope()
{
	return safe_cast<SynchronizationScope>(base->getSynchScope());
}
Value ^AtomicRMWInst::getPointerOperand()
{
	return gcnew Value(base->getPointerOperand());
}
unsigned AtomicRMWInst::getPointerOperandIndex()
{
	return llvm::AtomicRMWInst::getPointerOperandIndex();
}
Value ^AtomicRMWInst::getValOperand()
{
	return gcnew Value(base->getValOperand());
}
unsigned AtomicRMWInst::getPointerAddressSpace()
{
	return base->getPointerAddressSpace();
}
inline bool AtomicRMWInst::classof(Instruction ^I)
{
	return llvm::AtomicRMWInst::classof(I->base);
}
inline bool AtomicRMWInst::classof(Value ^V)
{
	return llvm::AtomicRMWInst::classof(V->base);
}


GetElementPtrInst::GetElementPtrInst(llvm::GetElementPtrInst *base)
	: base(base)
	, Instruction(base)
{
}
GetElementPtrInst::!GetElementPtrInst()
{
}
GetElementPtrInst::~GetElementPtrInst()
{
	this->!GetElementPtrInst();
}
GetElementPtrInst ^GetElementPtrInst::Create(Value ^Ptr, array<Value ^> ^IdxList)
{
	llvm::Value **b = new llvm::Value*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, IdxList->Length);
	auto r = gcnew GetElementPtrInst(llvm::GetElementPtrInst::Create(Ptr->base, brr));
	delete b;
	return r;
}
GetElementPtrInst ^GetElementPtrInst::Create(Value ^Ptr, array<Value ^> ^IdxList, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	llvm::Value **b = new llvm::Value*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, IdxList->Length);
	auto r = gcnew GetElementPtrInst(llvm::GetElementPtrInst::Create(Ptr->base, brr, ctx.marshal_as<const char *>(NameStr)));
	delete b;
	return r;
}
GetElementPtrInst ^GetElementPtrInst::Create(Value ^Ptr, array<Value ^> ^IdxList, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	llvm::Value **b = new llvm::Value*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, IdxList->Length);
	auto r = gcnew GetElementPtrInst(llvm::GetElementPtrInst::Create(Ptr->base, brr, ctx.marshal_as<const char *>(NameStr), InsertBefore->base));
	delete b;
	return r;
}
GetElementPtrInst ^GetElementPtrInst::Create(Value ^Ptr, array<Value ^> ^IdxList, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	llvm::Value **b = new llvm::Value*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, IdxList->Length);
	auto r = gcnew GetElementPtrInst(llvm::GetElementPtrInst::Create(Ptr->base, brr, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base));
	delete b;
	return r;
}
GetElementPtrInst ^GetElementPtrInst::CreateInBounds(Value ^Ptr, array<Value ^> ^IdxList)
{
	llvm::Value **b = new llvm::Value*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, IdxList->Length);
	auto r = gcnew GetElementPtrInst(llvm::GetElementPtrInst::CreateInBounds(Ptr->base, brr));
	delete b;
	return r;
}
GetElementPtrInst ^GetElementPtrInst::CreateInBounds(Value ^Ptr, array<Value ^> ^IdxList, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	llvm::Value **b = new llvm::Value*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, IdxList->Length);
	auto r = gcnew GetElementPtrInst(llvm::GetElementPtrInst::CreateInBounds(Ptr->base, brr, ctx.marshal_as<const char *>(NameStr)));
	delete b;
	return r;
}
GetElementPtrInst ^GetElementPtrInst::CreateInBounds(Value ^Ptr, array<Value ^> ^IdxList, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	llvm::Value **b = new llvm::Value*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, IdxList->Length);
	auto r = gcnew GetElementPtrInst(llvm::GetElementPtrInst::CreateInBounds(Ptr->base, brr, ctx.marshal_as<const char *>(NameStr), InsertBefore->base));
	delete b;
	return r;
}
GetElementPtrInst ^GetElementPtrInst::CreateInBounds(Value ^Ptr, array<Value ^> ^IdxList, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	llvm::Value **b = new llvm::Value*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, IdxList->Length);
	auto r = gcnew GetElementPtrInst(llvm::GetElementPtrInst::CreateInBounds(Ptr->base, brr, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base));
	delete b;
	return r;
}
SequentialType ^GetElementPtrInst::getType()
{
	return gcnew SequentialType(base->getType());
}
unsigned GetElementPtrInst::getAddressSpace()
{
	return base->getAddressSpace();
}
Type ^GetElementPtrInst::getIndexedType(Type ^Ptr, array<Value ^> ^IdxList)
{
	llvm::Value **b = new llvm::Value*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, IdxList->Length);
	auto r = gcnew Type(llvm::GetElementPtrInst::getIndexedType(Ptr->base, brr));
	delete b;
	return r;
}
Type ^GetElementPtrInst::getIndexedType(Type ^Ptr, array<Constant ^> ^IdxList)
{
	llvm::Constant **b = new llvm::Constant*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Constant*> brr(b, IdxList->Length);
	auto r = gcnew Type(llvm::GetElementPtrInst::getIndexedType(Ptr->base, brr));
	delete b;
	return r;
}
Type ^GetElementPtrInst::getIndexedType(Type ^Ptr, array<uint64_t> ^IdxList)
{
	auto r = gcnew Type(llvm::GetElementPtrInst::getIndexedType(Ptr->base, utils::unmanage_array(IdxList)));
	return r;
}
Value ^GetElementPtrInst::getPointerOperand()
{
	return gcnew Value(base->getPointerOperand());
}
unsigned GetElementPtrInst::getPointerOperandIndex()
{
	return llvm::GetElementPtrInst::getPointerOperandIndex();
}
Type ^GetElementPtrInst::getPointerOperandType()
{
	return gcnew Type(base->getPointerOperandType());
}
unsigned GetElementPtrInst::getPointerAddressSpace()
{
	return base->getPointerAddressSpace();
}
Type ^GetElementPtrInst::getGEPReturnType(Value ^Ptr, array<Value ^> ^IdxList)
{
	llvm::Value **b = new llvm::Value*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, IdxList->Length);
	auto r = gcnew Type(llvm::GetElementPtrInst::getGEPReturnType(Ptr->base, brr));
	delete b;
	return r;
}
unsigned GetElementPtrInst::getNumIndices()
{
	return base->getNumIndices();
}
bool GetElementPtrInst::hasIndices()
{
	return base->hasIndices();
}
bool GetElementPtrInst::hasAllZeroIndices()
{
	return base->hasAllZeroIndices();
}
bool GetElementPtrInst::hasAllConstantIndices()
{
	return base->hasAllConstantIndices();
}
void GetElementPtrInst::setIsInBounds()
{
	base->setIsInBounds();
}
void GetElementPtrInst::setIsInBounds(bool b)
{
	base->setIsInBounds(b);
}
bool GetElementPtrInst::isInBounds()
{
	return base->isInBounds();
}
inline bool GetElementPtrInst::classof(Instruction ^I)
{
	return llvm::GetElementPtrInst::classof(I->base);
}
inline bool GetElementPtrInst::classof(Value ^V)
{
	return llvm::GetElementPtrInst::classof(V->base);
}


ICmpInst::ICmpInst(llvm::ICmpInst *base)
	: base(base)
	, CmpInst(base)
	, constructed(false)
{
}
ICmpInst::!ICmpInst()
{
	if (constructed)
	{
		delete base;
	}
}
ICmpInst::~ICmpInst()
{
	this->!ICmpInst();
}
ICmpInst::ICmpInst(Instruction ^InsertBefore, Predicate pred, Value ^LHS, Value ^RHS)
	: base(new llvm::ICmpInst(InsertBefore->base, safe_cast<llvm::ICmpInst::Predicate>(pred), LHS->base, RHS->base))
	, CmpInst(base)
	, constructed(true)
{
}
llvm::ICmpInst *ICmpInst::_construct(Instruction ^InsertBefore, Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::ICmpInst(InsertBefore->base, safe_cast<llvm::ICmpInst::Predicate>(pred), LHS->base, RHS->base, ctx.marshal_as<const char *>(NameStr));
}
ICmpInst::ICmpInst(Instruction ^InsertBefore, Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr)
	: base(_construct(InsertBefore, pred, LHS, RHS, NameStr))
	, CmpInst(base)
	, constructed(true)
{
}
ICmpInst::ICmpInst(BasicBlock ^InsertAtEnd, Predicate pred, Value ^LHS, Value ^RHS)
	: base(new llvm::ICmpInst(*InsertAtEnd->base, safe_cast<llvm::ICmpInst::Predicate>(pred), LHS->base, RHS->base))
	, CmpInst(base)
	, constructed(true)
{
}
llvm::ICmpInst *ICmpInst::_construct(BasicBlock ^InsertAtEnd, Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::ICmpInst(*InsertAtEnd->base, safe_cast<llvm::ICmpInst::Predicate>(pred), LHS->base, RHS->base, ctx.marshal_as<const char *>(NameStr));
}
ICmpInst::ICmpInst(BasicBlock ^InsertAtEnd, Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr)
	: base(_construct(InsertAtEnd, pred, LHS, RHS, NameStr))
	, CmpInst(base)
	, constructed(true)
{
}
ICmpInst::ICmpInst(Predicate pred, Value ^LHS, Value ^RHS)
	: base(new llvm::ICmpInst(safe_cast<llvm::ICmpInst::Predicate>(pred), LHS->base, RHS->base))
	, CmpInst(base)
	, constructed(true)
{
}
llvm::ICmpInst *ICmpInst::_construct(Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::ICmpInst(safe_cast<llvm::ICmpInst::Predicate>(pred), LHS->base, RHS->base, ctx.marshal_as<const char *>(NameStr));
}
ICmpInst::ICmpInst(Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr)
	: base(_construct(pred, LHS, RHS, NameStr))
	, CmpInst(base)
	, constructed(true)
{
}
CmpInst::Predicate ICmpInst::getSignedPredicate()
{
	return safe_cast<CmpInst::Predicate>(base->getSignedPredicate());
}
CmpInst::Predicate ICmpInst::getSignedPredicate(Predicate pred)
{
	return safe_cast<CmpInst::Predicate>(llvm::ICmpInst::getSignedPredicate(safe_cast<llvm::ICmpInst::Predicate>(pred)));
}
CmpInst::Predicate ICmpInst::getUnsignedPredicate()
{
	return safe_cast<CmpInst::Predicate>(base->getUnsignedPredicate());
}
CmpInst::Predicate ICmpInst::getUnsignedPredicate(Predicate pred)
{
	return safe_cast<CmpInst::Predicate>(llvm::ICmpInst::getUnsignedPredicate(safe_cast<llvm::ICmpInst::Predicate>(pred)));
}
bool ICmpInst::isEquality(Predicate P)
{
	return llvm::ICmpInst::isEquality(safe_cast<llvm::ICmpInst::Predicate>(P));
}
bool ICmpInst::isEquality()
{
	return base->isEquality();
}
bool ICmpInst::isCommutative()
{
	return base->isCommutative();
}
bool ICmpInst::isRelational()
{
	return base->isRelational();
}
bool ICmpInst::isRelational(Predicate P)
{
	return llvm::ICmpInst::isRelational(safe_cast<llvm::ICmpInst::Predicate>(P));
}
void ICmpInst::swapOperands()
{
	base->swapOperands();
}
inline bool ICmpInst::classof(Instruction ^I)
{
	return llvm::ICmpInst::classof(I->base);
}
inline bool ICmpInst::classof(Value ^V)
{
	return llvm::ICmpInst::classof(V->base);
}


FCmpInst::FCmpInst(llvm::FCmpInst *base)
	: base(base)
	, CmpInst(base)
	, constructed(false)
{
}
FCmpInst::!FCmpInst()
{
	if (constructed)
	{
		delete base;
	}
}
FCmpInst::~FCmpInst()
{
	this->!FCmpInst();
}
FCmpInst::FCmpInst(Instruction ^InsertBefore, Predicate pred, Value ^LHS, Value ^RHS)
	: base(new llvm::FCmpInst(InsertBefore->base, safe_cast<llvm::FCmpInst::Predicate>(pred), LHS->base, RHS->base))
	, CmpInst(base)
	, constructed(true)
{
}
llvm::FCmpInst *FCmpInst::_construct(Instruction ^InsertBefore, Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::FCmpInst(InsertBefore->base, safe_cast<llvm::FCmpInst::Predicate>(pred), LHS->base, RHS->base, ctx.marshal_as<const char *>(NameStr));
}
FCmpInst::FCmpInst(Instruction ^InsertBefore, Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr)
	: base(_construct(InsertBefore, pred, LHS, RHS, NameStr))
	, CmpInst(base)
	, constructed(true)
{
}
FCmpInst::FCmpInst(BasicBlock ^InsertAtEnd, Predicate pred, Value ^LHS, Value ^RHS)
	: base(new llvm::FCmpInst(*InsertAtEnd->base, safe_cast<llvm::FCmpInst::Predicate>(pred), LHS->base, RHS->base))
	, CmpInst(base)
	, constructed(true)
{
}
llvm::FCmpInst *FCmpInst::_construct(BasicBlock ^InsertAtEnd, Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::FCmpInst(*InsertAtEnd->base, safe_cast<llvm::FCmpInst::Predicate>(pred), LHS->base, RHS->base, ctx.marshal_as<const char *>(NameStr));
}
FCmpInst::FCmpInst(BasicBlock ^InsertAtEnd, Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr)
	: base(_construct(InsertAtEnd, pred, LHS, RHS, NameStr))
	, CmpInst(base)
	, constructed(true)
{
}
FCmpInst::FCmpInst(Predicate pred, Value ^LHS, Value ^RHS)
	: base(new llvm::FCmpInst(safe_cast<llvm::FCmpInst::Predicate>(pred), LHS->base, RHS->base))
	, CmpInst(base)
	, constructed(true)
{
}
llvm::FCmpInst *FCmpInst::_construct(Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::FCmpInst(safe_cast<llvm::FCmpInst::Predicate>(pred), LHS->base, RHS->base, ctx.marshal_as<const char *>(NameStr));
}
FCmpInst::FCmpInst(Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr)
	: base(_construct(pred, LHS, RHS, NameStr))
	, CmpInst(base)
	, constructed(true)
{
}
bool FCmpInst::isEquality()
{
	return base->isEquality();
}
bool FCmpInst::isCommutative()
{
	return base->isCommutative();
}
bool FCmpInst::isRelational()
{
	return base->isRelational();
}
void FCmpInst::swapOperands()
{
	base->swapOperands();
}
inline bool FCmpInst::classof(Instruction ^I)
{
	return llvm::FCmpInst::classof(I->base);
}
inline bool FCmpInst::classof(Value ^V)
{
	return llvm::FCmpInst::classof(V->base);
}


CallInst::CallInst(llvm::CallInst *base)
	: base(base)
	, Instruction(base)
{
}
CallInst::!CallInst()
{
}
CallInst::~CallInst()
{
	this->!CallInst();
}
CallInst ^CallInst::Create(Value ^Func, array<Value ^> ^Args)
{
	llvm::Value **b = new llvm::Value*[Args->Length];
	for (int i = 0; i < Args->Length; i++)
		b[i] = Args[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, Args->Length);
	auto r = gcnew CallInst(llvm::CallInst::Create(Func->base, brr));
	delete b;
	return r;
}
CallInst ^CallInst::Create(Value ^Func, array<Value ^> ^Args, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	llvm::Value **b = new llvm::Value*[Args->Length];
	for (int i = 0; i < Args->Length; i++)
		b[i] = Args[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, Args->Length);
	auto r = gcnew CallInst(llvm::CallInst::Create(Func->base, brr, ctx.marshal_as<const char *>(NameStr)));
	delete b;
	return r;
}
CallInst ^CallInst::Create(Value ^Func, array<Value ^> ^Args, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	llvm::Value **b = new llvm::Value*[Args->Length];
	for (int i = 0; i < Args->Length; i++)
		b[i] = Args[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, Args->Length);
	auto r = gcnew CallInst(llvm::CallInst::Create(Func->base, brr, ctx.marshal_as<const char *>(NameStr), InsertBefore->base));
	delete b;
	return r;
}
CallInst ^CallInst::Create(Value ^Func, array<Value ^> ^Args, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	llvm::Value **b = new llvm::Value*[Args->Length];
	for (int i = 0; i < Args->Length; i++)
		b[i] = Args[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, Args->Length);
	auto r = gcnew CallInst(llvm::CallInst::Create(Func->base, brr, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base));
	delete b;
	return r;
}
CallInst ^CallInst::Create(Value ^F)
{
	return gcnew CallInst(llvm::CallInst::Create(F->base));
}
CallInst ^CallInst::Create(Value ^F, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return gcnew CallInst(llvm::CallInst::Create(F->base, ctx.marshal_as<const char *>(NameStr)));
}
CallInst ^CallInst::Create(Value ^F, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew CallInst(llvm::CallInst::Create(F->base, ctx.marshal_as<const char *>(NameStr), InsertBefore->base));
}
CallInst ^CallInst::Create(Value ^F, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return gcnew CallInst(llvm::CallInst::Create(F->base, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base));
}
Instruction ^CallInst::CreateMalloc(Instruction ^InsertBefore, Type ^IntPtrTy, Type ^AllocTy, Value ^AllocSize)
{
	return gcnew Instruction(llvm::CallInst::CreateMalloc(InsertBefore->base, IntPtrTy->base, AllocTy->base, AllocSize->base));
}
Instruction ^CallInst::CreateMalloc(Instruction ^InsertBefore, Type ^IntPtrTy, Type ^AllocTy, Value ^AllocSize, Value ^ArraySize)
{
	return gcnew Instruction(llvm::CallInst::CreateMalloc(InsertBefore->base, IntPtrTy->base, AllocTy->base, AllocSize->base, ArraySize->base));
}
Instruction ^CallInst::CreateMalloc(Instruction ^InsertBefore, Type ^IntPtrTy, Type ^AllocTy, Value ^AllocSize, Value ^ArraySize, Function ^MallocF)
{
	return gcnew Instruction(llvm::CallInst::CreateMalloc(InsertBefore->base, IntPtrTy->base, AllocTy->base, AllocSize->base, ArraySize->base, MallocF->base));
}
Instruction ^CallInst::CreateMalloc(Instruction ^InsertBefore, Type ^IntPtrTy, Type ^AllocTy, Value ^AllocSize, Value ^ArraySize, Function ^MallocF, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew Instruction(llvm::CallInst::CreateMalloc(InsertBefore->base, IntPtrTy->base, AllocTy->base, AllocSize->base, ArraySize->base, MallocF->base, ctx.marshal_as<const char *>(Name)));
}
Instruction ^CallInst::CreateMalloc(BasicBlock ^InsertAtEnd, Type ^IntPtrTy, Type ^AllocTy, Value ^AllocSize)
{
	return gcnew Instruction(llvm::CallInst::CreateMalloc(InsertAtEnd->base, IntPtrTy->base, AllocTy->base, AllocSize->base));
}
Instruction ^CallInst::CreateMalloc(BasicBlock ^InsertAtEnd, Type ^IntPtrTy, Type ^AllocTy, Value ^AllocSize, Value ^ArraySize)
{
	return gcnew Instruction(llvm::CallInst::CreateMalloc(InsertAtEnd->base, IntPtrTy->base, AllocTy->base, AllocSize->base, ArraySize->base));
}
Instruction ^CallInst::CreateMalloc(BasicBlock ^InsertAtEnd, Type ^IntPtrTy, Type ^AllocTy, Value ^AllocSize, Value ^ArraySize, Function ^MallocF)
{
	return gcnew Instruction(llvm::CallInst::CreateMalloc(InsertAtEnd->base, IntPtrTy->base, AllocTy->base, AllocSize->base, ArraySize->base, MallocF->base));
}
Instruction ^CallInst::CreateMalloc(BasicBlock ^InsertAtEnd, Type ^IntPtrTy, Type ^AllocTy, Value ^AllocSize, Value ^ArraySize, Function ^MallocF, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew Instruction(llvm::CallInst::CreateMalloc(InsertAtEnd->base, IntPtrTy->base, AllocTy->base, AllocSize->base, ArraySize->base, MallocF->base, ctx.marshal_as<const char *>(Name)));
}
Instruction ^CallInst::CreateFree(Value ^Source, Instruction ^InsertBefore)
{
	return gcnew Instruction(llvm::CallInst::CreateFree(Source->base, InsertBefore->base));
}
Instruction ^CallInst::CreateFree(Value ^Source, BasicBlock ^InsertAtEnd)
{
	return gcnew Instruction(llvm::CallInst::CreateFree(Source->base, InsertAtEnd->base));
}
bool CallInst::isTailCall()
{
	return base->isTailCall();
}
void CallInst::setTailCall()
{
	base->setTailCall();
}
void CallInst::setTailCall(bool isTC)
{
	base->setTailCall(isTC);
}
unsigned CallInst::getNumArgOperands()
{
	return base->getNumArgOperands();
}
Value ^CallInst::getArgOperand(unsigned i)
{
	return gcnew Value(base->getArgOperand(i));
}
void CallInst::setArgOperand(unsigned i, Value ^v)
{
	base->setArgOperand(i, v->base);
}
CallingConv::ID CallInst::getCallingConv()
{
	return safe_cast<CallingConv::ID>(base->getCallingConv());
}
void CallInst::setCallingConv(CallingConv::ID CC)
{
	base->setCallingConv(safe_cast<llvm::CallingConv::ID>(CC));
}
void CallInst::setAttributes(AttributeSet ^Attrs)
{
	base->setAttributes(*Attrs->base);
}
void CallInst::addAttribute(unsigned i, Attribute::AttrKind attr)
{
	base->addAttribute(i, safe_cast<llvm::Attribute::AttrKind>(attr));
}
void CallInst::removeAttribute(unsigned i, Attribute ^attr)
{
	base->removeAttribute(i, *attr->base);
}
bool CallInst::hasFnAttr(Attribute::AttrKind A)
{
	return base->hasFnAttr(safe_cast<llvm::Attribute::AttrKind>(A));
}
bool CallInst::paramHasAttr(unsigned i, Attribute::AttrKind A)
{
	return base->paramHasAttr(i, safe_cast<llvm::Attribute::AttrKind>(A));
}
unsigned CallInst::getParamAlignment(unsigned i)
{
	return base->getParamAlignment(i);
}
bool CallInst::isNoInline()
{
	return base->isNoInline();
}
void CallInst::setIsNoInline()
{
	base->setIsNoInline();
}
bool CallInst::canReturnTwice()
{
	return base->canReturnTwice();
}
void CallInst::setCanReturnTwice()
{
	base->setCanReturnTwice();
}
bool CallInst::doesNotAccessMemory()
{
	return base->doesNotAccessMemory();
}
void CallInst::setDoesNotAccessMemory()
{
	base->setDoesNotAccessMemory();
}
bool CallInst::onlyReadsMemory()
{
	return base->onlyReadsMemory();
}
void CallInst::setOnlyReadsMemory()
{
	base->setOnlyReadsMemory();
}
bool CallInst::doesNotReturn()
{
	return base->doesNotReturn();
}
void CallInst::setDoesNotReturn()
{
	base->setDoesNotReturn();
}
bool CallInst::doesNotThrow()
{
	return base->doesNotThrow();
}
void CallInst::setDoesNotThrow()
{
	base->setDoesNotThrow();
}
bool CallInst::cannotDuplicate()
{
	return base->cannotDuplicate();
}
void CallInst::setCannotDuplicate()
{
	base->setCannotDuplicate();
}
bool CallInst::hasStructRetAttr()
{
	return base->hasStructRetAttr();
}
bool CallInst::hasByValArgument()
{
	return base->hasByValArgument();
}
Function ^CallInst::getCalledFunction()
{
	return gcnew Function(base->getCalledFunction());
}
Value ^CallInst::getCalledValue()
{
	return gcnew Value(base->getCalledValue());
}
void CallInst::setCalledFunction(Value ^Fn)
{
	base->setCalledFunction(Fn->base);
}
bool CallInst::isInlineAsm()
{
	return base->isInlineAsm();
}
inline bool CallInst::classof(Instruction ^I)
{
	return llvm::CallInst::classof(I->base);
}
inline bool CallInst::classof(Value ^V)
{
	return llvm::CallInst::classof(V->base);
}


SelectInst::SelectInst(llvm::SelectInst *base)
	: base(base)
	, Instruction(base)
{
}
SelectInst::!SelectInst()
{
}
SelectInst::~SelectInst()
{
	this->!SelectInst();
}
SelectInst ^SelectInst::Create(Value ^C, Value ^S1, Value ^S2)
{
	return gcnew SelectInst(llvm::SelectInst::Create(C->base, S1->base, S2->base));
}
SelectInst ^SelectInst::Create(Value ^C, Value ^S1, Value ^S2, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return gcnew SelectInst(llvm::SelectInst::Create(C->base, S1->base, S2->base, ctx.marshal_as<const char *>(NameStr)));
}
SelectInst ^SelectInst::Create(Value ^C, Value ^S1, Value ^S2, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew SelectInst(llvm::SelectInst::Create(C->base, S1->base, S2->base, ctx.marshal_as<const char *>(NameStr), InsertBefore->base));
}
SelectInst ^SelectInst::Create(Value ^C, Value ^S1, Value ^S2, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return gcnew SelectInst(llvm::SelectInst::Create(C->base, S1->base, S2->base, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base));
}
Value ^SelectInst::getCondition()
{
	return gcnew Value(base->getCondition());
}
Value ^SelectInst::getTrueValue()
{
	return gcnew Value(base->getTrueValue());
}
Value ^SelectInst::getFalseValue()
{
	return gcnew Value(base->getFalseValue());
}
System::String ^SelectInst::areInvalidOperands(Value ^Cond, Value ^True, Value ^False)
{
	return utils::manage_str(llvm::SelectInst::areInvalidOperands(Cond->base, True->base, False->base));
}
Instruction::OtherOps SelectInst::getOpcode()
{
	return safe_cast<Instruction::OtherOps>(base->getOpcode());
}
inline bool SelectInst::classof(Instruction ^I)
{
	return llvm::SelectInst::classof(I->base);
}
inline bool SelectInst::classof(Value ^V)
{
	return llvm::SelectInst::classof(V->base);
}


VAArgInst::VAArgInst(llvm::VAArgInst *base)
	: base(base)
	, UnaryInstruction(base)
	, constructed(false)
{
}
VAArgInst::!VAArgInst()
{
	if (constructed)
	{
		delete base;
	}
}
VAArgInst::~VAArgInst()
{
	this->!VAArgInst();
}
VAArgInst::VAArgInst(Value ^List, Type ^Ty)
	: base(new llvm::VAArgInst(List->base, Ty->base))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::VAArgInst *VAArgInst::_construct(Value ^List, Type ^Ty, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::VAArgInst(List->base, Ty->base, ctx.marshal_as<const char *>(NameStr));
}
VAArgInst::VAArgInst(Value ^List, Type ^Ty, System::String ^NameStr)
	: base(_construct(List, Ty, NameStr))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::VAArgInst *VAArgInst::_construct(Value ^List, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::VAArgInst(List->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertBefore->base);
}
VAArgInst::VAArgInst(Value ^List, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
	: base(_construct(List, Ty, NameStr, InsertBefore))
	, UnaryInstruction(base)
	, constructed(true)
{
}
llvm::VAArgInst *VAArgInst::_construct(Value ^List, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::VAArgInst(List->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base);
}
VAArgInst::VAArgInst(Value ^List, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
	: base(_construct(List, Ty, NameStr, InsertAtEnd))
	, UnaryInstruction(base)
	, constructed(true)
{
}
Value ^VAArgInst::getPointerOperand()
{
	return gcnew Value(base->getPointerOperand());
}
unsigned VAArgInst::getPointerOperandIndex()
{
	return llvm::VAArgInst::getPointerOperandIndex();
}
inline bool VAArgInst::classof(Instruction ^I)
{
	return llvm::VAArgInst::classof(I->base);
}
inline bool VAArgInst::classof(Value ^V)
{
	return llvm::VAArgInst::classof(V->base);
}


ExtractElementInst::ExtractElementInst(llvm::ExtractElementInst *base)
	: base(base)
	, Instruction(base)
{
}
ExtractElementInst::!ExtractElementInst()
{
}
ExtractElementInst::~ExtractElementInst()
{
	this->!ExtractElementInst();
}
ExtractElementInst ^ExtractElementInst::Create(Value ^Vec, Value ^Idx)
{
	return gcnew ExtractElementInst(llvm::ExtractElementInst::Create(Vec->base, Idx->base));
}
ExtractElementInst ^ExtractElementInst::Create(Value ^Vec, Value ^Idx, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return gcnew ExtractElementInst(llvm::ExtractElementInst::Create(Vec->base, Idx->base, ctx.marshal_as<const char *>(NameStr)));
}
ExtractElementInst ^ExtractElementInst::Create(Value ^Vec, Value ^Idx, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew ExtractElementInst(llvm::ExtractElementInst::Create(Vec->base, Idx->base, ctx.marshal_as<const char *>(NameStr), InsertBefore->base));
}
ExtractElementInst ^ExtractElementInst::Create(Value ^Vec, Value ^Idx, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return gcnew ExtractElementInst(llvm::ExtractElementInst::Create(Vec->base, Idx->base, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base));
}
bool ExtractElementInst::isValidOperands(Value ^Vec, Value ^Idx)
{
	return llvm::ExtractElementInst::isValidOperands(Vec->base, Idx->base);
}
Value ^ExtractElementInst::getVectorOperand()
{
	return gcnew Value(base->getVectorOperand());
}
Value ^ExtractElementInst::getIndexOperand()
{
	return gcnew Value(base->getIndexOperand());
}
VectorType ^ExtractElementInst::getVectorOperandType()
{
	return gcnew VectorType(base->getVectorOperandType());
}
inline bool ExtractElementInst::classof(Instruction ^I)
{
	return llvm::ExtractElementInst::classof(I->base);
}
inline bool ExtractElementInst::classof(Value ^V)
{
	return llvm::ExtractElementInst::classof(V->base);
}


InsertElementInst::InsertElementInst(llvm::InsertElementInst *base)
	: base(base)
	, Instruction(base)
{
}
InsertElementInst::!InsertElementInst()
{
}
InsertElementInst::~InsertElementInst()
{
	this->!InsertElementInst();
}
InsertElementInst ^InsertElementInst::Create(Value ^Vec, Value ^NewElt, Value ^Idx)
{
	return gcnew InsertElementInst(llvm::InsertElementInst::Create(Vec->base, NewElt->base, Idx->base));
}
InsertElementInst ^InsertElementInst::Create(Value ^Vec, Value ^NewElt, Value ^Idx, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return gcnew InsertElementInst(llvm::InsertElementInst::Create(Vec->base, NewElt->base, Idx->base, ctx.marshal_as<const char *>(NameStr)));
}
InsertElementInst ^InsertElementInst::Create(Value ^Vec, Value ^NewElt, Value ^Idx, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew InsertElementInst(llvm::InsertElementInst::Create(Vec->base, NewElt->base, Idx->base, ctx.marshal_as<const char *>(NameStr), InsertBefore->base));
}
InsertElementInst ^InsertElementInst::Create(Value ^Vec, Value ^NewElt, Value ^Idx, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return gcnew InsertElementInst(llvm::InsertElementInst::Create(Vec->base, NewElt->base, Idx->base, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base));
}
bool InsertElementInst::isValidOperands(Value ^Vec, Value ^NewElt, Value ^Idx)
{
	return llvm::InsertElementInst::isValidOperands(Vec->base, NewElt->base, Idx->base);
}
VectorType ^InsertElementInst::getType()
{
	return gcnew VectorType(base->getType());
}
inline bool InsertElementInst::classof(Instruction ^I)
{
	return llvm::InsertElementInst::classof(I->base);
}
inline bool InsertElementInst::classof(Value ^V)
{
	return llvm::InsertElementInst::classof(V->base);
}


ShuffleVectorInst::ShuffleVectorInst(llvm::ShuffleVectorInst *base)
	: base(base)
	, Instruction(base)
	, constructed(false)
{
}
ShuffleVectorInst::!ShuffleVectorInst()
{
	if (constructed)
	{
		delete base;
	}
}
ShuffleVectorInst::~ShuffleVectorInst()
{
	this->!ShuffleVectorInst();
}
ShuffleVectorInst::ShuffleVectorInst(Value ^V1, Value ^V2, Value ^Mask)
	: base(new llvm::ShuffleVectorInst(V1->base, V2->base, Mask->base))
	, Instruction(base)
	, constructed(true)
{
}
llvm::ShuffleVectorInst *ShuffleVectorInst::_construct(Value ^V1, Value ^V2, Value ^Mask, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::ShuffleVectorInst(V1->base, V2->base, Mask->base, ctx.marshal_as<const char *>(NameStr));
}
ShuffleVectorInst::ShuffleVectorInst(Value ^V1, Value ^V2, Value ^Mask, System::String ^NameStr)
	: base(_construct(V1, V2, Mask, NameStr))
	, Instruction(base)
	, constructed(true)
{
}
llvm::ShuffleVectorInst *ShuffleVectorInst::_construct(Value ^V1, Value ^V2, Value ^Mask, System::String ^NameStr, Instruction ^InsertBefor)
{
	msclr::interop::marshal_context ctx;
	return new llvm::ShuffleVectorInst(V1->base, V2->base, Mask->base, ctx.marshal_as<const char *>(NameStr), InsertBefor->base);
}
ShuffleVectorInst::ShuffleVectorInst(Value ^V1, Value ^V2, Value ^Mask, System::String ^NameStr, Instruction ^InsertBefor)
	: base(_construct(V1, V2, Mask, NameStr, InsertBefor))
	, Instruction(base)
	, constructed(true)
{
}
llvm::ShuffleVectorInst *ShuffleVectorInst::_construct(Value ^V1, Value ^V2, Value ^Mask, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::ShuffleVectorInst(V1->base, V2->base, Mask->base, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base);
}
ShuffleVectorInst::ShuffleVectorInst(Value ^V1, Value ^V2, Value ^Mask, System::String ^NameStr, BasicBlock ^InsertAtEnd)
	: base(_construct(V1, V2, Mask, NameStr, InsertAtEnd))
	, Instruction(base)
	, constructed(true)
{
}
bool ShuffleVectorInst::isValidOperands(Value ^V1, Value ^V2, Value ^Mask)
{
	return llvm::ShuffleVectorInst::isValidOperands(V1->base, V2->base, Mask->base);
}
VectorType ^ShuffleVectorInst::getType()
{
	return gcnew VectorType(base->getType());
}
Constant ^ShuffleVectorInst::getMask()
{
	return gcnew Constant(base->getMask());
}
int ShuffleVectorInst::getMaskValue(Constant ^Mask, unsigned i)
{
	return llvm::ShuffleVectorInst::getMaskValue(Mask->base, i);
}
int ShuffleVectorInst::getMaskValue(unsigned i)
{
	return base->getMaskValue(i);
}
array<int> ^ShuffleVectorInst::getShuffleMaskArray(Constant ^Mask)
{
	llvm::SmallVector<int, 8> r;
	llvm::ShuffleVectorInst::getShuffleMask(Mask->base, r);
	array<int> ^s = gcnew array<int>(r.size());
	for (int i = 0; i < s->Length; i++)
		s[i] = r[i];
	return s;
}
array<int> ^ShuffleVectorInst::getShuffleMaskArray()
{
	llvm::SmallVector<int, 8> r;
	base->getShuffleMask(r);
	array<int> ^s = gcnew array<int>(r.size());
	for (int i = 0; i < s->Length; i++)
		s[i] = r[i];
	return s;
}
inline bool ShuffleVectorInst::classof(Instruction ^I)
{
	return llvm::ShuffleVectorInst::classof(I->base);
}
inline bool ShuffleVectorInst::classof(Value ^V)
{
	return llvm::ShuffleVectorInst::classof(V->base);
}


ExtractValueInst::ExtractValueInst(llvm::ExtractValueInst *base)
	: base(base)
	, UnaryInstruction(base)
{
}
ExtractValueInst::!ExtractValueInst()
{
}
ExtractValueInst::~ExtractValueInst()
{
	this->!ExtractValueInst();
}
ExtractValueInst ^ExtractValueInst::Create(Value ^Agg, array<unsigned> ^Idxs)
{
	auto r = gcnew ExtractValueInst(llvm::ExtractValueInst::Create(Agg->base, utils::unmanage_array(Idxs)));
	return r;
}
ExtractValueInst ^ExtractValueInst::Create(Value ^Agg, array<unsigned> ^Idxs, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	auto r = gcnew ExtractValueInst(llvm::ExtractValueInst::Create(Agg->base, utils::unmanage_array(Idxs), ctx.marshal_as<const char *>(NameStr)));
	return r;
}
ExtractValueInst ^ExtractValueInst::Create(Value ^Agg, array<unsigned> ^Idxs, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	auto r = gcnew ExtractValueInst(llvm::ExtractValueInst::Create(Agg->base, utils::unmanage_array(Idxs), ctx.marshal_as<const char *>(NameStr), InsertBefore->base));
	return r;
}
ExtractValueInst ^ExtractValueInst::Create(Value ^Agg, array<unsigned> ^Idxs, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	auto r = gcnew ExtractValueInst(llvm::ExtractValueInst::Create(Agg->base, utils::unmanage_array(Idxs), ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base));
	return r;
}
Type ^ExtractValueInst::getIndexedType(Type ^Agg, array<unsigned> ^Idxs)
{
	auto r = gcnew Type(llvm::ExtractValueInst::getIndexedType(Agg->base, utils::unmanage_array(Idxs)));
	return r;
}
Value ^ExtractValueInst::getAggregateOperand()
{
	return gcnew Value(base->getAggregateOperand());
}
unsigned ExtractValueInst::getAggregateOperandIndex()
{
	return llvm::ExtractValueInst::getAggregateOperandIndex();
}
array<unsigned> ^ExtractValueInst::getIndices()
{
	auto r = base->getIndices();
	array<unsigned> ^s = gcnew array<unsigned>(r.size());
	for (int i = 0; i < s->Length; i++)
		s[i] = r[i];
	return s;
}
unsigned ExtractValueInst::getNumIndices()
{
	return base->getNumIndices();
}
bool ExtractValueInst::hasIndices()
{
	return base->hasIndices();
}
inline bool ExtractValueInst::classof(Instruction ^I)
{
	return llvm::ExtractValueInst::classof(I->base);
}
inline bool ExtractValueInst::classof(Value ^V)
{
	return llvm::ExtractValueInst::classof(V->base);
}


InsertValueInst::InsertValueInst(llvm::InsertValueInst *base)
	: base(base)
	, Instruction(base)
{
}
InsertValueInst::!InsertValueInst()
{
}
InsertValueInst::~InsertValueInst()
{
	this->!InsertValueInst();
}
InsertValueInst ^InsertValueInst::Create(Value ^Agg, Value ^Val, array<unsigned> ^Idxs)
{
	auto r = gcnew InsertValueInst(llvm::InsertValueInst::Create(Agg->base, Val->base, utils::unmanage_array(Idxs)));
	return r;
}
InsertValueInst ^InsertValueInst::Create(Value ^Agg, Value ^Val, array<unsigned> ^Idxs, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	auto r = gcnew InsertValueInst(llvm::InsertValueInst::Create(Agg->base, Val->base, utils::unmanage_array(Idxs), ctx.marshal_as<const char *>(NameStr)));
	return r;
}
InsertValueInst ^InsertValueInst::Create(Value ^Agg, Value ^Val, array<unsigned> ^Idxs, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	auto r = gcnew InsertValueInst(llvm::InsertValueInst::Create(Agg->base, Val->base, utils::unmanage_array(Idxs), ctx.marshal_as<const char *>(NameStr), InsertBefore->base));
	return r;
}
InsertValueInst ^InsertValueInst::Create(Value ^Agg, Value ^Val, array<unsigned> ^Idxs, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	auto r = gcnew InsertValueInst(llvm::InsertValueInst::Create(Agg->base, Val->base, utils::unmanage_array(Idxs), ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base));
	return r;
}
Value ^InsertValueInst::getAggregateOperand()
{
	return gcnew Value(base->getAggregateOperand());
}
unsigned InsertValueInst::getAggregateOperandIndex()
{
	return llvm::InsertValueInst::getAggregateOperandIndex();
}
Value ^InsertValueInst::getInsertedValueOperand()
{
	return gcnew Value(base->getInsertedValueOperand());
}
unsigned InsertValueInst::getInsertedValueOperandIndex()
{
	return llvm::InsertValueInst::getInsertedValueOperandIndex();
}
array<unsigned> ^InsertValueInst::getIndices()
{
	auto r = base->getIndices();
	array<unsigned> ^s = gcnew array<unsigned>(r.size());
	for (int i = 0; i < s->Length; i++)
		s[i] = r[i];
	return s;
}
unsigned InsertValueInst::getNumIndices()
{
	return base->getNumIndices();
}
bool InsertValueInst::hasIndices()
{
	return base->hasIndices();
}
inline bool InsertValueInst::classof(Instruction ^I)
{
	return llvm::InsertValueInst::classof(I->base);
}
inline bool InsertValueInst::classof(Value ^V)
{
	return llvm::InsertValueInst::classof(V->base);
}


PHINode::PHINode(llvm::PHINode *base)
	: base(base)
	, Instruction(base)
{
}
PHINode::!PHINode()
{
}
PHINode::~PHINode()
{
	this->!PHINode();
}
PHINode ^PHINode::Create(Type ^Ty, unsigned NumReservedValues)
{
	return gcnew PHINode(llvm::PHINode::Create(Ty->base, NumReservedValues));
}
PHINode ^PHINode::Create(Type ^Ty, unsigned NumReservedValues, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return gcnew PHINode(llvm::PHINode::Create(Ty->base, NumReservedValues, ctx.marshal_as<const char *>(NameStr)));
}
PHINode ^PHINode::Create(Type ^Ty, unsigned NumReservedValues, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew PHINode(llvm::PHINode::Create(Ty->base, NumReservedValues, ctx.marshal_as<const char *>(NameStr), InsertBefore->base));
}
PHINode ^PHINode::Create(Type ^Ty, unsigned NumReservedValues, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return gcnew PHINode(llvm::PHINode::Create(Ty->base, NumReservedValues, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base));
}
unsigned PHINode::getNumIncomingValues()
{
	return base->getNumIncomingValues();
}
Value ^PHINode::getIncomingValue(unsigned i)
{
	return gcnew Value(base->getIncomingValue(i));
}
void PHINode::setIncomingValue(unsigned i, Value ^V)
{
	base->setIncomingValue(i, V->base);
}
unsigned PHINode::getOperandNumForIncomingValue(unsigned i)
{
	return llvm::PHINode::getOperandNumForIncomingValue(i);
}
unsigned PHINode::getIncomingValueNumForOperand(unsigned i)
{
	return llvm::PHINode::getIncomingValueNumForOperand(i);
}
BasicBlock ^PHINode::getIncomingBlock(unsigned i)
{
	return gcnew BasicBlock(base->getIncomingBlock(i));
}
BasicBlock ^PHINode::getIncomingBlock(Use ^U)
{
	return gcnew BasicBlock(base->getIncomingBlock(*U->base));
}
void PHINode::setIncomingBlock(unsigned i, BasicBlock ^BB)
{
	base->setIncomingBlock(i, BB->base);
}
void PHINode::addIncoming(Value ^V, BasicBlock ^BB)
{
	base->addIncoming(V->base, BB->base);
}
Value ^PHINode::removeIncomingValue(unsigned Idx)
{
	return gcnew Value(base->removeIncomingValue(Idx));
}
Value ^PHINode::removeIncomingValue(unsigned Idx, bool DeletePHIIfEmpty)
{
	return gcnew Value(base->removeIncomingValue(Idx, DeletePHIIfEmpty));
}
Value ^PHINode::removeIncomingValue(BasicBlock ^BB)
{
	return gcnew Value(base->removeIncomingValue(BB->base));
}
Value ^PHINode::removeIncomingValue(BasicBlock ^BB, bool DeletePHIIfEmpty)
{
	return gcnew Value(base->removeIncomingValue(BB->base, DeletePHIIfEmpty));
}
int PHINode::getBasicBlockIndex(BasicBlock ^BB)
{
	return base->getBasicBlockIndex(BB->base);
}
Value ^PHINode::getIncomingValueForBlock(BasicBlock ^BB)
{
	return gcnew Value(base->getIncomingValueForBlock(BB->base));
}
Value ^PHINode::hasConstantValue()
{
	return gcnew Value(base->hasConstantValue());
}
inline bool PHINode::classof(Instruction ^I)
{
	return llvm::PHINode::classof(I->base);
}
inline bool PHINode::classof(Value ^V)
{
	return llvm::PHINode::classof(V->base);
}


LandingPadInst::LandingPadInst(llvm::LandingPadInst *base)
	: base(base)
	, Instruction(base)
{
}
LandingPadInst::!LandingPadInst()
{
}
LandingPadInst::~LandingPadInst()
{
	this->!LandingPadInst();
}
LandingPadInst ^LandingPadInst::Create(Type ^RetTy, Value ^PersonalityFn, unsigned NumReservedClauses)
{
	return gcnew LandingPadInst(llvm::LandingPadInst::Create(RetTy->base, PersonalityFn->base, NumReservedClauses));
}
LandingPadInst ^LandingPadInst::Create(Type ^RetTy, Value ^PersonalityFn, unsigned NumReservedClauses, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return gcnew LandingPadInst(llvm::LandingPadInst::Create(RetTy->base, PersonalityFn->base, NumReservedClauses, ctx.marshal_as<const char *>(NameStr)));
}
LandingPadInst ^LandingPadInst::Create(Type ^RetTy, Value ^PersonalityFn, unsigned NumReservedClauses, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew LandingPadInst(llvm::LandingPadInst::Create(RetTy->base, PersonalityFn->base, NumReservedClauses, ctx.marshal_as<const char *>(NameStr), InsertBefore->base));
}
LandingPadInst ^LandingPadInst::Create(Type ^RetTy, Value ^PersonalityFn, unsigned NumReservedClauses, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return gcnew LandingPadInst(llvm::LandingPadInst::Create(RetTy->base, PersonalityFn->base, NumReservedClauses, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base));
}
Value ^LandingPadInst::getPersonalityFn()
{
	return gcnew Value(base->getPersonalityFn());
}
bool LandingPadInst::isCleanup()
{
	return base->isCleanup();
}
void LandingPadInst::setCleanup(bool V)
{
	base->setCleanup(V);
}
void LandingPadInst::addClause(Value ^ClauseVal)
{
	base->addClause(ClauseVal->base);
}
Value ^LandingPadInst::getClause(unsigned Idx)
{
	return gcnew Value(base->getClause(Idx));
}
bool LandingPadInst::isCatch(unsigned Idx)
{
	return base->isCatch(Idx);
}
bool LandingPadInst::isFilter(unsigned Idx)
{
	return base->isFilter(Idx);
}
unsigned LandingPadInst::getNumClauses()
{
	return base->getNumClauses();
}
void LandingPadInst::reserveClauses(unsigned Size)
{
	base->reserveClauses(Size);
}
inline bool LandingPadInst::classof(Instruction ^I)
{
	return llvm::LandingPadInst::classof(I->base);
}
inline bool LandingPadInst::classof(Value ^V)
{
	return llvm::LandingPadInst::classof(V->base);
}


ReturnInst::ReturnInst(llvm::ReturnInst *base)
	: base(base)
	, TerminatorInst(base)
{
}
ReturnInst::!ReturnInst()
{
}
ReturnInst::~ReturnInst()
{
	this->!ReturnInst();
}
ReturnInst ^ReturnInst::Create(LLVMContext ^C)
{
	return gcnew ReturnInst(llvm::ReturnInst::Create(*C->base));
}
ReturnInst ^ReturnInst::Create(LLVMContext ^C, Value ^retVal)
{
	return gcnew ReturnInst(llvm::ReturnInst::Create(*C->base, retVal->base));
}
ReturnInst ^ReturnInst::Create(LLVMContext ^C, Value ^retVal, Instruction ^InsertBefore)
{
	return gcnew ReturnInst(llvm::ReturnInst::Create(*C->base, retVal->base, InsertBefore->base));
}
ReturnInst ^ReturnInst::Create(LLVMContext ^C, Value ^retVal, BasicBlock ^InsertAtEnd)
{
	return gcnew ReturnInst(llvm::ReturnInst::Create(*C->base, retVal->base, InsertAtEnd->base));
}
ReturnInst ^ReturnInst::Create(LLVMContext ^C, BasicBlock ^InsertAtEnd)
{
	return gcnew ReturnInst(llvm::ReturnInst::Create(*C->base, InsertAtEnd->base));
}
Value ^ReturnInst::getReturnValue()
{
	return gcnew Value(base->getReturnValue());
}
unsigned ReturnInst::getNumSuccessors()
{
	return base->getNumSuccessors();
}
inline bool ReturnInst::classof(Instruction ^I)
{
	return llvm::ReturnInst::classof(I->base);
}
inline bool ReturnInst::classof(Value ^V)
{
	return llvm::ReturnInst::classof(V->base);
}


BranchInst::BranchInst(llvm::BranchInst *base)
	: base(base)
	, TerminatorInst(base)
{
}
BranchInst::!BranchInst()
{
}
BranchInst::~BranchInst()
{
	this->!BranchInst();
}
BranchInst ^BranchInst::Create(BasicBlock ^IfTrue)
{
	return gcnew BranchInst(llvm::BranchInst::Create(IfTrue->base));
}
BranchInst ^BranchInst::Create(BasicBlock ^IfTrue, Instruction ^InsertBefore)
{
	return gcnew BranchInst(llvm::BranchInst::Create(IfTrue->base, InsertBefore->base));
}
BranchInst ^BranchInst::Create(BasicBlock ^IfTrue, BasicBlock ^IfFalse, Value ^Cond)
{
	return gcnew BranchInst(llvm::BranchInst::Create(IfTrue->base, IfFalse->base, Cond->base));
}
BranchInst ^BranchInst::Create(BasicBlock ^IfTrue, BasicBlock ^IfFalse, Value ^Cond, Instruction ^InsertBefore)
{
	return gcnew BranchInst(llvm::BranchInst::Create(IfTrue->base, IfFalse->base, Cond->base, InsertBefore->base));
}
BranchInst ^BranchInst::Create(BasicBlock ^IfTrue, BasicBlock ^InsertAtEnd)
{
	return gcnew BranchInst(llvm::BranchInst::Create(IfTrue->base, InsertAtEnd->base));
}
BranchInst ^BranchInst::Create(BasicBlock ^IfTrue, BasicBlock ^IfFalse, Value ^Cond, BasicBlock ^InsertAtEnd)
{
	return gcnew BranchInst(llvm::BranchInst::Create(IfTrue->base, IfFalse->base, Cond->base, InsertAtEnd->base));
}
bool BranchInst::isUnconditional()
{
	return base->isUnconditional();
}
bool BranchInst::isConditional()
{
	return base->isConditional();
}
Value ^BranchInst::getCondition()
{
	return gcnew Value(base->getCondition());
}
void BranchInst::setCondition(Value ^V)
{
	base->setCondition(V->base);
}
unsigned BranchInst::getNumSuccessors()
{
	return base->getNumSuccessors();
}
BasicBlock ^BranchInst::getSuccessor(unsigned i)
{
	return gcnew BasicBlock(base->getSuccessor(i));
}
void BranchInst::setSuccessor(unsigned idx, BasicBlock ^NewSucc)
{
	base->setSuccessor(idx, NewSucc->base);
}
void BranchInst::swapSuccessors()
{
	base->swapSuccessors();
}
inline bool BranchInst::classof(Instruction ^I)
{
	return llvm::BranchInst::classof(I->base);
}
inline bool BranchInst::classof(Value ^V)
{
	return llvm::BranchInst::classof(V->base);
}


SwitchInst::SwitchInst(llvm::SwitchInst *base)
	: base(base)
	, TerminatorInst(base)
{
}
SwitchInst::!SwitchInst()
{
}
SwitchInst::~SwitchInst()
{
	this->!SwitchInst();
}
SwitchInst ^SwitchInst::Create(Value ^Value, BasicBlock ^Default, unsigned NumCases)
{
	return gcnew SwitchInst(llvm::SwitchInst::Create(Value->base, Default->base, NumCases));
}
SwitchInst ^SwitchInst::Create(Value ^Value, BasicBlock ^Default, unsigned NumCases, Instruction ^InsertBefore)
{
	return gcnew SwitchInst(llvm::SwitchInst::Create(Value->base, Default->base, NumCases, InsertBefore->base));
}
SwitchInst ^SwitchInst::Create(Value ^Value, BasicBlock ^Default, unsigned NumCases, BasicBlock ^InsertAtEnd)
{
	return gcnew SwitchInst(llvm::SwitchInst::Create(Value->base, Default->base, NumCases, InsertAtEnd->base));
}
Value ^SwitchInst::getCondition()
{
	return gcnew Value(base->getCondition());
}
void SwitchInst::setCondition(Value ^V)
{
	base->setCondition(V->base);
}
BasicBlock ^SwitchInst::getDefaultDest()
{
	return gcnew BasicBlock(base->getDefaultDest());
}
void SwitchInst::setDefaultDest(BasicBlock ^DefaultCase)
{
	base->setDefaultDest(DefaultCase->base);
}
unsigned SwitchInst::getNumCases()
{
	return base->getNumCases();
}
ConstantInt ^SwitchInst::findCaseDest(BasicBlock ^BB)
{
	return gcnew ConstantInt(base->findCaseDest(BB->base));
}
void SwitchInst::addCase(ConstantInt ^OnVal, BasicBlock ^Dest)
{
	base->addCase(OnVal->base, Dest->base);
}
unsigned SwitchInst::getNumSuccessors()
{
	return base->getNumSuccessors();
}
BasicBlock ^SwitchInst::getSuccessor(unsigned idx)
{
	return gcnew BasicBlock(base->getSuccessor(idx));
}
void SwitchInst::setSuccessor(unsigned idx, BasicBlock ^NewSucc)
{
	base->setSuccessor(idx, NewSucc->base);
}
uint16_t SwitchInst::hash()
{
	return base->hash();
}
inline bool SwitchInst::classof(Instruction ^I)
{
	return llvm::SwitchInst::classof(I->base);
}
inline bool SwitchInst::classof(Value ^V)
{
	return llvm::SwitchInst::classof(V->base);
}


IndirectBrInst::IndirectBrInst(llvm::IndirectBrInst *base)
	: base(base)
	, TerminatorInst(base)
{
}
IndirectBrInst::!IndirectBrInst()
{
}
IndirectBrInst::~IndirectBrInst()
{
	this->!IndirectBrInst();
}
IndirectBrInst ^IndirectBrInst::Create(Value ^Address, unsigned NumDests)
{
	return gcnew IndirectBrInst(llvm::IndirectBrInst::Create(Address->base, NumDests));
}
IndirectBrInst ^IndirectBrInst::Create(Value ^Address, unsigned NumDests, Instruction ^InsertBefore)
{
	return gcnew IndirectBrInst(llvm::IndirectBrInst::Create(Address->base, NumDests, InsertBefore->base));
}
IndirectBrInst ^IndirectBrInst::Create(Value ^Address, unsigned NumDests, BasicBlock ^InsertAtEnd)
{
	return gcnew IndirectBrInst(llvm::IndirectBrInst::Create(Address->base, NumDests, InsertAtEnd->base));
}
Value ^IndirectBrInst::getAddress()
{
	return gcnew Value(base->getAddress());
}
void IndirectBrInst::setAddress(Value ^V)
{
	base->setAddress(V->base);
}
unsigned IndirectBrInst::getNumDestinations()
{
	return base->getNumDestinations();
}
BasicBlock ^IndirectBrInst::getDestination(unsigned i)
{
	return gcnew BasicBlock(base->getDestination(i));
}
void IndirectBrInst::addDestination(BasicBlock ^Dest)
{
	base->addDestination(Dest->base);
}
void IndirectBrInst::removeDestination(unsigned i)
{
	base->removeDestination(i);
}
unsigned IndirectBrInst::getNumSuccessors()
{
	return base->getNumSuccessors();
}
BasicBlock ^IndirectBrInst::getSuccessor(unsigned i)
{
	return gcnew BasicBlock(base->getSuccessor(i));
}
void IndirectBrInst::setSuccessor(unsigned i, BasicBlock ^NewSucc)
{
	base->setSuccessor(i, NewSucc->base);
}
inline bool IndirectBrInst::classof(Instruction ^I)
{
	return llvm::IndirectBrInst::classof(I->base);
}
inline bool IndirectBrInst::classof(Value ^V)
{
	return llvm::IndirectBrInst::classof(V->base);
}


InvokeInst::InvokeInst(llvm::InvokeInst *base)
	: base(base)
	, TerminatorInst(base)
{
}
InvokeInst::!InvokeInst()
{
}
InvokeInst::~InvokeInst()
{
	this->!InvokeInst();
}
InvokeInst ^InvokeInst::Create(Value ^Func, BasicBlock ^IfNormal, BasicBlock ^IfException, array<Value ^> ^Args)
{
	llvm::Value **b = new llvm::Value*[Args->Length];
	for (int i = 0; i < Args->Length; i++)
		b[i] = Args[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, Args->Length);
	auto r = gcnew InvokeInst(llvm::InvokeInst::Create(Func->base, IfNormal->base, IfException->base, brr));
	delete b;
	return r;
}
InvokeInst ^InvokeInst::Create(Value ^Func, BasicBlock ^IfNormal, BasicBlock ^IfException, array<Value ^> ^Args, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	llvm::Value **b = new llvm::Value*[Args->Length];
	for (int i = 0; i < Args->Length; i++)
		b[i] = Args[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, Args->Length);
	auto r = gcnew InvokeInst(llvm::InvokeInst::Create(Func->base, IfNormal->base, IfException->base, brr, ctx.marshal_as<const char *>(NameStr)));
	delete b;
	return r;
}
InvokeInst ^InvokeInst::Create(Value ^Func, BasicBlock ^IfNormal, BasicBlock ^IfException, array<Value ^> ^Args, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	llvm::Value **b = new llvm::Value*[Args->Length];
	for (int i = 0; i < Args->Length; i++)
		b[i] = Args[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, Args->Length);
	auto r = gcnew InvokeInst(llvm::InvokeInst::Create(Func->base, IfNormal->base, IfException->base, brr, ctx.marshal_as<const char *>(NameStr), InsertBefore->base));
	delete b;
	return r;
}
InvokeInst ^InvokeInst::Create(Value ^Func, BasicBlock ^IfNormal, BasicBlock ^IfException, array<Value ^> ^Args, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	llvm::Value **b = new llvm::Value*[Args->Length];
	for (int i = 0; i < Args->Length; i++)
		b[i] = Args[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, Args->Length);
	auto r = gcnew InvokeInst(llvm::InvokeInst::Create(Func->base, IfNormal->base, IfException->base, brr, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base));
	delete b;
	return r;
}
unsigned InvokeInst::getNumArgOperands()
{
	return base->getNumArgOperands();
}
Value ^InvokeInst::getArgOperand(unsigned i)
{
	return gcnew Value(base->getArgOperand(i));
}
void InvokeInst::setArgOperand(unsigned i, Value ^v)
{
	base->setArgOperand(i, v->base);
}
CallingConv::ID InvokeInst::getCallingConv()
{
	return safe_cast<CallingConv::ID>(base->getCallingConv());
}
void InvokeInst::setCallingConv(CallingConv::ID CC)
{
	base->setCallingConv(safe_cast<llvm::CallingConv::ID>(CC));
}
void InvokeInst::setAttributes(AttributeSet ^Attrs)
{
	base->setAttributes(*Attrs->base);
}
void InvokeInst::addAttribute(unsigned i, Attribute::AttrKind attr)
{
	base->addAttribute(i, safe_cast<llvm::Attribute::AttrKind>(attr));
}
void InvokeInst::removeAttribute(unsigned i, Attribute ^attr)
{
	base->removeAttribute(i, *attr->base);
}
bool InvokeInst::hasFnAttr(Attribute::AttrKind A)
{
	return base->hasFnAttr(safe_cast<llvm::Attribute::AttrKind>(A));
}
bool InvokeInst::paramHasAttr(unsigned i, Attribute::AttrKind A)
{
	return base->paramHasAttr(i, safe_cast<llvm::Attribute::AttrKind>(A));
}
unsigned InvokeInst::getParamAlignment(unsigned i)
{
	return base->getParamAlignment(i);
}
bool InvokeInst::isNoInline()
{
	return base->isNoInline();
}
void InvokeInst::setIsNoInline()
{
	base->setIsNoInline();
}
bool InvokeInst::doesNotAccessMemory()
{
	return base->doesNotAccessMemory();
}
void InvokeInst::setDoesNotAccessMemory()
{
	base->setDoesNotAccessMemory();
}
bool InvokeInst::onlyReadsMemory()
{
	return base->onlyReadsMemory();
}
void InvokeInst::setOnlyReadsMemory()
{
	base->setOnlyReadsMemory();
}
bool InvokeInst::doesNotReturn()
{
	return base->doesNotReturn();
}
void InvokeInst::setDoesNotReturn()
{
	base->setDoesNotReturn();
}
bool InvokeInst::doesNotThrow()
{
	return base->doesNotThrow();
}
void InvokeInst::setDoesNotThrow()
{
	base->setDoesNotThrow();
}
bool InvokeInst::hasStructRetAttr()
{
	return base->hasStructRetAttr();
}
bool InvokeInst::hasByValArgument()
{
	return base->hasByValArgument();
}
Function ^InvokeInst::getCalledFunction()
{
	return gcnew Function(base->getCalledFunction());
}
Value ^InvokeInst::getCalledValue()
{
	return gcnew Value(base->getCalledValue());
}
void InvokeInst::setCalledFunction(Value ^Fn)
{
	base->setCalledFunction(Fn->base);
}
BasicBlock ^InvokeInst::getNormalDest()
{
	return gcnew BasicBlock(base->getNormalDest());
}
BasicBlock ^InvokeInst::getUnwindDest()
{
	return gcnew BasicBlock(base->getUnwindDest());
}
void InvokeInst::setNormalDest(BasicBlock ^B)
{
	base->setNormalDest(B->base);
}
void InvokeInst::setUnwindDest(BasicBlock ^B)
{
	base->setUnwindDest(B->base);
}
LandingPadInst ^InvokeInst::getLandingPadInst()
{
	return gcnew LandingPadInst(base->getLandingPadInst());
}
BasicBlock ^InvokeInst::getSuccessor(unsigned i)
{
	return gcnew BasicBlock(base->getSuccessor(i));
}
void InvokeInst::setSuccessor(unsigned idx, BasicBlock ^NewSucc)
{
	base->setSuccessor(idx, NewSucc->base);
}
unsigned InvokeInst::getNumSuccessors()
{
	return base->getNumSuccessors();
}
inline bool InvokeInst::classof(Instruction ^I)
{
	return llvm::InvokeInst::classof(I->base);
}
inline bool InvokeInst::classof(Value ^V)
{
	return llvm::InvokeInst::classof(V->base);
}


ResumeInst::ResumeInst(llvm::ResumeInst *base)
	: base(base)
	, TerminatorInst(base)
{
}
ResumeInst::!ResumeInst()
{
}
ResumeInst::~ResumeInst()
{
	this->!ResumeInst();
}
ResumeInst ^ResumeInst::Create(Value ^Exn)
{
	return gcnew ResumeInst(llvm::ResumeInst::Create(Exn->base));
}
ResumeInst ^ResumeInst::Create(Value ^Exn, Instruction ^InsertBefore)
{
	return gcnew ResumeInst(llvm::ResumeInst::Create(Exn->base, InsertBefore->base));
}
ResumeInst ^ResumeInst::Create(Value ^Exn, BasicBlock ^InsertAtEnd)
{
	return gcnew ResumeInst(llvm::ResumeInst::Create(Exn->base, InsertAtEnd->base));
}
Value ^ResumeInst::getValue()
{
	return gcnew Value(base->getValue());
}
unsigned ResumeInst::getNumSuccessors()
{
	return base->getNumSuccessors();
}
inline bool ResumeInst::classof(Instruction ^I)
{
	return llvm::ResumeInst::classof(I->base);
}
inline bool ResumeInst::classof(Value ^V)
{
	return llvm::ResumeInst::classof(V->base);
}


UnreachableInst::UnreachableInst(llvm::UnreachableInst *base)
	: base(base)
	, TerminatorInst(base)
	, constructed(false)
{
}
UnreachableInst::!UnreachableInst()
{
	if (constructed)
	{
		delete base;
	}
}
UnreachableInst::~UnreachableInst()
{
	this->!UnreachableInst();
}
UnreachableInst::UnreachableInst(LLVMContext ^C)
	: base(new llvm::UnreachableInst(*C->base))
	, TerminatorInst(base)
	, constructed(true)
{
}
UnreachableInst::UnreachableInst(LLVMContext ^C, Instruction ^InsertBefore)
	: base(new llvm::UnreachableInst(*C->base, InsertBefore->base))
	, TerminatorInst(base)
	, constructed(true)
{
}
UnreachableInst::UnreachableInst(LLVMContext ^C, BasicBlock ^InsertAtEnd)
	: base(new llvm::UnreachableInst(*C->base, InsertAtEnd->base))
	, TerminatorInst(base)
	, constructed(true)
{
}
unsigned UnreachableInst::getNumSuccessors()
{
	return base->getNumSuccessors();
}
inline bool UnreachableInst::classof(Instruction ^I)
{
	return llvm::UnreachableInst::classof(I->base);
}
inline bool UnreachableInst::classof(Value ^V)
{
	return llvm::UnreachableInst::classof(V->base);
}


TruncInst::TruncInst(llvm::TruncInst *base)
	: base(base)
	, CastInst(base)
	, constructed(false)
{
}
TruncInst::!TruncInst()
{
	if (constructed)
	{
		delete base;
	}
}
TruncInst::~TruncInst()
{
	this->!TruncInst();
}
TruncInst::TruncInst(Value ^S, Type ^Ty)
	: base(new llvm::TruncInst(S->base, Ty->base))
	, CastInst(base)
	, constructed(true)
{
}
llvm::TruncInst *TruncInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::TruncInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr));
}
TruncInst::TruncInst(Value ^S, Type ^Ty, System::String ^NameStr)
	: base(_construct(S, Ty, NameStr))
	, CastInst(base)
	, constructed(true)
{
}
llvm::TruncInst *TruncInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::TruncInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertBefore->base);
}
TruncInst::TruncInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
	: base(_construct(S, Ty, NameStr, InsertBefore))
	, CastInst(base)
	, constructed(true)
{
}
llvm::TruncInst *TruncInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::TruncInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base);
}
TruncInst::TruncInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
	: base(_construct(S, Ty, NameStr, InsertAtEnd))
	, CastInst(base)
	, constructed(true)
{
}
inline bool TruncInst::classof(Instruction ^I)
{
	return llvm::TruncInst::classof(I->base);
}
inline bool TruncInst::classof(Value ^V)
{
	return llvm::TruncInst::classof(V->base);
}


ZExtInst::ZExtInst(llvm::ZExtInst *base)
	: base(base)
	, CastInst(base)
	, constructed(false)
{
}
ZExtInst::!ZExtInst()
{
	if (constructed)
	{
		delete base;
	}
}
ZExtInst::~ZExtInst()
{
	this->!ZExtInst();
}
ZExtInst::ZExtInst(Value ^S, Type ^Ty)
	: base(new llvm::ZExtInst(S->base, Ty->base))
	, CastInst(base)
	, constructed(true)
{
}
llvm::ZExtInst *ZExtInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::ZExtInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr));
}
ZExtInst::ZExtInst(Value ^S, Type ^Ty, System::String ^NameStr)
	: base(_construct(S, Ty, NameStr))
	, CastInst(base)
	, constructed(true)
{
}
llvm::ZExtInst *ZExtInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::ZExtInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertBefore->base);
}
ZExtInst::ZExtInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
	: base(_construct(S, Ty, NameStr, InsertBefore))
	, CastInst(base)
	, constructed(true)
{
}
llvm::ZExtInst *ZExtInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::ZExtInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base);
}
ZExtInst::ZExtInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
	: base(_construct(S, Ty, NameStr, InsertAtEnd))
	, CastInst(base)
	, constructed(true)
{
}
inline bool ZExtInst::classof(Instruction ^I)
{
	return llvm::ZExtInst::classof(I->base);
}
inline bool ZExtInst::classof(Value ^V)
{
	return llvm::ZExtInst::classof(V->base);
}


SExtInst::SExtInst(llvm::SExtInst *base)
	: base(base)
	, CastInst(base)
	, constructed(false)
{
}
SExtInst::!SExtInst()
{
	if (constructed)
	{
		delete base;
	}
}
SExtInst::~SExtInst()
{
	this->!SExtInst();
}
SExtInst::SExtInst(Value ^S, Type ^Ty)
	: base(new llvm::SExtInst(S->base, Ty->base))
	, CastInst(base)
	, constructed(true)
{
}
llvm::SExtInst *SExtInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::SExtInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr));
}
SExtInst::SExtInst(Value ^S, Type ^Ty, System::String ^NameStr)
	: base(_construct(S, Ty, NameStr))
	, CastInst(base)
	, constructed(true)
{
}
llvm::SExtInst *SExtInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::SExtInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertBefore->base);
}
SExtInst::SExtInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
	: base(_construct(S, Ty, NameStr, InsertBefore))
	, CastInst(base)
	, constructed(true)
{
}
llvm::SExtInst *SExtInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::SExtInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base);
}
SExtInst::SExtInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
	: base(_construct(S, Ty, NameStr, InsertAtEnd))
	, CastInst(base)
	, constructed(true)
{
}
inline bool SExtInst::classof(Instruction ^I)
{
	return llvm::SExtInst::classof(I->base);
}
inline bool SExtInst::classof(Value ^V)
{
	return llvm::SExtInst::classof(V->base);
}


FPTruncInst::FPTruncInst(llvm::FPTruncInst *base)
	: base(base)
	, CastInst(base)
	, constructed(false)
{
}
FPTruncInst::!FPTruncInst()
{
	if (constructed)
	{
		delete base;
	}
}
FPTruncInst::~FPTruncInst()
{
	this->!FPTruncInst();
}
FPTruncInst::FPTruncInst(Value ^S, Type ^Ty)
	: base(new llvm::FPTruncInst(S->base, Ty->base))
	, CastInst(base)
	, constructed(true)
{
}
llvm::FPTruncInst *FPTruncInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::FPTruncInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr));
}
FPTruncInst::FPTruncInst(Value ^S, Type ^Ty, System::String ^NameStr)
	: base(_construct(S, Ty, NameStr))
	, CastInst(base)
	, constructed(true)
{
}
llvm::FPTruncInst *FPTruncInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::FPTruncInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertBefore->base);
}
FPTruncInst::FPTruncInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
	: base(_construct(S, Ty, NameStr, InsertBefore))
	, CastInst(base)
	, constructed(true)
{
}
llvm::FPTruncInst *FPTruncInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::FPTruncInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base);
}
FPTruncInst::FPTruncInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
	: base(_construct(S, Ty, NameStr, InsertAtEnd))
	, CastInst(base)
	, constructed(true)
{
}
inline bool FPTruncInst::classof(Instruction ^I)
{
	return llvm::FPTruncInst::classof(I->base);
}
inline bool FPTruncInst::classof(Value ^V)
{
	return llvm::FPTruncInst::classof(V->base);
}


FPExtInst::FPExtInst(llvm::FPExtInst *base)
	: base(base)
	, CastInst(base)
	, constructed(false)
{
}
FPExtInst::!FPExtInst()
{
	if (constructed)
	{
		delete base;
	}
}
FPExtInst::~FPExtInst()
{
	this->!FPExtInst();
}
FPExtInst::FPExtInst(Value ^S, Type ^Ty)
	: base(new llvm::FPExtInst(S->base, Ty->base))
	, CastInst(base)
	, constructed(true)
{
}
llvm::FPExtInst *FPExtInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::FPExtInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr));
}
FPExtInst::FPExtInst(Value ^S, Type ^Ty, System::String ^NameStr)
	: base(_construct(S, Ty, NameStr))
	, CastInst(base)
	, constructed(true)
{
}
llvm::FPExtInst *FPExtInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::FPExtInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertBefore->base);
}
FPExtInst::FPExtInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
	: base(_construct(S, Ty, NameStr, InsertBefore))
	, CastInst(base)
	, constructed(true)
{
}
llvm::FPExtInst *FPExtInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::FPExtInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base);
}
FPExtInst::FPExtInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
	: base(_construct(S, Ty, NameStr, InsertAtEnd))
	, CastInst(base)
	, constructed(true)
{
}
inline bool FPExtInst::classof(Instruction ^I)
{
	return llvm::FPExtInst::classof(I->base);
}
inline bool FPExtInst::classof(Value ^V)
{
	return llvm::FPExtInst::classof(V->base);
}


UIToFPInst::UIToFPInst(llvm::UIToFPInst *base)
	: base(base)
	, CastInst(base)
	, constructed(false)
{
}
UIToFPInst::!UIToFPInst()
{
	if (constructed)
	{
		delete base;
	}
}
UIToFPInst::~UIToFPInst()
{
	this->!UIToFPInst();
}
UIToFPInst::UIToFPInst(Value ^S, Type ^Ty)
	: base(new llvm::UIToFPInst(S->base, Ty->base))
	, CastInst(base)
	, constructed(true)
{
}
llvm::UIToFPInst *UIToFPInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::UIToFPInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr));
}
UIToFPInst::UIToFPInst(Value ^S, Type ^Ty, System::String ^NameStr)
	: base(_construct(S, Ty, NameStr))
	, CastInst(base)
	, constructed(true)
{
}
llvm::UIToFPInst *UIToFPInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::UIToFPInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertBefore->base);
}
UIToFPInst::UIToFPInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
	: base(_construct(S, Ty, NameStr, InsertBefore))
	, CastInst(base)
	, constructed(true)
{
}
llvm::UIToFPInst *UIToFPInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::UIToFPInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base);
}
UIToFPInst::UIToFPInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
	: base(_construct(S, Ty, NameStr, InsertAtEnd))
	, CastInst(base)
	, constructed(true)
{
}
inline bool UIToFPInst::classof(Instruction ^I)
{
	return llvm::UIToFPInst::classof(I->base);
}
inline bool UIToFPInst::classof(Value ^V)
{
	return llvm::UIToFPInst::classof(V->base);
}


SIToFPInst::SIToFPInst(llvm::SIToFPInst *base)
	: base(base)
	, CastInst(base)
	, constructed(false)
{
}
SIToFPInst::!SIToFPInst()
{
	if (constructed)
	{
		delete base;
	}
}
SIToFPInst::~SIToFPInst()
{
	this->!SIToFPInst();
}
SIToFPInst::SIToFPInst(Value ^S, Type ^Ty)
	: base(new llvm::SIToFPInst(S->base, Ty->base))
	, CastInst(base)
	, constructed(true)
{
}
llvm::SIToFPInst *SIToFPInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::SIToFPInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr));
}
SIToFPInst::SIToFPInst(Value ^S, Type ^Ty, System::String ^NameStr)
	: base(_construct(S, Ty, NameStr))
	, CastInst(base)
	, constructed(true)
{
}
llvm::SIToFPInst *SIToFPInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::SIToFPInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertBefore->base);
}
SIToFPInst::SIToFPInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
	: base(_construct(S, Ty, NameStr, InsertBefore))
	, CastInst(base)
	, constructed(true)
{
}
llvm::SIToFPInst *SIToFPInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::SIToFPInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base);
}
SIToFPInst::SIToFPInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
	: base(_construct(S, Ty, NameStr, InsertAtEnd))
	, CastInst(base)
	, constructed(true)
{
}
inline bool SIToFPInst::classof(Instruction ^I)
{
	return llvm::SIToFPInst::classof(I->base);
}
inline bool SIToFPInst::classof(Value ^V)
{
	return llvm::SIToFPInst::classof(V->base);
}


FPToUIInst::FPToUIInst(llvm::FPToUIInst *base)
	: base(base)
	, CastInst(base)
	, constructed(false)
{
}
FPToUIInst::!FPToUIInst()
{
	if (constructed)
	{
		delete base;
	}
}
FPToUIInst::~FPToUIInst()
{
	this->!FPToUIInst();
}
FPToUIInst::FPToUIInst(Value ^S, Type ^Ty)
	: base(new llvm::FPToUIInst(S->base, Ty->base))
	, CastInst(base)
	, constructed(true)
{
}
llvm::FPToUIInst *FPToUIInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::FPToUIInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr));
}
FPToUIInst::FPToUIInst(Value ^S, Type ^Ty, System::String ^NameStr)
	: base(_construct(S, Ty, NameStr))
	, CastInst(base)
	, constructed(true)
{
}
llvm::FPToUIInst *FPToUIInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::FPToUIInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertBefore->base);
}
FPToUIInst::FPToUIInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
	: base(_construct(S, Ty, NameStr, InsertBefore))
	, CastInst(base)
	, constructed(true)
{
}
llvm::FPToUIInst *FPToUIInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::FPToUIInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base);
}
FPToUIInst::FPToUIInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
	: base(_construct(S, Ty, NameStr, InsertAtEnd))
	, CastInst(base)
	, constructed(true)
{
}
inline bool FPToUIInst::classof(Instruction ^I)
{
	return llvm::FPToUIInst::classof(I->base);
}
inline bool FPToUIInst::classof(Value ^V)
{
	return llvm::FPToUIInst::classof(V->base);
}


FPToSIInst::FPToSIInst(llvm::FPToSIInst *base)
	: base(base)
	, CastInst(base)
	, constructed(false)
{
}
FPToSIInst::!FPToSIInst()
{
	if (constructed)
	{
		delete base;
	}
}
FPToSIInst::~FPToSIInst()
{
	this->!FPToSIInst();
}
FPToSIInst::FPToSIInst(Value ^S, Type ^Ty)
	: base(new llvm::FPToSIInst(S->base, Ty->base))
	, CastInst(base)
	, constructed(true)
{
}
llvm::FPToSIInst *FPToSIInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::FPToSIInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr));
}
FPToSIInst::FPToSIInst(Value ^S, Type ^Ty, System::String ^NameStr)
	: base(_construct(S, Ty, NameStr))
	, CastInst(base)
	, constructed(true)
{
}
llvm::FPToSIInst *FPToSIInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::FPToSIInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertBefore->base);
}
FPToSIInst::FPToSIInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
	: base(_construct(S, Ty, NameStr, InsertBefore))
	, CastInst(base)
	, constructed(true)
{
}
llvm::FPToSIInst *FPToSIInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::FPToSIInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base);
}
FPToSIInst::FPToSIInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
	: base(_construct(S, Ty, NameStr, InsertAtEnd))
	, CastInst(base)
	, constructed(true)
{
}
inline bool FPToSIInst::classof(Instruction ^I)
{
	return llvm::FPToSIInst::classof(I->base);
}
inline bool FPToSIInst::classof(Value ^V)
{
	return llvm::FPToSIInst::classof(V->base);
}


IntToPtrInst::IntToPtrInst(llvm::IntToPtrInst *base)
	: base(base)
	, CastInst(base)
	, constructed(false)
{
}
IntToPtrInst::!IntToPtrInst()
{
	if (constructed)
	{
		delete base;
	}
}
IntToPtrInst::~IntToPtrInst()
{
	this->!IntToPtrInst();
}
IntToPtrInst::IntToPtrInst(Value ^S, Type ^Ty)
	: base(new llvm::IntToPtrInst(S->base, Ty->base))
	, CastInst(base)
	, constructed(true)
{
}
llvm::IntToPtrInst *IntToPtrInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::IntToPtrInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr));
}
IntToPtrInst::IntToPtrInst(Value ^S, Type ^Ty, System::String ^NameStr)
	: base(_construct(S, Ty, NameStr))
	, CastInst(base)
	, constructed(true)
{
}
llvm::IntToPtrInst *IntToPtrInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::IntToPtrInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertBefore->base);
}
IntToPtrInst::IntToPtrInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
	: base(_construct(S, Ty, NameStr, InsertBefore))
	, CastInst(base)
	, constructed(true)
{
}
llvm::IntToPtrInst *IntToPtrInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::IntToPtrInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base);
}
IntToPtrInst::IntToPtrInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
	: base(_construct(S, Ty, NameStr, InsertAtEnd))
	, CastInst(base)
	, constructed(true)
{
}
IntToPtrInst ^IntToPtrInst::clone_impl()
{
	return gcnew IntToPtrInst(base->clone_impl());
}
unsigned IntToPtrInst::getAddressSpace()
{
	return base->getAddressSpace();
}
inline bool IntToPtrInst::classof(Instruction ^I)
{
	return llvm::IntToPtrInst::classof(I->base);
}
inline bool IntToPtrInst::classof(Value ^V)
{
	return llvm::IntToPtrInst::classof(V->base);
}


PtrToIntInst::PtrToIntInst(llvm::PtrToIntInst *base)
	: base(base)
	, CastInst(base)
	, constructed(false)
{
}
PtrToIntInst::!PtrToIntInst()
{
	if (constructed)
	{
		delete base;
	}
}
PtrToIntInst::~PtrToIntInst()
{
	this->!PtrToIntInst();
}
PtrToIntInst::PtrToIntInst(Value ^S, Type ^Ty)
	: base(new llvm::PtrToIntInst(S->base, Ty->base))
	, CastInst(base)
	, constructed(true)
{
}
llvm::PtrToIntInst *PtrToIntInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::PtrToIntInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr));
}
PtrToIntInst::PtrToIntInst(Value ^S, Type ^Ty, System::String ^NameStr)
	: base(_construct(S, Ty, NameStr))
	, CastInst(base)
	, constructed(true)
{
}
llvm::PtrToIntInst *PtrToIntInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::PtrToIntInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertBefore->base);
}
PtrToIntInst::PtrToIntInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
	: base(_construct(S, Ty, NameStr, InsertBefore))
	, CastInst(base)
	, constructed(true)
{
}
llvm::PtrToIntInst *PtrToIntInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::PtrToIntInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base);
}
PtrToIntInst::PtrToIntInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
	: base(_construct(S, Ty, NameStr, InsertAtEnd))
	, CastInst(base)
	, constructed(true)
{
}
Value ^PtrToIntInst::getPointerOperand()
{
	return gcnew Value(base->getPointerOperand());
}
unsigned PtrToIntInst::getPointerOperandIndex()
{
	return llvm::PtrToIntInst::getPointerOperandIndex();
}
unsigned PtrToIntInst::getPointerAddressSpace()
{
	return base->getPointerAddressSpace();
}
inline bool PtrToIntInst::classof(Instruction ^I)
{
	return llvm::PtrToIntInst::classof(I->base);
}
inline bool PtrToIntInst::classof(Value ^V)
{
	return llvm::PtrToIntInst::classof(V->base);
}


BitCastInst::BitCastInst(llvm::BitCastInst *base)
	: base(base)
	, CastInst(base)
	, constructed(false)
{
}
BitCastInst::!BitCastInst()
{
	if (constructed)
	{
		delete base;
	}
}
BitCastInst::~BitCastInst()
{
	this->!BitCastInst();
}
BitCastInst::BitCastInst(Value ^S, Type ^Ty)
	: base(new llvm::BitCastInst(S->base, Ty->base))
	, CastInst(base)
	, constructed(true)
{
}
llvm::BitCastInst *BitCastInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr)
{
	msclr::interop::marshal_context ctx;
	return new llvm::BitCastInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr));
}
BitCastInst::BitCastInst(Value ^S, Type ^Ty, System::String ^NameStr)
	: base(_construct(S, Ty, NameStr))
	, CastInst(base)
	, constructed(true)
{
}
llvm::BitCastInst *BitCastInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::BitCastInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertBefore->base);
}
BitCastInst::BitCastInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore)
	: base(_construct(S, Ty, NameStr, InsertBefore))
	, CastInst(base)
	, constructed(true)
{
}
llvm::BitCastInst *BitCastInst::_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return new llvm::BitCastInst(S->base, Ty->base, ctx.marshal_as<const char *>(NameStr), InsertAtEnd->base);
}
BitCastInst::BitCastInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd)
	: base(_construct(S, Ty, NameStr, InsertAtEnd))
	, CastInst(base)
	, constructed(true)
{
}
inline bool BitCastInst::classof(Instruction ^I)
{
	return llvm::BitCastInst::classof(I->base);
}
inline bool BitCastInst::classof(Value ^V)
{
	return llvm::BitCastInst::classof(V->base);
}
