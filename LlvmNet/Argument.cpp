#include "Argument.h"
#include "llvm/ADT/Twine.h"
#include "Type.h"
#include "Function.h"
#include "Attributes.h"
#include "Value.h"
#include <msclr/marshal.h>

using namespace LLVM;

Argument::Argument(llvm::Argument *base)
	: base(base)
	, Value(base)
	, constructed(false)
{
}
Argument::!Argument()
{
	if (constructed)
	{
		delete base;
	}
}
Argument::~Argument()
{
	this->!Argument();
}
Argument::Argument(Type ^Ty)
	: base(new llvm::Argument(Ty->base))
	, Value(base)
	, constructed(true)
{
}
llvm::Argument *Argument::_construct(Type ^Ty, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return new llvm::Argument(Ty->base, ctx.marshal_as<const char *>(Name));
}
Argument::Argument(Type ^Ty, System::String ^Name)
	: base(_construct(Ty, Name))
	, Value(base)
	, constructed(true)
{
}
llvm::Argument *Argument::_construct(Type ^Ty, System::String ^Name, Function ^F)
{
	msclr::interop::marshal_context ctx;
	return new llvm::Argument(Ty->base, ctx.marshal_as<const char *>(Name), F->base);
}
Argument::Argument(Type ^Ty, System::String ^Name, Function ^F)
	: base(_construct(Ty, Name, F))
	, Value(base)
	, constructed(true)
{
}
inline Function ^Argument::getParent()
{
	return gcnew Function(base->getParent());
}
unsigned Argument::getArgNo()
{
	return base->getArgNo();
}
bool Argument::hasByValAttr()
{
	return base->hasByValAttr();
}
unsigned Argument::getParamAlignment()
{
	return base->getParamAlignment();
}
bool Argument::hasNestAttr()
{
	return base->hasNestAttr();
}
bool Argument::hasNoAliasAttr()
{
	return base->hasNoAliasAttr();
}
bool Argument::hasNoCaptureAttr()
{
	return base->hasNoCaptureAttr();
}
bool Argument::hasStructRetAttr()
{
	return base->hasStructRetAttr();
}
bool Argument::hasReturnedAttr()
{
	return base->hasReturnedAttr();
}
void Argument::addAttr(AttributeSet ^AS)
{
	base->addAttr(*AS->base);
}
void Argument::removeAttr(AttributeSet ^AS)
{
	base->removeAttr(*AS->base);
}
inline bool Argument::classof(Value ^V)
{
	return llvm::Argument::classof(V->base);
}
