#pragma once
#using <mscorlib.dll>
#include "llvm/Support/PrettyStackTrace.h"

namespace LLVM
{

public ref class PrettyStackTraceEntry
{
internal:
	llvm::PrettyStackTraceEntry *base;

protected:
	PrettyStackTraceEntry(llvm::PrettyStackTraceEntry *base);

internal:
	static inline PrettyStackTraceEntry ^_wrap(llvm::PrettyStackTraceEntry *base);

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
	bool constructed;
	static llvm::PrettyStackTraceString *_construct(System::String ^str);

internal:
	llvm::PrettyStackTraceString *base;

protected:
	PrettyStackTraceString(llvm::PrettyStackTraceString *base);

internal:
	static inline PrettyStackTraceString ^_wrap(llvm::PrettyStackTraceString *base);

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

protected:
	PrettyStackTraceProgram(llvm::PrettyStackTraceProgram *base);

internal:
	static inline PrettyStackTraceProgram ^_wrap(llvm::PrettyStackTraceProgram *base);

public:
	!PrettyStackTraceProgram();
	virtual ~PrettyStackTraceProgram();
	// PrettyStackTraceProgram(int argc, const char * const *argv);
	//   : ArgC(argc), ArgV(argv);
	// virtual void print(raw_ostream &OS) const LLVM_OVERRIDE;
};

}
