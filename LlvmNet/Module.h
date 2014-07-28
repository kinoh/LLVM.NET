#pragma once
#using <mscorlib.dll>
#include "llvm/IR/Module.h"
#include "Metadata.h"
#include "Value.h"

namespace LLVM
{

ref class LLVMContext;
ref class GlobalValue;
ref class StructType;
ref class FunctionType;
ref class AttributeSet;
ref class Constant;
ref class Function;
ref class GlobalVariable;
ref class Type;
ref class GlobalAlias;
ref class NamedMDNode;
ref class Value;
ref class MDNode;
ref class GVMaterializer;
ref class ValueSymbolTable;
ref class raw_ostream;
ref class AssemblyAnnotationWriter;

public ref class Module
{
public:
	enum class Endianness	{ AnyEndianness, LittleEndian, BigEndian };
	enum class PointerSize
	{ AnyPointerSize, Pointer32, Pointer64 };
	enum class ModFlagBehavior
	{
		Error = 1,
		Warning	= 2,
		Require = 3,
		Override = 4,
		Append = 5,
		AppendUnique = 6
	};
	value class ModuleFlagEntry
	{
	public:
		ModFlagBehavior ^Behavior;
		MDString ^Key;
		Value ^Val;
		ModuleFlagEntry(ModFlagBehavior B, MDString ^K, Value ^V)
			: Behavior(B)
			, Key(K)
			, Val(V)
		{
		}

	internal:
		ModuleFlagEntry(llvm::Module::ModuleFlagEntry *base)
			: Behavior(safe_cast<ModFlagBehavior>(base->Behavior))
			, Key(gcnew MDString(base->Key))
			, Val(gcnew Value(base->Val))
		{
		}
	};


private:
	bool constructed;	static llvm::Module *_construct(System::String ^ModuleID, LLVMContext ^C);

internal:
	llvm::Module *base;
	Module(llvm::Module *base);

public:
	!Module();
	virtual ~Module();
	// typedef iplist<GlobalVariable> GlobalListType;
	// typedef iplist<Function> FunctionListType;
	// typedef iplist<GlobalAlias> AliasListType;
	// typedef ilist<NamedMDNode> NamedMDListType;
	// typedef GlobalListType::iterator                      global_iterator;
	// typedef GlobalListType::const_iterator          const_global_iterator;
	// typedef FunctionListType::iterator                           iterator;
	// typedef FunctionListType::const_iterator               const_iterator;
	// typedef AliasListType::iterator                        alias_iterator;
	// typedef AliasListType::const_iterator            const_alias_iterator;
	// typedef NamedMDListType::iterator             named_metadata_iterator;
	// typedef NamedMDListType::const_iterator const_named_metadata_iterator;
	Module(System::String ^ModuleID, LLVMContext ^C);
	// ~Module();
	// const std::string &getModuleIdentifier();
	// const std::string &getDataLayout();
	// const std::string &getTargetTriple();
	Module::Endianness getEndianness();
	Module::PointerSize getPointerSize();
	LLVMContext ^getContext();
	// const std::string &getModuleInlineAsm();
	void setModuleIdentifier(System::String ^ID);
	void setDataLayout(System::String ^DL);
	void setTargetTriple(System::String ^T);
	void setModuleInlineAsm(System::String ^Asm);
	void appendModuleInlineAsm(System::String ^Asm);
	GlobalValue ^getNamedValue(System::String ^Name);
	unsigned getMDKindID(System::String ^Name);
	array<System::String ^> ^getMDKindNamesArray();
	// typedef DenseMap<StructType*, unsigned, DenseMapInfo<StructType*> >;
	//                  NumeredTypesMapTy;
	StructType ^getTypeByName(System::String ^Name);
	Constant ^getOrInsertFunction(System::String ^Name, FunctionType ^T, AttributeSet ^AttributeList);
	Constant ^getOrInsertFunction(System::String ^Name, FunctionType ^T);
	// Constant *getOrInsertFunction(StringRef Name, AttributeSet AttributeList, Type *RetTy, ...)  END_WITH_NULL;
	// Constant *getOrInsertFunction(StringRef Name, Type *RetTy, ...);
	//   END_WITH_NULL;
	Constant ^getOrInsertTargetIntrinsic(System::String ^Name, FunctionType ^Ty, AttributeSet ^AttributeList);
	Function ^getFunction(System::String ^Name);
	GlobalVariable ^getGlobalVariable(System::String ^Name);
	GlobalVariable ^getGlobalVariable(System::String ^Name, bool AllowInternal);
	GlobalVariable ^getNamedGlobal(System::String ^Name);
	Constant ^getOrInsertGlobal(System::String ^Name, Type ^Ty);
	GlobalAlias ^getNamedAlias(System::String ^Name);
	NamedMDNode ^getNamedMetadata(System::String ^Name);
	NamedMDNode ^getOrInsertNamedMetadata(System::String ^Name);
	void eraseNamedMetadata(NamedMDNode ^NMD);
	array<Module::ModuleFlagEntry ^> ^getModuleFlagsMetadataArray();
	NamedMDNode ^getModuleFlagsMetadata();
	NamedMDNode ^getOrInsertModuleFlagsMetadata();
	void addModuleFlag(ModFlagBehavior Behavior, System::String ^Key, Value ^Val);
	void addModuleFlag(ModFlagBehavior Behavior, System::String ^Key, uint32_t Val);
	void addModuleFlag(MDNode ^Node);
	void setMaterializer(GVMaterializer ^GVM);
	GVMaterializer ^getMaterializer();
	bool isMaterializable(GlobalValue ^GV);
	bool isDematerializable(GlobalValue ^GV);
	bool Materialize(GlobalValue ^GV);
	void Dematerialize(GlobalValue ^GV);
	bool MaterializeAll();
	bool MaterializeAllPermanently();
	// const GlobalListType   &getGlobalList();
	System::Collections::Generic::List<GlobalVariable ^> ^getGlobalList();
	// static iplist<GlobalVariable> Module::*getSublistAccess(GlobalVariable*);
	// const FunctionListType &getFunctionList();
	System::Collections::Generic::List<Function ^> ^getFunctionList();
	// static iplist<Function> Module::*getSublistAccess(Function*);
	// const AliasListType    &getAliasList();
	System::Collections::Generic::List<GlobalAlias ^> ^getAliasList();
	// static iplist<GlobalAlias> Module::*getSublistAccess(GlobalAlias*);
	// const NamedMDListType  &getNamedMDList();
	System::Collections::Generic::List<NamedMDNode ^> ^getNamedMDList();
	// static ilist<NamedMDNode> Module::*getSublistAccess(NamedMDNode*);
	// const ValueSymbolTable &getValueSymbolTable();
	ValueSymbolTable ^getValueSymbolTable();
	// global_iterator       global_begin();
	// const_global_iterator global_begin();
	// global_iterator       global_end();
	// const_global_iterator global_end();
	bool global_empty();
	// iterator                begin();
	// const_iterator          begin();
	// iterator                end();
	// const_iterator          end();
	size_t size();
	bool empty();
	// alias_iterator       alias_begin();
	// const_alias_iterator alias_begin();
	// alias_iterator       alias_end();
	// const_alias_iterator alias_end();
	size_t alias_size();
	bool alias_empty();
	// named_metadata_iterator named_metadata_begin();
	// const_named_metadata_iterator named_metadata_begin();
	// named_metadata_iterator named_metadata_end();
	// const_named_metadata_iterator named_metadata_end();
	size_t named_metadata_size();
	bool named_metadata_empty();
	void print(raw_ostream ^OS, AssemblyAnnotationWriter ^AAW);
	void dump();
	void dropAllReferences();
};

}
