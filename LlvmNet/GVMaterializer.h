#pragma once
#include "llvm/GVMaterializer.h"

namespace LLVM
{

ref class GlobalValue;
ref class Module;

public ref class GVMaterializer
{
internal:
	llvm::GVMaterializer *base;
	GVMaterializer(llvm::GVMaterializer *base);

public:
	!GVMaterializer();
	virtual ~GVMaterializer();
	// virtual ~GVMaterializer();
	// virtual bool isMaterializable(const GlobalValue *GV) const = 0;
	// virtual bool isDematerializable(const GlobalValue *GV) const = 0;
	virtual bool Materialize(GlobalValue ^GV);
	virtual void Dematerialize(GlobalValue ^value);
	virtual bool MaterializeModule(Module ^M);
};

}
