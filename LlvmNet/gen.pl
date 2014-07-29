use strict;

my @prim_types = ('bool', 'int', 'unsigned', 'unsigned short', 'float', 'double', 'uint8_t', 'uint16_t', 'uint32_t', 'uint64_t', 'int8_t', 'int16_t', 'int32_t', 'int64_t', 'size_t');
my %defined_in_class = (
	'BundleLockStateType' => 'MCSectionData',
	'Flags' => 'SymbolRef',
	'OperandValueKind' => 'TargetTransformInfo',
	'RenderStyleKind' => 'Option',
	'NodeKind' => 'Node',
	'ConditionalAssemblyType' => 'AsmCond',
	'TermOps' => 'Instruction',
	'fltCategory' => 'APFloat',
	'StackDirection' => 'TargetFrameLowering',
	'OptionClass' => 'Option',
	'PossibleRelocationsTy' => 'Constant',
	'LoopDisposition' => 'SCEV',
	'LockFileState' => 'LockFileManager',
	'NoWrapFlags' => 'SCEV',
	'UnaryOp' => 'UnOpInit',
	'ExtensionPointTy' => 'PassManagerBuilder',
	'BooleanContent' => 'TargetLoweringBase',
	'LinkerMode' => 'Linker',
	'VisitFlag' => 'ImutAVLTreeGenericIterator',
	'ValueTy' => 'Value',
	'ExprKind' => 'MCExpr',
	'ComplexAddrKind' => 'DIBuilder',
	'ConstraintType' => 'TargetLowering',
	'MIFlag' => 'MachineInstr',
	'CastOps' => 'Instruction',
	'Kind' => 'Archive',
	'LocInfo' => 'CCValAssign',
	'AliasType' => 'AliasSet',
	'NodeColor' => 'BallLarusNode',
	'ArchType' => 'Triple',
	'Endianness' => 'Module',
	'uninitializedTag' => 'APFloat',
	'LinkageTypes' => 'GlobalValue',
	'RelocationType' => 'MachineRelocation',
	'DecodeStatus' => 'MCDisassembler',
	'RecTyKind' => 'RecTy',
	'Tristate' => 'LazyValueInfo',
	'OtherOps' => 'Instruction',
	'PointerSize' => 'Module',
	'BuiltinOpcodes' => 'SelectionDAGISel',
	'CodeGenFileType' => 'TargetMachine',
	'DiagKind' => 'SourceMgr',
	'LegalizeAction' => 'TargetLoweringBase',
	'MemOperandFlags' => 'MachineMemOperand',
	'SectionVariant' => 'MCSection',
	'AliasResult' => 'AliasAnalysis',
	'TargetCostConstants' => 'TargetTransformInfo',
	'VariantKind' => 'MCSymbolRefExpr',
	'OSType' => 'Triple',
	'TernaryOp' => 'TernOpInit',
	'HazardType' => 'ScheduleHazardRecognizer',
	'VendorType' => 'Triple',
	'LegalizeTypeAction' => 'TargetLoweringBase',
	'MachineOperandType' => 'MachineOperand',
	'QueryType' => 'MachineInstr',
	'ModFlagBehavior' => 'Module',
	'AsmDialect' => 'InlineAsm',
	'roundingMode' => 'APFloat',
	'BinOp' => 'AtomicRMWInst',
	'PopcntSupportKind' => 'TargetTransformInfo',
	'OrderKind' => 'SDep',
	'BinaryOps' => 'Instruction',
	'opStatus' => 'APFloat',
	'SequenceType' => 'SequenceNode',
	'BlockDisposition' => 'SCEV',
	'Strategy' => 'MachineTraceMetrics',
	'ThreadLocalMode' => 'GlobalVariable',
	'Type' => 'SymbolRef',
	'PrintStyle' => 'Region',
	'cmpResult' => 'APFloat',
	'Opcode' => 'MCBinaryExpr',
	'RemapFlags' => 'ValueMapTypeRemapper',
	'AttrIndex' => 'AttributeSet',
	'mapmode' => 'mapped_file_region',
	'StreamerKind' => 'MCStreamer',
	'SelectSupportKind' => 'TargetLoweringBase',
	'MatchResultTy' => 'MCTargetAsmParser',
	'SimpleValueType' => 'MVT',
	'MappingType' => 'MappingNode',
	'AccessType' => 'AliasSet',
	'JTEntryKind' => 'MachineJumpTableInfo',
	'BinaryOp' => 'BinOpInit',
	'TypeID' => 'Type',
	'EdgeType' => 'BallLarusEdge',
	'TimeConversions' => 'TimeValue',
	'Colors' => 'raw_ostream',
	'GetPathMode' => 'ProfileInfoT',
	'ID' => 'CallingConv',
	'ConstraintWeight' => 'TargetLowering',
	'FragmentType' => 'MCFragment',
	'ClauseType' => 'LandingPadInst',
	'Encoding' => 'BitCodeAbbrevOp',
	'ManglerPrefixTy' => 'Mangler',
	'ModRefResult' => 'AliasAnalysis',
	'EnvironmentType' => 'Triple',
	'LivenessQueryResult' => 'MachineBasicBlock',
	'CommentFlag' => 'MachineInstr',
	'BufferKind' => 'MemoryBuffer',
	'ProtectionFlags' => 'MemoryBlock',
	'VisibilityTypes' => 'GlobalValue',
	'AttrKind' => 'Attribute',
	'CFIMoveType' => 'AsmPrinter',
	'ConstraintPrefix' => 'InlineAsm',
	'OperationEquivalenceFlags' => 'Instruction',
	'MICheckType' => 'MachineInstr',
	'MemoryOps' => 'Instruction',
	'ShuffleKind' => 'TargetTransformInfo',
	'TokenKind' => 'AsmToken',
	'OpType' => 'MCDwarfFile',
	'Specification' => 'DILineInfoSpecifier',
	'ModRefBehavior' => 'AliasAnalysis',
	'Predicate' => 'CmpInst',
	'InterferenceKind' => 'LiveRegMatrix',

);
my %defined_in = (
	'MCAsmLexer' => 'llvm/MC/MCParser/MCAsmLexer.h',
	'ModulePass' => 'llvm/Pass.h',
	'Briggs' => 'llvm/CodeGen/PBQP/Heuristics/Briggs.h',
	'generic_gep_type_iterator' => 'llvm/Support/GetElementPtrTypeIterator.h',
	'directory_iterator' => 'llvm/Support/FileSystem.h',
	'ConstantFolder' => 'llvm/Support/ConstantFolder.h',
	'SDivOperator' => 'llvm/IR/Operator.h',
	'TargetMachine' => 'llvm/Target/TargetMachine.h',
	'Statistic' => 'llvm/ADT/Statistic.h',
	'UndefValue' => 'llvm/IR/Constants.h',
	'BinaryOperator' => 'llvm/IR/InstrTypes.h',
	'MachineLoop' => 'llvm/CodeGen/MachineLoopInfo.h',
	'ObjectSizeOffsetVisitor' => 'llvm/Analysis/MemoryBuiltins.h',
	'LazyValueInfo' => 'llvm/Analysis/LazyValueInfo.h',
	'MCValue' => 'llvm/MC/MCValue.h',
	'MCELF' => 'llvm/MC/MCELF.h',
	'SuperRegClassIterator' => 'llvm/Target/TargetRegisterInfo.h',
	'mapped_iterator' => 'llvm/ADT/STLExtras.h',
	'Value' => 'llvm/IR/Value.h',
	'has_FlowTraits' => 'llvm/Support/YAMLTraits.h',
	'MachineFrameInfo' => 'llvm/CodeGen/MachineFrameInfo.h',
	'RelocationRef' => 'llvm/Object/ObjectFile.h',
	'SDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'StringMapConstIterator' => 'llvm/ADT/StringMap.h',
	'WeakVH' => 'llvm/Support/ValueHandle.h',
	'IntegersSubsetTy' => 'llvm/Support/IntegersSubsetMapping.h',
	'ResourcePriorityQueue' => 'llvm/CodeGen/ResourcePriorityQueue.h',
	'Dependence' => 'llvm/Analysis/DependenceAnalysis.h',
	'MemDepResult' => 'llvm/Analysis/MemoryDependenceAnalysis.h',
	'OptTable' => 'llvm/Option/OptTable.h',
	'AtomicSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'MCAsmBackend' => 'llvm/MC/MCAsmBackend.h',
	'SDUse' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'CCValAssign' => 'llvm/CodeGen/CallingConvLower.h',
	'LeafNode' => 'llvm/ADT/IntervalMap.h',
	'FPToSIInst' => 'llvm/IR/Instructions.h',
	'RegionNode' => 'llvm/Analysis/RegionInfo.h',
	'AShrOperator' => 'llvm/IR/Operator.h',
	'DataLayout' => 'llvm/IR/DataLayout.h',
	'MachineBranchProbabilityInfo' => 'llvm/CodeGen/MachineBranchProbabilityInfo.h',
	'MCObjectStreamer' => 'llvm/MC/MCObjectStreamer.h',
	'MCAsmParser' => 'llvm/MC/MCParser/MCAsmParser.h',
	'CallGraph' => 'llvm/Analysis/CallGraph.h',
	'value_use_iterator' => 'llvm/IR/Use.h',
	'CallingConv' => 'llvm/IR/CallingConv.h',
	'OptionValueCopy' => 'llvm/Support/CommandLine.h',
	'MCCodeEmitter' => 'llvm/MC/MCCodeEmitter.h',
	'BitstreamWriter' => 'llvm/Bitcode/BitstreamWriter.h',
	'InsertValueInst' => 'llvm/IR/Instructions.h',
	'ValuesClass' => 'llvm/Support/CommandLine.h',
	'RWMutexImpl' => 'llvm/Support/RWMutex.h',
	'MachOObjectFile' => 'llvm/Object/MachO.h',
	'MachinePassRegistryNode' => 'llvm/CodeGen/MachinePassRegistry.h',
	'StringRef' => 'llvm/ADT/StringRef.h',
	'TargetLowering' => 'llvm/Target/TargetLowering.h',
	'LPPassManager' => 'llvm/Analysis/LoopPass.h',
	'Pass' => 'llvm/Pass.h',
	'ICmpInst' => 'llvm/IR/Instructions.h',
	'Loop' => 'llvm/Analysis/LoopInfo.h',
	'ScopedHashTableVal' => 'llvm/ADT/ScopedHashTable.h',
	'Node' => 'llvm/Support/YAMLParser.h',
	'ImmutableSet' => 'llvm/ADT/ImmutableSet.h',
	'BinOpInit' => 'llvm/TableGen/Record.h',
	'FrameIndexSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'FastFoldingSetNode' => 'llvm/ADT/FoldingSet.h',
	'MachineModuleInfoImpl' => 'llvm/CodeGen/MachineModuleInfo.h',
	'BlackList' => 'llvm/Transforms/Utils/BlackList.h',
	'RecyclingAllocator' => 'llvm/Support/RecyclingAllocator.h',
	'MCDwarfFile' => 'llvm/MC/MCDwarf.h',
	'ScheduleHazardRecognizer' => 'llvm/CodeGen/ScheduleHazardRecognizer.h',
	'RegionPass' => 'llvm/Analysis/RegionPass.h',
	'DILineInfo' => 'llvm/DebugInfo/DIContext.h',
	'SmallVector' => 'llvm/ADT/SmallVector.h',
	'RegPressureTracker' => 'llvm/CodeGen/RegisterPressure.h',
	'MachineRegisterInfo' => 'llvm/CodeGen/MachineRegisterInfo.h',
	'SlabAllocator' => 'llvm/Support/Allocator.h',
	'IntrinsicLowering' => 'llvm/CodeGen/IntrinsicLowering.h',
	'InvokeInst' => 'llvm/IR/Instructions.h',
	'FunctionPassManager' => 'llvm/PassManager.h',
	'CmpInst' => 'llvm/IR/InstrTypes.h',
	'SchedDFSResult' => 'llvm/CodeGen/ScheduleDFS.h',
	'MCDwarfCallFrameFragment' => 'llvm/MC/MCAssembler.h',
	'InstrItineraryData' => 'llvm/MC/MCInstrItineraries.h',
	'GCOVFile' => 'llvm/Support/GCOV.h',
	'LoopBlocksTraversal' => 'llvm/Analysis/LoopIterator.h',
	'TargetRegisterInfo' => 'llvm/Target/TargetRegisterInfo.h',
	'Operator' => 'llvm/IR/Operator.h',
	'constant_iterator' => 'llvm/Analysis/ConstantsScanner.h',
	'file_status' => 'llvm/Support/FileSystem.h',
	'ValueSymbolTable' => 'llvm/IR/ValueSymbolTable.h',
	'IntrinsicInst' => 'llvm/IR/IntrinsicInst.h',
	'ilist_iterator' => 'llvm/ADT/ilist.h',
	'MCOperandInfo' => 'llvm/MC/MCInstrDesc.h',
	'PassManagerType' => 'Pass.h',
	'ConstantDataVector' => 'llvm/IR/Constants.h',
	'MachineConstantPoolValue' => 'llvm/CodeGen/MachineConstantPool.h',
	'GCOVFunction' => 'llvm/Support/GCOV.h',
	'LatencyPriorityQueue' => 'llvm/CodeGen/LatencyPriorityQueue.h',
	'DenseMapIterator' => 'llvm/ADT/DenseMap.h',
	'SourceMgr' => 'llvm/Support/SourceMgr.h',
	'SMRange' => 'llvm/Support/SMLoc.h',
	'MCRegisterInfo' => 'llvm/MC/MCRegisterInfo.h',
	'MCSubtargetInfo' => 'llvm/MC/MCSubtargetInfo.h',
	'FPToUIInst' => 'llvm/IR/Instructions.h',
	'SDValue' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'MCModule' => 'llvm/MC/MCModule.h',
	'AssertingVH' => 'llvm/Support/ValueHandle.h',
	'Regex' => 'llvm/Support/Regex.h',
	'SmallSet' => 'llvm/ADT/SmallSet.h',
	'SetTy' => 'llvm/ADT/DepthFirstIterator.h',
	'StringRecTy' => 'llvm/TableGen/Record.h',
	'DominanceFrontier' => 'llvm/Analysis/DominanceFrontier.h',
	'ZExtInst' => 'llvm/IR/Instructions.h',
	'format_object5' => 'llvm/Support/Format.h',
	'LShrOperator' => 'llvm/IR/Operator.h',
	'Document' => 'llvm/Support/YAMLParser.h',
	'CodeExtractor' => 'llvm/Transforms/Utils/CodeExtractor.h',
	'TargetIntrinsicInfo' => 'llvm/Target/TargetIntrinsicInfo.h',
	'ScopedHashTable' => 'llvm/ADT/ScopedHashTable.h',
	'MCDataFragment' => 'llvm/MC/MCAssembler.h',
	'LibCallSimplifier' => 'llvm/Transforms/Utils/SimplifyLibCalls.h',
	'PassManager' => 'llvm/PassManager.h',
	'ExternalSymbolSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'SCEVExpander' => 'llvm/Analysis/ScalarEvolutionExpander.h',
	'TruncInst' => 'llvm/IR/Instructions.h',
	'DagInit' => 'llvm/TableGen/Record.h',
	'BitInit' => 'llvm/TableGen/Record.h',
	'Instruction' => 'llvm/IR/Instruction.h',
	'JITEventListener' => 'llvm/ExecutionEngine/JITEventListener.h',
	'Recycler' => 'llvm/Support/Recycler.h',
	'PassManagerPrettyStackEntry' => 'llvm/PassManagers.h',
	'SectionKind' => 'llvm/MC/SectionKind.h',
	'HeuristicBase' => 'llvm/CodeGen/PBQP/HeuristicBase.h',
	'UnOpInit' => 'llvm/TableGen/Record.h',
	'TimerGroup' => 'llvm/Support/Timer.h',
	'RegisterScheduler' => 'llvm/CodeGen/SchedulerRegistry.h',
	'APFloat' => 'llvm/ADT/APFloat.h',
	'Constant' => 'llvm/IR/Constant.h',
	'SelectionDAG' => 'llvm/CodeGen/SelectionDAG.h',
	'ScopedHashTableScope' => 'llvm/ADT/ScopedHashTable.h',
	'MemoryBlock' => 'llvm/Support/Memory.h',
	'SExtInst' => 'llvm/IR/Instructions.h',
	'MachineInstrBuilder' => 'llvm/CodeGen/MachineInstrBuilder.h',
	'IVUsers' => 'llvm/Analysis/IVUsers.h',
	'PassInfo' => 'llvm/PassSupport.h',
	'MulOperator' => 'llvm/IR/Operator.h',
	'MachineLoopInfo' => 'llvm/CodeGen/MachineLoopInfo.h',
	'mapped_file_region' => 'llvm/Support/FileSystem.h',
	'const_iterator' => 'llvm/Support/PathV2.h',
	'FoldingSetVector' => 'llvm/ADT/FoldingSet.h',
	'SmallPtrSet' => 'llvm/ADT/SmallPtrSet.h',
	'IO' => 'llvm/Support/YAMLTraits.h',
	'Output' => 'llvm/Support/YAMLTraits.h',
	'DIInliningInfo' => 'llvm/DebugInfo/DIContext.h',
	'SDNodeIterator' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'FoldingSetNodeIDRef' => 'llvm/ADT/FoldingSet.h',
	'VirtRegMap' => 'llvm/CodeGen/VirtRegMap.h',
	'LiveRangeEdit' => 'llvm/CodeGen/LiveRangeEdit.h',
	'ManagedStaticBase' => 'llvm/Support/ManagedStatic.h',
	'RecordVal' => 'llvm/TableGen/Record.h',
	'ScheduleDAGInstrs' => 'llvm/CodeGen/ScheduleDAGInstrs.h',
	'ValueMapTypeRemapper' => 'llvm/Transforms/Utils/ValueMapper.h',
	'MCStreamer' => 'llvm/MC/MCStreamer.h',
	'hash_code' => 'llvm/ADT/Hashing.h',
	'Process' => 'llvm/Support/Process.h',
	'raw_string_ostream' => 'llvm/Support/raw_ostream.h',
	'GlobalValue' => 'llvm/IR/GlobalValue.h',
	'DebugLoc' => 'llvm/Support/DebugLoc.h',
	'MCWinCOFFObjectTargetWriter' => 'llvm/MC/MCWinCOFFObjectWriter.h',
	'BitCodeAbbrev' => 'llvm/Bitcode/BitCodes.h',
	'FenceInst' => 'llvm/IR/Instructions.h',
	'StoreInst' => 'llvm/IR/Instructions.h',
	'format_object2' => 'llvm/Support/Format.h',
	'MachineBasicBlock' => 'llvm/CodeGen/MachineBasicBlock.h',
	'StreamingMemoryObject' => 'llvm/Support/StreamableMemoryObject.h',
	'DFAPacketizer' => 'llvm/CodeGen/DFAPacketizer.h',
	'TinyPtrVector' => 'llvm/ADT/TinyPtrVector.h',
	'ImmutableSetRef' => 'llvm/ADT/ImmutableSet.h',
	'ListInit' => 'llvm/TableGen/Record.h',
	'ConstantArray' => 'llvm/IR/Constants.h',
	'ImutAVLTree' => 'llvm/ADT/ImmutableSet.h',
	'ImutAVLTreeGenericIterator' => 'llvm/ADT/ImmutableSet.h',
	'LoopPass' => 'llvm/Analysis/LoopPass.h',
	'SMFixIt' => 'llvm/Support/SourceMgr.h',
	'LexicalScopes' => 'llvm/CodeGen/LexicalScopes.h',
	'IntervalMap' => 'llvm/ADT/IntervalMap.h',
	'PrintRegUnit' => 'llvm/Target/TargetRegisterInfo.h',
	'TargetLibraryInfo' => 'llvm/Target/TargetLibraryInfo.h',
	'IRBuilder' => 'llvm/IR/IRBuilder.h',
	'LoopBlocksDFS' => 'llvm/Analysis/LoopIterator.h',
	'IVStrideUse' => 'llvm/Analysis/IVUsers.h',
	'CrashRecoveryContextDestructorCleanup' => 'llvm/Support/CrashRecoveryContext.h',
	'Use' => 'llvm/IR/Use.h',
	'MachineOperandIteratorBase' => 'llvm/CodeGen/MachineInstrBundle.h',
	'ImmutableMap' => 'llvm/ADT/ImmutableMap.h',
	'MachineCodeInfo' => 'llvm/CodeGen/MachineCodeInfo.h',
	'MCAsmInfoCOFF' => 'llvm/MC/MCAsmInfoCOFF.h',
	'ScalarNode' => 'llvm/Support/YAMLParser.h',
	'GraphWriter' => 'llvm/Support/GraphWriter.h',
	'MIBundleBuilder' => 'llvm/CodeGen/MachineInstrBuilder.h',
	'Watchdog' => 'llvm/Support/Watchdog.h',
	'FoldingSetBucketIteratorImpl' => 'llvm/ADT/FoldingSet.h',
	'MCParsedAsmOperand' => 'llvm/MC/MCParser/MCParsedAsmOperand.h',
	'BitstreamReader' => 'llvm/Bitcode/BitstreamReader.h',
	'SmallVectorTemplateCommon' => 'llvm/ADT/SmallVector.h',
	'CrashRecoveryContextCleanup' => 'llvm/Support/CrashRecoveryContext.h',
	'MCObjectFileInfo' => 'llvm/MC/MCObjectFileInfo.h',
	'CrashRecoveryContextReleaseRefCleanup' => 'llvm/Support/CrashRecoveryContext.h',
	'MCSymbolRefExpr' => 'llvm/MC/MCExpr.h',
	'BasicBlockEdge' => 'llvm/Analysis/Dominators.h',
	'TargetSelectionDAGInfo' => 'llvm/Target/TargetSelectionDAGInfo.h',
	'PredIterator' => 'llvm/Support/CFG.h',
	'list_storage' => 'llvm/Support/CommandLine.h',
	'VAArgInst' => 'llvm/IR/Instructions.h',
	'CallInst' => 'llvm/IR/Instructions.h',
	'PassArgFilter' => 'llvm/Support/PassNameParser.h',
	'LiveIntervalUnion' => 'llvm/CodeGen/LiveIntervalUnion.h',
	'AttributeSet' => 'llvm/IR/Attributes.h',
	'MVT' => 'llvm/CodeGen/ValueTypes.h',
	'ilist_node' => 'llvm/ADT/ilist_node.h',
	'ProfilePath' => 'llvm/Analysis/PathProfileInfo.h',
	'VTSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'IntervalMapOverlaps' => 'llvm/ADT/IntervalMap.h',
	'MCRegAliasIterator' => 'llvm/MC/MCRegisterInfo.h',
	'EdgeBundles' => 'llvm/CodeGen/EdgeBundles.h',
	'OverflowingBinaryOperator' => 'llvm/IR/Operator.h',
	'DIBuilder' => 'llvm/DIBuilder.h',
	'MDString' => 'llvm/IR/Metadata.h',
	'MCCodeGenInfo' => 'llvm/MC/MCCodeGenInfo.h',
	'CrashRecoveryContextDeleteCleanup' => 'llvm/Support/CrashRecoveryContext.h',
	'GlobalAddressSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'GetElementPtrInst' => 'llvm/IR/Instructions.h',
	'PMDataManager' => 'llvm/PassManagers.h',
	'OpInit' => 'llvm/TableGen/Record.h',
	'ConstantRange' => 'llvm/Support/ConstantRange.h',
	'SDep' => 'llvm/CodeGen/ScheduleDAG.h',
	'SparseMultiSet' => 'llvm/ADT/SparseMultiSet.h',
	'JITCodeEmitter' => 'llvm/CodeGen/JITCodeEmitter.h',
	'VarInit' => 'llvm/TableGen/Record.h',
	'MachineDominatorTree' => 'llvm/CodeGen/MachineDominators.h',
	'MachineRelocation' => 'llvm/CodeGen/MachineRelocation.h',
	'KeyValueNode' => 'llvm/Support/YAMLParser.h',
	'MCRelaxableFragment' => 'llvm/MC/MCAssembler.h',
	'MachineModuleInfoMachO' => 'llvm/CodeGen/MachineModuleInfoImpls.h',
	'PassDebuggingString' => 'PassManagers.h',
	'PossiblyExactOperator' => 'llvm/IR/Operator.h',
	'Sequence' => 'llvm/ADT/PriorityQueue.h',
	'TypeFinder' => 'llvm/IR/TypeFinder.h',
	'SMLoc' => 'llvm/Support/SMLoc.h',
	'StringSet' => 'llvm/ADT/StringSet.h',
	'TargetLoweringBase' => 'llvm/Target/TargetLowering.h',
	'iplist' => 'llvm/ADT/ilist.h',
	'GlobalAlias' => 'llvm/IR/GlobalAlias.h',
	'EngineBuilder' => 'llvm/ExecutionEngine/ExecutionEngine.h',
	'BuildVectorSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'ConstantStruct' => 'llvm/IR/Constants.h',
	'MCELFStreamer' => 'llvm/MC/MCELFStreamer.h',
	'CondCodeSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'NoFolder' => 'llvm/Support/NoFolder.h',
	'RelocVisitor' => 'llvm/Object/RelocVisitor.h',
	'FoldingSetVectorIterator' => 'llvm/ADT/FoldingSet.h',
	'DOTGraphTraitsModuleViewer' => 'llvm/Analysis/DOTGraphTraitsPass.h',
	'TargetInstrInfo' => 'llvm/Target/TargetInstrInfo.h',
	'Stream' => 'llvm/Support/YAMLParser.h',
	'MachineSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'FastISel' => 'llvm/CodeGen/FastISel.h',
	'Twine' => 'llvm/ADT/Twine.h',
	'LLVMContext' => 'llvm/IR/LLVMContext.h',
	'RegisterRegAlloc' => 'llvm/CodeGen/RegAllocRegistry.h',
	'DenseMap' => 'llvm/ADT/DenseMap.h',
	'ObjectFile' => 'llvm/Object/ObjectFile.h',
	'ProfilePathEdge' => 'llvm/Analysis/PathProfileInfo.h',
	'MCAsmParserSemaCallback' => 'llvm/MC/MCParser/MCAsmParser.h',
	'MCOperand' => 'llvm/MC/MCInst.h',
	'MDNodeSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'ScopedHashTableIterator' => 'llvm/ADT/ScopedHashTable.h',
	'MCInstBuilder' => 'llvm/MC/MCInstBuilder.h',
	'ReturnInst' => 'llvm/IR/Instructions.h',
	'ArchiveMember' => 'llvm/Bitcode/Archive.h',
	'MDBuilder' => 'llvm/IR/MDBuilder.h',
	'MCSection' => 'llvm/MC/MCSection.h',
	'IndexListEntry' => 'llvm/CodeGen/SlotIndexes.h',
	'MemIntrinsicSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'APSInt' => 'llvm/ADT/APSInt.h',
	'ProfileDataLoader' => 'llvm/Analysis/ProfileDataLoader.h',
	'Intrinsic' => 'llvm/IR/Intrinsics.h',
	'IdentifyingPassPtr' => 'llvm/CodeGen/Passes.h',
	'BranchProbabilityInfo' => 'llvm/Analysis/BranchProbabilityInfo.h',
	'MachineCodeEmitter' => 'llvm/CodeGen/MachineCodeEmitter.h',
	'MachineConstantPool' => 'llvm/CodeGen/MachineConstantPool.h',
	'MCObjectWriter' => 'llvm/MC/MCObjectWriter.h',
	'CallGraphSCC' => 'llvm/Analysis/CallGraphSCCPass.h',
	'IntegersSubset' => 'llvm/Support/IntegersSubset.h',
	'MCAssembler' => 'llvm/MC/MCAssembler.h',
	'AnalysisID' => 'Pass.h',
	'BlockFrequencyInfo' => 'llvm/Analysis/BlockFrequencyInfo.h',
	'MCInstPrinter' => 'llvm/MC/MCInstPrinter.h',
	'FieldInit' => 'llvm/TableGen/Record.h',
	'ExecutionEngine' => 'llvm/ExecutionEngine/ExecutionEngine.h',
	'MapVector' => 'llvm/ADT/MapVector.h',
	'RegisterPassParser' => 'llvm/CodeGen/MachinePassRegistry.h',
	'ImmutableList' => 'llvm/ADT/ImmutableList.h',
	'SetType' => 'llvm/ADT/PostOrderIterator.h',
	'formatted_raw_ostream' => 'llvm/Support/FormattedStream.h',
	'Init' => 'llvm/TableGen/Record.h',
	'MachineInstr' => 'llvm/CodeGen/MachineInstr.h',
	'FunctionType' => 'llvm/IR/DerivedTypes.h',
	'Region' => 'llvm/Analysis/RegionInfo.h',
	'MCOrgFragment' => 'llvm/MC/MCAssembler.h',
	'CastInst' => 'llvm/IR/InstrTypes.h',
	'ReadyQueue' => 'llvm/CodeGen/MachineScheduler.h',
	'Timer' => 'llvm/Support/Timer.h',
	'IntItem' => 'llvm/Support/IntegersSubset.h',
	'ProfileInfoLoader' => 'llvm/Analysis/ProfileInfoLoader.h',
	'SequentialType' => 'llvm/IR/DerivedTypes.h',
	'GCStrategy' => 'llvm/CodeGen/GCStrategy.h',
	'BitVector' => 'llvm/ADT/BitVector.h',
	'PredIteratorCache' => 'llvm/Support/PredIteratorCache.h',
	'ConstantSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'MachinePassRegistry' => 'llvm/CodeGen/MachinePassRegistry.h',
	'SmallVectorBase' => 'llvm/ADT/SmallVector.h',
	'FileRemover' => 'llvm/Support/FileUtilities.h',
	'ResumeInst' => 'llvm/IR/Instructions.h',
	'BallLarusEdge' => 'llvm/Analysis/PathNumbering.h',
	'MCRegUnitIterator' => 'llvm/MC/MCRegisterInfo.h',
	'MCUnaryExpr' => 'llvm/MC/MCExpr.h',
	'MachineSSAUpdater' => 'llvm/CodeGen/MachineSSAUpdater.h',
	'LoadAndStorePromoter' => 'llvm/Transforms/Utils/SSAUpdater.h',
	'TrackingVH' => 'llvm/Support/ValueHandle.h',
	'StringSwitch' => 'llvm/ADT/StringSwitch.h',
	'RegisterAGBase' => 'llvm/PassSupport.h',
	'ArrayRef' => 'llvm/ADT/ArrayRef.h',
	'basic_parser' => 'llvm/Support/CommandLine.h',
	'TargetJITInfo' => 'llvm/Target/TargetJITInfo.h',
	'SmallPtrSetIteratorImpl' => 'llvm/ADT/SmallPtrSet.h',
	'MCExpr' => 'llvm/MC/MCExpr.h',
	'format_object3' => 'llvm/Support/Format.h',
	'Argument' => 'llvm/IR/Argument.h',
	'MachineJumpTableInfo' => 'llvm/CodeGen/MachineJumpTableInfo.h',
	'Mangler' => 'llvm/Target/Mangler.h',
	'StoreSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'MachineOperand' => 'llvm/CodeGen/MachineOperand.h',
	'MCBinaryExpr' => 'llvm/MC/MCExpr.h',
	'TargetLoweringObjectFileELF' => 'llvm/CodeGen/TargetLoweringObjectFileImpl.h',
	'SmallBitVector' => 'llvm/ADT/SmallBitVector.h',
	'MCLEBFragment' => 'llvm/MC/MCAssembler.h',
	'ImutAVLFactory' => 'llvm/ADT/ImmutableSet.h',
	'TargetFolder' => 'llvm/Support/TargetFolder.h',
	'ConcreteOperator' => 'llvm/IR/Operator.h',
	'BitCodeAbbrevOp' => 'llvm/Bitcode/BitCodes.h',
	'RecTy' => 'llvm/TableGen/Record.h',
	'IRBuilderBase' => 'llvm/IR/IRBuilder.h',
	'TerminatorInst' => 'llvm/IR/InstrTypes.h',
	'FunctionPass' => 'llvm/Pass.h',
	'CrashRecoveryContextCleanupRegistrar' => 'llvm/Support/CrashRecoveryContext.h',
	'Type' => 'llvm/IR/Type.h',
	'ArgList' => 'llvm/Option/ArgList.h',
	'PtrUseVisitor' => 'llvm/Analysis/PtrUseVisitor.h',
	'TargetPassConfig' => 'llvm/CodeGen/Passes.h',
	'SelectInst' => 'llvm/IR/Instructions.h',
	'AliasSet' => 'llvm/Analysis/AliasSetTracker.h',
	'AttrBuilder' => 'llvm/IR/Attributes.h',
	'ConstantPointerNull' => 'llvm/IR/Constants.h',
	'SubtargetFeatures' => 'llvm/MC/SubtargetFeature.h',
	'MCEncodedFragmentWithFixups' => 'llvm/MC/MCAssembler.h',
	'AtomicCmpXchgInst' => 'llvm/IR/Instructions.h',
	'process' => 'llvm/Support/Process.h',
	'SCEVConstant' => 'llvm/Analysis/ScalarEvolutionExpressions.h',
	'SmallString' => 'llvm/ADT/SmallString.h',
	'RecordKeeper' => 'llvm/TableGen/Record.h',
	'Path' => 'llvm/ADT/IntervalMap.h',
	'PtrUseVisitorBase' => 'llvm/Analysis/PtrUseVisitor.h',
	'StringMapEntryInitializer' => 'llvm/ADT/StringMap.h',
	'ProfileInfoT' => 'llvm/Analysis/ProfileInfo.h',
	'MCAtom' => 'llvm/MC/MCAtom.h',
	'MallocAllocator' => 'llvm/Support/Allocator.h',
	'DataStreamer' => 'llvm/Support/DataStream.h',
	'InputArgList' => 'llvm/Option/ArgList.h',
	'GEPOperator' => 'llvm/IR/Operator.h',
	'SetVector' => 'llvm/ADT/SetVector.h',
	'RegistryParser' => 'llvm/Support/RegistryParser.h',
	'IGT' => 'llvm/Analysis/IntervalIterator.h',
	'MallocSlabAllocator' => 'llvm/Support/Allocator.h',
	'LoadInst' => 'llvm/IR/Instructions.h',
	'DILineInfoSpecifier' => 'llvm/DebugInfo/DIContext.h',
	'Solution' => 'llvm/CodeGen/PBQP/Solution.h',
	'MCAsmInfo' => 'llvm/MC/MCAsmInfo.h',
	'_do_message' => 'llvm/Support/system_error.h',
	'JITMemoryManager' => 'llvm/ExecutionEngine/JITMemoryManager.h',
	'ManagedStatic' => 'llvm/Support/ManagedStatic.h',
	'ConstantDataSequential' => 'llvm/IR/Constants.h',
	'DomTreeNodeBase' => 'llvm/Analysis/Dominators.h',
	'ConstMIBundleOperands' => 'llvm/CodeGen/MachineInstrBundle.h',
	'PackedVectorBase' => 'llvm/ADT/PackedVector.h',
	'LLVMTargetMachine' => 'llvm/Target/TargetMachine.h',
	'DIContext' => 'llvm/DebugInfo/DIContext.h',
	'self_process' => 'llvm/Support/Process.h',
	'OutputBuffer' => 'llvm/Support/OutputBuffer.h',
	'DAGDeltaAlgorithm' => 'llvm/ADT/DAGDeltaAlgorithm.h',
	'NullablePtr' => 'llvm/ADT/NullablePtr.h',
	'df_iterator_storage' => 'llvm/ADT/DepthFirstIterator.h',
	'SpecificBumpPtrAllocator' => 'llvm/Support/Allocator.h',
	'ConstantInt' => 'llvm/IR/Constants.h',
	'error_code' => 'llvm/Support/system_error.h',
	'OwningPtr' => 'llvm/ADT/OwningPtr.h',
	'CallSiteBase' => 'llvm/Support/CallSite.h',
	'ImmutableIntervalMap' => 'llvm/ADT/ImmutableIntervalMap.h',
	'MutexGuard' => 'llvm/Support/MutexGuard.h',
	'FPTruncInst' => 'llvm/IR/Instructions.h',
	'VarBitInit' => 'llvm/TableGen/Record.h',
	'FPExtInst' => 'llvm/IR/Instructions.h',
	'BallLarusNode' => 'llvm/Analysis/PathNumbering.h',
	'CrashRecoveryContext' => 'llvm/Support/CrashRecoveryContext.h',
	'BranchNode' => 'llvm/ADT/IntervalMap.h',
	'SmallPtrSetIterator' => 'llvm/ADT/SmallPtrSet.h',
	'Graph' => 'llvm/CodeGen/PBQP/Graph.h',
	'User' => 'llvm/IR/User.h',
	'LockFileManager' => 'llvm/Support/LockFileManager.h',
	'FPPassManager' => 'llvm/PassManagers.h',
	'RecordRecTy' => 'llvm/TableGen/Record.h',
	'SmallVectorImpl' => 'llvm/ADT/SmallVector.h',
	'ObjectBufferStream' => 'llvm/ExecutionEngine/ObjectBuffer.h',
	'CCState' => 'llvm/CodeGen/CallingConvLower.h',
	'ContextualFoldingSet' => 'llvm/ADT/FoldingSet.h',
	'MCFillFragment' => 'llvm/MC/MCAssembler.h',
	'MCAsmInfoDarwin' => 'llvm/MC/MCAsmInfoDarwin.h',
	'StringMap' => 'llvm/ADT/StringMap.h',
	'Interval' => 'llvm/Analysis/Interval.h',
	'SSAUpdaterImpl' => 'llvm/Transforms/Utils/SSAUpdaterImpl.h',
	'BitRecTy' => 'llvm/TableGen/Record.h',
	'format_object_base' => 'llvm/Support/Format.h',
	'raw_fd_ostream' => 'llvm/Support/raw_ostream.h',
	'COFFObjectFile' => 'llvm/Object/COFF.h',
	'AliasSetTracker' => 'llvm/Analysis/AliasSetTracker.h',
	'VNInfo' => 'llvm/CodeGen/LiveInterval.h',
	'LoopBase' => 'llvm/Analysis/LoopInfo.h',
	'LibraryRef' => 'llvm/Object/ObjectFile.h',
	'FileInfo' => 'llvm/Support/GCOV.h',
	'AsmToken' => 'llvm/MC/MCParser/MCAsmLexer.h',
	'VectorType' => 'llvm/IR/DerivedTypes.h',
	'PtrToIntInst' => 'llvm/IR/Instructions.h',
	'MemSlab' => 'llvm/Support/Allocator.h',
	'ConstantDataArray' => 'llvm/IR/Constants.h',
	'MCMachObjectTargetWriter' => 'llvm/MC/MCMachObjectWriter.h',
	'DefInit' => 'llvm/TableGen/Record.h',
	'MachineModuleInfo' => 'llvm/CodeGen/MachineModuleInfo.h',
	'PointerUnionUIntTraits' => 'llvm/ADT/PointerUnion.h',
	'InsertElementInst' => 'llvm/IR/Instructions.h',
	'DominatorTree' => 'llvm/Analysis/Dominators.h',
	'AliasAnalysis' => 'llvm/Analysis/AliasAnalysis.h',
	'MachineConstantPoolEntry' => 'llvm/CodeGen/MachineConstantPool.h',
	'BlockAddress' => 'llvm/IR/Constants.h',
	'OptionCategory' => 'llvm/Support/CommandLine.h',
	'TargetSubtargetInfo' => 'llvm/Target/TargetSubtargetInfo.h',
	'MCSymbol' => 'llvm/MC/MCSymbol.h',
	'MachineBlockFrequencyInfo' => 'llvm/CodeGen/MachineBlockFrequencyInfo.h',
	'GCFunctionInfo' => 'llvm/CodeGen/GCMetadata.h',
	'TernarySDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'DataExtractor' => 'llvm/Support/DataExtractor.h',
	'MachineMemOperand' => 'llvm/CodeGen/MachineMemOperand.h',
	'RegisterSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'MCAsmLayout' => 'llvm/MC/MCAsmLayout.h',
	'ConstantFPSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'AddOperator' => 'llvm/IR/Operator.h',
	'PMTopLevelManager' => 'llvm/PassManagers.h',
	'circular_raw_ostream' => 'llvm/Support/circular_raw_ostream.h',
	'ThreadLocalImpl' => 'llvm/Support/ThreadLocal.h',
	'LoopInfo' => 'llvm/Analysis/LoopInfo.h',
	'ExtractElementInst' => 'llvm/IR/Instructions.h',
	'GCOVBuffer' => 'llvm/Support/GCOV.h',
	'InlineCost' => 'llvm/Analysis/InlineCost.h',
	'BinarySDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'directory_entry' => 'llvm/Support/FileSystem.h',
	'Trace' => 'llvm/Analysis/Trace.h',
	'LibCallInfo' => 'llvm/Analysis/LibCallSemantics.h',
	'ilist_half_node' => 'llvm/ADT/ilist_node.h',
	'StringMapIterator' => 'llvm/ADT/StringMap.h',
	'CrashRecoveryContextCleanupBase' => 'llvm/Support/CrashRecoveryContext.h',
	'UnaryInstruction' => 'llvm/IR/InstrTypes.h',
	'ImmutableListImpl' => 'llvm/ADT/ImmutableList.h',
	'VarListElementInit' => 'llvm/TableGen/Record.h',
	'StringMapEntryBase' => 'llvm/ADT/StringMap.h',
	'BitsInit' => 'llvm/TableGen/Record.h',
	'ImmutableListFactory' => 'llvm/ADT/ImmutableList.h',
	'PassManagerBuilder' => 'llvm/Transforms/IPO/PassManagerBuilder.h',
	'BlockAddressSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'TargetLoweringObjectFileMachO' => 'llvm/CodeGen/TargetLoweringObjectFileImpl.h',
	'ObjectImage' => 'llvm/ExecutionEngine/ObjectImage.h',
	'FPMathOperator' => 'llvm/IR/Operator.h',
	'SimplifyFortifiedLibCalls' => 'llvm/Transforms/Utils/BuildLibCalls.h',
	'SSAUpdater' => 'llvm/Transforms/Utils/SSAUpdater.h',
	'SimpleRegistryEntry' => 'llvm/Support/Registry.h',
	'ValueMap' => 'llvm/ADT/ValueMap.h',
	'DominatorBase' => 'llvm/Analysis/Dominators.h',
	'HeuristicSolverImpl' => 'llvm/CodeGen/PBQP/HeuristicSolver.h',
	'InlineCostAnalysis' => 'llvm/Analysis/InlineCost.h',
	'content_iterator' => 'llvm/Object/ObjectFile.h',
	'ImutAVLTreeInOrderIterator' => 'llvm/ADT/ImmutableSet.h',
	'LSBaseSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'RGPassManager' => 'llvm/Analysis/RegionPass.h',
	'VirtRegAuxInfo' => 'llvm/CodeGen/CalcSpillWeights.h',
	'LiveRegMatrix' => 'llvm/CodeGen/LiveRegMatrix.h',
	'opt_storage' => 'llvm/Support/CommandLine.h',
	'recursive_directory_iterator' => 'llvm/Support/FileSystem.h',
	'TargetOptions' => 'llvm/Target/TargetOptions.h',
	'TargetLoweringObjectFile' => 'llvm/Target/TargetLoweringObjectFile.h',
	'FileOutputBuffer' => 'llvm/Support/FileOutputBuffer.h',
	'SuccIterator' => 'llvm/Support/CFG.h',
	'HandleSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'AsmCond' => 'llvm/MC/MCParser/AsmCond.h',
	'GCMetadataPrinter' => 'llvm/CodeGen/GCMetadataPrinter.h',
	'EHLabelSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'ReferenceStorage' => 'llvm/Support/ErrorOr.h',
	'BasicBlockPass' => 'llvm/Pass.h',
	'IntegerType' => 'llvm/IR/DerivedTypes.h',
	'AnalysisUsage' => 'llvm/PassAnalysisSupport.h',
	'BitstreamCursor' => 'llvm/Bitcode/BitstreamReader.h',
	'ShuffleVectorSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'ExtractValueInst' => 'llvm/IR/Instructions.h',
	'MCInstrInfo' => 'llvm/MC/MCInstrInfo.h',
	'TimeValue' => 'llvm/Support/TimeValue.h',
	'MDNode' => 'llvm/IR/Metadata.h',
	'scc_iterator' => 'llvm/ADT/SCCIterator.h',
	'SelectionDAGISel' => 'llvm/CodeGen/SelectionDAGISel.h',
	'GVMaterializer' => 'llvm/GVMaterializer.h',
	'MCCompactEncodedInstFragment' => 'llvm/MC/MCAssembler.h',
	'DynamicLibrary' => 'llvm/Support/DynamicLibrary.h',
	'Program' => 'llvm/Support/Program.h',
	'MemoryObject' => 'llvm/Support/MemoryObject.h',
	'MachineSchedRegistry' => 'llvm/CodeGen/MachineScheduler.h',
	'PassManagerBase' => 'llvm/PassManager.h',
	'raw_null_ostream' => 'llvm/Support/raw_ostream.h',
	'ScoreboardHazardRecognizer' => 'llvm/CodeGen/ScoreboardHazardRecognizer.h',
	'LandingPadInst' => 'llvm/IR/Instructions.h',
	'MachORelocation' => 'llvm/CodeGen/MachORelocation.h',
	'IVVisitor' => 'llvm/Transforms/Utils/SimplifyIndVar.h',
	'SrcValueSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'PassNameParser' => 'llvm/Support/PassNameParser.h',
	'ValueMapIterator' => 'llvm/ADT/ValueMap.h',
	'format_object1' => 'llvm/Support/Format.h',
	'FoldingSetIterator' => 'llvm/ADT/FoldingSet.h',
	'AssemblyAnnotationWriter' => 'llvm/Assembly/AssemblyAnnotationWriter.h',
	'MachineFunction' => 'llvm/CodeGen/MachineFunction.h',
	'SDDbgInfo' => 'llvm/CodeGen/SelectionDAG.h',
	'raw_ostream' => 'llvm/Support/raw_ostream.h',
	'SCEV' => 'llvm/Analysis/ScalarEvolution.h',
	'UnreachableInst' => 'llvm/IR/Instructions.h',
	'IndexedMap' => 'llvm/ADT/IndexedMap.h',
	'MachineTraceMetrics' => 'llvm/CodeGen/MachineTraceMetrics.h',
	'generic_parser_base' => 'llvm/Support/CommandLine.h',
	'error_condition' => 'llvm/Support/system_error.h',
	'ParserClass' => 'llvm/Support/CommandLine.h',
	'BallLarusDag' => 'llvm/Analysis/PathNumbering.h',
	'Attribute' => 'llvm/IR/Attributes.h',
	'IntEqClasses' => 'llvm/ADT/IntEqClasses.h',
	'BumpPtrAllocator' => 'llvm/Support/Allocator.h',
	'AnalysisResolver' => 'llvm/PassAnalysisSupport.h',
	'FilteredPassNameParser' => 'llvm/Support/PassNameParser.h',
	'CallGraphSCCPass' => 'llvm/Analysis/CallGraphSCCPass.h',
	'MCSectionData' => 'llvm/MC/MCAssembler.h',
	'arg_iterator' => 'llvm/Option/ArgList.h',
	'LexicalScope' => 'llvm/CodeGen/LexicalScopes.h',
	'StructLayout' => 'llvm/IR/DataLayout.h',
	'MCLabel' => 'llvm/MC/MCLabel.h',
	'MachineLocation' => 'llvm/MC/MachineLocation.h',
	'SparseSolver' => 'llvm/Analysis/SparsePropagation.h',
	'Archive' => 'llvm/Object/Archive.h',
	'StreamableMemoryObject' => 'llvm/Support/StreamableMemoryObject.h',
	'DagRecTy' => 'llvm/TableGen/Record.h',
	'TernOpInit' => 'llvm/TableGen/Record.h',
	'GCOVBlock' => 'llvm/Support/GCOV.h',
	'AsmPrinter' => 'llvm/CodeGen/AsmPrinter.h',
	'ConstMIOperands' => 'llvm/CodeGen/MachineInstrBundle.h',
	'PMStack' => 'llvm/PassManagers.h',
	'IntervalPartition' => 'llvm/Analysis/IntervalPartition.h',
	'MCWin64EHInstruction' => 'llvm/MC/MCWin64EH.h',
	'PrintReg' => 'llvm/Target/TargetRegisterInfo.h',
	'FoldingSetBucketIterator' => 'llvm/ADT/FoldingSet.h',
	'TargetLoweringObjectFileCOFF' => 'llvm/CodeGen/TargetLoweringObjectFileImpl.h',
	'StructType' => 'llvm/IR/DerivedTypes.h',
	'VLIWPacketizerList' => 'llvm/CodeGen/DFAPacketizer.h',
	'SequenceNode' => 'llvm/Support/YAMLParser.h',
	'MachinePassRegistryListener' => 'llvm/CodeGen/MachinePassRegistry.h',
	'ProfileDataT' => 'llvm/Analysis/ProfileDataLoader.h',
	'NullNode' => 'llvm/Support/YAMLParser.h',
	'InlineFunctionInfo' => 'llvm/Transforms/Utils/Cloning.h',
	'Arg' => 'llvm/Option/Arg.h',
	'RTDyldMemoryManager' => 'llvm/ExecutionEngine/RuntimeDyld.h',
	'ShlOperator' => 'llvm/IR/Operator.h',
	'MCAlignFragment' => 'llvm/MC/MCAssembler.h',
	'MCInst' => 'llvm/MC/MCInst.h',
	'BlockFrequencyImpl' => 'llvm/Analysis/BlockFrequencyImpl.h',
	'MemoryBuffer' => 'llvm/Support/MemoryBuffer.h',
	'MappingNode' => 'llvm/Support/YAMLParser.h',
	'SparseSet' => 'llvm/ADT/SparseSet.h',
	'NodeRef' => 'llvm/ADT/IntervalMap.h',
	'ObjectSizeOffsetEvaluator' => 'llvm/Analysis/MemoryBuiltins.h',
	'PseudoSourceValue' => 'llvm/CodeGen/PseudoSourceValue.h',
	'BitCastInst' => 'llvm/IR/Instructions.h',
	'LoopInfoBase' => 'llvm/Analysis/LoopInfo.h',
	'AllocaInst' => 'llvm/IR/Instructions.h',
	'PBQPRAProblem' => 'llvm/CodeGen/RegAllocPBQP.h',
	'document_iterator' => 'llvm/Support/YAMLParser.h',
	'LoadSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'EquivalenceClasses' => 'llvm/ADT/EquivalenceClasses.h',
	'MCSectionMachO' => 'llvm/MC/MCSectionMachO.h',
	'TargetIndexSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'SymbolTableListTraits' => 'llvm/IR/SymbolTableListTraits.h',
	'Vector' => 'llvm/CodeGen/PBQP/Math.h',
	'AsmLexer' => 'llvm/MC/MCParser/AsmLexer.h',
	'PopulateLoopsDFS' => 'llvm/Analysis/LoopInfoImpl.h',
	'CompositeType' => 'llvm/IR/DerivedTypes.h',
	'Target' => 'llvm/Support/TargetRegistry.h',
	'bits_storage' => 'llvm/Support/CommandLine.h',
	'MCDwarfLineAddrFragment' => 'llvm/MC/MCAssembler.h',
	'RegScavenger' => 'llvm/CodeGen/RegisterScavenging.h',
	'format_object4' => 'llvm/Support/Format.h',
	'FoldingSetNodeID' => 'llvm/ADT/FoldingSet.h',
	'UnarySDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'ConstantFP' => 'llvm/IR/Constants.h',
	'ErrorOr' => 'llvm/Support/ErrorOr.h',
	'AlignerImpl' => 'llvm/Support/AlignOf.h',
	'MCSuperRegIterator' => 'llvm/MC/MCRegisterInfo.h',
	'InstVisitor' => 'llvm/InstVisitor.h',
	'SectionMemoryManager' => 'llvm/ExecutionEngine/SectionMemoryManager.h',
	'system_error' => 'llvm/Support/system_error.h',
	'PathProfileInfo' => 'llvm/Analysis/PathProfileInfo.h',
	'PackedVector' => 'llvm/ADT/PackedVector.h',
	'FoldingSetIteratorImpl' => 'llvm/ADT/FoldingSet.h',
	'BitsRecTy' => 'llvm/TableGen/Record.h',
	'DominanceFrontierBase' => 'llvm/Analysis/DominanceFrontier.h',
	'RefCountedBase' => 'llvm/ADT/IntrusiveRefCntPtr.h',
	'MCSubRegIterator' => 'llvm/MC/MCRegisterInfo.h',
	'MCTargetExpr' => 'llvm/MC/MCExpr.h',
	'FoldingSetNodeWrapper' => 'llvm/ADT/FoldingSet.h',
	'MCRegUnitRootIterator' => 'llvm/MC/MCRegisterInfo.h',
	'GCOVLines' => 'llvm/Support/GCOV.h',
	'SmallPtrSetImpl' => 'llvm/ADT/SmallPtrSet.h',
	'MCAsmParserExtension' => 'llvm/MC/MCParser/MCAsmParserExtension.h',
	'ShuffleVectorInst' => 'llvm/IR/Instructions.h',
	'MIOperands' => 'llvm/CodeGen/MachineInstrBundle.h',
	'PointerType' => 'llvm/IR/DerivedTypes.h',
	'IntToPtrInst' => 'llvm/IR/Instructions.h',
	'RNSuccIterator' => 'llvm/Analysis/RegionIterator.h',
	'OwningArrayPtr' => 'llvm/ADT/OwningPtr.h',
	'SwitchInst' => 'llvm/IR/Instructions.h',
	'AliasNode' => 'llvm/Support/YAMLParser.h',
	'PrettyStackTraceEntry' => 'llvm/Support/PrettyStackTrace.h',
	'TypeBuilder' => 'llvm/IR/TypeBuilder.h',
	'MCSchedModel' => 'llvm/MC/MCSchedule.h',
	'UnsetInit' => 'llvm/TableGen/Record.h',
	'GlobalVariable' => 'llvm/IR/GlobalVariable.h',
	'DOTGraphTraitsPrinter' => 'llvm/Analysis/DOTGraphTraitsPass.h',
	'IntInit' => 'llvm/TableGen/Record.h',
	'ListRecTy' => 'llvm/TableGen/Record.h',
	'MCFragment' => 'llvm/MC/MCAssembler.h',
	'LiveIntervals' => 'llvm/CodeGen/LiveIntervalAnalysis.h',
	'ImmutableMapRef' => 'llvm/ADT/ImmutableMap.h',
	'PHINode' => 'llvm/IR/Instructions.h',
	'FCmpInst' => 'llvm/IR/Instructions.h',
	'basic_collection_iterator' => 'llvm/Support/YAMLParser.h',
	'MutexImpl' => 'llvm/Support/Mutex.h',
	'ValueMapConstIterator' => 'llvm/ADT/ValueMap.h',
	'PassKind' => 'Pass.h',
	'TimeRecord' => 'llvm/Support/Timer.h',
	'DominatorTreeBase' => 'llvm/Analysis/Dominators.h',
	'MachineSchedStrategy' => 'llvm/CodeGen/MachineScheduler.h',
	'TargetSchedModel' => 'llvm/CodeGen/TargetSchedule.h',
	'PointerLikeTypeTraits' => 'llvm/Support/ValueHandle.h',
	'ValueMapCallbackVH' => 'llvm/ADT/ValueMap.h',
	'MemSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'DIDescriptor' => 'llvm/DebugInfo.h',
	'ScheduleDAGMI' => 'llvm/CodeGen/MachineScheduler.h',
	'MCInstrDesc' => 'llvm/MC/MCInstrDesc.h',
	'MachObjectWriter' => 'llvm/MC/MCMachObjectWriter.h',
	'MCDisassembler' => 'llvm/MC/MCDisassembler.h',
	'MCSectionELF' => 'llvm/MC/MCSectionELF.h',
	'StringMapEntry' => 'llvm/ADT/StringMap.h',
	'MCEncodedFragment' => 'llvm/MC/MCAssembler.h',
	'FoldingSetImpl' => 'llvm/ADT/FoldingSet.h',
	'FastMathFlags' => 'llvm/IR/Operator.h',
	'CallbackVH' => 'llvm/Support/ValueHandle.h',
	'NodeBase' => 'llvm/ADT/IntervalMap.h',
	'IntRecTy' => 'llvm/TableGen/Record.h',
	'AtomicRMWInst' => 'llvm/IR/Instructions.h',
	'MachineMove' => 'llvm/MC/MachineLocation.h',
	'CalleeSavedInfo' => 'llvm/CodeGen/MachineFrameInfo.h',
	'InlineAsm' => 'llvm/IR/InlineAsm.h',
	'raw_svector_ostream' => 'llvm/Support/raw_ostream.h',
	'MachineFunctionPass' => 'llvm/CodeGen/MachineFunctionPass.h',
	'raw_os_ostream' => 'llvm/Support/raw_os_ostream.h',
	'error_category' => 'llvm/Support/system_error.h',
	'FindUsedTypes' => 'llvm/Analysis/FindUsedTypes.h',
	'RegionInfo' => 'llvm/Analysis/RegionInfo.h',
	'ConstantExpr' => 'llvm/IR/Constants.h',
	'MCSymbolData' => 'llvm/MC/MCAssembler.h',
	'BranchProbability' => 'llvm/Support/BranchProbability.h',
	'ConstantVector' => 'llvm/IR/Constants.h',
	'LiveStacks' => 'llvm/CodeGen/LiveStackAnalysis.h',
	'SIToFPInst' => 'llvm/IR/Instructions.h',
	'UDivOperator' => 'llvm/IR/Operator.h',
	'CvtRndSatSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'ImutIntervalAVLFactory' => 'llvm/ADT/ImmutableIntervalMap.h',
	'NamedMDNode' => 'llvm/IR/Metadata.h',
	'RegisterClassInfo' => 'llvm/CodeGen/RegisterClassInfo.h',
	'BlockFrequency' => 'llvm/Support/BlockFrequency.h',
	'Matrix' => 'llvm/CodeGen/PBQP/Math.h',
	'basic_parser_impl' => 'llvm/Support/CommandLine.h',
	'Binary' => 'llvm/Object/Binary.h',
	'ReversePostOrderTraversal' => 'llvm/ADT/PostOrderIterator.h',
	'CallSite' => 'llvm/Support/CallSite.h',
	'SmallSetVector' => 'llvm/ADT/SetVector.h',
	'FileStatus' => 'llvm/Support/PathV1.h',
	'RegisterMaskSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'IntRange' => 'llvm/Support/IntegersSubset.h',
	'MCFixup' => 'llvm/MC/MCFixup.h',
	'Optional' => 'llvm/ADT/Optional.h',
	'DOTGraphTraitsViewer' => 'llvm/Analysis/DOTGraphTraitsPass.h',
	'SmallVectorTemplateBase' => 'llvm/ADT/SmallVector.h',
	'StringInit' => 'llvm/TableGen/Record.h',
	'ExecutionEngineState' => 'llvm/ExecutionEngine/ExecutionEngine.h',
	'MCContext' => 'llvm/MC/MCContext.h',
	'DenseSet' => 'llvm/ADT/DenseSet.h',
	'CallGraphNode' => 'llvm/Analysis/CallGraph.h',
	'Input' => 'llvm/Support/YAMLTraits.h',
	'MCRegisterClass' => 'llvm/MC/MCRegisterInfo.h',
	'UIToFPInst' => 'llvm/IR/Instructions.h',
	'BasicBlock' => 'llvm/IR/BasicBlock.h',
	'InstIterator' => 'llvm/Support/InstIterator.h',
	'BasicBlockSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'Module' => 'llvm/IR/Module.h',
	'StringMatcher' => 'llvm/TableGen/StringMatcher.h',
	'RuntimeDyld' => 'llvm/ExecutionEngine/RuntimeDyld.h',
	'SymbolRef' => 'llvm/Object/ObjectFile.h',
	'SubOperator' => 'llvm/IR/Operator.h',
	'DeltaAlgorithm' => 'llvm/ADT/DeltaAlgorithm.h',
	'ScheduleDAGMutation' => 'llvm/CodeGen/MachineScheduler.h',
	'StringPool' => 'llvm/Support/StringPool.h',
	'Option' => 'llvm/Support/CommandLine.h',
	'ObjectBuffer' => 'llvm/ExecutionEngine/ObjectBuffer.h',
	'ImmutableCallSite' => 'llvm/Support/CallSite.h',
	'TargetFrameLowering' => 'llvm/Target/TargetFrameLowering.h',
	'tool_output_file' => 'llvm/Support/ToolOutputFile.h',
	'LiveVariables' => 'llvm/CodeGen/LiveVariables.h',
	'Function' => 'llvm/IR/Function.h',
	'OptSpecifier' => 'llvm/Option/OptSpecifier.h',
	'TargetTransformInfo' => 'llvm/Analysis/TargetTransformInfo.h',
	'MCInstrAnalysis' => 'llvm/MC/MCInstrAnalysis.h',
	'ImmutablePass' => 'llvm/Pass.h',
	'AbstractLatticeFunction' => 'llvm/Analysis/SparsePropagation.h',
	'TimeRegion' => 'llvm/Support/Timer.h',
	'ObjectCache' => 'llvm/ExecutionEngine/ObjectCache.h',
	'PHITransAddr' => 'llvm/Analysis/PHITransAddr.h',
	'DenseMapBase' => 'llvm/ADT/DenseMap.h',
	'ConstantPoolSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'TargetRegisterClass' => 'llvm/Target/TargetRegisterInfo.h',
	'MCELFObjectTargetWriter' => 'llvm/MC/MCELFObjectWriter.h',
	'SMDiagnostic' => 'llvm/Support/SourceMgr.h',
	'po_iterator_storage' => 'llvm/ADT/PostOrderIterator.h',
	'Linker' => 'llvm/Linker.h',
	'alias' => 'llvm/Support/CommandLine.h',
	'OProfileWrapper' => 'llvm/ExecutionEngine/OProfileWrapper.h',
	'IRBuilderDefaultInserter' => 'llvm/IR/IRBuilder.h',
	'ArrayType' => 'llvm/IR/DerivedTypes.h',
	'Record' => 'llvm/TableGen/Record.h',
	'ArrayRecycler' => 'llvm/Support/ArrayRecycler.h',
	'parser' => 'llvm/Support/CommandLine.h',
	'SparseBitVector' => 'llvm/ADT/SparseBitVector.h',
	'BranchInst' => 'llvm/IR/Instructions.h',
	'TypedInit' => 'llvm/TableGen/Record.h',
	'PointerIntPair' => 'llvm/ADT/PointerIntPair.h',
	'MCConstantExpr' => 'llvm/MC/MCExpr.h',
	'MIBundleOperands' => 'llvm/CodeGen/MachineInstrBundle.h',
	'ValueHandleBase' => 'llvm/Support/ValueHandle.h',
	'APInt' => 'llvm/ADT/APInt.h',
	'DWARFFormValue' => 'llvm/DebugInfo/DWARFFormValue.h',
	'DOTGraphTraitsModulePrinter' => 'llvm/Analysis/DOTGraphTraitsPass.h',
	'IndirectBrInst' => 'llvm/IR/Instructions.h',
	'DerivedArgList' => 'llvm/Option/ArgList.h',
	'SmallDenseMap' => 'llvm/ADT/DenseMap.h',
	'JumpTableSDNode' => 'llvm/CodeGen/SelectionDAGNodes.h',
	'Triple' => 'llvm/ADT/Triple.h',
	'MCTargetAsmParser' => 'llvm/MC/MCTargetAsmParser.h',
	'MCSectionCOFF' => 'llvm/MC/MCSectionCOFF.h',
	'ConstantAggregateZero' => 'llvm/IR/Constants.h',
	'ELFObjectFile' => 'llvm/Object/ELF.h',
	'FunctionLoweringInfo' => 'llvm/CodeGen/FunctionLoweringInfo.h',
	'SectionRef' => 'llvm/Object/ObjectFile.h',
	'StringMapImpl' => 'llvm/ADT/StringMap.h',
	'PassRegistry' => 'llvm/PassRegistry.h',

);


