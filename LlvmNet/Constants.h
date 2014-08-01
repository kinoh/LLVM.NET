#pragma once
#using <mscorlib.dll>
#include "llvm/IR/Constants.h"
#include "Constant.h"

namespace LLVM
{

ref class LLVMContext;
ref class Type;
ref class Constant;
ref class IntegerType;
ref class Value;
ref class ArrayType;
ref class Use;
ref class StructType;
ref class VectorType;
ref class PointerType;
ref class SequentialType;
ref class Function;
ref class BasicBlock;
ref class Instruction;

public ref class ConstantInt
	: public Constant
{
internal:
	llvm::ConstantInt *base;

protected:
	ConstantInt(llvm::ConstantInt *base);

internal:
	static inline ConstantInt ^_wrap(llvm::ConstantInt *base);

public:
	!ConstantInt();
	virtual ~ConstantInt();
	static ConstantInt ^getTrue(LLVMContext ^Context);
	static ConstantInt ^getFalse(LLVMContext ^Context);
	static Constant ^getTrue(Type ^Ty);
	static Constant ^getFalse(Type ^Ty);
	static Constant ^get(Type ^Ty, uint64_t V);
	static Constant ^get(Type ^Ty, uint64_t V, bool isSigned);
	static ConstantInt ^get(IntegerType ^Ty, uint64_t V);
	static ConstantInt ^get(IntegerType ^Ty, uint64_t V, bool isSigned);
	static ConstantInt ^getSigned(IntegerType ^Ty, int64_t V);
	static Constant ^getSigned(Type ^Ty, int64_t V);
	// static ConstantInt *get(LLVMContext &Context, const APInt &V);
	static ConstantInt ^get(IntegerType ^Ty, System::String ^Str, uint8_t radix);
	// static Constant *get(Type *Ty, const APInt &V);
	// inline const APInt &getValue();
	unsigned getBitWidth();
	inline uint64_t getZExtValue();
	inline int64_t getSExtValue();
	bool equalsInt(uint64_t V);
	inline IntegerType ^getType();
	static bool isValueValidForType(Type ^Ty, uint64_t V);
	static bool isValueValidForType(Type ^Ty, int64_t V);
	bool isNegative();
	bool isZero();
	bool isOne();
	bool isMinusOne();
	bool isMaxValue(bool isSigned);
	bool isMinValue(bool isSigned);
	bool uge(uint64_t Num);
	// uint64_t getLimitedValue(uint64_t Limit = ~0ULL);
	static bool classof(Value ^V);
};


public ref class ConstantFP
	: public Constant
{
internal:
	llvm::ConstantFP *base;

protected:
	ConstantFP(llvm::ConstantFP *base);

internal:
	static inline ConstantFP ^_wrap(llvm::ConstantFP *base);

public:
	!ConstantFP();
	virtual ~ConstantFP();
	static Constant ^getZeroValueForNegation(Type ^Ty);
	static Constant ^get(Type ^Ty, double V);
	static Constant ^get(Type ^Ty, System::String ^Str);
	// static ConstantFP *get(LLVMContext &Context, const APFloat &V);
	static ConstantFP ^getNegativeZero(Type ^Ty);
	static ConstantFP ^getInfinity(Type ^Ty);
	static ConstantFP ^getInfinity(Type ^Ty, bool Negative);
	// static bool isValueValidForType(Type *Ty, const APFloat &V);
	// inline const APFloat &getValueAPF();
	bool isZero();
	bool isNegative();
	bool isNaN();
	// bool isExactlyValue(const APFloat &V);
	bool isExactlyValue(double V);
	static bool classof(Value ^V);
};


public ref class ConstantAggregateZero
	: public Constant
{
internal:
	llvm::ConstantAggregateZero *base;

protected:
	ConstantAggregateZero(llvm::ConstantAggregateZero *base);

internal:
	static inline ConstantAggregateZero ^_wrap(llvm::ConstantAggregateZero *base);

public:
	!ConstantAggregateZero();
	virtual ~ConstantAggregateZero();
	static ConstantAggregateZero ^get(Type ^Ty);
	virtual void destroyConstant() override;
	Constant ^getSequentialElement();
	Constant ^getStructElement(unsigned Elt);
	Constant ^getElementValue(Constant ^C);
	Constant ^getElementValue(unsigned Idx);
	static bool classof(Value ^V);
};


public ref class ConstantArray
	: public Constant
{
internal:
	llvm::ConstantArray *base;

protected:
	ConstantArray(llvm::ConstantArray *base);

internal:
	static inline ConstantArray ^_wrap(llvm::ConstantArray *base);

public:
	!ConstantArray();
	virtual ~ConstantArray();
	static Constant ^get(ArrayType ^T, array<Constant ^> ^V);
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Constant);
	inline ArrayType ^getType();
	virtual void destroyConstant() override;
	virtual void replaceUsesOfWithOnConstant(Value ^From, Value ^To, Use ^U) override;
	static bool classof(Value ^V);
};


