#include "MDBuilder.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/ArrayRef.h"
#include "LLVMContext.h"
#include "Metadata.h"
#include <msclr/marshal.h>
#include "utils.h"

using namespace LLVM;

MDBuilder::MDBuilder(llvm::MDBuilder *base)
	: base(base)
	, constructed(false)
{
}
inline MDBuilder ^MDBuilder::_wrap(llvm::MDBuilder *base)
{
	return base ? gcnew MDBuilder(base) : nullptr;
}
MDBuilder::!MDBuilder()
{
	if (constructed)
	{
		delete base;
	}
}
MDBuilder::~MDBuilder()
{
	this->!MDBuilder();
}
MDBuilder::MDBuilder(LLVMContext ^context)
	: base(new llvm::MDBuilder(*context->base))
	, constructed(true)
{
}
MDString ^MDBuilder::createString(System::String ^Str)
{
	msclr::interop::marshal_context ctx;
	return MDString::_wrap(base->createString(ctx.marshal_as<const char *>(Str)));
}
MDNode ^MDBuilder::createFPMath(float Accuracy)
{
	return MDNode::_wrap(base->createFPMath(Accuracy));
}
MDNode ^MDBuilder::createBranchWeights(uint32_t TrueWeight, uint32_t FalseWeight)
{
	return MDNode::_wrap(base->createBranchWeights(TrueWeight, FalseWeight));
}
MDNode ^MDBuilder::createBranchWeights(array<uint32_t> ^Weights)
{
	auto r = MDNode::_wrap(base->createBranchWeights(utils::unmanage_array(Weights)));
	return r;
}
MDNode ^MDBuilder::createAnonymousTBAARoot()
{
	return MDNode::_wrap(base->createAnonymousTBAARoot());
}
MDNode ^MDBuilder::createTBAARoot(System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return MDNode::_wrap(base->createTBAARoot(ctx.marshal_as<const char *>(Name)));
}
MDNode ^MDBuilder::createTBAANode(System::String ^Name, MDNode ^Parent)
{
	msclr::interop::marshal_context ctx;
	return MDNode::_wrap(base->createTBAANode(ctx.marshal_as<const char *>(Name), Parent->base));
}
MDNode ^MDBuilder::createTBAANode(System::String ^Name, MDNode ^Parent, bool isConstant)
{
	msclr::interop::marshal_context ctx;
	return MDNode::_wrap(base->createTBAANode(ctx.marshal_as<const char *>(Name), Parent->base, isConstant));
}
MDNode ^MDBuilder::createTBAAScalarTypeNode(System::String ^Name, MDNode ^Parent)
{
	msclr::interop::marshal_context ctx;
	return MDNode::_wrap(base->createTBAAScalarTypeNode(ctx.marshal_as<const char *>(Name), Parent->base));
}
MDNode ^MDBuilder::createTBAAScalarTypeNode(System::String ^Name, MDNode ^Parent, uint64_t Offset)
{
	msclr::interop::marshal_context ctx;
	return MDNode::_wrap(base->createTBAAScalarTypeNode(ctx.marshal_as<const char *>(Name), Parent->base, Offset));
}
MDNode ^MDBuilder::createTBAAStructTagNode(MDNode ^BaseType, MDNode ^AccessType, uint64_t Offset)
{
	return MDNode::_wrap(base->createTBAAStructTagNode(BaseType->base, AccessType->base, Offset));
}
