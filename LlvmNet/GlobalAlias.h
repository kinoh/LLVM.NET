#pragma once
#using <mscorlib.dll>
#include "llvm/IR/GlobalAlias.h"
#include "GlobalValue.h"

namespace LLVM
{

ref class Type;
ref class Constant;
ref class Module;
ref class Value;

public ref class GlobalAlias
	: public GlobalValue
{
private:
	bool constructed;	static llvm::GlobalAlias *_construct(Type ^Ty, LinkageTypes Linkage, System::String ^Name);
	static llvm::GlobalAlias *_construct(Type ^Ty, LinkageTypes Linkage, System::String ^Name, Constant ^Aliasee);
	static llvm::GlobalAlias *_construct(Type ^Ty, LinkageTypes Linkage, System::String ^Name, Constant ^Aliasee, Module ^Parent);

internal:
	llvm::GlobalAlias *base;
	GlobalAlias(llvm::GlobalAlias *base);

public:
	!GlobalAlias();
	virtual ~GlobalAlias();
	// void *operator new(size_t s);
	GlobalAlias(Type ^Ty, LinkageTypes Linkage);
	GlobalAlias(Type ^Ty, LinkageTypes Linkage, System::String ^Name);
	GlobalAlias(Type ^Ty, LinkageTypes Linkage, System::String ^Name, Constant ^Aliasee);
	GlobalAlias(Type ^Ty, LinkageTypes Linkage, System::String ^Name, Constant ^Aliasee, Module ^Parent);
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Constant);
	virtual void removeFromParent() override;
	virtual void eraseFromParent() override;
	void setAliasee(Constant ^GV);
	// const Constant *getAliasee();
	Constant ^getAliasee();
	// const GlobalValue *getAliasedGlobal();
	// const GlobalValue *resolveAliasedGlobal(bool stopOnWeak = true);
	static inline bool classof(Value ^V);
};

}
