#pragma once
#using <mscorlib.dll>
#include "llvm/Analysis/Verifier.h"

namespace LLVM
{

ref class FunctionPass;
ref class Module;
ref class Function;

enum VerifierFailureAction
{
	AbortProcessAction,
	PrintMessageAction,
	ReturnStatusAction 
};

public ref class Verifier
{
public:
	static FunctionPass ^createVerifierPass();
	static FunctionPass ^createVerifierPass(VerifierFailureAction action);
	static bool verifyModule(const Module ^M);
	static bool verifyModule(const Module ^M, VerifierFailureAction action);
	static bool verifyModule(const Module ^M, VerifierFailureAction action, System::String ^%ErrorInfo);
	static bool verifyFunction(const Function ^F);
	static bool verifyFunction(const Function ^F, VerifierFailureAction action);
};

}
