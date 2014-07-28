#pragma once
#using <mscorlib.dll>
#include "llvm/IR/Argument.h"
#include "Value.h"

namespace LLVM
{

ref class Type;
ref class Function;
ref class AttributeSet;
ref class Value;

public ref class Argument
	: public Value
{
private:
	bool constructed;	static llvm::Argument *_construct(Type ^Ty, System::String ^Name);
	static llvm::Argument *_construct(Type ^Ty, System::String ^Name, Function ^F);

internal:
	llvm::Argument *base;
	Argument(llvm::Argument *base);

public:
	!Argument();
	virtual ~Argument();
	Argument(Type ^Ty);
	Argument(Type ^Ty, System::String ^Name);
	Argument(Type ^Ty, System::String ^Name, Function ^F);
	// inline const Function *getParent();
	inline Function ^getParent();
	unsigned getArgNo();
	bool hasByValAttr();
	unsigned getParamAlignment();
	bool hasNestAttr();
	bool hasNoAliasAttr();
	bool hasNoCaptureAttr();
	bool hasStructRetAttr();
	bool hasReturnedAttr();
	void addAttr(AttributeSet ^AS);
	void removeAttr(AttributeSet ^AS);
	static inline bool classof(Value ^V);
};

}
