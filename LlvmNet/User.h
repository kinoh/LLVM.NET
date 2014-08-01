#pragma once
#include "llvm/IR/User.h"
#include "Value.h"

namespace LLVM
{

ref class Value;
ref class Use;

public ref class User
	: public Value
{
internal:
	llvm::User *base;

protected:
	User(llvm::User *base);

internal:
	static inline User ^_wrap(llvm::User *base);

public:
	!User();
	virtual ~User();
	//
	// void operator delete(void *Usr);
	// void operator delete(void *, unsigned);
	// void operator delete(void *, unsigned, bool);
	Value ^getOperand(unsigned i);
	void setOperand(unsigned i, Value ^Val);
	// const Use &getOperandUse(unsigned i);
	Use ^getOperandUse(unsigned i);
	unsigned getNumOperands();
	// typedef Use *      op_iterator;
	// typedef const Use *const_op_iterator;
	// inline op_iterator       op_begin();
	// inline const_op_iterator op_begin();
	// inline op_iterator       op_end();
	// inline const_op_iterator op_end()  ;
	// inline value_op_iterator value_op_begin();
	// inline value_op_iterator value_op_end();
	void dropAllReferences();
	void replaceUsesOfWith(Value ^From, Value ^To);
	static inline bool classof(Value ^V);
};

}
