#include "Use.h"
#include "Value.h"
#include "User.h"

using namespace LLVM;

Use::Use(llvm::Use *base)
	: base(base)
{
}
inline Use ^Use::_wrap(llvm::Use *base)
{
	return base ? gcnew Use(base) : nullptr;
}
Use::!Use()
{
}
Use::~Use()
{
	this->!Use();
}
void Use::swap(Use ^RHS)
{
	base->swap(*RHS->base);
}
Value ^Use::get()
{
	return Value::_wrap(base->get());
}
User ^Use::getUser()
{
	return User::_wrap(base->getUser());
}
inline void Use::set(Value ^Val)
{
	base->set(Val->base);
}
Use ^Use::getNext()
{
	return Use::_wrap(base->getNext());
}
Use ^Use::initTags(Use ^Start, Use ^Stop)
{
	return Use::_wrap(llvm::Use::initTags(Start->base, Stop->base));
}
void Use::zap(Use ^Start, Use ^Stop)
{
	llvm::Use::zap(Start->base, Stop->base);
}
void Use::zap(Use ^Start, Use ^Stop, bool del)
{
	llvm::Use::zap(Start->base, Stop->base, del);
}
