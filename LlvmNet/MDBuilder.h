#pragma once
#using <mscorlib.dll>
#include "llvm/IR/MDBuilder.h"

namespace LLVM
{

ref class LLVMContext;
ref class MDString;
ref class MDNode;

public ref class MDBuilder
{
private:
	bool constructed;

internal:
	llvm::MDBuilder *base;

protected:
	MDBuilder(llvm::MDBuilder *base);

internal:
	static inline MDBuilder ^_wrap(llvm::MDBuilder *base);

public:
	!MDBuilder();
	virtual ~MDBuilder();
	MDBuilder(LLVMContext ^context);
	MDString ^createString(System::String ^Str);
	MDNode ^createFPMath(float Accuracy);
	MDNode ^createBranchWeights(uint32_t TrueWeight, uint32_t FalseWeight);
	MDNode ^createBranchWeights(array<uint32_t> ^Weights);
	// MDNode *createRange(const APInt &Lo, const APInt &Hi);
	MDNode ^createAnonymousTBAARoot();
	MDNode ^createTBAARoot(System::String ^Name);
	MDNode ^createTBAANode(System::String ^Name, MDNode ^Parent);
	MDNode ^createTBAANode(System::String ^Name, MDNode ^Parent, bool isConstant);
	// struct TBAAStructField;
	// MDNode *createTBAAStructNode(ArrayRef<TBAAStructField> Fields);
	// MDNode *createTBAAStructTypeNode(StringRef Name, ArrayRef<std::pair<MDNode *, uint64_t> > Fields);
	MDNode ^createTBAAScalarTypeNode(System::String ^Name, MDNode ^Parent);
	MDNode ^createTBAAScalarTypeNode(System::String ^Name, MDNode ^Parent, uint64_t Offset);
	MDNode ^createTBAAStructTagNode(MDNode ^BaseType, MDNode ^AccessType, uint64_t Offset);
};

}
