#include "InstrTypes.h"
#include "Instruction.h"
#include "llvm/ADT/Twine.h"
#include "BasicBlock.h"
#include "Instruction.h"
#include "Value.h"
#include "Type.h"
#include <msclr/marshal.h>

using namespace LLVM;

TerminatorInst::TerminatorInst(llvm::TerminatorInst *base)
	: base(base)
	, Instruction(base)
{
}
TerminatorInst::!TerminatorInst()
{
}
TerminatorInst::~TerminatorInst()
{
	this->!TerminatorInst();
}
unsigned TerminatorInst::getNumSuccessors()
{
	return base->getNumSuccessors();
}
BasicBlock ^TerminatorInst::getSuccessor(unsigned idx)
{
	return gcnew BasicBlock(base->getSuccessor(idx));
}
void TerminatorInst::setSuccessor(unsigned idx, BasicBlock ^B)
{
	base->setSuccessor(idx, B->base);
}
inline bool TerminatorInst::classof(Instruction ^I)
{
	return llvm::TerminatorInst::classof(I->base);
}
inline bool TerminatorInst::classof(Value ^V)
{
	return llvm::TerminatorInst::classof(V->base);
}


UnaryInstruction::UnaryInstruction(llvm::UnaryInstruction *base)
	: base(base)
	, Instruction(base)
{
}
UnaryInstruction::!UnaryInstruction()
{
}
UnaryInstruction::~UnaryInstruction()
{
	this->!UnaryInstruction();
}
inline bool UnaryInstruction::classof(Instruction ^I)
{
	return llvm::UnaryInstruction::classof(I->base);
}
inline bool UnaryInstruction::classof(Value ^V)
{
	return llvm::UnaryInstruction::classof(V->base);
}


