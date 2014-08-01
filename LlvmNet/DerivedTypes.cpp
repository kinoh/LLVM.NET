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
inline IntegerType ^IntegerType::_wrap(llvm::IntegerType *base)
{
	return base ? gcnew IntegerType(base) : nullptr;
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
	return IntegerType::_wrap(llvm::IntegerType::get(*C->base, NumBits));
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
inline FunctionType ^FunctionType::_wrap(llvm::FunctionType *base)
{
	return base ? gcnew FunctionType(base) : nullptr;
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
	auto r = FunctionType::_wrap(llvm::FunctionType::get(Result->base, brr, isVarArg));
	delete b;
	return r;
}
FunctionType ^FunctionType::get(Type ^Result, bool isVarArg)
{
	return FunctionType::_wrap(llvm::FunctionType::get(Result->base, isVarArg));
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
	return Type::_wrap(base->getReturnType());
}
Type ^FunctionType::getParamType(unsigned i)
{
	return Type::_wrap(base->getParamType(i));
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
inline CompositeType ^CompositeType::_wrap(llvm::CompositeType *base)
{
	return base ? gcnew CompositeType(base) : nullptr;
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
	return Type::_wrap(base->getTypeAtIndex(V->base));
}
Type ^CompositeType::getTypeAtIndex(unsigned Idx)
{
	return Type::_wrap(base->getTypeAtIndex(Idx));
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
inline StructType ^StructType::_wrap(llvm::StructType *base)
{
	return base ? gcnew StructType(base) : nullptr;
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
	return StructType::_wrap(llvm::StructType::create(*Context->base, ctx.marshal_as<const char *>(Name)));
}
StructType ^StructType::create(LLVMContext ^Context)
{
	return StructType::_wrap(llvm::StructType::create(*Context->base));
}
StructType ^StructType::create(array<Type ^> ^Elements, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	llvm::Type **b = new llvm::Type*[Elements->Length];
	for (int i = 0; i < Elements->Length; i++)
		b[i] = Elements[i]->base;
	llvm::ArrayRef<llvm::Type*> brr(b, Elements->Length);
	auto r = StructType::_wrap(llvm::StructType::create(brr, ctx.marshal_as<const char *>(Name)));
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
	auto r = StructType::_wrap(llvm::StructType::create(brr, ctx.marshal_as<const char *>(Name), isPacked));
	delete b;
	return r;
}
StructType ^StructType::create(array<Type ^> ^Elements)
{
	llvm::Type **b = new llvm::Type*[Elements->Length];
	for (int i = 0; i < Elements->Length; i++)
		b[i] = Elements[i]->base;
	llvm::ArrayRef<llvm::Type*> brr(b, Elements->Length);
	auto r = StructType::_wrap(llvm::StructType::create(brr));
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
	auto r = StructType::_wrap(llvm::StructType::create(*Context->base, brr, ctx.marshal_as<const char *>(Name)));
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
	auto r = StructType::_wrap(llvm::StructType::create(*Context->base, brr, ctx.marshal_as<const char *>(Name), isPacked));
	delete b;
	return r;
}
StructType ^StructType::create(LLVMContext ^Context, array<Type ^> ^Elements)
{
	llvm::Type **b = new llvm::Type*[Elements->Length];
	for (int i = 0; i < Elements->Length; i++)
		b[i] = Elements[i]->base;
	llvm::ArrayRef<llvm::Type*> brr(b, Elements->Length);
	auto r = StructType::_wrap(llvm::StructType::create(*Context->base, brr));
	delete b;
	return r;
}
StructType ^StructType::get(LLVMContext ^Context, array<Type ^> ^Elements)
{
	llvm::Type **b = new llvm::Type*[Elements->Length];
	for (int i = 0; i < Elements->Length; i++)
		b[i] = Elements[i]->base;
	llvm::ArrayRef<llvm::Type*> brr(b, Elements->Length);
	auto r = StructType::_wrap(llvm::StructType::get(*Context->base, brr));
	delete b;
	return r;
}
StructType ^StructType::get(LLVMContext ^Context, array<Type ^> ^Elements, bool isPacked)
{
	llvm::Type **b = new llvm::Type*[Elements->Length];
	for (int i = 0; i < Elements->Length; i++)
		b[i] = Elements[i]->base;
	llvm::ArrayRef<llvm::Type*> brr(b, Elements->Length);
	auto r = StructType::_wrap(llvm::StructType::get(*Context->base, brr, isPacked));
	delete b;
	return r;
}
StructType ^StructType::get(LLVMContext ^Context)
{
	return StructType::_wrap(llvm::StructType::get(*Context->base));
}
StructType ^StructType::get(LLVMContext ^Context, bool isPacked)
{
	return StructType::_wrap(llvm::StructType::get(*Context->base, isPacked));
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
	return Type::_wrap(base->getElementType(N));
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
inline SequentialType ^SequentialType::_wrap(llvm::SequentialType *base)
{
	return base ? gcnew SequentialType(base) : nullptr;
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
	return Type::_wrap(base->getElementType());
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
inline ArrayType ^ArrayType::_wrap(llvm::ArrayType *base)
{
	return base ? gcnew ArrayType(base) : nullptr;
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
	return ArrayType::_wrap(llvm::ArrayType::get(ElementType->base, NumElements));
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
inline VectorType ^VectorType::_wrap(llvm::VectorType *base)
{
	return base ? gcnew VectorType(base) : nullptr;
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
	return VectorType::_wrap(llvm::VectorType::get(ElementType->base, NumElements));
}
VectorType ^VectorType::getInteger(VectorType ^VTy)
{
	return VectorType::_wrap(llvm::VectorType::getInteger(VTy->base));
}
VectorType ^VectorType::getExtendedElementVectorType(VectorType ^VTy)
{
	return VectorType::_wrap(llvm::VectorType::getExtendedElementVectorType(VTy->base));
}
VectorType ^VectorType::getTruncatedElementVectorType(VectorType ^VTy)
{
	return VectorType::_wrap(llvm::VectorType::getTruncatedElementVectorType(VTy->base));
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
inline PointerType ^PointerType::_wrap(llvm::PointerType *base)
{
	return base ? gcnew PointerType(base) : nullptr;
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
	return PointerType::_wrap(llvm::PointerType::get(ElementType->base, AddressSpace));
}
PointerType ^PointerType::getUnqual(Type ^ElementType)
{
	return PointerType::_wrap(llvm::PointerType::getUnqual(ElementType->base));
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
