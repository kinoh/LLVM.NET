#include "PassManager.h"
#include "Pass.h"
#include "Module.h"
#include "Function.h"

using namespace LLVM;

PassManagerBase::PassManagerBase(llvm::PassManagerBase *base)
	: base(base)
{
}
inline PassManagerBase ^PassManagerBase::_wrap(llvm::PassManagerBase *base)
{
	return base ? gcnew PassManagerBase(base) : nullptr;
}
PassManagerBase::!PassManagerBase()
{
}
PassManagerBase::~PassManagerBase()
{
	this->!PassManagerBase();
}
void PassManagerBase::add(Pass ^P)
{
	base->add(P->base);
}


PassManager::PassManager(llvm::PassManager *base)
	: base(base)
	, PassManagerBase(base)
	, constructed(false)
{
}
inline PassManager ^PassManager::_wrap(llvm::PassManager *base)
{
	return base ? gcnew PassManager(base) : nullptr;
}
PassManager::!PassManager()
{
	if (constructed)
	{
		delete base;
	}
}
PassManager::~PassManager()
{
	this->!PassManager();
}
PassManager::PassManager()
	: base(new llvm::PassManager())
	, PassManagerBase(base)
	, constructed(true)
{
}
void PassManager::add(Pass ^P)
{
	base->add(P->base);
}
bool PassManager::run(Module ^M)
{
	return base->run(*M->base);
}


FunctionPassManager::FunctionPassManager(llvm::FunctionPassManager *base)
	: base(base)
	, PassManagerBase(base)
	, constructed(false)
{
}
inline FunctionPassManager ^FunctionPassManager::_wrap(llvm::FunctionPassManager *base)
{
	return base ? gcnew FunctionPassManager(base) : nullptr;
}
FunctionPassManager::!FunctionPassManager()
{
	if (constructed)
	{
		delete base;
	}
}
FunctionPassManager::~FunctionPassManager()
{
	this->!FunctionPassManager();
}
FunctionPassManager::FunctionPassManager(Module ^M)
	: base(new llvm::FunctionPassManager(M->base))
	, PassManagerBase(base)
	, constructed(true)
{
}
void FunctionPassManager::add(Pass ^P)
{
	base->add(P->base);
}
bool FunctionPassManager::run(Function ^F)
{
	return base->run(*F->base);
}
bool FunctionPassManager::doInitialization()
{
	return base->doInitialization();
}
bool FunctionPassManager::doFinalization()
{
	return base->doFinalization();
}
