#pragma once
#using <mscorlib.dll>
#include "llvm/IR/Metadata.h"
#include "Value.h"

namespace LLVM
{

ref class LLVMContext;
ref class Value;
ref class Module;
ref class MDNode;
ref class raw_ostream;
ref class AssemblyAnnotationWriter;

public ref class MDString
	: public Value
{
internal:
	llvm::MDString *base;

protected:
	MDString(llvm::MDString *base);

internal:
	static inline MDString ^_wrap(llvm::MDString *base);

public:
	!MDString();
	virtual ~MDString();
	static MDString ^get(LLVMContext ^Context, System::String ^Str);
	System::String ^getString();
	unsigned getLength();
	// typedef StringRef::iterator iterator;
	// iterator begin();
	// iterator end();
	static bool classof(Value ^V);
};


public ref class MDNode
	: public Value
{
internal:
	llvm::MDNode *base;

protected:
	MDNode(llvm::MDNode *base);

internal:
	static inline MDNode ^_wrap(llvm::MDNode *base);

public:
	!MDNode();
	virtual ~MDNode();
	static MDNode ^get(LLVMContext ^Context, array<Value ^> ^Vals);
	static MDNode ^getWhenValsUnresolved(LLVMContext ^Context, array<Value ^> ^Vals, bool isFunctionLocal);
	static MDNode ^getIfExists(LLVMContext ^Context, array<Value ^> ^Vals);
	static MDNode ^getTemporary(LLVMContext ^Context, array<Value ^> ^Vals);
	static void deleteTemporary(MDNode ^N);
	void replaceOperandWith(unsigned i, Value ^NewVal);
	Value ^getOperand(unsigned i);
	unsigned getNumOperands();
	bool isFunctionLocal();
	// const Function *getFunction();
	// void Profile(FoldingSetNodeID &ID);
	static bool classof(Value ^V);
	static MDNode ^getMostGenericTBAA(MDNode ^A, MDNode ^B);
	static MDNode ^getMostGenericFPMath(MDNode ^A, MDNode ^B);
	static MDNode ^getMostGenericRange(MDNode ^A, MDNode ^B);
};


public ref class NamedMDNode
{
internal:
	llvm::NamedMDNode *base;

protected:
	NamedMDNode(llvm::NamedMDNode *base);

internal:
	static inline NamedMDNode ^_wrap(llvm::NamedMDNode *base);

public:
	!NamedMDNode();
	virtual ~NamedMDNode();
	void eraseFromParent();
	void dropAllReferences();
	inline Module ^getParent();
	// inline const Module *getParent();
	MDNode ^getOperand(unsigned i);
	unsigned getNumOperands();
	void addOperand(MDNode ^M);
	System::String ^getName();
	void print(raw_ostream ^ROS);
	void print(raw_ostream ^ROS, AssemblyAnnotationWriter ^AAW);
	void dump();
};

}
