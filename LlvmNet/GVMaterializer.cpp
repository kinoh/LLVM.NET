#include "GVMaterializer.h"
#include "GlobalValue.h"
#include "Module.h"

using namespace LLVM;

GVMaterializer::GVMaterializer(llvm::GVMaterializer *base)
	: base(base)
{
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
bool GVMaterializer::MaterializeModule(Module ^M)
{
	return base->MaterializeModule(M->base);
}
