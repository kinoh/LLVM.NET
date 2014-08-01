#include "raw_ostream.h"
#include "llvm/ADT/StringRef.h"
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include <string>
#include "utils.h"

using namespace LLVM;

raw_ostream::raw_ostream(llvm::raw_ostream *base)
	: base(base)
{
}
inline raw_ostream ^raw_ostream::_wrap(llvm::raw_ostream *base)
{
	return base ? gcnew raw_ostream(base) : nullptr;
}
raw_ostream::!raw_ostream()
{
}
raw_ostream::~raw_ostream()
{
	this->!raw_ostream();
}
uint64_t raw_ostream::tell()
{
	return base->tell();
}
void raw_ostream::SetBuffered()
{
	base->SetBuffered();
}
void raw_ostream::SetBufferSize(size_t Size)
{
	base->SetBufferSize(Size);
}
size_t raw_ostream::GetBufferSize()
{
	return base->GetBufferSize();
}
void raw_ostream::SetUnbuffered()
{
	base->SetUnbuffered();
}
size_t raw_ostream::GetNumBytesInBuffer()
{
	return base->GetNumBytesInBuffer();
}
void raw_ostream::flush()
{
	base->flush();
}
raw_ostream ^raw_ostream::write_escaped(System::String ^Str)
{
	msclr::interop::marshal_context ctx;
	return raw_ostream::_wrap(&base->write_escaped(ctx.marshal_as<const char *>(Str)));
}
raw_ostream ^raw_ostream::write_escaped(System::String ^Str, bool UseHexEscapes)
{
	msclr::interop::marshal_context ctx;
	return raw_ostream::_wrap(&base->write_escaped(ctx.marshal_as<const char *>(Str), UseHexEscapes));
}
raw_ostream ^raw_ostream::write(System::String ^Ptr, size_t Size)
{
	msclr::interop::marshal_context ctx;
	return raw_ostream::_wrap(&base->write(ctx.marshal_as<const char *>(Ptr), Size));
}
raw_ostream ^raw_ostream::indent(unsigned NumSpaces)
{
	return raw_ostream::_wrap(&base->indent(NumSpaces));
}
raw_ostream ^raw_ostream::resetColor()
{
	return raw_ostream::_wrap(&base->resetColor());
}
raw_ostream ^raw_ostream::reverseColor()
{
	return raw_ostream::_wrap(&base->reverseColor());
}
bool raw_ostream::is_displayed()
{
	return base->is_displayed();
}
bool raw_ostream::has_colors()
{
	return base->has_colors();
}


System::String ^raw_fd_ostream::ErrorInfo::get()
{
	return msclr::interop::marshal_as<System::String ^>(*this->errorInfo);
}
raw_fd_ostream::!raw_fd_ostream()
{
	delete errorInfo;
	delete base;
}
raw_fd_ostream::~raw_fd_ostream()
{
	this->!raw_fd_ostream();
}
llvm::raw_fd_ostream *raw_fd_ostream::_construct(System::String ^Filename, std::string &ErrorInfo)
{
	msclr::interop::marshal_context ctx;
	return new llvm::raw_fd_ostream(ctx.marshal_as<const char *>(Filename), ErrorInfo);
}
raw_fd_ostream::raw_fd_ostream(System::String ^Filename)
	: errorInfo(new std::string())
	, base(_construct(Filename, *this->errorInfo))
	, raw_ostream(base)
{
}
llvm::raw_fd_ostream *raw_fd_ostream::_construct(System::String ^Filename, std::string &ErrorInfo, unsigned Flags)
{
	msclr::interop::marshal_context ctx;
	return new llvm::raw_fd_ostream(ctx.marshal_as<const char *>(Filename), ErrorInfo, Flags);
}
raw_fd_ostream::raw_fd_ostream(System::String ^Filename, unsigned Flags)
	: errorInfo(new std::string())
	, base(_construct(Filename, *this->errorInfo, Flags))
	, raw_ostream(base)
{
}
raw_fd_ostream::raw_fd_ostream(int fd, bool shouldClose)
	: base(new llvm::raw_fd_ostream(fd, shouldClose))
	, raw_ostream(base)
{
}
raw_fd_ostream::raw_fd_ostream(int fd, bool shouldClose, bool unbuffered)
	: base(new llvm::raw_fd_ostream(fd, shouldClose, unbuffered))
	, raw_ostream(base)
{
}
void raw_fd_ostream::close()
{
	base->close();
}
uint64_t raw_fd_ostream::seek(uint64_t off)
{
	return base->seek(off);
}
void raw_fd_ostream::SetUseAtomicWrites(bool Value)
{
	base->SetUseAtomicWrites(Value);
}
bool raw_fd_ostream::has_error()
{
	return base->has_error();
}
void raw_fd_ostream::clear_error()
{
	base->clear_error();
}


raw_string_ostream::!raw_string_ostream()
{
	delete base;
}
raw_string_ostream::~raw_string_ostream()
{
	this->!raw_string_ostream();
}
raw_string_ostream::raw_string_ostream(System::String ^O)
	: base(new llvm::raw_string_ostream(msclr::interop::marshal_as<std::string>(O)))
	, raw_ostream(base)
{
}
System::String ^raw_string_ostream::str()
{
	return utils::manage_str(base->str());
}


raw_null_ostream::raw_null_ostream()
	: base(new llvm::raw_null_ostream())
	, raw_ostream(base)
{
}
raw_null_ostream::!raw_null_ostream()
{
	delete base;
}
raw_null_ostream::~raw_null_ostream()
{
	this->!raw_null_ostream();
}
