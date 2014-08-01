#include "Passes.h"
#include "Pass.h"
#include "PassRegistry.h"
#include "raw_ostream.h"
#include <msclr/marshal_cppstd.h>
#include <string>

using namespace LLVM;

ModulePass ^Passes::createPrintModulePass(raw_ostream ^OS)
{
	return ModulePass::_wrap(llvm::createPrintModulePass(OS->base));
}
ModulePass ^Passes::createPrintModulePass(raw_ostream ^OS, bool DeleteStream)
{
	return ModulePass::_wrap(llvm::createPrintModulePass(OS->base, DeleteStream));
}
ModulePass ^Passes::createPrintModulePass(raw_ostream ^OS, bool DeleteStream, System::String ^Banner)
{
	return ModulePass::_wrap(llvm::createPrintModulePass(OS->base, DeleteStream, msclr::interop::marshal_as<std::string>(Banner)));
}
FunctionPass ^Passes::createPrintFunctionPass(System::String ^Banner, raw_ostream ^OS)
{
	return FunctionPass::_wrap(llvm::createPrintFunctionPass(msclr::interop::marshal_as<std::string>(Banner), OS->base));
}
FunctionPass ^Passes::createPrintFunctionPass(System::String ^Banner, raw_ostream ^OS, bool DeleteStream)
{
	return FunctionPass::_wrap(llvm::createPrintFunctionPass(msclr::interop::marshal_as<std::string>(Banner), OS->base, DeleteStream));
}
BasicBlockPass ^Passes::createPrintBasicBlockPass(raw_ostream ^OS)
{
	return BasicBlockPass::_wrap(llvm::createPrintBasicBlockPass(OS->base));
}
BasicBlockPass ^Passes::createPrintBasicBlockPass(raw_ostream ^OS, bool DeleteStream)
{
	return BasicBlockPass::_wrap(llvm::createPrintBasicBlockPass(OS->base, DeleteStream));
}
BasicBlockPass ^Passes::createPrintBasicBlockPass(raw_ostream ^OS, bool DeleteStream, System::String ^Banner)
{
	return BasicBlockPass::_wrap(llvm::createPrintBasicBlockPass(OS->base, DeleteStream, msclr::interop::marshal_as<std::string>(Banner)));
}

