#include "Constants.h"
#include "llvm/ADT/StringRef.h"
#include "Constant.h"
#include "llvm/ADT/ArrayRef.h"
#include "LLVMContext.h"
#include "Type.h"
#include "Constant.h"
#include "DerivedTypes.h"
#include "Value.h"
#include "Use.h"
#include "Function.h"
#include "BasicBlock.h"
#include "Instruction.h"
#include <msclr/marshal.h>
#include "utils.h"

using namespace LLVM;

ConstantInt::ConstantInt(llvm::ConstantInt *base)
	: base(base)
	, Constant(base)
{
}
ConstantInt::!ConstantInt()
{
}
ConstantInt::~ConstantInt()
{
	this->!ConstantInt();
}
ConstantInt ^ConstantInt::getTrue(LLVMContext ^Context)
{
	return gcnew ConstantInt(llvm::ConstantInt::getTrue(*Context->base));
}
ConstantInt ^ConstantInt::getFalse(LLVMContext ^Context)
{
	return gcnew ConstantInt(llvm::ConstantInt::getFalse(*Context->base));
}
Constant ^ConstantInt::getTrue(Type ^Ty)
{
	return gcnew Constant(llvm::ConstantInt::getTrue(Ty->base));
}
Constant ^ConstantInt::getFalse(Type ^Ty)
{
	return gcnew Constant(llvm::ConstantInt::getFalse(Ty->base));
}
Constant ^ConstantInt::get(Type ^Ty, uint64_t V)
{
	return gcnew Constant(llvm::ConstantInt::get(Ty->base, V));
}
Constant ^ConstantInt::get(Type ^Ty, uint64_t V, bool isSigned)
{
	return gcnew Constant(llvm::ConstantInt::get(Ty->base, V, isSigned));
}
ConstantInt ^ConstantInt::get(IntegerType ^Ty, uint64_t V)
{
	return gcnew ConstantInt(llvm::ConstantInt::get(Ty->base, V));
}
ConstantInt ^ConstantInt::get(IntegerType ^Ty, uint64_t V, bool isSigned)
{
	return gcnew ConstantInt(llvm::ConstantInt::get(Ty->base, V, isSigned));
}
ConstantInt ^ConstantInt::getSigned(IntegerType ^Ty, int64_t V)
{
	return gcnew ConstantInt(llvm::ConstantInt::getSigned(Ty->base, V));
}
Constant ^ConstantInt::getSigned(Type ^Ty, int64_t V)
{
	return gcnew Constant(llvm::ConstantInt::getSigned(Ty->base, V));
}
ConstantInt ^ConstantInt::get(IntegerType ^Ty, System::String ^Str, uint8_t radix)
{
	msclr::interop::marshal_context ctx;
	return gcnew ConstantInt(llvm::ConstantInt::get(Ty->base, ctx.marshal_as<const char *>(Str), radix));
}
unsigned ConstantInt::getBitWidth()
{
	return base->getBitWidth();
}
inline uint64_t ConstantInt::getZExtValue()
{
	return base->getZExtValue();
}
inline int64_t ConstantInt::getSExtValue()
{
	return base->getSExtValue();
}
bool ConstantInt::equalsInt(uint64_t V)
{
	return base->equalsInt(V);
}
inline IntegerType ^ConstantInt::getType()
{
	return gcnew IntegerType(base->getType());
}
bool ConstantInt::isValueValidForType(Type ^Ty, uint64_t V)
{
	return llvm::ConstantInt::isValueValidForType(Ty->base, V);
}
bool ConstantInt::isValueValidForType(Type ^Ty, int64_t V)
{
	return llvm::ConstantInt::isValueValidForType(Ty->base, V);
}
bool ConstantInt::isNegative()
{
	return base->isNegative();
}
bool ConstantInt::isZero()
{
	return base->isZero();
}
bool ConstantInt::isOne()
{
	return base->isOne();
}
bool ConstantInt::isMinusOne()
{
	return base->isMinusOne();
}
bool ConstantInt::isMaxValue(bool isSigned)
{
	return base->isMaxValue(isSigned);
}
bool ConstantInt::isMinValue(bool isSigned)
{
	return base->isMinValue(isSigned);
}
bool ConstantInt::uge(uint64_t Num)
{
	return base->uge(Num);
}
bool ConstantInt::classof(Value ^V)
{
	return llvm::ConstantInt::classof(V->base);
}


ConstantFP::ConstantFP(llvm::ConstantFP *base)
	: base(base)
	, Constant(base)
{
}
ConstantFP::!ConstantFP()
{
}
ConstantFP::~ConstantFP()
{
	this->!ConstantFP();
}
Constant ^ConstantFP::getZeroValueForNegation(Type ^Ty)
{
	return gcnew Constant(llvm::ConstantFP::getZeroValueForNegation(Ty->base));
}
Constant ^ConstantFP::get(Type ^Ty, double V)
{
	return gcnew Constant(llvm::ConstantFP::get(Ty->base, V));
}
Constant ^ConstantFP::get(Type ^Ty, System::String ^Str)
{
	msclr::interop::marshal_context ctx;
	return gcnew Constant(llvm::ConstantFP::get(Ty->base, ctx.marshal_as<const char *>(Str)));
}
ConstantFP ^ConstantFP::getNegativeZero(Type ^Ty)
{
	return gcnew ConstantFP(llvm::ConstantFP::getNegativeZero(Ty->base));
}
ConstantFP ^ConstantFP::getInfinity(Type ^Ty)
{
	return gcnew ConstantFP(llvm::ConstantFP::getInfinity(Ty->base));
}
ConstantFP ^ConstantFP::getInfinity(Type ^Ty, bool Negative)
{
	return gcnew ConstantFP(llvm::ConstantFP::getInfinity(Ty->base, Negative));
}
bool ConstantFP::isZero()
{
	return base->isZero();
}
bool ConstantFP::isNegative()
{
	return base->isNegative();
}
bool ConstantFP::isNaN()
{
	return base->isNaN();
}
bool ConstantFP::isExactlyValue(double V)
{
	return base->isExactlyValue(V);
}
bool ConstantFP::classof(Value ^V)
{
	return llvm::ConstantFP::classof(V->base);
}


