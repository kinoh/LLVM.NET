#include "DerivedTypes.h"
#include "Type.h"
#include "llvm/ADT/ArrayRef.h"
#include "llvm/ADT/StringRef.h"
#include "LLVMContext.h"
#include "Type.h"
#include "Value.h"
#include <msclr/marshal.h>
#include "utils.h"

using namespace LLVM;

IntegerType::IntegerType(llvm::IntegerType *base)
	: base(base)
	, Type(base)
{
}
IntegerType::!IntegerType()
{
}
IntegerType::~IntegerType()
{
	this->!IntegerType();
}
IntegerType ^IntegerType::get(LLVMContext ^C, unsigned NumBits)
{
	return gcnew IntegerType(llvm::IntegerType::get(*C->base, NumBits));
}
unsigned IntegerType::getBitWidth()
{
	return base->getBitWidth();
}
uint64_t IntegerType::getBitMask()
{
	return base->getBitMask();
}
uint64_t IntegerType::getSignBit()
{
	return base->getSignBit();
}
bool IntegerType::isPowerOf2ByteWidth()
{
	return base->isPowerOf2ByteWidth();
}
inline bool IntegerType::classof(Type ^T)
{
	return llvm::IntegerType::classof(T->base);
}


FunctionType::FunctionType(llvm::FunctionType *base)
	: base(base)
	, Type(base)
{
}
FunctionType::!FunctionType()
{
}
FunctionType::~FunctionType()
{
	this->!FunctionType();
}
FunctionType ^FunctionType::get(Type ^Result, array<Type ^> ^Params, bool isVarArg)
{
	llvm::Type **b = new llvm::Type*[Params->Length];
	for (int i = 0; i < Params->Length; i++)
		b[i] = Params[i]->base;
	llvm::ArrayRef<llvm::Type*> brr(b, Params->Length);
	auto r = gcnew FunctionType(llvm::FunctionType::get(Result->base, brr, isVarArg));
	delete b;
	return r;
}
FunctionType ^FunctionType::get(Type ^Result, bool isVarArg)
{
	return gcnew FunctionType(llvm::FunctionType::get(Result->base, isVarArg));
}
bool FunctionType::isValidReturnType(Type ^RetTy)
{
	return llvm::FunctionType::isValidReturnType(RetTy->base);
}
bool FunctionType::isValidArgumentType(Type ^ArgTy)
{
	return llvm::FunctionType::isValidArgumentType(ArgTy->base);
}
bool FunctionType::isVarArg()
{
	return base->isVarArg();
}
Type ^FunctionType::getReturnType()
{
	return gcnew Type(base->getReturnType());
}
Type ^FunctionType::getParamType(unsigned i)
{
	return gcnew Type(base->getParamType(i));
}
unsigned FunctionType::getNumParams()
{
	return base->getNumParams();
}
inline bool FunctionType::classof(Type ^T)
{
	return llvm::FunctionType::classof(T->base);
}


CompositeType::CompositeType(llvm::CompositeType *base)
	: base(base)
	, Type(base)
{
}
CompositeType::!CompositeType()
{
}
CompositeType::~CompositeType()
{
	this->!CompositeType();
}
Type ^CompositeType::getTypeAtIndex(Value ^V)
{
	return gcnew Type(base->getTypeAtIndex(V->base));
}
Type ^CompositeType::getTypeAtIndex(unsigned Idx)
{
	return gcnew Type(base->getTypeAtIndex(Idx));
}
bool CompositeType::indexValid(Value ^V)
{
	return base->indexValid(V->base);
}
bool CompositeType::indexValid(unsigned Idx)
{
	return base->indexValid(Idx);
}
inline bool CompositeType::classof(Type ^T)
{
	return llvm::CompositeType::classof(T->base);
}


