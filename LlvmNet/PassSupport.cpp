#include "PassSupport.h"
#include "Pass.h"
#include <msclr/marshal.h>
#include "utils.h"

using namespace LLVM;

PassInfo::PassInfo(llvm::PassInfo *base)
	: base(base)
	, constructed(false)
{
}
PassInfo::!PassInfo()
{
	if (constructed)
	{
		delete base;
	}
}
PassInfo::~PassInfo()
{
	this->!PassInfo();
}
llvm::PassInfo *PassInfo::_construct(System::String ^name, void *pi)
{
	msclr::interop::marshal_context ctx;
	return new llvm::PassInfo(ctx.marshal_as<const char *>(name), pi);
}
PassInfo::PassInfo(System::String ^name, void *pi)
	: base(_construct(name, pi))
	, constructed(true)
{
}
System::String ^PassInfo::getPassName()
{
	return utils::manage_str(base->getPassName());
}
System::String ^PassInfo::getPassArgument()
{
	return utils::manage_str(base->getPassArgument());
}
bool PassInfo::isPassID(void *IDPtr)
{
	return base->isPassID(IDPtr);
}
bool PassInfo::isAnalysisGroup()
{
	return base->isAnalysisGroup();
}
bool PassInfo::isAnalysis()
{
	return base->isAnalysis();
}
bool PassInfo::isCFGOnlyPass()
{
	return base->isCFGOnlyPass();
}
Pass ^PassInfo::createPass()
{
	return Pass::_wrap(base->createPass());
}
void PassInfo::addInterfaceImplemented(PassInfo ^ItfPI)
{
	base->addInterfaceImplemented(ItfPI->base);
}


RegisterAGBase::RegisterAGBase(llvm::RegisterAGBase *base)
	: base(base)
	, PassInfo(base)
	, constructed(false)
{
}
RegisterAGBase::!RegisterAGBase()
{
	if (constructed)
	{
		delete base;
	}
}
RegisterAGBase::~RegisterAGBase()
{
	this->!RegisterAGBase();
}
llvm::RegisterAGBase *RegisterAGBase::_construct(System::String ^Name, void *InterfaceID)
{
	msclr::interop::marshal_context ctx;
	return new llvm::RegisterAGBase(ctx.marshal_as<const char *>(Name), InterfaceID);
}
RegisterAGBase::RegisterAGBase(System::String ^Name, void *InterfaceID)
	: base(_construct(Name, InterfaceID))
	, PassInfo(base)
	, constructed(true)
{
}
llvm::RegisterAGBase *RegisterAGBase::_construct(System::String ^Name, void *InterfaceID, void *PassID)
{
	msclr::interop::marshal_context ctx;
	return new llvm::RegisterAGBase(ctx.marshal_as<const char *>(Name), InterfaceID, PassID);
}
RegisterAGBase::RegisterAGBase(System::String ^Name, void *InterfaceID, void *PassID)
	: base(_construct(Name, InterfaceID, PassID))
	, PassInfo(base)
	, constructed(true)
{
}
llvm::RegisterAGBase *RegisterAGBase::_construct(System::String ^Name, void *InterfaceID, void *PassID, bool isDefault)
{
	msclr::interop::marshal_context ctx;
	return new llvm::RegisterAGBase(ctx.marshal_as<const char *>(Name), InterfaceID, PassID, isDefault);
}
RegisterAGBase::RegisterAGBase(System::String ^Name, void *InterfaceID, void *PassID, bool isDefault)
	: base(_construct(Name, InterfaceID, PassID, isDefault))
	, PassInfo(base)
	, constructed(true)
{
}

PassRegistrationListener::PassRegistrationListener(llvm::PassRegistrationListener *base)
	: base(base)
{
}
PassRegistrationListener::!PassRegistrationListener()
{
	delete base;
}
PassRegistrationListener::~PassRegistrationListener()
{
	this->!PassRegistrationListener();
}
void PassRegistrationListener::passRegistered(const PassInfo ^info)
{
	base->passRegistered(info->base);
}
void PassRegistrationListener::enumeratePasses()
{
	base->enumeratePasses();
}
void PassRegistrationListener::passEnumerate(const PassInfo ^info)
{
	base->passEnumerate(info->base);
}
