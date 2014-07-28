#pragma once
#using <mscorlib.dll>
#include "llvm/IR/DerivedTypes.h"
#include "Type.h"

namespace LLVM
{

ref class LLVMContext;
ref class Type;
ref class Value;

public ref class IntegerType
	: public Type
{
internal:
	llvm::IntegerType *base;
	IntegerType(llvm::IntegerType *base);

public:
	!IntegerType();
	virtual ~IntegerType();
	// enum;
	static IntegerType ^get(LLVMContext ^C, unsigned NumBits);
	unsigned getBitWidth();
	uint64_t getBitMask();
	uint64_t getSignBit();
	// APInt getMask();
	bool isPowerOf2ByteWidth();
	static inline bool classof(Type ^T);
};


public ref class FunctionType
	: public Type
{
internal:
	llvm::FunctionType *base;
	FunctionType(llvm::FunctionType *base);

public:
	!FunctionType();
	virtual ~FunctionType();
	static FunctionType ^get(Type ^Result, array<Type ^> ^Params, bool isVarArg);
	static FunctionType ^get(Type ^Result, bool isVarArg);
	static bool isValidReturnType(Type ^RetTy);
	static bool isValidArgumentType(Type ^ArgTy);
	bool isVarArg();
	Type ^getReturnType();
	// typedef Type::subtype_iterator param_iterator;
	// param_iterator param_begin();
	// param_iterator param_end();
	Type ^getParamType(unsigned i);
	unsigned getNumParams();
	static inline bool classof(Type ^T);
};


public ref class CompositeType
	: public Type
{
internal:
	llvm::CompositeType *base;
	CompositeType(llvm::CompositeType *base);

public:
	!CompositeType();
	virtual ~CompositeType();
	Type ^getTypeAtIndex(Value ^V);
	Type ^getTypeAtIndex(unsigned Idx);
	bool indexValid(Value ^V);
	bool indexValid(unsigned Idx);
	static inline bool classof(Type ^T);
};


public ref class StructType
	: public CompositeType
{
internal:
	llvm::StructType *base;
	StructType(llvm::StructType *base);

public:
	!StructType();
	virtual ~StructType();
	// ~StructType();
	static StructType ^create(LLVMContext ^Context, System::String ^Name);
	static StructType ^create(LLVMContext ^Context);
	static StructType ^create(array<Type ^> ^Elements, System::String ^Name);
	static StructType ^create(array<Type ^> ^Elements, System::String ^Name, bool isPacked);
	static StructType ^create(array<Type ^> ^Elements);
	static StructType ^create(LLVMContext ^Context, array<Type ^> ^Elements, System::String ^Name);
	static StructType ^create(LLVMContext ^Context, array<Type ^> ^Elements, System::String ^Name, bool isPacked);
	static StructType ^create(LLVMContext ^Context, array<Type ^> ^Elements);
	// static StructType *create(StringRef Name, Type *elt1, ...) END_WITH_NULL;
	static StructType ^get(LLVMContext ^Context, array<Type ^> ^Elements);
	static StructType ^get(LLVMContext ^Context, array<Type ^> ^Elements, bool isPacked);
	static StructType ^get(LLVMContext ^Context);
	static StructType ^get(LLVMContext ^Context, bool isPacked);
	// static StructType *get(Type *elt1, ...) END_WITH_NULL;
	bool isPacked();
	bool isLiteral();
	bool isOpaque();
	bool isSized();
	bool hasName();
	System::String ^getName();
	void setName(System::String ^Name);
	void setBody(array<Type ^> ^Elements);
	void setBody(array<Type ^> ^Elements, bool isPacked);
	// void setBody(Type *elt1, ...) END_WITH_NULL;
	static bool isValidElementType(Type ^ElemTy);
	// typedef Type::subtype_iterator element_iterator;
	// element_iterator element_begin();
	// element_iterator element_end();
	bool isLayoutIdentical(StructType ^Other);
	unsigned getNumElements();
	Type ^getElementType(unsigned N);
	static inline bool classof(Type ^T);
};


public ref class SequentialType
	: public CompositeType
{
internal:
	llvm::SequentialType *base;
	SequentialType(llvm::SequentialType *base);

public:
	!SequentialType();
	virtual ~SequentialType();
	Type ^getElementType();
	static inline bool classof(Type ^T);
};


public ref class ArrayType
	: public SequentialType
{
internal:
	llvm::ArrayType *base;
	ArrayType(llvm::ArrayType *base);

public:
	!ArrayType();
	virtual ~ArrayType();
	static ArrayType ^get(Type ^ElementType, uint64_t NumElements);
	static bool isValidElementType(Type ^ElemTy);
	uint64_t getNumElements();
	static inline bool classof(Type ^T);
};


public ref class VectorType
	: public SequentialType
{
internal:
	llvm::VectorType *base;
	VectorType(llvm::VectorType *base);

public:
	!VectorType();
	virtual ~VectorType();
	static VectorType ^get(Type ^ElementType, unsigned NumElements);
	static VectorType ^getInteger(VectorType ^VTy);
	static VectorType ^getExtendedElementVectorType(VectorType ^VTy);
	static VectorType ^getTruncatedElementVectorType(VectorType ^VTy);
	static bool isValidElementType(Type ^ElemTy);
	unsigned getNumElements();
	unsigned getBitWidth();
	static inline bool classof(Type ^T);
};


public ref class PointerType
	: public SequentialType
{
internal:
	llvm::PointerType *base;
	PointerType(llvm::PointerType *base);

public:
	!PointerType();
	virtual ~PointerType();
	static PointerType ^get(Type ^ElementType, unsigned AddressSpace);
	static PointerType ^getUnqual(Type ^ElementType);
	static bool isValidElementType(Type ^ElemTy);
	inline unsigned getAddressSpace();
	static inline bool classof(Type ^T);
};

}
