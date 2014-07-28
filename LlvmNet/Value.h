#pragma once
#using <mscorlib.dll>
#include "llvm/IR/Value.h"

namespace LLVM
{

ref class Value;
ref class raw_ostream;
ref class AssemblyAnnotationWriter;
ref class Type;
ref class LLVMContext;
ref class User;
ref class BasicBlock;
ref class Use;
typedef System::Collections::Generic::KeyValuePair<System::String ^, Value ^> ValueName;

public ref class Value
{
public:
	enum class ValueTy
	{
		ArgumentVal,
		BasicBlockVal,
		FunctionVal,
		GlobalAliasVal,
		GlobalVariableVal,
		UndefValueVal,
		BlockAddressVal,
		ConstantExprVal,
		ConstantAggregateZeroVal,
		ConstantDataArrayVal,
		ConstantDataVectorVal,
		ConstantIntVal,
		ConstantFPVal,
		ConstantArrayVal,
		ConstantStructVal,
		ConstantVectorVal,
		ConstantPointerNullVal,
		MDNodeVal,
		MDStringVal,
		InlineAsmVal,
		PseudoSourceValueVal,
		FixedStackPseudoSourceValueVal,
		InstructionVal,
		ConstantFirstVal = FunctionVal,
		ConstantLastVal	= ConstantPointerNullVal
	};

internal:
	llvm::Value *base;
	Value(llvm::Value *base);

public:
	!Value();
	virtual ~Value();
	// virtual ~Value();
	void dump();
	void print(raw_ostream ^O);
	void print(raw_ostream ^O, AssemblyAnnotationWriter ^AAW);
	Type ^getType();
	LLVMContext ^getContext();
	bool hasName();
	ValueName ^getValueName();
	void setValueName(ValueName ^VN);
	System::String ^getName();
	void setName(System::String ^Name);
	void takeName(Value ^V);
	void replaceAllUsesWith(Value ^V);
	// typedef value_use_iterator<User>       use_iterator;
	// typedef value_use_iterator<const User> const_use_iterator;
	bool use_empty();
	// use_iterator       use_begin();
	// const_use_iterator use_begin();
	// use_iterator       use_end();
	// const_use_iterator use_end()  ;
	User ^use_back();
	// const User        *use_back() ;
	bool hasOneUse();
	bool hasNUses(unsigned N);
	bool hasNUsesOrMore(unsigned N);
	bool isUsedInBasicBlock(BasicBlock ^BB);
	unsigned getNumUses();
	void addUse(Use ^U);
	unsigned getValueID();
	unsigned getRawSubclassOptionalData();
	void clearSubclassOptionalData();
	bool hasSameSubclassOptionalData(Value ^V);
	void intersectOptionalDataWith(Value ^V);
	bool hasValueHandle();
	Value ^stripPointerCasts();
	// const Value *stripPointerCasts();
	Value ^stripPointerCastsNoFollowAliases();
	// const Value *stripPointerCastsNoFollowAliases();
	Value ^stripInBoundsConstantOffsets();
	// const Value *stripInBoundsConstantOffsets();
	Value ^stripInBoundsOffsets();
	// const Value *stripInBoundsOffsets();
	bool isDereferenceablePointer();
	Value ^DoPHITranslation(BasicBlock ^CurBB, BasicBlock ^PredBB);
	// const Value *DoPHITranslation(const BasicBlock *CurBB, const BasicBlock *PredBB);
	// static const unsigned MaximumAlignment = 1u << 29;
	void mutateType(Type ^Ty);
};

}
