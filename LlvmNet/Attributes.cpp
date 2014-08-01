#include "Attributes.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/ArrayRef.h"
#include "LLVMContext.h"
#include "Attributes.h"
#include <msclr/marshal.h>
#include "utils.h"

using namespace LLVM;

Attribute::Attribute(llvm::Attribute *base)
	: base(base)
	, constructed(false)
{
}
inline Attribute ^Attribute::_wrap(llvm::Attribute *base)
{
	return base ? gcnew Attribute(base) : nullptr;
}
Attribute::!Attribute()
{
	if (constructed)
	{
		delete base;
	}
}
Attribute::~Attribute()
{
	this->!Attribute();
}
Attribute::Attribute()
	: base(new llvm::Attribute())
	, constructed(true)
{
}
Attribute ^Attribute::get(LLVMContext ^Context, AttrKind Kind)
{
	return Attribute::_wrap(&llvm::Attribute::get(*Context->base, safe_cast<llvm::Attribute::AttrKind>(Kind)));
}
Attribute ^Attribute::get(LLVMContext ^Context, AttrKind Kind, uint64_t Val)
{
	return Attribute::_wrap(&llvm::Attribute::get(*Context->base, safe_cast<llvm::Attribute::AttrKind>(Kind), Val));
}
Attribute ^Attribute::get(LLVMContext ^Context, System::String ^Kind)
{
	msclr::interop::marshal_context ctx;
	return Attribute::_wrap(&llvm::Attribute::get(*Context->base, ctx.marshal_as<const char *>(Kind)));
}
Attribute ^Attribute::get(LLVMContext ^Context, System::String ^Kind, System::String ^Val)
{
	msclr::interop::marshal_context ctx;
	return Attribute::_wrap(&llvm::Attribute::get(*Context->base, ctx.marshal_as<const char *>(Kind), ctx.marshal_as<const char *>(Val)));
}
Attribute ^Attribute::getWithAlignment(LLVMContext ^Context, uint64_t Align)
{
	return Attribute::_wrap(&llvm::Attribute::getWithAlignment(*Context->base, Align));
}
Attribute ^Attribute::getWithStackAlignment(LLVMContext ^Context, uint64_t Align)
{
	return Attribute::_wrap(&llvm::Attribute::getWithStackAlignment(*Context->base, Align));
}
bool Attribute::isEnumAttribute()
{
	return base->isEnumAttribute();
}
bool Attribute::isAlignAttribute()
{
	return base->isAlignAttribute();
}
bool Attribute::isStringAttribute()
{
	return base->isStringAttribute();
}
bool Attribute::hasAttribute(AttrKind Val)
{
	return base->hasAttribute(safe_cast<llvm::Attribute::AttrKind>(Val));
}
bool Attribute::hasAttribute(System::String ^Val)
{
	msclr::interop::marshal_context ctx;
	return base->hasAttribute(ctx.marshal_as<const char *>(Val));
}
Attribute::AttrKind Attribute::getKindAsEnum()
{
	return safe_cast<Attribute::AttrKind>(base->getKindAsEnum());
}
uint64_t Attribute::getValueAsInt()
{
	return base->getValueAsInt();
}
System::String ^Attribute::getKindAsString()
{
	return utils::manage_str(base->getKindAsString());
}
System::String ^Attribute::getValueAsString()
{
	return utils::manage_str(base->getValueAsString());
}
unsigned Attribute::getAlignment()
{
	return base->getAlignment();
}
unsigned Attribute::getStackAlignment()
{
	return base->getStackAlignment();
}
System::String ^Attribute::getAsString()
{
	return utils::manage_str(base->getAsString());
}
System::String ^Attribute::getAsString(bool InAttrGrp)
{
	return utils::manage_str(base->getAsString(InAttrGrp));
}