ConstantAggregateZero::ConstantAggregateZero(llvm::ConstantAggregateZero *base)
	: base(base)
	, Constant(base)
{
}
ConstantAggregateZero::!ConstantAggregateZero()
{
}
ConstantAggregateZero::~ConstantAggregateZero()
{
	this->!ConstantAggregateZero();
}
ConstantAggregateZero ^ConstantAggregateZero::get(Type ^Ty)
{
	return gcnew ConstantAggregateZero(llvm::ConstantAggregateZero::get(Ty->base));
}
void ConstantAggregateZero::destroyConstant()
{
	base->destroyConstant();
}
Constant ^ConstantAggregateZero::getSequentialElement()
{
	return gcnew Constant(base->getSequentialElement());
}
Constant ^ConstantAggregateZero::getStructElement(unsigned Elt)
{
	return gcnew Constant(base->getStructElement(Elt));
}
Constant ^ConstantAggregateZero::getElementValue(Constant ^C)
{
	return gcnew Constant(base->getElementValue(C->base));
}
Constant ^ConstantAggregateZero::getElementValue(unsigned Idx)
{
	return gcnew Constant(base->getElementValue(Idx));
}
bool ConstantAggregateZero::classof(Value ^V)
{
	return llvm::ConstantAggregateZero::classof(V->base);
}


ConstantArray::ConstantArray(llvm::ConstantArray *base)
	: base(base)
	, Constant(base)
{
}
ConstantArray::!ConstantArray()
{
}
ConstantArray::~ConstantArray()
{
	this->!ConstantArray();
}
Constant ^ConstantArray::get(ArrayType ^T, array<Constant ^> ^V)
{
	llvm::Constant **b = new llvm::Constant*[V->Length];
	for (int i = 0; i < V->Length; i++)
		b[i] = V[i]->base;
	llvm::ArrayRef<llvm::Constant*> brr(b, V->Length);
	auto r = gcnew Constant(llvm::ConstantArray::get(T->base, brr));
	delete b;
	return r;
}
inline ArrayType ^ConstantArray::getType()
{
	return gcnew ArrayType(base->getType());
}
void ConstantArray::destroyConstant()
{
	base->destroyConstant();
}
void ConstantArray::replaceUsesOfWithOnConstant(Value ^From, Value ^To, Use ^U)
{
	base->replaceUsesOfWithOnConstant(From->base, To->base, U->base);
}
bool ConstantArray::classof(Value ^V)
{
	return llvm::ConstantArray::classof(V->base);
}


