#include "Pass.h"
#include "Module.h"
#include "raw_ostream.h"
#include "PassManagers.h"
#include "PassAnalysisSupport.h"
#include "Pass.h"
#include "Function.h"
#include "BasicBlock.h"
#include <msclr/marshal_cppstd.h>
#include <string>
#include "utils.h"

using namespace LLVM;

Pass::Pass(llvm::Pass *base)
	: base(base)
{
}
inline Pass ^Pass::_wrap(llvm::Pass *base)
{
	return base ? gcnew Pass(base) : nullptr;
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
	return AnalysisResolver::_wrap(base->getResolver());
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
	return ImmutablePass::_wrap(base->getAsImmutablePass());
}
PMDataManager ^Pass::getAsPMDataManager()
{
	return PMDataManager::_wrap(base->getAsPMDataManager());
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
	return Pass::_wrap(llvm::Pass::createPass(ID->base));
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
inline ModulePass ^ModulePass::_wrap(llvm::ModulePass *base)
{
	return base ? gcnew ModulePass(base) : nullptr;
}
ModulePass::!ModulePass()
{
}
ModulePass::~ModulePass()
{
	this->!ModulePass();
}
Pass ^ModulePass::createPrinterPass(raw_ostream ^O, System::String ^Banner)
{
	return Pass::_wrap(base->createPrinterPass(*O->base, msclr::interop::marshal_as<std::string>(Banner)));
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
inline ImmutablePass ^ImmutablePass::_wrap(llvm::ImmutablePass *base)
{
	return base ? gcnew ImmutablePass(base) : nullptr;
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
	return ImmutablePass::_wrap(base->getAsImmutablePass());
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
inline FunctionPass ^FunctionPass::_wrap(llvm::FunctionPass *base)
{
	return base ? gcnew FunctionPass(base) : nullptr;
}
FunctionPass::!FunctionPass()
{
}
FunctionPass::~FunctionPass()
{
	this->!FunctionPass();
}
Pass ^FunctionPass::createPrinterPass(raw_ostream ^O, System::String ^Banner)
{
	return Pass::_wrap(base->createPrinterPass(*O->base, msclr::interop::marshal_as<std::string>(Banner)));
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
inline BasicBlockPass ^BasicBlockPass::_wrap(llvm::BasicBlockPass *base)
{
	return base ? gcnew BasicBlockPass(base) : nullptr;
}
BasicBlockPass::!BasicBlockPass()
{
}
BasicBlockPass::~BasicBlockPass()
{
	this->!BasicBlockPass();
}
Pass ^BasicBlockPass::createPrinterPass(raw_ostream ^O, System::String ^Banner)
{
	return Pass::_wrap(base->createPrinterPass(*O->base, msclr::interop::marshal_as<std::string>(Banner)));
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