BinaryOperator::BinaryOperator(llvm::BinaryOperator *base)
	: base(base)
	, Instruction(base)
{
}
BinaryOperator::!BinaryOperator()
{
}
BinaryOperator::~BinaryOperator()
{
	this->!BinaryOperator();
}
BinaryOperator ^BinaryOperator::Create(BinaryOps Op, Value ^S1, Value ^S2)
{
	return gcnew BinaryOperator(llvm::BinaryOperator::Create(safe_cast<llvm::BinaryOperator::BinaryOps>(Op), S1->base, S2->base));
}
BinaryOperator ^BinaryOperator::Create(BinaryOps Op, Value ^S1, Value ^S2, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::Create(safe_cast<llvm::BinaryOperator::BinaryOps>(Op), S1->base, S2->base, ctx.marshal_as<const char *>(Name)));
}
BinaryOperator ^BinaryOperator::Create(BinaryOps Op, Value ^S1, Value ^S2, System::String ^Name, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::Create(safe_cast<llvm::BinaryOperator::BinaryOps>(Op), S1->base, S2->base, ctx.marshal_as<const char *>(Name), InsertBefore->base));
}
BinaryOperator ^BinaryOperator::Create(BinaryOps Op, Value ^S1, Value ^S2, System::String ^Name, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::Create(safe_cast<llvm::BinaryOperator::BinaryOps>(Op), S1->base, S2->base, ctx.marshal_as<const char *>(Name), InsertAtEnd->base));
}
BinaryOperator ^BinaryOperator::CreateNSW(BinaryOps Opc, Value ^V1, Value ^V2)
{
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNSW(safe_cast<llvm::BinaryOperator::BinaryOps>(Opc), V1->base, V2->base));
}
BinaryOperator ^BinaryOperator::CreateNSW(BinaryOps Opc, Value ^V1, Value ^V2, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNSW(safe_cast<llvm::BinaryOperator::BinaryOps>(Opc), V1->base, V2->base, ctx.marshal_as<const char *>(Name)));
}
BinaryOperator ^BinaryOperator::CreateNSW(BinaryOps Opc, Value ^V1, Value ^V2, System::String ^Name, BasicBlock ^BB)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNSW(safe_cast<llvm::BinaryOperator::BinaryOps>(Opc), V1->base, V2->base, ctx.marshal_as<const char *>(Name), BB->base));
}
BinaryOperator ^BinaryOperator::CreateNSW(BinaryOps Opc, Value ^V1, Value ^V2, System::String ^Name, Instruction ^I)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNSW(safe_cast<llvm::BinaryOperator::BinaryOps>(Opc), V1->base, V2->base, ctx.marshal_as<const char *>(Name), I->base));
}
BinaryOperator ^BinaryOperator::CreateNUW(BinaryOps Opc, Value ^V1, Value ^V2)
{
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNUW(safe_cast<llvm::BinaryOperator::BinaryOps>(Opc), V1->base, V2->base));
}
BinaryOperator ^BinaryOperator::CreateNUW(BinaryOps Opc, Value ^V1, Value ^V2, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNUW(safe_cast<llvm::BinaryOperator::BinaryOps>(Opc), V1->base, V2->base, ctx.marshal_as<const char *>(Name)));
}
BinaryOperator ^BinaryOperator::CreateNUW(BinaryOps Opc, Value ^V1, Value ^V2, System::String ^Name, BasicBlock ^BB)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNUW(safe_cast<llvm::BinaryOperator::BinaryOps>(Opc), V1->base, V2->base, ctx.marshal_as<const char *>(Name), BB->base));
}
BinaryOperator ^BinaryOperator::CreateNUW(BinaryOps Opc, Value ^V1, Value ^V2, System::String ^Name, Instruction ^I)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNUW(safe_cast<llvm::BinaryOperator::BinaryOps>(Opc), V1->base, V2->base, ctx.marshal_as<const char *>(Name), I->base));
}
BinaryOperator ^BinaryOperator::CreateExact(BinaryOps Opc, Value ^V1, Value ^V2)
{
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateExact(safe_cast<llvm::BinaryOperator::BinaryOps>(Opc), V1->base, V2->base));
}
BinaryOperator ^BinaryOperator::CreateExact(BinaryOps Opc, Value ^V1, Value ^V2, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateExact(safe_cast<llvm::BinaryOperator::BinaryOps>(Opc), V1->base, V2->base, ctx.marshal_as<const char *>(Name)));
}
BinaryOperator ^BinaryOperator::CreateExact(BinaryOps Opc, Value ^V1, Value ^V2, System::String ^Name, BasicBlock ^BB)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateExact(safe_cast<llvm::BinaryOperator::BinaryOps>(Opc), V1->base, V2->base, ctx.marshal_as<const char *>(Name), BB->base));
}
BinaryOperator ^BinaryOperator::CreateExact(BinaryOps Opc, Value ^V1, Value ^V2, System::String ^Name, Instruction ^I)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateExact(safe_cast<llvm::BinaryOperator::BinaryOps>(Opc), V1->base, V2->base, ctx.marshal_as<const char *>(Name), I->base));
}
BinaryOperator ^BinaryOperator::CreateNeg(Value ^Op)
{
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNeg(Op->base));
}
BinaryOperator ^BinaryOperator::CreateNeg(Value ^Op, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNeg(Op->base, ctx.marshal_as<const char *>(Name)));
}
BinaryOperator ^BinaryOperator::CreateNeg(Value ^Op, System::String ^Name, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNeg(Op->base, ctx.marshal_as<const char *>(Name), InsertBefore->base));
}
BinaryOperator ^BinaryOperator::CreateNeg(Value ^Op, System::String ^Name, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNeg(Op->base, ctx.marshal_as<const char *>(Name), InsertAtEnd->base));
}
BinaryOperator ^BinaryOperator::CreateNSWNeg(Value ^Op)
{
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNSWNeg(Op->base));
}
BinaryOperator ^BinaryOperator::CreateNSWNeg(Value ^Op, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNSWNeg(Op->base, ctx.marshal_as<const char *>(Name)));
}
BinaryOperator ^BinaryOperator::CreateNSWNeg(Value ^Op, System::String ^Name, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNSWNeg(Op->base, ctx.marshal_as<const char *>(Name), InsertBefore->base));
}
BinaryOperator ^BinaryOperator::CreateNSWNeg(Value ^Op, System::String ^Name, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNSWNeg(Op->base, ctx.marshal_as<const char *>(Name), InsertAtEnd->base));
}
BinaryOperator ^BinaryOperator::CreateNUWNeg(Value ^Op)
{
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNUWNeg(Op->base));
}
BinaryOperator ^BinaryOperator::CreateNUWNeg(Value ^Op, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNUWNeg(Op->base, ctx.marshal_as<const char *>(Name)));
}
BinaryOperator ^BinaryOperator::CreateNUWNeg(Value ^Op, System::String ^Name, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNUWNeg(Op->base, ctx.marshal_as<const char *>(Name), InsertBefore->base));
}
BinaryOperator ^BinaryOperator::CreateNUWNeg(Value ^Op, System::String ^Name, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNUWNeg(Op->base, ctx.marshal_as<const char *>(Name), InsertAtEnd->base));
}
BinaryOperator ^BinaryOperator::CreateFNeg(Value ^Op)
{
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateFNeg(Op->base));
}
BinaryOperator ^BinaryOperator::CreateFNeg(Value ^Op, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateFNeg(Op->base, ctx.marshal_as<const char *>(Name)));
}
BinaryOperator ^BinaryOperator::CreateFNeg(Value ^Op, System::String ^Name, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateFNeg(Op->base, ctx.marshal_as<const char *>(Name), InsertBefore->base));
}
BinaryOperator ^BinaryOperator::CreateFNeg(Value ^Op, System::String ^Name, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateFNeg(Op->base, ctx.marshal_as<const char *>(Name), InsertAtEnd->base));
}
BinaryOperator ^BinaryOperator::CreateNot(Value ^Op)
{
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNot(Op->base));
}
BinaryOperator ^BinaryOperator::CreateNot(Value ^Op, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNot(Op->base, ctx.marshal_as<const char *>(Name)));
}
BinaryOperator ^BinaryOperator::CreateNot(Value ^Op, System::String ^Name, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNot(Op->base, ctx.marshal_as<const char *>(Name), InsertBefore->base));
}
BinaryOperator ^BinaryOperator::CreateNot(Value ^Op, System::String ^Name, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return gcnew BinaryOperator(llvm::BinaryOperator::CreateNot(Op->base, ctx.marshal_as<const char *>(Name), InsertAtEnd->base));
}
bool BinaryOperator::isNeg(Value ^V)
{
	return llvm::BinaryOperator::isNeg(V->base);
}
bool BinaryOperator::isFNeg(Value ^V)
{
	return llvm::BinaryOperator::isFNeg(V->base);
}
bool BinaryOperator::isFNeg(Value ^V, bool IgnoreZeroSign)
{
	return llvm::BinaryOperator::isFNeg(V->base, IgnoreZeroSign);
}
bool BinaryOperator::isNot(Value ^V)
{
	return llvm::BinaryOperator::isNot(V->base);
}
Instruction::BinaryOps BinaryOperator::getOpcode()
{
	return safe_cast<Instruction::BinaryOps>(base->getOpcode());
}
bool BinaryOperator::swapOperands()
{
	return base->swapOperands();
}
void BinaryOperator::setHasNoUnsignedWrap()
{
	base->setHasNoUnsignedWrap();
}
void BinaryOperator::setHasNoUnsignedWrap(bool b)
{
	base->setHasNoUnsignedWrap(b);
}
void BinaryOperator::setHasNoSignedWrap()
{
	base->setHasNoSignedWrap();
}
void BinaryOperator::setHasNoSignedWrap(bool b)
{
	base->setHasNoSignedWrap(b);
}
void BinaryOperator::setIsExact()
{
	base->setIsExact();
}
void BinaryOperator::setIsExact(bool b)
{
	base->setIsExact(b);
}
bool BinaryOperator::hasNoUnsignedWrap()
{
	return base->hasNoUnsignedWrap();
}
bool BinaryOperator::hasNoSignedWrap()
{
	return base->hasNoSignedWrap();
}
bool BinaryOperator::isExact()
{
	return base->isExact();
}
inline bool BinaryOperator::classof(Instruction ^I)
{
	return llvm::BinaryOperator::classof(I->base);
}
inline bool BinaryOperator::classof(Value ^V)
{
	return llvm::BinaryOperator::classof(V->base);
}


