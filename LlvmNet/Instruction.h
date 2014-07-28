#pragma once
#using <mscorlib.dll>
#include "llvm/IR/Instruction.h"
#include "User.h"

namespace LLVM
{

ref class BasicBlock;
ref class MDNode;
ref class DebugLoc;
ref class FastMathFlags;
ref class Value;

public ref class Instruction
	: public User
{
public:
	enum class OperationEquivalenceFlags
	{
		CompareIgnoringAlignment = 1<<0,
		CompareUsingScalarTypes = 1<<1
	};
	enum class TermOps
	{
#define	FIRST_TERM_INST(N)						 TermOpsBegin = N,
#define HANDLE_TERM_INST(N, OPC, CLASS) OPC = N,
#define	 LAST_TERM_INST(N)						 TermOpsEnd = N+1
#include "llvm/IR/Instruction.def"
	};
	enum class BinaryOps
	{
#define	FIRST_BINARY_INST(N)						 BinaryOpsBegin = N,
#define HANDLE_BINARY_INST(N, OPC, CLASS) OPC = N,
#define	 LAST_BINARY_INST(N)						 BinaryOpsEnd = N+1
#include "llvm/IR/Instruction.def"
	};
	enum class MemoryOps
	{
#define	FIRST_MEMORY_INST(N)						 MemoryOpsBegin = N,
#define HANDLE_MEMORY_INST(N, OPC, CLASS) OPC = N,
#define	 LAST_MEMORY_INST(N)						 MemoryOpsEnd = N+1
#include "llvm/IR/Instruction.def"
	};
	enum class CastOps
	{
#define	FIRST_CAST_INST(N)						 CastOpsBegin = N,
#define HANDLE_CAST_INST(N, OPC, CLASS) OPC = N,
#define	 LAST_CAST_INST(N)						 CastOpsEnd = N+1
#include "llvm/IR/Instruction.def"
	};
	enum class OtherOps
	{
#define	FIRST_OTHER_INST(N)						 OtherOpsBegin = N,
#define HANDLE_OTHER_INST(N, OPC, CLASS) OPC = N,
#define	 LAST_OTHER_INST(N)						 OtherOpsEnd = N+1
#include "llvm/IR/Instruction.def"
	};

internal:
	llvm::Instruction *base;
	Instruction(llvm::Instruction *base);

public:
	!Instruction();
	virtual ~Instruction();
	// ~Instruction();
	Instruction ^use_back();
	// const Instruction *use_back();
	// inline const BasicBlock *getParent();
	inline BasicBlock ^getParent();
	void removeFromParent();
	void eraseFromParent();
	void insertBefore(Instruction ^InsertPos);
	void insertAfter(Instruction ^InsertPos);
	void moveBefore(Instruction ^MovePos);
	unsigned getOpcode();
	System::String ^getOpcodeName();
	bool isTerminator();
	bool isBinaryOp();
	bool isShift();
	bool isCast();
	static System::String ^getOpcodeName(unsigned OpCode);
	static inline bool isTerminator(unsigned OpCode);
	static inline bool isBinaryOp(unsigned Opcode);
	static inline bool isShift(unsigned Opcode);
	inline bool isLogicalShift();
	inline bool isArithmeticShift();
	static inline bool isCast(unsigned OpCode);
	bool hasMetadata();
	bool hasMetadataOtherThanDebugLoc();
	MDNode ^getMetadata(unsigned KindID);
	MDNode ^getMetadata(System::String ^Kind);
	// void getAllMetadata(SmallVectorImpl<std::pair<unsigned, MDNode*> > &MDs)const;
	// void getAllMetadataOtherThanDebugLoc(SmallVectorImpl<std::pair<unsigned, MDNode*> > &MDs);
	void setMetadata(unsigned KindID, MDNode ^Node);
	void setMetadata(System::String ^Kind, MDNode ^Node);
	void setDebugLoc(DebugLoc ^Loc);
	// const DebugLoc &getDebugLoc();
	void setHasUnsafeAlgebra(bool B);
	void setHasNoNaNs(bool B);
	void setHasNoInfs(bool B);
	void setHasNoSignedZeros(bool B);
	void setHasAllowReciprocal(bool B);
	void setFastMathFlags(FastMathFlags ^FMF);
	bool hasUnsafeAlgebra();
	bool hasNoNaNs();
	bool hasNoInfs();
	bool hasNoSignedZeros();
	bool hasAllowReciprocal();
	FastMathFlags ^getFastMathFlags();
	void copyFastMathFlags(Instruction ^I);
	bool isAssociative();
	static bool isAssociative(unsigned op);
	bool isCommutative();
	static bool isCommutative(unsigned op);
	bool isIdempotent();
	static bool isIdempotent(unsigned op);
	bool isNilpotent();
	static bool isNilpotent(unsigned op);
	bool mayWriteToMemory();
	bool mayReadFromMemory();
	bool mayReadOrWriteMemory();
	bool mayThrow();
	bool mayReturn();
	bool mayHaveSideEffects();
	Instruction ^clone();
	bool isIdenticalTo(Instruction ^I);
	bool isIdenticalToWhenDefined(Instruction ^I);
	bool isSameOperationAs(Instruction ^I);
	bool isSameOperationAs(Instruction ^I, unsigned flags);
	bool isUsedOutsideOfBlock(BasicBlock ^BB);
	static inline bool classof(Value ^V);
};

}
