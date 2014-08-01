#pragma once
#using <mscorlib.dll>
#include "llvm/IR/LLVMContext.h"

namespace LLVM
{

ref class Instruction;

public ref class LLVMContext
{
private:
	bool constructed;

internal:
	llvm::LLVMContext *base;

protected:
	LLVMContext(llvm::LLVMContext *base);

internal:
	static inline LLVMContext ^_wrap(llvm::LLVMContext *base);

public:
	!LLVMContext();
	virtual ~LLVMContext();
	// LLVMContextImpl *const pImpl;
	LLVMContext();
	// enum;
	unsigned getMDKindID(System::String ^Name);
	array<System::String ^> ^getMDKindNamesArray();
	// typedef void(*InlineAsmDiagHandlerTy)(const SMDiagnostic &, void *Context, unsigned LocCookie);
	// void setInlineAsmDiagnosticHandler(InlineAsmDiagHandlerTy DiagHandler, void *DiagContext = 0);
	// InlineAsmDiagHandlerTy getInlineAsmDiagnosticHandler();
	void *getInlineAsmDiagnosticContext();
	void emitError(unsigned LocCookie, System::String ^ErrorStr);
	void emitError(Instruction ^I, System::String ^ErrorStr);
	void emitError(System::String ^ErrorStr);
};

}
