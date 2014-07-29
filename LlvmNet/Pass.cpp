#include "Pass.h"
#include "Pass.h"
#include "Module.h"
#include "raw_ostream.h"
#include "PassManagers.h"
#include "PassAnalysisSupport.h"
#include "Function.h"
#include "BasicBlock.h"
#include "utils.h"

using namespace LLVM;

Pass::Pass(llvm::Pass *base)
	: base(base)
{
}
Pass::!Pass()
{
}
Pass::~Pass()
{
	this->!Pass();
}
PassKind Pass::getPassKind()
{
	return safe_cast<PassKind>(base->getPassKind());
}
System::String ^Pass::getPassName()
{
	return utils::manage_str(base->getPassName());
}
AnalysisID ^Pass::getPassID()
{
	return gcnew AnalysisID(base->getPassID());
}
bool Pass::doInitialization(Module ^module)
{
	return base->doInitialization(*module->base);
}
bool Pass::doFinalization(Module ^module)
{
	return base->doFinalization(*module->base);
}
void Pass::print(raw_ostream ^O, Module ^M)
{
	base->print(*O->base, M->base);
}
void Pass::dump()
{
	base->dump();
}
void Pass::assignPassManager(PMStack ^stack, PassManagerType type)
{
	base->assignPassManager(*stack->base, safe_cast<llvm::PassManagerType>(type));
}
void Pass::preparePassManager(PMStack ^stack)
{
	base->preparePassManager(*stack->base);
}
PassManagerType Pass::getPotentialPassManagerType()
{
	return safe_cast<PassManagerType>(base->getPotentialPassManagerType());
}
void Pass::setResolver(AnalysisResolver ^AR)
{
	base->setResolver(AR->base);
}
AnalysisResolver ^Pass::getResolver()
{
	return gcnew AnalysisResolver(base->getResolver());
}
void Pass::getAnalysisUsage(AnalysisUsage ^usage)
{
	base->getAnalysisUsage(*usage->base);
}
void Pass::releaseMemory()
{
	base->releaseMemory();
}
void *Pass::getAdjustedAnalysisPointer(AnalysisID ^ID)
{
	return base->getAdjustedAnalysisPointer(ID->base);
}
ImmutablePass ^Pass::getAsImmutablePass()
{
	return gcnew ImmutablePass(base->getAsImmutablePass());
}
PMDataManager ^Pass::getAsPMDataManager()
{
	return gcnew PMDataManager(base->getAsPMDataManager());
}
void Pass::verifyAnalysis()
{
	base->verifyAnalysis();
}
void Pass::dumpPassStructure()
{
	base->dumpPassStructure();
}
void Pass::dumpPassStructure(unsigned Offset)
{
	base->dumpPassStructure(Offset);
}
Pass ^Pass::createPass(AnalysisID ^ID)
{
	return gcnew Pass(llvm::Pass::createPass(ID->base));
}
bool Pass::mustPreserveAnalysisID(char AID)
{
	return base->mustPreserveAnalysisID(AID);
}


ModulePass::ModulePass(llvm::ModulePass *base)
	: base(base)
	, Pass(base)
{
}
ModulePass::!ModulePass()
{
}
ModulePass::~ModulePass()
{
	this->!ModulePass();
}
bool ModulePass::runOnModule(Module ^M)
{
	return base->runOnModule(*M->base);
}
void ModulePass::assignPassManager(PMStack ^PMS, PassManagerType T)
{
	base->assignPassManager(*PMS->base, safe_cast<llvm::PassManagerType>(T));
}
PassManagerType ModulePass::getPotentialPassManagerType()
{
	return safe_cast<PassManagerType>(base->getPotentialPassManagerType());
}


ImmutablePass::ImmutablePass(llvm::ImmutablePass *base)
	: base(base)
	, ModulePass(base)
	, constructed(false)
{
}
ImmutablePass::!ImmutablePass()
{
	if (constructed)
	{
		delete base;
	}
}
ImmutablePass::~ImmutablePass()
{
	this->!ImmutablePass();
}
void ImmutablePass::initializePass()
{
	base->initializePass();
}
ImmutablePass ^ImmutablePass::getAsImmutablePass()
{
	return gcnew ImmutablePass(base->getAsImmutablePass());
}
bool ImmutablePass::runOnModule(Module ^module)
{
	return base->runOnModule(*module->base);
}
ImmutablePass::ImmutablePass(char pid)
	: base(new llvm::ImmutablePass(pid))
	, ModulePass(base)
	, constructed(true)
{
}


FunctionPass::FunctionPass(llvm::FunctionPass *base)
	: base(base)
	, Pass(base)
{
}
FunctionPass::!FunctionPass()
{
}
FunctionPass::~FunctionPass()
{
	this->!FunctionPass();
}
bool FunctionPass::runOnFunction(Function ^F)
{
	return base->runOnFunction(*F->base);
}
void FunctionPass::assignPassManager(PMStack ^PMS, PassManagerType T)
{
	base->assignPassManager(*PMS->base, safe_cast<llvm::PassManagerType>(T));
}
PassManagerType FunctionPass::getPotentialPassManagerType()
{
	return safe_cast<PassManagerType>(base->getPotentialPassManagerType());
}


BasicBlockPass::BasicBlockPass(llvm::BasicBlockPass *base)
	: base(base)
	, Pass(base)
{
}
BasicBlockPass::!BasicBlockPass()
{
}
BasicBlockPass::~BasicBlockPass()
{
	this->!BasicBlockPass();
}
bool BasicBlockPass::doInitialization(Function ^function)
{
	return base->doInitialization(*function->base);
}
bool BasicBlockPass::runOnBasicBlock(BasicBlock ^BB)
{
	return base->runOnBasicBlock(*BB->base);
}
bool BasicBlockPass::doFinalization(Function ^function)
{
	return base->doFinalization(*function->base);
}
void BasicBlockPass::assignPassManager(PMStack ^PMS, PassManagerType T)
{
	base->assignPassManager(*PMS->base, safe_cast<llvm::PassManagerType>(T));
}
PassManagerType BasicBlockPass::getPotentialPassManagerType()
{
	return safe_cast<PassManagerType>(base->getPotentialPassManagerType());
}
