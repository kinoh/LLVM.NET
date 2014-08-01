#pragma once
#using <mscorlib.dll>
#include "llvm/PassManagers.h"
#include "PrettyStackTrace.h"
#include "Pass.h"

namespace LLVM
{

ref class Pass;
ref class Value;
ref class Module;
ref class raw_ostream;
ref class PMDataManager;
value class AnalysisID;
ref class AnalysisUsage;
ref class ImmutablePass;
ref class Function;
ref class PMTopLevelManager;
ref class PMStack;

enum class PassDebuggingString
{
  EXECUTION_MSG,
  MODIFICATION_MSG,
  FREEING_MSG,
  ON_BASICBLOCK_MSG,
  ON_FUNCTION_MSG,
  ON_MODULE_MSG,
  ON_REGION_MSG,
  ON_LOOP_MSG,
  ON_CG_MSG
};

public ref class PassManagerPrettyStackEntry
	: public PrettyStackTraceEntry
{
private:
	bool constructed;

internal:
	llvm::PassManagerPrettyStackEntry *base;

protected:
	PassManagerPrettyStackEntry(llvm::PassManagerPrettyStackEntry *base);

internal:
	static inline PassManagerPrettyStackEntry ^_wrap(llvm::PassManagerPrettyStackEntry *base);

public:
	!PassManagerPrettyStackEntry();
	virtual ~PassManagerPrettyStackEntry();
	PassManagerPrettyStackEntry(Pass ^p);
	//   : P(p), V(0), M(0);
	PassManagerPrettyStackEntry(Pass ^p, Value ^v);
	//   : P(p), V(&v), M(0);
	PassManagerPrettyStackEntry(Pass ^p, Module ^m);
	//   : P(p), V(0), M(&m);
	virtual void print(raw_ostream ^OS);
};


public ref class PMStack
{
internal:
	llvm::PMStack *base;

protected:
	PMStack(llvm::PMStack *base);

internal:
	static inline PMStack ^_wrap(llvm::PMStack *base);

public:
	!PMStack();
	virtual ~PMStack();
	// typedef std::vector<PMDataManager *>::const_reverse_iterator iterator;
	// iterator begin();
	// iterator end();
	void pop();
	PMDataManager ^top();
	void push(PMDataManager ^PM);
	bool empty();
	void dump();
};


public ref class PMTopLevelManager
{
internal:
	llvm::PMTopLevelManager *base;

protected:
	PMTopLevelManager(llvm::PMTopLevelManager *base);

internal:
	static inline PMTopLevelManager ^_wrap(llvm::PMTopLevelManager *base);

public:
	!PMTopLevelManager();
	virtual ~PMTopLevelManager();
	void schedulePass(Pass ^P);
	void setLastUser(array<Pass ^> ^AnalysisPasses, Pass ^P);
	array<Pass ^> ^collectLastUsesArray(Pass ^P);
	Pass ^findAnalysisPass(AnalysisID ^AID);
	AnalysisUsage ^findAnalysisUsage(Pass ^P);
	// virtual ~PMTopLevelManager();
	inline void addImmutablePass(ImmutablePass ^P);
	// inline SmallVectorImpl<ImmutablePass *>& getImmutablePasses();
	void addPassManager(PMDataManager ^Manager);
	inline void addIndirectPassManager(PMDataManager ^Manager);
	void dumpPasses();
	void dumpArguments();
	// PMStack activeStack;
};


public ref class PMDataManager
{
internal:
	llvm::PMDataManager *base;

protected:
	PMDataManager(llvm::PMDataManager *base);

internal:
	static inline PMDataManager ^_wrap(llvm::PMDataManager *base);

public:
	!PMDataManager();
	virtual ~PMDataManager();
	// explicit PMDataManager() : TPM(NULL), Depth(0);
	// virtual ~PMDataManager();
	virtual Pass ^getAsPass();
	void recordAvailableAnalysis(Pass ^P);
	void verifyPreservedAnalysis(Pass ^P);
	void removeNotPreservedAnalysis(Pass ^P);
	void removeDeadPasses(Pass ^P, System::String ^Msg, PassDebuggingString string);
	void freePass(Pass ^P, System::String ^Msg, PassDebuggingString string);
	void add(Pass ^P);
	void add(Pass ^P, bool ProcessAnalysis);
	virtual void addLowerLevelRequiredPass(Pass ^P, Pass ^RequiredPass);
	virtual Pass ^getOnTheFlyPass(Pass ^P, AnalysisID ^PI, Function ^F);
	void initializeAnalysisInfo();
	bool preserveHigherLevelAnalysis(Pass ^P);
	// void collectRequiredAnalysis(SmallVectorImpl<Pass *> &RequiredPasses, SmallVectorImpl<AnalysisID> &ReqPassNotAvailable, Pass *P);
	void initializeAnalysisImpl(Pass ^P);
	Pass ^findAnalysisPass(AnalysisID ^AID, bool Direction);
	PMTopLevelManager ^getTopLevelManager();
	void setTopLevelManager(PMTopLevelManager ^T);
	unsigned getDepth();
	void setDepth(unsigned newDepth);
	void dumpLastUses(Pass ^P, unsigned Offset);
	void dumpPassArguments();
	// void dumpPassInfo(Pass *P, enum PassDebuggingString S1, enum PassDebuggingString S2, StringRef Msg);
	void dumpRequiredSet(Pass ^P);
	void dumpPreservedSet(Pass ^P);
	unsigned getNumContainedPasses();
	virtual PassManagerType getPassManagerType();
	// DenseMap<AnalysisID, Pass *> *getAvailableAnalysis();
	void populateInheritedAnalysis(PMStack ^PMS);
};

}
