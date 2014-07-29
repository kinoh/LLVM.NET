#pragma once
#using <mscorlib.dll>
#include "llvm/Support/PrettyStackTrace.h"

namespace LLVM
{

public ref class PrettyStackTraceEntry
{
internal:
	llvm::PrettyStackTraceEntry *base;
	PrettyStackTraceEntry(llvm::PrettyStackTraceEntry *base);

public:
	!PrettyStackTraceEntry();
	virtual ~PrettyStackTraceEntry();
	// PrettyStackTraceEntry();
	// virtual ~PrettyStackTraceEntry();
	// virtual void print(raw_ostream &OS) const = 0;
	// const PrettyStackTraceEntry *getNextEntry();
};


public ref class PrettyStackTraceString
	: public PrettyStackTraceEntry
{
private:
	bool constructed;	static llvm::PrettyStackTraceString *_construct(System::String ^str);

internal:
	llvm::PrettyStackTraceString *base;
	PrettyStackTraceString(llvm::PrettyStackTraceString *base);

public:
	!PrettyStackTraceString();
	virtual ~PrettyStackTraceString();
	PrettyStackTraceString(System::String ^str);
	// virtual void print(raw_ostream &OS) const LLVM_OVERRIDE;
};


public ref class PrettyStackTraceProgram
	: public PrettyStackTraceEntry
{
internal:
	llvm::PrettyStackTraceProgram *base;
	PrettyStackTraceProgram(llvm::PrettyStackTraceProgram *base);

public:
	!PrettyStackTraceProgram();
	virtual ~PrettyStackTraceProgram();
	// PrettyStackTraceProgram(int argc, const char  *const*argv);
	//   : ArgC(argc), ArgV(argv);
	// virtual void print(raw_ostream &OS) const LLVM_OVERRIDE;
};

}
