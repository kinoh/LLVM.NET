#pragma once
#using <mscorlib.dll>
#include "llvm/PassSupport.h"

namespace LLVM
{

ref class Pass;

public ref class PassInfo
{
private:
	bool constructed;
	//static llvm::PassInfo *_construct(System::String ^name, System::String ^arg, void *pi, NormalCtor_t normal, bool isCFGOnly, bool is_analysis);
	static llvm::PassInfo *_construct(System::String ^name, void *pi);

internal:
	llvm::PassInfo *base;
	PassInfo(llvm::PassInfo *base);

public:
	!PassInfo();
	virtual ~PassInfo();
	// typedef Pass *(*NormalCtor_t)();
	//PassInfo(System::String ^name, System::String ^arg, void *pi, NormalCtor_t normal, bool isCFGOnly, bool is_analysis);
	//   : PassName(name), PassArgument(arg), PassID(pi), IsCFGOnlyPass(isCFGOnly), IsAnalysis(is_analysis), IsAnalysisGroup(false), NormalCtor(normal);
	PassInfo(System::String ^name, void *pi);
	//   : PassName(name), PassArgument(""), PassID(pi), IsCFGOnlyPass(false), IsAnalysis(false), IsAnalysisGroup(true), NormalCtor(0);
	System::String ^getPassName();
	System::String ^getPassArgument();
	// const void *getTypeInfo();
	bool isPassID(void *IDPtr);
	bool isAnalysisGroup();
	bool isAnalysis();
	bool isCFGOnlyPass();
	//NormalCtor_t getNormalCtor();
	//void setNormalCtor(NormalCtor_t Ctor);
	Pass ^createPass();
	void addInterfaceImplemented(PassInfo ^ItfPI);
	// const std::vector<const PassInfo *> &getInterfacesImplemented();
};


public ref class RegisterAGBase
	: public PassInfo
{
private:
	bool constructed;	static llvm::RegisterAGBase *_construct(System::String ^Name, void *InterfaceID);
	static llvm::RegisterAGBase *_construct(System::String ^Name, void *InterfaceID, void *PassID);
	static llvm::RegisterAGBase *_construct(System::String ^Name, void *InterfaceID, void *PassID, bool isDefault);

internal:
	llvm::RegisterAGBase *base;
	RegisterAGBase(llvm::RegisterAGBase *base);

public:
	!RegisterAGBase();
	virtual ~RegisterAGBase();
	RegisterAGBase(System::String ^Name, void *InterfaceID);
	RegisterAGBase(System::String ^Name, void *InterfaceID, void *PassID);
	RegisterAGBase(System::String ^Name, void *InterfaceID, void *PassID, bool isDefault);
};

ref class PassRegistrationListener
{
internal:
	llvm::PassRegistrationListener *base;
	PassRegistrationListener(llvm::PassRegistrationListener *base);

public:
	!PassRegistrationListener();
	virtual ~PassRegistrationListener();
	virtual void passRegistered(const PassInfo ^);
	void enumeratePasses();
	virtual void passEnumerate(const PassInfo ^);
};

}
