#include "Metadata.h"
#include "llvm/ADT/StringRef.h"
#include "Value.h"
#include "llvm/ADT/ArrayRef.h"
#include "LLVMContext.h"
#include "Value.h"
#include "Module.h"
#include "Metadata.h"
#include "raw_ostream.h"
#include "AssemblyAnnotationWriter.h"
#include <msclr/marshal.h>
#include "utils.h"

using namespace LLVM;

MDString::MDString(llvm::MDString *base)
	: base(base)
	, Value(base)
{
}
inline MDString ^MDString::_wrap(llvm::MDString *base)
{
	return base ? gcnew MDString(base) : nullptr;
}
MDString::!MDString()
{
}
MDString::~MDString()
{
	this->!MDString();
}
MDString ^MDString::get(LLVMContext ^Context, System::String ^Str)
{
	msclr::interop::marshal_context ctx;
	return MDString::_wrap(llvm::MDString::get(*Context->base, ctx.marshal_as<const char *>(Str)));
}
System::String ^MDString::getString()
{
	return utils::manage_str(base->getString());
}
unsigned MDString::getLength()
{
	return base->getLength();
}
bool MDString::classof(Value ^V)
{
	return llvm::MDString::classof(V->base);
}


MDNode::MDNode(llvm::MDNode *base)
	: base(base)
	, Value(base)
{
}
inline MDNode ^MDNode::_wrap(llvm::MDNode *base)
{
	return base ? gcnew MDNode(base) : nullptr;
}
MDNode::!MDNode()
{
}
MDNode::~MDNode()
{
	this->!MDNode();
}
MDNode ^MDNode::get(LLVMContext ^Context, array<Value ^> ^Vals)
{
	llvm::Value **b = new llvm::Value*[Vals->Length];
	for (int i = 0; i < Vals->Length; i++)
		b[i] = Vals[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, Vals->Length);
	auto r = MDNode::_wrap(llvm::MDNode::get(*Context->base, brr));
	delete b;
	return r;
}
MDNode ^MDNode::getWhenValsUnresolved(LLVMContext ^Context, array<Value ^> ^Vals, bool isFunctionLocal)
{
	llvm::Value **b = new llvm::Value*[Vals->Length];
	for (int i = 0; i < Vals->Length; i++)
		b[i] = Vals[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, Vals->Length);
	auto r = MDNode::_wrap(llvm::MDNode::getWhenValsUnresolved(*Context->base, brr, isFunctionLocal));
	delete b;
	return r;
}
MDNode ^MDNode::getIfExists(LLVMContext ^Context, array<Value ^> ^Vals)
{
	llvm::Value **b = new llvm::Value*[Vals->Length];
	for (int i = 0; i < Vals->Length; i++)
		b[i] = Vals[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, Vals->Length);
	auto r = MDNode::_wrap(llvm::MDNode::getIfExists(*Context->base, brr));
	delete b;
	return r;
}
MDNode ^MDNode::getTemporary(LLVMContext ^Context, array<Value ^> ^Vals)
{
	llvm::Value **b = new llvm::Value*[Vals->Length];
	for (int i = 0; i < Vals->Length; i++)
		b[i] = Vals[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, Vals->Length);
	auto r = MDNode::_wrap(llvm::MDNode::getTemporary(*Context->base, brr));
	delete b;
	return r;
}
void MDNode::deleteTemporary(MDNode ^N)
{
	llvm::MDNode::deleteTemporary(N->base);
}
void MDNode::replaceOperandWith(unsigned i, Value ^NewVal)
{
	base->replaceOperandWith(i, NewVal->base);
}
Value ^MDNode::getOperand(unsigned i)
{
	return Value::_wrap(base->getOperand(i));
}
unsigned MDNode::getNumOperands()
{
	return base->getNumOperands();
}
bool MDNode::isFunctionLocal()
{
	return base->isFunctionLocal();
}
bool MDNode::classof(Value ^V)
{
	return llvm::MDNode::classof(V->base);
}
MDNode ^MDNode::getMostGenericTBAA(MDNode ^A, MDNode ^B)
{
	return MDNode::_wrap(llvm::MDNode::getMostGenericTBAA(A->base, B->base));
}
MDNode ^MDNode::getMostGenericFPMath(MDNode ^A, MDNode ^B)
{
	return MDNode::_wrap(llvm::MDNode::getMostGenericFPMath(A->base, B->base));
}
MDNode ^MDNode::getMostGenericRange(MDNode ^A, MDNode ^B)
{
	return MDNode::_wrap(llvm::MDNode::getMostGenericRange(A->base, B->base));
}


NamedMDNode::NamedMDNode(llvm::NamedMDNode *base)
	: base(base)
{
}
inline NamedMDNode ^NamedMDNode::_wrap(llvm::NamedMDNode *base)
{
	return base ? gcnew NamedMDNode(base) : nullptr;
}
NamedMDNode::!NamedMDNode()
{
}
NamedMDNode::~NamedMDNode()
{
	this->!NamedMDNode();
}
void NamedMDNode::eraseFromParent()
{
	base->eraseFromParent();
}
void NamedMDNode::dropAllReferences()
{
	base->dropAllReferences();
}
inline Module ^NamedMDNode::getParent()
{
	return Module::_wrap(base->getParent());
}
MDNode ^NamedMDNode::getOperand(unsigned i)
{
	return MDNode::_wrap(base->getOperand(i));
}
unsigned NamedMDNode::getNumOperands()
{
	return base->getNumOperands();
}
void NamedMDNode::addOperand(MDNode ^M)
{
	base->addOperand(M->base);
}
System::String ^NamedMDNode::getName()
{
	return utils::manage_str(base->getName());
}
void NamedMDNode::print(raw_ostream ^ROS)
{
	base->print(*ROS->base);
}
void NamedMDNode::print(raw_ostream ^ROS, AssemblyAnnotationWriter ^AAW)
{
	base->print(*ROS->base, AAW->base);
}
void NamedMDNode::dump()
{
	base->dump();
}