CastInst::CastInst(llvm::CastInst *base)
	: base(base)
	, UnaryInstruction(base)
{
}
CastInst::!CastInst()
{
}
CastInst::~CastInst()
{
	this->!CastInst();
}
CastInst ^CastInst::Create(CastOps castOps, Value ^S, Type ^Ty)
{
	return gcnew CastInst(llvm::CastInst::Create(safe_cast<llvm::CastInst::CastOps>(castOps), S->base, Ty->base));
}
CastInst ^CastInst::Create(CastOps castOps, Value ^S, Type ^Ty, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::Create(safe_cast<llvm::CastInst::CastOps>(castOps), S->base, Ty->base, ctx.marshal_as<const char *>(Name)));
}
CastInst ^CastInst::Create(CastOps castOps, Value ^S, Type ^Ty, System::String ^Name, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::Create(safe_cast<llvm::CastInst::CastOps>(castOps), S->base, Ty->base, ctx.marshal_as<const char *>(Name), InsertBefore->base));
}
CastInst ^CastInst::Create(CastOps castOps, Value ^S, Type ^Ty, System::String ^Name, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::Create(safe_cast<llvm::CastInst::CastOps>(castOps), S->base, Ty->base, ctx.marshal_as<const char *>(Name), InsertAtEnd->base));
}
CastInst ^CastInst::CreateZExtOrBitCast(Value ^S, Type ^Ty)
{
	return gcnew CastInst(llvm::CastInst::CreateZExtOrBitCast(S->base, Ty->base));
}
CastInst ^CastInst::CreateZExtOrBitCast(Value ^S, Type ^Ty, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::CreateZExtOrBitCast(S->base, Ty->base, ctx.marshal_as<const char *>(Name)));
}
CastInst ^CastInst::CreateZExtOrBitCast(Value ^S, Type ^Ty, System::String ^Name, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::CreateZExtOrBitCast(S->base, Ty->base, ctx.marshal_as<const char *>(Name), InsertBefore->base));
}
CastInst ^CastInst::CreateZExtOrBitCast(Value ^S, Type ^Ty, System::String ^Name, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::CreateZExtOrBitCast(S->base, Ty->base, ctx.marshal_as<const char *>(Name), InsertAtEnd->base));
}
CastInst ^CastInst::CreateSExtOrBitCast(Value ^S, Type ^Ty)
{
	return gcnew CastInst(llvm::CastInst::CreateSExtOrBitCast(S->base, Ty->base));
}
CastInst ^CastInst::CreateSExtOrBitCast(Value ^S, Type ^Ty, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::CreateSExtOrBitCast(S->base, Ty->base, ctx.marshal_as<const char *>(Name)));
}
CastInst ^CastInst::CreateSExtOrBitCast(Value ^S, Type ^Ty, System::String ^Name, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::CreateSExtOrBitCast(S->base, Ty->base, ctx.marshal_as<const char *>(Name), InsertBefore->base));
}
CastInst ^CastInst::CreateSExtOrBitCast(Value ^S, Type ^Ty, System::String ^Name, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::CreateSExtOrBitCast(S->base, Ty->base, ctx.marshal_as<const char *>(Name), InsertAtEnd->base));
}
CastInst ^CastInst::CreatePointerCast(Value ^S, Type ^Ty, System::String ^Name, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::CreatePointerCast(S->base, Ty->base, ctx.marshal_as<const char *>(Name), InsertAtEnd->base));
}
CastInst ^CastInst::CreatePointerCast(Value ^S, Type ^Ty)
{
	return gcnew CastInst(llvm::CastInst::CreatePointerCast(S->base, Ty->base));
}
CastInst ^CastInst::CreatePointerCast(Value ^S, Type ^Ty, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::CreatePointerCast(S->base, Ty->base, ctx.marshal_as<const char *>(Name)));
}
CastInst ^CastInst::CreatePointerCast(Value ^S, Type ^Ty, System::String ^Name, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::CreatePointerCast(S->base, Ty->base, ctx.marshal_as<const char *>(Name), InsertBefore->base));
}
CastInst ^CastInst::CreateIntegerCast(Value ^S, Type ^Ty, bool isSigned)
{
	return gcnew CastInst(llvm::CastInst::CreateIntegerCast(S->base, Ty->base, isSigned));
}
CastInst ^CastInst::CreateIntegerCast(Value ^S, Type ^Ty, bool isSigned, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::CreateIntegerCast(S->base, Ty->base, isSigned, ctx.marshal_as<const char *>(Name)));
}
CastInst ^CastInst::CreateIntegerCast(Value ^S, Type ^Ty, bool isSigned, System::String ^Name, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::CreateIntegerCast(S->base, Ty->base, isSigned, ctx.marshal_as<const char *>(Name), InsertBefore->base));
}
CastInst ^CastInst::CreateIntegerCast(Value ^S, Type ^Ty, bool isSigned, System::String ^Name, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::CreateIntegerCast(S->base, Ty->base, isSigned, ctx.marshal_as<const char *>(Name), InsertAtEnd->base));
}
CastInst ^CastInst::CreateFPCast(Value ^S, Type ^Ty)
{
	return gcnew CastInst(llvm::CastInst::CreateFPCast(S->base, Ty->base));
}
CastInst ^CastInst::CreateFPCast(Value ^S, Type ^Ty, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::CreateFPCast(S->base, Ty->base, ctx.marshal_as<const char *>(Name)));
}
CastInst ^CastInst::CreateFPCast(Value ^S, Type ^Ty, System::String ^Name, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::CreateFPCast(S->base, Ty->base, ctx.marshal_as<const char *>(Name), InsertBefore->base));
}
CastInst ^CastInst::CreateFPCast(Value ^S, Type ^Ty, System::String ^Name, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::CreateFPCast(S->base, Ty->base, ctx.marshal_as<const char *>(Name), InsertAtEnd->base));
}
CastInst ^CastInst::CreateTruncOrBitCast(Value ^S, Type ^Ty)
{
	return gcnew CastInst(llvm::CastInst::CreateTruncOrBitCast(S->base, Ty->base));
}
CastInst ^CastInst::CreateTruncOrBitCast(Value ^S, Type ^Ty, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::CreateTruncOrBitCast(S->base, Ty->base, ctx.marshal_as<const char *>(Name)));
}
CastInst ^CastInst::CreateTruncOrBitCast(Value ^S, Type ^Ty, System::String ^Name, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::CreateTruncOrBitCast(S->base, Ty->base, ctx.marshal_as<const char *>(Name), InsertBefore->base));
}
CastInst ^CastInst::CreateTruncOrBitCast(Value ^S, Type ^Ty, System::String ^Name, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return gcnew CastInst(llvm::CastInst::CreateTruncOrBitCast(S->base, Ty->base, ctx.marshal_as<const char *>(Name), InsertAtEnd->base));
}
bool CastInst::isCastable(Type ^SrcTy, Type ^DestTy)
{
	return llvm::CastInst::isCastable(SrcTy->base, DestTy->base);
}
Instruction::CastOps CastInst::getCastOpcode(Value ^Val, bool SrcIsSigned, Type ^Ty, bool DstIsSigned)
{
	return safe_cast<Instruction::CastOps>(llvm::CastInst::getCastOpcode(Val->base, SrcIsSigned, Ty->base, DstIsSigned));
}
bool CastInst::isIntegerCast()
{
	return base->isIntegerCast();
}
bool CastInst::isLosslessCast()
{
	return base->isLosslessCast();
}
bool CastInst::isNoopCast(Instruction::CastOps Opcode, Type ^SrcTy, Type ^DstTy, Type ^IntPtrTy)
{
	return llvm::CastInst::isNoopCast(safe_cast<llvm::Instruction::CastOps>(Opcode), SrcTy->base, DstTy->base, IntPtrTy->base);
}
bool CastInst::isNoopCast(Type ^IntPtrTy)
{
	return base->isNoopCast(IntPtrTy->base);
}
unsigned CastInst::isEliminableCastPair(Instruction::CastOps firstOpcode, Instruction::CastOps secondOpcode, Type ^SrcTy, Type ^MidTy, Type ^DstTy, Type ^SrcIntPtrTy, Type ^MidIntPtrTy, Type ^DstIntPtrTy)
{
	return llvm::CastInst::isEliminableCastPair(safe_cast<llvm::Instruction::CastOps>(firstOpcode), safe_cast<llvm::Instruction::CastOps>(secondOpcode), SrcTy->base, MidTy->base, DstTy->base, SrcIntPtrTy->base, MidIntPtrTy->base, DstIntPtrTy->base);
}
Instruction::CastOps CastInst::getOpcode()
{
	return safe_cast<Instruction::CastOps>(base->getOpcode());
}
Type ^CastInst::getSrcTy()
{
	return gcnew Type(base->getSrcTy());
}
Type ^CastInst::getDestTy()
{
	return gcnew Type(base->getDestTy());
}
bool CastInst::castIsValid(Instruction::CastOps op, Value ^S, Type ^DstTy)
{
	return llvm::CastInst::castIsValid(safe_cast<llvm::Instruction::CastOps>(op), S->base, DstTy->base);
}
inline bool CastInst::classof(Instruction ^I)
{
	return llvm::CastInst::classof(I->base);
}
inline bool CastInst::classof(Value ^V)
{
	return llvm::CastInst::classof(V->base);
}


