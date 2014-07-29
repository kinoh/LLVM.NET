#pragma once
#include "llvm/PassManager.h"

namespace LLVM
{

ref class Pass;
ref class Module;
ref class Function;

public ref class PassManagerBase
{
internal:
	llvm::PassManagerBase *base;
	PassManagerBase(llvm::PassManagerBase *base);

public:
	!PassManagerBase();
	virtual ~PassManagerBase();
	// virtual ~PassManagerBase();
	virtual void add(Pass ^P);
};


public ref class PassManager
	: public PassManagerBase
{
private:
	bool constructed;
internal:
	llvm::PassManager *base;
	PassManager(llvm::PassManager *base);

public:
	!PassManager();
	virtual ~PassManager();
	PassManager();
	virtual void add(Pass ^P) override;
	bool run(Module ^M);
};


public ref class FunctionPassManager
	: public PassManagerBase
{
private:
	bool constructed;
internal:
	llvm::FunctionPassManager *base;
	FunctionPassManager(llvm::FunctionPassManager *base);

public:
	!FunctionPassManager();
	virtual ~FunctionPassManager();
	FunctionPassManager(Module ^M);
	virtual void add(Pass ^P) override;
	bool run(Function ^F);
	bool doInitialization();
	bool doFinalization();
};

}
