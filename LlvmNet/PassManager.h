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

protected:
	PassManagerBase(llvm::PassManagerBase *base);

internal:
	static inline PassManagerBase ^_wrap(llvm::PassManagerBase *base);

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

protected:
	PassManager(llvm::PassManager *base);

internal:
	static inline PassManager ^_wrap(llvm::PassManager *base);

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

protected:
	FunctionPassManager(llvm::FunctionPassManager *base);

internal:
	static inline FunctionPassManager ^_wrap(llvm::FunctionPassManager *base);

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