public ref class ConstantStruct
	: public Constant
{
internal:
	llvm::ConstantStruct *base;

protected:
	ConstantStruct(llvm::ConstantStruct *base);

internal:
	static inline ConstantStruct ^_wrap(llvm::ConstantStruct *base);

public:
	!ConstantStruct();
	virtual ~ConstantStruct();
	static Constant ^get(StructType ^T, array<Constant ^> ^V);
	// static Constant *get(StructType *T, ...) END_WITH_NULL;
	static Constant ^getAnon(array<Constant ^> ^V);
	static Constant ^getAnon(array<Constant ^> ^V, bool Packed);
	static Constant ^getAnon(LLVMContext ^Ctx, array<Constant ^> ^V);
	static Constant ^getAnon(LLVMContext ^Ctx, array<Constant ^> ^V, bool Packed);
	static StructType ^getTypeForElements(array<Constant ^> ^V);
	static StructType ^getTypeForElements(array<Constant ^> ^V, bool Packed);
	static StructType ^getTypeForElements(LLVMContext ^Ctx, array<Constant ^> ^V);
	static StructType ^getTypeForElements(LLVMContext ^Ctx, array<Constant ^> ^V, bool Packed);
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Constant);
	inline StructType ^getType();
	virtual void destroyConstant() override;
	virtual void replaceUsesOfWithOnConstant(Value ^From, Value ^To, Use ^U) override;
	static bool classof(Value ^V);
};


public ref class ConstantVector
	: public Constant
{
internal:
	llvm::ConstantVector *base;

protected:
	ConstantVector(llvm::ConstantVector *base);

internal:
	static inline ConstantVector ^_wrap(llvm::ConstantVector *base);

public:
	!ConstantVector();
	virtual ~ConstantVector();
	static Constant ^get(array<Constant ^> ^V);
	static Constant ^getSplat(unsigned NumElts, Constant ^Elt);
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Constant);
	inline VectorType ^getType();
	Constant ^getSplatValue();
	virtual void destroyConstant() override;
	virtual void replaceUsesOfWithOnConstant(Value ^From, Value ^To, Use ^U) override;
	static bool classof(Value ^V);
};


public ref class ConstantPointerNull
	: public Constant
{
internal:
	llvm::ConstantPointerNull *base;

protected:
	ConstantPointerNull(llvm::ConstantPointerNull *base);

internal:
	static inline ConstantPointerNull ^_wrap(llvm::ConstantPointerNull *base);

public:
	!ConstantPointerNull();
	virtual ~ConstantPointerNull();
	static ConstantPointerNull ^get(PointerType ^T);
	virtual void destroyConstant() override;
	inline PointerType ^getType();
	static bool classof(Value ^V);
};


public ref class ConstantDataSequential
	: public Constant
{
internal:
	llvm::ConstantDataSequential *base;

protected:
	ConstantDataSequential(llvm::ConstantDataSequential *base);

internal:
	static inline ConstantDataSequential ^_wrap(llvm::ConstantDataSequential *base);

public:
	!ConstantDataSequential();
	virtual ~ConstantDataSequential();
	static bool isElementTypeCompatible(Type ^Ty);
	uint64_t getElementAsInteger(unsigned i);
	// APFloat getElementAsAPFloat(unsigned i);
	float getElementAsFloat(unsigned i);
	double getElementAsDouble(unsigned i);
	Constant ^getElementAsConstant(unsigned i);
	inline SequentialType ^getType();
	Type ^getElementType();
	unsigned getNumElements();
	uint64_t getElementByteSize();
	bool isString();
	bool isCString();
	System::String ^getAsString();
	System::String ^getAsCString();
	System::String ^getRawDataValues();
	virtual void destroyConstant() override;
	static bool classof(Value ^V);
};


