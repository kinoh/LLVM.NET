#include "PassAnalysisSupport.h"
#include "PassManagers.h"
#include "Pass.h"
#include "Function.h"

using namespace LLVM;

AnalysisUsage::AnalysisUsage(llvm::AnalysisUsage *base)
	: base(base)
	, constructed(false)
{
}
AnalysisUsage::!AnalysisUsage()
{
	if (constructed)
	{
		delete base;
	}
}
AnalysisUsage::~AnalysisUsage()
{
	this->!AnalysisUsage();
}
AnalysisUsage::AnalysisUsage()
	: base(new llvm::AnalysisUsage())
	, constructed(true)
{
}
AnalysisUsage ^AnalysisUsage::addRequiredID(void *ID)
{
	return gcnew AnalysisUsage(&base->addRequiredID(ID));
}
AnalysisUsage ^AnalysisUsage::addRequiredID(char ID)
{
	return gcnew AnalysisUsage(&base->addRequiredID(ID));
}
AnalysisUsage ^AnalysisUsage::addRequiredTransitiveID(char ID)
{
	return gcnew AnalysisUsage(&base->addRequiredTransitiveID(ID));
}
AnalysisUsage ^AnalysisUsage::addPreservedID(void *ID)
{
	return gcnew AnalysisUsage(&base->addPreservedID(ID));
}
AnalysisUsage ^AnalysisUsage::addPreservedID(char ID)
{
	return gcnew AnalysisUsage(&base->addPreservedID(ID));
}
void AnalysisUsage::setPreservesAll()
{
	base->setPreservesAll();
}
bool AnalysisUsage::getPreservesAll()
{
	return base->getPreservesAll();
}
void AnalysisUsage::setPreservesCFG()
{
	base->setPreservesCFG();
}


AnalysisResolver::AnalysisResolver(llvm::AnalysisResolver *base)
	: base(base)
	, constructed(false)
{
}
AnalysisResolver::!AnalysisResolver()
{
	if (constructed)
	{
		delete base;
	}
}
AnalysisResolver::~AnalysisResolver()
{
	this->!AnalysisResolver();
}
AnalysisResolver::AnalysisResolver(PMDataManager ^P)
	: base(new llvm::AnalysisResolver(*P->base))
	, constructed(true)
{
}
inline PMDataManager ^AnalysisResolver::getPMDataManager()
{
	return gcnew PMDataManager(&base->getPMDataManager());
}
Pass ^AnalysisResolver::findImplPass(AnalysisID ^PI)
{
	return gcnew Pass(base->findImplPass(PI->base));
}
Pass ^AnalysisResolver::findImplPass(Pass ^P, AnalysisID ^PI, Function ^F)
{
	return gcnew Pass(base->findImplPass(P->base, PI->base, *F->base));
}
void AnalysisResolver::addAnalysisImplsPair(AnalysisID ^PI, Pass ^P)
{
	base->addAnalysisImplsPair(PI->base, P->base);
}
void AnalysisResolver::clearAnalysisImpls()
{
	base->clearAnalysisImpls();
}
