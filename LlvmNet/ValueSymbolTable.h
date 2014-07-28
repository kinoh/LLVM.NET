#pragma once
#using <mscorlib.dll>
#include "llvm/IR/ValueSymbolTable.h"

namespace LLVM
{

ref class Value;

public ref class ValueSymbolTable
{
private:
	bool constructed;
internal:
	llvm::ValueSymbolTable *base;
	ValueSymbolTable(llvm::ValueSymbolTable *base);

public:
	!ValueSymbolTable();
	virtual ~ValueSymbolTable();
	// typedef StringMap<Value*> ValueMap;
	// typedef ValueMap::iterator iterator;
	// typedef ValueMap::const_iterator const_iterator;
	ValueSymbolTable();
	// ~ValueSymbolTable();
	Value ^lookup(System::String ^Name);
	inline bool empty();
	inline unsigned size();
	void dump();
	// inline iterator begin();
	// inline const_iterator begin();
	// inline iterator end();
	// inline const_iterator end();
};

}
