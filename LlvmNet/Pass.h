#pragma once
#using <mscorlib.dll>
#include "llvm/Pass.h"

namespace LLVM
{

ref class Module;
ref class raw_ostream;
ref class PMStack;
ref class AnalysisResolver;
ref class AnalysisUsage;
value class AnalysisID;
ref class ImmutablePass;
ref class PMDataManager;
ref class Pass;
ref class Function;
ref class BasicBlock;

public value class AnalysisID
{
internal:
	const void *base;
	AnalysisID(const void *base)
		: base(base)
	{
	}
};


enum class PassManagerType
{
  PMT_Unknown = 0,
  PMT_ModulePassManager = 1,
  PMT_CallGraphPassManager,
  PMT_FunctionPassManager,
  PMT_LoopPassManager,
  PMT_RegionPassManager,
  PMT_BasicBlockPassManager,
  PMT_Last
};

enum class PassKind
{
  PT_BasicBlock,
  PT_Region,
  PT_Loop,
  PT_Function,
  PT_CallGraphSCC,
  PT_Module,
  PT_PassManager
};

public ref class Pass
{
internal:
	llvm::Pass *base;

protected:
	Pass(llvm::Pass *base);

internal:
	static inline Pass ^_wrap(llvm::Pass *base);

public:
	!Pass();
	virtual ~Pass();
	// explicit Pass(PassKind K, char &pid) : Resolver(0), PassID(&pid), Kind(K);
	// virtual ~Pass();
	PassKind getPassKind();
	virtual System::String ^getPassName();
	AnalysisID ^getPassID();
	virtual bool doInitialization(Module ^module);
	virtual bool doFinalization(Module ^module);
	virtual void print(raw_ostream ^O, Module ^M);
	void dump();
	// virtual Pass *createPrinterPass(raw_ostream &O, const std::string &Banner) const = 0;
	virtual void assignPassManager(PMStack ^stack, PassManagerType type);
	virtual void preparePassManager(PMStack ^stack);
	virtual PassManagerType getPotentialPassManagerType();
	void setResolver(AnalysisResolver ^AR);
	AnalysisResolver ^getResolver();
	virtual void getAnalysisUsage(AnalysisUsage ^usage);
	virtual void releaseMemory();
	virtual void *getAdjustedAnalysisPointer(AnalysisID ^ID);
	virtual ImmutablePass ^getAsImmutablePass();
	virtual PMDataManager ^getAsPMDataManager();
	virtual void verifyAnalysis();
	virtual void dumpPassStructure();
	virtual void dumpPassStructure(unsigned Offset);
	// static const PassInfo *lookupPassInfo(const void *TI);
	// static const PassInfo *lookupPassInfo(StringRef Arg);
	static Pass ^createPass(AnalysisID ^ID);
	// template<typename AnalysisType> AnalysisType *;
	//   getAnalysisIfAvailable();
	bool mustPreserveAnalysisID(char AID);
	// template<typename AnalysisType>;
	// AnalysisType &getAnalysis();
	// template<typename AnalysisType>;
	// AnalysisType &getAnalysis(Function &F);
	// template<typename AnalysisType>;
	// AnalysisType &getAnalysisID(AnalysisID PI);
	// template<typename AnalysisType>;
	// AnalysisType &getAnalysisID(AnalysisID PI, Function &F);
};


public ref class ModulePass
	: public Pass
{
internal:
	llvm::ModulePass *base;

protected:
	ModulePass(llvm::ModulePass *base);

internal:
	static inline ModulePass ^_wrap(llvm::ModulePass *base);

public:
	!ModulePass();
	virtual ~ModulePass();
	virtual Pass ^createPrinterPass(raw_ostream ^O, System::String ^Banner);
	virtual bool runOnModule(Module ^M);
	virtual void assignPassManager(PMStack ^PMS, PassManagerType T) override;
	virtual PassManagerType getPotentialPassManagerType() override;
	// explicit ModulePass(char &pid) : Pass(PT_Module, pid);
	// virtual ~ModulePass();
};


public ref class ImmutablePass
	: public ModulePass
{
private:
	bool constructed;

internal:
	llvm::ImmutablePass *base;

protected:
	ImmutablePass(llvm::ImmutablePass *base);

internal:
	static inline ImmutablePass ^_wrap(llvm::ImmutablePass *base);

public:
	!ImmutablePass();
	virtual ~ImmutablePass();
	virtual void initializePass();
	virtual ImmutablePass ^getAsImmutablePass() override;
	virtual bool runOnModule(Module ^module) override;
	ImmutablePass(char pid);
	// : ModulePass(pid);
	// virtual ~ImmutablePass();
};


public ref class FunctionPass
	: public Pass
{
internal:
	llvm::FunctionPass *base;

protected:
	FunctionPass(llvm::FunctionPass *base);

internal:
	static inline FunctionPass ^_wrap(llvm::FunctionPass *base);

public:
	!FunctionPass();
	virtual ~FunctionPass();
	// explicit FunctionPass(char &pid) : Pass(PT_Function, pid);
	Pass ^createPrinterPass(raw_ostream ^O, System::String ^Banner);
	virtual bool runOnFunction(Function ^F);
	virtual void assignPassManager(PMStack ^PMS, PassManagerType T) override;
	virtual PassManagerType getPotentialPassManagerType() override;
};


public ref class BasicBlockPass
	: public Pass
{
internal:
	llvm::BasicBlockPass *base;

protected:
	BasicBlockPass(llvm::BasicBlockPass *base);

internal:
	static inline BasicBlockPass ^_wrap(llvm::BasicBlockPass *base);

public:
	!BasicBlockPass();
	virtual ~BasicBlockPass();
	// explicit BasicBlockPass(char &pid) : Pass(PT_BasicBlock, pid);
	Pass ^createPrinterPass(raw_ostream ^O, System::String ^Banner);
	// using llvm::Pass::doInitialization;
	// using llvm::Pass::doFinalization;
	virtual bool doInitialization(Function ^function);
	virtual bool runOnBasicBlock(BasicBlock ^BB);
	virtual bool doFinalization(Function ^function);
	virtual void assignPassManager(PMStack ^PMS, PassManagerType T) override;
	virtual PassManagerType getPotentialPassManagerType() override;
};

}
