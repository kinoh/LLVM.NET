#include "User.h"
#include "Value.h"
#include "Use.h"

using namespace LLVM;

User::User(llvm::User *base)
	: base(base)
	, Value(base)
{
}
inline User ^User::_wrap(llvm::User *base)
{
	return base ? gcnew User(base) : nullptr;
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
	return Value::_wrap(base->getOperand(i));
}
void User::setOperand(unsigned i, Value ^Val)
{
	base->setOperand(i, Val->base);
}
Use ^User::getOperandUse(unsigned i)
{
	return Use::_wrap(&base->getOperandUse(i));
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