my $file = $ARGV[0];

my ($folder, $file_name, $file_ext) = ($file =~ /([^\\\/]+)[\\\/]([^\\\/]+)\.(\w+)$/);
my $output_h = "$file_name.h";
my $output_c = "$file_name.cpp";
unlink $output_h;
unlink $output_c;

print "Source   : $file\n";

my $use_netlib = 0;
my $use_marshal = 0;
my $use_marshal_cpp = 0;
my @libs = ();
my @refs_decl = ();
my @refs_incl = ();
my @refs_incl_h = ();
my @additional_decl = ();

my $class = '';
my $base = '';
my @data = ();
my $public = 0;
my $static_class = 0;
my $use_utils = 0;
my (@header, @code) = ((), ());
open F, $file;
while (<F>)
{
	s/^\s\s// if ($class eq 'DebugLoc' or ($class and ($file_name eq 'IntrinsicInst' or $file_name eq 'PrettyStackTrace')));

	if (/^namespace (\w+)\s*\{/
		and ($1 eq 'CallingConv' or $1 eq 'Intrinsic'))
	{
		print "namespace $1\n";
		$class = $1;
		$base = '';
		@data = ();
		$public = 1;
		$static_class = 1;
	}
	elsif (not $class
		and /^\s*class (\w+)(?:\s*:\s*([\w <>,\*]+))?\s*(\{)?[^;\{]*(?:\/\/.*)?$/)
	{
		if ($1 eq 'ConcreteOperator'
			or $1 eq 'IRBuilderDefaultInserter'
			or $1 eq 'raw_svector_ostream'
			or $1 eq 'FPPassManager'
			or $1 =~ /iterator/)
		{
			next;
		}
		print "class $1\n";
		$class = $1;
		$base = $2;
		unless ($3)
		{
			my $cl;
			do {
				$_ = <F>;
				/^\s*([^\{]+)(\{)?/;
				$base .= $1;
				$cl = $2;
			} while (not $cl);
		}
		@data = ();
		$public = 0;
		$static_class = 0;
	}
	elsif ($class
			and (/^\};/ or ($static_class and /^\}/)))
	{
		my ($h, $c) = &manage_class();
		push @header, $h;
		push @code, $c if ($c);
		$class = 0;
	}
	elsif (not $class and /^\s*enum (\w+)(?!\w)([^\}]*)(?:\};)?/)
	{
		my $h = "enum class " . $1 . $2;
		unless ($3)
		{
			while (<F>) {
				last if (/\};/);
				$h .= $_;
			}
		}
		$h .= '};';
		$h =~ s/\s*\{/\n{/;
		$h =~ s/^\s\s/\t/g;
		$h =~ s/\s*\/\/.+//g;
		push @header, $h;
	}
	elsif ($class and /^\s*class (\w+)\s*[\{:]([^\}]*)(?:\};)?/)
	{
		print "IGNORE $1 in $class\n";
		unless ($3)
		{
			while (<F>) {
				last if (/\};/);
			}
		}
	} elsif (/^\s*(public|protected|private):/) {
		$public = ($1 eq 'public');
	} elsif ($public) {
		push @data, $_;
	}
}
close F;