ConstantStruct::ConstantStruct(llvm::ConstantStruct *base)
	: base(base)
	, Constant(base)
{
}
ConstantStruct::!ConstantStruct()
{
}
ConstantStruct::~ConstantStruct()
{
	this->!ConstantStruct();
}
Constant ^ConstantStruct::get(StructType ^T, array<Constant ^> ^V)
{
	llvm::Constant **b = new llvm::Constant*[V->Length];
	for (int i = 0; i < V->Length; i++)
		b[i] = V[i]->base;
	llvm::ArrayRef<llvm::Constant*> brr(b, V->Length);
	auto r = gcnew Constant(llvm::ConstantStruct::get(T->base, brr));
	delete b;
	return r;
}
Constant ^ConstantStruct::getAnon(array<Constant ^> ^V)
{
	llvm::Constant **b = new llvm::Constant*[V->Length];
	for (int i = 0; i < V->Length; i++)
		b[i] = V[i]->base;
	llvm::ArrayRef<llvm::Constant*> brr(b, V->Length);
	auto r = gcnew Constant(llvm::ConstantStruct::getAnon(brr));
	delete b;
	return r;
}
Constant ^ConstantStruct::getAnon(array<Constant ^> ^V, bool Packed)
{
	llvm::Constant **b = new llvm::Constant*[V->Length];
	for (int i = 0; i < V->Length; i++)
		b[i] = V[i]->base;
	llvm::ArrayRef<llvm::Constant*> brr(b, V->Length);
	auto r = gcnew Constant(llvm::ConstantStruct::getAnon(brr, Packed));
	delete b;
	return r;
}
Constant ^ConstantStruct::getAnon(LLVMContext ^Ctx, array<Constant ^> ^V)
{
	llvm::Constant **b = new llvm::Constant*[V->Length];
	for (int i = 0; i < V->Length; i++)
		b[i] = V[i]->base;
	llvm::ArrayRef<llvm::Constant*> brr(b, V->Length);
	auto r = gcnew Constant(llvm::ConstantStruct::getAnon(*Ctx->base, brr));
	delete b;
	return r;
}
Constant ^ConstantStruct::getAnon(LLVMContext ^Ctx, array<Constant ^> ^V, bool Packed)
{
	llvm::Constant **b = new llvm::Constant*[V->Length];
	for (int i = 0; i < V->Length; i++)
		b[i] = V[i]->base;
	llvm::ArrayRef<llvm::Constant*> brr(b, V->Length);
	auto r = gcnew Constant(llvm::ConstantStruct::getAnon(*Ctx->base, brr, Packed));
	delete b;
	return r;
}
StructType ^ConstantStruct::getTypeForElements(array<Constant ^> ^V)
{
	llvm::Constant **b = new llvm::Constant*[V->Length];
	for (int i = 0; i < V->Length; i++)
		b[i] = V[i]->base;
	llvm::ArrayRef<llvm::Constant*> brr(b, V->Length);
	auto r = gcnew StructType(llvm::ConstantStruct::getTypeForElements(brr));
	delete b;
	return r;
}
StructType ^ConstantStruct::getTypeForElements(array<Constant ^> ^V, bool Packed)
{
	llvm::Constant **b = new llvm::Constant*[V->Length];
	for (int i = 0; i < V->Length; i++)
		b[i] = V[i]->base;
	llvm::ArrayRef<llvm::Constant*> brr(b, V->Length);
	auto r = gcnew StructType(llvm::ConstantStruct::getTypeForElements(brr, Packed));
	delete b;
	return r;
}
StructType ^ConstantStruct::getTypeForElements(LLVMContext ^Ctx, array<Constant ^> ^V)
{
	llvm::Constant **b = new llvm::Constant*[V->Length];
	for (int i = 0; i < V->Length; i++)
		b[i] = V[i]->base;
	llvm::ArrayRef<llvm::Constant*> brr(b, V->Length);
	auto r = gcnew StructType(llvm::ConstantStruct::getTypeForElements(*Ctx->base, brr));
	delete b;
	return r;
}
StructType ^ConstantStruct::getTypeForElements(LLVMContext ^Ctx, array<Constant ^> ^V, bool Packed)
{
	llvm::Constant **b = new llvm::Constant*[V->Length];
	for (int i = 0; i < V->Length; i++)
		b[i] = V[i]->base;
	llvm::ArrayRef<llvm::Constant*> brr(b, V->Length);
	auto r = gcnew StructType(llvm::ConstantStruct::getTypeForElements(*Ctx->base, brr, Packed));
	delete b;
	return r;
}
inline StructType ^ConstantStruct::getType()
{
	return gcnew StructType(base->getType());
}
void ConstantStruct::destroyConstant()
{
	base->destroyConstant();
}
void ConstantStruct::replaceUsesOfWithOnConstant(Value ^From, Value ^To, Use ^U)
{
	base->replaceUsesOfWithOnConstant(From->base, To->base, U->base);
}
bool ConstantStruct::classof(Value ^V)
{
	return llvm::ConstantStruct::classof(V->base);
}


ConstantVector::ConstantVector(llvm::ConstantVector *base)
	: base(base)
	, Constant(base)
{
}
ConstantVector::!ConstantVector()
{
}
ConstantVector::~ConstantVector()
{
	this->!ConstantVector();
}
Constant ^ConstantVector::get(array<Constant ^> ^V)
{
	llvm::Constant **b = new llvm::Constant*[V->Length];
	for (int i = 0; i < V->Length; i++)
		b[i] = V[i]->base;
	llvm::ArrayRef<llvm::Constant*> brr(b, V->Length);
	auto r = gcnew Constant(llvm::ConstantVector::get(brr));
	delete b;
	return r;
}
Constant ^ConstantVector::getSplat(unsigned NumElts, Constant ^Elt)
{
	return gcnew Constant(llvm::ConstantVector::getSplat(NumElts, Elt->base));
}
inline VectorType ^ConstantVector::getType()
{
	return gcnew VectorType(base->getType());
}
Constant ^ConstantVector::getSplatValue()
{
	return gcnew Constant(base->getSplatValue());
}
void ConstantVector::destroyConstant()
{
	base->destroyConstant();
}
void ConstantVector::replaceUsesOfWithOnConstant(Value ^From, Value ^To, Use ^U)
{
	base->replaceUsesOfWithOnConstant(From->base, To->base, U->base);
}
bool ConstantVector::classof(Value ^V)
{
	return llvm::ConstantVector::classof(V->base);
}


ConstantPointerNull::ConstantPointerNull(llvm::ConstantPointerNull *base)
	: base(base)
	, Constant(base)
{
}
ConstantPointerNull::!ConstantPointerNull()
{
}
ConstantPointerNull::~ConstantPointerNull()
{
	this->!ConstantPointerNull();
}
ConstantPointerNull ^ConstantPointerNull::get(PointerType ^T)
{
	return gcnew ConstantPointerNull(llvm::ConstantPointerNull::get(T->base));
}
void ConstantPointerNull::destroyConstant()
{
	base->destroyConstant();
}
inline PointerType ^ConstantPointerNull::getType()
{
	return gcnew PointerType(base->getType());
}
bool ConstantPointerNull::classof(Value ^V)
{
	return llvm::ConstantPointerNull::classof(V->base);
}


