#include "ValueSymbolTable.h"
#include "llvm/ADT/StringRef.h"
#include "Value.h"
#include <msclr/marshal.h>

using namespace LLVM;

ValueSymbolTable::ValueSymbolTable(llvm::ValueSymbolTable *base)
	: base(base)
	, constructed(false)
{
}
ValueSymbolTable::!ValueSymbolTable()
{
	if (constructed)
	{
		delete base;
	}
}
ValueSymbolTable::~ValueSymbolTable()
{
	this->!ValueSymbolTable();
}
ValueSymbolTable::ValueSymbolTable()
	: base(new llvm::ValueSymbolTable())
	, constructed(true)
{
}
Value ^ValueSymbolTable::lookup(System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew Value(base->lookup(ctx.marshal_as<const char *>(Name)));
}
inline bool ValueSymbolTable::empty()
{
	return base->empty();
}
inline unsigned ValueSymbolTable::size()
{
	return base->size();
}
void ValueSymbolTable::dump()
{
	base->dump();
}
