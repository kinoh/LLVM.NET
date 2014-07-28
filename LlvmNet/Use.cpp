#include "Use.h"
#include "Value.h"
#include "User.h"

using namespace LLVM;

Use::Use(llvm::Use *base)
	: base(base)
{
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
	return gcnew Value(base->get());
}
User ^Use::getUser()
{
	return gcnew User(base->getUser());
}
inline void Use::set(Value ^Val)
{
	base->set(Val->base);
}
Use ^Use::getNext()
{
	return gcnew Use(base->getNext());
}
Use ^Use::initTags(Use ^Start, Use ^Stop)
{
	return gcnew Use(llvm::Use::initTags(Start->base, Stop->base));
}
void Use::zap(Use ^Start, Use ^Stop)
{
	llvm::Use::zap(Start->base, Stop->base);
}
void Use::zap(Use ^Start, Use ^Stop, bool del)
{
	llvm::Use::zap(Start->base, Stop->base, del);
}
