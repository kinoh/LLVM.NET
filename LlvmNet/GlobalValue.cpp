#include "GlobalValue.h"
#include "llvm/ADT/StringRef.h"
#include "DerivedTypes.h"
#include "Module.h"
#include "Value.h"
#include <msclr/marshal.h>

using namespace LLVM;

GlobalValue::GlobalValue(llvm::GlobalValue *base)
	: base(base)
	, Constant(base)
{
}
GlobalValue::!GlobalValue()
{
}
GlobalValue::~GlobalValue()
{
	this->!GlobalValue();
}
unsigned GlobalValue::getAlignment()
{
	return base->getAlignment();
}
void GlobalValue::setAlignment(unsigned Align)
{
	base->setAlignment(Align);
}
bool GlobalValue::hasUnnamedAddr()
{
	return base->hasUnnamedAddr();
}
void GlobalValue::setUnnamedAddr(bool Val)
{
	base->setUnnamedAddr(Val);
}
GlobalValue::VisibilityTypes GlobalValue::getVisibility()
{
	return safe_cast<GlobalValue::VisibilityTypes>(base->getVisibility());
}
bool GlobalValue::hasDefaultVisibility()
{
	return base->hasDefaultVisibility();
}
bool GlobalValue::hasHiddenVisibility()
{
	return base->hasHiddenVisibility();
}
bool GlobalValue::hasProtectedVisibility()
{
	return base->hasProtectedVisibility();
}
void GlobalValue::setVisibility(VisibilityTypes V)
{
	base->setVisibility(safe_cast<llvm::GlobalValue::VisibilityTypes>(V));
}
bool GlobalValue::hasSection()
{
	return base->hasSection();
}
void GlobalValue::setSection(System::String ^S)
{
	msclr::interop::marshal_context ctx;
	base->setSection(ctx.marshal_as<const char *>(S));
}
inline PointerType ^GlobalValue::getType()
{
	return gcnew PointerType(base->getType());
}
GlobalValue::LinkageTypes GlobalValue::getLinkOnceLinkage(bool ODR)
{
	return safe_cast<GlobalValue::LinkageTypes>(llvm::GlobalValue::getLinkOnceLinkage(ODR));
}
GlobalValue::LinkageTypes GlobalValue::getWeakLinkage(bool ODR)
{
	return safe_cast<GlobalValue::LinkageTypes>(llvm::GlobalValue::getWeakLinkage(ODR));
}
bool GlobalValue::isExternalLinkage(LinkageTypes Linkage)
{
	return llvm::GlobalValue::isExternalLinkage(safe_cast<llvm::GlobalValue::LinkageTypes>(Linkage));
}
bool GlobalValue::isAvailableExternallyLinkage(LinkageTypes Linkage)
{
	return llvm::GlobalValue::isAvailableExternallyLinkage(safe_cast<llvm::GlobalValue::LinkageTypes>(Linkage));
}
bool GlobalValue::isLinkOnceLinkage(LinkageTypes Linkage)
{
	return llvm::GlobalValue::isLinkOnceLinkage(safe_cast<llvm::GlobalValue::LinkageTypes>(Linkage));
}
bool GlobalValue::isLinkOnceODRAutoHideLinkage(LinkageTypes Linkage)
{
	return llvm::GlobalValue::isLinkOnceODRAutoHideLinkage(safe_cast<llvm::GlobalValue::LinkageTypes>(Linkage));
}
bool GlobalValue::isWeakLinkage(LinkageTypes Linkage)
{
	return llvm::GlobalValue::isWeakLinkage(safe_cast<llvm::GlobalValue::LinkageTypes>(Linkage));
}
bool GlobalValue::isAppendingLinkage(LinkageTypes Linkage)
{
	return llvm::GlobalValue::isAppendingLinkage(safe_cast<llvm::GlobalValue::LinkageTypes>(Linkage));
}
bool GlobalValue::isInternalLinkage(LinkageTypes Linkage)
{
	return llvm::GlobalValue::isInternalLinkage(safe_cast<llvm::GlobalValue::LinkageTypes>(Linkage));
}
bool GlobalValue::isPrivateLinkage(LinkageTypes Linkage)
{
	return llvm::GlobalValue::isPrivateLinkage(safe_cast<llvm::GlobalValue::LinkageTypes>(Linkage));
}
bool GlobalValue::isLinkerPrivateLinkage(LinkageTypes Linkage)
{
	return llvm::GlobalValue::isLinkerPrivateLinkage(safe_cast<llvm::GlobalValue::LinkageTypes>(Linkage));
}
bool GlobalValue::isLinkerPrivateWeakLinkage(LinkageTypes Linkage)
{
	return llvm::GlobalValue::isLinkerPrivateWeakLinkage(safe_cast<llvm::GlobalValue::LinkageTypes>(Linkage));
}
bool GlobalValue::isLocalLinkage(LinkageTypes Linkage)
{
	return llvm::GlobalValue::isLocalLinkage(safe_cast<llvm::GlobalValue::LinkageTypes>(Linkage));
}
bool GlobalValue::isDLLImportLinkage(LinkageTypes Linkage)
{
	return llvm::GlobalValue::isDLLImportLinkage(safe_cast<llvm::GlobalValue::LinkageTypes>(Linkage));
}
bool GlobalValue::isDLLExportLinkage(LinkageTypes Linkage)
{
	return llvm::GlobalValue::isDLLExportLinkage(safe_cast<llvm::GlobalValue::LinkageTypes>(Linkage));
}
bool GlobalValue::isExternalWeakLinkage(LinkageTypes Linkage)
{
	return llvm::GlobalValue::isExternalWeakLinkage(safe_cast<llvm::GlobalValue::LinkageTypes>(Linkage));
}
bool GlobalValue::isCommonLinkage(LinkageTypes Linkage)
{
	return llvm::GlobalValue::isCommonLinkage(safe_cast<llvm::GlobalValue::LinkageTypes>(Linkage));
}
bool GlobalValue::isDiscardableIfUnused(LinkageTypes Linkage)
{
	return llvm::GlobalValue::isDiscardableIfUnused(safe_cast<llvm::GlobalValue::LinkageTypes>(Linkage));
}
bool GlobalValue::mayBeOverridden(LinkageTypes Linkage)
{
	return llvm::GlobalValue::mayBeOverridden(safe_cast<llvm::GlobalValue::LinkageTypes>(Linkage));
}
bool GlobalValue::isWeakForLinker(LinkageTypes Linkage)
{
	return llvm::GlobalValue::isWeakForLinker(safe_cast<llvm::GlobalValue::LinkageTypes>(Linkage));
}
bool GlobalValue::hasExternalLinkage()
{
	return base->hasExternalLinkage();
}
bool GlobalValue::hasAvailableExternallyLinkage()
{
	return base->hasAvailableExternallyLinkage();
}
bool GlobalValue::hasLinkOnceLinkage()
{
	return base->hasLinkOnceLinkage();
}
bool GlobalValue::hasLinkOnceODRAutoHideLinkage()
{
	return base->hasLinkOnceODRAutoHideLinkage();
}
bool GlobalValue::hasWeakLinkage()
{
	return base->hasWeakLinkage();
}
bool GlobalValue::hasAppendingLinkage()
{
	return base->hasAppendingLinkage();
}
bool GlobalValue::hasInternalLinkage()
{
	return base->hasInternalLinkage();
}
bool GlobalValue::hasPrivateLinkage()
{
	return base->hasPrivateLinkage();
}
bool GlobalValue::hasLinkerPrivateLinkage()
{
	return base->hasLinkerPrivateLinkage();
}
bool GlobalValue::hasLinkerPrivateWeakLinkage()
{
	return base->hasLinkerPrivateWeakLinkage();
}
bool GlobalValue::hasLocalLinkage()
{
	return base->hasLocalLinkage();
}
bool GlobalValue::hasDLLImportLinkage()
{
	return base->hasDLLImportLinkage();
}
bool GlobalValue::hasDLLExportLinkage()
{
	return base->hasDLLExportLinkage();
}
bool GlobalValue::hasExternalWeakLinkage()
{
	return base->hasExternalWeakLinkage();
}
bool GlobalValue::hasCommonLinkage()
{
	return base->hasCommonLinkage();
}
void GlobalValue::setLinkage(LinkageTypes LT)
{
	base->setLinkage(safe_cast<llvm::GlobalValue::LinkageTypes>(LT));
}
GlobalValue::LinkageTypes GlobalValue::getLinkage()
{
	return safe_cast<GlobalValue::LinkageTypes>(base->getLinkage());
}
bool GlobalValue::isDiscardableIfUnused()
{
	return base->isDiscardableIfUnused();
}
bool GlobalValue::mayBeOverridden()
{
	return base->mayBeOverridden();
}
bool GlobalValue::isWeakForLinker()
{
	return base->isWeakForLinker();
}
void GlobalValue::copyAttributesFrom(GlobalValue ^Src)
{
	base->copyAttributesFrom(Src->base);
}
bool GlobalValue::isMaterializable()
{
	return base->isMaterializable();
}
bool GlobalValue::isDematerializable()
{
	return base->isDematerializable();
}
bool GlobalValue::Materialize()
{
	return base->Materialize();
}
void GlobalValue::Dematerialize()
{
	base->Dematerialize();
}
void GlobalValue::destroyConstant()
{
	base->destroyConstant();
}
bool GlobalValue::isDeclaration()
{
	return base->isDeclaration();
}
void GlobalValue::removeFromParent()
{
	base->removeFromParent();
}
void GlobalValue::eraseFromParent()
{
	base->eraseFromParent();
}
inline Module ^GlobalValue::getParent()
{
	return gcnew Module(base->getParent());
}
inline bool GlobalValue::classof(Value ^V)
{
	return llvm::GlobalValue::classof(V->base);
}