AttributeSet::AttributeSet(llvm::AttributeSet *base)
	: base(base)
	, constructed(false)
{
}
inline AttributeSet ^AttributeSet::_wrap(llvm::AttributeSet *base)
{
	return base ? gcnew AttributeSet(base) : nullptr;
}
AttributeSet::!AttributeSet()
{
	if (constructed)
	{
		delete base;
	}
}
AttributeSet::~AttributeSet()
{
	this->!AttributeSet();
}
AttributeSet::AttributeSet()
	: base(new llvm::AttributeSet())
	, constructed(true)
{
}
AttributeSet ^AttributeSet::get(LLVMContext ^C, array<AttributeSet ^> ^Attrs)
{
	llvm::AttributeSet *b = new llvm::AttributeSet[Attrs->Length];
	for (int i = 0; i < Attrs->Length; i++)
		b[i] = *Attrs[i]->base;
	llvm::ArrayRef<llvm::AttributeSet> brr(b, Attrs->Length);
	auto r = AttributeSet::_wrap(&llvm::AttributeSet::get(*C->base, brr));
	delete b;
	return r;
}
AttributeSet ^AttributeSet::get(LLVMContext ^C, unsigned Index, array<Attribute::AttrKind> ^Kind)
{
	llvm::Attribute::AttrKind *b = new llvm::Attribute::AttrKind[Kind->Length];
	for (int i = 0; i < Kind->Length; i++)
		b[i] = safe_cast<llvm::Attribute::AttrKind>(Kind[i]);
	llvm::ArrayRef<llvm::Attribute::AttrKind> brr(b, Kind->Length);
	auto r = AttributeSet::_wrap(&llvm::AttributeSet::get(*C->base, Index, brr));
	delete b;
	return r;
}
AttributeSet ^AttributeSet::get(LLVMContext ^C, unsigned Index, AttrBuilder ^B)
{
	return AttributeSet::_wrap(&llvm::AttributeSet::get(*C->base, Index, *B->base));
}
AttributeSet ^AttributeSet::addAttribute(LLVMContext ^C, unsigned Index, Attribute::AttrKind Attr)
{
	return AttributeSet::_wrap(&base->addAttribute(*C->base, Index, safe_cast<llvm::Attribute::AttrKind>(Attr)));
}
AttributeSet ^AttributeSet::addAttribute(LLVMContext ^C, unsigned Index, System::String ^Kind)
{
	msclr::interop::marshal_context ctx;
	return AttributeSet::_wrap(&base->addAttribute(*C->base, Index, ctx.marshal_as<const char *>(Kind)));
}
AttributeSet ^AttributeSet::addAttributes(LLVMContext ^C, unsigned Index, AttributeSet ^Attrs)
{
	return AttributeSet::_wrap(&base->addAttributes(*C->base, Index, *Attrs->base));
}
AttributeSet ^AttributeSet::removeAttribute(LLVMContext ^C, unsigned Index, Attribute::AttrKind Attr)
{
	return AttributeSet::_wrap(&base->removeAttribute(*C->base, Index, safe_cast<llvm::Attribute::AttrKind>(Attr)));
}
AttributeSet ^AttributeSet::removeAttributes(LLVMContext ^C, unsigned Index, AttributeSet ^Attrs)
{
	return AttributeSet::_wrap(&base->removeAttributes(*C->base, Index, *Attrs->base));
}
LLVMContext ^AttributeSet::getContext()
{
	return LLVMContext::_wrap(&base->getContext());
}
AttributeSet ^AttributeSet::getParamAttributes(unsigned Index)
{
	return AttributeSet::_wrap(&base->getParamAttributes(Index));
}
AttributeSet ^AttributeSet::getRetAttributes()
{
	return AttributeSet::_wrap(&base->getRetAttributes());
}
AttributeSet ^AttributeSet::getFnAttributes()
{
	return AttributeSet::_wrap(&base->getFnAttributes());
}
bool AttributeSet::hasAttribute(unsigned Index, Attribute::AttrKind Kind)
{
	return base->hasAttribute(Index, safe_cast<llvm::Attribute::AttrKind>(Kind));
}
bool AttributeSet::hasAttribute(unsigned Index, System::String ^Kind)
{
	msclr::interop::marshal_context ctx;
	return base->hasAttribute(Index, ctx.marshal_as<const char *>(Kind));
}
bool AttributeSet::hasAttributes(unsigned Index)
{
	return base->hasAttributes(Index);
}
bool AttributeSet::hasAttrSomewhere(Attribute::AttrKind Attr)
{
	return base->hasAttrSomewhere(safe_cast<llvm::Attribute::AttrKind>(Attr));
}
Attribute ^AttributeSet::getAttribute(unsigned Index, Attribute::AttrKind Kind)
{
	return Attribute::_wrap(&base->getAttribute(Index, safe_cast<llvm::Attribute::AttrKind>(Kind)));
}
Attribute ^AttributeSet::getAttribute(unsigned Index, System::String ^Kind)
{
	msclr::interop::marshal_context ctx;
	return Attribute::_wrap(&base->getAttribute(Index, ctx.marshal_as<const char *>(Kind)));
}
unsigned AttributeSet::getParamAlignment(unsigned Index)
{
	return base->getParamAlignment(Index);
}
unsigned AttributeSet::getStackAlignment(unsigned Index)
{
	return base->getStackAlignment(Index);
}
System::String ^AttributeSet::getAsString(unsigned Index)
{
	return utils::manage_str(base->getAsString(Index));
}
System::String ^AttributeSet::getAsString(unsigned Index, bool InAttrGrp)
{
	return utils::manage_str(base->getAsString(Index, InAttrGrp));
}
uint64_t AttributeSet::Raw(unsigned Index)
{
	return base->Raw(Index);
}
void *AttributeSet::getRawPointer()
{
	return base->getRawPointer();
}
bool AttributeSet::isEmpty()
{
	return base->isEmpty();
}
unsigned AttributeSet::getNumSlots()
{
	return base->getNumSlots();
}
unsigned AttributeSet::getSlotIndex(unsigned Slot)
{
	return base->getSlotIndex(Slot);
}
AttributeSet ^AttributeSet::getSlotAttributes(unsigned Slot)
{
	return AttributeSet::_wrap(&base->getSlotAttributes(Slot));
}
void AttributeSet::dump()
{
	base->dump();
}


