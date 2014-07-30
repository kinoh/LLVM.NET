#pragma once
#include "llvm/PassRegistry.h"

namespace LLVM
{

ref class PassInfo;
ref class PassRegistrationListener;

public ref class PassRegistry
{
private:
	bool constructed;
internal:
	llvm::PassRegistry *base;
	PassRegistry(llvm::PassRegistry *base);

public:
	!PassRegistry();
	virtual ~PassRegistry();
	PassRegistry();
	static PassRegistry ^getPassRegistry();
	// const PassInfo *getPassInfo(const void *TI);
	// const PassInfo *getPassInfo(StringRef Arg);
	void registerPass(PassInfo ^PI);
	void registerPass(PassInfo ^PI, bool ShouldFree);
	void unregisterPass(PassInfo ^PI);
	void registerAnalysisGroup(void *InterfaceID, void *PassID, PassInfo ^Registeree, bool isDefault);
	void registerAnalysisGroup(void *InterfaceID, void *PassID, PassInfo ^Registeree, bool isDefault, bool ShouldFree);
	void enumerateWith(PassRegistrationListener ^L);
	void addRegistrationListener(PassRegistrationListener ^L);
	void removeRegistrationListener(PassRegistrationListener ^L);
};

}
