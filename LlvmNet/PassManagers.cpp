#include "PassManagers.h"
#include "llvm/ADT/ArrayRef.h"
#include "llvm/ADT/SmallVector.h"
#include "Pass.h"
#include "llvm/ADT/StringRef.h"
#include "Pass.h"
#include "Value.h"
#include "Module.h"
#include "raw_ostream.h"
#include "PassManagers.h"
#include "PassAnalysisSupport.h"
#include "Function.h"
#include <msclr/marshal.h>

using namespace LLVM;

PassManagerPrettyStackEntry::PassManagerPrettyStackEntry(llvm::PassManagerPrettyStackEntry *base)
	: base(base)
	, PrettyStackTraceEntry(base)
	, constructed(false)
{
}
PassManagerPrettyStackEntry::!PassManagerPrettyStackEntry()
{
	if (constructed)
	{
		delete base;
	}
}
PassManagerPrettyStackEntry::~PassManagerPrettyStackEntry()
{
	this->!PassManagerPrettyStackEntry();
}
PassManagerPrettyStackEntry::PassManagerPrettyStackEntry(Pass ^p)
	: base(new llvm::PassManagerPrettyStackEntry(p->base))
	, PrettyStackTraceEntry(base)
	, constructed(true)
{
}
PassManagerPrettyStackEntry::PassManagerPrettyStackEntry(Pass ^p, Value ^v)
	: base(new llvm::PassManagerPrettyStackEntry(p->base, *v->base))
	, PrettyStackTraceEntry(base)
	, constructed(true)
{
}
PassManagerPrettyStackEntry::PassManagerPrettyStackEntry(Pass ^p, Module ^m)
	: base(new llvm::PassManagerPrettyStackEntry(p->base, *m->base))
	, PrettyStackTraceEntry(base)
	, constructed(true)
{
}
void PassManagerPrettyStackEntry::print(raw_ostream ^OS)
{
	base->print(*OS->base);
}


PMStack::PMStack(llvm::PMStack *base)
	: base(base)
{
}
PMStack::!PMStack()
{
}
PMStack::~PMStack()
{
	this->!PMStack();
}
void PMStack::pop()
{
	base->pop();
}
PMDataManager ^PMStack::top()
{
	return gcnew PMDataManager(base->top());
}
void PMStack::push(PMDataManager ^PM)
{
	base->push(PM->base);
}
bool PMStack::empty()
{
	return base->empty();
}
void PMStack::dump()
{
	base->dump();
}


PMTopLevelManager::PMTopLevelManager(llvm::PMTopLevelManager *base)
	: base(base)
{
}
PMTopLevelManager::!PMTopLevelManager()
{
}
PMTopLevelManager::~PMTopLevelManager()
{
	this->!PMTopLevelManager();
}
void PMTopLevelManager::schedulePass(Pass ^P)
{
	base->schedulePass(P->base);
}
void PMTopLevelManager::setLastUser(array<Pass ^> ^AnalysisPasses, Pass ^P)
{
	llvm::Pass **b = new llvm::Pass*[AnalysisPasses->Length];
	for (int i = 0; i < AnalysisPasses->Length; i++)
		b[i] = AnalysisPasses[i]->base;
	llvm::ArrayRef<llvm::Pass*> brr(b, AnalysisPasses->Length);
	base->setLastUser(brr, P->base);
	delete b;
}
array<Pass ^> ^PMTopLevelManager::collectLastUsesArray(Pass ^P)
{
	llvm::SmallVector<llvm::Pass *, 8> r;
	base->collectLastUses(r, P->base);
	array<Pass ^> ^s = gcnew array<Pass ^>(r.size());
	for (int i = 0; i < s->Length; i++)
		s[i] = gcnew Pass(r[i]);
	return s;
}
Pass ^PMTopLevelManager::findAnalysisPass(AnalysisID ^AID)
{
	return gcnew Pass(base->findAnalysisPass(AID->base));
}
AnalysisUsage ^PMTopLevelManager::findAnalysisUsage(Pass ^P)
{
	return gcnew AnalysisUsage(base->findAnalysisUsage(P->base));
}
inline void PMTopLevelManager::addImmutablePass(ImmutablePass ^P)
{
	base->addImmutablePass(P->base);
}
void PMTopLevelManager::addPassManager(PMDataManager ^Manager)
{
	base->addPassManager(Manager->base);
}
inline void PMTopLevelManager::addIndirectPassManager(PMDataManager ^Manager)
{
	base->addIndirectPassManager(Manager->base);
}
void PMTopLevelManager::dumpPasses()
{
	base->dumpPasses();
}
void PMTopLevelManager::dumpArguments()
{
	base->dumpArguments();
}


