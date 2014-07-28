#include "GlobalVariable.h"
#include "llvm/ADT/Twine.h"
#include "Type.h"
#include "Constant.h"
#include "Module.h"
#include "GlobalValue.h"
#include "Value.h"
#include "Use.h"
#include <msclr/marshal.h>

using namespace LLVM;

GlobalVariable::GlobalVariable(llvm::GlobalVariable *base)
	: base(base)
	, GlobalValue(base)
	, constructed(false)
{
}
GlobalVariable::!GlobalVariable()
{
	if (constructed)
	{
		delete base;
	}
}
GlobalVariable::~GlobalVariable()
{
	this->!GlobalVariable();
}
GlobalVariable::GlobalVariable(Type ^Ty, bool isConstant, LinkageTypes Linkage)
	: base(new llvm::GlobalVariable(Ty->base, isConstant, safe_cast<llvm::GlobalVariable::LinkageTypes>(Linkage)))
	, GlobalValue(base)
	, constructed(true)
{
}
GlobalVariable::GlobalVariable(Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer)
	: base(new llvm::GlobalVariable(Ty->base, isConstant, safe_cast<llvm::GlobalVariable::LinkageTypes>(Linkage), Initializer->base))
	, GlobalValue(base)
	, constructed(true)
{
}
llvm::GlobalVariable *GlobalVariable::_construct(Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return new llvm::GlobalVariable(Ty->base, isConstant, safe_cast<llvm::GlobalVariable::LinkageTypes>(Linkage), Initializer->base, ctx.marshal_as<const char *>(Name));
}
GlobalVariable::GlobalVariable(Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name)
	: base(_construct(Ty, isConstant, Linkage, Initializer, Name))
	, GlobalValue(base)
	, constructed(true)
{
}
llvm::GlobalVariable *GlobalVariable::_construct(Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, ThreadLocalMode threadLocalMode)
{
	msclr::interop::marshal_context ctx;
	return new llvm::GlobalVariable(Ty->base, isConstant, safe_cast<llvm::GlobalVariable::LinkageTypes>(Linkage), Initializer->base, ctx.marshal_as<const char *>(Name), safe_cast<llvm::GlobalVariable::ThreadLocalMode>(threadLocalMode));
}
GlobalVariable::GlobalVariable(Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, ThreadLocalMode threadLocalMode)
	: base(_construct(Ty, isConstant, Linkage, Initializer, Name, threadLocalMode))
	, GlobalValue(base)
	, constructed(true)
{
}
llvm::GlobalVariable *GlobalVariable::_construct(Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, ThreadLocalMode threadLocalMode, unsigned AddressSpace)
{
	msclr::interop::marshal_context ctx;
	return new llvm::GlobalVariable(Ty->base, isConstant, safe_cast<llvm::GlobalVariable::LinkageTypes>(Linkage), Initializer->base, ctx.marshal_as<const char *>(Name), safe_cast<llvm::GlobalVariable::ThreadLocalMode>(threadLocalMode), AddressSpace);
}
GlobalVariable::GlobalVariable(Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, ThreadLocalMode threadLocalMode, unsigned AddressSpace)
	: base(_construct(Ty, isConstant, Linkage, Initializer, Name, threadLocalMode, AddressSpace))
	, GlobalValue(base)
	, constructed(true)
{
}
llvm::GlobalVariable *GlobalVariable::_construct(Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, ThreadLocalMode threadLocalMode, unsigned AddressSpace, bool isExternallyInitialized)
{
	msclr::interop::marshal_context ctx;
	return new llvm::GlobalVariable(Ty->base, isConstant, safe_cast<llvm::GlobalVariable::LinkageTypes>(Linkage), Initializer->base, ctx.marshal_as<const char *>(Name), safe_cast<llvm::GlobalVariable::ThreadLocalMode>(threadLocalMode), AddressSpace, isExternallyInitialized);
}
GlobalVariable::GlobalVariable(Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, ThreadLocalMode threadLocalMode, unsigned AddressSpace, bool isExternallyInitialized)
	: base(_construct(Ty, isConstant, Linkage, Initializer, Name, threadLocalMode, AddressSpace, isExternallyInitialized))
	, GlobalValue(base)
	, constructed(true)
{
}
GlobalVariable::GlobalVariable(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer)
	: base(new llvm::GlobalVariable(*M->base, Ty->base, isConstant, safe_cast<llvm::GlobalVariable::LinkageTypes>(Linkage), Initializer->base))
	, GlobalValue(base)
	, constructed(true)
{
}
llvm::GlobalVariable *GlobalVariable::_construct(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return new llvm::GlobalVariable(*M->base, Ty->base, isConstant, safe_cast<llvm::GlobalVariable::LinkageTypes>(Linkage), Initializer->base, ctx.marshal_as<const char *>(Name));
}
GlobalVariable::GlobalVariable(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name)
	: base(_construct(M, Ty, isConstant, Linkage, Initializer, Name))
	, GlobalValue(base)
	, constructed(true)
{
}
llvm::GlobalVariable *GlobalVariable::_construct(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, GlobalVariable ^InsertBefore)
{
	msclr::interop::marshal_context ctx;
	return new llvm::GlobalVariable(*M->base, Ty->base, isConstant, safe_cast<llvm::GlobalVariable::LinkageTypes>(Linkage), Initializer->base, ctx.marshal_as<const char *>(Name), InsertBefore->base);
}
GlobalVariable::GlobalVariable(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, GlobalVariable ^InsertBefore)
	: base(_construct(M, Ty, isConstant, Linkage, Initializer, Name, InsertBefore))
	, GlobalValue(base)
	, constructed(true)
{
}
llvm::GlobalVariable *GlobalVariable::_construct(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, GlobalVariable ^InsertBefore, ThreadLocalMode threadLocalMode)
{
	msclr::interop::marshal_context ctx;
	return new llvm::GlobalVariable(*M->base, Ty->base, isConstant, safe_cast<llvm::GlobalVariable::LinkageTypes>(Linkage), Initializer->base, ctx.marshal_as<const char *>(Name), InsertBefore->base, safe_cast<llvm::GlobalVariable::ThreadLocalMode>(threadLocalMode));
}
GlobalVariable::GlobalVariable(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, GlobalVariable ^InsertBefore, ThreadLocalMode threadLocalMode)
	: base(_construct(M, Ty, isConstant, Linkage, Initializer, Name, InsertBefore, threadLocalMode))
	, GlobalValue(base)
	, constructed(true)
{
}
llvm::GlobalVariable *GlobalVariable::_construct(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, GlobalVariable ^InsertBefore, ThreadLocalMode threadLocalMode, unsigned AddressSpace)
{
	msclr::interop::marshal_context ctx;
	return new llvm::GlobalVariable(*M->base, Ty->base, isConstant, safe_cast<llvm::GlobalVariable::LinkageTypes>(Linkage), Initializer->base, ctx.marshal_as<const char *>(Name), InsertBefore->base, safe_cast<llvm::GlobalVariable::ThreadLocalMode>(threadLocalMode), AddressSpace);
}
GlobalVariable::GlobalVariable(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, GlobalVariable ^InsertBefore, ThreadLocalMode threadLocalMode, unsigned AddressSpace)
	: base(_construct(M, Ty, isConstant, Linkage, Initializer, Name, InsertBefore, threadLocalMode, AddressSpace))
	, GlobalValue(base)
	, constructed(true)
{
}
llvm::GlobalVariable *GlobalVariable::_construct(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, GlobalVariable ^InsertBefore, ThreadLocalMode threadLocalMode, unsigned AddressSpace, bool isExternallyInitialized)
{
	msclr::interop::marshal_context ctx;
	return new llvm::GlobalVariable(*M->base, Ty->base, isConstant, safe_cast<llvm::GlobalVariable::LinkageTypes>(Linkage), Initializer->base, ctx.marshal_as<const char *>(Name), InsertBefore->base, safe_cast<llvm::GlobalVariable::ThreadLocalMode>(threadLocalMode), AddressSpace, isExternallyInitialized);
}
GlobalVariable::GlobalVariable(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, GlobalVariable ^InsertBefore, ThreadLocalMode threadLocalMode, unsigned AddressSpace, bool isExternallyInitialized)
	: base(_construct(M, Ty, isConstant, Linkage, Initializer, Name, InsertBefore, threadLocalMode, AddressSpace, isExternallyInitialized))
	, GlobalValue(base)
	, constructed(true)
{
}
inline bool GlobalVariable::hasInitializer()
{
	return base->hasInitializer();
}
inline bool GlobalVariable::hasDefinitiveInitializer()
{
	return base->hasDefinitiveInitializer();
}
inline bool GlobalVariable::hasUniqueInitializer()
{
	return base->hasUniqueInitializer();
}
inline Constant ^GlobalVariable::getInitializer()
{
	return gcnew Constant(base->getInitializer());
}
void GlobalVariable::setInitializer(Constant ^InitVal)
{
	base->setInitializer(InitVal->base);
}
bool GlobalVariable::isConstant()
{
	return base->isConstant();
}
void GlobalVariable::setConstant(bool Val)
{
	base->setConstant(Val);
}
bool GlobalVariable::isThreadLocal()
{
	return base->isThreadLocal();
}
void GlobalVariable::setThreadLocal(bool Val)
{
	base->setThreadLocal(Val);
}
void GlobalVariable::setThreadLocalMode(ThreadLocalMode Val)
{
	base->setThreadLocalMode(safe_cast<llvm::GlobalVariable::ThreadLocalMode>(Val));
}
GlobalVariable::ThreadLocalMode GlobalVariable::getThreadLocalMode()
{
	return safe_cast<GlobalVariable::ThreadLocalMode>(base->getThreadLocalMode());
}
bool GlobalVariable::isExternallyInitialized()
{
	return base->isExternallyInitialized();
}
void GlobalVariable::setExternallyInitialized(bool Val)
{
	base->setExternallyInitialized(Val);
}
void GlobalVariable::copyAttributesFrom(GlobalValue ^Src)
{
	base->copyAttributesFrom(Src->base);
}
void GlobalVariable::removeFromParent()
{
	base->removeFromParent();
}
void GlobalVariable::eraseFromParent()
{
	base->eraseFromParent();
}
void GlobalVariable::replaceUsesOfWithOnConstant(Value ^From, Value ^To, Use ^U)
{
	base->replaceUsesOfWithOnConstant(From->base, To->base, U->base);
}
inline bool GlobalVariable::classof(Value ^V)
{
	return llvm::GlobalVariable::classof(V->base);
}
