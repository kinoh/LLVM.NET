#pragma once
#include "llvm/IR/Use.h"

namespace LLVM
{

ref class Value;
ref class User;

public ref class Use
{
internal:
	llvm::Use *base;
	Use(llvm::Use *base);

public:
	!Use();
	virtual ~Use();
	void swap(Use ^RHS);
	// typedef PointerIntPair<User*, 1, unsigned> UserRef;
	// operator Value*();
	Value ^get();
	User ^getUser();
	inline void set(Value ^Val);
	// Value *operator=(Value *RHS);
	// const Use &operator=(const Use &RHS);
	//       Value *operator->();
	// const Value *operator->();
	Use ^getNext();
	static Use ^initTags(Use ^Start, Use ^Stop);
	static void zap(Use ^Start, Use ^Stop);
	static void zap(Use ^Start, Use ^Stop, bool del);
};

}
