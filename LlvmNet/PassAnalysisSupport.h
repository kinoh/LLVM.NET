#pragma once
#include "llvm/PassAnalysisSupport.h"

namespace LLVM
{

ref class PMDataManager;
value class AnalysisID;
ref class Pass;
ref class Function;

public ref class AnalysisUsage
{
private:
	bool constructed;
internal:
	llvm::AnalysisUsage *base;
	AnalysisUsage(llvm::AnalysisUsage *base);

public:
	!AnalysisUsage();
	virtual ~AnalysisUsage();
	// typedef SmallVector<AnalysisID, 32> VectorType;
	AnalysisUsage();
	AnalysisUsage ^addRequiredID(void *ID);
	AnalysisUsage ^addRequiredID(char ID);
	// template<class PassClass>;
	// AnalysisUsage &addRequired();
	AnalysisUsage ^addRequiredTransitiveID(char ID);
	// template<class PassClass>;
	// AnalysisUsage &addRequiredTransitive();
	AnalysisUsage ^addPreservedID(void *ID);
	AnalysisUsage ^addPreservedID(char ID);
	// template<class PassClass>;
	// AnalysisUsage &addPreserved();
	// AnalysisUsage &addPreserved(StringRef Arg);
	void setPreservesAll();
	bool getPreservesAll();
	void setPreservesCFG();
	// const VectorType &getRequiredSet();
	// const VectorType &getRequiredTransitiveSet();
	// const VectorType &getPreservedSet();
};


public ref class AnalysisResolver
{
private:
	bool constructed;
internal:
	llvm::AnalysisResolver *base;
	AnalysisResolver(llvm::AnalysisResolver *base);

public:
	!AnalysisResolver();
	virtual ~AnalysisResolver();
	AnalysisResolver(PMDataManager ^P);
	inline PMDataManager ^getPMDataManager();
	Pass ^findImplPass(AnalysisID ^PI);
	Pass ^findImplPass(Pass ^P, AnalysisID ^PI, Function ^F);
	void addAnalysisImplsPair(AnalysisID ^PI, Pass ^P);
	void clearAnalysisImpls();
	// Pass *getAnalysisIfAvailable(AnalysisID ID, bool Direction);
};

}