ConstantDataSequential::ConstantDataSequential(llvm::ConstantDataSequential *base)
	: base(base)
	, Constant(base)
{
}
ConstantDataSequential::!ConstantDataSequential()
{
}
ConstantDataSequential::~ConstantDataSequential()
{
	this->!ConstantDataSequential();
}
bool ConstantDataSequential::isElementTypeCompatible(Type ^Ty)
{
	return llvm::ConstantDataSequential::isElementTypeCompatible(Ty->base);
}
uint64_t ConstantDataSequential::getElementAsInteger(unsigned i)
{
	return base->getElementAsInteger(i);
}
float ConstantDataSequential::getElementAsFloat(unsigned i)
{
	return base->getElementAsFloat(i);
}
double ConstantDataSequential::getElementAsDouble(unsigned i)
{
	return base->getElementAsDouble(i);
}
Constant ^ConstantDataSequential::getElementAsConstant(unsigned i)
{
	return gcnew Constant(base->getElementAsConstant(i));
}
inline SequentialType ^ConstantDataSequential::getType()
{
	return gcnew SequentialType(base->getType());
}
Type ^ConstantDataSequential::getElementType()
{
	return gcnew Type(base->getElementType());
}
unsigned ConstantDataSequential::getNumElements()
{
	return base->getNumElements();
}
uint64_t ConstantDataSequential::getElementByteSize()
{
	return base->getElementByteSize();
}
bool ConstantDataSequential::isString()
{
	return base->isString();
}
bool ConstantDataSequential::isCString()
{
	return base->isCString();
}
System::String ^ConstantDataSequential::getAsString()
{
	return utils::manage_str(base->getAsString());
}
System::String ^ConstantDataSequential::getAsCString()
{
	return utils::manage_str(base->getAsCString());
}
System::String ^ConstantDataSequential::getRawDataValues()
{
	return utils::manage_str(base->getRawDataValues());
}
void ConstantDataSequential::destroyConstant()
{
	base->destroyConstant();
}
bool ConstantDataSequential::classof(Value ^V)
{
	return llvm::ConstantDataSequential::classof(V->base);
}


ConstantDataArray::ConstantDataArray(llvm::ConstantDataArray *base)
	: base(base)
	, ConstantDataSequential(base)
{
}
ConstantDataArray::!ConstantDataArray()
{
}
ConstantDataArray::~ConstantDataArray()
{
	this->!ConstantDataArray();
}
Constant ^ConstantDataArray::get(LLVMContext ^Context, array<uint8_t> ^Elts)
{
	auto r = gcnew Constant(llvm::ConstantDataArray::get(*Context->base, utils::unmanage_array(Elts)));
	return r;
}
Constant ^ConstantDataArray::get(LLVMContext ^Context, array<uint16_t> ^Elts)
{
	auto r = gcnew Constant(llvm::ConstantDataArray::get(*Context->base, utils::unmanage_array(Elts)));
	return r;
}
Constant ^ConstantDataArray::get(LLVMContext ^Context, array<uint32_t> ^Elts)
{
	auto r = gcnew Constant(llvm::ConstantDataArray::get(*Context->base, utils::unmanage_array(Elts)));
	return r;
}
Constant ^ConstantDataArray::get(LLVMContext ^Context, array<uint64_t> ^Elts)
{
	auto r = gcnew Constant(llvm::ConstantDataArray::get(*Context->base, utils::unmanage_array(Elts)));
	return r;
}
Constant ^ConstantDataArray::get(LLVMContext ^Context, array<float> ^Elts)
{
	auto r = gcnew Constant(llvm::ConstantDataArray::get(*Context->base, utils::unmanage_array(Elts)));
	return r;
}
Constant ^ConstantDataArray::get(LLVMContext ^Context, array<double> ^Elts)
{
	auto r = gcnew Constant(llvm::ConstantDataArray::get(*Context->base, utils::unmanage_array(Elts)));
	return r;
}
Constant ^ConstantDataArray::getString(LLVMContext ^Context, System::String ^Initializer)
{
	msclr::interop::marshal_context ctx;
	return gcnew Constant(llvm::ConstantDataArray::getString(*Context->base, ctx.marshal_as<const char *>(Initializer)));
}
Constant ^ConstantDataArray::getString(LLVMContext ^Context, System::String ^Initializer, bool AddNull)
{
	msclr::interop::marshal_context ctx;
	return gcnew Constant(llvm::ConstantDataArray::getString(*Context->base, ctx.marshal_as<const char *>(Initializer), AddNull));
}
inline ArrayType ^ConstantDataArray::getType()
{
	return gcnew ArrayType(base->getType());
}
bool ConstantDataArray::classof(Value ^V)
{
	return llvm::ConstantDataArray::classof(V->base);
}


ConstantDataVector::ConstantDataVector(llvm::ConstantDataVector *base)
	: base(base)
	, ConstantDataSequential(base)
{
}
ConstantDataVector::!ConstantDataVector()
{
}
ConstantDataVector::~ConstantDataVector()
{
	this->!ConstantDataVector();
}
Constant ^ConstantDataVector::get(LLVMContext ^Context, array<uint8_t> ^Elts)
{
	auto r = gcnew Constant(llvm::ConstantDataVector::get(*Context->base, utils::unmanage_array(Elts)));
	return r;
}
Constant ^ConstantDataVector::get(LLVMContext ^Context, array<uint16_t> ^Elts)
{
	auto r = gcnew Constant(llvm::ConstantDataVector::get(*Context->base, utils::unmanage_array(Elts)));
	return r;
}
Constant ^ConstantDataVector::get(LLVMContext ^Context, array<uint32_t> ^Elts)
{
	auto r = gcnew Constant(llvm::ConstantDataVector::get(*Context->base, utils::unmanage_array(Elts)));
	return r;
}
Constant ^ConstantDataVector::get(LLVMContext ^Context, array<uint64_t> ^Elts)
{
	auto r = gcnew Constant(llvm::ConstantDataVector::get(*Context->base, utils::unmanage_array(Elts)));
	return r;
}
Constant ^ConstantDataVector::get(LLVMContext ^Context, array<float> ^Elts)
{
	auto r = gcnew Constant(llvm::ConstantDataVector::get(*Context->base, utils::unmanage_array(Elts)));
	return r;
}
Constant ^ConstantDataVector::get(LLVMContext ^Context, array<double> ^Elts)
{
	auto r = gcnew Constant(llvm::ConstantDataVector::get(*Context->base, utils::unmanage_array(Elts)));
	return r;
}
Constant ^ConstantDataVector::getSplat(unsigned NumElts, Constant ^Elt)
{
	return gcnew Constant(llvm::ConstantDataVector::getSplat(NumElts, Elt->base));
}
Constant ^ConstantDataVector::getSplatValue()
{
	return gcnew Constant(base->getSplatValue());
}
inline VectorType ^ConstantDataVector::getType()
{
	return gcnew VectorType(base->getType());
}
bool ConstantDataVector::classof(Value ^V)
{
	return llvm::ConstantDataVector::classof(V->base);
}


