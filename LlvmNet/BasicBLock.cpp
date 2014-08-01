#include "BasicBLock.h"
#include "llvm/ADT/Twine.h"
#include "llvm/ADT/ilist.h"
#include "LLVMContext.h"
#include "Function.h"
#include "InstrTypes.h"
#include "Instruction.h"
#include "ValueSymbolTable.h"
#include "Value.h"
#include "Instructions.h"
#include <msclr/marshal.h>

using namespace LLVM;

BasicBlock::BasicBlock(llvm::BasicBlock *base)
	: base(base)
	, Value(base)
{
}
inline BasicBlock ^BasicBlock::_wrap(llvm::BasicBlock *base)
{
	return base ? gcnew BasicBlock(base) : nullptr;
}
BasicBlock::!BasicBlock()
{
}
BasicBlock::~BasicBlock()
{
	this->!BasicBlock();
}
LLVMContext ^BasicBlock::getContext()
{
	return LLVMContext::_wrap(&base->getContext());
}
BasicBlock ^BasicBlock::Create(LLVMContext ^Context)
{
	return BasicBlock::_wrap(llvm::BasicBlock::Create(*Context->base));
}
BasicBlock ^BasicBlock::Create(LLVMContext ^Context, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return BasicBlock::_wrap(llvm::BasicBlock::Create(*Context->base, ctx.marshal_as<const char *>(Name)));
}
BasicBlock ^BasicBlock::Create(LLVMContext ^Context, System::String ^Name, Function ^Parent)
{
	msclr::interop::marshal_context ctx;
	return BasicBlock::_wrap(llvm::BasicBlock::Create(*Context->base, ctx.marshal_as<const char *>(Name), Parent->base));
}
BasicBlock ^BasicBlock::Create(LLVMContext ^Context, System::String ^Name, Function ^Parent, BasicBlock ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return BasicBlock::_wrap(llvm::BasicBlock::Create(*Context->base, ctx.marshal_as<const char *>(Name), Parent->base, InsertBefore->base));
}
Function ^BasicBlock::getParent()
{
	return Function::_wrap(base->getParent());
}
TerminatorInst ^BasicBlock::getTerminator()
{
	return TerminatorInst::_wrap(base->getTerminator());
}
Instruction ^BasicBlock::getFirstNonPHI()
{
	return Instruction::_wrap(base->getFirstNonPHI());
}
Instruction ^BasicBlock::getFirstNonPHIOrDbg()
{
	return Instruction::_wrap(base->getFirstNonPHIOrDbg());
}
Instruction ^BasicBlock::getFirstNonPHIOrDbgOrLifetime()
{
	return Instruction::_wrap(base->getFirstNonPHIOrDbgOrLifetime());
}
void BasicBlock::removeFromParent()
{
	base->removeFromParent();
}
void BasicBlock::eraseFromParent()
{
	base->eraseFromParent();
}
void BasicBlock::moveBefore(BasicBlock ^MovePos)
{
	base->moveBefore(MovePos->base);
}
void BasicBlock::moveAfter(BasicBlock ^MovePos)
{
	base->moveAfter(MovePos->base);
}
BasicBlock ^BasicBlock::getSinglePredecessor()
{
	return BasicBlock::_wrap(base->getSinglePredecessor());
}
BasicBlock ^BasicBlock::getUniquePredecessor()
{
	return BasicBlock::_wrap(base->getUniquePredecessor());
}
inline size_t BasicBlock::size()
{
	return base->size();
}
inline bool BasicBlock::empty()
{
	return base->empty();
}
inline Instruction ^BasicBlock::front()
{
	return Instruction::_wrap(&base->front());
}
inline Instruction ^BasicBlock::back()
{
	return Instruction::_wrap(&base->back());
}
System::Collections::Generic::List<Instruction ^> ^BasicBlock::getInstList()
{
	auto r = &base->getInstList();
	auto s = gcnew System::Collections::Generic::List<Instruction ^>(r->size());
	for (auto it = r->begin(); it != r->end(); ++it)
		s->Add(Instruction::_wrap(it));
	return s;
}
ValueSymbolTable ^BasicBlock::getValueSymbolTable()
{
	return ValueSymbolTable::_wrap(base->getValueSymbolTable());
}
inline bool BasicBlock::classof(Value ^V)
{
	return llvm::BasicBlock::classof(V->base);
}
void BasicBlock::dropAllReferences()
{
	base->dropAllReferences();
}
void BasicBlock::removePredecessor(BasicBlock ^Pred)
{
	base->removePredecessor(Pred->base);
}
void BasicBlock::removePredecessor(BasicBlock ^Pred, bool DontDeleteUselessPHIs)
{
	base->removePredecessor(Pred->base, DontDeleteUselessPHIs);
}
bool BasicBlock::hasAddressTaken()
{
	return base->hasAddressTaken();
}
void BasicBlock::replaceSuccessorsPhiUsesWith(BasicBlock ^New)
{
	base->replaceSuccessorsPhiUsesWith(New->base);
}
bool BasicBlock::isLandingPad()
{
	return base->isLandingPad();
}
LandingPadInst ^BasicBlock::getLandingPadInst()
{
	return LandingPadInst::_wrap(base->getLandingPadInst());
}