AttrBuilder::AttrBuilder(llvm::AttrBuilder *base)
	: base(base)
	, constructed(false)
{
}
inline AttrBuilder ^AttrBuilder::_wrap(llvm::AttrBuilder *base)
{
	return base ? gcnew AttrBuilder(base) : nullptr;
}
AttrBuilder::!AttrBuilder()
{
	if (constructed)
	{
		delete base;
	}
}
AttrBuilder::~AttrBuilder()
{
	this->!AttrBuilder();
}
AttrBuilder::AttrBuilder()
	: base(new llvm::AttrBuilder())
	, constructed(true)
{
}
AttrBuilder::AttrBuilder(uint64_t Val)
	: base(new llvm::AttrBuilder(Val))
	, constructed(true)
{
}
AttrBuilder::AttrBuilder(Attribute ^A)
	: base(new llvm::AttrBuilder(*A->base))
	, constructed(true)
{
}
AttrBuilder::AttrBuilder(AttributeSet ^AS, unsigned Idx)
	: base(new llvm::AttrBuilder(*AS->base, Idx))
	, constructed(true)
{
}
AttrBuilder::AttrBuilder(AttrBuilder ^B)
	: base(new llvm::AttrBuilder(*B->base))
	, constructed(true)
{
}
void AttrBuilder::clear()
{
	base->clear();
}
AttrBuilder ^AttrBuilder::addAttribute(Attribute::AttrKind Val)
{
	return AttrBuilder::_wrap(&base->addAttribute(safe_cast<llvm::Attribute::AttrKind>(Val)));
}
AttrBuilder ^AttrBuilder::addAttribute(Attribute ^A)
{
	return AttrBuilder::_wrap(&base->addAttribute(*A->base));
}
AttrBuilder ^AttrBuilder::addAttribute(System::String ^A)
{
	msclr::interop::marshal_context ctx;
	return AttrBuilder::_wrap(&base->addAttribute(ctx.marshal_as<const char *>(A)));
}
AttrBuilder ^AttrBuilder::addAttribute(System::String ^A, System::String ^V)
{
	msclr::interop::marshal_context ctx;
	return AttrBuilder::_wrap(&base->addAttribute(ctx.marshal_as<const char *>(A), ctx.marshal_as<const char *>(V)));
}
AttrBuilder ^AttrBuilder::removeAttribute(Attribute::AttrKind Val)
{
	return AttrBuilder::_wrap(&base->removeAttribute(safe_cast<llvm::Attribute::AttrKind>(Val)));
}
AttrBuilder ^AttrBuilder::removeAttributes(AttributeSet ^A, uint64_t Index)
{
	return AttrBuilder::_wrap(&base->removeAttributes(*A->base, Index));
}
AttrBuilder ^AttrBuilder::removeAttribute(System::String ^A)
{
	msclr::interop::marshal_context ctx;
	return AttrBuilder::_wrap(&base->removeAttribute(ctx.marshal_as<const char *>(A)));
}
AttrBuilder ^AttrBuilder::merge(AttrBuilder ^B)
{
	return AttrBuilder::_wrap(&base->merge(*B->base));
}
bool AttrBuilder::contains(Attribute::AttrKind A)
{
	return base->contains(safe_cast<llvm::Attribute::AttrKind>(A));
}
bool AttrBuilder::contains(System::String ^A)
{
	msclr::interop::marshal_context ctx;
	return base->contains(ctx.marshal_as<const char *>(A));
}
bool AttrBuilder::hasAttributes()
{
	return base->hasAttributes();
}
bool AttrBuilder::hasAttributes(AttributeSet ^A, uint64_t Index)
{
	return base->hasAttributes(*A->base, Index);
}
bool AttrBuilder::hasAlignmentAttr()
{
	return base->hasAlignmentAttr();
}
uint64_t AttrBuilder::getAlignment()
{
	return base->getAlignment();
}
uint64_t AttrBuilder::getStackAlignment()
{
	return base->getStackAlignment();
}
AttrBuilder ^AttrBuilder::addAlignmentAttr(unsigned Align)
{
	return AttrBuilder::_wrap(&base->addAlignmentAttr(Align));
}
AttrBuilder ^AttrBuilder::addStackAlignmentAttr(unsigned Align)
{
	return AttrBuilder::_wrap(&base->addStackAlignmentAttr(Align));
}
bool AttrBuilder::empty()
{
	return base->empty();
}
bool AttrBuilder::td_empty()
{
	return base->td_empty();
}
AttrBuilder ^AttrBuilder::addRawValue(uint64_t Val)
{
	return AttrBuilder::_wrap(&base->addRawValue(Val));
}