BlockAddress::BlockAddress(llvm::BlockAddress *base)
	: base(base)
	, Constant(base)
{
}
BlockAddress::!BlockAddress()
{
}
BlockAddress::~BlockAddress()
{
	this->!BlockAddress();
}
BlockAddress ^BlockAddress::get(Function ^F, BasicBlock ^BB)
{
	return gcnew BlockAddress(llvm::BlockAddress::get(F->base, BB->base));
}
BlockAddress ^BlockAddress::get(BasicBlock ^BB)
{
	return gcnew BlockAddress(llvm::BlockAddress::get(BB->base));
}
Function ^BlockAddress::getFunction()
{
	return gcnew Function(base->getFunction());
}
BasicBlock ^BlockAddress::getBasicBlock()
{
	return gcnew BasicBlock(base->getBasicBlock());
}
void BlockAddress::destroyConstant()
{
	base->destroyConstant();
}
void BlockAddress::replaceUsesOfWithOnConstant(Value ^From, Value ^To, Use ^U)
{
	base->replaceUsesOfWithOnConstant(From->base, To->base, U->base);
}
inline bool BlockAddress::classof(Value ^V)
{
	return llvm::BlockAddress::classof(V->base);
}


ConstantExpr::ConstantExpr(llvm::ConstantExpr *base)
	: base(base)
	, Constant(base)
{
}
ConstantExpr::!ConstantExpr()
{
}
ConstantExpr::~ConstantExpr()
{
	this->!ConstantExpr();
}
Constant ^ConstantExpr::getAlignOf(Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getAlignOf(Ty->base));
}
Constant ^ConstantExpr::getSizeOf(Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getSizeOf(Ty->base));
}
Constant ^ConstantExpr::getOffsetOf(StructType ^STy, unsigned FieldNo)
{
	return gcnew Constant(llvm::ConstantExpr::getOffsetOf(STy->base, FieldNo));
}
Constant ^ConstantExpr::getOffsetOf(Type ^Ty, Constant ^FieldNo)
{
	return gcnew Constant(llvm::ConstantExpr::getOffsetOf(Ty->base, FieldNo->base));
}
Constant ^ConstantExpr::getNeg(Constant ^C)
{
	return gcnew Constant(llvm::ConstantExpr::getNeg(C->base));
}
Constant ^ConstantExpr::getNeg(Constant ^C, bool HasNUW)
{
	return gcnew Constant(llvm::ConstantExpr::getNeg(C->base, HasNUW));
}
Constant ^ConstantExpr::getNeg(Constant ^C, bool HasNUW, bool HasNSW)
{
	return gcnew Constant(llvm::ConstantExpr::getNeg(C->base, HasNUW, HasNSW));
}
Constant ^ConstantExpr::getFNeg(Constant ^C)
{
	return gcnew Constant(llvm::ConstantExpr::getFNeg(C->base));
}
Constant ^ConstantExpr::getNot(Constant ^C)
{
	return gcnew Constant(llvm::ConstantExpr::getNot(C->base));
}
Constant ^ConstantExpr::getAdd(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getAdd(C1->base, C2->base));
}
Constant ^ConstantExpr::getAdd(Constant ^C1, Constant ^C2, bool HasNUW)
{
	return gcnew Constant(llvm::ConstantExpr::getAdd(C1->base, C2->base, HasNUW));
}
Constant ^ConstantExpr::getAdd(Constant ^C1, Constant ^C2, bool HasNUW, bool HasNSW)
{
	return gcnew Constant(llvm::ConstantExpr::getAdd(C1->base, C2->base, HasNUW, HasNSW));
}
Constant ^ConstantExpr::getFAdd(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getFAdd(C1->base, C2->base));
}
Constant ^ConstantExpr::getSub(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getSub(C1->base, C2->base));
}
Constant ^ConstantExpr::getSub(Constant ^C1, Constant ^C2, bool HasNUW)
{
	return gcnew Constant(llvm::ConstantExpr::getSub(C1->base, C2->base, HasNUW));
}
Constant ^ConstantExpr::getSub(Constant ^C1, Constant ^C2, bool HasNUW, bool HasNSW)
{
	return gcnew Constant(llvm::ConstantExpr::getSub(C1->base, C2->base, HasNUW, HasNSW));
}
Constant ^ConstantExpr::getFSub(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getFSub(C1->base, C2->base));
}
Constant ^ConstantExpr::getMul(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getMul(C1->base, C2->base));
}
Constant ^ConstantExpr::getMul(Constant ^C1, Constant ^C2, bool HasNUW)
{
	return gcnew Constant(llvm::ConstantExpr::getMul(C1->base, C2->base, HasNUW));
}
Constant ^ConstantExpr::getMul(Constant ^C1, Constant ^C2, bool HasNUW, bool HasNSW)
{
	return gcnew Constant(llvm::ConstantExpr::getMul(C1->base, C2->base, HasNUW, HasNSW));
}
Constant ^ConstantExpr::getFMul(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getFMul(C1->base, C2->base));
}
Constant ^ConstantExpr::getUDiv(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getUDiv(C1->base, C2->base));
}
Constant ^ConstantExpr::getUDiv(Constant ^C1, Constant ^C2, bool isExact)
{
	return gcnew Constant(llvm::ConstantExpr::getUDiv(C1->base, C2->base, isExact));
}
Constant ^ConstantExpr::getSDiv(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getSDiv(C1->base, C2->base));
}
Constant ^ConstantExpr::getSDiv(Constant ^C1, Constant ^C2, bool isExact)
{
	return gcnew Constant(llvm::ConstantExpr::getSDiv(C1->base, C2->base, isExact));
}
Constant ^ConstantExpr::getFDiv(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getFDiv(C1->base, C2->base));
}
Constant ^ConstantExpr::getURem(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getURem(C1->base, C2->base));
}
Constant ^ConstantExpr::getSRem(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getSRem(C1->base, C2->base));
}
Constant ^ConstantExpr::getFRem(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getFRem(C1->base, C2->base));
}
Constant ^ConstantExpr::getAnd(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getAnd(C1->base, C2->base));
}
Constant ^ConstantExpr::getOr(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getOr(C1->base, C2->base));
}
Constant ^ConstantExpr::getXor(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getXor(C1->base, C2->base));
}
Constant ^ConstantExpr::getShl(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getShl(C1->base, C2->base));
}
Constant ^ConstantExpr::getShl(Constant ^C1, Constant ^C2, bool HasNUW)
{
	return gcnew Constant(llvm::ConstantExpr::getShl(C1->base, C2->base, HasNUW));
}
Constant ^ConstantExpr::getShl(Constant ^C1, Constant ^C2, bool HasNUW, bool HasNSW)
{
	return gcnew Constant(llvm::ConstantExpr::getShl(C1->base, C2->base, HasNUW, HasNSW));
}
Constant ^ConstantExpr::getLShr(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getLShr(C1->base, C2->base));
}
Constant ^ConstantExpr::getLShr(Constant ^C1, Constant ^C2, bool isExact)
{
	return gcnew Constant(llvm::ConstantExpr::getLShr(C1->base, C2->base, isExact));
}
Constant ^ConstantExpr::getAShr(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getAShr(C1->base, C2->base));
}
Constant ^ConstantExpr::getAShr(Constant ^C1, Constant ^C2, bool isExact)
{
	return gcnew Constant(llvm::ConstantExpr::getAShr(C1->base, C2->base, isExact));
}
Constant ^ConstantExpr::getTrunc(Constant ^C, Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getTrunc(C->base, Ty->base));
}
Constant ^ConstantExpr::getSExt(Constant ^C, Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getSExt(C->base, Ty->base));
}
Constant ^ConstantExpr::getZExt(Constant ^C, Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getZExt(C->base, Ty->base));
}
Constant ^ConstantExpr::getFPTrunc(Constant ^C, Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getFPTrunc(C->base, Ty->base));
}
Constant ^ConstantExpr::getFPExtend(Constant ^C, Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getFPExtend(C->base, Ty->base));
}
Constant ^ConstantExpr::getUIToFP(Constant ^C, Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getUIToFP(C->base, Ty->base));
}
Constant ^ConstantExpr::getSIToFP(Constant ^C, Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getSIToFP(C->base, Ty->base));
}
Constant ^ConstantExpr::getFPToUI(Constant ^C, Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getFPToUI(C->base, Ty->base));
}
Constant ^ConstantExpr::getFPToSI(Constant ^C, Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getFPToSI(C->base, Ty->base));
}
Constant ^ConstantExpr::getPtrToInt(Constant ^C, Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getPtrToInt(C->base, Ty->base));
}
Constant ^ConstantExpr::getIntToPtr(Constant ^C, Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getIntToPtr(C->base, Ty->base));
}
Constant ^ConstantExpr::getBitCast(Constant ^C, Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getBitCast(C->base, Ty->base));
}
Constant ^ConstantExpr::getNSWNeg(Constant ^C)
{
	return gcnew Constant(llvm::ConstantExpr::getNSWNeg(C->base));
}
Constant ^ConstantExpr::getNUWNeg(Constant ^C)
{
	return gcnew Constant(llvm::ConstantExpr::getNUWNeg(C->base));
}
Constant ^ConstantExpr::getNSWAdd(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getNSWAdd(C1->base, C2->base));
}
Constant ^ConstantExpr::getNUWAdd(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getNUWAdd(C1->base, C2->base));
}
Constant ^ConstantExpr::getNSWSub(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getNSWSub(C1->base, C2->base));
}
Constant ^ConstantExpr::getNUWSub(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getNUWSub(C1->base, C2->base));
}
Constant ^ConstantExpr::getNSWMul(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getNSWMul(C1->base, C2->base));
}
Constant ^ConstantExpr::getNUWMul(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getNUWMul(C1->base, C2->base));
}
Constant ^ConstantExpr::getNSWShl(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getNSWShl(C1->base, C2->base));
}
Constant ^ConstantExpr::getNUWShl(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getNUWShl(C1->base, C2->base));
}
Constant ^ConstantExpr::getExactSDiv(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getExactSDiv(C1->base, C2->base));
}
Constant ^ConstantExpr::getExactUDiv(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getExactUDiv(C1->base, C2->base));
}
Constant ^ConstantExpr::getExactAShr(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getExactAShr(C1->base, C2->base));
}
Constant ^ConstantExpr::getExactLShr(Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getExactLShr(C1->base, C2->base));
}
Constant ^ConstantExpr::getBinOpIdentity(unsigned Opcode, Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getBinOpIdentity(Opcode, Ty->base));
}
Constant ^ConstantExpr::getBinOpAbsorber(unsigned Opcode, Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getBinOpAbsorber(Opcode, Ty->base));
}
Constant ^ConstantExpr::getCast(unsigned ops, Constant ^C, Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getCast(ops, C->base, Ty->base));
}
Constant ^ConstantExpr::getZExtOrBitCast(Constant ^C, Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getZExtOrBitCast(C->base, Ty->base));
}
Constant ^ConstantExpr::getSExtOrBitCast(Constant ^C, Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getSExtOrBitCast(C->base, Ty->base));
}
Constant ^ConstantExpr::getTruncOrBitCast(Constant ^C, Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getTruncOrBitCast(C->base, Ty->base));
}
Constant ^ConstantExpr::getPointerCast(Constant ^C, Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getPointerCast(C->base, Ty->base));
}
Constant ^ConstantExpr::getIntegerCast(Constant ^C, Type ^Ty, bool isSigned)
{
	return gcnew Constant(llvm::ConstantExpr::getIntegerCast(C->base, Ty->base, isSigned));
}
Constant ^ConstantExpr::getFPCast(Constant ^C, Type ^Ty)
{
	return gcnew Constant(llvm::ConstantExpr::getFPCast(C->base, Ty->base));
}
bool ConstantExpr::isCast()
{
	return base->isCast();
}
bool ConstantExpr::isCompare()
{
	return base->isCompare();
}
bool ConstantExpr::hasIndices()
{
	return base->hasIndices();
}
bool ConstantExpr::isGEPWithNoNotionalOverIndexing()
{
	return base->isGEPWithNoNotionalOverIndexing();
}
Constant ^ConstantExpr::getSelect(Constant ^C, Constant ^V1, Constant ^V2)
{
	return gcnew Constant(llvm::ConstantExpr::getSelect(C->base, V1->base, V2->base));
}
Constant ^ConstantExpr::get(unsigned Opcode, Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::get(Opcode, C1->base, C2->base));
}
Constant ^ConstantExpr::get(unsigned Opcode, Constant ^C1, Constant ^C2, unsigned Flags)
{
	return gcnew Constant(llvm::ConstantExpr::get(Opcode, C1->base, C2->base, Flags));
}
Constant ^ConstantExpr::getCompare(unsigned short pred, Constant ^C1, Constant ^C2)
{
	return gcnew Constant(llvm::ConstantExpr::getCompare(pred, C1->base, C2->base));
}
Constant ^ConstantExpr::getICmp(unsigned short pred, Constant ^LHS, Constant ^RHS)
{
	return gcnew Constant(llvm::ConstantExpr::getICmp(pred, LHS->base, RHS->base));
}
Constant ^ConstantExpr::getFCmp(unsigned short pred, Constant ^LHS, Constant ^RHS)
{
	return gcnew Constant(llvm::ConstantExpr::getFCmp(pred, LHS->base, RHS->base));
}
Constant ^ConstantExpr::getGetElementPtr(Constant ^C, array<Constant ^> ^IdxList)
{
	llvm::Constant **b = new llvm::Constant*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Constant*> brr(b, IdxList->Length);
	auto r = gcnew Constant(llvm::ConstantExpr::getGetElementPtr(C->base, brr));
	delete b;
	return r;
}
Constant ^ConstantExpr::getGetElementPtr(Constant ^C, array<Constant ^> ^IdxList, bool InBounds)
{
	llvm::Constant **b = new llvm::Constant*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Constant*> brr(b, IdxList->Length);
	auto r = gcnew Constant(llvm::ConstantExpr::getGetElementPtr(C->base, brr, InBounds));
	delete b;
	return r;
}
Constant ^ConstantExpr::getGetElementPtr(Constant ^C, Constant ^Idx)
{
	return gcnew Constant(llvm::ConstantExpr::getGetElementPtr(C->base, Idx->base));
}
Constant ^ConstantExpr::getGetElementPtr(Constant ^C, Constant ^Idx, bool InBounds)
{
	return gcnew Constant(llvm::ConstantExpr::getGetElementPtr(C->base, Idx->base, InBounds));
}
Constant ^ConstantExpr::getGetElementPtr(Constant ^C, array<Value ^> ^IdxList)
{
	llvm::Value **b = new llvm::Value*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, IdxList->Length);
	auto r = gcnew Constant(llvm::ConstantExpr::getGetElementPtr(C->base, brr));
	delete b;
	return r;
}
Constant ^ConstantExpr::getGetElementPtr(Constant ^C, array<Value ^> ^IdxList, bool InBounds)
{
	llvm::Value **b = new llvm::Value*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, IdxList->Length);
	auto r = gcnew Constant(llvm::ConstantExpr::getGetElementPtr(C->base, brr, InBounds));
	delete b;
	return r;
}
Constant ^ConstantExpr::getInBoundsGetElementPtr(Constant ^C, array<Constant ^> ^IdxList)
{
	llvm::Constant **b = new llvm::Constant*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Constant*> brr(b, IdxList->Length);
	auto r = gcnew Constant(llvm::ConstantExpr::getInBoundsGetElementPtr(C->base, brr));
	delete b;
	return r;
}
Constant ^ConstantExpr::getInBoundsGetElementPtr(Constant ^C, Constant ^Idx)
{
	return gcnew Constant(llvm::ConstantExpr::getInBoundsGetElementPtr(C->base, Idx->base));
}
Constant ^ConstantExpr::getInBoundsGetElementPtr(Constant ^C, array<Value ^> ^IdxList)
{
	llvm::Value **b = new llvm::Value*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, IdxList->Length);
	auto r = gcnew Constant(llvm::ConstantExpr::getInBoundsGetElementPtr(C->base, brr));
	delete b;
	return r;
}
Constant ^ConstantExpr::getExtractElement(Constant ^Vec, Constant ^Idx)
{
	return gcnew Constant(llvm::ConstantExpr::getExtractElement(Vec->base, Idx->base));
}
Constant ^ConstantExpr::getInsertElement(Constant ^Vec, Constant ^Elt, Constant ^Idx)
{
	return gcnew Constant(llvm::ConstantExpr::getInsertElement(Vec->base, Elt->base, Idx->base));
}
Constant ^ConstantExpr::getShuffleVector(Constant ^V1, Constant ^V2, Constant ^Mask)
{
	return gcnew Constant(llvm::ConstantExpr::getShuffleVector(V1->base, V2->base, Mask->base));
}
Constant ^ConstantExpr::getExtractValue(Constant ^Agg, array<unsigned> ^Idxs)
{
	auto r = gcnew Constant(llvm::ConstantExpr::getExtractValue(Agg->base, utils::unmanage_array(Idxs)));
	return r;
}
Constant ^ConstantExpr::getInsertValue(Constant ^Agg, Constant ^Val, array<unsigned> ^Idxs)
{
	auto r = gcnew Constant(llvm::ConstantExpr::getInsertValue(Agg->base, Val->base, utils::unmanage_array(Idxs)));
	return r;
}
unsigned ConstantExpr::getOpcode()
{
	return base->getOpcode();
}
unsigned ConstantExpr::getPredicate()
{
	return base->getPredicate();
}
array<unsigned> ^ConstantExpr::getIndices()
{
	auto r = base->getIndices();
	array<unsigned> ^s = gcnew array<unsigned>(r.size());
	for (int i = 0; i < s->Length; i++)
		s[i] = r[i];
	return s;
}
System::String ^ConstantExpr::getOpcodeName()
{
	return utils::manage_str(base->getOpcodeName());
}
Constant ^ConstantExpr::getWithOperandReplaced(unsigned OpNo, Constant ^Op)
{
	return gcnew Constant(base->getWithOperandReplaced(OpNo, Op->base));
}
Constant ^ConstantExpr::getWithOperands(array<Constant ^> ^Ops)
{
	llvm::Constant **b = new llvm::Constant*[Ops->Length];
	for (int i = 0; i < Ops->Length; i++)
		b[i] = Ops[i]->base;
	llvm::ArrayRef<llvm::Constant*> brr(b, Ops->Length);
	auto r = gcnew Constant(base->getWithOperands(brr));
	delete b;
	return r;
}
Constant ^ConstantExpr::getWithOperands(array<Constant ^> ^Ops, Type ^Ty)
{
	llvm::Constant **b = new llvm::Constant*[Ops->Length];
	for (int i = 0; i < Ops->Length; i++)
		b[i] = Ops[i]->base;
	llvm::ArrayRef<llvm::Constant*> brr(b, Ops->Length);
	auto r = gcnew Constant(base->getWithOperands(brr, Ty->base));
	delete b;
	return r;
}
Instruction ^ConstantExpr::getAsInstruction()
{
	return gcnew Instruction(base->getAsInstruction());
}
void ConstantExpr::destroyConstant()
{
	base->destroyConstant();
}
void ConstantExpr::replaceUsesOfWithOnConstant(Value ^From, Value ^To, Use ^U)
{
	base->replaceUsesOfWithOnConstant(From->base, To->base, U->base);
}
inline bool ConstantExpr::classof(Value ^V)
{
	return llvm::ConstantExpr::classof(V->base);
}


UndefValue::UndefValue(llvm::UndefValue *base)
	: base(base)
	, Constant(base)
{
}
UndefValue::!UndefValue()
{
}
UndefValue::~UndefValue()
{
	this->!UndefValue();
}
UndefValue ^UndefValue::get(Type ^T)
{
	return gcnew UndefValue(llvm::UndefValue::get(T->base));
}
UndefValue ^UndefValue::getSequentialElement()
{
	return gcnew UndefValue(base->getSequentialElement());
}
UndefValue ^UndefValue::getStructElement(unsigned Elt)
{
	return gcnew UndefValue(base->getStructElement(Elt));
}
UndefValue ^UndefValue::getElementValue(Constant ^C)
{
	return gcnew UndefValue(base->getElementValue(C->base));
}
UndefValue ^UndefValue::getElementValue(unsigned Idx)
{
	return gcnew UndefValue(base->getElementValue(Idx));
}
void UndefValue::destroyConstant()
{
	base->destroyConstant();
}
bool UndefValue::classof(Value ^V)
{
	return llvm::UndefValue::classof(V->base);
}
