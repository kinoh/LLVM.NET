#include "raw_ostream.h"
#include "llvm/ADT/StringRef.h"
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include "utils.h"

using namespace LLVM;

raw_ostream::raw_ostream(llvm::raw_ostream *base)
	: base(base)
{
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
raw_ostream ^raw_ostream::write_hex(unsigned long long N)
{
	return gcnew raw_ostream(&base->write_hex(N));
}
raw_ostream ^raw_ostream::write_escaped(System::String ^Str)
{
	msclr::interop::marshal_context ctx;
	return gcnew raw_ostream(&base->write_escaped(ctx.marshal_as<const char *>(Str)));
}
raw_ostream ^raw_ostream::write_escaped(System::String ^Str, bool UseHexEscapes)
{
	msclr::interop::marshal_context ctx;
	return gcnew raw_ostream(&base->write_escaped(ctx.marshal_as<const char *>(Str), UseHexEscapes));
}
raw_ostream ^raw_ostream::write(unsigned char C)
{
	return gcnew raw_ostream(&base->write(C));
}
raw_ostream ^raw_ostream::write(System::String ^Ptr, size_t Size)
{
	msclr::interop::marshal_context ctx;
	return gcnew raw_ostream(&base->write(ctx.marshal_as<const char *>(Ptr), Size));
}
raw_ostream ^raw_ostream::indent(unsigned NumSpaces)
{
	return gcnew raw_ostream(&base->indent(NumSpaces));
}
raw_ostream ^raw_ostream::changeColor(Colors Color)
{
	return gcnew raw_ostream(&base->changeColor(safe_cast<llvm::raw_ostream::Colors>(Color)));
}
raw_ostream ^raw_ostream::changeColor(Colors Color, bool Bold)
{
	return gcnew raw_ostream(&base->changeColor(safe_cast<llvm::raw_ostream::Colors>(Color), Bold));
}
raw_ostream ^raw_ostream::changeColor(Colors Color, bool Bold, bool BG)
{
	return gcnew raw_ostream(&base->changeColor(safe_cast<llvm::raw_ostream::Colors>(Color), Bold, BG));
}
raw_ostream ^raw_ostream::resetColor()
{
	return gcnew raw_ostream(&base->resetColor());
}
raw_ostream ^raw_ostream::reverseColor()
{
	return gcnew raw_ostream(&base->reverseColor());
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


raw_string_ostream::raw_string_ostream(llvm::raw_string_ostream *base)
	: base(base)
	, raw_ostream(base)
	, constructed(false)
{
}
raw_string_ostream::!raw_string_ostream()
{
	if (constructed)
	{
		delete base;
	}
}
raw_string_ostream::~raw_string_ostream()
{
	this->!raw_string_ostream();
}
raw_string_ostream::raw_string_ostream(std::string O)
	: base(new llvm::raw_string_ostream(O))
	, raw_ostream(base)
	, constructed(true)
{
}
System::String ^raw_string_ostream::str()
{
	return utils::manage_str(base->str());
}


raw_null_ostream::raw_null_ostream(llvm::raw_null_ostream *base)
	: base(base)
	, raw_ostream(base)
	, constructed(false)
{
}
raw_null_ostream::!raw_null_ostream()
{
	if (constructed)
	{
		delete base;
	}
}
raw_null_ostream::~raw_null_ostream()
{
	this->!raw_null_ostream();
}
raw_null_ostream::raw_null_ostream()
	: base(new llvm::raw_null_ostream())
	, raw_ostream(base)
	, constructed(true)
{
}
