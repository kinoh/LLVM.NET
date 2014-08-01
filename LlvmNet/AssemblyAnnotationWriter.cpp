#include "AssemblyAnnotationWriter.h"

using namespace LLVM;

AssemblyAnnotationWriter::AssemblyAnnotationWriter(llvm::AssemblyAnnotationWriter *base)
	: base(base)
{
}
inline AssemblyAnnotationWriter ^AssemblyAnnotationWriter::_wrap(llvm::AssemblyAnnotationWriter *base)
{
	return base ? gcnew AssemblyAnnotationWriter(base) : nullptr;
}
AssemblyAnnotationWriter::!AssemblyAnnotationWriter()
{
}
AssemblyAnnotationWriter::~AssemblyAnnotationWriter()
{
	this->!AssemblyAnnotationWriter();
}
