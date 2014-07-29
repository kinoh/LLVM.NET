#pragma once
#using <mscorlib.dll>
#include "llvm/IR/GlobalValue.h"
#include "Constant.h"

namespace LLVM
{

ref class PointerType;
ref class Module;
ref class Value;

public ref class GlobalValue
	: public Constant
{
public:
	enum class LinkageTypes
	{
		ExternalLinkage = 0,
		AvailableExternallyLinkage,
		LinkOnceAnyLinkage,
		LinkOnceODRLinkage,
		LinkOnceODRAutoHideLinkage,
		WeakAnyLinkage,
		WeakODRLinkage,
		AppendingLinkage,
		InternalLinkage,
		PrivateLinkage,
		LinkerPrivateLinkage,
		LinkerPrivateWeakLinkage,
		DLLImportLinkage,
		DLLExportLinkage,
		ExternalWeakLinkage,
		CommonLinkage
	};
	enum class VisibilityTypes
	{
		DefaultVisibility = 0,
		HiddenVisibility,
		ProtectedVisibility
	};

internal:
	llvm::GlobalValue *base;
	GlobalValue(llvm::GlobalValue *base);

public:
	!GlobalValue();
	virtual ~GlobalValue();
	//
	unsigned getAlignment();
	void setAlignment(unsigned Align);
	bool hasUnnamedAddr();
	void setUnnamedAddr(bool Val);
	GlobalValue::VisibilityTypes getVisibility();
	bool hasDefaultVisibility();
	bool hasHiddenVisibility();
	bool hasProtectedVisibility();
	void setVisibility(VisibilityTypes V);
	bool hasSection();
	// const std::string &getSection();
	void setSection(System::String ^S);
	// bool use_empty_except_constants();
	inline PointerType ^getType();
	static GlobalValue::LinkageTypes getLinkOnceLinkage(bool ODR);
	static GlobalValue::LinkageTypes getWeakLinkage(bool ODR);
	static bool isExternalLinkage(LinkageTypes Linkage);
	static bool isAvailableExternallyLinkage(LinkageTypes Linkage);
	static bool isLinkOnceLinkage(LinkageTypes Linkage);
	static bool isLinkOnceODRAutoHideLinkage(LinkageTypes Linkage);
	static bool isWeakLinkage(LinkageTypes Linkage);
	static bool isAppendingLinkage(LinkageTypes Linkage);
	static bool isInternalLinkage(LinkageTypes Linkage);
	static bool isPrivateLinkage(LinkageTypes Linkage);
	static bool isLinkerPrivateLinkage(LinkageTypes Linkage);
	static bool isLinkerPrivateWeakLinkage(LinkageTypes Linkage);
	static bool isLocalLinkage(LinkageTypes Linkage);
	static bool isDLLImportLinkage(LinkageTypes Linkage);
	static bool isDLLExportLinkage(LinkageTypes Linkage);
	static bool isExternalWeakLinkage(LinkageTypes Linkage);
	static bool isCommonLinkage(LinkageTypes Linkage);
	static bool isDiscardableIfUnused(LinkageTypes Linkage);
	static bool mayBeOverridden(LinkageTypes Linkage);
	static bool isWeakForLinker(LinkageTypes Linkage);
	bool hasExternalLinkage();
	bool hasAvailableExternallyLinkage();
	bool hasLinkOnceLinkage();
	bool hasLinkOnceODRAutoHideLinkage();
	bool hasWeakLinkage();
	bool hasAppendingLinkage();
	bool hasInternalLinkage();
	bool hasPrivateLinkage();
	bool hasLinkerPrivateLinkage();
	bool hasLinkerPrivateWeakLinkage();
	bool hasLocalLinkage();
	bool hasDLLImportLinkage();
	bool hasDLLExportLinkage();
	bool hasExternalWeakLinkage();
	bool hasCommonLinkage();
	void setLinkage(LinkageTypes LT);
	GlobalValue::LinkageTypes getLinkage();
	bool isDiscardableIfUnused();
	bool mayBeOverridden();
	bool isWeakForLinker();
	virtual void copyAttributesFrom(GlobalValue ^Src);
	bool isMaterializable();
	bool isDematerializable();
	bool Materialize();
	void Dematerialize();
	virtual void destroyConstant() override;
	bool isDeclaration();
	virtual void removeFromParent();
	virtual void eraseFromParent();
	inline Module ^getParent();
	// inline const Module *getParent();
	static inline bool classof(Value ^V);
};

}