print "Generate : $output_h\n";
open H, "> $output_h";
print H "#pragma once\n";
print H "#using <mscorlib.dll>\n" if ($use_netlib);
print H "#include \"llvm/" . ($folder ne 'llvm' ? "$folder/" : '') . "$file_name.$file_ext\"\n";
foreach (@refs_incl_h) {
	print H "#include \"$_\"\n";
}
print H "\n";
print H "namespace LLVM\n";
print H "{\n\n";
foreach (@refs_decl) {
	my $t;
	if ($_ eq 'AnalysisID') {
		$t = 'value';
	} elsif (&is_enum($_)) {
		$t = 'enum';
	} else {
		$t = 'ref';
	}
	print H "$t class $_;\n";
}
foreach (@additional_decl) {
	print H "$_\n";
}
print H "\n" if ((@refs_decl ne 0) or (@additional_decl ne 0));
print H (join "\n\n", @header);
print H "\n}\n";
close H;

if ($#code >= 0)
{
	print "Generate : $output_c\n";
	open C, "> $output_c";
	print C "#include \"$output_h\"\n";
	foreach (@libs) {
		print C "#include \"$_\"\n";
	}
	foreach (@refs_incl) {
		print C "#include \"$_\"\n";
	}
	print C "#include <msclr/marshal.h>\n" if ($use_marshal);
	print C "#include <msclr/marshal_cpp.h>\n" if ($use_marshal_cpp);
	print C "#include \"utils.h\"\n" if ($use_utils);
	print C "\n";
	print C "using namespace LLVM;\n\n";
	print C (join "\n\n", @code);
	close C;
}


my $abstruct;
my $constr_inhr;
my @member_private;
my @decl;

sub manage_class
{
	if ($class eq 'Value')
	{
		push @refs_decl, 'Value';
		push @additional_decl,
			'typedef System::Collections::Generic::KeyValuePair<System::String ^, Value ^> ValueName;';
	}
	elsif ($class eq 'Pass')
	{
		push @additional_decl, <<EOF

public value class AnalysisID
{
internal:
	const void *base;
	AnalysisID(const void *base)
		: base(base)
	{
	}
};
EOF
	}

	$constr_inhr = '';
	@member_private = ();
	my @base_reconstr = ();
	foreach (split /,\s*/, $base)
	{
		if (/public (\w+?[^\s])\s*$/
			and $1 ne 'FoldingSetNode'
			and $1 ne 'Inserter'
			and (substr $1, 0, 10) ne 'ilist_node')
		{
			&add_lib($1, 1);
			$constr_inhr .= "\t\t, $1(base)\n";
			push @base_reconstr, 'public ' . $1;
		}
	}
	$base = join ', ', @base_reconstr;

	@decl = ();

	my $text = join '', @data;
	$text =~ s/enum (\w+\s*\{[^\}]+\};)/
		push @decl, "enum class $1";
		'' /megs;

	$text =~ s/\s*\/\/.*//g;
	$text =~ s/,\s*\n\s*/, /mg;
	$text =~ s/\{[^\{\}]*((?R)[^\{\}]*)*\}//mgs;
	$text =~ s/\(\s*\n\s*/(/mg;
	$text =~ s/\s*\n\s*\)/)/mg;
	$text =~ s/^\s*\n//mg;

	$text =~ s/([\*&]) / $1/g;
	$text =~ s/(?<=[a-zA-Z])\s+(?=\()//g;
	$text =~ s/(?:\s*;\s*|(?<=[^;\s])\s*)$/;/mg;
	$text =~ s/ const;$/;/mg;
	$text =~ s/^\s*~$class\(\)\s*;\s*$//mg;
	$text =~ s/^	/\t/mg;

	$abstruct = ($text =~ / = 0;/);

	my @header = ();
	my @code = ();
	my $has_constr = 0;

	foreach (split /\n+/, $text)
	{
		if (/^\s*
			((?:static\ )?+)
			((?:explicit\ )?+(?:virtual\ )?+(?:inline\ )?+)
			\s*((?&TYPE))?
			(?(3)\s+)
			([*&]?)(\w+)
			\(
				((?&ARG)(?:,\s*(?&ARG))*)?
				((?(6),\s*)(?&ARG)(?&DEF)(?:,\s*(?&ARG)(?&DEF))*)?
			\)
			(?:\s*:\s*\w+[^;]+)?\s*(?:=\s*0\s*)?;

			(?(DEFINE)
				(?<TYPE>(?:\w+::)?\w+(?:\ \w+)*(?:<(?:\w+::)?\w+\s*(?:\*\s*)?>)?)
				(?<ARG>(?&TYPE)(?:\ [*&]?\w*)?)
				(?<DEF>\s*=\s*(?:\w+(?:\(\))?|\"\"))
			)
			/x and &func_filter($1, $2, $3, $4, $5, $6 . $7)
			and not ($abstruct and $5 eq $class))
		{
			$has_constr = 1 if ($5 eq $class);
			my ($h, $c) = &trans_func($1, $2, $3, $4, $5, $6, $7);
			for (my $i = 0; $i <= $#{$h}; $i++)
			{
				next if (grep { $_ eq $$h[$i] } @header);
				push @header, $$h[$i];
				push @code, $$c[$i];
			}
		}
		elsif ($_ eq '  struct ModuleFlagEntry;')
		{
			&add_lib('MDString', 1);
			&add_lib('Value', 1);
			my $h =<<EOF;
value class ModuleFlagEntry
	{
	public:
		ModFlagBehavior ^Behavior;
		MDString ^Key;
		Value ^Val;
		ModuleFlagEntry(ModFlagBehavior B, MDString ^K, Value ^V)
			: Behavior(B)
			, Key(K)
			, Val(V)
		{
		}

	internal:
		ModuleFlagEntry(llvm::Module::ModuleFlagEntry *base)
			: Behavior(safe_cast<ModFlagBehavior>(base->Behavior))
			, Key(gcnew MDString(base->Key))
			, Val(gcnew Value(base->Val))
		{
		}
	};
EOF
			push @decl, $h;
		}
		else
		{
			push @header, "\t//" . (substr $_, 1) . "\n";
		}
	}

	$base =~ s/,\s*public ilist_node<\w+>\s*//;

	my $original = 'llvm::' . $class;
	$original .= '<>' if ($class eq 'IRBuilder');

	my $pre_header = "public ref class $class\n";
	$pre_header .= "\t: $base\n" if ($base);
	$pre_header .= "{\n";

	if (@decl)
	{
		$pre_header .= "public:\n";
		foreach (@decl)
		{
			s/  /\t/g;
			s/\s*\/\/.+//g;
			s/ \{/\n\t{/;
			$pre_header .= "\t$_\n";
		}
		$pre_header .= "\n";
	}
	if (@member_private or $has_constr)
	{
		$pre_header .= "private:\n";
		$pre_header .= "\tbool constructed;" if ($has_constr);
		$pre_header .= join '', @member_private;
		$pre_header .= "\n";
	}
	if ($static_class) {
		$pre_header .= "public:\n";
	} else {
		$pre_header .=
			"internal:\n"
			. "\t$original *base;\n"
			. "\t$class($original *base);\n\n"
			. "public:\n"
			. "\t!$class();\n"
			. "\tvirtual ~$class();\n";
	}

	my $pre_code = '';
	unless ($static_class)
	{
		$pre_code .=
			"${class}::$class($original *base)\n"
			. "\t: base(base)\n"
			. &reduce_indent($constr_inhr);
		$pre_code .= "\t, constructed(false)\n" if ($has_constr);
		$pre_code .=
			"{\n}\n"
			. "${class}::!$class()\n"
			. "{\n";
		if ($has_constr)
		{
			$pre_code .=
				"\tif (constructed)\n"
				. "\t{\n"
				. "\t\tdelete base;\n"
				. "\t}\n";
		}
		$pre_code .= "}\n"
			. "${class}::~$class()\n{\n\tthis->!$class();\n}\n";
	}

	return ($pre_header . (join '', @header) . "};\n", $pre_code . (join '', @code));
}
sub func_filter
{
	my ($static, $mod, $type, $ptr, $name, $args) = @_;

	if ($type =~ /^const (?!char|Twine)| operator$|iterator$|APInt/
		or $name eq 'DECLARE_TRANSPARENT_OPERAND_ACCESSORS'
		or $name eq 'DEFINE_HELPERS'
		or $name eq 'raw_ostream'
		or $name eq 'getIntrinsicInfoTableEntries'
		or $name eq 'use_empty_except_constants'
		or $name eq 'getAnalysisIfAvailable'
		or $name eq 'addRequired'
		or $name eq 'addRequiredTransitive'
		or $name eq 'addPreserved'
		or $name eq 'getImmutablePasses'
		or $args =~ /iterator|APInt|APFloat|FoldingSet|InlineAsmDiagHandlerTy|CaseIt|IntegersSubset|TBAAStructField|Inserter|InsertPoint| T |DataLayout|SmallVectorImpl/
		or $type eq 'APInt'
		or $type eq 'APFloat'
		or $type eq 'InlineAsmDiagHandlerTy'
		or $type eq 'CaseIt'
		or $type eq 'ConstCaseIt'
		or $type eq 'ConstraintInfoVector'
		or $type eq 'InstTy'
		or $type eq 'InsertPoint'
		or $type eq 'AnalysisType'
		)
	{
		return 0;
	}
	return 1;
}

sub trans_func
{
	my ($static, $mod, $type, $ptr, $name, $arg, $varg) = @_;

	if (($class eq 'Value') and ($name eq 'getValueName'))
	{
		&add_lib('StringRef');
		&add_lib('StringMapEntry');
		$use_utils = 1;
		my $code =<<EOF;
ValueName ^Value::getValueName()
{
	auto a = base->getValueName();
	return gcnew ValueName(utils::manage_str(a->getKey()), gcnew Value(a->getValue()));
}
EOF
		my @h = ("\tValueName ^getValueName();\n");
		my @c = ($code);
		return (\@h, \@c);
	}
	if (($class eq 'Value') and ($name eq 'setValueName'))
	{
		&add_lib('StringRef');
		&add_lib('StringMapEntry');
		$use_utils = 1;
		my $code =<<EOF;
void Value::setValueName(ValueName ^VN)
{
	msclr::interop::marshal_context ctx;
	const char *key = ctx.marshal_as<const char *>(VN->Key);
	auto a = llvm::ValueName::Create(key, key + VN->Key->Length);
	auto value = VN->Value->base;
	a->setValue(value);
	base->setValueName(a);
}
EOF
		my @h = ("\tvoid setValueName(ValueName ^VN);\n");
		my @c = ($code);
		return (\@h, \@c);
	}

	$arg =~ tr/*/^/;
	my @args = split /,\s*/, $arg;
	$varg =~ tr/*/^/;
	$varg =~ s/\s*=\s*\w+//g;
	my @vargs = split /,\s*/, $varg;
	if (@vargs == 0) {
		push @vargs, '';
	} elsif (@args == 0) {
		unshift @vargs, '';
	}

	my $return_by_ptr = 0;
	my $constr = '';
	my $pre = '';
	my $post = '';
	my $constructor = ((not $type) and ($name eq $class));
	my $store = 0;
	my $use_ctx = 0;
	my @arg_call = ();

	if (not $constructor and ($args[$#args] =~ /^(SmallVectorImpl<\w+>)\s+&\w+$/))
	{
		pop @args;
		$type = $1;
		$return_by_ptr = 1;
	}

	$static = 'static ' if (not $static and $static_class);

	for (my $i = 0; $i <= $#args; $i++)
	{
		($args[$i], $arg_call[$i], $constr, $pre, $post, $store, $use_ctx)
			= &manage_arg($args[$i], $constr, $pre, $post, $store, $use_ctx, $constructor);
	}

	if ($return_by_ptr)
	{
		splice @arg_call, 1, 0, 'r';
	}
	
	my $array = 0;
	my $need_cast = &is_enum($type);

	if ($need_cast
		and $type !~ /::/
		and (defined $defined_in_class{$type}))
	{
		$type = $defined_in_class{$type} . '::' . $type;
	}

	if ($type =~ /(SmallVectorImpl)<((?:\w+::)?\w+)\s*(\*?)>/)
	{
		&add_lib($1);
		&add_lib($2);
		$use_netlib = 1;
		$store++;
		my ($t, $c) = ($2, 'r[i]');
		if ((grep { $_ =~ /(?:enum|value) class $t(?!\w)/ } @decl)) {
			$t = $class . '::' . $t;
		}

		$pre = "\tllvm::SmallVector<" . (&is_prim_type($t) ? '' : 'llvm::') . $t . ($3 ? ' ^' : '') . ", 8> r;\n";
		unless (&is_prim_type($t))
		{
			if ($t eq 'StringRef')
			{
				$use_utils = 1;
				$t = 'System::String ^';
				$c = "utils::manage_str($c)";
			}
			elsif (&is_enum($t))
			{
				$c = "safe_cast<$t>($c)";
			}
			else
			{
				if ($t !~ /\^$/) {
					$c = "gcnew $t(&$c)";
					$t = "$t ^";
				} else {
					$c = "gcnew $t($c)";
				}
			}
		}
		$post =
			"\tarray<$t> ^s = gcnew array<$t>(r.size());\n"
			. "\tfor (int i = 0; i < s->Length; i++)\n"
			. "\t\ts[i] = $c;\n"
			. $post;
		$type = "array<$t>";
		$ptr = 1;
		$array = 1;
	}
	elsif ($type =~ /(ArrayRef)<((?:\w+::)?\w+)\s*(\*?)>/)
	{
		&add_lib($1);
		&add_lib($2);
		$use_netlib = 1;
		$store++;
		my ($t, $c);
		($t, $c, $constr, $pre, $post, $store, $use_ctx)
			= &manage_arg($2 . ($3 ? ' ^' : ' ') . 'r', $constr, $pre, $post, $store, $use_ctx, $constructor);
		$t =~ s/ ?\w+$//;
		$post =
			"\tarray<$t> ^s = gcnew array<$t>(r.size());\n"
			. "\tfor (int i = 0; i < s->Length; i++)\n"
			. "\t\ts[i] = ${c}[i];\n"
			. $post;
		$type = "array<$t>";
		$ptr = '*';
		$array = 1;
	}
	elsif ($type =~ /^(\w+)ListType$/)
	{
		my $t = $1;
		$t = 'GlobalVariable' if ($t eq 'Global');
		$t = 'GlobalAlias' if ($t eq 'Alias');
		$t = 'NamedMDNode' if ($t eq 'NamedMD');
		$t = 'Instruction' if ($t eq 'Inst');
		&add_type($t);
		&add_lib('iplist');
		$use_netlib = 1;
		$type = "System::Collections::Generic::List<$t ^>";
		$store++;
		$post =
			"\tauto s = gcnew System::Collections::Generic::List<$t ^>(r->size());\n"
			. "\tfor (auto it = r->begin(); it != r->end(); ++it)\n"
			. "\t\ts->Add(gcnew $t(it));\n"
			. $post;
		$ptr = '&';
		$array = 1;
	}
	elsif (($type eq 'const char' and $ptr)
		or $type eq 'StringRef'
		or $type eq 'std::string')
	{
		$use_netlib = 1;
		&add_lib('StringRef') if ($type eq 'StringRef');
		$type = 'System::String';
		$ptr = '*';
		$need_cast = 0;
	}
	elsif ($type eq 'AnalysisID')
	{
		$ptr = '*';
	}
	elsif ($type)
	{
		&add_type($type);
		$ptr = '&' if (not $ptr and &is_ref_class($type));
	}

	my $call_by;
	if ($constructor)
	{
		$mod = '';
		$call_by = 'new llvm::';
	}
	else
	{
		if ((grep { $_ =~ /enum class $type(?!\w)/ } @decl)) {
			$mod .= $class . '::';
			$need_cast = 1;
		}
		$mod .= "$type " . ($ptr ? ($type eq 'void' ? '*' : '^') : '');
		$call_by = ($static ? "llvm::${class}::" : 'base->');
	}
	my $mod_c = $mod;
	$mod_c =~ s/virtual |explicit //;

	my $no_ret = (($type eq 'void') and (not $ptr));
	my $suffix = ($return_by_ptr ? 'Array' : '');
	my $template_param = (($constructor and $class eq 'IRBuilder') ? '<>' : '');
	my @header = ();
	my @code = ();
	foreach (@vargs)
	{
		if ($_)
		{
			last if (/ErrInfo/);
			my ($a, $c);
			($a, $c, $constr, $pre, $post, $store, $use_ctx)
				= &manage_arg($_, $constr, $pre, $post, $store, $use_ctx, $constructor);
			push @args, $a;
			push @arg_call, $c;
		}

		my $call = $call_by . $name . $template_param . '(' . join(', ', @arg_call) . ')';
		if (($ptr ne '*')
			and not $constructor
			and not $need_cast
			and not $return_by_ptr
			and ($type ne 'void')
			and ($type ne 'AnalysisID')
			and not &is_prim_type($type))
		{
			$call =  '&' . $call;
		}

		my $arg_str = join ', ', @args;

		if ($constructor and $use_ctx)
		{
			my $arg_names = join ', ', ( map { /[ ^&](\w+)$/; $1 } @args );
			my $h = "\tstatic llvm::$class$template_param *_construct($arg_str);\n";
			unless (grep { $_ eq $h } @member_private)
			{
				push @member_private, $h;
				push @header, "\t$mod$class($arg_str);\n";
				push @code, "llvm::$class$template_param *${class}::_construct($arg_str)\n"
					. "{\n"
					. $pre
					. "\treturn $call;\n"
					. "}\n"
					. "$mod_c${class}::$class($arg_str)\n"
					. "\t: ${constr}base(_construct($arg_names))\n" . &reduce_indent($constr_inhr)
					. "\t, constructed(true)\n"
					. "{\n}\n";
			}
			next;
		}

		unless ($return_by_ptr)
		{
			if ($ptr)
			{
				if ($type eq 'System::String') {
					$use_utils = 1;
					$call = "utils::manage_str($call)";
				} elsif ((not $array) and ($type ne 'void')) {
					$call = "gcnew $type($call)";
				}
			}
			$call = "safe_cast<$type>($call)" if ($need_cast);
		}

		$post =~ s/\t*return \w+;\n$//m if ($no_ret);

		my $decl_suffix = '';
		if ((($base =~ /public GlobalValue/)
			and ($name eq 'removeFromParent'
				or $name eq 'eraseFromParent'
				or $name eq 'copyAttributesFrom'))
		or ($class ne 'Pass'
			and ($name eq 'assignPassManager'
				or $name eq 'getPotentialPassManagerType'
				or $name eq 'getAsImmutablePass'
				or $name eq 'runOnModule'))
		or ($class ne 'PassManagerBase'
			and $name eq 'add')
		or ($class ne 'Constant'
			and $name eq 'destroyConstant'))
		{
			$mod = 'virtual ' . $mod if ($mod !~ /virtual/);
			$decl_suffix .= ' override';
		}

		push @header, "\t$static$mod$name$suffix($arg_str)$decl_suffix;\n";
		push @code, "$mod_c${class}::$name$suffix($arg_str)\n"
				. ($constructor
					? "\t: ${constr}base($call)\n"
						. &reduce_indent($constr_inhr)
						. "\t, constructed(true)\n"
					: '')
				. "{\n"
				. $pre
				. ($constructor ? ''
					: "\t"
					. (($no_ret or $return_by_ptr)
						? ''
						: ($store ? 'auto r = ' : 'return '))
					. $call . ";\n")
				. $post
				. ($array
					? "\treturn s;\n"
					: (($store and not $constructor and not ($no_ret or $return_by_ptr))
						? "\treturn r;\n"
						: '')
					)
				. "}\n";
	}

	return (\@header, \@code);
}

sub manage_arg
{
	my ($arg, $constr, $pre, $post, $store, $use_ctx, $constructor) = @_;
	my ($r, $call);

	$arg =~ s/^enum //;

	if ($arg =~ /(?<c>ArrayRef)<(?<ns>\w+::)?(?<t>\w+)\s*(?<ptr>\^)?> &?(?<n>\w+)/)
	{
		&add_lib($+{c});
		&add_type($+{t});

		$store++;
		if ((not $+{ns}) and &is_prim_type($+{t}))
		{
			$use_utils = 1;
			$r = "array<$+{t}> ^$+{n}";
			$call = "utils::unmanage_array($+{n})";
		}
		else
		{
			my $is_enum = &is_enum($+{t});
			$r = "array<$+{ns}$+{t}" . ($is_enum ? '' : ' ^') . "> ^$+{n}";
			my $n = chr(97 + $store);
			my $m = $n . 'rr';
			my $p = ($+{ptr} ? '*' : '');
			my $h = ($is_enum ? '' : '^');
			$pre .=
				"\tllvm::$+{ns}$+{t} *$p$n = new llvm::$+{ns}$+{t}${p}[$+{n}->Length];\n"
				. "\tfor (int i = 0; i < $+{n}->Length; i++)\n"
				. "\t\t${n}[i] = " . (($+{ptr} or $is_enum) ? '' : '*') . &make_call("$+{ns}$+{t} $h$+{n}" . "[i]") . ";\n"
				. "\tllvm::ArrayRef<llvm::$+{ns}$+{t}$p> $m($n, $+{n}->Length);\n";
			$call = $m;
			$post = "\tdelete $n;\n" . $post;
		}
	}
	elsif ($arg =~ /((?<=const )(?:Twine|char)|StringRef)\s*[\^&]?\s*(\w+)/)
	{
		$use_netlib = 1;
		$use_marshal = 1;
		&add_lib($1) if ($1 ne 'char');

		$r = "System::String ^$2";
		$call = "ctx.marshal_as<const char *>($2)";

		unless ($use_ctx)
		{
			$use_ctx = 1;
			$pre = "\tmsclr::interop::marshal_context ctx;\n" . $pre;
		}
	}
	elsif ($arg =~ /^(?:const )?((?:\w+::)*\w+)(?: &?(\^?)(\w*))?$/ and not &is_prim_type($1))
	{
		my $n = $3;
		unless ($n) {
			$n = $1;
			$n =~ s/^.*([A-Z][a-z]*)$/ lc($1) /e;
		}
		&add_type($1);
		if ($1 eq 'void') {
			$r = "void *$n";
			$call = $n;
		} else {
			my $ptr = '';
			if ($2 or ($1 eq 'AnalysisID')) {
				$ptr = '^';
			} elsif (&is_ref_class($1)) {
				$ptr = '&';
			}
			$r = "$1 " . ($ptr ? '^' : '') . $n;
			$call = &make_call("$1 $ptr$n");
		}
	}
	elsif ($arg =~ /^(\w+) &(\w+)$/ and &is_prim_type($1))
	{
		$r = $arg;
		$call = $2;
	}
	else
	{
		$r = $arg;
		$call = &make_call($arg);
	}

	return ($r, $call, $constr, $pre, $post, $store, $use_ctx);
}

sub make_call
{
	$_ = $_[0];
	if (/^((?:(\w+)::)?([\w ]+)) (\w+(?:\[\w+\])?)$/)
	{
		if (&is_enum($1)) {
			my $ns = $2;
			$ns = $class if ((not $ns) and (defined $defined_in_class{$3}));
			return "safe_cast<llvm::" . ($ns ? $ns . '::' : '') . "$3>($4)";
		} else {
			return $4;
		}
	}
	elsif (/^([\w ]+) ([\^&])(\w+(?:\[\w+\])?)$/)
	{
		return ($2 eq '&' ? '*' : '') . "$3->base";
	}
	elsif (/(^[\w ]+) \^(\w+(?:\[\w+\])?)$/)
	{
		return "$2->base";
	}
	return '?';
}

sub add_lib
{
	my $lib = &defined_in($_[0]);
	my $in_header = $_[1];
	$lib =~ s/^llvm\/(?:IR|Support|Assembly)\/|^llvm\/(?=[^\/]+$)//;
	
	if ($lib and $lib ne "$file_name.h")
	{
		if ($in_header and not (grep { $_ eq $lib } @refs_incl_h)) {
			push @refs_incl_h, $lib;
		} elsif (not (grep { $_ eq $lib } @libs)) {
			push @libs, $lib;
		}
	}
}
sub add_type
{
	my $n = $_[0];
	$n =~ s/^const //;
	
	if ($n =~ /^(\w+)::(.+)$/)
	{
		&add_lib($1, 1);
		$n = $2;
	}
		
	if ($n eq $class
		or (grep { $_ =~ /enum class $n(?!\w)/ } @decl))
	{
		return;
	}

	if (&is_global_enum($n))
	{
		&add_lib($n, 1);
		return;
	}

	my $fn = &defined_in($n);
	$fn =~ s/^llvm\/(?:IR|Support|Assembly)\/|^llvm\/(?=[^\/]+$)//;

	if ($fn)
	{
		push @refs_decl, $n unless (grep { $_ eq $n } @refs_decl);
		push @refs_incl, $fn unless (grep { $_ eq $fn } @refs_incl);
		return;
	}
}
sub defined_in
{
	my $type = $_[0];

	return 'utils.h' if ($type eq 'utils');

	$type =~ s/^const //;
	$type =~ s/^\w+:://g;
	$type =~ s/<[^<>]*((?R)[^<>]*)*>//;
	if ($type ne 'void'
		and not &is_prim_type($type)
		and not (grep { $_ =~ /^enum class $type/ } @decl))
	{
		return $defined_in{$type};
	}
	return '';
}
sub is_prim_type
{
	return grep { $_ eq $_[0] } @prim_types;
}
sub is_ref_class
{
	my $type = $_[0];
	return ((defined $defined_in{$type}) and not &is_enum($type));
}
sub is_enum
{
	my $type = $_[0];
	my ($ns, $n) = ($type =~ /^(\w+)::(\w+)$/);
	$n = $type unless ($n);
	return (
		&is_global_enum($type)
		or (($ns or not (defined $defined_in{$type}))
			and (defined $defined_in_class{$n})));
}
sub is_global_enum
{
	my $type = $_[0];
	return (($type eq 'AtomicOrdering')
		or ($type eq 'SynchronizationScope')
		or ($type eq 'PassManagerType')
		or ($type eq 'PassKind')
		or ($type eq 'PassDebuggingString'));
}
sub reduce_indent
{
	my $s = $_[0];
	$s =~ s/\t\t/\t/g;
	return $s;
}
