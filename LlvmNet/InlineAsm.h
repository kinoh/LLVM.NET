#pragma once
#using <mscorlib.dll>
#include "llvm/IR/InlineAsm.h"
#include "Value.h"

namespace LLVM
{

ref class FunctionType;
ref class PointerType;
ref class Value;

public ref class InlineAsm
	: public Value
{
public:
	enum class AsmDialect
	{
		AD_ATT,
		AD_Intel
	};
	enum class ConstraintPrefix
	{
		isInput,
		isOutput,
		isClobber
	};

internal:
	llvm::InlineAsm *base;
	InlineAsm(llvm::InlineAsm *base);

public:
	!InlineAsm();
	virtual ~InlineAsm();
	static InlineAsm ^get(FunctionType ^Ty, System::String ^AsmString, System::String ^Constraints, bool hasSideEffects);
	static InlineAsm ^get(FunctionType ^Ty, System::String ^AsmString, System::String ^Constraints, bool hasSideEffects, bool isAlignStack);
	static InlineAsm ^get(FunctionType ^Ty, System::String ^AsmString, System::String ^Constraints, bool hasSideEffects, bool isAlignStack, AsmDialect asmDialect);
	bool hasSideEffects();
	bool isAlignStack();
	InlineAsm::AsmDialect getDialect();
	PointerType ^getType();
	FunctionType ^getFunctionType();
	// const std::string &getAsmString();
	// const std::string &getConstraintString();
	static bool Verify(FunctionType ^Ty, System::String ^Constraints);
	// typedef std::vector<std::string> ConstraintCodeVector;
	// struct SubConstraintInfo;
	// typedef std::vector<SubConstraintInfo> SubConstraintInfoVector;
	// struct ConstraintInfo;
	// typedef std::vector<ConstraintInfo> ConstraintInfoVector;
	// struct ConstraintInfo;
	// static ConstraintInfoVector ParseConstraints(StringRef ConstraintString);
	// ConstraintInfoVector ParseConstraints();
	static inline bool classof(Value ^V);
	// enum;
	static unsigned getFlagWord(unsigned Kind, unsigned NumOps);
	static unsigned getFlagWordForMatchingOp(unsigned InputFlag, unsigned MatchedOperandNo);
	static unsigned getFlagWordForRegClass(unsigned InputFlag, unsigned RC);
	static unsigned getKind(unsigned Flags);
	static bool isRegDefKind(unsigned Flag);
	static bool isImmKind(unsigned Flag);
	static bool isMemKind(unsigned Flag);
	static bool isRegDefEarlyClobberKind(unsigned Flag);
	static bool isClobberKind(unsigned Flag);
	static unsigned getNumOperandRegisters(unsigned Flag);
	static bool isUseOperandTiedToDef(unsigned Flag, unsigned &Idx);
	static bool hasRegClassConstraint(unsigned Flag, unsigned &RC);
};

}
