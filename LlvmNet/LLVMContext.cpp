#include "LLVMContext.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/Twine.h"
#include "Instruction.h"
#include <msclr/marshal.h>
#include "utils.h"

using namespace LLVM;

LLVMContext::LLVMContext(llvm::LLVMContext *base)
	: base(base)
	, constructed(false)
{
}
inline LLVMContext ^LLVMContext::_wrap(llvm::LLVMContext *base)
{
	return base ? gcnew LLVMContext(base) : nullptr;
}
LLVMContext::!LLVMContext()
{
	if (constructed)
	{
		delete base;
	}
}
LLVMContext::~LLVMContext()
{
	this->!LLVMContext();
}
LLVMContext::LLVMContext()
	: base(new llvm::LLVMContext())
	, constructed(true)
{
}
unsigned LLVMContext::getMDKindID(System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return base->getMDKindID(ctx.marshal_as<const char *>(Name));
}
array<System::String ^> ^LLVMContext::getMDKindNamesArray()
{
	llvm::SmallVector<llvm::StringRef, 8> r;
	base->getMDKindNames(r);
	array<System::String ^> ^s = gcnew array<System::String ^>(r.size());
	for (int i = 0; i < s->Length; i++)
		s[i] = utils::manage_str(r[i]);
	return s;
}
void *LLVMContext::getInlineAsmDiagnosticContext()
{
	return base->getInlineAsmDiagnosticContext();
}
void LLVMContext::emitError(unsigned LocCookie, System::String ^ErrorStr)
{
	msclr::interop::marshal_context ctx;
	base->emitError(LocCookie, ctx.marshal_as<const char *>(ErrorStr));
}
void LLVMContext::emitError(Instruction ^I, System::String ^ErrorStr)
{
	msclr::interop::marshal_context ctx;
	base->emitError(I->base, ctx.marshal_as<const char *>(ErrorStr));
}
void LLVMContext::emitError(System::String ^ErrorStr)
{
	msclr::interop::marshal_context ctx;
	base->emitError(ctx.marshal_as<const char *>(ErrorStr));
}
