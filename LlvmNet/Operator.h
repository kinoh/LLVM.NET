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

protected:
	Operator(llvm::Operator *base);

internal:
	static inline Operator ^_wrap(llvm::Operator *base);

public:
	!Operator();
	virtual ~Operator();
	unsigned getOpcode();
	static unsigned getOpcode(Value ^V);
	static inline bool classof(Instruction ^instruction);
	static inline bool classof(ConstantExpr ^expr);
	static inline bool classof(Value ^V);
};


public ref class OverflowingBinaryOperator
	: public Operator
{
internal:
	llvm::OverflowingBinaryOperator *base;

protected:
	OverflowingBinaryOperator(llvm::OverflowingBinaryOperator *base);

internal:
	static inline OverflowingBinaryOperator ^_wrap(llvm::OverflowingBinaryOperator *base);

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

protected:
	PossiblyExactOperator(llvm::PossiblyExactOperator *base);

internal:
	static inline PossiblyExactOperator ^_wrap(llvm::PossiblyExactOperator *base);

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

protected:
	FastMathFlags(llvm::FastMathFlags *base);

internal:
	static inline FastMathFlags ^_wrap(llvm::FastMathFlags *base);

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

protected:
	FPMathOperator(llvm::FPMathOperator *base);

internal:
	static inline FPMathOperator ^_wrap(llvm::FPMathOperator *base);

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

protected:
	AddOperator(llvm::AddOperator *base);

internal:
	static inline AddOperator ^_wrap(llvm::AddOperator *base);

public:
	!AddOperator();
	virtual ~AddOperator();
};


public ref class SubOperator
{
internal:
	llvm::SubOperator *base;

protected:
	SubOperator(llvm::SubOperator *base);

internal:
	static inline SubOperator ^_wrap(llvm::SubOperator *base);

public:
	!SubOperator();
	virtual ~SubOperator();
};


public ref class MulOperator
{
internal:
	llvm::MulOperator *base;

protected:
	MulOperator(llvm::MulOperator *base);

internal:
	static inline MulOperator ^_wrap(llvm::MulOperator *base);

public:
	!MulOperator();
	virtual ~MulOperator();
};


public ref class ShlOperator
{
internal:
	llvm::ShlOperator *base;

protected:
	ShlOperator(llvm::ShlOperator *base);

internal:
	static inline ShlOperator ^_wrap(llvm::ShlOperator *base);

public:
	!ShlOperator();
	virtual ~ShlOperator();
};


public ref class SDivOperator
{
internal:
	llvm::SDivOperator *base;

protected:
	SDivOperator(llvm::SDivOperator *base);

internal:
	static inline SDivOperator ^_wrap(llvm::SDivOperator *base);

public:
	!SDivOperator();
	virtual ~SDivOperator();
};


public ref class UDivOperator
{
internal:
	llvm::UDivOperator *base;

protected:
	UDivOperator(llvm::UDivOperator *base);

internal:
	static inline UDivOperator ^_wrap(llvm::UDivOperator *base);

public:
	!UDivOperator();
	virtual ~UDivOperator();
};


public ref class AShrOperator
{
internal:
	llvm::AShrOperator *base;

protected:
	AShrOperator(llvm::AShrOperator *base);

internal:
	static inline AShrOperator ^_wrap(llvm::AShrOperator *base);

public:
	!AShrOperator();
	virtual ~AShrOperator();
};


public ref class LShrOperator
{
internal:
	llvm::LShrOperator *base;

protected:
	LShrOperator(llvm::LShrOperator *base);

internal:
	static inline LShrOperator ^_wrap(llvm::LShrOperator *base);

public:
	!LShrOperator();
	virtual ~LShrOperator();
};


public ref class GEPOperator
{
internal:
	llvm::GEPOperator *base;

protected:
	GEPOperator(llvm::GEPOperator *base);

internal:
	static inline GEPOperator ^_wrap(llvm::GEPOperator *base);

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