StructType::StructType(llvm::StructType *base)
	: base(base)
	, CompositeType(base)
{
}
StructType::!StructType()
{
}
StructType::~StructType()
{
	this->!StructType();
}
StructType ^StructType::create(LLVMContext ^Context, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew StructType(llvm::StructType::create(*Context->base, ctx.marshal_as<const char *>(Name)));
}
StructType ^StructType::create(LLVMContext ^Context)
{
	return gcnew StructType(llvm::StructType::create(*Context->base));
}
StructType ^StructType::create(array<Type ^> ^Elements, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	llvm::Type **b = new llvm::Type*[Elements->Length];
	for (int i = 0; i < Elements->Length; i++)
		b[i] = Elements[i]->base;
	llvm::ArrayRef<llvm::Type*> brr(b, Elements->Length);
	auto r = gcnew StructType(llvm::StructType::create(brr, ctx.marshal_as<const char *>(Name)));
	delete b;
	return r;
}
StructType ^StructType::create(array<Type ^> ^Elements, System::String ^Name, bool isPacked)
{
	msclr::interop::marshal_context ctx;
	llvm::Type **b = new llvm::Type*[Elements->Length];
	for (int i = 0; i < Elements->Length; i++)
		b[i] = Elements[i]->base;
	llvm::ArrayRef<llvm::Type*> brr(b, Elements->Length);
	auto r = gcnew StructType(llvm::StructType::create(brr, ctx.marshal_as<const char *>(Name), isPacked));
	delete b;
	return r;
}
StructType ^StructType::create(array<Type ^> ^Elements)
{
	llvm::Type **b = new llvm::Type*[Elements->Length];
	for (int i = 0; i < Elements->Length; i++)
		b[i] = Elements[i]->base;
	llvm::ArrayRef<llvm::Type*> brr(b, Elements->Length);
	auto r = gcnew StructType(llvm::StructType::create(brr));
	delete b;
	return r;
}
StructType ^StructType::create(LLVMContext ^Context, array<Type ^> ^Elements, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	llvm::Type **b = new llvm::Type*[Elements->Length];
	for (int i = 0; i < Elements->Length; i++)
		b[i] = Elements[i]->base;
	llvm::ArrayRef<llvm::Type*> brr(b, Elements->Length);
	auto r = gcnew StructType(llvm::StructType::create(*Context->base, brr, ctx.marshal_as<const char *>(Name)));
	delete b;
	return r;
}
StructType ^StructType::create(LLVMContext ^Context, array<Type ^> ^Elements, System::String ^Name, bool isPacked)
{
	msclr::interop::marshal_context ctx;
	llvm::Type **b = new llvm::Type*[Elements->Length];
	for (int i = 0; i < Elements->Length; i++)
		b[i] = Elements[i]->base;
	llvm::ArrayRef<llvm::Type*> brr(b, Elements->Length);
	auto r = gcnew StructType(llvm::StructType::create(*Context->base, brr, ctx.marshal_as<const char *>(Name), isPacked));
	delete b;
	return r;
}
StructType ^StructType::create(LLVMContext ^Context, array<Type ^> ^Elements)
{
	llvm::Type **b = new llvm::Type*[Elements->Length];
	for (int i = 0; i < Elements->Length; i++)
		b[i] = Elements[i]->base;
	llvm::ArrayRef<llvm::Type*> brr(b, Elements->Length);
	auto r = gcnew StructType(llvm::StructType::create(*Context->base, brr));
	delete b;
	return r;
}
StructType ^StructType::get(LLVMContext ^Context, array<Type ^> ^Elements)
{
	llvm::Type **b = new llvm::Type*[Elements->Length];
	for (int i = 0; i < Elements->Length; i++)
		b[i] = Elements[i]->base;
	llvm::ArrayRef<llvm::Type*> brr(b, Elements->Length);
	auto r = gcnew StructType(llvm::StructType::get(*Context->base, brr));
	delete b;
	return r;
}
StructType ^StructType::get(LLVMContext ^Context, array<Type ^> ^Elements, bool isPacked)
{
	llvm::Type **b = new llvm::Type*[Elements->Length];
	for (int i = 0; i < Elements->Length; i++)
		b[i] = Elements[i]->base;
	llvm::ArrayRef<llvm::Type*> brr(b, Elements->Length);
	auto r = gcnew StructType(llvm::StructType::get(*Context->base, brr, isPacked));
	delete b;
	return r;
}
StructType ^StructType::get(LLVMContext ^Context)
{
	return gcnew StructType(llvm::StructType::get(*Context->base));
}
StructType ^StructType::get(LLVMContext ^Context, bool isPacked)
{
	return gcnew StructType(llvm::StructType::get(*Context->base, isPacked));
}
bool StructType::isPacked()
{
	return base->isPacked();
}
bool StructType::isLiteral()
{
	return base->isLiteral();
}
bool StructType::isOpaque()
{
	return base->isOpaque();
}
bool StructType::isSized()
{
	return base->isSized();
}
bool StructType::hasName()
{
	return base->hasName();
}
System::String ^StructType::getName()
{
	return utils::manage_str(base->getName());
}
void StructType::setName(System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	base->setName(ctx.marshal_as<const char *>(Name));
}
void StructType::setBody(array<Type ^> ^Elements)
{
	llvm::Type **b = new llvm::Type*[Elements->Length];
	for (int i = 0; i < Elements->Length; i++)
		b[i] = Elements[i]->base;
	llvm::ArrayRef<llvm::Type*> brr(b, Elements->Length);
	base->setBody(brr);
	delete b;
}
void StructType::setBody(array<Type ^> ^Elements, bool isPacked)
{
	llvm::Type **b = new llvm::Type*[Elements->Length];
	for (int i = 0; i < Elements->Length; i++)
		b[i] = Elements[i]->base;
	llvm::ArrayRef<llvm::Type*> brr(b, Elements->Length);
	base->setBody(brr, isPacked);
	delete b;
}
bool StructType::isValidElementType(Type ^ElemTy)
{
	return llvm::StructType::isValidElementType(ElemTy->base);
}
bool StructType::isLayoutIdentical(StructType ^Other)
{
	return base->isLayoutIdentical(Other->base);
}
unsigned StructType::getNumElements()
{
	return base->getNumElements();
}
Type ^StructType::getElementType(unsigned N)
{
	return gcnew Type(base->getElementType(N));
}
inline bool StructType::classof(Type ^T)
{
	return llvm::StructType::classof(T->base);
}


