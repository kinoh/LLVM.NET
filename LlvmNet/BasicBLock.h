#pragma once
#using <mscorlib.dll>
#include "llvm/IR/BasicBLock.h"
#include "Value.h"

namespace LLVM
{

ref class LLVMContext;
ref class Function;
ref class TerminatorInst;
ref class Instruction;
ref class ValueSymbolTable;
ref class Value;
ref class LandingPadInst;

public ref class BasicBlock
	: public Value
{
internal:
	llvm::BasicBlock *base;
	BasicBlock(llvm::BasicBlock *base);

public:
	!BasicBlock();
	virtual ~BasicBlock();
	// typedef iplist<Instruction> InstListType;
	LLVMContext ^getContext();
	// typedef InstListType::iterator iterator;
	// typedef InstListType::const_iterator const_iterator;
	// typedef InstListType::reverse_iterator reverse_iterator;
	// typedef InstListType::const_reverse_iterator const_reverse_iterator;
	static BasicBlock ^Create(LLVMContext ^Context);
	static BasicBlock ^Create(LLVMContext ^Context, System::String ^Name);
	static BasicBlock ^Create(LLVMContext ^Context, System::String ^Name, Function ^Parent);
	static BasicBlock ^Create(LLVMContext ^Context, System::String ^Name, Function ^Parent, BasicBlock ^InsertBefore);
	// ~BasicBlock();
	// const Function *getParent();
	Function ^getParent();
	TerminatorInst ^getTerminator();
	// const TerminatorInst *getTerminator();
	Instruction ^getFirstNonPHI();
	// const Instruction *getFirstNonPHI();
	Instruction ^getFirstNonPHIOrDbg();
	// const Instruction *getFirstNonPHIOrDbg();
	Instruction ^getFirstNonPHIOrDbgOrLifetime();
	// const Instruction *getFirstNonPHIOrDbgOrLifetime();
	// iterator getFirstInsertionPt();
	// const_iterator getFirstInsertionPt();
	void removeFromParent();
	void eraseFromParent();
	void moveBefore(BasicBlock ^MovePos);
	void moveAfter(BasicBlock ^MovePos);
	BasicBlock ^getSinglePredecessor();
	// const BasicBlock *getSinglePredecessor();
	BasicBlock ^getUniquePredecessor();
	// const BasicBlock *getUniquePredecessor();
	// inline iterator                begin();
	// inline const_iterator          begin();
	// inline iterator                end();
	// inline const_iterator          end();
	// inline reverse_iterator        rbegin();
	// inline const_reverse_iterator  rbegin();
	// inline reverse_iterator        rend();
	// inline const_reverse_iterator  rend();
	inline size_t size();
	inline bool empty();
	// inline const Instruction      &front();
	inline Instruction ^front();
	// inline const Instruction       &back();
	inline Instruction ^back();
	// const InstListType &getInstList();
	System::Collections::Generic::List<Instruction ^> ^getInstList();
	// static iplist<Instruction> BasicBlock::*getSublistAccess(Instruction*);
	ValueSymbolTable ^getValueSymbolTable();
	static inline bool classof(Value ^V);
	void dropAllReferences();
	void removePredecessor(BasicBlock ^Pred);
	void removePredecessor(BasicBlock ^Pred, bool DontDeleteUselessPHIs);
	// BasicBlock *splitBasicBlock(iterator I, const Twine &BBName = "");
	bool hasAddressTaken();
	void replaceSuccessorsPhiUsesWith(BasicBlock ^New);
	bool isLandingPad();
	LandingPadInst ^getLandingPadInst();
	// const LandingPadInst *getLandingPadInst();
};

}
