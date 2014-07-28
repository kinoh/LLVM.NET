#pragma once
#using <mscorlib.dll>
#include "llvm/IR/Instructions.h"
#include "InstrTypes.h"
#include "Instruction.h"
#include "CallingConv.h"
#include "Attributes.h"

namespace LLVM
{

ref class Type;
ref class Value;
ref class Instruction;
ref class BasicBlock;
ref class PointerType;
ref class LLVMContext;
ref class SequentialType;
ref class Constant;
ref class Function;
ref class AttributeSet;
ref class Attribute;
ref class VectorType;
ref class Use;
ref class ConstantInt;
ref class LandingPadInst;

enum class AtomicOrdering
{
  NotAtomic = 0,
  Unordered = 1,
  Monotonic = 2,
  Acquire = 4,
  Release = 5,
  AcquireRelease = 6,
  SequentiallyConsistent = 7
};

enum class SynchronizationScope
{
  SingleThread = 0,
  CrossThread = 1
};

public ref class AllocaInst
	: public UnaryInstruction
{
private:
	bool constructed;	static llvm::AllocaInst *_construct(Type ^Ty, Value ^ArraySize, System::String ^Name);
	static llvm::AllocaInst *_construct(Type ^Ty, Value ^ArraySize, System::String ^Name, Instruction ^InsertBefore);
	static llvm::AllocaInst *_construct(Type ^Ty, Value ^ArraySize, System::String ^Name, BasicBlock ^InsertAtEnd);
	static llvm::AllocaInst *_construct(Type ^Ty, System::String ^Name);
	static llvm::AllocaInst *_construct(Type ^Ty, System::String ^Name, Instruction ^InsertBefore);
	static llvm::AllocaInst *_construct(Type ^Ty, System::String ^Name, BasicBlock ^InsertAtEnd);
	static llvm::AllocaInst *_construct(Type ^Ty, Value ^ArraySize, unsigned Align, System::String ^Name);
	static llvm::AllocaInst *_construct(Type ^Ty, Value ^ArraySize, unsigned Align, System::String ^Name, Instruction ^InsertBefore);
	static llvm::AllocaInst *_construct(Type ^Ty, Value ^ArraySize, unsigned Align, System::String ^Name, BasicBlock ^InsertAtEnd);

internal:
	llvm::AllocaInst *base;
	AllocaInst(llvm::AllocaInst *base);

public:
	!AllocaInst();
	virtual ~AllocaInst();
	AllocaInst(Type ^Ty);
	AllocaInst(Type ^Ty, Value ^ArraySize);
	AllocaInst(Type ^Ty, Value ^ArraySize, System::String ^Name);
	AllocaInst(Type ^Ty, Value ^ArraySize, System::String ^Name, Instruction ^InsertBefore);
	AllocaInst(Type ^Ty, Value ^ArraySize, System::String ^Name, BasicBlock ^InsertAtEnd);
	AllocaInst(Type ^Ty, System::String ^Name);
	AllocaInst(Type ^Ty, System::String ^Name, Instruction ^InsertBefore);
	AllocaInst(Type ^Ty, System::String ^Name, BasicBlock ^InsertAtEnd);
	AllocaInst(Type ^Ty, Value ^ArraySize, unsigned Align);
	AllocaInst(Type ^Ty, Value ^ArraySize, unsigned Align, System::String ^Name);
	AllocaInst(Type ^Ty, Value ^ArraySize, unsigned Align, System::String ^Name, Instruction ^InsertBefore);
	AllocaInst(Type ^Ty, Value ^ArraySize, unsigned Align, System::String ^Name, BasicBlock ^InsertAtEnd);
	// virtual ~AllocaInst();
	bool isArrayAllocation();
	// const Value *getArraySize();
	Value ^getArraySize();
	PointerType ^getType();
	Type ^getAllocatedType();
	unsigned getAlignment();
	void setAlignment(unsigned Align);
	bool isStaticAlloca();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class LoadInst
	: public UnaryInstruction
{
private:
	bool constructed;	static llvm::LoadInst *_construct(Value ^Ptr, System::String ^NameStr, Instruction ^InsertBefore);
	static llvm::LoadInst *_construct(Value ^Ptr, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	static llvm::LoadInst *_construct(Value ^Ptr, System::String ^NameStr);
	static llvm::LoadInst *_construct(Value ^Ptr, System::String ^NameStr, bool isVolatile);
	static llvm::LoadInst *_construct(Value ^Ptr, System::String ^NameStr, bool isVolatile, Instruction ^InsertBefore);
	static llvm::LoadInst *_construct(Value ^Ptr, System::String ^NameStr, bool isVolatile, BasicBlock ^InsertAtEnd);
	static llvm::LoadInst *_construct(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align);
	static llvm::LoadInst *_construct(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, Instruction ^InsertBefore);
	static llvm::LoadInst *_construct(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, BasicBlock ^InsertAtEnd);
	static llvm::LoadInst *_construct(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, AtomicOrdering Order);
	static llvm::LoadInst *_construct(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, AtomicOrdering Order, SynchronizationScope SynchScope);
	static llvm::LoadInst *_construct(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, AtomicOrdering Order, SynchronizationScope SynchScope, Instruction ^InsertBefore);
	static llvm::LoadInst *_construct(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, AtomicOrdering Order, SynchronizationScope SynchScope, BasicBlock ^InsertAtEnd);

internal:
	llvm::LoadInst *base;
	LoadInst(llvm::LoadInst *base);

public:
	!LoadInst();
	virtual ~LoadInst();
	LoadInst(Value ^Ptr, System::String ^NameStr, Instruction ^InsertBefore);
	LoadInst(Value ^Ptr, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	LoadInst(Value ^Ptr, System::String ^NameStr);
	LoadInst(Value ^Ptr, System::String ^NameStr, bool isVolatile);
	LoadInst(Value ^Ptr, System::String ^NameStr, bool isVolatile, Instruction ^InsertBefore);
	LoadInst(Value ^Ptr, System::String ^NameStr, bool isVolatile, BasicBlock ^InsertAtEnd);
	LoadInst(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align);
	LoadInst(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, Instruction ^InsertBefore);
	LoadInst(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, BasicBlock ^InsertAtEnd);
	LoadInst(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, AtomicOrdering Order);
	LoadInst(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, AtomicOrdering Order, SynchronizationScope SynchScope);
	LoadInst(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, AtomicOrdering Order, SynchronizationScope SynchScope, Instruction ^InsertBefore);
	LoadInst(Value ^Ptr, System::String ^NameStr, bool isVolatile, unsigned Align, AtomicOrdering Order, SynchronizationScope SynchScope, BasicBlock ^InsertAtEnd);
	LoadInst(Value ^Ptr);
	bool isVolatile();
	void setVolatile(bool V);
	unsigned getAlignment();
	void setAlignment(unsigned Align);
	AtomicOrdering getOrdering();
	void setOrdering(AtomicOrdering Ordering);
	SynchronizationScope getSynchScope();
	void setSynchScope(SynchronizationScope xthread);
	bool isAtomic();
	void setAtomic(AtomicOrdering Ordering);
	void setAtomic(AtomicOrdering Ordering, SynchronizationScope SynchScope);
	bool isSimple();
	bool isUnordered();
	Value ^getPointerOperand();
	// const Value *getPointerOperand();
	static unsigned getPointerOperandIndex();
	unsigned getPointerAddressSpace();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class StoreInst
	: public Instruction
{
private:
	bool constructed;
internal:
	llvm::StoreInst *base;
	StoreInst(llvm::StoreInst *base);

public:
	!StoreInst();
	virtual ~StoreInst();
	// void *operator new(size_t s);
	StoreInst(Value ^Val, Value ^Ptr, Instruction ^InsertBefore);
	StoreInst(Value ^Val, Value ^Ptr, BasicBlock ^InsertAtEnd);
	StoreInst(Value ^Val, Value ^Ptr);
	StoreInst(Value ^Val, Value ^Ptr, bool isVolatile);
	StoreInst(Value ^Val, Value ^Ptr, bool isVolatile, Instruction ^InsertBefore);
	StoreInst(Value ^Val, Value ^Ptr, bool isVolatile, BasicBlock ^InsertAtEnd);
	StoreInst(Value ^Val, Value ^Ptr, bool isVolatile, unsigned Align);
	StoreInst(Value ^Val, Value ^Ptr, bool isVolatile, unsigned Align, Instruction ^InsertBefore);
	StoreInst(Value ^Val, Value ^Ptr, bool isVolatile, unsigned Align, BasicBlock ^InsertAtEnd);
	StoreInst(Value ^Val, Value ^Ptr, bool isVolatile, unsigned Align, AtomicOrdering Order);
	StoreInst(Value ^Val, Value ^Ptr, bool isVolatile, unsigned Align, AtomicOrdering Order, SynchronizationScope SynchScope);
	StoreInst(Value ^Val, Value ^Ptr, bool isVolatile, unsigned Align, AtomicOrdering Order, SynchronizationScope SynchScope, Instruction ^InsertBefore);
	StoreInst(Value ^Val, Value ^Ptr, bool isVolatile, unsigned Align, AtomicOrdering Order, SynchronizationScope SynchScope, BasicBlock ^InsertAtEnd);
	bool isVolatile();
	void setVolatile(bool V);
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	unsigned getAlignment();
	void setAlignment(unsigned Align);
	AtomicOrdering getOrdering();
	void setOrdering(AtomicOrdering Ordering);
	SynchronizationScope getSynchScope();
	void setSynchScope(SynchronizationScope xthread);
	bool isAtomic();
	void setAtomic(AtomicOrdering Ordering);
	void setAtomic(AtomicOrdering Ordering, SynchronizationScope SynchScope);
	bool isSimple();
	bool isUnordered();
	Value ^getValueOperand();
	// const Value *getValueOperand();
	Value ^getPointerOperand();
	// const Value *getPointerOperand();
	static unsigned getPointerOperandIndex();
	unsigned getPointerAddressSpace();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class FenceInst
	: public Instruction
{
private:
	bool constructed;
internal:
	llvm::FenceInst *base;
	FenceInst(llvm::FenceInst *base);

public:
	!FenceInst();
	virtual ~FenceInst();
	// void *operator new(size_t s);
	FenceInst(LLVMContext ^C, AtomicOrdering Ordering);
	FenceInst(LLVMContext ^C, AtomicOrdering Ordering, SynchronizationScope SynchScope);
	FenceInst(LLVMContext ^C, AtomicOrdering Ordering, SynchronizationScope SynchScope, Instruction ^InsertBefore);
	FenceInst(LLVMContext ^C, AtomicOrdering Ordering, SynchronizationScope SynchScope, BasicBlock ^InsertAtEnd);
	AtomicOrdering getOrdering();
	void setOrdering(AtomicOrdering Ordering);
	SynchronizationScope getSynchScope();
	void setSynchScope(SynchronizationScope xthread);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class AtomicCmpXchgInst
	: public Instruction
{
private:
	bool constructed;
internal:
	llvm::AtomicCmpXchgInst *base;
	AtomicCmpXchgInst(llvm::AtomicCmpXchgInst *base);

public:
	!AtomicCmpXchgInst();
	virtual ~AtomicCmpXchgInst();
	// void *operator new(size_t s);
	AtomicCmpXchgInst(Value ^Ptr, Value ^Cmp, Value ^NewVal, AtomicOrdering Ordering, SynchronizationScope SynchScope);
	AtomicCmpXchgInst(Value ^Ptr, Value ^Cmp, Value ^NewVal, AtomicOrdering Ordering, SynchronizationScope SynchScope, Instruction ^InsertBefore);
	AtomicCmpXchgInst(Value ^Ptr, Value ^Cmp, Value ^NewVal, AtomicOrdering Ordering, SynchronizationScope SynchScope, BasicBlock ^InsertAtEnd);
	bool isVolatile();
	void setVolatile(bool V);
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	void setOrdering(AtomicOrdering Ordering);
	void setSynchScope(SynchronizationScope SynchScope);
	AtomicOrdering getOrdering();
	SynchronizationScope getSynchScope();
	Value ^getPointerOperand();
	// const Value *getPointerOperand();
	static unsigned getPointerOperandIndex();
	Value ^getCompareOperand();
	// const Value *getCompareOperand();
	Value ^getNewValOperand();
	// const Value *getNewValOperand();
	unsigned getPointerAddressSpace();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class AtomicRMWInst
	: public Instruction
{
public:
	enum class BinOp
	{
		Xchg,
		Add,
		Sub,
		And,
		Nand,
		Or,
		Xor,
		Max,
		Min,
		UMax,
		UMin,

		FIRST_BINOP = Xchg,
		LAST_BINOP = UMin,
		BAD_BINOP
	};

private:
	bool constructed;
internal:
	llvm::AtomicRMWInst *base;
	AtomicRMWInst(llvm::AtomicRMWInst *base);

public:
	!AtomicRMWInst();
	virtual ~AtomicRMWInst();
	// void *operator new(size_t s);
	AtomicRMWInst(BinOp Operation, Value ^Ptr, Value ^Val, AtomicOrdering Ordering, SynchronizationScope SynchScope);
	AtomicRMWInst(BinOp Operation, Value ^Ptr, Value ^Val, AtomicOrdering Ordering, SynchronizationScope SynchScope, Instruction ^InsertBefore);
	AtomicRMWInst(BinOp Operation, Value ^Ptr, Value ^Val, AtomicOrdering Ordering, SynchronizationScope SynchScope, BasicBlock ^InsertAtEnd);
	AtomicRMWInst::BinOp getOperation();
	void setOperation(BinOp Operation);
	bool isVolatile();
	void setVolatile(bool V);
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	void setOrdering(AtomicOrdering Ordering);
	void setSynchScope(SynchronizationScope SynchScope);
	AtomicOrdering getOrdering();
	SynchronizationScope getSynchScope();
	Value ^getPointerOperand();
	// const Value *getPointerOperand();
	static unsigned getPointerOperandIndex();
	Value ^getValOperand();
	// const Value *getValOperand();
	unsigned getPointerAddressSpace();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class GetElementPtrInst
	: public Instruction
{
internal:
	llvm::GetElementPtrInst *base;
	GetElementPtrInst(llvm::GetElementPtrInst *base);

public:
	!GetElementPtrInst();
	virtual ~GetElementPtrInst();
	static GetElementPtrInst ^Create(Value ^Ptr, array<Value ^> ^IdxList);
	static GetElementPtrInst ^Create(Value ^Ptr, array<Value ^> ^IdxList, System::String ^NameStr);
	static GetElementPtrInst ^Create(Value ^Ptr, array<Value ^> ^IdxList, System::String ^NameStr, Instruction ^InsertBefore);
	static GetElementPtrInst ^Create(Value ^Ptr, array<Value ^> ^IdxList, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	static GetElementPtrInst ^CreateInBounds(Value ^Ptr, array<Value ^> ^IdxList);
	static GetElementPtrInst ^CreateInBounds(Value ^Ptr, array<Value ^> ^IdxList, System::String ^NameStr);
	static GetElementPtrInst ^CreateInBounds(Value ^Ptr, array<Value ^> ^IdxList, System::String ^NameStr, Instruction ^InsertBefore);
	static GetElementPtrInst ^CreateInBounds(Value ^Ptr, array<Value ^> ^IdxList, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	SequentialType ^getType();
	unsigned getAddressSpace();
	static Type ^getIndexedType(Type ^Ptr, array<Value ^> ^IdxList);
	static Type ^getIndexedType(Type ^Ptr, array<Constant ^> ^IdxList);
	static Type ^getIndexedType(Type ^Ptr, array<uint64_t> ^IdxList);
	// inline op_iterator       idx_begin();
	// inline const_op_iterator idx_begin();
	// inline op_iterator       idx_end();
	// inline const_op_iterator idx_end()  ;
	Value ^getPointerOperand();
	// const Value *getPointerOperand();
	static unsigned getPointerOperandIndex();
	Type ^getPointerOperandType();
	unsigned getPointerAddressSpace();
	static Type ^getGEPReturnType(Value ^Ptr, array<Value ^> ^IdxList);
	unsigned getNumIndices();
	bool hasIndices();
	bool hasAllZeroIndices();
	bool hasAllConstantIndices();
	void setIsInBounds();
	void setIsInBounds(bool b);
	bool isInBounds();
	// bool accumulateConstantOffset(const DataLayout &DL, APInt &Offset);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class ICmpInst
	: public CmpInst
{
private:
	bool constructed;	static llvm::ICmpInst *_construct(Instruction ^InsertBefore, Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr);
	static llvm::ICmpInst *_construct(BasicBlock ^InsertAtEnd, Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr);
	static llvm::ICmpInst *_construct(Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr);

internal:
	llvm::ICmpInst *base;
	ICmpInst(llvm::ICmpInst *base);

public:
	!ICmpInst();
	virtual ~ICmpInst();
	ICmpInst(Instruction ^InsertBefore, Predicate pred, Value ^LHS, Value ^RHS);
	ICmpInst(Instruction ^InsertBefore, Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr);
	ICmpInst(BasicBlock ^InsertAtEnd, Predicate pred, Value ^LHS, Value ^RHS);
	ICmpInst(BasicBlock ^InsertAtEnd, Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr);
	ICmpInst(Predicate pred, Value ^LHS, Value ^RHS);
	ICmpInst(Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr);
	CmpInst::Predicate getSignedPredicate();
	static CmpInst::Predicate getSignedPredicate(Predicate pred);
	CmpInst::Predicate getUnsignedPredicate();
	static CmpInst::Predicate getUnsignedPredicate(Predicate pred);
	static bool isEquality(Predicate P);
	bool isEquality();
	bool isCommutative();
	bool isRelational();
	static bool isRelational(Predicate P);
	// static ConstantRange makeConstantRange(Predicate pred, const APInt &C);
	void swapOperands();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class FCmpInst
	: public CmpInst
{
private:
	bool constructed;	static llvm::FCmpInst *_construct(Instruction ^InsertBefore, Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr);
	static llvm::FCmpInst *_construct(BasicBlock ^InsertAtEnd, Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr);
	static llvm::FCmpInst *_construct(Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr);

internal:
	llvm::FCmpInst *base;
	FCmpInst(llvm::FCmpInst *base);

public:
	!FCmpInst();
	virtual ~FCmpInst();
	FCmpInst(Instruction ^InsertBefore, Predicate pred, Value ^LHS, Value ^RHS);
	FCmpInst(Instruction ^InsertBefore, Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr);
	FCmpInst(BasicBlock ^InsertAtEnd, Predicate pred, Value ^LHS, Value ^RHS);
	FCmpInst(BasicBlock ^InsertAtEnd, Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr);
	FCmpInst(Predicate pred, Value ^LHS, Value ^RHS);
	FCmpInst(Predicate pred, Value ^LHS, Value ^RHS, System::String ^NameStr);
	bool isEquality();
	bool isCommutative();
	bool isRelational();
	void swapOperands();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class CallInst
	: public Instruction
{
internal:
	llvm::CallInst *base;
	CallInst(llvm::CallInst *base);

public:
	!CallInst();
	virtual ~CallInst();
	static CallInst ^Create(Value ^Func, array<Value ^> ^Args);
	static CallInst ^Create(Value ^Func, array<Value ^> ^Args, System::String ^NameStr);
	static CallInst ^Create(Value ^Func, array<Value ^> ^Args, System::String ^NameStr, Instruction ^InsertBefore);
	static CallInst ^Create(Value ^Func, array<Value ^> ^Args, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	static CallInst ^Create(Value ^F);
	static CallInst ^Create(Value ^F, System::String ^NameStr);
	static CallInst ^Create(Value ^F, System::String ^NameStr, Instruction ^InsertBefore);
	static CallInst ^Create(Value ^F, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	static Instruction ^CreateMalloc(Instruction ^InsertBefore, Type ^IntPtrTy, Type ^AllocTy, Value ^AllocSize);
	static Instruction ^CreateMalloc(Instruction ^InsertBefore, Type ^IntPtrTy, Type ^AllocTy, Value ^AllocSize, Value ^ArraySize);
	static Instruction ^CreateMalloc(Instruction ^InsertBefore, Type ^IntPtrTy, Type ^AllocTy, Value ^AllocSize, Value ^ArraySize, Function ^MallocF);
	static Instruction ^CreateMalloc(Instruction ^InsertBefore, Type ^IntPtrTy, Type ^AllocTy, Value ^AllocSize, Value ^ArraySize, Function ^MallocF, System::String ^Name);
	static Instruction ^CreateMalloc(BasicBlock ^InsertAtEnd, Type ^IntPtrTy, Type ^AllocTy, Value ^AllocSize);
	static Instruction ^CreateMalloc(BasicBlock ^InsertAtEnd, Type ^IntPtrTy, Type ^AllocTy, Value ^AllocSize, Value ^ArraySize);
	static Instruction ^CreateMalloc(BasicBlock ^InsertAtEnd, Type ^IntPtrTy, Type ^AllocTy, Value ^AllocSize, Value ^ArraySize, Function ^MallocF);
	static Instruction ^CreateMalloc(BasicBlock ^InsertAtEnd, Type ^IntPtrTy, Type ^AllocTy, Value ^AllocSize, Value ^ArraySize, Function ^MallocF, System::String ^Name);
	static Instruction ^CreateFree(Value ^Source, Instruction ^InsertBefore);
	static Instruction ^CreateFree(Value ^Source, BasicBlock ^InsertAtEnd);
	// ~CallInst();
	bool isTailCall();
	void setTailCall();
	void setTailCall(bool isTC);
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	unsigned getNumArgOperands();
	Value ^getArgOperand(unsigned i);
	void setArgOperand(unsigned i, Value ^v);
	CallingConv::ID getCallingConv();
	void setCallingConv(CallingConv::ID CC);
	// const AttributeSet &getAttributes();
	void setAttributes(AttributeSet ^Attrs);
	void addAttribute(unsigned i, Attribute::AttrKind attr);
	void removeAttribute(unsigned i, Attribute ^attr);
	bool hasFnAttr(Attribute::AttrKind A);
	bool paramHasAttr(unsigned i, Attribute::AttrKind A);
	unsigned getParamAlignment(unsigned i);
	bool isNoInline();
	void setIsNoInline();
	bool canReturnTwice();
	void setCanReturnTwice();
	bool doesNotAccessMemory();
	void setDoesNotAccessMemory();
	bool onlyReadsMemory();
	void setOnlyReadsMemory();
	bool doesNotReturn();
	void setDoesNotReturn();
	bool doesNotThrow();
	void setDoesNotThrow();
	bool cannotDuplicate();
	void setCannotDuplicate();
	bool hasStructRetAttr();
	bool hasByValArgument();
	Function ^getCalledFunction();
	// const Value *getCalledValue();
	Value ^getCalledValue();
	void setCalledFunction(Value ^Fn);
	bool isInlineAsm();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class SelectInst
	: public Instruction
{
internal:
	llvm::SelectInst *base;
	SelectInst(llvm::SelectInst *base);

public:
	!SelectInst();
	virtual ~SelectInst();
	static SelectInst ^Create(Value ^C, Value ^S1, Value ^S2);
	static SelectInst ^Create(Value ^C, Value ^S1, Value ^S2, System::String ^NameStr);
	static SelectInst ^Create(Value ^C, Value ^S1, Value ^S2, System::String ^NameStr, Instruction ^InsertBefore);
	static SelectInst ^Create(Value ^C, Value ^S1, Value ^S2, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	// const Value *getCondition();
	// const Value *getTrueValue();
	// const Value *getFalseValue();
	Value ^getCondition();
	Value ^getTrueValue();
	Value ^getFalseValue();
	static System::String ^areInvalidOperands(Value ^Cond, Value ^True, Value ^False);
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	Instruction::OtherOps getOpcode();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class VAArgInst
	: public UnaryInstruction
{
private:
	bool constructed;	static llvm::VAArgInst *_construct(Value ^List, Type ^Ty, System::String ^NameStr);
	static llvm::VAArgInst *_construct(Value ^List, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	static llvm::VAArgInst *_construct(Value ^List, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);

internal:
	llvm::VAArgInst *base;
	VAArgInst(llvm::VAArgInst *base);

public:
	!VAArgInst();
	virtual ~VAArgInst();
	VAArgInst(Value ^List, Type ^Ty);
	VAArgInst(Value ^List, Type ^Ty, System::String ^NameStr);
	VAArgInst(Value ^List, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	//   : UnaryInstruction(Ty, VAArg, List, InsertBefore);
	VAArgInst(Value ^List, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	//   : UnaryInstruction(Ty, VAArg, List, InsertAtEnd);
	Value ^getPointerOperand();
	// const Value *getPointerOperand();
	static unsigned getPointerOperandIndex();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class ExtractElementInst
	: public Instruction
{
internal:
	llvm::ExtractElementInst *base;
	ExtractElementInst(llvm::ExtractElementInst *base);

public:
	!ExtractElementInst();
	virtual ~ExtractElementInst();
	static ExtractElementInst ^Create(Value ^Vec, Value ^Idx);
	static ExtractElementInst ^Create(Value ^Vec, Value ^Idx, System::String ^NameStr);
	static ExtractElementInst ^Create(Value ^Vec, Value ^Idx, System::String ^NameStr, Instruction ^InsertBefore);
	static ExtractElementInst ^Create(Value ^Vec, Value ^Idx, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	static bool isValidOperands(Value ^Vec, Value ^Idx);
	Value ^getVectorOperand();
	Value ^getIndexOperand();
	// const Value *getVectorOperand();
	// const Value *getIndexOperand();
	VectorType ^getVectorOperandType();
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class InsertElementInst
	: public Instruction
{
internal:
	llvm::InsertElementInst *base;
	InsertElementInst(llvm::InsertElementInst *base);

public:
	!InsertElementInst();
	virtual ~InsertElementInst();
	static InsertElementInst ^Create(Value ^Vec, Value ^NewElt, Value ^Idx);
	static InsertElementInst ^Create(Value ^Vec, Value ^NewElt, Value ^Idx, System::String ^NameStr);
	static InsertElementInst ^Create(Value ^Vec, Value ^NewElt, Value ^Idx, System::String ^NameStr, Instruction ^InsertBefore);
	static InsertElementInst ^Create(Value ^Vec, Value ^NewElt, Value ^Idx, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	static bool isValidOperands(Value ^Vec, Value ^NewElt, Value ^Idx);
	VectorType ^getType();
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class ShuffleVectorInst
	: public Instruction
{
private:
	bool constructed;	static llvm::ShuffleVectorInst *_construct(Value ^V1, Value ^V2, Value ^Mask, System::String ^NameStr);
	static llvm::ShuffleVectorInst *_construct(Value ^V1, Value ^V2, Value ^Mask, System::String ^NameStr, Instruction ^InsertBefor);
	static llvm::ShuffleVectorInst *_construct(Value ^V1, Value ^V2, Value ^Mask, System::String ^NameStr, BasicBlock ^InsertAtEnd);

internal:
	llvm::ShuffleVectorInst *base;
	ShuffleVectorInst(llvm::ShuffleVectorInst *base);

public:
	!ShuffleVectorInst();
	virtual ~ShuffleVectorInst();
	// void *operator new(size_t s);
	ShuffleVectorInst(Value ^V1, Value ^V2, Value ^Mask);
	ShuffleVectorInst(Value ^V1, Value ^V2, Value ^Mask, System::String ^NameStr);
	ShuffleVectorInst(Value ^V1, Value ^V2, Value ^Mask, System::String ^NameStr, Instruction ^InsertBefor);
	ShuffleVectorInst(Value ^V1, Value ^V2, Value ^Mask, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	static bool isValidOperands(Value ^V1, Value ^V2, Value ^Mask);
	VectorType ^getType();
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	Constant ^getMask();
	static int getMaskValue(Constant ^Mask, unsigned i);
	int getMaskValue(unsigned i);
	static array<int> ^getShuffleMaskArray(Constant ^Mask);
	array<int> ^getShuffleMaskArray();
	// SmallVector<int, 16> getShuffleMask();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class ExtractValueInst
	: public UnaryInstruction
{
internal:
	llvm::ExtractValueInst *base;
	ExtractValueInst(llvm::ExtractValueInst *base);

public:
	!ExtractValueInst();
	virtual ~ExtractValueInst();
	static ExtractValueInst ^Create(Value ^Agg, array<unsigned> ^Idxs);
	static ExtractValueInst ^Create(Value ^Agg, array<unsigned> ^Idxs, System::String ^NameStr);
	static ExtractValueInst ^Create(Value ^Agg, array<unsigned> ^Idxs, System::String ^NameStr, Instruction ^InsertBefore);
	static ExtractValueInst ^Create(Value ^Agg, array<unsigned> ^Idxs, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	static Type ^getIndexedType(Type ^Agg, array<unsigned> ^Idxs);
	// typedef const unsigned *idx_iterator;
	// inline idx_iterator idx_begin();
	// inline idx_iterator idx_end()  ;
	Value ^getAggregateOperand();
	// const Value *getAggregateOperand();
	static unsigned getAggregateOperandIndex();
	array<unsigned> ^getIndices();
	unsigned getNumIndices();
	bool hasIndices();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class InsertValueInst
	: public Instruction
{
internal:
	llvm::InsertValueInst *base;
	InsertValueInst(llvm::InsertValueInst *base);

public:
	!InsertValueInst();
	virtual ~InsertValueInst();
	// void *operator new(size_t s);
	static InsertValueInst ^Create(Value ^Agg, Value ^Val, array<unsigned> ^Idxs);
	static InsertValueInst ^Create(Value ^Agg, Value ^Val, array<unsigned> ^Idxs, System::String ^NameStr);
	static InsertValueInst ^Create(Value ^Agg, Value ^Val, array<unsigned> ^Idxs, System::String ^NameStr, Instruction ^InsertBefore);
	static InsertValueInst ^Create(Value ^Agg, Value ^Val, array<unsigned> ^Idxs, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	// typedef const unsigned *idx_iterator;
	// inline idx_iterator idx_begin();
	// inline idx_iterator idx_end()  ;
	Value ^getAggregateOperand();
	// const Value *getAggregateOperand();
	static unsigned getAggregateOperandIndex();
	Value ^getInsertedValueOperand();
	// const Value *getInsertedValueOperand();
	static unsigned getInsertedValueOperandIndex();
	array<unsigned> ^getIndices();
	unsigned getNumIndices();
	bool hasIndices();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class PHINode
	: public Instruction
{
internal:
	llvm::PHINode *base;
	PHINode(llvm::PHINode *base);

public:
	!PHINode();
	virtual ~PHINode();
	static PHINode ^Create(Type ^Ty, unsigned NumReservedValues);
	static PHINode ^Create(Type ^Ty, unsigned NumReservedValues, System::String ^NameStr);
	static PHINode ^Create(Type ^Ty, unsigned NumReservedValues, System::String ^NameStr, Instruction ^InsertBefore);
	static PHINode ^Create(Type ^Ty, unsigned NumReservedValues, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	// ~PHINode();
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	// typedef BasicBlock **block_iterator;
	// typedef BasicBlock  *const *const_block_iterator;
	// block_iterator block_begin();
	// const_block_iterator block_begin();
	// block_iterator block_end();
	// const_block_iterator block_end();
	unsigned getNumIncomingValues();
	Value ^getIncomingValue(unsigned i);
	void setIncomingValue(unsigned i, Value ^V);
	static unsigned getOperandNumForIncomingValue(unsigned i);
	static unsigned getIncomingValueNumForOperand(unsigned i);
	BasicBlock ^getIncomingBlock(unsigned i);
	BasicBlock ^getIncomingBlock(Use ^U);
	// template <typename U>;
	// BasicBlock *getIncomingBlock(value_use_iterator<U> I);
	void setIncomingBlock(unsigned i, BasicBlock ^BB);
	void addIncoming(Value ^V, BasicBlock ^BB);
	Value ^removeIncomingValue(unsigned Idx);
	Value ^removeIncomingValue(unsigned Idx, bool DeletePHIIfEmpty);
	Value ^removeIncomingValue(BasicBlock ^BB);
	Value ^removeIncomingValue(BasicBlock ^BB, bool DeletePHIIfEmpty);
	int getBasicBlockIndex(BasicBlock ^BB);
	Value ^getIncomingValueForBlock(BasicBlock ^BB);
	Value ^hasConstantValue();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class LandingPadInst
	: public Instruction
{
public:
	enum class ClauseType
	{ Catch, Filter };

internal:
	llvm::LandingPadInst *base;
	LandingPadInst(llvm::LandingPadInst *base);

public:
	!LandingPadInst();
	virtual ~LandingPadInst();
	static LandingPadInst ^Create(Type ^RetTy, Value ^PersonalityFn, unsigned NumReservedClauses);
	static LandingPadInst ^Create(Type ^RetTy, Value ^PersonalityFn, unsigned NumReservedClauses, System::String ^NameStr);
	static LandingPadInst ^Create(Type ^RetTy, Value ^PersonalityFn, unsigned NumReservedClauses, System::String ^NameStr, Instruction ^InsertBefore);
	static LandingPadInst ^Create(Type ^RetTy, Value ^PersonalityFn, unsigned NumReservedClauses, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	// ~LandingPadInst();
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	Value ^getPersonalityFn();
	bool isCleanup();
	void setCleanup(bool V);
	void addClause(Value ^ClauseVal);
	Value ^getClause(unsigned Idx);
	bool isCatch(unsigned Idx);
	bool isFilter(unsigned Idx);
	unsigned getNumClauses();
	void reserveClauses(unsigned Size);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class ReturnInst
	: public TerminatorInst
{
internal:
	llvm::ReturnInst *base;
	ReturnInst(llvm::ReturnInst *base);

public:
	!ReturnInst();
	virtual ~ReturnInst();
	static ReturnInst ^Create(LLVMContext ^C);
	static ReturnInst ^Create(LLVMContext ^C, Value ^retVal);
	static ReturnInst ^Create(LLVMContext ^C, Value ^retVal, Instruction ^InsertBefore);
	static ReturnInst ^Create(LLVMContext ^C, Value ^retVal, BasicBlock ^InsertAtEnd);
	static ReturnInst ^Create(LLVMContext ^C, BasicBlock ^InsertAtEnd);
	// virtual ~ReturnInst();
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	Value ^getReturnValue();
	unsigned getNumSuccessors();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class BranchInst
	: public TerminatorInst
{
internal:
	llvm::BranchInst *base;
	BranchInst(llvm::BranchInst *base);

public:
	!BranchInst();
	virtual ~BranchInst();
	static BranchInst ^Create(BasicBlock ^IfTrue);
	static BranchInst ^Create(BasicBlock ^IfTrue, Instruction ^InsertBefore);
	static BranchInst ^Create(BasicBlock ^IfTrue, BasicBlock ^IfFalse, Value ^Cond);
	static BranchInst ^Create(BasicBlock ^IfTrue, BasicBlock ^IfFalse, Value ^Cond, Instruction ^InsertBefore);
	static BranchInst ^Create(BasicBlock ^IfTrue, BasicBlock ^InsertAtEnd);
	static BranchInst ^Create(BasicBlock ^IfTrue, BasicBlock ^IfFalse, Value ^Cond, BasicBlock ^InsertAtEnd);
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	bool isUnconditional();
	bool isConditional();
	Value ^getCondition();
	void setCondition(Value ^V);
	unsigned getNumSuccessors();
	BasicBlock ^getSuccessor(unsigned i);
	void setSuccessor(unsigned idx, BasicBlock ^NewSucc);
	void swapSuccessors();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class SwitchInst
	: public TerminatorInst
{
internal:
	llvm::SwitchInst *base;
	SwitchInst(llvm::SwitchInst *base);

public:
	!SwitchInst();
	virtual ~SwitchInst();
	// template <class SwitchInstTy, class ConstantIntTy, class SubsetsItTy, class BasicBlockTy>;
	//   class CaseIteratorT;
	// typedef CaseIteratorT<const SwitchInst, const ConstantInt, SubsetsConstIt, const BasicBlock> ConstCaseIt;
	// class CaseIt;
	// static const unsigned DefaultPseudoIndex = static_cast<unsigned>(~0L-1);
	static SwitchInst ^Create(Value ^Value, BasicBlock ^Default, unsigned NumCases);
	static SwitchInst ^Create(Value ^Value, BasicBlock ^Default, unsigned NumCases, Instruction ^InsertBefore);
	static SwitchInst ^Create(Value ^Value, BasicBlock ^Default, unsigned NumCases, BasicBlock ^InsertAtEnd);
	// ~SwitchInst();
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	Value ^getCondition();
	void setCondition(Value ^V);
	BasicBlock ^getDefaultDest();
	void setDefaultDest(BasicBlock ^DefaultCase);
	unsigned getNumCases();
	// CaseIt case_begin();
	// ConstCaseIt case_begin();
	// CaseIt case_end();
	// ConstCaseIt case_end();
	// CaseIt case_default();
	// ConstCaseIt case_default();
	// CaseIt findCaseValue(const ConstantInt *C);
	// ConstCaseIt findCaseValue(const ConstantInt *C);
	ConstantInt ^findCaseDest(BasicBlock ^BB);
	void addCase(ConstantInt ^OnVal, BasicBlock ^Dest);
	// void addCase(IntegersSubset &OnVal, BasicBlock *Dest);
	// void removeCase(CaseIt &i);
	unsigned getNumSuccessors();
	BasicBlock ^getSuccessor(unsigned idx);
	void setSuccessor(unsigned idx, BasicBlock ^NewSucc);
	uint16_t hash();
	// template <class SwitchInstTy, class ConstantIntTy, class SubsetsItTy, class BasicBlockTy>;
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class IndirectBrInst
	: public TerminatorInst
{
internal:
	llvm::IndirectBrInst *base;
	IndirectBrInst(llvm::IndirectBrInst *base);

public:
	!IndirectBrInst();
	virtual ~IndirectBrInst();
	static IndirectBrInst ^Create(Value ^Address, unsigned NumDests);
	static IndirectBrInst ^Create(Value ^Address, unsigned NumDests, Instruction ^InsertBefore);
	static IndirectBrInst ^Create(Value ^Address, unsigned NumDests, BasicBlock ^InsertAtEnd);
	// ~IndirectBrInst();
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	Value ^getAddress();
	// const Value *getAddress();
	void setAddress(Value ^V);
	unsigned getNumDestinations();
	BasicBlock ^getDestination(unsigned i);
	// const BasicBlock *getDestination(unsigned i);
	void addDestination(BasicBlock ^Dest);
	void removeDestination(unsigned i);
	unsigned getNumSuccessors();
	BasicBlock ^getSuccessor(unsigned i);
	void setSuccessor(unsigned i, BasicBlock ^NewSucc);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class InvokeInst
	: public TerminatorInst
{
internal:
	llvm::InvokeInst *base;
	InvokeInst(llvm::InvokeInst *base);

public:
	!InvokeInst();
	virtual ~InvokeInst();
	static InvokeInst ^Create(Value ^Func, BasicBlock ^IfNormal, BasicBlock ^IfException, array<Value ^> ^Args);
	static InvokeInst ^Create(Value ^Func, BasicBlock ^IfNormal, BasicBlock ^IfException, array<Value ^> ^Args, System::String ^NameStr);
	static InvokeInst ^Create(Value ^Func, BasicBlock ^IfNormal, BasicBlock ^IfException, array<Value ^> ^Args, System::String ^NameStr, Instruction ^InsertBefore);
	static InvokeInst ^Create(Value ^Func, BasicBlock ^IfNormal, BasicBlock ^IfException, array<Value ^> ^Args, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	unsigned getNumArgOperands();
	Value ^getArgOperand(unsigned i);
	void setArgOperand(unsigned i, Value ^v);
	CallingConv::ID getCallingConv();
	void setCallingConv(CallingConv::ID CC);
	// const AttributeSet &getAttributes();
	void setAttributes(AttributeSet ^Attrs);
	void addAttribute(unsigned i, Attribute::AttrKind attr);
	void removeAttribute(unsigned i, Attribute ^attr);
	bool hasFnAttr(Attribute::AttrKind A);
	bool paramHasAttr(unsigned i, Attribute::AttrKind A);
	unsigned getParamAlignment(unsigned i);
	bool isNoInline();
	void setIsNoInline();
	bool doesNotAccessMemory();
	void setDoesNotAccessMemory();
	bool onlyReadsMemory();
	void setOnlyReadsMemory();
	bool doesNotReturn();
	void setDoesNotReturn();
	bool doesNotThrow();
	void setDoesNotThrow();
	bool hasStructRetAttr();
	bool hasByValArgument();
	Function ^getCalledFunction();
	// const Value *getCalledValue();
	Value ^getCalledValue();
	void setCalledFunction(Value ^Fn);
	BasicBlock ^getNormalDest();
	BasicBlock ^getUnwindDest();
	void setNormalDest(BasicBlock ^B);
	void setUnwindDest(BasicBlock ^B);
	LandingPadInst ^getLandingPadInst();
	BasicBlock ^getSuccessor(unsigned i);
	void setSuccessor(unsigned idx, BasicBlock ^NewSucc);
	unsigned getNumSuccessors();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class ResumeInst
	: public TerminatorInst
{
internal:
	llvm::ResumeInst *base;
	ResumeInst(llvm::ResumeInst *base);

public:
	!ResumeInst();
	virtual ~ResumeInst();
	static ResumeInst ^Create(Value ^Exn);
	static ResumeInst ^Create(Value ^Exn, Instruction ^InsertBefore);
	static ResumeInst ^Create(Value ^Exn, BasicBlock ^InsertAtEnd);
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	Value ^getValue();
	unsigned getNumSuccessors();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class UnreachableInst
	: public TerminatorInst
{
private:
	bool constructed;
internal:
	llvm::UnreachableInst *base;
	UnreachableInst(llvm::UnreachableInst *base);

public:
	!UnreachableInst();
	virtual ~UnreachableInst();
	// void *operator new(size_t s);
	UnreachableInst(LLVMContext ^C);
	UnreachableInst(LLVMContext ^C, Instruction ^InsertBefore);
	UnreachableInst(LLVMContext ^C, BasicBlock ^InsertAtEnd);
	unsigned getNumSuccessors();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class TruncInst
	: public CastInst
{
private:
	bool constructed;	static llvm::TruncInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr);
	static llvm::TruncInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	static llvm::TruncInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);

internal:
	llvm::TruncInst *base;
	TruncInst(llvm::TruncInst *base);

public:
	!TruncInst();
	virtual ~TruncInst();
	TruncInst(Value ^S, Type ^Ty);
	TruncInst(Value ^S, Type ^Ty, System::String ^NameStr);
	TruncInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	TruncInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class ZExtInst
	: public CastInst
{
private:
	bool constructed;	static llvm::ZExtInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr);
	static llvm::ZExtInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	static llvm::ZExtInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);

internal:
	llvm::ZExtInst *base;
	ZExtInst(llvm::ZExtInst *base);

public:
	!ZExtInst();
	virtual ~ZExtInst();
	ZExtInst(Value ^S, Type ^Ty);
	ZExtInst(Value ^S, Type ^Ty, System::String ^NameStr);
	ZExtInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	ZExtInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class SExtInst
	: public CastInst
{
private:
	bool constructed;	static llvm::SExtInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr);
	static llvm::SExtInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	static llvm::SExtInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);

internal:
	llvm::SExtInst *base;
	SExtInst(llvm::SExtInst *base);

public:
	!SExtInst();
	virtual ~SExtInst();
	SExtInst(Value ^S, Type ^Ty);
	SExtInst(Value ^S, Type ^Ty, System::String ^NameStr);
	SExtInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	SExtInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class FPTruncInst
	: public CastInst
{
private:
	bool constructed;	static llvm::FPTruncInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr);
	static llvm::FPTruncInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	static llvm::FPTruncInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);

internal:
	llvm::FPTruncInst *base;
	FPTruncInst(llvm::FPTruncInst *base);

public:
	!FPTruncInst();
	virtual ~FPTruncInst();
	FPTruncInst(Value ^S, Type ^Ty);
	FPTruncInst(Value ^S, Type ^Ty, System::String ^NameStr);
	FPTruncInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	FPTruncInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class FPExtInst
	: public CastInst
{
private:
	bool constructed;	static llvm::FPExtInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr);
	static llvm::FPExtInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	static llvm::FPExtInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);

internal:
	llvm::FPExtInst *base;
	FPExtInst(llvm::FPExtInst *base);

public:
	!FPExtInst();
	virtual ~FPExtInst();
	FPExtInst(Value ^S, Type ^Ty);
	FPExtInst(Value ^S, Type ^Ty, System::String ^NameStr);
	FPExtInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	FPExtInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class UIToFPInst
	: public CastInst
{
private:
	bool constructed;	static llvm::UIToFPInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr);
	static llvm::UIToFPInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	static llvm::UIToFPInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);

internal:
	llvm::UIToFPInst *base;
	UIToFPInst(llvm::UIToFPInst *base);

public:
	!UIToFPInst();
	virtual ~UIToFPInst();
	UIToFPInst(Value ^S, Type ^Ty);
	UIToFPInst(Value ^S, Type ^Ty, System::String ^NameStr);
	UIToFPInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	UIToFPInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class SIToFPInst
	: public CastInst
{
private:
	bool constructed;	static llvm::SIToFPInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr);
	static llvm::SIToFPInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	static llvm::SIToFPInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);

internal:
	llvm::SIToFPInst *base;
	SIToFPInst(llvm::SIToFPInst *base);

public:
	!SIToFPInst();
	virtual ~SIToFPInst();
	SIToFPInst(Value ^S, Type ^Ty);
	SIToFPInst(Value ^S, Type ^Ty, System::String ^NameStr);
	SIToFPInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	SIToFPInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class FPToUIInst
	: public CastInst
{
private:
	bool constructed;	static llvm::FPToUIInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr);
	static llvm::FPToUIInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	static llvm::FPToUIInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);

internal:
	llvm::FPToUIInst *base;
	FPToUIInst(llvm::FPToUIInst *base);

public:
	!FPToUIInst();
	virtual ~FPToUIInst();
	FPToUIInst(Value ^S, Type ^Ty);
	FPToUIInst(Value ^S, Type ^Ty, System::String ^NameStr);
	FPToUIInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	FPToUIInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class FPToSIInst
	: public CastInst
{
private:
	bool constructed;	static llvm::FPToSIInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr);
	static llvm::FPToSIInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	static llvm::FPToSIInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);

internal:
	llvm::FPToSIInst *base;
	FPToSIInst(llvm::FPToSIInst *base);

public:
	!FPToSIInst();
	virtual ~FPToSIInst();
	FPToSIInst(Value ^S, Type ^Ty);
	FPToSIInst(Value ^S, Type ^Ty, System::String ^NameStr);
	FPToSIInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	FPToSIInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class IntToPtrInst
	: public CastInst
{
private:
	bool constructed;	static llvm::IntToPtrInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr);
	static llvm::IntToPtrInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	static llvm::IntToPtrInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);

internal:
	llvm::IntToPtrInst *base;
	IntToPtrInst(llvm::IntToPtrInst *base);

public:
	!IntToPtrInst();
	virtual ~IntToPtrInst();
	IntToPtrInst(Value ^S, Type ^Ty);
	IntToPtrInst(Value ^S, Type ^Ty, System::String ^NameStr);
	IntToPtrInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	IntToPtrInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	virtual IntToPtrInst ^clone_impl();
	unsigned getAddressSpace();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class PtrToIntInst
	: public CastInst
{
private:
	bool constructed;	static llvm::PtrToIntInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr);
	static llvm::PtrToIntInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	static llvm::PtrToIntInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);

internal:
	llvm::PtrToIntInst *base;
	PtrToIntInst(llvm::PtrToIntInst *base);

public:
	!PtrToIntInst();
	virtual ~PtrToIntInst();
	PtrToIntInst(Value ^S, Type ^Ty);
	PtrToIntInst(Value ^S, Type ^Ty, System::String ^NameStr);
	PtrToIntInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	PtrToIntInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	Value ^getPointerOperand();
	// const Value *getPointerOperand();
	static unsigned getPointerOperandIndex();
	unsigned getPointerAddressSpace();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class BitCastInst
	: public CastInst
{
private:
	bool constructed;	static llvm::BitCastInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr);
	static llvm::BitCastInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	static llvm::BitCastInst *_construct(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);

internal:
	llvm::BitCastInst *base;
	BitCastInst(llvm::BitCastInst *base);

public:
	!BitCastInst();
	virtual ~BitCastInst();
	BitCastInst(Value ^S, Type ^Ty);
	BitCastInst(Value ^S, Type ^Ty, System::String ^NameStr);
	BitCastInst(Value ^S, Type ^Ty, System::String ^NameStr, Instruction ^InsertBefore);
	BitCastInst(Value ^S, Type ^Ty, System::String ^NameStr, BasicBlock ^InsertAtEnd);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};

}
