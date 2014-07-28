#pragma once
#include "llvm/IR/Operator.h"
#include "User.h"

namespace LLVM
{

ref class Value;
ref class Instruction;
ref class ConstantExpr;
ref class FastMathFlags;
ref class Type;

public ref class Operator
	: public User
{
internal:
	llvm::Operator *base;
	Operator(llvm::Operator *base);

public:
	!Operator();
	virtual ~Operator();
	unsigned getOpcode();
	static unsigned getOpcode(Value ^V);
	// static inline bool classof(const Instruction *);
	// static inline bool classof(const ConstantExpr *);
	static inline bool classof(Value ^V);
};


public ref class OverflowingBinaryOperator
	: public Operator
{
internal:
	llvm::OverflowingBinaryOperator *base;
	OverflowingBinaryOperator(llvm::OverflowingBinaryOperator *base);

public:
	!OverflowingBinaryOperator();
	virtual ~OverflowingBinaryOperator();
	// enum;
	bool hasNoUnsignedWrap();
	bool hasNoSignedWrap();
	static inline bool classof(Instruction ^I);
	static inline bool classof(ConstantExpr ^CE);
	static inline bool classof(Value ^V);
};


public ref class PossiblyExactOperator
	: public Operator
{
internal:
	llvm::PossiblyExactOperator *base;
	PossiblyExactOperator(llvm::PossiblyExactOperator *base);

public:
	!PossiblyExactOperator();
	virtual ~PossiblyExactOperator();
	// enum;
	bool isExact();
	static bool isPossiblyExactOpcode(unsigned OpC);
	static inline bool classof(ConstantExpr ^CE);
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class FastMathFlags
{
private:
	bool constructed;
internal:
	llvm::FastMathFlags *base;
	FastMathFlags(llvm::FastMathFlags *base);

public:
	!FastMathFlags();
	virtual ~FastMathFlags();
	// enum;
	FastMathFlags();
	bool any();
	void clear();
	bool noNaNs();
	bool noInfs();
	bool noSignedZeros();
	bool allowReciprocal();
	bool unsafeAlgebra();
	void setNoNaNs();
	void setNoInfs();
	void setNoSignedZeros();
	void setAllowReciprocal();
	void setUnsafeAlgebra();
};


public ref class FPMathOperator
	: public Operator
{
internal:
	llvm::FPMathOperator *base;
	FPMathOperator(llvm::FPMathOperator *base);

public:
	!FPMathOperator();
	virtual ~FPMathOperator();
	bool hasUnsafeAlgebra();
	bool hasNoNaNs();
	bool hasNoInfs();
	bool hasNoSignedZeros();
	bool hasAllowReciprocal();
	FastMathFlags ^getFastMathFlags();
	float getFPAccuracy();
	static inline bool classof(Instruction ^I);
	static inline bool classof(Value ^V);
};


public ref class AddOperator
{
internal:
	llvm::AddOperator *base;
	AddOperator(llvm::AddOperator *base);

public:
	!AddOperator();
	virtual ~AddOperator();
};


public ref class SubOperator
{
internal:
	llvm::SubOperator *base;
	SubOperator(llvm::SubOperator *base);

public:
	!SubOperator();
	virtual ~SubOperator();
};


public ref class MulOperator
{
internal:
	llvm::MulOperator *base;
	MulOperator(llvm::MulOperator *base);

public:
	!MulOperator();
	virtual ~MulOperator();
};


public ref class ShlOperator
{
internal:
	llvm::ShlOperator *base;
	ShlOperator(llvm::ShlOperator *base);

public:
	!ShlOperator();
	virtual ~ShlOperator();
};


public ref class SDivOperator
{
internal:
	llvm::SDivOperator *base;
	SDivOperator(llvm::SDivOperator *base);

public:
	!SDivOperator();
	virtual ~SDivOperator();
};


public ref class UDivOperator
{
internal:
	llvm::UDivOperator *base;
	UDivOperator(llvm::UDivOperator *base);

public:
	!UDivOperator();
	virtual ~UDivOperator();
};


public ref class AShrOperator
{
internal:
	llvm::AShrOperator *base;
	AShrOperator(llvm::AShrOperator *base);

public:
	!AShrOperator();
	virtual ~AShrOperator();
};


public ref class LShrOperator
{
internal:
	llvm::LShrOperator *base;
	LShrOperator(llvm::LShrOperator *base);

public:
	!LShrOperator();
	virtual ~LShrOperator();
};


public ref class GEPOperator
{
internal:
	llvm::GEPOperator *base;
	GEPOperator(llvm::GEPOperator *base);

public:
	!GEPOperator();
	virtual ~GEPOperator();
	bool isInBounds();
	// inline op_iterator       idx_begin();
	// inline const_op_iterator idx_begin();
	// inline op_iterator       idx_end();
	// inline const_op_iterator idx_end()  ;
	Value ^getPointerOperand();
	// const Value *getPointerOperand();
	static unsigned getPointerOperandIndex();
	Type ^getPointerOperandType();
	unsigned getPointerAddressSpace();
	unsigned getNumIndices();
	bool hasIndices();
	bool hasAllZeroIndices();
	bool hasAllConstantIndices();
	// bool accumulateConstantOffset(const DataLayout &DL, APInt &Offset);
};

}
