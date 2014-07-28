#include "AssemblyAnnotationWriter.h"

using namespace LLVM;

AssemblyAnnotationWriter::AssemblyAnnotationWriter(llvm::AssemblyAnnotationWriter *base)
	: base(base)
{
}
AssemblyAnnotationWriter::!AssemblyAnnotationWriter()
{
}
AssemblyAnnotationWriter::~AssemblyAnnotationWriter()
{
	this->!AssemblyAnnotationWriter();
}
