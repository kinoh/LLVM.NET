#pragma once
#include "llvm/IR/Constant.h"
#include "User.h"

namespace LLVM
{

ref class Value;
ref class Use;
ref class Type;

public ref class Constant
	: public User
{
public:
	enum class PossibleRelocationsTy
	{
		NoRelocation = 0,
		LocalRelocation = 1,
		GlobalRelocations = 2
	};

internal:
	llvm::Constant *base;

protected:
	Constant(llvm::Constant *base);

internal:
	static inline Constant ^_wrap(llvm::Constant *base);

public:
	!Constant();
	virtual ~Constant();
	bool isNullValue();
	bool isAllOnesValue();
	bool isNegativeZeroValue();
	bool isZeroValue();
	bool canTrap();
	bool isThreadDependent();
	bool isConstantUsed();
	Constant::PossibleRelocationsTy getRelocationInfo();
	Constant ^getAggregateElement(unsigned Elt);
	Constant ^getAggregateElement(Constant ^Elt);
	Constant ^getSplatValue();
	// const APInt &getUniqueInteger();
	virtual void destroyConstant();
	static inline bool classof(Value ^V);
	virtual void replaceUsesOfWithOnConstant(Value ^From, Value ^To, Use ^use);
	static Constant ^getNullValue(Type ^Ty);
	static Constant ^getAllOnesValue(Type ^Ty);
	// static Constant *getIntegerValue(Type *Ty, const APInt &V);
	void removeDeadConstantUsers();
};

}
