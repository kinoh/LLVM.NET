#include "Instruction.h"
#include "llvm/ADT/StringRef.h"
#include "BasicBlock.h"
#include "Metadata.h"
#include "DebugLoc.h"
#include "Operator.h"
#include "Value.h"
#include <msclr/marshal.h>
#include "utils.h"

using namespace LLVM;

Instruction::Instruction(llvm::Instruction *base)
	: base(base)
	, User(base)
{
}
Instruction::!Instruction()
{
}
Instruction::~Instruction()
{
	this->!Instruction();
}
Instruction ^Instruction::use_back()
{
	return gcnew Instruction(base->use_back());
}
inline BasicBlock ^Instruction::getParent()
{
	return gcnew BasicBlock(base->getParent());
}
void Instruction::removeFromParent()
{
	base->removeFromParent();
}
void Instruction::eraseFromParent()
{
	base->eraseFromParent();
}
void Instruction::insertBefore(Instruction ^InsertPos)
{
	base->insertBefore(InsertPos->base);
}
void Instruction::insertAfter(Instruction ^InsertPos)
{
	base->insertAfter(InsertPos->base);
}
void Instruction::moveBefore(Instruction ^MovePos)
{
	base->moveBefore(MovePos->base);
}
unsigned Instruction::getOpcode()
{
	return base->getOpcode();
}
System::String ^Instruction::getOpcodeName()
{
	return utils::manage_str(base->getOpcodeName());
}
bool Instruction::isTerminator()
{
	return base->isTerminator();
}
bool Instruction::isBinaryOp()
{
	return base->isBinaryOp();
}
bool Instruction::isShift()
{
	return base->isShift();
}
bool Instruction::isCast()
{
	return base->isCast();
}
System::String ^Instruction::getOpcodeName(unsigned OpCode)
{
	return utils::manage_str(llvm::Instruction::getOpcodeName(OpCode));
}
inline bool Instruction::isTerminator(unsigned OpCode)
{
	return llvm::Instruction::isTerminator(OpCode);
}
inline bool Instruction::isBinaryOp(unsigned Opcode)
{
	return llvm::Instruction::isBinaryOp(Opcode);
}
inline bool Instruction::isShift(unsigned Opcode)
{
	return llvm::Instruction::isShift(Opcode);
}
inline bool Instruction::isLogicalShift()
{
	return base->isLogicalShift();
}
inline bool Instruction::isArithmeticShift()
{
	return base->isArithmeticShift();
}
inline bool Instruction::isCast(unsigned OpCode)
{
	return llvm::Instruction::isCast(OpCode);
}
bool Instruction::hasMetadata()
{
	return base->hasMetadata();
}
bool Instruction::hasMetadataOtherThanDebugLoc()
{
	return base->hasMetadataOtherThanDebugLoc();
}
MDNode ^Instruction::getMetadata(unsigned KindID)
{
	return gcnew MDNode(base->getMetadata(KindID));
}
MDNode ^Instruction::getMetadata(System::String ^Kind)
{
	msclr::interop::marshal_context ctx;
	return gcnew MDNode(base->getMetadata(ctx.marshal_as<const char *>(Kind)));
}
void Instruction::setMetadata(unsigned KindID, MDNode ^Node)
{
	base->setMetadata(KindID, Node->base);
}
void Instruction::setMetadata(System::String ^Kind, MDNode ^Node)
{
	msclr::interop::marshal_context ctx;
	base->setMetadata(ctx.marshal_as<const char *>(Kind), Node->base);
}
void Instruction::setDebugLoc(DebugLoc ^Loc)
{
	base->setDebugLoc(*Loc->base);
}
void Instruction::setHasUnsafeAlgebra(bool B)
{
	base->setHasUnsafeAlgebra(B);
}
void Instruction::setHasNoNaNs(bool B)
{
	base->setHasNoNaNs(B);
}
void Instruction::setHasNoInfs(bool B)
{
	base->setHasNoInfs(B);
}
void Instruction::setHasNoSignedZeros(bool B)
{
	base->setHasNoSignedZeros(B);
}
void Instruction::setHasAllowReciprocal(bool B)
{
	base->setHasAllowReciprocal(B);
}
void Instruction::setFastMathFlags(FastMathFlags ^FMF)
{
	base->setFastMathFlags(*FMF->base);
}
bool Instruction::hasUnsafeAlgebra()
{
	return base->hasUnsafeAlgebra();
}
bool Instruction::hasNoNaNs()
{
	return base->hasNoNaNs();
}
bool Instruction::hasNoInfs()
{
	return base->hasNoInfs();
}
bool Instruction::hasNoSignedZeros()
{
	return base->hasNoSignedZeros();
}
bool Instruction::hasAllowReciprocal()
{
	return base->hasAllowReciprocal();
}
FastMathFlags ^Instruction::getFastMathFlags()
{
	return gcnew FastMathFlags(&base->getFastMathFlags());
}
void Instruction::copyFastMathFlags(Instruction ^I)
{
	base->copyFastMathFlags(I->base);
}
bool Instruction::isAssociative()
{
	return base->isAssociative();
}
bool Instruction::isAssociative(unsigned op)
{
	return llvm::Instruction::isAssociative(op);
}
bool Instruction::isCommutative()
{
	return base->isCommutative();
}
bool Instruction::isCommutative(unsigned op)
{
	return llvm::Instruction::isCommutative(op);
}
bool Instruction::isIdempotent()
{
	return base->isIdempotent();
}
bool Instruction::isIdempotent(unsigned op)
{
	return llvm::Instruction::isIdempotent(op);
}
bool Instruction::isNilpotent()
{
	return base->isNilpotent();
}
bool Instruction::isNilpotent(unsigned op)
{
	return llvm::Instruction::isNilpotent(op);
}
bool Instruction::mayWriteToMemory()
{
	return base->mayWriteToMemory();
}
bool Instruction::mayReadFromMemory()
{
	return base->mayReadFromMemory();
}
bool Instruction::mayReadOrWriteMemory()
{
	return base->mayReadOrWriteMemory();
}
bool Instruction::mayThrow()
{
	return base->mayThrow();
}
bool Instruction::mayReturn()
{
	return base->mayReturn();
}
bool Instruction::mayHaveSideEffects()
{
	return base->mayHaveSideEffects();
}
Instruction ^Instruction::clone()
{
	return gcnew Instruction(base->clone());
}
bool Instruction::isIdenticalTo(Instruction ^I)
{
	return base->isIdenticalTo(I->base);
}
bool Instruction::isIdenticalToWhenDefined(Instruction ^I)
{
	return base->isIdenticalToWhenDefined(I->base);
}
bool Instruction::isSameOperationAs(Instruction ^I)
{
	return base->isSameOperationAs(I->base);
}
bool Instruction::isSameOperationAs(Instruction ^I, unsigned flags)
{
	return base->isSameOperationAs(I->base, flags);
}
bool Instruction::isUsedOutsideOfBlock(BasicBlock ^BB)
{
	return base->isUsedOutsideOfBlock(BB->base);
}
inline bool Instruction::classof(Value ^V)
{
	return llvm::Instruction::classof(V->base);
}