CmpInst::CmpInst(llvm::CmpInst *base)
	: base(base)
	, Instruction(base)
{
}
CmpInst::!CmpInst()
{
}
CmpInst::~CmpInst()
{
	this->!CmpInst();
}
CmpInst ^CmpInst::Create(OtherOps Op, unsigned short predicate, Value ^S1, Value ^S2)
{
	return gcnew CmpInst(llvm::CmpInst::Create(safe_cast<llvm::CmpInst::OtherOps>(Op), predicate, S1->base, S2->base));
}
CmpInst ^CmpInst::Create(OtherOps Op, unsigned short predicate, Value ^S1, Value ^S2, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew CmpInst(llvm::CmpInst::Create(safe_cast<llvm::CmpInst::OtherOps>(Op), predicate, S1->base, S2->base, ctx.marshal_as<const char *>(Name)));
}
CmpInst ^CmpInst::Create(OtherOps Op, unsigned short predicate, Value ^S1, Value ^S2, System::String ^Name, Instruction ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return gcnew CmpInst(llvm::CmpInst::Create(safe_cast<llvm::CmpInst::OtherOps>(Op), predicate, S1->base, S2->base, ctx.marshal_as<const char *>(Name), InsertBefore->base));
}
CmpInst ^CmpInst::Create(OtherOps Op, unsigned short predicate, Value ^S1, Value ^S2, System::String ^Name, BasicBlock ^InsertAtEnd)
{
	msclr::interop::marshal_context ctx;
	return gcnew CmpInst(llvm::CmpInst::Create(safe_cast<llvm::CmpInst::OtherOps>(Op), predicate, S1->base, S2->base, ctx.marshal_as<const char *>(Name), InsertAtEnd->base));
}
Instruction::OtherOps CmpInst::getOpcode()
{
	return safe_cast<Instruction::OtherOps>(base->getOpcode());
}
CmpInst::Predicate CmpInst::getPredicate()
{
	return safe_cast<CmpInst::Predicate>(base->getPredicate());
}
void CmpInst::setPredicate(Predicate P)
{
	base->setPredicate(safe_cast<llvm::CmpInst::Predicate>(P));
}
bool CmpInst::isFPPredicate(Predicate P)
{
	return llvm::CmpInst::isFPPredicate(safe_cast<llvm::CmpInst::Predicate>(P));
}
bool CmpInst::isIntPredicate(Predicate P)
{
	return llvm::CmpInst::isIntPredicate(safe_cast<llvm::CmpInst::Predicate>(P));
}
bool CmpInst::isFPPredicate()
{
	return base->isFPPredicate();
}
bool CmpInst::isIntPredicate()
{
	return base->isIntPredicate();
}
CmpInst::Predicate CmpInst::getInversePredicate()
{
	return safe_cast<CmpInst::Predicate>(base->getInversePredicate());
}
CmpInst::Predicate CmpInst::getInversePredicate(Predicate pred)
{
	return safe_cast<CmpInst::Predicate>(llvm::CmpInst::getInversePredicate(safe_cast<llvm::CmpInst::Predicate>(pred)));
}
CmpInst::Predicate CmpInst::getSwappedPredicate()
{
	return safe_cast<CmpInst::Predicate>(base->getSwappedPredicate());
}
CmpInst::Predicate CmpInst::getSwappedPredicate(Predicate pred)
{
	return safe_cast<CmpInst::Predicate>(llvm::CmpInst::getSwappedPredicate(safe_cast<llvm::CmpInst::Predicate>(pred)));
}
void CmpInst::swapOperands()
{
	base->swapOperands();
}
bool CmpInst::isCommutative()
{
	return base->isCommutative();
}
bool CmpInst::isEquality()
{
	return base->isEquality();
}
bool CmpInst::isSigned()
{
	return base->isSigned();
}
bool CmpInst::isUnsigned()
{
	return base->isUnsigned();
}
bool CmpInst::isTrueWhenEqual()
{
	return base->isTrueWhenEqual();
}
bool CmpInst::isFalseWhenEqual()
{
	return base->isFalseWhenEqual();
}
bool CmpInst::isUnsigned(unsigned short predicate)
{
	return llvm::CmpInst::isUnsigned(predicate);
}
bool CmpInst::isSigned(unsigned short predicate)
{
	return llvm::CmpInst::isSigned(predicate);
}
bool CmpInst::isOrdered(unsigned short predicate)
{
	return llvm::CmpInst::isOrdered(predicate);
}
bool CmpInst::isUnordered(unsigned short predicate)
{
	return llvm::CmpInst::isUnordered(predicate);
}
bool CmpInst::isTrueWhenEqual(unsigned short predicate)
{
	return llvm::CmpInst::isTrueWhenEqual(predicate);
}
bool CmpInst::isFalseWhenEqual(unsigned short predicate)
{
	return llvm::CmpInst::isFalseWhenEqual(predicate);
}
inline bool CmpInst::classof(Instruction ^I)
{
	return llvm::CmpInst::classof(I->base);
}
inline bool CmpInst::classof(Value ^V)
{
	return llvm::CmpInst::classof(V->base);
}
Type ^CmpInst::makeCmpResultType(Type ^opnd_type)
{
	return gcnew Type(llvm::CmpInst::makeCmpResultType(opnd_type->base));
}
