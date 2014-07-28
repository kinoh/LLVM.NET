#include "Module.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/Twine.h"
#include "llvm/ADT/ilist.h"
#include "LLVMContext.h"
#include "GlobalValue.h"
#include "DerivedTypes.h"
#include "Attributes.h"
#include "Constant.h"
#include "Function.h"
#include "GlobalVariable.h"
#include "Type.h"
#include "GlobalAlias.h"
#include "Metadata.h"
#include "Value.h"
#include "GVMaterializer.h"
#include "ValueSymbolTable.h"
#include "raw_ostream.h"
#include "AssemblyAnnotationWriter.h"
#include <msclr/marshal.h>
#include "utils.h"

using namespace LLVM;

Module::Module(llvm::Module *base)
	: base(base)
	, constructed(false)
{
}
Module::!Module()
{
	if (constructed)
	{
		delete base;
	}
}
Module::~Module()
{
	this->!Module();
}
llvm::Module *Module::_construct(System::String ^ModuleID, LLVMContext ^C)
{
	msclr::interop::marshal_context ctx;
	return new llvm::Module(ctx.marshal_as<const char *>(ModuleID), *C->base);
}
Module::Module(System::String ^ModuleID, LLVMContext ^C)
	: base(_construct(ModuleID, C))
	, constructed(true)
{
}
Module::Endianness Module::getEndianness()
{
	return safe_cast<Module::Endianness>(base->getEndianness());
}
Module::PointerSize Module::getPointerSize()
{
	return safe_cast<Module::PointerSize>(base->getPointerSize());
}
LLVMContext ^Module::getContext()
{
	return gcnew LLVMContext(&base->getContext());
}
void Module::setModuleIdentifier(System::String ^ID)
{
	msclr::interop::marshal_context ctx;
	base->setModuleIdentifier(ctx.marshal_as<const char *>(ID));
}
void Module::setDataLayout(System::String ^DL)
{
	msclr::interop::marshal_context ctx;
	base->setDataLayout(ctx.marshal_as<const char *>(DL));
}
void Module::setTargetTriple(System::String ^T)
{
	msclr::interop::marshal_context ctx;
	base->setTargetTriple(ctx.marshal_as<const char *>(T));
}
void Module::setModuleInlineAsm(System::String ^Asm)
{
	msclr::interop::marshal_context ctx;
	base->setModuleInlineAsm(ctx.marshal_as<const char *>(Asm));
}
void Module::appendModuleInlineAsm(System::String ^Asm)
{
	msclr::interop::marshal_context ctx;
	base->appendModuleInlineAsm(ctx.marshal_as<const char *>(Asm));
}
GlobalValue ^Module::getNamedValue(System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew GlobalValue(base->getNamedValue(ctx.marshal_as<const char *>(Name)));
}
unsigned Module::getMDKindID(System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return base->getMDKindID(ctx.marshal_as<const char *>(Name));
}
array<System::String ^> ^Module::getMDKindNamesArray()
{
	llvm::SmallVector<llvm::StringRef, 8> r;
	base->getMDKindNames(r);
	array<System::String ^> ^s = gcnew array<System::String ^>(r.size());
	for (int i = 0; i < s->Length; i++)
		s[i] = utils::manage_str(r[i]);
	return s;
}
StructType ^Module::getTypeByName(System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew StructType(base->getTypeByName(ctx.marshal_as<const char *>(Name)));
}
Constant ^Module::getOrInsertFunction(System::String ^Name, FunctionType ^T, AttributeSet ^AttributeList)
{
	msclr::interop::marshal_context ctx;
	return gcnew Constant(base->getOrInsertFunction(ctx.marshal_as<const char *>(Name), T->base, *AttributeList->base));
}
Constant ^Module::getOrInsertFunction(System::String ^Name, FunctionType ^T)
{
	msclr::interop::marshal_context ctx;
	return gcnew Constant(base->getOrInsertFunction(ctx.marshal_as<const char *>(Name), T->base));
}
Constant ^Module::getOrInsertTargetIntrinsic(System::String ^Name, FunctionType ^Ty, AttributeSet ^AttributeList)
{
	msclr::interop::marshal_context ctx;
	return gcnew Constant(base->getOrInsertTargetIntrinsic(ctx.marshal_as<const char *>(Name), Ty->base, *AttributeList->base));
}
Function ^Module::getFunction(System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew Function(base->getFunction(ctx.marshal_as<const char *>(Name)));
}
GlobalVariable ^Module::getGlobalVariable(System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew GlobalVariable(base->getGlobalVariable(ctx.marshal_as<const char *>(Name)));
}
GlobalVariable ^Module::getGlobalVariable(System::String ^Name, bool AllowInternal)
{
	msclr::interop::marshal_context ctx;
	return gcnew GlobalVariable(base->getGlobalVariable(ctx.marshal_as<const char *>(Name), AllowInternal));
}
GlobalVariable ^Module::getNamedGlobal(System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew GlobalVariable(base->getNamedGlobal(ctx.marshal_as<const char *>(Name)));
}
Constant ^Module::getOrInsertGlobal(System::String ^Name, Type ^Ty)
{
	msclr::interop::marshal_context ctx;
	return gcnew Constant(base->getOrInsertGlobal(ctx.marshal_as<const char *>(Name), Ty->base));
}
GlobalAlias ^Module::getNamedAlias(System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew GlobalAlias(base->getNamedAlias(ctx.marshal_as<const char *>(Name)));
}
NamedMDNode ^Module::getNamedMetadata(System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew NamedMDNode(base->getNamedMetadata(ctx.marshal_as<const char *>(Name)));
}
NamedMDNode ^Module::getOrInsertNamedMetadata(System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return gcnew NamedMDNode(base->getOrInsertNamedMetadata(ctx.marshal_as<const char *>(Name)));
}
void Module::eraseNamedMetadata(NamedMDNode ^NMD)
{
	base->eraseNamedMetadata(NMD->base);
}
array<Module::ModuleFlagEntry ^> ^Module::getModuleFlagsMetadataArray()
{
	llvm::SmallVector<llvm::Module::ModuleFlagEntry, 8> r;
	base->getModuleFlagsMetadata(r);
	array<Module::ModuleFlagEntry ^> ^s = gcnew array<Module::ModuleFlagEntry ^>(r.size());
	for (int i = 0; i < s->Length; i++)
		s[i] = gcnew Module::ModuleFlagEntry(&r[i]);
	return s;
}
NamedMDNode ^Module::getModuleFlagsMetadata()
{
	return gcnew NamedMDNode(base->getModuleFlagsMetadata());
}
NamedMDNode ^Module::getOrInsertModuleFlagsMetadata()
{
	return gcnew NamedMDNode(base->getOrInsertModuleFlagsMetadata());
}
void Module::addModuleFlag(ModFlagBehavior Behavior, System::String ^Key, Value ^Val)
{
	msclr::interop::marshal_context ctx;
	base->addModuleFlag(safe_cast<llvm::Module::ModFlagBehavior>(Behavior), ctx.marshal_as<const char *>(Key), Val->base);
}
void Module::addModuleFlag(ModFlagBehavior Behavior, System::String ^Key, uint32_t Val)
{
	msclr::interop::marshal_context ctx;
	base->addModuleFlag(safe_cast<llvm::Module::ModFlagBehavior>(Behavior), ctx.marshal_as<const char *>(Key), Val);
}
void Module::addModuleFlag(MDNode ^Node)
{
	base->addModuleFlag(Node->base);
}
void Module::setMaterializer(GVMaterializer ^GVM)
{
	base->setMaterializer(GVM->base);
}
GVMaterializer ^Module::getMaterializer()
{
	return gcnew GVMaterializer(base->getMaterializer());
}
bool Module::isMaterializable(GlobalValue ^GV)
{
	return base->isMaterializable(GV->base);
}
bool Module::isDematerializable(GlobalValue ^GV)
{
	return base->isDematerializable(GV->base);
}
bool Module::Materialize(GlobalValue ^GV)
{
	return base->Materialize(GV->base);
}
void Module::Dematerialize(GlobalValue ^GV)
{
	base->Dematerialize(GV->base);
}
bool Module::MaterializeAll()
{
	return base->MaterializeAll();
}
bool Module::MaterializeAllPermanently()
{
	return base->MaterializeAllPermanently();
}
System::Collections::Generic::List<GlobalVariable ^> ^Module::getGlobalList()
{
	auto r = &base->getGlobalList();
	auto s = gcnew System::Collections::Generic::List<GlobalVariable ^>(r->size());
	for (auto it = r->begin(); it != r->end(); ++it)
		s->Add(gcnew GlobalVariable(it));
	return s;
}
System::Collections::Generic::List<Function ^> ^Module::getFunctionList()
{
	auto r = &base->getFunctionList();
	auto s = gcnew System::Collections::Generic::List<Function ^>(r->size());
	for (auto it = r->begin(); it != r->end(); ++it)
		s->Add(gcnew Function(it));
	return s;
}
System::Collections::Generic::List<GlobalAlias ^> ^Module::getAliasList()
{
	auto r = &base->getAliasList();
	auto s = gcnew System::Collections::Generic::List<GlobalAlias ^>(r->size());
	for (auto it = r->begin(); it != r->end(); ++it)
		s->Add(gcnew GlobalAlias(it));
	return s;
}
System::Collections::Generic::List<NamedMDNode ^> ^Module::getNamedMDList()
{
	auto r = &base->getNamedMDList();
	auto s = gcnew System::Collections::Generic::List<NamedMDNode ^>(r->size());
	for (auto it = r->begin(); it != r->end(); ++it)
		s->Add(gcnew NamedMDNode(it));
	return s;
}
ValueSymbolTable ^Module::getValueSymbolTable()
{
	return gcnew ValueSymbolTable(&base->getValueSymbolTable());
}
bool Module::global_empty()
{
	return base->global_empty();
}
size_t Module::size()
{
	return base->size();
}
bool Module::empty()
{
	return base->empty();
}
size_t Module::alias_size()
{
	return base->alias_size();
}
bool Module::alias_empty()
{
	return base->alias_empty();
}
size_t Module::named_metadata_size()
{
	return base->named_metadata_size();
}
bool Module::named_metadata_empty()
{
	return base->named_metadata_empty();
}
void Module::print(raw_ostream ^OS, AssemblyAnnotationWriter ^AAW)
{
	base->print(*OS->base, AAW->base);
}
void Module::dump()
{
	base->dump();
}
void Module::dropAllReferences()
{
	base->dropAllReferences();
}
