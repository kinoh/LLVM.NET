#pragma once
#include "llvm/Assembly/AssemblyAnnotationWriter.h"

namespace LLVM
{

public ref class AssemblyAnnotationWriter
{
internal:
	llvm::AssemblyAnnotationWriter *base;
	AssemblyAnnotationWriter(llvm::AssemblyAnnotationWriter *base);

public:
	!AssemblyAnnotationWriter();
	virtual ~AssemblyAnnotationWriter();
	// virtual ~AssemblyAnnotationWriter();
	// virtual void emitFunctionAnnot(const Function *, formatted_raw_ostream &);
	// virtual void emitBasicBlockStartAnnot(const BasicBlock *, formatted_raw_ostream &);
	// virtual void emitBasicBlockEndAnnot(const BasicBlock *, formatted_raw_ostream &);
	// virtual void emitInstructionAnnot(const Instruction *, formatted_raw_ostream &);
	// virtual void printInfoComment(const Value &, formatted_raw_ostream &);
};

}
