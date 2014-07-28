#pragma once
#using <mscorlib.dll>
#include "llvm/ADT/ArrayRef.h"
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include <string>

class utils
{
public:
	inline static System::String ^manage_str(std::string str)
	{
		return msclr::interop::marshal_as<System::String ^>(str);
	}
	template <typename T>
	inline static llvm::ArrayRef<T> unmanage_array(array<T> ^src)
	{
		pin_ptr<T> a = &src[0];
		llvm::ArrayRef<T> arr(a, src->Length);
		return arr;
	}
};