void Passes::initializeCore(PassRegistry ^registry)
{
	llvm::initializeCore(*registry->base);
}
void Passes::initializeTransformUtils(PassRegistry ^registry)
{
	llvm::initializeTransformUtils(*registry->base);
}
void Passes::initializeScalarOpts(PassRegistry ^registry)
{
	llvm::initializeScalarOpts(*registry->base);
}
void Passes::initializeObjCARCOpts(PassRegistry ^registry)
{
	llvm::initializeObjCARCOpts(*registry->base);
}
void Passes::initializeVectorization(PassRegistry ^registry)
{
	llvm::initializeVectorization(*registry->base);
}
void Passes::initializeInstCombine(PassRegistry ^registry)
{
	llvm::initializeInstCombine(*registry->base);
}
void Passes::initializeIPO(PassRegistry ^registry)
{
	llvm::initializeIPO(*registry->base);
}
void Passes::initializeInstrumentation(PassRegistry ^registry)
{
	llvm::initializeInstrumentation(*registry->base);
}
void Passes::initializeAnalysis(PassRegistry ^registry)
{
	llvm::initializeAnalysis(*registry->base);
}
void Passes::initializeIPA(PassRegistry ^registry)
{
	llvm::initializeIPA(*registry->base);
}
void Passes::initializeCodeGen(PassRegistry ^registry)
{
	llvm::initializeCodeGen(*registry->base);
}
void Passes::initializeTarget(PassRegistry ^registry)
{
	llvm::initializeTarget(*registry->base);
}
void Passes::initializeAAEvalPass(PassRegistry ^registry)
{
	llvm::initializeAAEvalPass(*registry->base);
}
void Passes::initializeADCEPass(PassRegistry ^registry)
{
	llvm::initializeADCEPass(*registry->base);
}
void Passes::initializeAliasAnalysisAnalysisGroup(PassRegistry ^registry)
{
	llvm::initializeAliasAnalysisAnalysisGroup(*registry->base);
}
void Passes::initializeAliasAnalysisCounterPass(PassRegistry ^registry)
{
	llvm::initializeAliasAnalysisCounterPass(*registry->base);
}
void Passes::initializeAliasDebuggerPass(PassRegistry ^registry)
{
	llvm::initializeAliasDebuggerPass(*registry->base);
}
void Passes::initializeAliasSetPrinterPass(PassRegistry ^registry)
{
	llvm::initializeAliasSetPrinterPass(*registry->base);
}
void Passes::initializeAlwaysInlinerPass(PassRegistry ^registry)
{
	llvm::initializeAlwaysInlinerPass(*registry->base);
}
void Passes::initializeArgPromotionPass(PassRegistry ^registry)
{
	llvm::initializeArgPromotionPass(*registry->base);
}
void Passes::initializeBarrierNoopPass(PassRegistry ^registry)
{
	llvm::initializeBarrierNoopPass(*registry->base);
}
void Passes::initializeBasicAliasAnalysisPass(PassRegistry ^registry)
{
	llvm::initializeBasicAliasAnalysisPass(*registry->base);
}
void Passes::initializeBasicCallGraphPass(PassRegistry ^registry)
{
	llvm::initializeBasicCallGraphPass(*registry->base);
}
void Passes::initializeBasicTTIPass(PassRegistry ^registry)
{
	llvm::initializeBasicTTIPass(*registry->base);
}
void Passes::initializeBlockExtractorPassPass(PassRegistry ^registry)
{
	llvm::initializeBlockExtractorPassPass(*registry->base);
}
void Passes::initializeBlockFrequencyInfoPass(PassRegistry ^registry)
{
	llvm::initializeBlockFrequencyInfoPass(*registry->base);
}
void Passes::initializeBlockPlacementPass(PassRegistry ^registry)
{
	llvm::initializeBlockPlacementPass(*registry->base);
}
void Passes::initializeBoundsCheckingPass(PassRegistry ^registry)
{
	llvm::initializeBoundsCheckingPass(*registry->base);
}
void Passes::initializeBranchFolderPassPass(PassRegistry ^registry)
{
	llvm::initializeBranchFolderPassPass(*registry->base);
}
void Passes::initializeBranchProbabilityInfoPass(PassRegistry ^registry)
{
	llvm::initializeBranchProbabilityInfoPass(*registry->base);
}
void Passes::initializeBreakCriticalEdgesPass(PassRegistry ^registry)
{
	llvm::initializeBreakCriticalEdgesPass(*registry->base);
}
void Passes::initializeCallGraphPrinterPass(PassRegistry ^registry)
{
	llvm::initializeCallGraphPrinterPass(*registry->base);
}
void Passes::initializeCallGraphViewerPass(PassRegistry ^registry)
{
	llvm::initializeCallGraphViewerPass(*registry->base);
}
void Passes::initializeCFGOnlyPrinterPass(PassRegistry ^registry)
{
	llvm::initializeCFGOnlyPrinterPass(*registry->base);
}
void Passes::initializeCFGOnlyViewerPass(PassRegistry ^registry)
{
	llvm::initializeCFGOnlyViewerPass(*registry->base);
}
void Passes::initializeCFGPrinterPass(PassRegistry ^registry)
{
	llvm::initializeCFGPrinterPass(*registry->base);
}
void Passes::initializeCFGSimplifyPassPass(PassRegistry ^registry)
{
	llvm::initializeCFGSimplifyPassPass(*registry->base);
}
void Passes::initializeCFGViewerPass(PassRegistry ^registry)
{
	llvm::initializeCFGViewerPass(*registry->base);
}
void Passes::initializeCalculateSpillWeightsPass(PassRegistry ^registry)
{
	llvm::initializeCalculateSpillWeightsPass(*registry->base);
}
void Passes::initializeCallGraphAnalysisGroup(PassRegistry ^registry)
{
	llvm::initializeCallGraphAnalysisGroup(*registry->base);
}
void Passes::initializeCodeGenPreparePass(PassRegistry ^registry)
{
	llvm::initializeCodeGenPreparePass(*registry->base);
}
void Passes::initializeConstantMergePass(PassRegistry ^registry)
{
	llvm::initializeConstantMergePass(*registry->base);
}
void Passes::initializeConstantPropagationPass(PassRegistry ^registry)
{
	llvm::initializeConstantPropagationPass(*registry->base);
}
void Passes::initializeMachineCopyPropagationPass(PassRegistry ^registry)
{
	llvm::initializeMachineCopyPropagationPass(*registry->base);
}
void Passes::initializeCostModelAnalysisPass(PassRegistry ^registry)
{
	llvm::initializeCostModelAnalysisPass(*registry->base);
}
void Passes::initializeCorrelatedValuePropagationPass(PassRegistry ^registry)
{
	llvm::initializeCorrelatedValuePropagationPass(*registry->base);
}
void Passes::initializeDAEPass(PassRegistry ^registry)
{
	llvm::initializeDAEPass(*registry->base);
}
void Passes::initializeDAHPass(PassRegistry ^registry)
{
	llvm::initializeDAHPass(*registry->base);
}
void Passes::initializeDCEPass(PassRegistry ^registry)
{
	llvm::initializeDCEPass(*registry->base);
}
void Passes::initializeDSEPass(PassRegistry ^registry)
{
	llvm::initializeDSEPass(*registry->base);
}
void Passes::initializeDeadInstEliminationPass(PassRegistry ^registry)
{
	llvm::initializeDeadInstEliminationPass(*registry->base);
}
void Passes::initializeDeadMachineInstructionElimPass(PassRegistry ^registry)
{
	llvm::initializeDeadMachineInstructionElimPass(*registry->base);
}
void Passes::initializeDependenceAnalysisPass(PassRegistry ^registry)
{
	llvm::initializeDependenceAnalysisPass(*registry->base);
}
void Passes::initializeDomOnlyPrinterPass(PassRegistry ^registry)
{
	llvm::initializeDomOnlyPrinterPass(*registry->base);
}
void Passes::initializeDomOnlyViewerPass(PassRegistry ^registry)
{
	llvm::initializeDomOnlyViewerPass(*registry->base);
}
void Passes::initializeDomPrinterPass(PassRegistry ^registry)
{
	llvm::initializeDomPrinterPass(*registry->base);
}
void Passes::initializeDomViewerPass(PassRegistry ^registry)
{
	llvm::initializeDomViewerPass(*registry->base);
}
void Passes::initializeDominanceFrontierPass(PassRegistry ^registry)
{
	llvm::initializeDominanceFrontierPass(*registry->base);
}
void Passes::initializeDominatorTreePass(PassRegistry ^registry)
{
	llvm::initializeDominatorTreePass(*registry->base);
}
void Passes::initializeEarlyIfConverterPass(PassRegistry ^registry)
{
	llvm::initializeEarlyIfConverterPass(*registry->base);
}
void Passes::initializeEdgeBundlesPass(PassRegistry ^registry)
{
	llvm::initializeEdgeBundlesPass(*registry->base);
}
void Passes::initializeEdgeProfilerPass(PassRegistry ^registry)
{
	llvm::initializeEdgeProfilerPass(*registry->base);
}
void Passes::initializeExpandPostRAPass(PassRegistry ^registry)
{
	llvm::initializeExpandPostRAPass(*registry->base);
}
void Passes::initializePathProfilerPass(PassRegistry ^registry)
{
	llvm::initializePathProfilerPass(*registry->base);
}
void Passes::initializeGCOVProfilerPass(PassRegistry ^registry)
{
	llvm::initializeGCOVProfilerPass(*registry->base);
}
void Passes::initializeAddressSanitizerPass(PassRegistry ^registry)
{
	llvm::initializeAddressSanitizerPass(*registry->base);
}
void Passes::initializeAddressSanitizerModulePass(PassRegistry ^registry)
{
	llvm::initializeAddressSanitizerModulePass(*registry->base);
}
void Passes::initializeMemorySanitizerPass(PassRegistry ^registry)
{
	llvm::initializeMemorySanitizerPass(*registry->base);
}
void Passes::initializeThreadSanitizerPass(PassRegistry ^registry)
{
	llvm::initializeThreadSanitizerPass(*registry->base);
}
void Passes::initializeEarlyCSEPass(PassRegistry ^registry)
{
	llvm::initializeEarlyCSEPass(*registry->base);
}
void Passes::initializeExpandISelPseudosPass(PassRegistry ^registry)
{
	llvm::initializeExpandISelPseudosPass(*registry->base);
}
void Passes::initializeFindUsedTypesPass(PassRegistry ^registry)
{
	llvm::initializeFindUsedTypesPass(*registry->base);
}
void Passes::initializeFunctionAttrsPass(PassRegistry ^registry)
{
	llvm::initializeFunctionAttrsPass(*registry->base);
}
void Passes::initializeGCMachineCodeAnalysisPass(PassRegistry ^registry)
{
	llvm::initializeGCMachineCodeAnalysisPass(*registry->base);
}
void Passes::initializeGCModuleInfoPass(PassRegistry ^registry)
{
	llvm::initializeGCModuleInfoPass(*registry->base);
}
void Passes::initializeGVNPass(PassRegistry ^registry)
{
	llvm::initializeGVNPass(*registry->base);
}
void Passes::initializeGlobalDCEPass(PassRegistry ^registry)
{
	llvm::initializeGlobalDCEPass(*registry->base);
}
void Passes::initializeGlobalOptPass(PassRegistry ^registry)
{
	llvm::initializeGlobalOptPass(*registry->base);
}
void Passes::initializeGlobalsModRefPass(PassRegistry ^registry)
{
	llvm::initializeGlobalsModRefPass(*registry->base);
}
void Passes::initializeIPCPPass(PassRegistry ^registry)
{
	llvm::initializeIPCPPass(*registry->base);
}
void Passes::initializeIPSCCPPass(PassRegistry ^registry)
{
	llvm::initializeIPSCCPPass(*registry->base);
}
void Passes::initializeIVUsersPass(PassRegistry ^registry)
{
	llvm::initializeIVUsersPass(*registry->base);
}
void Passes::initializeIfConverterPass(PassRegistry ^registry)
{
	llvm::initializeIfConverterPass(*registry->base);
}
void Passes::initializeIndVarSimplifyPass(PassRegistry ^registry)
{
	llvm::initializeIndVarSimplifyPass(*registry->base);
}
void Passes::initializeInlineCostAnalysisPass(PassRegistry ^registry)
{
	llvm::initializeInlineCostAnalysisPass(*registry->base);
}
void Passes::initializeInstCombinerPass(PassRegistry ^registry)
{
	llvm::initializeInstCombinerPass(*registry->base);
}
void Passes::initializeInstCountPass(PassRegistry ^registry)
{
	llvm::initializeInstCountPass(*registry->base);
}
void Passes::initializeInstNamerPass(PassRegistry ^registry)
{
	llvm::initializeInstNamerPass(*registry->base);
}
void Passes::initializeInternalizePassPass(PassRegistry ^registry)
{
	llvm::initializeInternalizePassPass(*registry->base);
}
void Passes::initializeIntervalPartitionPass(PassRegistry ^registry)
{
	llvm::initializeIntervalPartitionPass(*registry->base);
}
void Passes::initializeJumpThreadingPass(PassRegistry ^registry)
{
	llvm::initializeJumpThreadingPass(*registry->base);
}
void Passes::initializeLCSSAPass(PassRegistry ^registry)
{
	llvm::initializeLCSSAPass(*registry->base);
}
void Passes::initializeLICMPass(PassRegistry ^registry)
{
	llvm::initializeLICMPass(*registry->base);
}
void Passes::initializeLazyValueInfoPass(PassRegistry ^registry)
{
	llvm::initializeLazyValueInfoPass(*registry->base);
}
void Passes::initializeLibCallAliasAnalysisPass(PassRegistry ^registry)
{
	llvm::initializeLibCallAliasAnalysisPass(*registry->base);
}
void Passes::initializeLintPass(PassRegistry ^registry)
{
	llvm::initializeLintPass(*registry->base);
}
void Passes::initializeLiveDebugVariablesPass(PassRegistry ^registry)
{
	llvm::initializeLiveDebugVariablesPass(*registry->base);
}
void Passes::initializeLiveIntervalsPass(PassRegistry ^registry)
{
	llvm::initializeLiveIntervalsPass(*registry->base);
}
void Passes::initializeLiveRegMatrixPass(PassRegistry ^registry)
{
	llvm::initializeLiveRegMatrixPass(*registry->base);
}
void Passes::initializeLiveStacksPass(PassRegistry ^registry)
{
	llvm::initializeLiveStacksPass(*registry->base);
}
void Passes::initializeLiveVariablesPass(PassRegistry ^registry)
{
	llvm::initializeLiveVariablesPass(*registry->base);
}
void Passes::initializeLoaderPassPass(PassRegistry ^registry)
{
	llvm::initializeLoaderPassPass(*registry->base);
}
void Passes::initializeProfileMetadataLoaderPassPass(PassRegistry ^registry)
{
	llvm::initializeProfileMetadataLoaderPassPass(*registry->base);
}
void Passes::initializePathProfileLoaderPassPass(PassRegistry ^registry)
{
	llvm::initializePathProfileLoaderPassPass(*registry->base);
}
void Passes::initializeLocalStackSlotPassPass(PassRegistry ^registry)
{
	llvm::initializeLocalStackSlotPassPass(*registry->base);
}
void Passes::initializeLoopDeletionPass(PassRegistry ^registry)
{
	llvm::initializeLoopDeletionPass(*registry->base);
}
void Passes::initializeLoopExtractorPass(PassRegistry ^registry)
{
	llvm::initializeLoopExtractorPass(*registry->base);
}
void Passes::initializeLoopInfoPass(PassRegistry ^registry)
{
	llvm::initializeLoopInfoPass(*registry->base);
}
void Passes::initializeLoopInstSimplifyPass(PassRegistry ^registry)
{
	llvm::initializeLoopInstSimplifyPass(*registry->base);
}
void Passes::initializeLoopRotatePass(PassRegistry ^registry)
{
	llvm::initializeLoopRotatePass(*registry->base);
}
void Passes::initializeLoopSimplifyPass(PassRegistry ^registry)
{
	llvm::initializeLoopSimplifyPass(*registry->base);
}
void Passes::initializeLoopStrengthReducePass(PassRegistry ^registry)
{
	llvm::initializeLoopStrengthReducePass(*registry->base);
}
void Passes::initializeGlobalMergePass(PassRegistry ^registry)
{
	llvm::initializeGlobalMergePass(*registry->base);
}
void Passes::initializeLoopUnrollPass(PassRegistry ^registry)
{
	llvm::initializeLoopUnrollPass(*registry->base);
}
void Passes::initializeLoopUnswitchPass(PassRegistry ^registry)
{
	llvm::initializeLoopUnswitchPass(*registry->base);
}
void Passes::initializeLoopIdiomRecognizePass(PassRegistry ^registry)
{
	llvm::initializeLoopIdiomRecognizePass(*registry->base);
}
void Passes::initializeLowerAtomicPass(PassRegistry ^registry)
{
	llvm::initializeLowerAtomicPass(*registry->base);
}
void Passes::initializeLowerExpectIntrinsicPass(PassRegistry ^registry)
{
	llvm::initializeLowerExpectIntrinsicPass(*registry->base);
}
void Passes::initializeLowerIntrinsicsPass(PassRegistry ^registry)
{
	llvm::initializeLowerIntrinsicsPass(*registry->base);
}
void Passes::initializeLowerInvokePass(PassRegistry ^registry)
{
	llvm::initializeLowerInvokePass(*registry->base);
}
void Passes::initializeLowerSwitchPass(PassRegistry ^registry)
{
	llvm::initializeLowerSwitchPass(*registry->base);
}
void Passes::initializeMachineBlockFrequencyInfoPass(PassRegistry ^registry)
{
	llvm::initializeMachineBlockFrequencyInfoPass(*registry->base);
}
void Passes::initializeMachineBlockPlacementPass(PassRegistry ^registry)
{
	llvm::initializeMachineBlockPlacementPass(*registry->base);
}
void Passes::initializeMachineBlockPlacementStatsPass(PassRegistry ^registry)
{
	llvm::initializeMachineBlockPlacementStatsPass(*registry->base);
}
void Passes::initializeMachineBranchProbabilityInfoPass(PassRegistry ^registry)
{
	llvm::initializeMachineBranchProbabilityInfoPass(*registry->base);
}
void Passes::initializeMachineCSEPass(PassRegistry ^registry)
{
	llvm::initializeMachineCSEPass(*registry->base);
}
void Passes::initializeMachineDominatorTreePass(PassRegistry ^registry)
{
	llvm::initializeMachineDominatorTreePass(*registry->base);
}
void Passes::initializeMachinePostDominatorTreePass(PassRegistry ^registry)
{
	llvm::initializeMachinePostDominatorTreePass(*registry->base);
}
void Passes::initializeMachineLICMPass(PassRegistry ^registry)
{
	llvm::initializeMachineLICMPass(*registry->base);
}
void Passes::initializeMachineLoopInfoPass(PassRegistry ^registry)
{
	llvm::initializeMachineLoopInfoPass(*registry->base);
}
void Passes::initializeMachineModuleInfoPass(PassRegistry ^registry)
{
	llvm::initializeMachineModuleInfoPass(*registry->base);
}
void Passes::initializeMachineSchedulerPass(PassRegistry ^registry)
{
	llvm::initializeMachineSchedulerPass(*registry->base);
}
void Passes::initializeMachineSinkingPass(PassRegistry ^registry)
{
	llvm::initializeMachineSinkingPass(*registry->base);
}
void Passes::initializeMachineTraceMetricsPass(PassRegistry ^registry)
{
	llvm::initializeMachineTraceMetricsPass(*registry->base);
}
void Passes::initializeMachineVerifierPassPass(PassRegistry ^registry)
{
	llvm::initializeMachineVerifierPassPass(*registry->base);
}
void Passes::initializeMemCpyOptPass(PassRegistry ^registry)
{
	llvm::initializeMemCpyOptPass(*registry->base);
}
void Passes::initializeMemDepPrinterPass(PassRegistry ^registry)
{
	llvm::initializeMemDepPrinterPass(*registry->base);
}
void Passes::initializeMemoryDependenceAnalysisPass(PassRegistry ^registry)
{
	llvm::initializeMemoryDependenceAnalysisPass(*registry->base);
}
void Passes::initializeMetaRenamerPass(PassRegistry ^registry)
{
	llvm::initializeMetaRenamerPass(*registry->base);
}
void Passes::initializeMergeFunctionsPass(PassRegistry ^registry)
{
	llvm::initializeMergeFunctionsPass(*registry->base);
}
void Passes::initializeModuleDebugInfoPrinterPass(PassRegistry ^registry)
{
	llvm::initializeModuleDebugInfoPrinterPass(*registry->base);
}
void Passes::initializeNoAAPass(PassRegistry ^registry)
{
	llvm::initializeNoAAPass(*registry->base);
}
void Passes::initializeNoProfileInfoPass(PassRegistry ^registry)
{
	llvm::initializeNoProfileInfoPass(*registry->base);
}
void Passes::initializeNoPathProfileInfoPass(PassRegistry ^registry)
{
	llvm::initializeNoPathProfileInfoPass(*registry->base);
}
void Passes::initializeObjCARCAliasAnalysisPass(PassRegistry ^registry)
{
	llvm::initializeObjCARCAliasAnalysisPass(*registry->base);
}
void Passes::initializeObjCARCAPElimPass(PassRegistry ^registry)
{
	llvm::initializeObjCARCAPElimPass(*registry->base);
}
void Passes::initializeObjCARCExpandPass(PassRegistry ^registry)
{
	llvm::initializeObjCARCExpandPass(*registry->base);
}
void Passes::initializeObjCARCContractPass(PassRegistry ^registry)
{
	llvm::initializeObjCARCContractPass(*registry->base);
}
void Passes::initializeObjCARCOptPass(PassRegistry ^registry)
{
	llvm::initializeObjCARCOptPass(*registry->base);
}
void Passes::initializeOptimalEdgeProfilerPass(PassRegistry ^registry)
{
	llvm::initializeOptimalEdgeProfilerPass(*registry->base);
}
void Passes::initializeOptimizePHIsPass(PassRegistry ^registry)
{
	llvm::initializeOptimizePHIsPass(*registry->base);
}
void Passes::initializePEIPass(PassRegistry ^registry)
{
	llvm::initializePEIPass(*registry->base);
}
void Passes::initializePHIEliminationPass(PassRegistry ^registry)
{
	llvm::initializePHIEliminationPass(*registry->base);
}
void Passes::initializePartialInlinerPass(PassRegistry ^registry)
{
	llvm::initializePartialInlinerPass(*registry->base);
}
void Passes::initializePeepholeOptimizerPass(PassRegistry ^registry)
{
	llvm::initializePeepholeOptimizerPass(*registry->base);
}
void Passes::initializePostDomOnlyPrinterPass(PassRegistry ^registry)
{
	llvm::initializePostDomOnlyPrinterPass(*registry->base);
}
void Passes::initializePostDomOnlyViewerPass(PassRegistry ^registry)
{
	llvm::initializePostDomOnlyViewerPass(*registry->base);
}
void Passes::initializePostDomPrinterPass(PassRegistry ^registry)
{
	llvm::initializePostDomPrinterPass(*registry->base);
}
void Passes::initializePostDomViewerPass(PassRegistry ^registry)
{
	llvm::initializePostDomViewerPass(*registry->base);
}
void Passes::initializePostDominatorTreePass(PassRegistry ^registry)
{
	llvm::initializePostDominatorTreePass(*registry->base);
}
void Passes::initializePostRASchedulerPass(PassRegistry ^registry)
{
	llvm::initializePostRASchedulerPass(*registry->base);
}
void Passes::initializePreVerifierPass(PassRegistry ^registry)
{
	llvm::initializePreVerifierPass(*registry->base);
}
void Passes::initializePrintFunctionPassPass(PassRegistry ^registry)
{
	llvm::initializePrintFunctionPassPass(*registry->base);
}
void Passes::initializePrintModulePassPass(PassRegistry ^registry)
{
	llvm::initializePrintModulePassPass(*registry->base);
}
void Passes::initializePrintBasicBlockPassPass(PassRegistry ^registry)
{
	llvm::initializePrintBasicBlockPassPass(*registry->base);
}
void Passes::initializeProcessImplicitDefsPass(PassRegistry ^registry)
{
	llvm::initializeProcessImplicitDefsPass(*registry->base);
}
void Passes::initializeProfileEstimatorPassPass(PassRegistry ^registry)
{
	llvm::initializeProfileEstimatorPassPass(*registry->base);
}
void Passes::initializeProfileInfoAnalysisGroup(PassRegistry ^registry)
{
	llvm::initializeProfileInfoAnalysisGroup(*registry->base);
}
void Passes::initializePathProfileInfoAnalysisGroup(PassRegistry ^registry)
{
	llvm::initializePathProfileInfoAnalysisGroup(*registry->base);
}
void Passes::initializePathProfileVerifierPass(PassRegistry ^registry)
{
	llvm::initializePathProfileVerifierPass(*registry->base);
}
void Passes::initializeProfileVerifierPassPass(PassRegistry ^registry)
{
	llvm::initializeProfileVerifierPassPass(*registry->base);
}
void Passes::initializePromotePassPass(PassRegistry ^registry)
{
	llvm::initializePromotePassPass(*registry->base);
}
void Passes::initializePruneEHPass(PassRegistry ^registry)
{
	llvm::initializePruneEHPass(*registry->base);
}
void Passes::initializeReassociatePass(PassRegistry ^registry)
{
	llvm::initializeReassociatePass(*registry->base);
}
void Passes::initializeRegToMemPass(PassRegistry ^registry)
{
	llvm::initializeRegToMemPass(*registry->base);
}
void Passes::initializeRegionInfoPass(PassRegistry ^registry)
{
	llvm::initializeRegionInfoPass(*registry->base);
}
void Passes::initializeRegionOnlyPrinterPass(PassRegistry ^registry)
{
	llvm::initializeRegionOnlyPrinterPass(*registry->base);
}
void Passes::initializeRegionOnlyViewerPass(PassRegistry ^registry)
{
	llvm::initializeRegionOnlyViewerPass(*registry->base);
}
void Passes::initializeRegionPrinterPass(PassRegistry ^registry)
{
	llvm::initializeRegionPrinterPass(*registry->base);
}
void Passes::initializeRegionViewerPass(PassRegistry ^registry)
{
	llvm::initializeRegionViewerPass(*registry->base);
}
void Passes::initializeSCCPPass(PassRegistry ^registry)
{
	llvm::initializeSCCPPass(*registry->base);
}
void Passes::initializeSROAPass(PassRegistry ^registry)
{
	llvm::initializeSROAPass(*registry->base);
}
void Passes::initializeSROA_DTPass(PassRegistry ^registry)
{
	llvm::initializeSROA_DTPass(*registry->base);
}
void Passes::initializeSROA_SSAUpPass(PassRegistry ^registry)
{
	llvm::initializeSROA_SSAUpPass(*registry->base);
}
void Passes::initializeScalarEvolutionAliasAnalysisPass(PassRegistry ^registry)
{
	llvm::initializeScalarEvolutionAliasAnalysisPass(*registry->base);
}
void Passes::initializeScalarEvolutionPass(PassRegistry ^registry)
{
	llvm::initializeScalarEvolutionPass(*registry->base);
}
void Passes::initializeSimpleInlinerPass(PassRegistry ^registry)
{
	llvm::initializeSimpleInlinerPass(*registry->base);
}
void Passes::initializeRegisterCoalescerPass(PassRegistry ^registry)
{
	llvm::initializeRegisterCoalescerPass(*registry->base);
}
void Passes::initializeSimplifyLibCallsPass(PassRegistry ^registry)
{
	llvm::initializeSimplifyLibCallsPass(*registry->base);
}
void Passes::initializeSingleLoopExtractorPass(PassRegistry ^registry)
{
	llvm::initializeSingleLoopExtractorPass(*registry->base);
}
void Passes::initializeSinkingPass(PassRegistry ^registry)
{
	llvm::initializeSinkingPass(*registry->base);
}
void Passes::initializeSlotIndexesPass(PassRegistry ^registry)
{
	llvm::initializeSlotIndexesPass(*registry->base);
}
void Passes::initializeSpillPlacementPass(PassRegistry ^registry)
{
	llvm::initializeSpillPlacementPass(*registry->base);
}
void Passes::initializeStackProtectorPass(PassRegistry ^registry)
{
	llvm::initializeStackProtectorPass(*registry->base);
}
void Passes::initializeStackColoringPass(PassRegistry ^registry)
{
	llvm::initializeStackColoringPass(*registry->base);
}
void Passes::initializeStackSlotColoringPass(PassRegistry ^registry)
{
	llvm::initializeStackSlotColoringPass(*registry->base);
}
void Passes::initializeStripDeadDebugInfoPass(PassRegistry ^registry)
{
	llvm::initializeStripDeadDebugInfoPass(*registry->base);
}
void Passes::initializeStripDeadPrototypesPassPass(PassRegistry ^registry)
{
	llvm::initializeStripDeadPrototypesPassPass(*registry->base);
}
void Passes::initializeStripDebugDeclarePass(PassRegistry ^registry)
{
	llvm::initializeStripDebugDeclarePass(*registry->base);
}
void Passes::initializeStripNonDebugSymbolsPass(PassRegistry ^registry)
{
	llvm::initializeStripNonDebugSymbolsPass(*registry->base);
}
void Passes::initializeStripSymbolsPass(PassRegistry ^registry)
{
	llvm::initializeStripSymbolsPass(*registry->base);
}
void Passes::initializeStrongPHIEliminationPass(PassRegistry ^registry)
{
	llvm::initializeStrongPHIEliminationPass(*registry->base);
}
void Passes::initializeTailCallElimPass(PassRegistry ^registry)
{
	llvm::initializeTailCallElimPass(*registry->base);
}
void Passes::initializeTailDuplicatePassPass(PassRegistry ^registry)
{
	llvm::initializeTailDuplicatePassPass(*registry->base);
}
void Passes::initializeTargetPassConfigPass(PassRegistry ^registry)
{
	llvm::initializeTargetPassConfigPass(*registry->base);
}
void Passes::initializeDataLayoutPass(PassRegistry ^registry)
{
	llvm::initializeDataLayoutPass(*registry->base);
}
void Passes::initializeTargetTransformInfoAnalysisGroup(PassRegistry ^registry)
{
	llvm::initializeTargetTransformInfoAnalysisGroup(*registry->base);
}
void Passes::initializeNoTTIPass(PassRegistry ^registry)
{
	llvm::initializeNoTTIPass(*registry->base);
}
void Passes::initializeTargetLibraryInfoPass(PassRegistry ^registry)
{
	llvm::initializeTargetLibraryInfoPass(*registry->base);
}
void Passes::initializeTwoAddressInstructionPassPass(PassRegistry ^registry)
{
	llvm::initializeTwoAddressInstructionPassPass(*registry->base);
}
void Passes::initializeTypeBasedAliasAnalysisPass(PassRegistry ^registry)
{
	llvm::initializeTypeBasedAliasAnalysisPass(*registry->base);
}
void Passes::initializeUnifyFunctionExitNodesPass(PassRegistry ^registry)
{
	llvm::initializeUnifyFunctionExitNodesPass(*registry->base);
}
void Passes::initializeUnreachableBlockElimPass(PassRegistry ^registry)
{
	llvm::initializeUnreachableBlockElimPass(*registry->base);
}
void Passes::initializeUnreachableMachineBlockElimPass(PassRegistry ^registry)
{
	llvm::initializeUnreachableMachineBlockElimPass(*registry->base);
}
void Passes::initializeVerifierPass(PassRegistry ^registry)
{
	llvm::initializeVerifierPass(*registry->base);
}
void Passes::initializeVirtRegMapPass(PassRegistry ^registry)
{
	llvm::initializeVirtRegMapPass(*registry->base);
}
void Passes::initializeVirtRegRewriterPass(PassRegistry ^registry)
{
	llvm::initializeVirtRegRewriterPass(*registry->base);
}
void Passes::initializeInstSimplifierPass(PassRegistry ^registry)
{
	llvm::initializeInstSimplifierPass(*registry->base);
}
void Passes::initializeUnpackMachineBundlesPass(PassRegistry ^registry)
{
	llvm::initializeUnpackMachineBundlesPass(*registry->base);
}
void Passes::initializeFinalizeMachineBundlesPass(PassRegistry ^registry)
{
	llvm::initializeFinalizeMachineBundlesPass(*registry->base);
}
void Passes::initializeLoopVectorizePass(PassRegistry ^registry)
{
	llvm::initializeLoopVectorizePass(*registry->base);
}
void Passes::initializeSLPVectorizerPass(PassRegistry ^registry)
{
	llvm::initializeSLPVectorizerPass(*registry->base);
}
void Passes::initializeBBVectorizePass(PassRegistry ^registry)
{
	llvm::initializeBBVectorizePass(*registry->base);
}
void Passes::initializeMachineFunctionPrinterPassPass(PassRegistry ^registry)
{
	llvm::initializeMachineFunctionPrinterPassPass(*registry->base);
}
