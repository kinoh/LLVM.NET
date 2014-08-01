#include "PrettyStackTrace.h"
#include <msclr/marshal.h>

using namespace LLVM;

PrettyStackTraceEntry::PrettyStackTraceEntry(llvm::PrettyStackTraceEntry *base)
	: base(base)
{
}
inline PrettyStackTraceEntry ^PrettyStackTraceEntry::_wrap(llvm::PrettyStackTraceEntry *base)
{
	return base ? gcnew PrettyStackTraceEntry(base) : nullptr;
}
PrettyStackTraceEntry::!PrettyStackTraceEntry()
{
}
PrettyStackTraceEntry::~PrettyStackTraceEntry()
{
	this->!PrettyStackTraceEntry();
}


PrettyStackTraceString::PrettyStackTraceString(llvm::PrettyStackTraceString *base)
	: base(base)
	, PrettyStackTraceEntry(base)
	, constructed(false)
{
}
inline PrettyStackTraceString ^PrettyStackTraceString::_wrap(llvm::PrettyStackTraceString *base)
{
	return base ? gcnew PrettyStackTraceString(base) : nullptr;
}
PrettyStackTraceString::!PrettyStackTraceString()
{
	if (constructed)
	{
		delete base;
	}
}
PrettyStackTraceString::~PrettyStackTraceString()
{
	this->!PrettyStackTraceString();
}
llvm::PrettyStackTraceString *PrettyStackTraceString::_construct(System::String ^str)
{
	msclr::interop::marshal_context ctx;
	return new llvm::PrettyStackTraceString(ctx.marshal_as<const char *>(str));
}
PrettyStackTraceString::PrettyStackTraceString(System::String ^str)
	: base(_construct(str))
	, PrettyStackTraceEntry(base)
	, constructed(true)
{
}


PrettyStackTraceProgram::PrettyStackTraceProgram(llvm::PrettyStackTraceProgram *base)
	: base(base)
	, PrettyStackTraceEntry(base)
{
}
inline PrettyStackTraceProgram ^PrettyStackTraceProgram::_wrap(llvm::PrettyStackTraceProgram *base)
{
	return base ? gcnew PrettyStackTraceProgram(base) : nullptr;
}
PrettyStackTraceProgram::!PrettyStackTraceProgram()
{
}
PrettyStackTraceProgram::~PrettyStackTraceProgram()
{
	this->!PrettyStackTraceProgram();
}
