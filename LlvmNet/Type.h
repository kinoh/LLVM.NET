#pragma once
#using <mscorlib.dll>
#include "llvm/IR/Type.h"

namespace LLVM
{

ref class LLVMContext;
ref class IntegerType;
ref class PointerType;

public ref class Type
{
public:
	enum class TypeID
	{
		VoidTyID = 0,
		HalfTyID,
		FloatTyID,
		DoubleTyID,
		X86_FP80TyID,
		FP128TyID,
		PPC_FP128TyID,
		LabelTyID,
		MetadataTyID,
		X86_MMXTyID,
		IntegerTyID,
		FunctionTyID,
		StructTyID,
		ArrayTyID,
		PointerTyID,
		VectorTyID,

		NumTypeIDs,
		LastPrimitiveTyID = X86_MMXTyID,
		FirstDerivedTyID = IntegerTyID
	};

internal:
	llvm::Type *base;
	Type(llvm::Type *base);

public:
	!Type();
	virtual ~Type();
	// void print(raw_ostream &O);
	void dump();
	LLVMContext ^getContext();
	Type::TypeID getTypeID();
	bool isVoidTy();
	bool isHalfTy();
	bool isFloatTy();
	bool isDoubleTy();
	bool isX86_FP80Ty();
	bool isFP128Ty();
	bool isPPC_FP128Ty();
	bool isFloatingPointTy();
	// const fltSemantics &getFltSemantics();
	bool isX86_MMXTy();
	bool isFPOrFPVectorTy();
	bool isLabelTy();
	bool isMetadataTy();
	bool isIntegerTy();
	bool isIntegerTy(unsigned Bitwidth);
	bool isIntOrIntVectorTy();
	bool isFunctionTy();
	bool isStructTy();
	bool isArrayTy();
	bool isPointerTy();
	bool isPtrOrPtrVectorTy();
	bool isVectorTy();
	bool canLosslesslyBitCastTo(Type ^Ty);
	bool isEmptyTy();
	bool isPrimitiveType();
	bool isDerivedType();
	bool isFirstClassType();
	bool isSingleValueType();
	bool isAggregateType();
	bool isSized();
	unsigned getPrimitiveSizeInBits();
	unsigned getScalarSizeInBits();
	int getFPMantissaWidth();
	// const Type *getScalarType();
	Type ^getScalarType();
	// typedef Type  *const *subtype_iterator;
	// subtype_iterator subtype_begin();
	// subtype_iterator subtype_end();
	Type ^getContainedType(unsigned i);
	unsigned getNumContainedTypes();
	unsigned getIntegerBitWidth();
	Type ^getFunctionParamType(unsigned i);
	unsigned getFunctionNumParams();
	bool isFunctionVarArg();
	System::String ^getStructName();
	unsigned getStructNumElements();
	Type ^getStructElementType(unsigned N);
	Type ^getSequentialElementType();
	uint64_t getArrayNumElements();
	Type ^getArrayElementType();
	unsigned getVectorNumElements();
	Type ^getVectorElementType();
	Type ^getPointerElementType();
	unsigned getPointerAddressSpace();
	static Type ^getPrimitiveType(LLVMContext ^C, TypeID IDNumber);
	static Type ^getVoidTy(LLVMContext ^C);
	static Type ^getLabelTy(LLVMContext ^C);
	static Type ^getHalfTy(LLVMContext ^C);
	static Type ^getFloatTy(LLVMContext ^C);
	static Type ^getDoubleTy(LLVMContext ^C);
	static Type ^getMetadataTy(LLVMContext ^C);
	static Type ^getX86_FP80Ty(LLVMContext ^C);
	static Type ^getFP128Ty(LLVMContext ^C);
	static Type ^getPPC_FP128Ty(LLVMContext ^C);
	static Type ^getX86_MMXTy(LLVMContext ^C);
	static IntegerType ^getIntNTy(LLVMContext ^C, unsigned N);
	static IntegerType ^getInt1Ty(LLVMContext ^C);
	static IntegerType ^getInt8Ty(LLVMContext ^C);
	static IntegerType ^getInt16Ty(LLVMContext ^C);
	static IntegerType ^getInt32Ty(LLVMContext ^C);
	static IntegerType ^getInt64Ty(LLVMContext ^C);
	static PointerType ^getHalfPtrTy(LLVMContext ^C);
	static PointerType ^getHalfPtrTy(LLVMContext ^C, unsigned AS);
	static PointerType ^getFloatPtrTy(LLVMContext ^C);
	static PointerType ^getFloatPtrTy(LLVMContext ^C, unsigned AS);
	static PointerType ^getDoublePtrTy(LLVMContext ^C);
	static PointerType ^getDoublePtrTy(LLVMContext ^C, unsigned AS);
	static PointerType ^getX86_FP80PtrTy(LLVMContext ^C);
	static PointerType ^getX86_FP80PtrTy(LLVMContext ^C, unsigned AS);
	static PointerType ^getFP128PtrTy(LLVMContext ^C);
	static PointerType ^getFP128PtrTy(LLVMContext ^C, unsigned AS);
	static PointerType ^getPPC_FP128PtrTy(LLVMContext ^C);
	static PointerType ^getPPC_FP128PtrTy(LLVMContext ^C, unsigned AS);
	static PointerType ^getX86_MMXPtrTy(LLVMContext ^C);
	static PointerType ^getX86_MMXPtrTy(LLVMContext ^C, unsigned AS);
	static PointerType ^getIntNPtrTy(LLVMContext ^C, unsigned N);
	static PointerType ^getIntNPtrTy(LLVMContext ^C, unsigned N, unsigned AS);
	static PointerType ^getInt1PtrTy(LLVMContext ^C);
	static PointerType ^getInt1PtrTy(LLVMContext ^C, unsigned AS);
	static PointerType ^getInt8PtrTy(LLVMContext ^C);
	static PointerType ^getInt8PtrTy(LLVMContext ^C, unsigned AS);
	static PointerType ^getInt16PtrTy(LLVMContext ^C);
	static PointerType ^getInt16PtrTy(LLVMContext ^C, unsigned AS);
	static PointerType ^getInt32PtrTy(LLVMContext ^C);
	static PointerType ^getInt32PtrTy(LLVMContext ^C, unsigned AS);
	static PointerType ^getInt64PtrTy(LLVMContext ^C);
	static PointerType ^getInt64PtrTy(LLVMContext ^C, unsigned AS);
	PointerType ^getPointerTo();
	PointerType ^getPointerTo(unsigned AddrSpace);
};

}
