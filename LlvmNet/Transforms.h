#pragma once
#include "llvm/Transforms/Scalar.h"

namespace LLVM
{

ref class FunctionPass;
ref class Pass;
//ref class TargetLowering;

public ref class Transforms
{
public:
	static FunctionPass ^createConstantPropagationPass();
	static FunctionPass ^createSCCPPass();
	static Pass ^createDeadInstEliminationPass();
	static FunctionPass ^createDeadCodeEliminationPass();
	static FunctionPass ^createDeadStoreEliminationPass();
	static FunctionPass ^createAggressiveDCEPass();
	static FunctionPass ^createSROAPass();
	static FunctionPass ^createSROAPass(bool RequiresDomTree);
	static FunctionPass ^createScalarReplAggregatesPass();
	static FunctionPass ^createScalarReplAggregatesPass(signed Threshold);
	static FunctionPass ^createScalarReplAggregatesPass(signed Threshold, bool UseDomTree);
	static FunctionPass ^createScalarReplAggregatesPass(signed Threshold, bool UseDomTree, signed StructMemberThreshold);
	static FunctionPass ^createScalarReplAggregatesPass(signed Threshold, bool UseDomTree, signed StructMemberThreshold, signed ArrayElementThreshold);
	static FunctionPass ^createScalarReplAggregatesPass(signed Threshold, bool UseDomTree, signed StructMemberThreshold, signed ArrayElementThreshold, signed ScalarLoadThreshold);
	static Pass ^createIndVarSimplifyPass();
	static FunctionPass ^createInstructionCombiningPass();
	static Pass ^createLICMPass();
	static Pass ^createLoopStrengthReducePass();
	static Pass ^createGlobalMergePass();
	//static Pass ^createGlobalMergePass(TargetLowering ^TLI);
	static Pass ^createLoopUnswitchPass();
	static Pass ^createLoopUnswitchPass(bool OptimizeForSize);
	static Pass ^createLoopInstSimplifyPass();
	static Pass ^createLoopUnrollPass();
	static Pass ^createLoopUnrollPass(int Threshold);
	static Pass ^createLoopUnrollPass(int Threshold, int Count);
	static Pass ^createLoopUnrollPass(int Threshold, int Count, int AllowPartial);
	static Pass ^createLoopRotatePass();
	static Pass ^createLoopIdiomPass();
	static FunctionPass ^createPromoteMemoryToRegisterPass();
	static FunctionPass ^createDemoteRegisterToMemoryPass();
	static FunctionPass ^createReassociatePass();
	static FunctionPass ^createJumpThreadingPass();
	static FunctionPass ^createCFGSimplificationPass();
	static FunctionPass ^createBreakCriticalEdgesPass();
	static Pass ^createLoopSimplifyPass();
	static FunctionPass ^createTailCallEliminationPass();
	static FunctionPass ^createLowerSwitchPass();
	static FunctionPass ^createLowerInvokePass();
	//static FunctionPass ^createLowerInvokePass(TargetLowering ^TLI);
	//static FunctionPass ^createLowerInvokePass(TargetLowering ^TLI, bool useExpensiveEHSupport);
	static FunctionPass ^createBlockPlacementPass();
	static Pass ^createLCSSAPass();
	static FunctionPass ^createEarlyCSEPass();
	static FunctionPass ^createGVNPass();
	static FunctionPass ^createGVNPass(bool NoLoads);
	static FunctionPass ^createMemCpyOptPass();
	static Pass ^createLoopDeletionPass();
	static FunctionPass ^createSimplifyLibCallsPass();
	static FunctionPass ^createCodeGenPreparePass();
	//static FunctionPass ^createCodeGenPreparePass(TargetLowering ^TLI);
	static FunctionPass ^createInstructionNamerPass();
	static FunctionPass ^createSinkingPass();
	static Pass ^createLowerAtomicPass();
	static Pass ^createCorrelatedValuePropagationPass();
	static FunctionPass ^createInstructionSimplifierPass();
	static FunctionPass ^createLowerExpectIntrinsicPass();
};

}
