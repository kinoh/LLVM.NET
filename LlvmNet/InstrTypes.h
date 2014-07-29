#pragma once
#using <mscorlib.dll>
#include "llvm/IR/InstrTypes.h"
#include "Instruction.h"

namespace LLVM
{

ref class BasicBlock;
ref class Instruction;
ref class Value;
ref class Type;

public ref class TerminatorInst
	: public Instruction
{
internal:
	llvm::TerminatorInst *base;
	TerminatorInst(llvm::TerminatorInst *base);

public:
	!TerminatorInst();
	virtual ~TerminatorInst();
	unsigned getNumSuccessors();
	BasicBlock ^getSuccessor(unsigned idx);
	void setSuccessor(unsigned idx, BasicBlock ^B);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class UnaryInstruction
	: public Instruction
{
internal:
	llvm::UnaryInstruction *base;
	UnaryInstruction(llvm::UnaryInstruction *base);

public:
	!UnaryInstruction();
	virtual ~UnaryInstruction();
	// void *operator new(size_t s);
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class BinaryOperator
	: public Instruction
{
internal:
	llvm::BinaryOperator *base;
	BinaryOperator(llvm::BinaryOperator *base);

public:
	!BinaryOperator();
	virtual ~BinaryOperator();
	// void *operator new(size_t s);
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	static BinaryOperator ^Create(BinaryOps Op, Value ^S1, Value ^S2);
	static BinaryOperator ^Create(BinaryOps Op, Value ^S1, Value ^S2, System::String ^Name);
	static BinaryOperator ^Create(BinaryOps Op, Value ^S1, Value ^S2, System::String ^Name, Instruction ^InsertBefore);
	static BinaryOperator ^Create(BinaryOps Op, Value ^S1, Value ^S2, System::String ^Name, BasicBlock ^InsertAtEnd);
	//define HANDLE_BINARY_INST(N, OPC, CLASS) \;
	// static BinaryOperator *Create##OPC(Value *V1, Value *V2, \;
	//                                    const Twine &Name = "");
	//include "llvm/IR/Instruction.def";
	//define HANDLE_BINARY_INST(N, OPC, CLASS) \;
	// static BinaryOperator *Create##OPC(Value *V1, Value *V2, \;
	//                                    const Twine &Name, BasicBlock *BB);
	//include "llvm/IR/Instruction.def";
	//define HANDLE_BINARY_INST(N, OPC, CLASS) \;
	// static BinaryOperator *Create##OPC(Value *V1, Value *V2, \;
	//                                    const Twine &Name, Instruction *I);
	//include "llvm/IR/Instruction.def";
	static BinaryOperator ^CreateNSW(BinaryOps Opc, Value ^V1, Value ^V2);
	static BinaryOperator ^CreateNSW(BinaryOps Opc, Value ^V1, Value ^V2, System::String ^Name);
	static BinaryOperator ^CreateNSW(BinaryOps Opc, Value ^V1, Value ^V2, System::String ^Name, BasicBlock ^BB);
	static BinaryOperator ^CreateNSW(BinaryOps Opc, Value ^V1, Value ^V2, System::String ^Name, Instruction ^I);
	static BinaryOperator ^CreateNUW(BinaryOps Opc, Value ^V1, Value ^V2);
	static BinaryOperator ^CreateNUW(BinaryOps Opc, Value ^V1, Value ^V2, System::String ^Name);
	static BinaryOperator ^CreateNUW(BinaryOps Opc, Value ^V1, Value ^V2, System::String ^Name, BasicBlock ^BB);
	static BinaryOperator ^CreateNUW(BinaryOps Opc, Value ^V1, Value ^V2, System::String ^Name, Instruction ^I);
	static BinaryOperator ^CreateExact(BinaryOps Opc, Value ^V1, Value ^V2);
	static BinaryOperator ^CreateExact(BinaryOps Opc, Value ^V1, Value ^V2, System::String ^Name);
	static BinaryOperator ^CreateExact(BinaryOps Opc, Value ^V1, Value ^V2, System::String ^Name, BasicBlock ^BB);
	static BinaryOperator ^CreateExact(BinaryOps Opc, Value ^V1, Value ^V2, System::String ^Name, Instruction ^I);
	//define DEFINE_HELPERS(OPC, NUWNSWEXACT)                                     \;
	// static BinaryOperator *Create ## NUWNSWEXACT ## OPC                        \;
	//          (Value *V1, Value *V2, const Twine &Name = "")                                                                           \;
	// static BinaryOperator *Create ## NUWNSWEXACT ## OPC                        \;
	//          (Value *V1, Value *V2, const Twine &Name, BasicBlock *BB)                                                                           \;
	// static BinaryOperator *Create ## NUWNSWEXACT ## OPC                        \;
	//          (Value *V1, Value *V2, const Twine &Name, Instruction *I);
	// DEFINE_HELPERS(Add, NSW);
	// DEFINE_HELPERS(Add, NUW);
	// DEFINE_HELPERS(Sub, NSW);
	// DEFINE_HELPERS(Sub, NUW);
	// DEFINE_HELPERS(Mul, NSW);
	// DEFINE_HELPERS(Mul, NUW);
	// DEFINE_HELPERS(Shl, NSW);
	// DEFINE_HELPERS(Shl, NUW);
	// DEFINE_HELPERS(SDiv, Exact);
	// DEFINE_HELPERS(UDiv, Exact);
	// DEFINE_HELPERS(AShr, Exact);
	// DEFINE_HELPERS(LShr, Exact);
	//undef DEFINE_HELPERS;
	static BinaryOperator ^CreateNeg(Value ^Op);
	static BinaryOperator ^CreateNeg(Value ^Op, System::String ^Name);
	static BinaryOperator ^CreateNeg(Value ^Op, System::String ^Name, Instruction ^InsertBefore);
	static BinaryOperator ^CreateNeg(Value ^Op, System::String ^Name, BasicBlock ^InsertAtEnd);
	static BinaryOperator ^CreateNSWNeg(Value ^Op);
	static BinaryOperator ^CreateNSWNeg(Value ^Op, System::String ^Name);
	static BinaryOperator ^CreateNSWNeg(Value ^Op, System::String ^Name, Instruction ^InsertBefore);
	static BinaryOperator ^CreateNSWNeg(Value ^Op, System::String ^Name, BasicBlock ^InsertAtEnd);
	static BinaryOperator ^CreateNUWNeg(Value ^Op);
	static BinaryOperator ^CreateNUWNeg(Value ^Op, System::String ^Name);
	static BinaryOperator ^CreateNUWNeg(Value ^Op, System::String ^Name, Instruction ^InsertBefore);
	static BinaryOperator ^CreateNUWNeg(Value ^Op, System::String ^Name, BasicBlock ^InsertAtEnd);
	static BinaryOperator ^CreateFNeg(Value ^Op);
	static BinaryOperator ^CreateFNeg(Value ^Op, System::String ^Name);
	static BinaryOperator ^CreateFNeg(Value ^Op, System::String ^Name, Instruction ^InsertBefore);
	static BinaryOperator ^CreateFNeg(Value ^Op, System::String ^Name, BasicBlock ^InsertAtEnd);
	static BinaryOperator ^CreateNot(Value ^Op);
	static BinaryOperator ^CreateNot(Value ^Op, System::String ^Name);
	static BinaryOperator ^CreateNot(Value ^Op, System::String ^Name, Instruction ^InsertBefore);
	static BinaryOperator ^CreateNot(Value ^Op, System::String ^Name, BasicBlock ^InsertAtEnd);
	static bool isNeg(Value ^V);
	static bool isFNeg(Value ^V);
	static bool isFNeg(Value ^V, bool IgnoreZeroSign);
	static bool isNot(Value ^V);
	// static const Value *getNegArgument(const Value *BinOp);
	// static       Value *getNegArgument(      Value *BinOp);
	// static const Value *getFNegArgument(const Value *BinOp);
	// static       Value *getFNegArgument(      Value *BinOp);
	// static const Value *getNotArgument(const Value *BinOp);
	// static       Value *getNotArgument(      Value *BinOp);
	Instruction::BinaryOps getOpcode();
	bool swapOperands();
	void setHasNoUnsignedWrap();
	void setHasNoUnsignedWrap(bool b);
	void setHasNoSignedWrap();
	void setHasNoSignedWrap(bool b);
	void setIsExact();
	void setIsExact(bool b);
	bool hasNoUnsignedWrap();
	bool hasNoSignedWrap();
	bool isExact();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class CastInst
	: public UnaryInstruction
{
internal:
	llvm::CastInst *base;
	CastInst(llvm::CastInst *base);

public:
	!CastInst();
	virtual ~CastInst();
	static CastInst ^Create(Instruction::CastOps ops, Value ^S, Type ^Ty);
	static CastInst ^Create(Instruction::CastOps ops, Value ^S, Type ^Ty, System::String ^Name);
	static CastInst ^Create(Instruction::CastOps ops, Value ^S, Type ^Ty, System::String ^Name, Instruction ^InsertBefore);
	static CastInst ^Create(Instruction::CastOps ops, Value ^S, Type ^Ty, System::String ^Name, BasicBlock ^InsertAtEnd);
	static CastInst ^CreateZExtOrBitCast(Value ^S, Type ^Ty);
	static CastInst ^CreateZExtOrBitCast(Value ^S, Type ^Ty, System::String ^Name);
	static CastInst ^CreateZExtOrBitCast(Value ^S, Type ^Ty, System::String ^Name, Instruction ^InsertBefore);
	static CastInst ^CreateZExtOrBitCast(Value ^S, Type ^Ty, System::String ^Name, BasicBlock ^InsertAtEnd);
	static CastInst ^CreateSExtOrBitCast(Value ^S, Type ^Ty);
	static CastInst ^CreateSExtOrBitCast(Value ^S, Type ^Ty, System::String ^Name);
	static CastInst ^CreateSExtOrBitCast(Value ^S, Type ^Ty, System::String ^Name, Instruction ^InsertBefore);
	static CastInst ^CreateSExtOrBitCast(Value ^S, Type ^Ty, System::String ^Name, BasicBlock ^InsertAtEnd);
	static CastInst ^CreatePointerCast(Value ^S, Type ^Ty, System::String ^Name, BasicBlock ^InsertAtEnd);
	static CastInst ^CreatePointerCast(Value ^S, Type ^Ty);
	static CastInst ^CreatePointerCast(Value ^S, Type ^Ty, System::String ^Name);
	static CastInst ^CreatePointerCast(Value ^S, Type ^Ty, System::String ^Name, Instruction ^InsertBefore);
	static CastInst ^CreateIntegerCast(Value ^S, Type ^Ty, bool isSigned);
	static CastInst ^CreateIntegerCast(Value ^S, Type ^Ty, bool isSigned, System::String ^Name);
	static CastInst ^CreateIntegerCast(Value ^S, Type ^Ty, bool isSigned, System::String ^Name, Instruction ^InsertBefore);
	static CastInst ^CreateIntegerCast(Value ^S, Type ^Ty, bool isSigned, System::String ^Name, BasicBlock ^InsertAtEnd);
	static CastInst ^CreateFPCast(Value ^S, Type ^Ty);
	static CastInst ^CreateFPCast(Value ^S, Type ^Ty, System::String ^Name);
	static CastInst ^CreateFPCast(Value ^S, Type ^Ty, System::String ^Name, Instruction ^InsertBefore);
	static CastInst ^CreateFPCast(Value ^S, Type ^Ty, System::String ^Name, BasicBlock ^InsertAtEnd);
	static CastInst ^CreateTruncOrBitCast(Value ^S, Type ^Ty);
	static CastInst ^CreateTruncOrBitCast(Value ^S, Type ^Ty, System::String ^Name);
	static CastInst ^CreateTruncOrBitCast(Value ^S, Type ^Ty, System::String ^Name, Instruction ^InsertBefore);
	static CastInst ^CreateTruncOrBitCast(Value ^S, Type ^Ty, System::String ^Name, BasicBlock ^InsertAtEnd);
	static bool isCastable(Type ^SrcTy, Type ^DestTy);
	static Instruction::CastOps getCastOpcode(Value ^Val, bool SrcIsSigned, Type ^Ty, bool DstIsSigned);
	bool isIntegerCast();
	bool isLosslessCast();
	static bool isNoopCast(Instruction::CastOps Opcode, Type ^SrcTy, Type ^DstTy, Type ^IntPtrTy);
	bool isNoopCast(Type ^IntPtrTy);
	static unsigned isEliminableCastPair(Instruction::CastOps firstOpcode, Instruction::CastOps secondOpcode, Type ^SrcTy, Type ^MidTy, Type ^DstTy, Type ^SrcIntPtrTy, Type ^MidIntPtrTy, Type ^DstIntPtrTy);
	Instruction::CastOps getOpcode();
	Type ^getSrcTy();
	Type ^getDestTy();
	static bool castIsValid(Instruction::CastOps op, Value ^S, Type ^DstTy);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class CmpInst
	: public Instruction
{
public:
	enum class Predicate
	{
		FCMP_FALSE =	0,
		FCMP_OEQ	 =	1,
		FCMP_OGT	 =	2,
		FCMP_OGE	 =	3,
		FCMP_OLT	 =	4,
		FCMP_OLE	 =	5,
		FCMP_ONE	 =	6,
		FCMP_ORD	 =	7,
		FCMP_UNO	 =	8,
		FCMP_UEQ	 =	9,
		FCMP_UGT	 = 10,
		FCMP_UGE	 = 11,
		FCMP_ULT	 = 12,
		FCMP_ULE	 = 13,
		FCMP_UNE	 = 14,
		FCMP_TRUE	= 15,
		FIRST_FCMP_PREDICATE = FCMP_FALSE,
		LAST_FCMP_PREDICATE = FCMP_TRUE,
		BAD_FCMP_PREDICATE = FCMP_TRUE + 1,
		ICMP_EQ		= 32,
		ICMP_NE		= 33,
		ICMP_UGT	 = 34,
		ICMP_UGE	 = 35,
		ICMP_ULT	 = 36,
		ICMP_ULE	 = 37,
		ICMP_SGT	 = 38,
		ICMP_SGE	 = 39,
		ICMP_SLT	 = 40,
		ICMP_SLE	 = 41,
		FIRST_ICMP_PREDICATE = ICMP_EQ,
		LAST_ICMP_PREDICATE = ICMP_SLE,
		BAD_ICMP_PREDICATE = ICMP_SLE + 1
	};

internal:
	llvm::CmpInst *base;
	CmpInst(llvm::CmpInst *base);

public:
	!CmpInst();
	virtual ~CmpInst();
	// void *operator new(size_t s);
	static CmpInst ^Create(OtherOps Op, unsigned short predicate, Value ^S1, Value ^S2);
	static CmpInst ^Create(OtherOps Op, unsigned short predicate, Value ^S1, Value ^S2, System::String ^Name);
	static CmpInst ^Create(OtherOps Op, unsigned short predicate, Value ^S1, Value ^S2, System::String ^Name, Instruction ^InsertBefore);
	static CmpInst ^Create(OtherOps Op, unsigned short predicate, Value ^S1, Value ^S2, System::String ^Name, BasicBlock ^InsertAtEnd);
	Instruction::OtherOps getOpcode();
	CmpInst::Predicate getPredicate();
	void setPredicate(Predicate P);
	static bool isFPPredicate(Predicate P);
	static bool isIntPredicate(Predicate P);
	bool isFPPredicate();
	bool isIntPredicate();
	CmpInst::Predicate getInversePredicate();
	static CmpInst::Predicate getInversePredicate(Predicate pred);
	CmpInst::Predicate getSwappedPredicate();
	static CmpInst::Predicate getSwappedPredicate(Predicate pred);
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	void swapOperands();
	bool isCommutative();
	bool isEquality();
	bool isSigned();
	bool isUnsigned();
	bool isTrueWhenEqual();
	bool isFalseWhenEqual();
	static bool isUnsigned(unsigned short predicate);
	static bool isSigned(unsigned short predicate);
	static bool isOrdered(unsigned short predicate);
	static bool isUnordered(unsigned short predicate);
	static bool isTrueWhenEqual(unsigned short predicate);
	static bool isFalseWhenEqual(unsigned short predicate);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
	static Type ^makeCmpResultType(Type ^opnd_type);
};

}
