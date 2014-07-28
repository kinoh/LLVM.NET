#include "User.h"
#include "Value.h"
#include "Use.h"

using namespace LLVM;

User::User(llvm::User *base)
	: base(base)
	, Value(base)
{
}
User::!User()
{
}
User::~User()
{
	this->!User();
}
Value ^User::getOperand(unsigned i)
{
	return gcnew Value(base->getOperand(i));
}
void User::setOperand(unsigned i, Value ^Val)
{
	base->setOperand(i, Val->base);
}
Use ^User::getOperandUse(unsigned i)
{
	return gcnew Use(&base->getOperandUse(i));
}
unsigned User::getNumOperands()
{
	return base->getNumOperands();
}
void User::dropAllReferences()
{
	base->dropAllReferences();
}
void User::replaceUsesOfWith(Value ^From, Value ^To)
{
	base->replaceUsesOfWith(From->base, To->base);
}
inline bool User::classof(Value ^V)
{
	return llvm::User::classof(V->base);
}
