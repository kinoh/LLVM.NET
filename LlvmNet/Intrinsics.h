#pragma once
#using <mscorlib.dll>
#include "llvm/IR/Intrinsics.h"
#include "CallingConv.h"

namespace LLVM
{

ref class Type;
ref class LLVMContext;
ref class FunctionType;
ref class AttributeSet;
ref class Module;
ref class Function;

public ref class Intrinsic
{
public:
	enum class ID
	{
		not_intrinsic = 0,
#define GET_INTRINSIC_ENUM_VALUES
#include "llvm/IR/Intrinsics.gen"
#undef GET_INTRINSIC_ENUM_VALUES
		, num_intrinsics
	};
	enum class ArgKind
	{
			AK_AnyInteger,
			AK_AnyFloat,
			AK_AnyVector,
			AK_AnyPointer
		};

public:
	static System::String ^getName(ID id);
	static System::String ^getName(ID id, array<Type ^> ^Tys);
	static FunctionType ^getType(LLVMContext ^Context, ID id);
	static FunctionType ^getType(LLVMContext ^Context, ID id, array<Type ^> ^Tys);
	static bool isOverloaded(ID id);
	static AttributeSet ^getAttributes(LLVMContext ^C, ID id);
	static Function ^getDeclaration(Module ^M, ID id);
	static Function ^getDeclaration(Module ^M, ID id, array<Type ^> ^Tys);
	static CallingConv::ID getIntrinsicForGCCBuiltin(System::String ^Prefix, System::String ^BuiltinName);
	// struct IITDescriptor;
	// void getIntrinsicInfoTableEntries(ID id, SmallVectorImpl<IITDescriptor> &T);
};

}
