#include "Type.h"
#include "llvm/ADT/StringRef.h"
#include "raw_ostream.h"
#include "LLVMContext.h"
#include "DerivedTypes.h"
#include "utils.h"

using namespace LLVM;

Type::Type(llvm::Type *base)
	: base(base)
{
}
Type::!Type()
{
}
Type::~Type()
{
	this->!Type();
}
void Type::print(raw_ostream ^O)
{
	base->print(*O->base);
}
void Type::dump()
{
	base->dump();
}
LLVMContext ^Type::getContext()
{
	return gcnew LLVMContext(&base->getContext());
}
Type::TypeID Type::getTypeID()
{
	return safe_cast<Type::TypeID>(base->getTypeID());
}
bool Type::isVoidTy()
{
	return base->isVoidTy();
}
bool Type::isHalfTy()
{
	return base->isHalfTy();
}
bool Type::isFloatTy()
{
	return base->isFloatTy();
}
bool Type::isDoubleTy()
{
	return base->isDoubleTy();
}
bool Type::isX86_FP80Ty()
{
	return base->isX86_FP80Ty();
}
bool Type::isFP128Ty()
{
	return base->isFP128Ty();
}
bool Type::isPPC_FP128Ty()
{
	return base->isPPC_FP128Ty();
}
bool Type::isFloatingPointTy()
{
	return base->isFloatingPointTy();
}
bool Type::isX86_MMXTy()
{
	return base->isX86_MMXTy();
}
bool Type::isFPOrFPVectorTy()
{
	return base->isFPOrFPVectorTy();
}
bool Type::isLabelTy()
{
	return base->isLabelTy();
}
bool Type::isMetadataTy()
{
	return base->isMetadataTy();
}
bool Type::isIntegerTy()
{
	return base->isIntegerTy();
}
bool Type::isIntegerTy(unsigned Bitwidth)
{
	return base->isIntegerTy(Bitwidth);
}
bool Type::isIntOrIntVectorTy()
{
	return base->isIntOrIntVectorTy();
}
bool Type::isFunctionTy()
{
	return base->isFunctionTy();
}
bool Type::isStructTy()
{
	return base->isStructTy();
}
bool Type::isArrayTy()
{
	return base->isArrayTy();
}
bool Type::isPointerTy()
{
	return base->isPointerTy();
}
bool Type::isPtrOrPtrVectorTy()
{
	return base->isPtrOrPtrVectorTy();
}
bool Type::isVectorTy()
{
	return base->isVectorTy();
}
bool Type::canLosslesslyBitCastTo(Type ^Ty)
{
	return base->canLosslesslyBitCastTo(Ty->base);
}
bool Type::isEmptyTy()
{
	return base->isEmptyTy();
}
bool Type::isPrimitiveType()
{
	return base->isPrimitiveType();
}
bool Type::isDerivedType()
{
	return base->isDerivedType();
}
bool Type::isFirstClassType()
{
	return base->isFirstClassType();
}
bool Type::isSingleValueType()
{
	return base->isSingleValueType();
}
bool Type::isAggregateType()
{
	return base->isAggregateType();
}
bool Type::isSized()
{
	return base->isSized();
}
unsigned Type::getPrimitiveSizeInBits()
{
	return base->getPrimitiveSizeInBits();
}
unsigned Type::getScalarSizeInBits()
{
	return base->getScalarSizeInBits();
}
int Type::getFPMantissaWidth()
{
	return base->getFPMantissaWidth();
}
Type ^Type::getScalarType()
{
	return gcnew Type(base->getScalarType());
}
Type ^Type::getContainedType(unsigned i)
{
	return gcnew Type(base->getContainedType(i));
}
unsigned Type::getNumContainedTypes()
{
	return base->getNumContainedTypes();
}
unsigned Type::getIntegerBitWidth()
{
	return base->getIntegerBitWidth();
}
Type ^Type::getFunctionParamType(unsigned i)
{
	return gcnew Type(base->getFunctionParamType(i));
}
unsigned Type::getFunctionNumParams()
{
	return base->getFunctionNumParams();
}
bool Type::isFunctionVarArg()
{
	return base->isFunctionVarArg();
}
System::String ^Type::getStructName()
{
	return utils::manage_str(base->getStructName());
}
unsigned Type::getStructNumElements()
{
	return base->getStructNumElements();
}
Type ^Type::getStructElementType(unsigned N)
{
	return gcnew Type(base->getStructElementType(N));
}
Type ^Type::getSequentialElementType()
{
	return gcnew Type(base->getSequentialElementType());
}
uint64_t Type::getArrayNumElements()
{
	return base->getArrayNumElements();
}
Type ^Type::getArrayElementType()
{
	return gcnew Type(base->getArrayElementType());
}
unsigned Type::getVectorNumElements()
{
	return base->getVectorNumElements();
}
Type ^Type::getVectorElementType()
{
	return gcnew Type(base->getVectorElementType());
}
Type ^Type::getPointerElementType()
{
	return gcnew Type(base->getPointerElementType());
}
unsigned Type::getPointerAddressSpace()
{
	return base->getPointerAddressSpace();
}
Type ^Type::getPrimitiveType(LLVMContext ^C, TypeID IDNumber)
{
	return gcnew Type(llvm::Type::getPrimitiveType(*C->base, safe_cast<llvm::Type::TypeID>(IDNumber)));
}
Type ^Type::getVoidTy(LLVMContext ^C)
{
	return gcnew Type(llvm::Type::getVoidTy(*C->base));
}
Type ^Type::getLabelTy(LLVMContext ^C)
{
	return gcnew Type(llvm::Type::getLabelTy(*C->base));
}
Type ^Type::getHalfTy(LLVMContext ^C)
{
	return gcnew Type(llvm::Type::getHalfTy(*C->base));
}
Type ^Type::getFloatTy(LLVMContext ^C)
{
	return gcnew Type(llvm::Type::getFloatTy(*C->base));
}
Type ^Type::getDoubleTy(LLVMContext ^C)
{
	return gcnew Type(llvm::Type::getDoubleTy(*C->base));
}
Type ^Type::getMetadataTy(LLVMContext ^C)
{
	return gcnew Type(llvm::Type::getMetadataTy(*C->base));
}
Type ^Type::getX86_FP80Ty(LLVMContext ^C)
{
	return gcnew Type(llvm::Type::getX86_FP80Ty(*C->base));
}
Type ^Type::getFP128Ty(LLVMContext ^C)
{
	return gcnew Type(llvm::Type::getFP128Ty(*C->base));
}
Type ^Type::getPPC_FP128Ty(LLVMContext ^C)
{
	return gcnew Type(llvm::Type::getPPC_FP128Ty(*C->base));
}
Type ^Type::getX86_MMXTy(LLVMContext ^C)
{
	return gcnew Type(llvm::Type::getX86_MMXTy(*C->base));
}
IntegerType ^Type::getIntNTy(LLVMContext ^C, unsigned N)
{
	return gcnew IntegerType(llvm::Type::getIntNTy(*C->base, N));
}
IntegerType ^Type::getInt1Ty(LLVMContext ^C)
{
	return gcnew IntegerType(llvm::Type::getInt1Ty(*C->base));
}
IntegerType ^Type::getInt8Ty(LLVMContext ^C)
{
	return gcnew IntegerType(llvm::Type::getInt8Ty(*C->base));
}
IntegerType ^Type::getInt16Ty(LLVMContext ^C)
{
	return gcnew IntegerType(llvm::Type::getInt16Ty(*C->base));
}
IntegerType ^Type::getInt32Ty(LLVMContext ^C)
{
	return gcnew IntegerType(llvm::Type::getInt32Ty(*C->base));
}
IntegerType ^Type::getInt64Ty(LLVMContext ^C)
{
	return gcnew IntegerType(llvm::Type::getInt64Ty(*C->base));
}
PointerType ^Type::getHalfPtrTy(LLVMContext ^C)
{
	return gcnew PointerType(llvm::Type::getHalfPtrTy(*C->base));
}
PointerType ^Type::getHalfPtrTy(LLVMContext ^C, unsigned AS)
{
	return gcnew PointerType(llvm::Type::getHalfPtrTy(*C->base, AS));
}
PointerType ^Type::getFloatPtrTy(LLVMContext ^C)
{
	return gcnew PointerType(llvm::Type::getFloatPtrTy(*C->base));
}
PointerType ^Type::getFloatPtrTy(LLVMContext ^C, unsigned AS)
{
	return gcnew PointerType(llvm::Type::getFloatPtrTy(*C->base, AS));
}
PointerType ^Type::getDoublePtrTy(LLVMContext ^C)
{
	return gcnew PointerType(llvm::Type::getDoublePtrTy(*C->base));
}
PointerType ^Type::getDoublePtrTy(LLVMContext ^C, unsigned AS)
{
	return gcnew PointerType(llvm::Type::getDoublePtrTy(*C->base, AS));
}
PointerType ^Type::getX86_FP80PtrTy(LLVMContext ^C)
{
	return gcnew PointerType(llvm::Type::getX86_FP80PtrTy(*C->base));
}
PointerType ^Type::getX86_FP80PtrTy(LLVMContext ^C, unsigned AS)
{
	return gcnew PointerType(llvm::Type::getX86_FP80PtrTy(*C->base, AS));
}
PointerType ^Type::getFP128PtrTy(LLVMContext ^C)
{
	return gcnew PointerType(llvm::Type::getFP128PtrTy(*C->base));
}
PointerType ^Type::getFP128PtrTy(LLVMContext ^C, unsigned AS)
{
	return gcnew PointerType(llvm::Type::getFP128PtrTy(*C->base, AS));
}
PointerType ^Type::getPPC_FP128PtrTy(LLVMContext ^C)
{
	return gcnew PointerType(llvm::Type::getPPC_FP128PtrTy(*C->base));
}
PointerType ^Type::getPPC_FP128PtrTy(LLVMContext ^C, unsigned AS)
{
	return gcnew PointerType(llvm::Type::getPPC_FP128PtrTy(*C->base, AS));
}
PointerType ^Type::getX86_MMXPtrTy(LLVMContext ^C)
{
	return gcnew PointerType(llvm::Type::getX86_MMXPtrTy(*C->base));
}
PointerType ^Type::getX86_MMXPtrTy(LLVMContext ^C, unsigned AS)
{
	return gcnew PointerType(llvm::Type::getX86_MMXPtrTy(*C->base, AS));
}
PointerType ^Type::getIntNPtrTy(LLVMContext ^C, unsigned N)
{
	return gcnew PointerType(llvm::Type::getIntNPtrTy(*C->base, N));
}
PointerType ^Type::getIntNPtrTy(LLVMContext ^C, unsigned N, unsigned AS)
{
	return gcnew PointerType(llvm::Type::getIntNPtrTy(*C->base, N, AS));
}
PointerType ^Type::getInt1PtrTy(LLVMContext ^C)
{
	return gcnew PointerType(llvm::Type::getInt1PtrTy(*C->base));
}
PointerType ^Type::getInt1PtrTy(LLVMContext ^C, unsigned AS)
{
	return gcnew PointerType(llvm::Type::getInt1PtrTy(*C->base, AS));
}
PointerType ^Type::getInt8PtrTy(LLVMContext ^C)
{
	return gcnew PointerType(llvm::Type::getInt8PtrTy(*C->base));
}
PointerType ^Type::getInt8PtrTy(LLVMContext ^C, unsigned AS)
{
	return gcnew PointerType(llvm::Type::getInt8PtrTy(*C->base, AS));
}
PointerType ^Type::getInt16PtrTy(LLVMContext ^C)
{
	return gcnew PointerType(llvm::Type::getInt16PtrTy(*C->base));
}
PointerType ^Type::getInt16PtrTy(LLVMContext ^C, unsigned AS)
{
	return gcnew PointerType(llvm::Type::getInt16PtrTy(*C->base, AS));
}
PointerType ^Type::getInt32PtrTy(LLVMContext ^C)
{
	return gcnew PointerType(llvm::Type::getInt32PtrTy(*C->base));
}
PointerType ^Type::getInt32PtrTy(LLVMContext ^C, unsigned AS)
{
	return gcnew PointerType(llvm::Type::getInt32PtrTy(*C->base, AS));
}
PointerType ^Type::getInt64PtrTy(LLVMContext ^C)
{
	return gcnew PointerType(llvm::Type::getInt64PtrTy(*C->base));
}
PointerType ^Type::getInt64PtrTy(LLVMContext ^C, unsigned AS)
{
	return gcnew PointerType(llvm::Type::getInt64PtrTy(*C->base, AS));
}
PointerType ^Type::getPointerTo()
{
	return gcnew PointerType(base->getPointerTo());
}
PointerType ^Type::getPointerTo(unsigned AddrSpace)
{
	return gcnew PointerType(base->getPointerTo(AddrSpace));
}
