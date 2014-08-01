#include "Function.h"
#include "llvm/ADT/Twine.h"
#include "CallingConv.h"
#include "llvm/ADT/StringRef.h"
#include "Attributes.h"
#include "llvm/ADT/ilist.h"
#include "DerivedTypes.h"
#include "Module.h"
#include "Type.h"
#include "LLVMContext.h"
#include "Attributes.h"
#include "GlobalValue.h"
#include "Argument.h"
#include "BasicBlock.h"
#include "ValueSymbolTable.h"
#include "Value.h"
#include <msclr/marshal.h>
#include "utils.h"

using namespace LLVM;

Function::Function(llvm::Function *base)
	: base(base)
	, GlobalValue(base)
{
}
inline Function ^Function::_wrap(llvm::Function *base)
{
	return base ? gcnew Function(base) : nullptr;
}
Function::!Function()
{
}
Function::~Function()
{
	this->!Function();
}
Function ^Function::Create(FunctionType ^Ty, LinkageTypes Linkage)
{
	return Function::_wrap(llvm::Function::Create(Ty->base, safe_cast<llvm::Function::LinkageTypes>(Linkage)));
}
Function ^Function::Create(FunctionType ^Ty, LinkageTypes Linkage, System::String ^N)
{
	msclr::interop::marshal_context ctx;
	return Function::_wrap(llvm::Function::Create(Ty->base, safe_cast<llvm::Function::LinkageTypes>(Linkage), ctx.marshal_as<const char *>(N)));
}
Function ^Function::Create(FunctionType ^Ty, LinkageTypes Linkage, System::String ^N, Module ^M)
{
	msclr::interop::marshal_context ctx;
	return Function::_wrap(llvm::Function::Create(Ty->base, safe_cast<llvm::Function::LinkageTypes>(Linkage), ctx.marshal_as<const char *>(N), M->base));
}
Type ^Function::getReturnType()
{
	return Type::_wrap(base->getReturnType());
}
FunctionType ^Function::getFunctionType()
{
	return FunctionType::_wrap(base->getFunctionType());
}
LLVMContext ^Function::getContext()
{
	return LLVMContext::_wrap(&base->getContext());
}
bool Function::isVarArg()
{
	return base->isVarArg();
}
bool Function::isIntrinsic()
{
	return base->isIntrinsic();
}
CallingConv::ID Function::getCallingConv()
{
	return safe_cast<CallingConv::ID>(base->getCallingConv());
}
void Function::setCallingConv(CallingConv::ID CC)
{
	base->setCallingConv(safe_cast<llvm::CallingConv::ID>(CC));
}
AttributeSet ^Function::getAttributes()
{
	return AttributeSet::_wrap(&base->getAttributes());
}
void Function::setAttributes(AttributeSet ^attrs)
{
	base->setAttributes(*attrs->base);
}
void Function::addFnAttr(Attribute::AttrKind N)
{
	base->addFnAttr(safe_cast<llvm::Attribute::AttrKind>(N));
}
void Function::addFnAttr(System::String ^Kind)
{
	msclr::interop::marshal_context ctx;
	base->addFnAttr(ctx.marshal_as<const char *>(Kind));
}
bool Function::hasFnAttribute(Attribute::AttrKind Kind)
{
	return base->hasFnAttribute(safe_cast<llvm::Attribute::AttrKind>(Kind));
}
bool Function::hasFnAttribute(System::String ^Kind)
{
	msclr::interop::marshal_context ctx;
	return base->hasFnAttribute(ctx.marshal_as<const char *>(Kind));
}
bool Function::hasGC()
{
	return base->hasGC();
}
System::String ^Function::getGC()
{
	return utils::manage_str(base->getGC());
}
void Function::setGC(System::String ^Str)
{
	msclr::interop::marshal_context ctx;
	base->setGC(ctx.marshal_as<const char *>(Str));
}
void Function::clearGC()
{
	base->clearGC();
}
void Function::addAttribute(unsigned i, Attribute::AttrKind attr)
{
	base->addAttribute(i, safe_cast<llvm::Attribute::AttrKind>(attr));
}
void Function::addAttributes(unsigned i, AttributeSet ^attrs)
{
	base->addAttributes(i, *attrs->base);
}
void Function::removeAttributes(unsigned i, AttributeSet ^attr)
{
	base->removeAttributes(i, *attr->base);
}
unsigned Function::getParamAlignment(unsigned i)
{
	return base->getParamAlignment(i);
}
bool Function::doesNotAccessMemory()
{
	return base->doesNotAccessMemory();
}
void Function::setDoesNotAccessMemory()
{
	base->setDoesNotAccessMemory();
}
bool Function::onlyReadsMemory()
{
	return base->onlyReadsMemory();
}
void Function::setOnlyReadsMemory()
{
	base->setOnlyReadsMemory();
}
bool Function::doesNotReturn()
{
	return base->doesNotReturn();
}
void Function::setDoesNotReturn()
{
	base->setDoesNotReturn();
}
bool Function::doesNotThrow()
{
	return base->doesNotThrow();
}
void Function::setDoesNotThrow()
{
	base->setDoesNotThrow();
}
bool Function::cannotDuplicate()
{
	return base->cannotDuplicate();
}
void Function::setCannotDuplicate()
{
	base->setCannotDuplicate();
}
bool Function::hasUWTable()
{
	return base->hasUWTable();
}
void Function::setHasUWTable()
{
	base->setHasUWTable();
}
bool Function::needsUnwindTableEntry()
{
	return base->needsUnwindTableEntry();
}
bool Function::hasStructRetAttr()
{
	return base->hasStructRetAttr();
}
bool Function::doesNotAlias(unsigned n)
{
	return base->doesNotAlias(n);
}
void Function::setDoesNotAlias(unsigned n)
{
	base->setDoesNotAlias(n);
}
bool Function::doesNotCapture(unsigned n)
{
	return base->doesNotCapture(n);
}
void Function::setDoesNotCapture(unsigned n)
{
	base->setDoesNotCapture(n);
}
void Function::copyAttributesFrom(GlobalValue ^Src)
{
	base->copyAttributesFrom(Src->base);
}
void Function::deleteBody()
{
	base->deleteBody();
}
void Function::removeFromParent()
{
	base->removeFromParent();
}
void Function::eraseFromParent()
{
	base->eraseFromParent();
}
System::Collections::Generic::List<Argument ^> ^Function::getArgumentList()
{
	auto r = &base->getArgumentList();
	auto s = gcnew System::Collections::Generic::List<Argument ^>(r->size());
	for (auto it = r->begin(); it != r->end(); ++it)
		s->Add(Argument::_wrap(it));
	return s;
}
System::Collections::Generic::List<BasicBlock ^> ^Function::getBasicBlockList()
{
	auto r = &base->getBasicBlockList();
	auto s = gcnew System::Collections::Generic::List<BasicBlock ^>(r->size());
	for (auto it = r->begin(); it != r->end(); ++it)
		s->Add(BasicBlock::_wrap(it));
	return s;
}
BasicBlock ^Function::getEntryBlock()
{
	return BasicBlock::_wrap(&base->getEntryBlock());
}
inline ValueSymbolTable ^Function::getValueSymbolTable()
{
	return ValueSymbolTable::_wrap(&base->getValueSymbolTable());
}
size_t Function::size()
{
	return base->size();
}
bool Function::empty()
{
	return base->empty();
}
BasicBlock ^Function::front()
{
	return BasicBlock::_wrap(&base->front());
}
BasicBlock ^Function::back()
{
	return BasicBlock::_wrap(&base->back());
}
size_t Function::arg_size()
{
	return base->arg_size();
}
bool Function::arg_empty()
{
	return base->arg_empty();
}
void Function::viewCFG()
{
	base->viewCFG();
}
void Function::viewCFGOnly()
{
	base->viewCFGOnly();
}
inline bool Function::classof(Value ^V)
{
	return llvm::Function::classof(V->base);
}
void Function::dropAllReferences()
{
	base->dropAllReferences();
}
bool Function::isDefTriviallyDead()
{
	return base->isDefTriviallyDead();
}
bool Function::callsFunctionThatReturnsTwice()
{
	return base->callsFunctionThatReturnsTwice();
}
