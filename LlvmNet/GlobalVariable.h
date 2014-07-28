#pragma once
#using <mscorlib.dll>
#include "llvm/IR/GlobalVariable.h"
#include "GlobalValue.h"

namespace LLVM
{

ref class Type;
ref class Constant;
ref class Module;
ref class GlobalValue;
ref class Value;
ref class Use;

public ref class GlobalVariable
	: public GlobalValue
{
public:
	enum class ThreadLocalMode
	{
		NotThreadLocal = 0,
		GeneralDynamicTLSModel,
		LocalDynamicTLSModel,
		InitialExecTLSModel,
		LocalExecTLSModel
	};

private:
	bool constructed;	static llvm::GlobalVariable *_construct(Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name);
	static llvm::GlobalVariable *_construct(Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, ThreadLocalMode threadLocalMode);
	static llvm::GlobalVariable *_construct(Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, ThreadLocalMode threadLocalMode, unsigned AddressSpace);
	static llvm::GlobalVariable *_construct(Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, ThreadLocalMode threadLocalMode, unsigned AddressSpace, bool isExternallyInitialized);
	static llvm::GlobalVariable *_construct(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name);
	static llvm::GlobalVariable *_construct(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, GlobalVariable ^InsertBefore);
	static llvm::GlobalVariable *_construct(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, GlobalVariable ^InsertBefore, ThreadLocalMode threadLocalMode);
	static llvm::GlobalVariable *_construct(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, GlobalVariable ^InsertBefore, ThreadLocalMode threadLocalMode, unsigned AddressSpace);
	static llvm::GlobalVariable *_construct(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, GlobalVariable ^InsertBefore, ThreadLocalMode threadLocalMode, unsigned AddressSpace, bool isExternallyInitialized);

internal:
	llvm::GlobalVariable *base;
	GlobalVariable(llvm::GlobalVariable *base);

public:
	!GlobalVariable();
	virtual ~GlobalVariable();
	// void *operator new(size_t s);
	GlobalVariable(Type ^Ty, bool isConstant, LinkageTypes Linkage);
	GlobalVariable(Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer);
	GlobalVariable(Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name);
	GlobalVariable(Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, ThreadLocalMode threadLocalMode);
	GlobalVariable(Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, ThreadLocalMode threadLocalMode, unsigned AddressSpace);
	GlobalVariable(Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, ThreadLocalMode threadLocalMode, unsigned AddressSpace, bool isExternallyInitialized);
	GlobalVariable(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer);
	GlobalVariable(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name);
	GlobalVariable(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, GlobalVariable ^InsertBefore);
	GlobalVariable(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, GlobalVariable ^InsertBefore, ThreadLocalMode threadLocalMode);
	GlobalVariable(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, GlobalVariable ^InsertBefore, ThreadLocalMode threadLocalMode, unsigned AddressSpace);
	GlobalVariable(Module ^M, Type ^Ty, bool isConstant, LinkageTypes Linkage, Constant ^Initializer, System::String ^Name, GlobalVariable ^InsertBefore, ThreadLocalMode threadLocalMode, unsigned AddressSpace, bool isExternallyInitialized);
	// ~GlobalVariable();
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	inline bool hasInitializer();
	inline bool hasDefinitiveInitializer();
	inline bool hasUniqueInitializer();
	// inline const Constant *getInitializer();
	inline Constant ^getInitializer();
	void setInitializer(Constant ^InitVal);
	bool isConstant();
	void setConstant(bool Val);
	bool isThreadLocal();
	void setThreadLocal(bool Val);
	void setThreadLocalMode(ThreadLocalMode Val);
	GlobalVariable::ThreadLocalMode getThreadLocalMode();
	bool isExternallyInitialized();
	void setExternallyInitialized(bool Val);
	virtual void copyAttributesFrom(GlobalValue ^Src) override;
	virtual void removeFromParent() override;
	virtual void eraseFromParent() override;
	virtual void replaceUsesOfWithOnConstant(Value ^From, Value ^To, Use ^U);
	static inline bool classof(Value ^V);
};

}
