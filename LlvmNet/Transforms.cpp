#include "Transforms.h"
#include "Pass.h"
//#include "llvm/Target/TargetLowering.h"

using namespace LLVM;

FunctionPass ^Transforms::createConstantPropagationPass()
{
	return FunctionPass::_wrap(llvm::createConstantPropagationPass());
}
FunctionPass ^Transforms::createSCCPPass()
{
	return FunctionPass::_wrap(llvm::createSCCPPass());
}
Pass ^Transforms::createDeadInstEliminationPass()
{
	return Pass::_wrap(llvm::createDeadInstEliminationPass());
}
FunctionPass ^Transforms::createDeadCodeEliminationPass()
{
	return FunctionPass::_wrap(llvm::createDeadCodeEliminationPass());
}
FunctionPass ^Transforms::createDeadStoreEliminationPass()
{
	return FunctionPass::_wrap(llvm::createDeadStoreEliminationPass());
}
FunctionPass ^Transforms::createAggressiveDCEPass()
{
	return FunctionPass::_wrap(llvm::createAggressiveDCEPass());
}
FunctionPass ^Transforms::createSROAPass()
{
	return FunctionPass::_wrap(llvm::createSROAPass());
}
FunctionPass ^Transforms::createSROAPass(bool RequiresDomTree)
{
	return FunctionPass::_wrap(llvm::createSROAPass(RequiresDomTree));
}
FunctionPass ^Transforms::createScalarReplAggregatesPass()
{
	return FunctionPass::_wrap(llvm::createScalarReplAggregatesPass());
}
FunctionPass ^Transforms::createScalarReplAggregatesPass(signed Threshold)
{
	return FunctionPass::_wrap(llvm::createScalarReplAggregatesPass(Threshold));
}
FunctionPass ^Transforms::createScalarReplAggregatesPass(signed Threshold, bool UseDomTree)
{
	return FunctionPass::_wrap(llvm::createScalarReplAggregatesPass(Threshold, UseDomTree));
}
FunctionPass ^Transforms::createScalarReplAggregatesPass(signed Threshold, bool UseDomTree, signed StructMemberThreshold)
{
	return FunctionPass::_wrap(llvm::createScalarReplAggregatesPass(Threshold, UseDomTree, StructMemberThreshold));
}
FunctionPass ^Transforms::createScalarReplAggregatesPass(signed Threshold, bool UseDomTree, signed StructMemberThreshold, signed ArrayElementThreshold)
{
	return FunctionPass::_wrap(llvm::createScalarReplAggregatesPass(Threshold, UseDomTree, StructMemberThreshold, ArrayElementThreshold));
}
FunctionPass ^Transforms::createScalarReplAggregatesPass(signed Threshold, bool UseDomTree, signed StructMemberThreshold, signed ArrayElementThreshold, signed ScalarLoadThreshold)
{
	return FunctionPass::_wrap(llvm::createScalarReplAggregatesPass(Threshold, UseDomTree, StructMemberThreshold, ArrayElementThreshold, ScalarLoadThreshold));
}
Pass ^Transforms::createIndVarSimplifyPass()
{
	return Pass::_wrap(llvm::createIndVarSimplifyPass());
}
FunctionPass ^Transforms::createInstructionCombiningPass()
{
	return FunctionPass::_wrap(llvm::createInstructionCombiningPass());
}
Pass ^Transforms::createLICMPass()
{
	return Pass::_wrap(llvm::createLICMPass());
}
Pass ^Transforms::createLoopStrengthReducePass()
{
	return Pass::_wrap(llvm::createLoopStrengthReducePass());
}
Pass ^Transforms::createGlobalMergePass()
{
	return Pass::_wrap(llvm::createGlobalMergePass());
}
/*Pass ^Transforms::createGlobalMergePass(TargetLowering ^TLI)
{
	return Pass::_wrap(llvm::createGlobalMergePass(TLI->base));
}*/
Pass ^Transforms::createLoopUnswitchPass()
{
	return Pass::_wrap(llvm::createLoopUnswitchPass());
}
Pass ^Transforms::createLoopUnswitchPass(bool OptimizeForSize)
{
	return Pass::_wrap(llvm::createLoopUnswitchPass(OptimizeForSize));
}
Pass ^Transforms::createLoopInstSimplifyPass()
{
	return Pass::_wrap(llvm::createLoopInstSimplifyPass());
}
Pass ^Transforms::createLoopUnrollPass()
{
	return Pass::_wrap(llvm::createLoopUnrollPass());
}
Pass ^Transforms::createLoopUnrollPass(int Threshold)
{
	return Pass::_wrap(llvm::createLoopUnrollPass(Threshold));
}
Pass ^Transforms::createLoopUnrollPass(int Threshold, int Count)
{
	return Pass::_wrap(llvm::createLoopUnrollPass(Threshold, Count));
}
Pass ^Transforms::createLoopUnrollPass(int Threshold, int Count, int AllowPartial)
{
	return Pass::_wrap(llvm::createLoopUnrollPass(Threshold, Count, AllowPartial));
}
Pass ^Transforms::createLoopRotatePass()
{
	return Pass::_wrap(llvm::createLoopRotatePass());
}
Pass ^Transforms::createLoopIdiomPass()
{
	return Pass::_wrap(llvm::createLoopIdiomPass());
}
FunctionPass ^Transforms::createPromoteMemoryToRegisterPass()
{
	return FunctionPass::_wrap(llvm::createPromoteMemoryToRegisterPass());
}
FunctionPass ^Transforms::createDemoteRegisterToMemoryPass()
{
	return FunctionPass::_wrap(llvm::createDemoteRegisterToMemoryPass());
}
FunctionPass ^Transforms::createReassociatePass()
{
	return FunctionPass::_wrap(llvm::createReassociatePass());
}
FunctionPass ^Transforms::createJumpThreadingPass()
{
	return FunctionPass::_wrap(llvm::createJumpThreadingPass());
}
FunctionPass ^Transforms::createCFGSimplificationPass()
{
	return FunctionPass::_wrap(llvm::createCFGSimplificationPass());
}
FunctionPass ^Transforms::createBreakCriticalEdgesPass()
{
	return FunctionPass::_wrap(llvm::createBreakCriticalEdgesPass());
}
Pass ^Transforms::createLoopSimplifyPass()
{
	return Pass::_wrap(llvm::createLoopSimplifyPass());
}
FunctionPass ^Transforms::createTailCallEliminationPass()
{
	return FunctionPass::_wrap(llvm::createTailCallEliminationPass());
}
FunctionPass ^Transforms::createLowerSwitchPass()
{
	return FunctionPass::_wrap(llvm::createLowerSwitchPass());
}
FunctionPass ^Transforms::createLowerInvokePass()
{
	return FunctionPass::_wrap(llvm::createLowerInvokePass());
}
/*FunctionPass ^Transforms::createLowerInvokePass(TargetLowering ^TLI)
{
	return FunctionPass::_wrap(llvm::createLowerInvokePass(TLI->base));
}
FunctionPass ^Transforms::createLowerInvokePass(TargetLowering ^TLI, bool useExpensiveEHSupport)
{
	return FunctionPass::_wrap(llvm::createLowerInvokePass(TLI->base, useExpensiveEHSupport));
}*/
FunctionPass ^Transforms::createBlockPlacementPass()
{
	return FunctionPass::_wrap(llvm::createBlockPlacementPass());
}
Pass ^Transforms::createLCSSAPass()
{
	return Pass::_wrap(llvm::createLCSSAPass());
}
FunctionPass ^Transforms::createEarlyCSEPass()
{
	return FunctionPass::_wrap(llvm::createEarlyCSEPass());
}
FunctionPass ^Transforms::createGVNPass()
{
	return FunctionPass::_wrap(llvm::createGVNPass());
}
FunctionPass ^Transforms::createGVNPass(bool NoLoads)
{
	return FunctionPass::_wrap(llvm::createGVNPass(NoLoads));
}
FunctionPass ^Transforms::createMemCpyOptPass()
{
	return FunctionPass::_wrap(llvm::createMemCpyOptPass());
}
Pass ^Transforms::createLoopDeletionPass()
{
	return Pass::_wrap(llvm::createLoopDeletionPass());
}
FunctionPass ^Transforms::createSimplifyLibCallsPass()
{
	return FunctionPass::_wrap(llvm::createSimplifyLibCallsPass());
}
FunctionPass ^Transforms::createCodeGenPreparePass()
{
	return FunctionPass::_wrap(llvm::createCodeGenPreparePass());
}
/*FunctionPass ^Transforms::createCodeGenPreparePass(TargetLowering ^TLI)
{
	return FunctionPass::_wrap(llvm::createCodeGenPreparePass(TLI->base));
}*/
FunctionPass ^Transforms::createInstructionNamerPass()
{
	return FunctionPass::_wrap(llvm::createInstructionNamerPass());
}
FunctionPass ^Transforms::createSinkingPass()
{
	return FunctionPass::_wrap(llvm::createSinkingPass());
}
Pass ^Transforms::createLowerAtomicPass()
{
	return Pass::_wrap(llvm::createLowerAtomicPass());
}
Pass ^Transforms::createCorrelatedValuePropagationPass()
{
	return Pass::_wrap(llvm::createCorrelatedValuePropagationPass());
}
FunctionPass ^Transforms::createInstructionSimplifierPass()
{
	return FunctionPass::_wrap(llvm::createInstructionSimplifierPass());
}
FunctionPass ^Transforms::createLowerExpectIntrinsicPass()
{
	return FunctionPass::_wrap(llvm::createLowerExpectIntrinsicPass());
}
