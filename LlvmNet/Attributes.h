#pragma once
#using <mscorlib.dll>
#include "llvm/IR/Attributes.h"

namespace LLVM
{

ref class LLVMContext;
ref class AttrBuilder;
ref class Attribute;
ref class AttributeSet;

public ref class Attribute
{
public:
	enum class AttrKind
	{
		None,
		Alignment,
		AlwaysInline,
		ByVal,
		InlineHint,
		InReg,
		MinSize,
		Naked,
		Nest,
		NoAlias,
		NoBuiltin,
		NoCapture,
		NoDuplicate,
		NoImplicitFloat,
		NoInline,
		NonLazyBind,
		NoRedZone,
		NoReturn,
		NoUnwind,
		OptimizeForSize,
		ReadNone,
		ReadOnly,
		Returned,
		ReturnsTwice,
		SExt,
		StackAlignment,
		StackProtect,
		StackProtectReq,
		StackProtectStrong,
		StructRet,
		SanitizeAddress,
		SanitizeThread,
		SanitizeMemory,
		UWTable,
		ZExt,

		EndAttrKinds
	};

private:
	bool constructed;

internal:
	llvm::Attribute *base;

protected:
	Attribute(llvm::Attribute *base);

internal:
	static inline Attribute ^_wrap(llvm::Attribute *base);

public:
	!Attribute();
	virtual ~Attribute();
	Attribute();
	static Attribute ^get(LLVMContext ^Context, AttrKind Kind);
	static Attribute ^get(LLVMContext ^Context, AttrKind Kind, uint64_t Val);
	static Attribute ^get(LLVMContext ^Context, System::String ^Kind);
	static Attribute ^get(LLVMContext ^Context, System::String ^Kind, System::String ^Val);
	static Attribute ^getWithAlignment(LLVMContext ^Context, uint64_t Align);
	static Attribute ^getWithStackAlignment(LLVMContext ^Context, uint64_t Align);
	bool isEnumAttribute();
	bool isAlignAttribute();
	bool isStringAttribute();
	bool hasAttribute(AttrKind Val);
	bool hasAttribute(System::String ^Val);
	Attribute::AttrKind getKindAsEnum();
	uint64_t getValueAsInt();
	System::String ^getKindAsString();
	System::String ^getValueAsString();
	unsigned getAlignment();
	unsigned getStackAlignment();
	System::String ^getAsString();
	System::String ^getAsString(bool InAttrGrp);
	// bool operator==(Attribute A);
	// bool operator!=(Attribute A);
	// bool operator<(Attribute A);
	// void Profile(FoldingSetNodeID &ID);
};


public ref class AttributeSet
{
public:
	enum class AttrIndex
	{
		ReturnIndex = 0U,
		FunctionIndex = ~0U
	};

private:
	bool constructed;

internal:
	llvm::AttributeSet *base;

protected:
	AttributeSet(llvm::AttributeSet *base);

internal:
	static inline AttributeSet ^_wrap(llvm::AttributeSet *base);

public:
	!AttributeSet();
	virtual ~AttributeSet();
	AttributeSet();
	static AttributeSet ^get(LLVMContext ^C, array<AttributeSet ^> ^Attrs);
	static AttributeSet ^get(LLVMContext ^C, unsigned Index, array<Attribute::AttrKind> ^Kind);
	static AttributeSet ^get(LLVMContext ^C, unsigned Index, AttrBuilder ^B);
	AttributeSet ^addAttribute(LLVMContext ^C, unsigned Index, Attribute::AttrKind Attr);
	AttributeSet ^addAttribute(LLVMContext ^C, unsigned Index, System::String ^Kind);
	AttributeSet ^addAttributes(LLVMContext ^C, unsigned Index, AttributeSet ^Attrs);
	AttributeSet ^removeAttribute(LLVMContext ^C, unsigned Index, Attribute::AttrKind Attr);
	AttributeSet ^removeAttributes(LLVMContext ^C, unsigned Index, AttributeSet ^Attrs);
	LLVMContext ^getContext();
	AttributeSet ^getParamAttributes(unsigned Index);
	AttributeSet ^getRetAttributes();
	AttributeSet ^getFnAttributes();
	bool hasAttribute(unsigned Index, Attribute::AttrKind Kind);
	bool hasAttribute(unsigned Index, System::String ^Kind);
	bool hasAttributes(unsigned Index);
	bool hasAttrSomewhere(Attribute::AttrKind Attr);
	Attribute ^getAttribute(unsigned Index, Attribute::AttrKind Kind);
	Attribute ^getAttribute(unsigned Index, System::String ^Kind);
	unsigned getParamAlignment(unsigned Index);
	unsigned getStackAlignment(unsigned Index);
	System::String ^getAsString(unsigned Index);
	System::String ^getAsString(unsigned Index, bool InAttrGrp);
	// typedef ArrayRef<Attribute>::iterator iterator;
	// iterator begin(unsigned Slot);
	// iterator end(unsigned Slot);
	// bool operator==(const AttributeSet &RHS);
	// bool operator!=(const AttributeSet &RHS);
	uint64_t Raw(unsigned Index);
	void *getRawPointer();
	bool isEmpty();
	unsigned getNumSlots();
	unsigned getSlotIndex(unsigned Slot);
	AttributeSet ^getSlotAttributes(unsigned Slot);
	void dump();
};


public ref class AttrBuilder
{
private:
	bool constructed;

internal:
	llvm::AttrBuilder *base;

protected:
	AttrBuilder(llvm::AttrBuilder *base);

internal:
	static inline AttrBuilder ^_wrap(llvm::AttrBuilder *base);

public:
	!AttrBuilder();
	virtual ~AttrBuilder();
	AttrBuilder();
	AttrBuilder(uint64_t Val);
	//   : Attrs(0), Alignment(0), StackAlignment(0);
	AttrBuilder(Attribute ^A);
	AttrBuilder(AttributeSet ^AS, unsigned Idx);
	AttrBuilder(AttrBuilder ^B);
	//   : Attrs(B.Attrs), TargetDepAttrs(B.TargetDepAttrs.begin(), B.TargetDepAttrs.end()), Alignment(B.Alignment), StackAlignment(B.StackAlignment);
	void clear();
	AttrBuilder ^addAttribute(Attribute::AttrKind Val);
	AttrBuilder ^addAttribute(Attribute ^A);
	AttrBuilder ^addAttribute(System::String ^A);
	AttrBuilder ^addAttribute(System::String ^A, System::String ^V);
	AttrBuilder ^removeAttribute(Attribute::AttrKind Val);
	AttrBuilder ^removeAttributes(AttributeSet ^A, uint64_t Index);
	AttrBuilder ^removeAttribute(System::String ^A);
	AttrBuilder ^merge(AttrBuilder ^B);
	bool contains(Attribute::AttrKind A);
	bool contains(System::String ^A);
	bool hasAttributes();
	bool hasAttributes(AttributeSet ^A, uint64_t Index);
	bool hasAlignmentAttr();
	uint64_t getAlignment();
	uint64_t getStackAlignment();
	AttrBuilder ^addAlignmentAttr(unsigned Align);
	AttrBuilder ^addStackAlignmentAttr(unsigned Align);
	bool empty();
	// typedef std::pair<std::string, std::string>                td_type;
	// typedef std::map<std::string, std::string>::iterator       td_iterator;
	// typedef std::map<std::string, std::string>::const_iterator td_const_iterator;
	// td_iterator td_begin();
	// td_iterator td_end();
	// td_const_iterator td_begin();
	// td_const_iterator td_end();
	bool td_empty();
	// bool operator==(const AttrBuilder &B);
	// bool operator!=(const AttrBuilder &B);
	AttrBuilder ^addRawValue(uint64_t Val);
};

}