PMDataManager::PMDataManager(llvm::PMDataManager *base)
	: base(base)
{
}
PMDataManager::!PMDataManager()
{
}
PMDataManager::~PMDataManager()
{
	this->!PMDataManager();
}
Pass ^PMDataManager::getAsPass()
{
	return gcnew Pass(base->getAsPass());
}
void PMDataManager::recordAvailableAnalysis(Pass ^P)
{
	base->recordAvailableAnalysis(P->base);
}
void PMDataManager::verifyPreservedAnalysis(Pass ^P)
{
	base->verifyPreservedAnalysis(P->base);
}
void PMDataManager::removeNotPreservedAnalysis(Pass ^P)
{
	base->removeNotPreservedAnalysis(P->base);
}
void PMDataManager::removeDeadPasses(Pass ^P, System::String ^Msg, PassDebuggingString string)
{
	msclr::interop::marshal_context ctx;
	base->removeDeadPasses(P->base, ctx.marshal_as<const char *>(Msg), safe_cast<llvm::PassDebuggingString>(string));
}
void PMDataManager::freePass(Pass ^P, System::String ^Msg, PassDebuggingString string)
{
	msclr::interop::marshal_context ctx;
	base->freePass(P->base, ctx.marshal_as<const char *>(Msg), safe_cast<llvm::PassDebuggingString>(string));
}
void PMDataManager::add(Pass ^P)
{
	base->add(P->base);
}
void PMDataManager::add(Pass ^P, bool ProcessAnalysis)
{
	base->add(P->base, ProcessAnalysis);
}
void PMDataManager::addLowerLevelRequiredPass(Pass ^P, Pass ^RequiredPass)
{
	base->addLowerLevelRequiredPass(P->base, RequiredPass->base);
}
Pass ^PMDataManager::getOnTheFlyPass(Pass ^P, AnalysisID ^PI, Function ^F)
{
	return gcnew Pass(base->getOnTheFlyPass(P->base, PI->base, *F->base));
}
void PMDataManager::initializeAnalysisInfo()
{
	base->initializeAnalysisInfo();
}
bool PMDataManager::preserveHigherLevelAnalysis(Pass ^P)
{
	return base->preserveHigherLevelAnalysis(P->base);
}
void PMDataManager::initializeAnalysisImpl(Pass ^P)
{
	base->initializeAnalysisImpl(P->base);
}
Pass ^PMDataManager::findAnalysisPass(AnalysisID ^AID, bool Direction)
{
	return gcnew Pass(base->findAnalysisPass(AID->base, Direction));
}
PMTopLevelManager ^PMDataManager::getTopLevelManager()
{
	return gcnew PMTopLevelManager(base->getTopLevelManager());
}
void PMDataManager::setTopLevelManager(PMTopLevelManager ^T)
{
	base->setTopLevelManager(T->base);
}
unsigned PMDataManager::getDepth()
{
	return base->getDepth();
}
void PMDataManager::setDepth(unsigned newDepth)
{
	base->setDepth(newDepth);
}
void PMDataManager::dumpLastUses(Pass ^P, unsigned Offset)
{
	base->dumpLastUses(P->base, Offset);
}
void PMDataManager::dumpPassArguments()
{
	base->dumpPassArguments();
}
void PMDataManager::dumpPassInfo(Pass ^P, PassDebuggingString S1, PassDebuggingString S2, System::String ^Msg)
{
	msclr::interop::marshal_context ctx;
	base->dumpPassInfo(P->base, safe_cast<llvm::PassDebuggingString>(S1), safe_cast<llvm::PassDebuggingString>(S2), ctx.marshal_as<const char *>(Msg));
}
void PMDataManager::dumpRequiredSet(Pass ^P)
{
	base->dumpRequiredSet(P->base);
}
void PMDataManager::dumpPreservedSet(Pass ^P)
{
	base->dumpPreservedSet(P->base);
}
unsigned PMDataManager::getNumContainedPasses()
{
	return base->getNumContainedPasses();
}
PassManagerType PMDataManager::getPassManagerType()
{
	return safe_cast<PassManagerType>(base->getPassManagerType());
}
void PMDataManager::populateInheritedAnalysis(PMStack ^PMS)
{
	base->populateInheritedAnalysis(*PMS->base);
}
