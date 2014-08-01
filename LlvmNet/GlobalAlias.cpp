#include "GlobalAlias.h"
#include "llvm/ADT/Twine.h"
#include "Type.h"
#include "Constant.h"
#include "Module.h"
#include "Value.h"
#include <msclr/marshal.h>

using namespace LLVM;

GlobalAlias::GlobalAlias(llvm::GlobalAlias *base)
	: base(base)
	, GlobalValue(base)
	, constructed(false)
{
}
inline GlobalAlias ^GlobalAlias::_wrap(llvm::GlobalAlias *base)
{
	return base ? gcnew GlobalAlias(base) : nullptr;
}
GlobalAlias::!GlobalAlias()
{
	if (constructed)
	{
		delete base;
	}
}
GlobalAlias::~GlobalAlias()
{
	this->!GlobalAlias();
}
GlobalAlias::GlobalAlias(Type ^Ty, LinkageTypes Linkage)
	: base(new llvm::GlobalAlias(Ty->base, safe_cast<llvm::GlobalAlias::LinkageTypes>(Linkage)))
	, GlobalValue(base)
	, constructed(true)
{
}
llvm::GlobalAlias *GlobalAlias::_construct(Type ^Ty, LinkageTypes Linkage, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return new llvm::GlobalAlias(Ty->base, safe_cast<llvm::GlobalAlias::LinkageTypes>(Linkage), ctx.marshal_as<const char *>(Name));
}
GlobalAlias::GlobalAlias(Type ^Ty, LinkageTypes Linkage, System::String ^Name)
	: base(_construct(Ty, Linkage, Name))
	, GlobalValue(base)
	, constructed(true)
{
}
llvm::GlobalAlias *GlobalAlias::_construct(Type ^Ty, LinkageTypes Linkage, System::String ^Name, Constant ^Aliasee)
{
	msclr::interop::marshal_context ctx;
	return new llvm::GlobalAlias(Ty->base, safe_cast<llvm::GlobalAlias::LinkageTypes>(Linkage), ctx.marshal_as<const char *>(Name), Aliasee->base);
}
GlobalAlias::GlobalAlias(Type ^Ty, LinkageTypes Linkage, System::String ^Name, Constant ^Aliasee)
	: base(_construct(Ty, Linkage, Name, Aliasee))
	, GlobalValue(base)
	, constructed(true)
{
}
llvm::GlobalAlias *GlobalAlias::_construct(Type ^Ty, LinkageTypes Linkage, System::String ^Name, Constant ^Aliasee, Module ^Parent)
{
	msclr::interop::marshal_context ctx;
	return new llvm::GlobalAlias(Ty->base, safe_cast<llvm::GlobalAlias::LinkageTypes>(Linkage), ctx.marshal_as<const char *>(Name), Aliasee->base, Parent->base);
}
GlobalAlias::GlobalAlias(Type ^Ty, LinkageTypes Linkage, System::String ^Name, Constant ^Aliasee, Module ^Parent)
	: base(_construct(Ty, Linkage, Name, Aliasee, Parent))
	, GlobalValue(base)
	, constructed(true)
{
}
void GlobalAlias::removeFromParent()
{
	base->removeFromParent();
}
void GlobalAlias::eraseFromParent()
{
	base->eraseFromParent();
}
void GlobalAlias::setAliasee(Constant ^GV)
{
	base->setAliasee(GV->base);
}
Constant ^GlobalAlias::getAliasee()
{
	return Constant::_wrap(base->getAliasee());
}
inline bool GlobalAlias::classof(Value ^V)
{
	return llvm::GlobalAlias::classof(V->base);
}
