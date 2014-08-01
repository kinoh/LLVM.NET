#include "InlineAsm.h"
#include "llvm/ADT/StringRef.h"
#include "DerivedTypes.h"
#include "Value.h"
#include <msclr/marshal.h>

using namespace LLVM;

InlineAsm::InlineAsm(llvm::InlineAsm *base)
	: base(base)
	, Value(base)
{
}
inline InlineAsm ^InlineAsm::_wrap(llvm::InlineAsm *base)
{
	return base ? gcnew InlineAsm(base) : nullptr;
}
InlineAsm::!InlineAsm()
{
}
InlineAsm::~InlineAsm()
{
	this->!InlineAsm();
}
InlineAsm ^InlineAsm::get(FunctionType ^Ty, System::String ^AsmString, System::String ^Constraints, bool hasSideEffects)
{
	msclr::interop::marshal_context ctx;
	return InlineAsm::_wrap(llvm::InlineAsm::get(Ty->base, ctx.marshal_as<const char *>(AsmString), ctx.marshal_as<const char *>(Constraints), hasSideEffects));
}
InlineAsm ^InlineAsm::get(FunctionType ^Ty, System::String ^AsmString, System::String ^Constraints, bool hasSideEffects, bool isAlignStack)
{
	msclr::interop::marshal_context ctx;
	return InlineAsm::_wrap(llvm::InlineAsm::get(Ty->base, ctx.marshal_as<const char *>(AsmString), ctx.marshal_as<const char *>(Constraints), hasSideEffects, isAlignStack));
}
InlineAsm ^InlineAsm::get(FunctionType ^Ty, System::String ^AsmString, System::String ^Constraints, bool hasSideEffects, bool isAlignStack, AsmDialect asmDialect)
{
	msclr::interop::marshal_context ctx;
	return InlineAsm::_wrap(llvm::InlineAsm::get(Ty->base, ctx.marshal_as<const char *>(AsmString), ctx.marshal_as<const char *>(Constraints), hasSideEffects, isAlignStack, safe_cast<llvm::InlineAsm::AsmDialect>(asmDialect)));
}
bool InlineAsm::hasSideEffects()
{
	return base->hasSideEffects();
}
bool InlineAsm::isAlignStack()
{
	return base->isAlignStack();
}
InlineAsm::AsmDialect InlineAsm::getDialect()
{
	return safe_cast<InlineAsm::AsmDialect>(base->getDialect());
}
PointerType ^InlineAsm::getType()
{
	return PointerType::_wrap(base->getType());
}
FunctionType ^InlineAsm::getFunctionType()
{
	return FunctionType::_wrap(base->getFunctionType());
}
bool InlineAsm::Verify(FunctionType ^Ty, System::String ^Constraints)
{
	msclr::interop::marshal_context ctx;
	return llvm::InlineAsm::Verify(Ty->base, ctx.marshal_as<const char *>(Constraints));
}
inline bool InlineAsm::classof(Value ^V)
{
	return llvm::InlineAsm::classof(V->base);
}
unsigned InlineAsm::getFlagWord(unsigned Kind, unsigned NumOps)
{
	return llvm::InlineAsm::getFlagWord(Kind, NumOps);
}
unsigned InlineAsm::getFlagWordForMatchingOp(unsigned InputFlag, unsigned MatchedOperandNo)
{
	return llvm::InlineAsm::getFlagWordForMatchingOp(InputFlag, MatchedOperandNo);
}
unsigned InlineAsm::getFlagWordForRegClass(unsigned InputFlag, unsigned RC)
{
	return llvm::InlineAsm::getFlagWordForRegClass(InputFlag, RC);
}
unsigned InlineAsm::getKind(unsigned Flags)
{
	return llvm::InlineAsm::getKind(Flags);
}
bool InlineAsm::isRegDefKind(unsigned Flag)
{
	return llvm::InlineAsm::isRegDefKind(Flag);
}
bool InlineAsm::isImmKind(unsigned Flag)
{
	return llvm::InlineAsm::isImmKind(Flag);
}
bool InlineAsm::isMemKind(unsigned Flag)
{
	return llvm::InlineAsm::isMemKind(Flag);
}
bool InlineAsm::isRegDefEarlyClobberKind(unsigned Flag)
{
	return llvm::InlineAsm::isRegDefEarlyClobberKind(Flag);
}
bool InlineAsm::isClobberKind(unsigned Flag)
{
	return llvm::InlineAsm::isClobberKind(Flag);
}
unsigned InlineAsm::getNumOperandRegisters(unsigned Flag)
{
	return llvm::InlineAsm::getNumOperandRegisters(Flag);
}
bool InlineAsm::isUseOperandTiedToDef(unsigned Flag, unsigned &Idx)
{
	return llvm::InlineAsm::isUseOperandTiedToDef(Flag, Idx);
}
bool InlineAsm::hasRegClassConstraint(unsigned Flag, unsigned &RC)
{
	return llvm::InlineAsm::hasRegClassConstraint(Flag, RC);
}
