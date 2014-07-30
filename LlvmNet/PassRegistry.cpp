#include "PassRegistry.h"
#include "PassSupport.h"
#include "PassSupport.h"

using namespace LLVM;

PassRegistry::PassRegistry(llvm::PassRegistry *base)
	: base(base)
	, constructed(false)
{
}
PassRegistry::!PassRegistry()
{
	if (constructed)
	{
		delete base;
	}
}
PassRegistry::~PassRegistry()
{
	this->!PassRegistry();
}
PassRegistry::PassRegistry()
	: base(new llvm::PassRegistry())
	, constructed(true)
{
}
PassRegistry ^PassRegistry::getPassRegistry()
{
	return gcnew PassRegistry(llvm::PassRegistry::getPassRegistry());
}
void PassRegistry::registerPass(PassInfo ^PI)
{
	base->registerPass(*PI->base);
}
void PassRegistry::registerPass(PassInfo ^PI, bool ShouldFree)
{
	base->registerPass(*PI->base, ShouldFree);
}
void PassRegistry::unregisterPass(PassInfo ^PI)
{
	base->unregisterPass(*PI->base);
}
void PassRegistry::registerAnalysisGroup(void *InterfaceID, void *PassID, PassInfo ^Registeree, bool isDefault)
{
	base->registerAnalysisGroup(InterfaceID, PassID, *Registeree->base, isDefault);
}
void PassRegistry::registerAnalysisGroup(void *InterfaceID, void *PassID, PassInfo ^Registeree, bool isDefault, bool ShouldFree)
{
	base->registerAnalysisGroup(InterfaceID, PassID, *Registeree->base, isDefault, ShouldFree);
}
void PassRegistry::enumerateWith(PassRegistrationListener ^L)
{
	base->enumerateWith(L->base);
}
void PassRegistry::addRegistrationListener(PassRegistrationListener ^L)
{
	base->addRegistrationListener(L->base);
}
void PassRegistry::removeRegistrationListener(PassRegistrationListener ^L)
{
	base->removeRegistrationListener(L->base);
}
