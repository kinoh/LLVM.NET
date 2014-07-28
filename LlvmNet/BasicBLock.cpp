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
BasicBlock::!BasicBlock()
{
}
BasicBlock::~BasicBlock()
{
	this->!BasicBlock();
}
LLVMContext ^BasicBlock::getContext()
{
	return gcnew LLVMContext(&base->getContext());
}
BasicBlock ^BasicBlock::Create(LLVMContext ^Context)
{
	return gcnew BasicBlock(llvm::BasicBlock::Create(*Context->base));
}
BasicBlock ^BasicBlock::Create(LLVMContext ^Context, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew BasicBlock(llvm::BasicBlock::Create(*Context->base, ctx.marshal_as<const char *>(Name)));
}
BasicBlock ^BasicBlock::Create(LLVMContext ^Context, System::String ^Name, Function ^Parent)
{
	msclr::interop::marshal_context ctx;
	return gcnew BasicBlock(llvm::BasicBlock::Create(*Context->base, ctx.marshal_as<const char *>(Name), Parent->base));
}
BasicBlock ^BasicBlock::Create(LLVMContext ^Context, System::String ^Name, Function ^Parent, BasicBlock ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew BasicBlock(llvm::BasicBlock::Create(*Context->base, ctx.marshal_as<const char *>(Name), Parent->base, InsertBefore->base));
}
Function ^BasicBlock::getParent()
{
	return gcnew Function(base->getParent());
}
TerminatorInst ^BasicBlock::getTerminator()
{
	return gcnew TerminatorInst(base->getTerminator());
}
Instruction ^BasicBlock::getFirstNonPHI()
{
	return gcnew Instruction(base->getFirstNonPHI());
}
Instruction ^BasicBlock::getFirstNonPHIOrDbg()
{
	return gcnew Instruction(base->getFirstNonPHIOrDbg());
}
Instruction ^BasicBlock::getFirstNonPHIOrDbgOrLifetime()
{
	return gcnew Instruction(base->getFirstNonPHIOrDbgOrLifetime());
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
	return gcnew BasicBlock(base->getSinglePredecessor());
}
BasicBlock ^BasicBlock::getUniquePredecessor()
{
	return gcnew BasicBlock(base->getUniquePredecessor());
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
	return gcnew Instruction(&base->front());
}
inline Instruction ^BasicBlock::back()
{
	return gcnew Instruction(&base->back());
}
System::Collections::Generic::List<Instruction ^> ^BasicBlock::getInstList()
{
	auto r = &base->getInstList();
	auto s = gcnew System::Collections::Generic::List<Instruction ^>(r->size());
	for (auto it = r->begin(); it != r->end(); ++it)
		s->Add(gcnew Instruction(it));
	return s;
}
ValueSymbolTable ^BasicBlock::getValueSymbolTable()
{
	return gcnew ValueSymbolTable(base->getValueSymbolTable());
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
	return gcnew LandingPadInst(base->getLandingPadInst());
}