public ref class ConstantDataArray
	: public ConstantDataSequential
{
internal:
	llvm::ConstantDataArray *base;

protected:
	ConstantDataArray(llvm::ConstantDataArray *base);

internal:
	static inline ConstantDataArray ^_wrap(llvm::ConstantDataArray *base);

public:
	!ConstantDataArray();
	virtual ~ConstantDataArray();
	static Constant ^get(LLVMContext ^Context, array<uint8_t> ^Elts);
	static Constant ^get(LLVMContext ^Context, array<uint16_t> ^Elts);
	static Constant ^get(LLVMContext ^Context, array<uint32_t> ^Elts);
	static Constant ^get(LLVMContext ^Context, array<uint64_t> ^Elts);
	static Constant ^get(LLVMContext ^Context, array<float> ^Elts);
	static Constant ^get(LLVMContext ^Context, array<double> ^Elts);
	static Constant ^getString(LLVMContext ^Context, System::String ^Initializer);
	static Constant ^getString(LLVMContext ^Context, System::String ^Initializer, bool AddNull);
	inline ArrayType ^getType();
	static bool classof(Value ^V);
};


public ref class ConstantDataVector
	: public ConstantDataSequential
{
internal:
	llvm::ConstantDataVector *base;

protected:
	ConstantDataVector(llvm::ConstantDataVector *base);

internal:
	static inline ConstantDataVector ^_wrap(llvm::ConstantDataVector *base);

public:
	!ConstantDataVector();
	virtual ~ConstantDataVector();
	static Constant ^get(LLVMContext ^Context, array<uint8_t> ^Elts);
	static Constant ^get(LLVMContext ^Context, array<uint16_t> ^Elts);
	static Constant ^get(LLVMContext ^Context, array<uint32_t> ^Elts);
	static Constant ^get(LLVMContext ^Context, array<uint64_t> ^Elts);
	static Constant ^get(LLVMContext ^Context, array<float> ^Elts);
	static Constant ^get(LLVMContext ^Context, array<double> ^Elts);
	static Constant ^getSplat(unsigned NumElts, Constant ^Elt);
	Constant ^getSplatValue();
	inline VectorType ^getType();
	static bool classof(Value ^V);
};


public ref class BlockAddress
	: public Constant
{
internal:
	llvm::BlockAddress *base;

protected:
	BlockAddress(llvm::BlockAddress *base);

internal:
	static inline BlockAddress ^_wrap(llvm::BlockAddress *base);

public:
	!BlockAddress();
	virtual ~BlockAddress();
	static BlockAddress ^get(Function ^F, BasicBlock ^BB);
	static BlockAddress ^get(BasicBlock ^BB);
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Value);
	Function ^getFunction();
	BasicBlock ^getBasicBlock();
	virtual void destroyConstant() override;
	virtual void replaceUsesOfWithOnConstant(Value ^From, Value ^To, Use ^U) override;
	static inline bool classof(Value ^V);
};


