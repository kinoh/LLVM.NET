#include "Verifier.h"
#include "Pass.h"
#include "Module.h"
#include "Function.h"
#include <msclr/marshal_cppstd.h>

using namespace LLVM;

FunctionPass ^Verifier::createVerifierPass()
{
	return FunctionPass::_wrap(llvm::createVerifierPass());
}
FunctionPass ^Verifier::createVerifierPass(VerifierFailureAction action)
{
	return FunctionPass::_wrap(llvm::createVerifierPass(safe_cast<llvm::VerifierFailureAction>(action)));
}
bool Verifier::verifyModule(const Module ^M)
{
	return llvm::verifyModule(*M->base);
}
bool Verifier::verifyModule(const Module ^M, VerifierFailureAction action)
{
	return llvm::verifyModule(*M->base, safe_cast<llvm::VerifierFailureAction>(action));
}
bool Verifier::verifyModule(const Module ^M, VerifierFailureAction action, System::String ^%ErrorInfo)
{
	std::string err;
	auto r = llvm::verifyModule(*M->base, safe_cast<llvm::VerifierFailureAction>(action), &err);
	ErrorInfo = msclr::interop::marshal_as<System::String ^>(err);
	return r;
}
bool Verifier::verifyFunction(const Function ^F)
{
	return llvm::verifyFunction(*F->base);
}
bool Verifier::verifyFunction(const Function ^F, VerifierFailureAction action)
{
	return llvm::verifyFunction(*F->base, safe_cast<llvm::VerifierFailureAction>(action));
}
