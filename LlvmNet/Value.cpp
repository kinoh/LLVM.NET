#include "Value.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/StringMap.h"
#include "llvm/ADT/Twine.h"
#include "raw_ostream.h"
#include "AssemblyAnnotationWriter.h"
#include "Type.h"
#include "LLVMContext.h"
#include "User.h"
#include "BasicBlock.h"
#include "Use.h"
#include <msclr/marshal.h>
#include "utils.h"

using namespace LLVM;

Value::Value(llvm::Value *base)
	: base(base)
{
}
Value::!Value()
{
}
Value::~Value()
{
	this->!Value();
}
void Value::dump()
{
	base->dump();
}
void Value::print(raw_ostream ^O)
{
	base->print(*O->base);
}
void Value::print(raw_ostream ^O, AssemblyAnnotationWriter ^AAW)
{
	base->print(*O->base, AAW->base);
}
Type ^Value::getType()
{
	return gcnew Type(base->getType());
}
LLVMContext ^Value::getContext()
{
	return gcnew LLVMContext(&base->getContext());
}
bool Value::hasName()
{
	return base->hasName();
}
ValueName ^Value::getValueName()
{
	auto a = base->getValueName();
	return gcnew ValueName(utils::manage_str(a->getKey()), gcnew Value(a->getValue()));
}
void Value::setValueName(ValueName ^VN)
{
	msclr::interop::marshal_context ctx;
	const char *key = ctx.marshal_as<const char *>(VN->Key);
	auto a = llvm::ValueName::Create(key, key + VN->Key->Length);
	auto value = VN->Value->base;
	a->setValue(value);
	base->setValueName(a);
}
System::String ^Value::getName()
{
	return utils::manage_str(base->getName());
}
void Value::setName(System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	base->setName(ctx.marshal_as<const char *>(Name));
}
void Value::takeName(Value ^V)
{
	base->takeName(V->base);
}
void Value::replaceAllUsesWith(Value ^V)
{
	base->replaceAllUsesWith(V->base);
}
bool Value::use_empty()
{
	return base->use_empty();
}
User ^Value::use_back()
{
	return gcnew User(base->use_back());
}
bool Value::hasOneUse()
{
	return base->hasOneUse();
}
bool Value::hasNUses(unsigned N)
{
	return base->hasNUses(N);
}
bool Value::hasNUsesOrMore(unsigned N)
{
	return base->hasNUsesOrMore(N);
}
bool Value::isUsedInBasicBlock(BasicBlock ^BB)
{
	return base->isUsedInBasicBlock(BB->base);
}
unsigned Value::getNumUses()
{
	return base->getNumUses();
}
void Value::addUse(Use ^U)
{
	base->addUse(*U->base);
}
unsigned Value::getValueID()
{
	return base->getValueID();
}
unsigned Value::getRawSubclassOptionalData()
{
	return base->getRawSubclassOptionalData();
}
void Value::clearSubclassOptionalData()
{
	base->clearSubclassOptionalData();
}
bool Value::hasSameSubclassOptionalData(Value ^V)
{
	return base->hasSameSubclassOptionalData(V->base);
}
void Value::intersectOptionalDataWith(Value ^V)
{
	base->intersectOptionalDataWith(V->base);
}
bool Value::hasValueHandle()
{
	return base->hasValueHandle();
}
Value ^Value::stripPointerCasts()
{
	return gcnew Value(base->stripPointerCasts());
}
Value ^Value::stripPointerCastsNoFollowAliases()
{
	return gcnew Value(base->stripPointerCastsNoFollowAliases());
}
Value ^Value::stripInBoundsConstantOffsets()
{
	return gcnew Value(base->stripInBoundsConstantOffsets());
}
Value ^Value::stripInBoundsOffsets()
{
	return gcnew Value(base->stripInBoundsOffsets());
}
bool Value::isDereferenceablePointer()
{
	return base->isDereferenceablePointer();
}
Value ^Value::DoPHITranslation(BasicBlock ^CurBB, BasicBlock ^PredBB)
{
	return gcnew Value(base->DoPHITranslation(CurBB->base, PredBB->base));
}
void Value::mutateType(Type ^Ty)
{
	base->mutateType(Ty->base);
}