public ref class ConstantExpr
	: public Constant
{
internal:
	llvm::ConstantExpr *base;

protected:
	ConstantExpr(llvm::ConstantExpr *base);

internal:
	static inline ConstantExpr ^_wrap(llvm::ConstantExpr *base);

public:
	!ConstantExpr();
	virtual ~ConstantExpr();
	static Constant ^getAlignOf(Type ^Ty);
	static Constant ^getSizeOf(Type ^Ty);
	static Constant ^getOffsetOf(StructType ^STy, unsigned FieldNo);
	static Constant ^getOffsetOf(Type ^Ty, Constant ^FieldNo);
	static Constant ^getNeg(Constant ^C);
	static Constant ^getNeg(Constant ^C, bool HasNUW);
	static Constant ^getNeg(Constant ^C, bool HasNUW, bool HasNSW);
	static Constant ^getFNeg(Constant ^C);
	static Constant ^getNot(Constant ^C);
	static Constant ^getAdd(Constant ^C1, Constant ^C2);
	static Constant ^getAdd(Constant ^C1, Constant ^C2, bool HasNUW);
	static Constant ^getAdd(Constant ^C1, Constant ^C2, bool HasNUW, bool HasNSW);
	static Constant ^getFAdd(Constant ^C1, Constant ^C2);
	static Constant ^getSub(Constant ^C1, Constant ^C2);
	static Constant ^getSub(Constant ^C1, Constant ^C2, bool HasNUW);
	static Constant ^getSub(Constant ^C1, Constant ^C2, bool HasNUW, bool HasNSW);
	static Constant ^getFSub(Constant ^C1, Constant ^C2);
	static Constant ^getMul(Constant ^C1, Constant ^C2);
	static Constant ^getMul(Constant ^C1, Constant ^C2, bool HasNUW);
	static Constant ^getMul(Constant ^C1, Constant ^C2, bool HasNUW, bool HasNSW);
	static Constant ^getFMul(Constant ^C1, Constant ^C2);
	static Constant ^getUDiv(Constant ^C1, Constant ^C2);
	static Constant ^getUDiv(Constant ^C1, Constant ^C2, bool isExact);
	static Constant ^getSDiv(Constant ^C1, Constant ^C2);
	static Constant ^getSDiv(Constant ^C1, Constant ^C2, bool isExact);
	static Constant ^getFDiv(Constant ^C1, Constant ^C2);
	static Constant ^getURem(Constant ^C1, Constant ^C2);
	static Constant ^getSRem(Constant ^C1, Constant ^C2);
	static Constant ^getFRem(Constant ^C1, Constant ^C2);
	static Constant ^getAnd(Constant ^C1, Constant ^C2);
	static Constant ^getOr(Constant ^C1, Constant ^C2);
	static Constant ^getXor(Constant ^C1, Constant ^C2);
	static Constant ^getShl(Constant ^C1, Constant ^C2);
	static Constant ^getShl(Constant ^C1, Constant ^C2, bool HasNUW);
	static Constant ^getShl(Constant ^C1, Constant ^C2, bool HasNUW, bool HasNSW);
	static Constant ^getLShr(Constant ^C1, Constant ^C2);
	static Constant ^getLShr(Constant ^C1, Constant ^C2, bool isExact);
	static Constant ^getAShr(Constant ^C1, Constant ^C2);
	static Constant ^getAShr(Constant ^C1, Constant ^C2, bool isExact);
	static Constant ^getTrunc(Constant ^C, Type ^Ty);
	static Constant ^getSExt(Constant ^C, Type ^Ty);
	static Constant ^getZExt(Constant ^C, Type ^Ty);
	static Constant ^getFPTrunc(Constant ^C, Type ^Ty);
	static Constant ^getFPExtend(Constant ^C, Type ^Ty);
	static Constant ^getUIToFP(Constant ^C, Type ^Ty);
	static Constant ^getSIToFP(Constant ^C, Type ^Ty);
	static Constant ^getFPToUI(Constant ^C, Type ^Ty);
	static Constant ^getFPToSI(Constant ^C, Type ^Ty);
	static Constant ^getPtrToInt(Constant ^C, Type ^Ty);
	static Constant ^getIntToPtr(Constant ^C, Type ^Ty);
	static Constant ^getBitCast(Constant ^C, Type ^Ty);
	static Constant ^getNSWNeg(Constant ^C);
	static Constant ^getNUWNeg(Constant ^C);
	static Constant ^getNSWAdd(Constant ^C1, Constant ^C2);
	static Constant ^getNUWAdd(Constant ^C1, Constant ^C2);
	static Constant ^getNSWSub(Constant ^C1, Constant ^C2);
	static Constant ^getNUWSub(Constant ^C1, Constant ^C2);
	static Constant ^getNSWMul(Constant ^C1, Constant ^C2);
	static Constant ^getNUWMul(Constant ^C1, Constant ^C2);
	static Constant ^getNSWShl(Constant ^C1, Constant ^C2);
	static Constant ^getNUWShl(Constant ^C1, Constant ^C2);
	static Constant ^getExactSDiv(Constant ^C1, Constant ^C2);
	static Constant ^getExactUDiv(Constant ^C1, Constant ^C2);
	static Constant ^getExactAShr(Constant ^C1, Constant ^C2);
	static Constant ^getExactLShr(Constant ^C1, Constant ^C2);
	static Constant ^getBinOpIdentity(unsigned Opcode, Type ^Ty);
	static Constant ^getBinOpAbsorber(unsigned Opcode, Type ^Ty);
	// DECLARE_TRANSPARENT_OPERAND_ACCESSORS(Constant);
	static Constant ^getCast(unsigned ops, Constant ^C, Type ^Ty);
	static Constant ^getZExtOrBitCast(Constant ^C, Type ^Ty);
	static Constant ^getSExtOrBitCast(Constant ^C, Type ^Ty);
	static Constant ^getTruncOrBitCast(Constant ^C, Type ^Ty);
	static Constant ^getPointerCast(Constant ^C, Type ^Ty);
	static Constant ^getIntegerCast(Constant ^C, Type ^Ty, bool isSigned);
	static Constant ^getFPCast(Constant ^C, Type ^Ty);
	bool isCast();
	bool isCompare();
	bool hasIndices();
	bool isGEPWithNoNotionalOverIndexing();
	static Constant ^getSelect(Constant ^C, Constant ^V1, Constant ^V2);
	static Constant ^get(unsigned Opcode, Constant ^C1, Constant ^C2);
	static Constant ^get(unsigned Opcode, Constant ^C1, Constant ^C2, unsigned Flags);
	// static Constant *getCompare(unsigned short pred, Constant *C1, Constant *C2);
	// static Constant *getICmp(unsigned short pred, Constant *LHS, Constant *RHS);
	// static Constant *getFCmp(unsigned short pred, Constant *LHS, Constant *RHS);
	static Constant ^getGetElementPtr(Constant ^C, array<Constant ^> ^IdxList);
	static Constant ^getGetElementPtr(Constant ^C, array<Constant ^> ^IdxList, bool InBounds);
	static Constant ^getGetElementPtr(Constant ^C, Constant ^Idx);
	static Constant ^getGetElementPtr(Constant ^C, Constant ^Idx, bool InBounds);
	static Constant ^getGetElementPtr(Constant ^C, array<Value ^> ^IdxList);
	static Constant ^getGetElementPtr(Constant ^C, array<Value ^> ^IdxList, bool InBounds);
	static Constant ^getInBoundsGetElementPtr(Constant ^C, array<Constant ^> ^IdxList);
	static Constant ^getInBoundsGetElementPtr(Constant ^C, Constant ^Idx);
	static Constant ^getInBoundsGetElementPtr(Constant ^C, array<Value ^> ^IdxList);
	static Constant ^getExtractElement(Constant ^Vec, Constant ^Idx);
	static Constant ^getInsertElement(Constant ^Vec, Constant ^Elt, Constant ^Idx);
	static Constant ^getShuffleVector(Constant ^V1, Constant ^V2, Constant ^Mask);
	static Constant ^getExtractValue(Constant ^Agg, array<unsigned> ^Idxs);
	static Constant ^getInsertValue(Constant ^Agg, Constant ^Val, array<unsigned> ^Idxs);
	unsigned getOpcode();
	unsigned getPredicate();
	array<unsigned> ^getIndices();
	System::String ^getOpcodeName();
	Constant ^getWithOperandReplaced(unsigned OpNo, Constant ^Op);
	Constant ^getWithOperands(array<Constant ^> ^Ops);
	Constant ^getWithOperands(array<Constant ^> ^Ops, Type ^Ty);
	Instruction ^getAsInstruction();
	virtual void destroyConstant() override;
	virtual void replaceUsesOfWithOnConstant(Value ^From, Value ^To, Use ^U) override;
	static inline bool classof(Value ^V);
};


public ref class UndefValue
	: public Constant
{
internal:
	llvm::UndefValue *base;

protected:
	UndefValue(llvm::UndefValue *base);

internal:
	static inline UndefValue ^_wrap(llvm::UndefValue *base);

public:
	!UndefValue();
	virtual ~UndefValue();
	static UndefValue ^get(Type ^T);
	UndefValue ^getSequentialElement();
	UndefValue ^getStructElement(unsigned Elt);
	UndefValue ^getElementValue(Constant ^C);
	UndefValue ^getElementValue(unsigned Idx);
	virtual void destroyConstant() override;
	static bool classof(Value ^V);
};

}
