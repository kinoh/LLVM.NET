#include "Intrinsics.h"
#include "llvm/ADT/ArrayRef.h"
#include "Type.h"
#include "LLVMContext.h"
#include "DerivedTypes.h"
#include "Attributes.h"
#include "Module.h"
#include "Function.h"
#include <msclr/marshal.h>
#include "utils.h"

using namespace LLVM;

System::String ^Intrinsic::getName(ID id)
{
	return utils::manage_str(llvm::Intrinsic::getName(safe_cast<llvm::Intrinsic::ID>(id)));
}
System::String ^Intrinsic::getName(ID id, array<Type ^> ^Tys)
{
	llvm::Type **b = new llvm::Type*[Tys->Length];
	for (int i = 0; i < Tys->Length; i++)
		b[i] = Tys[i]->base;
	llvm::ArrayRef<llvm::Type*> brr(b, Tys->Length);
	auto r = utils::manage_str(llvm::Intrinsic::getName(safe_cast<llvm::Intrinsic::ID>(id), brr));
	delete b;
	return r;
}
FunctionType ^Intrinsic::getType(LLVMContext ^Context, ID id)
{
	return gcnew FunctionType(llvm::Intrinsic::getType(*Context->base, safe_cast<llvm::Intrinsic::ID>(id)));
}
FunctionType ^Intrinsic::getType(LLVMContext ^Context, ID id, array<Type ^> ^Tys)
{
	llvm::Type **b = new llvm::Type*[Tys->Length];
	for (int i = 0; i < Tys->Length; i++)
		b[i] = Tys[i]->base;
	llvm::ArrayRef<llvm::Type*> brr(b, Tys->Length);
	auto r = gcnew FunctionType(llvm::Intrinsic::getType(*Context->base, safe_cast<llvm::Intrinsic::ID>(id), brr));
	delete b;
	return r;
}
bool Intrinsic::isOverloaded(ID id)
{
	return llvm::Intrinsic::isOverloaded(safe_cast<llvm::Intrinsic::ID>(id));
}
AttributeSet ^Intrinsic::getAttributes(LLVMContext ^C, ID id)
{
	return gcnew AttributeSet(&llvm::Intrinsic::getAttributes(*C->base, safe_cast<llvm::Intrinsic::ID>(id)));
}
Function ^Intrinsic::getDeclaration(Module ^M, ID id)
{
	return gcnew Function(llvm::Intrinsic::getDeclaration(M->base, safe_cast<llvm::Intrinsic::ID>(id)));
}
Function ^Intrinsic::getDeclaration(Module ^M, ID id, array<Type ^> ^Tys)
{
	llvm::Type **b = new llvm::Type*[Tys->Length];
	for (int i = 0; i < Tys->Length; i++)
		b[i] = Tys[i]->base;
	llvm::ArrayRef<llvm::Type*> brr(b, Tys->Length);
	auto r = gcnew Function(llvm::Intrinsic::getDeclaration(M->base, safe_cast<llvm::Intrinsic::ID>(id), brr));
	delete b;
	return r;
}
CallingConv::ID Intrinsic::getIntrinsicForGCCBuiltin(System::String ^Prefix, System::String ^BuiltinName)
{
	msclr::interop::marshal_context ctx;
	return safe_cast<CallingConv::ID>(llvm::Intrinsic::getIntrinsicForGCCBuiltin(ctx.marshal_as<const char *>(Prefix), ctx.marshal_as<const char *>(BuiltinName)));
}
