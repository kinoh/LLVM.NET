#pragma once
#using <mscorlib.dll>
#include "llvm/IR/Function.h"
#include "GlobalValue.h"
#include "CallingConv.h"
#include "Attributes.h"

namespace LLVM
{

ref class FunctionType;
ref class Module;
ref class Type;
ref class LLVMContext;
ref class AttributeSet;
ref class GlobalValue;
ref class Argument;
ref class BasicBlock;
ref class ValueSymbolTable;
ref class Value;

public ref class Function
	: public GlobalValue
{
internal:
	llvm::Function *base;
	Function(llvm::Function *base);

public:
	!Function();
	virtual ~Function();
	// typedef iplist<Argument> ArgumentListType;
	// typedef iplist<BasicBlock> BasicBlockListType;
	// typedef BasicBlockListType::iterator iterator;
	// typedef BasicBlockListType::const_iterator const_iterator;
	// typedef ArgumentListType::iterator arg_iterator;
	// typedef ArgumentListType::const_iterator const_arg_iterator;
	static Function ^Create(FunctionType ^Ty, LinkageTypes Linkage);
	static Function ^Create(FunctionType ^Ty, LinkageTypes Linkage, System::String ^N);
	static Function ^Create(FunctionType ^Ty, LinkageTypes Linkage, System::String ^N, Module ^M);
	Type ^getReturnType();
	FunctionType ^getFunctionType();
	LLVMContext ^getContext();
	bool isVarArg();
	// unsigned getIntrinsicID() const LLVM_READONLY;
	bool isIntrinsic();
	CallingConv::ID getCallingConv();
	void setCallingConv(CallingConv::ID CC);
	AttributeSet ^getAttributes();
	void setAttributes(AttributeSet ^attrs);
	void addFnAttr(Attribute::AttrKind N);
	void addFnAttr(System::String ^Kind);
	bool hasFnAttribute(Attribute::AttrKind Kind);
	bool hasFnAttribute(System::String ^Kind);
	bool hasGC();
	System::String ^getGC();
	void setGC(System::String ^Str);
	void clearGC();
	void addAttribute(unsigned i, Attribute::AttrKind attr);
	void addAttributes(unsigned i, AttributeSet ^attrs);
	void removeAttributes(unsigned i, AttributeSet ^attr);
	unsigned getParamAlignment(unsigned i);
	bool doesNotAccessMemory();
	void setDoesNotAccessMemory();
	bool onlyReadsMemory();
	void setOnlyReadsMemory();
	bool doesNotReturn();
	void setDoesNotReturn();
	bool doesNotThrow();
	void setDoesNotThrow();
	bool cannotDuplicate();
	void setCannotDuplicate();
	bool hasUWTable();
	void setHasUWTable();
	bool needsUnwindTableEntry();
	bool hasStructRetAttr();
	bool doesNotAlias(unsigned n);
	void setDoesNotAlias(unsigned n);
	bool doesNotCapture(unsigned n);
	void setDoesNotCapture(unsigned n);
	virtual void copyAttributesFrom(GlobalValue ^Src) override;
	void deleteBody();
	virtual void removeFromParent() override;
	virtual void eraseFromParent() override;
	// const ArgumentListType &getArgumentList();
	System::Collections::Generic::List<Argument ^> ^getArgumentList();
	// static iplist<Argument> Function::*getSublistAccess(Argument*);
	// const BasicBlockListType &getBasicBlockList();
	System::Collections::Generic::List<BasicBlock ^> ^getBasicBlockList();
	// static iplist<BasicBlock> Function::*getSublistAccess(BasicBlock*);
	// const BasicBlock       &getEntryBlock();
	BasicBlock ^getEntryBlock();
	inline ValueSymbolTable ^getValueSymbolTable();
	// inline const ValueSymbolTable &getValueSymbolTable();
	// iterator                begin();
	// const_iterator          begin();
	// iterator                end();
	// const_iterator          end();
	size_t size();
	bool empty();
	// const BasicBlock       &front();
	BasicBlock ^front();
	// const BasicBlock        &back();
	BasicBlock ^back();
	// arg_iterator arg_begin();
	// const_arg_iterator arg_begin();
	// arg_iterator arg_end();
	// const_arg_iterator arg_end();
	size_t arg_size();
	bool arg_empty();
	void viewCFG();
	void viewCFGOnly();
	static inline bool classof(Value ^V);
	void dropAllReferences();
	// bool hasAddressTaken(const User* *= 0);
	bool isDefTriviallyDead();
	bool callsFunctionThatReturnsTwice();
};

}
