#include "GVMaterializer.h"
#include "GlobalValue.h"
#include "Module.h"

using namespace LLVM;

GVMaterializer::GVMaterializer(llvm::GVMaterializer *base)
	: base(base)
{
}
inline GVMaterializer ^GVMaterializer::_wrap(llvm::GVMaterializer *base)
{
	return base ? gcnew GVMaterializer(base) : nullptr;
}
GVMaterializer::!GVMaterializer()
{
}
GVMaterializer::~GVMaterializer()
{
	this->!GVMaterializer();
}
bool GVMaterializer::Materialize(GlobalValue ^GV)
{
	return base->Materialize(GV->base);
}
void GVMaterializer::Dematerialize(GlobalValue ^value)
{
	base->Dematerialize(value->base);
}
bool GVMaterializer::MaterializeModule(Module ^M)
{
	return base->MaterializeModule(M->base);
}
