#pragma once
#using <mscorlib.dll>
#include "llvm/Support/raw_ostream.h"

namespace LLVM
{

public ref class raw_ostream
{
public:
	enum class Colors
	{
		BLACK=0,
		RED,
		GREEN,
		YELLOW,
		BLUE,
		MAGENTA,
		CYAN,
		WHITE,
		SAVEDCOLOR
	};

internal:
	llvm::raw_ostream *base;
	raw_ostream(llvm::raw_ostream *base);

public:
	!raw_ostream();
	virtual ~raw_ostream();
	// explicit raw_ostream(bool unbuffered=false);
	//   : BufferMode(unbuffered ? Unbuffered : InternalBuffer);
	// virtual ~raw_ostream();
	uint64_t tell();
	void SetBuffered();
	void SetBufferSize(size_t Size);
	size_t GetBufferSize();
	void SetUnbuffered();
	size_t GetNumBytesInBuffer();
	void flush();
	// raw_ostream &operator<<(char C);
	// raw_ostream &operator<<(unsigned char C);
	// raw_ostream &operator<<(signed char C);
	// raw_ostream &operator<<(StringRef Str);
	// raw_ostream &operator<<(const char *Str);
	// raw_ostream &operator<<(const std::string &Str);
	// raw_ostream &operator<<(unsigned long N);
	// raw_ostream &operator<<(long N);
	// raw_ostream &operator<<(unsigned long long N);
	// raw_ostream &operator<<(long long N);
	// raw_ostream &operator<<(const void *P);
	// raw_ostream &operator<<(unsigned int N);
	// raw_ostream &operator<<(int N);
	// raw_ostream &operator<<(double N);
	raw_ostream ^write_hex(unsigned long long N);
	raw_ostream ^write_escaped(System::String ^Str);
	raw_ostream ^write_escaped(System::String ^Str, bool UseHexEscapes);
	raw_ostream ^write(unsigned char C);
	raw_ostream ^write(System::String ^Ptr, size_t Size);
	// raw_ostream &operator<<(const format_object_base &Fmt);
	raw_ostream ^indent(unsigned NumSpaces);
	virtual raw_ostream ^changeColor(Colors Color);
	virtual raw_ostream ^changeColor(Colors Color, bool Bold);
	virtual raw_ostream ^changeColor(Colors Color, bool Bold, bool BG);
	virtual raw_ostream ^resetColor();
	virtual raw_ostream ^reverseColor();
	virtual bool is_displayed();
	virtual bool has_colors();
};


public ref class raw_fd_ostream
	: public raw_ostream
{
private:
	std::string *errorInfo;
	static llvm::raw_fd_ostream *_construct(System::String ^Filename, std::string &ErrorInfo);
	static llvm::raw_fd_ostream *_construct(System::String ^Filename, std::string &ErrorInfo, unsigned Flags);

internal:
	llvm::raw_fd_ostream *base;

public:
	property System::String ^ErrorInfo
	{
		System::String ^get();
	}
	!raw_fd_ostream();
	virtual ~raw_fd_ostream();
	// enum;
	raw_fd_ostream(System::String ^Filename);
	raw_fd_ostream(System::String ^Filename, unsigned Flags);
	raw_fd_ostream(int fd, bool shouldClose);
	raw_fd_ostream(int fd, bool shouldClose, bool unbuffered);
	void close();
	uint64_t seek(uint64_t off);
	void SetUseAtomicWrites(bool Value);
	// virtual raw_ostream &changeColor(enum Colors colors, bool bold=false, bool bg=false) LLVM_OVERRIDE;
	// virtual raw_ostream &resetColor() LLVM_OVERRIDE;
	// virtual raw_ostream &reverseColor() LLVM_OVERRIDE;
	// virtual bool is_displayed() const LLVM_OVERRIDE;
	// virtual bool has_colors() const LLVM_OVERRIDE;
	bool has_error();
	void clear_error();
};


public ref class raw_string_ostream
	: public raw_ostream
{
private:
	bool constructed;
internal:
	llvm::raw_string_ostream *base;
	raw_string_ostream(llvm::raw_string_ostream *base);

public:
	!raw_string_ostream();
	virtual ~raw_string_ostream();
	raw_string_ostream(std::string O);
	System::String ^str();
};


public ref class raw_null_ostream
	: public raw_ostream
{
private:
	bool constructed;
internal:
	llvm::raw_null_ostream *base;
	raw_null_ostream(llvm::raw_null_ostream *base);

public:
	!raw_null_ostream();
	virtual ~raw_null_ostream();
	raw_null_ostream();
};

}