SequentialType::SequentialType(llvm::SequentialType *base)
	: base(base)
	, CompositeType(base)
{
}
SequentialType::!SequentialType()
{
}
SequentialType::~SequentialType()
{
	this->!SequentialType();
}
Type ^SequentialType::getElementType()
{
	return gcnew Type(base->getElementType());
}
inline bool SequentialType::classof(Type ^T)
{
	return llvm::SequentialType::classof(T->base);
}


ArrayType::ArrayType(llvm::ArrayType *base)
	: base(base)
	, SequentialType(base)
{
}
ArrayType::!ArrayType()
{
}
ArrayType::~ArrayType()
{
	this->!ArrayType();
}
ArrayType ^ArrayType::get(Type ^ElementType, uint64_t NumElements)
{
	return gcnew ArrayType(llvm::ArrayType::get(ElementType->base, NumElements));
}
bool ArrayType::isValidElementType(Type ^ElemTy)
{
	return llvm::ArrayType::isValidElementType(ElemTy->base);
}
uint64_t ArrayType::getNumElements()
{
	return base->getNumElements();
}
inline bool ArrayType::classof(Type ^T)
{
	return llvm::ArrayType::classof(T->base);
}


VectorType::VectorType(llvm::VectorType *base)
	: base(base)
	, SequentialType(base)
{
}
VectorType::!VectorType()
{
}
VectorType::~VectorType()
{
	this->!VectorType();
}
VectorType ^VectorType::get(Type ^ElementType, unsigned NumElements)
{
	return gcnew VectorType(llvm::VectorType::get(ElementType->base, NumElements));
}
VectorType ^VectorType::getInteger(VectorType ^VTy)
{
	return gcnew VectorType(llvm::VectorType::getInteger(VTy->base));
}
VectorType ^VectorType::getExtendedElementVectorType(VectorType ^VTy)
{
	return gcnew VectorType(llvm::VectorType::getExtendedElementVectorType(VTy->base));
}
VectorType ^VectorType::getTruncatedElementVectorType(VectorType ^VTy)
{
	return gcnew VectorType(llvm::VectorType::getTruncatedElementVectorType(VTy->base));
}
bool VectorType::isValidElementType(Type ^ElemTy)
{
	return llvm::VectorType::isValidElementType(ElemTy->base);
}
unsigned VectorType::getNumElements()
{
	return base->getNumElements();
}
unsigned VectorType::getBitWidth()
{
	return base->getBitWidth();
}
inline bool VectorType::classof(Type ^T)
{
	return llvm::VectorType::classof(T->base);
}


PointerType::PointerType(llvm::PointerType *base)
	: base(base)
	, SequentialType(base)
{
}
PointerType::!PointerType()
{
}
PointerType::~PointerType()
{
	this->!PointerType();
}
PointerType ^PointerType::get(Type ^ElementType, unsigned AddressSpace)
{
	return gcnew PointerType(llvm::PointerType::get(ElementType->base, AddressSpace));
}
PointerType ^PointerType::getUnqual(Type ^ElementType)
{
	return gcnew PointerType(llvm::PointerType::getUnqual(ElementType->base));
}
bool PointerType::isValidElementType(Type ^ElemTy)
{
	return llvm::PointerType::isValidElementType(ElemTy->base);
}
inline unsigned PointerType::getAddressSpace()
{
	return base->getAddressSpace();
}
inline bool PointerType::classof(Type ^T)
{
	return llvm::PointerType::classof(T->base);
}
