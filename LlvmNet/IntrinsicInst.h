#pragma once
#include "llvm/IR/IntrinsicInst.h"
#include "Instructions.h"
#include "Intrinsics.h"

namespace LLVM
{

ref class CallInst;
ref class Value;
ref class IntrinsicInst;
ref class MDNode;
ref class ConstantInt;
ref class Constant;
ref class Type;

public ref class IntrinsicInst
	: public CallInst
{
internal:
	llvm::IntrinsicInst *base;
	IntrinsicInst(llvm::IntrinsicInst *base);

public:
	!IntrinsicInst();
	virtual ~IntrinsicInst();
	Intrinsic::ID getIntrinsicID();
	static inline bool classof(CallInst ^I);
	static inline bool classof(Value ^V);
};


public ref class DbgInfoIntrinsic
	: public IntrinsicInst
{
internal:
	llvm::DbgInfoIntrinsic *base;
	DbgInfoIntrinsic(llvm::DbgInfoIntrinsic *base);

public:
	!DbgInfoIntrinsic();
	virtual ~DbgInfoIntrinsic();
	static inline bool classof(IntrinsicInst ^I);
	static inline bool classof(Value ^V);
	static Value ^StripCast(Value ^C);
};


public ref class DbgDeclareInst
	: public DbgInfoIntrinsic
{
internal:
	llvm::DbgDeclareInst *base;
	DbgDeclareInst(llvm::DbgDeclareInst *base);

public:
	!DbgDeclareInst();
	virtual ~DbgDeclareInst();
	Value ^getAddress();
	MDNode ^getVariable();
	static inline bool classof(IntrinsicInst ^I);
	static inline bool classof(Value ^V);
};


public ref class DbgValueInst
	: public DbgInfoIntrinsic
{
internal:
	llvm::DbgValueInst *base;
	DbgValueInst(llvm::DbgValueInst *base);

public:
	!DbgValueInst();
	virtual ~DbgValueInst();
	// const Value *getValue();
	Value ^getValue();
	uint64_t getOffset();
	MDNode ^getVariable();
	static inline bool classof(IntrinsicInst ^I);
	static inline bool classof(Value ^V);
};


public ref class MemIntrinsic
	: public IntrinsicInst
{
internal:
	llvm::MemIntrinsic *base;
	MemIntrinsic(llvm::MemIntrinsic *base);

public:
	!MemIntrinsic();
	virtual ~MemIntrinsic();
	Value ^getRawDest();
	Value ^getLength();
	ConstantInt ^getAlignmentCst();
	unsigned getAlignment();
	ConstantInt ^getVolatileCst();
	bool isVolatile();
	unsigned getDestAddressSpace();
	Value ^getDest();
	void setDest(Value ^Ptr);
	void setLength(Value ^L);
	void setAlignment(Constant ^A);
	void setVolatile(Constant ^V);
	Type ^getAlignmentType();
	static inline bool classof(IntrinsicInst ^I);
	static inline bool classof(Value ^V);
};


public ref class MemSetInst
	: public MemIntrinsic
{
internal:
	llvm::MemSetInst *base;
	MemSetInst(llvm::MemSetInst *base);

public:
	!MemSetInst();
	virtual ~MemSetInst();
	Value ^getValue();
	void setValue(Value ^Val);
	static inline bool classof(IntrinsicInst ^I);
	static inline bool classof(Value ^V);
};


public ref class MemTransferInst
	: public MemIntrinsic
{
internal:
	llvm::MemTransferInst *base;
	MemTransferInst(llvm::MemTransferInst *base);

public:
	!MemTransferInst();
	virtual ~MemTransferInst();
	Value ^getRawSource();
	Value ^getSource();
	unsigned getSourceAddressSpace();
	void setSource(Value ^Ptr);
	static inline bool classof(IntrinsicInst ^I);
	static inline bool classof(Value ^V);
};


public ref class MemCpyInst
	: public MemTransferInst
{
internal:
	llvm::MemCpyInst *base;
	MemCpyInst(llvm::MemCpyInst *base);

public:
	!MemCpyInst();
	virtual ~MemCpyInst();
	static inline bool classof(IntrinsicInst ^I);
	static inline bool classof(Value ^V);
};


public ref class MemMoveInst
	: public MemTransferInst
{
internal:
	llvm::MemMoveInst *base;
	MemMoveInst(llvm::MemMoveInst *base);

public:
	!MemMoveInst();
	virtual ~MemMoveInst();
	static inline bool classof(IntrinsicInst ^I);
	static inline bool classof(Value ^V);
};


public ref class VAStartInst
	: public IntrinsicInst
{
internal:
	llvm::VAStartInst *base;
	VAStartInst(llvm::VAStartInst *base);

public:
	!VAStartInst();
	virtual ~VAStartInst();
	static inline bool classof(IntrinsicInst ^I);
	static inline bool classof(Value ^V);
	Value ^getArgList();
};


public ref class VAEndInst
	: public IntrinsicInst
{
internal:
	llvm::VAEndInst *base;
	VAEndInst(llvm::VAEndInst *base);

public:
	!VAEndInst();
	virtual ~VAEndInst();
	static inline bool classof(IntrinsicInst ^I);
	static inline bool classof(Value ^V);
	Value ^getArgList();
};


public ref class VACopyInst
	: public IntrinsicInst
{
internal:
	llvm::VACopyInst *base;
	VACopyInst(llvm::VACopyInst *base);

public:
	!VACopyInst();
	virtual ~VACopyInst();
	static inline bool classof(IntrinsicInst ^I);
	static inline bool classof(Value ^V);
	Value ^getDest();
	Value ^getSrc();
};

}
