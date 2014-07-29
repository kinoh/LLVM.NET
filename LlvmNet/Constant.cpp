#include "Constant.h"
#include "Value.h"
#include "Use.h"
#include "Type.h"

using namespace LLVM;

Constant::Constant(llvm::Constant *base)
	: base(base)
	, User(base)
{
}
Constant::!Constant()
{
}
Constant::~Constant()
{
	this->!Constant();
}
bool Constant::isNullValue()
{
	return base->isNullValue();
}
bool Constant::isAllOnesValue()
{
	return base->isAllOnesValue();
}
bool Constant::isNegativeZeroValue()
{
	return base->isNegativeZeroValue();
}
bool Constant::isZeroValue()
{
	return base->isZeroValue();
}
bool Constant::canTrap()
{
	return base->canTrap();
}
bool Constant::isThreadDependent()
{
	return base->isThreadDependent();
}
bool Constant::isConstantUsed()
{
	return base->isConstantUsed();
}
Constant::PossibleRelocationsTy Constant::getRelocationInfo()
{
	return safe_cast<Constant::PossibleRelocationsTy>(base->getRelocationInfo());
}
Constant ^Constant::getAggregateElement(unsigned Elt)
{
	return gcnew Constant(base->getAggregateElement(Elt));
}
Constant ^Constant::getAggregateElement(Constant ^Elt)
{
	return gcnew Constant(base->getAggregateElement(Elt->base));
}
Constant ^Constant::getSplatValue()
{
	return gcnew Constant(base->getSplatValue());
}
void Constant::destroyConstant()
{
	base->destroyConstant();
}
inline bool Constant::classof(Value ^V)
{
	return llvm::Constant::classof(V->base);
}
void Constant::replaceUsesOfWithOnConstant(Value ^From, Value ^To, Use ^use)
{
	base->replaceUsesOfWithOnConstant(From->base, To->base, use->base);
}
Constant ^Constant::getNullValue(Type ^Ty)
{
	return gcnew Constant(llvm::Constant::getNullValue(Ty->base));
}
Constant ^Constant::getAllOnesValue(Type ^Ty)
{
	return gcnew Constant(llvm::Constant::getAllOnesValue(Ty->base));
}
void Constant::removeDeadConstantUsers()
{
	base->removeDeadConstantUsers();
}
