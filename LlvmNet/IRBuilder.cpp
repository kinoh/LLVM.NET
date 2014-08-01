#include "IRBuilder.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/Twine.h"
#include "llvm/ADT/ArrayRef.h"
#include "Instruction.h"
#include "InstrTypes.h"
#include "LLVMContext.h"
#include "BasicBlock.h"
#include "Instruction.h"
#include "Use.h"
#include "DebugLoc.h"
#include "Type.h"
#include "Value.h"
#include "Constants.h"
#include "DerivedTypes.h"
#include "Instructions.h"
#include "Metadata.h"
#include "Operator.h"
#include "Constant.h"
#include <msclr/marshal.h>
#include "utils.h"

using namespace LLVM;

IRBuilderBase::IRBuilderBase(llvm::IRBuilderBase *base)
	: base(base)
	, constructed(false)
{
}
inline IRBuilderBase ^IRBuilderBase::_wrap(llvm::IRBuilderBase *base)
{
	return base ? gcnew IRBuilderBase(base) : nullptr;
}
IRBuilderBase::!IRBuilderBase()
{
	if (constructed)
	{
		delete base;
	}
}
IRBuilderBase::~IRBuilderBase()
{
	this->!IRBuilderBase();
}
IRBuilderBase::IRBuilderBase(LLVMContext ^context)
	: base(new llvm::IRBuilderBase(*context->base))
	, constructed(true)
{
}
void IRBuilderBase::ClearInsertionPoint()
{
	base->ClearInsertionPoint();
}
BasicBlock ^IRBuilderBase::GetInsertBlock()
{
	return BasicBlock::_wrap(base->GetInsertBlock());
}
LLVMContext ^IRBuilderBase::getContext()
{
	return LLVMContext::_wrap(&base->getContext());
}
void IRBuilderBase::SetInsertPoint(BasicBlock ^TheBB)
{
	base->SetInsertPoint(TheBB->base);
}
void IRBuilderBase::SetInsertPoint(Instruction ^I)
{
	base->SetInsertPoint(I->base);
}
void IRBuilderBase::SetInsertPoint(Use ^U)
{
	base->SetInsertPoint(*U->base);
}
void IRBuilderBase::SetCurrentDebugLocation(DebugLoc ^L)
{
	base->SetCurrentDebugLocation(*L->base);
}
void IRBuilderBase::DisableDebugLocations()
{
	base->DisableDebugLocations();
}
void IRBuilderBase::EnableDebugLocations()
{
	base->EnableDebugLocations();
}
DebugLoc ^IRBuilderBase::getCurrentDebugLocation()
{
	return DebugLoc::_wrap(&base->getCurrentDebugLocation());
}
void IRBuilderBase::SetInstDebugLocation(Instruction ^I)
{
	base->SetInstDebugLocation(I->base);
}
Type ^IRBuilderBase::getCurrentFunctionReturnType()
{
	return Type::_wrap(base->getCurrentFunctionReturnType());
}
Value ^IRBuilderBase::CreateGlobalString(System::String ^Str)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateGlobalString(ctx.marshal_as<const char *>(Str)));
}
Value ^IRBuilderBase::CreateGlobalString(System::String ^Str, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateGlobalString(ctx.marshal_as<const char *>(Str), ctx.marshal_as<const char *>(Name)));
}
ConstantInt ^IRBuilderBase::getInt1(bool V)
{
	return ConstantInt::_wrap(base->getInt1(V));
}
ConstantInt ^IRBuilderBase::getTrue()
{
	return ConstantInt::_wrap(base->getTrue());
}
ConstantInt ^IRBuilderBase::getFalse()
{
	return ConstantInt::_wrap(base->getFalse());
}
ConstantInt ^IRBuilderBase::getInt8(uint8_t C)
{
	return ConstantInt::_wrap(base->getInt8(C));
}
ConstantInt ^IRBuilderBase::getInt16(uint16_t C)
{
	return ConstantInt::_wrap(base->getInt16(C));
}
ConstantInt ^IRBuilderBase::getInt32(uint32_t C)
{
	return ConstantInt::_wrap(base->getInt32(C));
}
ConstantInt ^IRBuilderBase::getInt64(uint64_t C)
{
	return ConstantInt::_wrap(base->getInt64(C));
}
IntegerType ^IRBuilderBase::getInt1Ty()
{
	return IntegerType::_wrap(base->getInt1Ty());
}
IntegerType ^IRBuilderBase::getInt8Ty()
{
	return IntegerType::_wrap(base->getInt8Ty());
}
IntegerType ^IRBuilderBase::getInt16Ty()
{
	return IntegerType::_wrap(base->getInt16Ty());
}
IntegerType ^IRBuilderBase::getInt32Ty()
{
	return IntegerType::_wrap(base->getInt32Ty());
}
IntegerType ^IRBuilderBase::getInt64Ty()
{
	return IntegerType::_wrap(base->getInt64Ty());
}
Type ^IRBuilderBase::getFloatTy()
{
	return Type::_wrap(base->getFloatTy());
}
Type ^IRBuilderBase::getDoubleTy()
{
	return Type::_wrap(base->getDoubleTy());
}
Type ^IRBuilderBase::getVoidTy()
{
	return Type::_wrap(base->getVoidTy());
}
PointerType ^IRBuilderBase::getInt8PtrTy()
{
	return PointerType::_wrap(base->getInt8PtrTy());
}
PointerType ^IRBuilderBase::getInt8PtrTy(unsigned AddrSpace)
{
	return PointerType::_wrap(base->getInt8PtrTy(AddrSpace));
}
CallInst ^IRBuilderBase::CreateMemSet(Value ^Ptr, Value ^Val, uint64_t Size, unsigned Align)
{
	return CallInst::_wrap(base->CreateMemSet(Ptr->base, Val->base, Size, Align));
}
CallInst ^IRBuilderBase::CreateMemSet(Value ^Ptr, Value ^Val, uint64_t Size, unsigned Align, bool isVolatile)
{
	return CallInst::_wrap(base->CreateMemSet(Ptr->base, Val->base, Size, Align, isVolatile));
}
CallInst ^IRBuilderBase::CreateMemSet(Value ^Ptr, Value ^Val, uint64_t Size, unsigned Align, bool isVolatile, MDNode ^TBAATag)
{
	return CallInst::_wrap(base->CreateMemSet(Ptr->base, Val->base, Size, Align, isVolatile, TBAATag->base));
}
CallInst ^IRBuilderBase::CreateMemSet(Value ^Ptr, Value ^Val, Value ^Size, unsigned Align)
{
	return CallInst::_wrap(base->CreateMemSet(Ptr->base, Val->base, Size->base, Align));
}
CallInst ^IRBuilderBase::CreateMemSet(Value ^Ptr, Value ^Val, Value ^Size, unsigned Align, bool isVolatile)
{
	return CallInst::_wrap(base->CreateMemSet(Ptr->base, Val->base, Size->base, Align, isVolatile));
}
CallInst ^IRBuilderBase::CreateMemSet(Value ^Ptr, Value ^Val, Value ^Size, unsigned Align, bool isVolatile, MDNode ^TBAATag)
{
	return CallInst::_wrap(base->CreateMemSet(Ptr->base, Val->base, Size->base, Align, isVolatile, TBAATag->base));
}
CallInst ^IRBuilderBase::CreateMemCpy(Value ^Dst, Value ^Src, uint64_t Size, unsigned Align)
{
	return CallInst::_wrap(base->CreateMemCpy(Dst->base, Src->base, Size, Align));
}
CallInst ^IRBuilderBase::CreateMemCpy(Value ^Dst, Value ^Src, uint64_t Size, unsigned Align, bool isVolatile)
{
	return CallInst::_wrap(base->CreateMemCpy(Dst->base, Src->base, Size, Align, isVolatile));
}
CallInst ^IRBuilderBase::CreateMemCpy(Value ^Dst, Value ^Src, uint64_t Size, unsigned Align, bool isVolatile, MDNode ^TBAATag)
{
	return CallInst::_wrap(base->CreateMemCpy(Dst->base, Src->base, Size, Align, isVolatile, TBAATag->base));
}
CallInst ^IRBuilderBase::CreateMemCpy(Value ^Dst, Value ^Src, uint64_t Size, unsigned Align, bool isVolatile, MDNode ^TBAATag, MDNode ^TBAAStructTag)
{
	return CallInst::_wrap(base->CreateMemCpy(Dst->base, Src->base, Size, Align, isVolatile, TBAATag->base, TBAAStructTag->base));
}
CallInst ^IRBuilderBase::CreateMemCpy(Value ^Dst, Value ^Src, Value ^Size, unsigned Align)
{
	return CallInst::_wrap(base->CreateMemCpy(Dst->base, Src->base, Size->base, Align));
}
CallInst ^IRBuilderBase::CreateMemCpy(Value ^Dst, Value ^Src, Value ^Size, unsigned Align, bool isVolatile)
{
	return CallInst::_wrap(base->CreateMemCpy(Dst->base, Src->base, Size->base, Align, isVolatile));
}
CallInst ^IRBuilderBase::CreateMemCpy(Value ^Dst, Value ^Src, Value ^Size, unsigned Align, bool isVolatile, MDNode ^TBAATag)
{
	return CallInst::_wrap(base->CreateMemCpy(Dst->base, Src->base, Size->base, Align, isVolatile, TBAATag->base));
}
CallInst ^IRBuilderBase::CreateMemCpy(Value ^Dst, Value ^Src, Value ^Size, unsigned Align, bool isVolatile, MDNode ^TBAATag, MDNode ^TBAAStructTag)
{
	return CallInst::_wrap(base->CreateMemCpy(Dst->base, Src->base, Size->base, Align, isVolatile, TBAATag->base, TBAAStructTag->base));
}
CallInst ^IRBuilderBase::CreateMemMove(Value ^Dst, Value ^Src, uint64_t Size, unsigned Align)
{
	return CallInst::_wrap(base->CreateMemMove(Dst->base, Src->base, Size, Align));
}
CallInst ^IRBuilderBase::CreateMemMove(Value ^Dst, Value ^Src, uint64_t Size, unsigned Align, bool isVolatile)
{
	return CallInst::_wrap(base->CreateMemMove(Dst->base, Src->base, Size, Align, isVolatile));
}
CallInst ^IRBuilderBase::CreateMemMove(Value ^Dst, Value ^Src, uint64_t Size, unsigned Align, bool isVolatile, MDNode ^TBAATag)
{
	return CallInst::_wrap(base->CreateMemMove(Dst->base, Src->base, Size, Align, isVolatile, TBAATag->base));
}
CallInst ^IRBuilderBase::CreateMemMove(Value ^Dst, Value ^Src, Value ^Size, unsigned Align)
{
	return CallInst::_wrap(base->CreateMemMove(Dst->base, Src->base, Size->base, Align));
}
CallInst ^IRBuilderBase::CreateMemMove(Value ^Dst, Value ^Src, Value ^Size, unsigned Align, bool isVolatile)
{
	return CallInst::_wrap(base->CreateMemMove(Dst->base, Src->base, Size->base, Align, isVolatile));
}
CallInst ^IRBuilderBase::CreateMemMove(Value ^Dst, Value ^Src, Value ^Size, unsigned Align, bool isVolatile, MDNode ^TBAATag)
{
	return CallInst::_wrap(base->CreateMemMove(Dst->base, Src->base, Size->base, Align, isVolatile, TBAATag->base));
}
CallInst ^IRBuilderBase::CreateLifetimeStart(Value ^Ptr)
{
	return CallInst::_wrap(base->CreateLifetimeStart(Ptr->base));
}
CallInst ^IRBuilderBase::CreateLifetimeStart(Value ^Ptr, ConstantInt ^Size)
{
	return CallInst::_wrap(base->CreateLifetimeStart(Ptr->base, Size->base));
}
CallInst ^IRBuilderBase::CreateLifetimeEnd(Value ^Ptr)
{
	return CallInst::_wrap(base->CreateLifetimeEnd(Ptr->base));
}
CallInst ^IRBuilderBase::CreateLifetimeEnd(Value ^Ptr, ConstantInt ^Size)
{
	return CallInst::_wrap(base->CreateLifetimeEnd(Ptr->base, Size->base));
}


IRBuilder::IRBuilder(llvm::IRBuilder<> *base)
	: base(base)
	, IRBuilderBase(base)
	, constructed(false)
{
}
inline IRBuilder ^IRBuilder::_wrap(llvm::IRBuilder<> *base)
{
	return base ? gcnew IRBuilder(base) : nullptr;
}
IRBuilder::!IRBuilder()
{
	if (constructed)
	{
		delete base;
	}
}
IRBuilder::~IRBuilder()
{
	this->!IRBuilder();
}
IRBuilder::IRBuilder(LLVMContext ^C)
	: base(new llvm::IRBuilder<>(*C->base))
	, IRBuilderBase(base)
	, constructed(true)
{
}
IRBuilder::IRBuilder(LLVMContext ^C, MDNode ^FPMathTag)
	: base(new llvm::IRBuilder<>(*C->base, FPMathTag->base))
	, IRBuilderBase(base)
	, constructed(true)
{
}
IRBuilder::IRBuilder(BasicBlock ^TheBB)
	: base(new llvm::IRBuilder<>(TheBB->base))
	, IRBuilderBase(base)
	, constructed(true)
{
}
IRBuilder::IRBuilder(BasicBlock ^TheBB, MDNode ^FPMathTag)
	: base(new llvm::IRBuilder<>(TheBB->base, FPMathTag->base))
	, IRBuilderBase(base)
	, constructed(true)
{
}
IRBuilder::IRBuilder(Instruction ^IP)
	: base(new llvm::IRBuilder<>(IP->base))
	, IRBuilderBase(base)
	, constructed(true)
{
}
IRBuilder::IRBuilder(Instruction ^IP, MDNode ^FPMathTag)
	: base(new llvm::IRBuilder<>(IP->base, FPMathTag->base))
	, IRBuilderBase(base)
	, constructed(true)
{
}
IRBuilder::IRBuilder(Use ^U)
	: base(new llvm::IRBuilder<>(*U->base))
	, IRBuilderBase(base)
	, constructed(true)
{
}
IRBuilder::IRBuilder(Use ^U, MDNode ^FPMathTag)
	: base(new llvm::IRBuilder<>(*U->base, FPMathTag->base))
	, IRBuilderBase(base)
	, constructed(true)
{
}
MDNode ^IRBuilder::getDefaultFPMathTag()
{
	return MDNode::_wrap(base->getDefaultFPMathTag());
}
FastMathFlags ^IRBuilder::getFastMathFlags()
{
	return FastMathFlags::_wrap(&base->getFastMathFlags());
}
void IRBuilder::clearFastMathFlags()
{
	base->clearFastMathFlags();
}
void IRBuilder::SetDefaultFPMathTag(MDNode ^FPMathTag)
{
	base->SetDefaultFPMathTag(FPMathTag->base);
}
void IRBuilder::SetFastMathFlags(FastMathFlags ^NewFMF)
{
	base->SetFastMathFlags(*NewFMF->base);
}
bool IRBuilder::isNamePreserving()
{
	return base->isNamePreserving();
}
Constant ^IRBuilder::Insert(Constant ^C)
{
	return Constant::_wrap(base->Insert(C->base));
}
Constant ^IRBuilder::Insert(Constant ^C, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Constant::_wrap(base->Insert(C->base, ctx.marshal_as<const char *>(Name)));
}
ReturnInst ^IRBuilder::CreateRetVoid()
{
	return ReturnInst::_wrap(base->CreateRetVoid());
}
ReturnInst ^IRBuilder::CreateRet(Value ^V)
{
	return ReturnInst::_wrap(base->CreateRet(V->base));
}
BranchInst ^IRBuilder::CreateBr(BasicBlock ^Dest)
{
	return BranchInst::_wrap(base->CreateBr(Dest->base));
}
BranchInst ^IRBuilder::CreateCondBr(Value ^Cond, BasicBlock ^True, BasicBlock ^False)
{
	return BranchInst::_wrap(base->CreateCondBr(Cond->base, True->base, False->base));
}
BranchInst ^IRBuilder::CreateCondBr(Value ^Cond, BasicBlock ^True, BasicBlock ^False, MDNode ^BranchWeights)
{
	return BranchInst::_wrap(base->CreateCondBr(Cond->base, True->base, False->base, BranchWeights->base));
}
SwitchInst ^IRBuilder::CreateSwitch(Value ^V, BasicBlock ^Dest)
{
	return SwitchInst::_wrap(base->CreateSwitch(V->base, Dest->base));
}
SwitchInst ^IRBuilder::CreateSwitch(Value ^V, BasicBlock ^Dest, unsigned NumCases)
{
	return SwitchInst::_wrap(base->CreateSwitch(V->base, Dest->base, NumCases));
}
SwitchInst ^IRBuilder::CreateSwitch(Value ^V, BasicBlock ^Dest, unsigned NumCases, MDNode ^BranchWeights)
{
	return SwitchInst::_wrap(base->CreateSwitch(V->base, Dest->base, NumCases, BranchWeights->base));
}
IndirectBrInst ^IRBuilder::CreateIndirectBr(Value ^Addr)
{
	return IndirectBrInst::_wrap(base->CreateIndirectBr(Addr->base));
}
IndirectBrInst ^IRBuilder::CreateIndirectBr(Value ^Addr, unsigned NumDests)
{
	return IndirectBrInst::_wrap(base->CreateIndirectBr(Addr->base, NumDests));
}
InvokeInst ^IRBuilder::CreateInvoke(Value ^Callee, BasicBlock ^NormalDest, BasicBlock ^UnwindDest)
{
	return InvokeInst::_wrap(base->CreateInvoke(Callee->base, NormalDest->base, UnwindDest->base));
}
InvokeInst ^IRBuilder::CreateInvoke(Value ^Callee, BasicBlock ^NormalDest, BasicBlock ^UnwindDest, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return InvokeInst::_wrap(base->CreateInvoke(Callee->base, NormalDest->base, UnwindDest->base, ctx.marshal_as<const char *>(Name)));
}
InvokeInst ^IRBuilder::CreateInvoke(Value ^Callee, BasicBlock ^NormalDest, BasicBlock ^UnwindDest, Value ^Arg1)
{
	return InvokeInst::_wrap(base->CreateInvoke(Callee->base, NormalDest->base, UnwindDest->base, Arg1->base));
}
InvokeInst ^IRBuilder::CreateInvoke(Value ^Callee, BasicBlock ^NormalDest, BasicBlock ^UnwindDest, Value ^Arg1, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return InvokeInst::_wrap(base->CreateInvoke(Callee->base, NormalDest->base, UnwindDest->base, Arg1->base, ctx.marshal_as<const char *>(Name)));
}
InvokeInst ^IRBuilder::CreateInvoke3(Value ^Callee, BasicBlock ^NormalDest, BasicBlock ^UnwindDest, Value ^Arg1, Value ^Arg2, Value ^Arg3)
{
	return InvokeInst::_wrap(base->CreateInvoke3(Callee->base, NormalDest->base, UnwindDest->base, Arg1->base, Arg2->base, Arg3->base));
}
InvokeInst ^IRBuilder::CreateInvoke3(Value ^Callee, BasicBlock ^NormalDest, BasicBlock ^UnwindDest, Value ^Arg1, Value ^Arg2, Value ^Arg3, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return InvokeInst::_wrap(base->CreateInvoke3(Callee->base, NormalDest->base, UnwindDest->base, Arg1->base, Arg2->base, Arg3->base, ctx.marshal_as<const char *>(Name)));
}
InvokeInst ^IRBuilder::CreateInvoke(Value ^Callee, BasicBlock ^NormalDest, BasicBlock ^UnwindDest, array<Value ^> ^Args)
{
	llvm::Value **b = new llvm::Value*[Args->Length];
	for (int i = 0; i < Args->Length; i++)
		b[i] = Args[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, Args->Length);
	auto r = InvokeInst::_wrap(base->CreateInvoke(Callee->base, NormalDest->base, UnwindDest->base, brr));
	delete b;
	return r;
}
InvokeInst ^IRBuilder::CreateInvoke(Value ^Callee, BasicBlock ^NormalDest, BasicBlock ^UnwindDest, array<Value ^> ^Args, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	llvm::Value **b = new llvm::Value*[Args->Length];
	for (int i = 0; i < Args->Length; i++)
		b[i] = Args[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, Args->Length);
	auto r = InvokeInst::_wrap(base->CreateInvoke(Callee->base, NormalDest->base, UnwindDest->base, brr, ctx.marshal_as<const char *>(Name)));
	delete b;
	return r;
}
ResumeInst ^IRBuilder::CreateResume(Value ^Exn)
{
	return ResumeInst::_wrap(base->CreateResume(Exn->base));
}
UnreachableInst ^IRBuilder::CreateUnreachable()
{
	return UnreachableInst::_wrap(base->CreateUnreachable());
}
Value ^IRBuilder::CreateAdd(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateAdd(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateAdd(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateAdd(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateAdd(Value ^LHS, Value ^RHS, System::String ^Name, bool HasNUW)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateAdd(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name), HasNUW));
}
Value ^IRBuilder::CreateAdd(Value ^LHS, Value ^RHS, System::String ^Name, bool HasNUW, bool HasNSW)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateAdd(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name), HasNUW, HasNSW));
}
Value ^IRBuilder::CreateNSWAdd(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateNSWAdd(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateNSWAdd(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateNSWAdd(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateNUWAdd(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateNUWAdd(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateNUWAdd(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateNUWAdd(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFAdd(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateFAdd(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateFAdd(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFAdd(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFAdd(Value ^LHS, Value ^RHS, System::String ^Name, MDNode ^FPMathTag)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFAdd(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name), FPMathTag->base));
}
Value ^IRBuilder::CreateSub(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateSub(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateSub(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateSub(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateSub(Value ^LHS, Value ^RHS, System::String ^Name, bool HasNUW)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateSub(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name), HasNUW));
}
Value ^IRBuilder::CreateSub(Value ^LHS, Value ^RHS, System::String ^Name, bool HasNUW, bool HasNSW)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateSub(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name), HasNUW, HasNSW));
}
Value ^IRBuilder::CreateNSWSub(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateNSWSub(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateNSWSub(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateNSWSub(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateNUWSub(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateNUWSub(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateNUWSub(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateNUWSub(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFSub(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateFSub(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateFSub(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFSub(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFSub(Value ^LHS, Value ^RHS, System::String ^Name, MDNode ^FPMathTag)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFSub(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name), FPMathTag->base));
}
Value ^IRBuilder::CreateMul(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateMul(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateMul(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateMul(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateMul(Value ^LHS, Value ^RHS, System::String ^Name, bool HasNUW)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateMul(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name), HasNUW));
}
Value ^IRBuilder::CreateMul(Value ^LHS, Value ^RHS, System::String ^Name, bool HasNUW, bool HasNSW)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateMul(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name), HasNUW, HasNSW));
}
Value ^IRBuilder::CreateNSWMul(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateNSWMul(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateNSWMul(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateNSWMul(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateNUWMul(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateNUWMul(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateNUWMul(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateNUWMul(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFMul(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateFMul(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateFMul(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFMul(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFMul(Value ^LHS, Value ^RHS, System::String ^Name, MDNode ^FPMathTag)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFMul(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name), FPMathTag->base));
}
Value ^IRBuilder::CreateUDiv(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateUDiv(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateUDiv(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateUDiv(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateUDiv(Value ^LHS, Value ^RHS, System::String ^Name, bool isExact)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateUDiv(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name), isExact));
}
Value ^IRBuilder::CreateExactUDiv(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateExactUDiv(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateExactUDiv(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateExactUDiv(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateSDiv(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateSDiv(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateSDiv(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateSDiv(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateSDiv(Value ^LHS, Value ^RHS, System::String ^Name, bool isExact)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateSDiv(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name), isExact));
}
Value ^IRBuilder::CreateExactSDiv(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateExactSDiv(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateExactSDiv(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateExactSDiv(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFDiv(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateFDiv(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateFDiv(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFDiv(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFDiv(Value ^LHS, Value ^RHS, System::String ^Name, MDNode ^FPMathTag)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFDiv(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name), FPMathTag->base));
}
Value ^IRBuilder::CreateURem(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateURem(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateURem(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateURem(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateSRem(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateSRem(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateSRem(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateSRem(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFRem(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateFRem(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateFRem(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFRem(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFRem(Value ^LHS, Value ^RHS, System::String ^Name, MDNode ^FPMathTag)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFRem(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name), FPMathTag->base));
}
Value ^IRBuilder::CreateShl(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateShl(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateShl(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateShl(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateShl(Value ^LHS, Value ^RHS, System::String ^Name, bool HasNUW)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateShl(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name), HasNUW));
}
Value ^IRBuilder::CreateShl(Value ^LHS, Value ^RHS, System::String ^Name, bool HasNUW, bool HasNSW)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateShl(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name), HasNUW, HasNSW));
}
Value ^IRBuilder::CreateShl(Value ^LHS, uint64_t RHS)
{
	return Value::_wrap(base->CreateShl(LHS->base, RHS));
}
Value ^IRBuilder::CreateShl(Value ^LHS, uint64_t RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateShl(LHS->base, RHS, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateShl(Value ^LHS, uint64_t RHS, System::String ^Name, bool HasNUW)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateShl(LHS->base, RHS, ctx.marshal_as<const char *>(Name), HasNUW));
}
Value ^IRBuilder::CreateShl(Value ^LHS, uint64_t RHS, System::String ^Name, bool HasNUW, bool HasNSW)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateShl(LHS->base, RHS, ctx.marshal_as<const char *>(Name), HasNUW, HasNSW));
}
Value ^IRBuilder::CreateLShr(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateLShr(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateLShr(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateLShr(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateLShr(Value ^LHS, Value ^RHS, System::String ^Name, bool isExact)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateLShr(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name), isExact));
}
Value ^IRBuilder::CreateLShr(Value ^LHS, uint64_t RHS)
{
	return Value::_wrap(base->CreateLShr(LHS->base, RHS));
}
Value ^IRBuilder::CreateLShr(Value ^LHS, uint64_t RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateLShr(LHS->base, RHS, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateLShr(Value ^LHS, uint64_t RHS, System::String ^Name, bool isExact)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateLShr(LHS->base, RHS, ctx.marshal_as<const char *>(Name), isExact));
}
Value ^IRBuilder::CreateAShr(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateAShr(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateAShr(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateAShr(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateAShr(Value ^LHS, Value ^RHS, System::String ^Name, bool isExact)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateAShr(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name), isExact));
}
Value ^IRBuilder::CreateAShr(Value ^LHS, uint64_t RHS)
{
	return Value::_wrap(base->CreateAShr(LHS->base, RHS));
}
Value ^IRBuilder::CreateAShr(Value ^LHS, uint64_t RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateAShr(LHS->base, RHS, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateAShr(Value ^LHS, uint64_t RHS, System::String ^Name, bool isExact)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateAShr(LHS->base, RHS, ctx.marshal_as<const char *>(Name), isExact));
}
Value ^IRBuilder::CreateAnd(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateAnd(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateAnd(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateAnd(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateAnd(Value ^LHS, uint64_t RHS)
{
	return Value::_wrap(base->CreateAnd(LHS->base, RHS));
}
Value ^IRBuilder::CreateAnd(Value ^LHS, uint64_t RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateAnd(LHS->base, RHS, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateOr(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateOr(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateOr(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateOr(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateOr(Value ^LHS, uint64_t RHS)
{
	return Value::_wrap(base->CreateOr(LHS->base, RHS));
}
Value ^IRBuilder::CreateOr(Value ^LHS, uint64_t RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateOr(LHS->base, RHS, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateXor(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateXor(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateXor(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateXor(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateXor(Value ^LHS, uint64_t RHS)
{
	return Value::_wrap(base->CreateXor(LHS->base, RHS));
}
Value ^IRBuilder::CreateXor(Value ^LHS, uint64_t RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateXor(LHS->base, RHS, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateBinOp(Instruction::BinaryOps Opc, Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateBinOp(safe_cast<llvm::Instruction::BinaryOps>(Opc), LHS->base, RHS->base));
}
Value ^IRBuilder::CreateBinOp(Instruction::BinaryOps Opc, Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateBinOp(safe_cast<llvm::Instruction::BinaryOps>(Opc), LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateNeg(Value ^V)
{
	return Value::_wrap(base->CreateNeg(V->base));
}
Value ^IRBuilder::CreateNeg(Value ^V, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateNeg(V->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateNeg(Value ^V, System::String ^Name, bool HasNUW)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateNeg(V->base, ctx.marshal_as<const char *>(Name), HasNUW));
}
Value ^IRBuilder::CreateNeg(Value ^V, System::String ^Name, bool HasNUW, bool HasNSW)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateNeg(V->base, ctx.marshal_as<const char *>(Name), HasNUW, HasNSW));
}
Value ^IRBuilder::CreateNSWNeg(Value ^V)
{
	return Value::_wrap(base->CreateNSWNeg(V->base));
}
Value ^IRBuilder::CreateNSWNeg(Value ^V, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateNSWNeg(V->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateNUWNeg(Value ^V)
{
	return Value::_wrap(base->CreateNUWNeg(V->base));
}
Value ^IRBuilder::CreateNUWNeg(Value ^V, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateNUWNeg(V->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFNeg(Value ^V)
{
	return Value::_wrap(base->CreateFNeg(V->base));
}
Value ^IRBuilder::CreateFNeg(Value ^V, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFNeg(V->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFNeg(Value ^V, System::String ^Name, MDNode ^FPMathTag)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFNeg(V->base, ctx.marshal_as<const char *>(Name), FPMathTag->base));
}
Value ^IRBuilder::CreateNot(Value ^V)
{
	return Value::_wrap(base->CreateNot(V->base));
}
Value ^IRBuilder::CreateNot(Value ^V, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateNot(V->base, ctx.marshal_as<const char *>(Name)));
}
AllocaInst ^IRBuilder::CreateAlloca(Type ^Ty)
{
	return AllocaInst::_wrap(base->CreateAlloca(Ty->base));
}
AllocaInst ^IRBuilder::CreateAlloca(Type ^Ty, Value ^ArraySize)
{
	return AllocaInst::_wrap(base->CreateAlloca(Ty->base, ArraySize->base));
}
AllocaInst ^IRBuilder::CreateAlloca(Type ^Ty, Value ^ArraySize, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return AllocaInst::_wrap(base->CreateAlloca(Ty->base, ArraySize->base, ctx.marshal_as<const char *>(Name)));
}
LoadInst ^IRBuilder::CreateLoad(Value ^Ptr, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return LoadInst::_wrap(base->CreateLoad(Ptr->base, ctx.marshal_as<const char *>(Name)));
}
LoadInst ^IRBuilder::CreateLoad(Value ^Ptr)
{
	return LoadInst::_wrap(base->CreateLoad(Ptr->base));
}
LoadInst ^IRBuilder::CreateLoad(Value ^Ptr, bool isVolatile)
{
	return LoadInst::_wrap(base->CreateLoad(Ptr->base, isVolatile));
}
LoadInst ^IRBuilder::CreateLoad(Value ^Ptr, bool isVolatile, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return LoadInst::_wrap(base->CreateLoad(Ptr->base, isVolatile, ctx.marshal_as<const char *>(Name)));
}
StoreInst ^IRBuilder::CreateStore(Value ^Val, Value ^Ptr)
{
	return StoreInst::_wrap(base->CreateStore(Val->base, Ptr->base));
}
StoreInst ^IRBuilder::CreateStore(Value ^Val, Value ^Ptr, bool isVolatile)
{
	return StoreInst::_wrap(base->CreateStore(Val->base, Ptr->base, isVolatile));
}
LoadInst ^IRBuilder::CreateAlignedLoad(Value ^Ptr, unsigned Align, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return LoadInst::_wrap(base->CreateAlignedLoad(Ptr->base, Align, ctx.marshal_as<const char *>(Name)));
}
LoadInst ^IRBuilder::CreateAlignedLoad(Value ^Ptr, unsigned Align)
{
	return LoadInst::_wrap(base->CreateAlignedLoad(Ptr->base, Align));
}
LoadInst ^IRBuilder::CreateAlignedLoad(Value ^Ptr, unsigned Align, bool isVolatile)
{
	return LoadInst::_wrap(base->CreateAlignedLoad(Ptr->base, Align, isVolatile));
}
LoadInst ^IRBuilder::CreateAlignedLoad(Value ^Ptr, unsigned Align, bool isVolatile, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return LoadInst::_wrap(base->CreateAlignedLoad(Ptr->base, Align, isVolatile, ctx.marshal_as<const char *>(Name)));
}
StoreInst ^IRBuilder::CreateAlignedStore(Value ^Val, Value ^Ptr, unsigned Align)
{
	return StoreInst::_wrap(base->CreateAlignedStore(Val->base, Ptr->base, Align));
}
StoreInst ^IRBuilder::CreateAlignedStore(Value ^Val, Value ^Ptr, unsigned Align, bool isVolatile)
{
	return StoreInst::_wrap(base->CreateAlignedStore(Val->base, Ptr->base, Align, isVolatile));
}
FenceInst ^IRBuilder::CreateFence(AtomicOrdering Ordering)
{
	return FenceInst::_wrap(base->CreateFence(safe_cast<llvm::AtomicOrdering>(Ordering)));
}
FenceInst ^IRBuilder::CreateFence(AtomicOrdering Ordering, SynchronizationScope SynchScope)
{
	return FenceInst::_wrap(base->CreateFence(safe_cast<llvm::AtomicOrdering>(Ordering), safe_cast<llvm::SynchronizationScope>(SynchScope)));
}
AtomicCmpXchgInst ^IRBuilder::CreateAtomicCmpXchg(Value ^Ptr, Value ^Cmp, Value ^New, AtomicOrdering Ordering)
{
	return AtomicCmpXchgInst::_wrap(base->CreateAtomicCmpXchg(Ptr->base, Cmp->base, New->base, safe_cast<llvm::AtomicOrdering>(Ordering)));
}
AtomicCmpXchgInst ^IRBuilder::CreateAtomicCmpXchg(Value ^Ptr, Value ^Cmp, Value ^New, AtomicOrdering Ordering, SynchronizationScope SynchScope)
{
	return AtomicCmpXchgInst::_wrap(base->CreateAtomicCmpXchg(Ptr->base, Cmp->base, New->base, safe_cast<llvm::AtomicOrdering>(Ordering), safe_cast<llvm::SynchronizationScope>(SynchScope)));
}
AtomicRMWInst ^IRBuilder::CreateAtomicRMW(AtomicRMWInst::BinOp Op, Value ^Ptr, Value ^Val, AtomicOrdering Ordering)
{
	return AtomicRMWInst::_wrap(base->CreateAtomicRMW(safe_cast<llvm::AtomicRMWInst::BinOp>(Op), Ptr->base, Val->base, safe_cast<llvm::AtomicOrdering>(Ordering)));
}
AtomicRMWInst ^IRBuilder::CreateAtomicRMW(AtomicRMWInst::BinOp Op, Value ^Ptr, Value ^Val, AtomicOrdering Ordering, SynchronizationScope SynchScope)
{
	return AtomicRMWInst::_wrap(base->CreateAtomicRMW(safe_cast<llvm::AtomicRMWInst::BinOp>(Op), Ptr->base, Val->base, safe_cast<llvm::AtomicOrdering>(Ordering), safe_cast<llvm::SynchronizationScope>(SynchScope)));
}
Value ^IRBuilder::CreateGEP(Value ^Ptr, array<Value ^> ^IdxList)
{
	llvm::Value **b = new llvm::Value*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, IdxList->Length);
	auto r = Value::_wrap(base->CreateGEP(Ptr->base, brr));
	delete b;
	return r;
}
Value ^IRBuilder::CreateGEP(Value ^Ptr, array<Value ^> ^IdxList, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	llvm::Value **b = new llvm::Value*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, IdxList->Length);
	auto r = Value::_wrap(base->CreateGEP(Ptr->base, brr, ctx.marshal_as<const char *>(Name)));
	delete b;
	return r;
}
Value ^IRBuilder::CreateInBoundsGEP(Value ^Ptr, array<Value ^> ^IdxList)
{
	llvm::Value **b = new llvm::Value*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, IdxList->Length);
	auto r = Value::_wrap(base->CreateInBoundsGEP(Ptr->base, brr));
	delete b;
	return r;
}
Value ^IRBuilder::CreateInBoundsGEP(Value ^Ptr, array<Value ^> ^IdxList, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	llvm::Value **b = new llvm::Value*[IdxList->Length];
	for (int i = 0; i < IdxList->Length; i++)
		b[i] = IdxList[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, IdxList->Length);
	auto r = Value::_wrap(base->CreateInBoundsGEP(Ptr->base, brr, ctx.marshal_as<const char *>(Name)));
	delete b;
	return r;
}
Value ^IRBuilder::CreateGEP(Value ^Ptr, Value ^Idx)
{
	return Value::_wrap(base->CreateGEP(Ptr->base, Idx->base));
}
Value ^IRBuilder::CreateGEP(Value ^Ptr, Value ^Idx, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateGEP(Ptr->base, Idx->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateInBoundsGEP(Value ^Ptr, Value ^Idx)
{
	return Value::_wrap(base->CreateInBoundsGEP(Ptr->base, Idx->base));
}
Value ^IRBuilder::CreateInBoundsGEP(Value ^Ptr, Value ^Idx, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateInBoundsGEP(Ptr->base, Idx->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateConstGEP1_32(Value ^Ptr, unsigned Idx0)
{
	return Value::_wrap(base->CreateConstGEP1_32(Ptr->base, Idx0));
}
Value ^IRBuilder::CreateConstGEP1_32(Value ^Ptr, unsigned Idx0, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateConstGEP1_32(Ptr->base, Idx0, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateConstInBoundsGEP1_32(Value ^Ptr, unsigned Idx0)
{
	return Value::_wrap(base->CreateConstInBoundsGEP1_32(Ptr->base, Idx0));
}
Value ^IRBuilder::CreateConstInBoundsGEP1_32(Value ^Ptr, unsigned Idx0, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateConstInBoundsGEP1_32(Ptr->base, Idx0, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateConstGEP2_32(Value ^Ptr, unsigned Idx0, unsigned Idx1)
{
	return Value::_wrap(base->CreateConstGEP2_32(Ptr->base, Idx0, Idx1));
}
Value ^IRBuilder::CreateConstGEP2_32(Value ^Ptr, unsigned Idx0, unsigned Idx1, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateConstGEP2_32(Ptr->base, Idx0, Idx1, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateConstInBoundsGEP2_32(Value ^Ptr, unsigned Idx0, unsigned Idx1)
{
	return Value::_wrap(base->CreateConstInBoundsGEP2_32(Ptr->base, Idx0, Idx1));
}
Value ^IRBuilder::CreateConstInBoundsGEP2_32(Value ^Ptr, unsigned Idx0, unsigned Idx1, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateConstInBoundsGEP2_32(Ptr->base, Idx0, Idx1, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateConstGEP1_64(Value ^Ptr, uint64_t Idx0)
{
	return Value::_wrap(base->CreateConstGEP1_64(Ptr->base, Idx0));
}
Value ^IRBuilder::CreateConstGEP1_64(Value ^Ptr, uint64_t Idx0, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateConstGEP1_64(Ptr->base, Idx0, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateConstInBoundsGEP1_64(Value ^Ptr, uint64_t Idx0)
{
	return Value::_wrap(base->CreateConstInBoundsGEP1_64(Ptr->base, Idx0));
}
Value ^IRBuilder::CreateConstInBoundsGEP1_64(Value ^Ptr, uint64_t Idx0, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateConstInBoundsGEP1_64(Ptr->base, Idx0, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateConstGEP2_64(Value ^Ptr, uint64_t Idx0, uint64_t Idx1)
{
	return Value::_wrap(base->CreateConstGEP2_64(Ptr->base, Idx0, Idx1));
}
Value ^IRBuilder::CreateConstGEP2_64(Value ^Ptr, uint64_t Idx0, uint64_t Idx1, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateConstGEP2_64(Ptr->base, Idx0, Idx1, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateConstInBoundsGEP2_64(Value ^Ptr, uint64_t Idx0, uint64_t Idx1)
{
	return Value::_wrap(base->CreateConstInBoundsGEP2_64(Ptr->base, Idx0, Idx1));
}
Value ^IRBuilder::CreateConstInBoundsGEP2_64(Value ^Ptr, uint64_t Idx0, uint64_t Idx1, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateConstInBoundsGEP2_64(Ptr->base, Idx0, Idx1, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateStructGEP(Value ^Ptr, unsigned Idx)
{
	return Value::_wrap(base->CreateStructGEP(Ptr->base, Idx));
}
Value ^IRBuilder::CreateStructGEP(Value ^Ptr, unsigned Idx, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateStructGEP(Ptr->base, Idx, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateGlobalStringPtr(System::String ^Str)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateGlobalStringPtr(ctx.marshal_as<const char *>(Str)));
}
Value ^IRBuilder::CreateGlobalStringPtr(System::String ^Str, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateGlobalStringPtr(ctx.marshal_as<const char *>(Str), ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateTrunc(Value ^V, Type ^DestTy)
{
	return Value::_wrap(base->CreateTrunc(V->base, DestTy->base));
}
Value ^IRBuilder::CreateTrunc(Value ^V, Type ^DestTy, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateTrunc(V->base, DestTy->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateZExt(Value ^V, Type ^DestTy)
{
	return Value::_wrap(base->CreateZExt(V->base, DestTy->base));
}
Value ^IRBuilder::CreateZExt(Value ^V, Type ^DestTy, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateZExt(V->base, DestTy->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateSExt(Value ^V, Type ^DestTy)
{
	return Value::_wrap(base->CreateSExt(V->base, DestTy->base));
}
Value ^IRBuilder::CreateSExt(Value ^V, Type ^DestTy, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateSExt(V->base, DestTy->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateZExtOrTrunc(Value ^V, Type ^DestTy)
{
	return Value::_wrap(base->CreateZExtOrTrunc(V->base, DestTy->base));
}
Value ^IRBuilder::CreateZExtOrTrunc(Value ^V, Type ^DestTy, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateZExtOrTrunc(V->base, DestTy->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateSExtOrTrunc(Value ^V, Type ^DestTy)
{
	return Value::_wrap(base->CreateSExtOrTrunc(V->base, DestTy->base));
}
Value ^IRBuilder::CreateSExtOrTrunc(Value ^V, Type ^DestTy, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateSExtOrTrunc(V->base, DestTy->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFPToUI(Value ^V, Type ^DestTy)
{
	return Value::_wrap(base->CreateFPToUI(V->base, DestTy->base));
}
Value ^IRBuilder::CreateFPToUI(Value ^V, Type ^DestTy, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFPToUI(V->base, DestTy->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFPToSI(Value ^V, Type ^DestTy)
{
	return Value::_wrap(base->CreateFPToSI(V->base, DestTy->base));
}
Value ^IRBuilder::CreateFPToSI(Value ^V, Type ^DestTy, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFPToSI(V->base, DestTy->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateUIToFP(Value ^V, Type ^DestTy)
{
	return Value::_wrap(base->CreateUIToFP(V->base, DestTy->base));
}
Value ^IRBuilder::CreateUIToFP(Value ^V, Type ^DestTy, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateUIToFP(V->base, DestTy->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateSIToFP(Value ^V, Type ^DestTy)
{
	return Value::_wrap(base->CreateSIToFP(V->base, DestTy->base));
}
Value ^IRBuilder::CreateSIToFP(Value ^V, Type ^DestTy, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateSIToFP(V->base, DestTy->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFPTrunc(Value ^V, Type ^DestTy)
{
	return Value::_wrap(base->CreateFPTrunc(V->base, DestTy->base));
}
Value ^IRBuilder::CreateFPTrunc(Value ^V, Type ^DestTy, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFPTrunc(V->base, DestTy->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFPExt(Value ^V, Type ^DestTy)
{
	return Value::_wrap(base->CreateFPExt(V->base, DestTy->base));
}
Value ^IRBuilder::CreateFPExt(Value ^V, Type ^DestTy, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFPExt(V->base, DestTy->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreatePtrToInt(Value ^V, Type ^DestTy)
{
	return Value::_wrap(base->CreatePtrToInt(V->base, DestTy->base));
}
Value ^IRBuilder::CreatePtrToInt(Value ^V, Type ^DestTy, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreatePtrToInt(V->base, DestTy->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateIntToPtr(Value ^V, Type ^DestTy)
{
	return Value::_wrap(base->CreateIntToPtr(V->base, DestTy->base));
}
Value ^IRBuilder::CreateIntToPtr(Value ^V, Type ^DestTy, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateIntToPtr(V->base, DestTy->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateBitCast(Value ^V, Type ^DestTy)
{
	return Value::_wrap(base->CreateBitCast(V->base, DestTy->base));
}
Value ^IRBuilder::CreateBitCast(Value ^V, Type ^DestTy, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateBitCast(V->base, DestTy->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateZExtOrBitCast(Value ^V, Type ^DestTy)
{
	return Value::_wrap(base->CreateZExtOrBitCast(V->base, DestTy->base));
}
Value ^IRBuilder::CreateZExtOrBitCast(Value ^V, Type ^DestTy, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateZExtOrBitCast(V->base, DestTy->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateSExtOrBitCast(Value ^V, Type ^DestTy)
{
	return Value::_wrap(base->CreateSExtOrBitCast(V->base, DestTy->base));
}
Value ^IRBuilder::CreateSExtOrBitCast(Value ^V, Type ^DestTy, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateSExtOrBitCast(V->base, DestTy->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateTruncOrBitCast(Value ^V, Type ^DestTy)
{
	return Value::_wrap(base->CreateTruncOrBitCast(V->base, DestTy->base));
}
Value ^IRBuilder::CreateTruncOrBitCast(Value ^V, Type ^DestTy, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateTruncOrBitCast(V->base, DestTy->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateCast(Instruction::CastOps Op, Value ^V, Type ^DestTy)
{
	return Value::_wrap(base->CreateCast(safe_cast<llvm::Instruction::CastOps>(Op), V->base, DestTy->base));
}
Value ^IRBuilder::CreateCast(Instruction::CastOps Op, Value ^V, Type ^DestTy, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateCast(safe_cast<llvm::Instruction::CastOps>(Op), V->base, DestTy->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreatePointerCast(Value ^V, Type ^DestTy)
{
	return Value::_wrap(base->CreatePointerCast(V->base, DestTy->base));
}
Value ^IRBuilder::CreatePointerCast(Value ^V, Type ^DestTy, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreatePointerCast(V->base, DestTy->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateIntCast(Value ^V, Type ^DestTy, bool isSigned)
{
	return Value::_wrap(base->CreateIntCast(V->base, DestTy->base, isSigned));
}
Value ^IRBuilder::CreateIntCast(Value ^V, Type ^DestTy, bool isSigned, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateIntCast(V->base, DestTy->base, isSigned, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFPCast(Value ^V, Type ^DestTy)
{
	return Value::_wrap(base->CreateFPCast(V->base, DestTy->base));
}
Value ^IRBuilder::CreateFPCast(Value ^V, Type ^DestTy, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFPCast(V->base, DestTy->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateICmpEQ(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateICmpEQ(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateICmpEQ(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateICmpEQ(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateICmpNE(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateICmpNE(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateICmpNE(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateICmpNE(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateICmpUGT(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateICmpUGT(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateICmpUGT(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateICmpUGT(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateICmpUGE(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateICmpUGE(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateICmpUGE(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateICmpUGE(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateICmpULT(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateICmpULT(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateICmpULT(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateICmpULT(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateICmpULE(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateICmpULE(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateICmpULE(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateICmpULE(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateICmpSGT(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateICmpSGT(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateICmpSGT(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateICmpSGT(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateICmpSGE(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateICmpSGE(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateICmpSGE(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateICmpSGE(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateICmpSLT(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateICmpSLT(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateICmpSLT(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateICmpSLT(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateICmpSLE(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateICmpSLE(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateICmpSLE(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateICmpSLE(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFCmpOEQ(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateFCmpOEQ(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateFCmpOEQ(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFCmpOEQ(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFCmpOGT(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateFCmpOGT(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateFCmpOGT(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFCmpOGT(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFCmpOGE(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateFCmpOGE(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateFCmpOGE(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFCmpOGE(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFCmpOLT(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateFCmpOLT(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateFCmpOLT(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFCmpOLT(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFCmpOLE(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateFCmpOLE(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateFCmpOLE(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFCmpOLE(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFCmpONE(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateFCmpONE(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateFCmpONE(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFCmpONE(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFCmpORD(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateFCmpORD(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateFCmpORD(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFCmpORD(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFCmpUNO(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateFCmpUNO(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateFCmpUNO(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFCmpUNO(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFCmpUEQ(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateFCmpUEQ(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateFCmpUEQ(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFCmpUEQ(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFCmpUGT(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateFCmpUGT(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateFCmpUGT(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFCmpUGT(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFCmpUGE(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateFCmpUGE(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateFCmpUGE(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFCmpUGE(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFCmpULT(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateFCmpULT(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateFCmpULT(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFCmpULT(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFCmpULE(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateFCmpULE(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateFCmpULE(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFCmpULE(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFCmpUNE(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateFCmpUNE(LHS->base, RHS->base));
}
Value ^IRBuilder::CreateFCmpUNE(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFCmpUNE(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateICmp(CmpInst::Predicate P, Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateICmp(safe_cast<llvm::CmpInst::Predicate>(P), LHS->base, RHS->base));
}
Value ^IRBuilder::CreateICmp(CmpInst::Predicate P, Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateICmp(safe_cast<llvm::CmpInst::Predicate>(P), LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateFCmp(CmpInst::Predicate P, Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreateFCmp(safe_cast<llvm::CmpInst::Predicate>(P), LHS->base, RHS->base));
}
Value ^IRBuilder::CreateFCmp(CmpInst::Predicate P, Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateFCmp(safe_cast<llvm::CmpInst::Predicate>(P), LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
PHINode ^IRBuilder::CreatePHI(Type ^Ty, unsigned NumReservedValues)
{
	return PHINode::_wrap(base->CreatePHI(Ty->base, NumReservedValues));
}
PHINode ^IRBuilder::CreatePHI(Type ^Ty, unsigned NumReservedValues, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return PHINode::_wrap(base->CreatePHI(Ty->base, NumReservedValues, ctx.marshal_as<const char *>(Name)));
}
CallInst ^IRBuilder::CreateCall(Value ^Callee)
{
	return CallInst::_wrap(base->CreateCall(Callee->base));
}
CallInst ^IRBuilder::CreateCall(Value ^Callee, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return CallInst::_wrap(base->CreateCall(Callee->base, ctx.marshal_as<const char *>(Name)));
}
CallInst ^IRBuilder::CreateCall(Value ^Callee, Value ^Arg)
{
	return CallInst::_wrap(base->CreateCall(Callee->base, Arg->base));
}
CallInst ^IRBuilder::CreateCall(Value ^Callee, Value ^Arg, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return CallInst::_wrap(base->CreateCall(Callee->base, Arg->base, ctx.marshal_as<const char *>(Name)));
}
CallInst ^IRBuilder::CreateCall2(Value ^Callee, Value ^Arg1, Value ^Arg2)
{
	return CallInst::_wrap(base->CreateCall2(Callee->base, Arg1->base, Arg2->base));
}
CallInst ^IRBuilder::CreateCall2(Value ^Callee, Value ^Arg1, Value ^Arg2, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return CallInst::_wrap(base->CreateCall2(Callee->base, Arg1->base, Arg2->base, ctx.marshal_as<const char *>(Name)));
}
CallInst ^IRBuilder::CreateCall3(Value ^Callee, Value ^Arg1, Value ^Arg2, Value ^Arg3)
{
	return CallInst::_wrap(base->CreateCall3(Callee->base, Arg1->base, Arg2->base, Arg3->base));
}
CallInst ^IRBuilder::CreateCall3(Value ^Callee, Value ^Arg1, Value ^Arg2, Value ^Arg3, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return CallInst::_wrap(base->CreateCall3(Callee->base, Arg1->base, Arg2->base, Arg3->base, ctx.marshal_as<const char *>(Name)));
}
CallInst ^IRBuilder::CreateCall4(Value ^Callee, Value ^Arg1, Value ^Arg2, Value ^Arg3, Value ^Arg4)
{
	return CallInst::_wrap(base->CreateCall4(Callee->base, Arg1->base, Arg2->base, Arg3->base, Arg4->base));
}
CallInst ^IRBuilder::CreateCall4(Value ^Callee, Value ^Arg1, Value ^Arg2, Value ^Arg3, Value ^Arg4, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return CallInst::_wrap(base->CreateCall4(Callee->base, Arg1->base, Arg2->base, Arg3->base, Arg4->base, ctx.marshal_as<const char *>(Name)));
}
CallInst ^IRBuilder::CreateCall5(Value ^Callee, Value ^Arg1, Value ^Arg2, Value ^Arg3, Value ^Arg4, Value ^Arg5)
{
	return CallInst::_wrap(base->CreateCall5(Callee->base, Arg1->base, Arg2->base, Arg3->base, Arg4->base, Arg5->base));
}
CallInst ^IRBuilder::CreateCall5(Value ^Callee, Value ^Arg1, Value ^Arg2, Value ^Arg3, Value ^Arg4, Value ^Arg5, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return CallInst::_wrap(base->CreateCall5(Callee->base, Arg1->base, Arg2->base, Arg3->base, Arg4->base, Arg5->base, ctx.marshal_as<const char *>(Name)));
}
CallInst ^IRBuilder::CreateCall(Value ^Callee, array<Value ^> ^Args)
{
	llvm::Value **b = new llvm::Value*[Args->Length];
	for (int i = 0; i < Args->Length; i++)
		b[i] = Args[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, Args->Length);
	auto r = CallInst::_wrap(base->CreateCall(Callee->base, brr));
	delete b;
	return r;
}
CallInst ^IRBuilder::CreateCall(Value ^Callee, array<Value ^> ^Args, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	llvm::Value **b = new llvm::Value*[Args->Length];
	for (int i = 0; i < Args->Length; i++)
		b[i] = Args[i]->base;
	llvm::ArrayRef<llvm::Value*> brr(b, Args->Length);
	auto r = CallInst::_wrap(base->CreateCall(Callee->base, brr, ctx.marshal_as<const char *>(Name)));
	delete b;
	return r;
}
Value ^IRBuilder::CreateSelect(Value ^C, Value ^True, Value ^False)
{
	return Value::_wrap(base->CreateSelect(C->base, True->base, False->base));
}
Value ^IRBuilder::CreateSelect(Value ^C, Value ^True, Value ^False, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateSelect(C->base, True->base, False->base, ctx.marshal_as<const char *>(Name)));
}
VAArgInst ^IRBuilder::CreateVAArg(Value ^List, Type ^Ty)
{
	return VAArgInst::_wrap(base->CreateVAArg(List->base, Ty->base));
}
VAArgInst ^IRBuilder::CreateVAArg(Value ^List, Type ^Ty, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return VAArgInst::_wrap(base->CreateVAArg(List->base, Ty->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateExtractElement(Value ^Vec, Value ^Idx)
{
	return Value::_wrap(base->CreateExtractElement(Vec->base, Idx->base));
}
Value ^IRBuilder::CreateExtractElement(Value ^Vec, Value ^Idx, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateExtractElement(Vec->base, Idx->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateInsertElement(Value ^Vec, Value ^NewElt, Value ^Idx)
{
	return Value::_wrap(base->CreateInsertElement(Vec->base, NewElt->base, Idx->base));
}
Value ^IRBuilder::CreateInsertElement(Value ^Vec, Value ^NewElt, Value ^Idx, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateInsertElement(Vec->base, NewElt->base, Idx->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateShuffleVector(Value ^V1, Value ^V2, Value ^Mask)
{
	return Value::_wrap(base->CreateShuffleVector(V1->base, V2->base, Mask->base));
}
Value ^IRBuilder::CreateShuffleVector(Value ^V1, Value ^V2, Value ^Mask, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateShuffleVector(V1->base, V2->base, Mask->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateExtractValue(Value ^Agg, array<unsigned> ^Idxs)
{
	auto r = Value::_wrap(base->CreateExtractValue(Agg->base, utils::unmanage_array(Idxs)));
	return r;
}
Value ^IRBuilder::CreateExtractValue(Value ^Agg, array<unsigned> ^Idxs, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	auto r = Value::_wrap(base->CreateExtractValue(Agg->base, utils::unmanage_array(Idxs), ctx.marshal_as<const char *>(Name)));
	return r;
}
Value ^IRBuilder::CreateInsertValue(Value ^Agg, Value ^Val, array<unsigned> ^Idxs)
{
	auto r = Value::_wrap(base->CreateInsertValue(Agg->base, Val->base, utils::unmanage_array(Idxs)));
	return r;
}
Value ^IRBuilder::CreateInsertValue(Value ^Agg, Value ^Val, array<unsigned> ^Idxs, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	auto r = Value::_wrap(base->CreateInsertValue(Agg->base, Val->base, utils::unmanage_array(Idxs), ctx.marshal_as<const char *>(Name)));
	return r;
}
LandingPadInst ^IRBuilder::CreateLandingPad(Type ^Ty, Value ^PersFn, unsigned NumClauses)
{
	return LandingPadInst::_wrap(base->CreateLandingPad(Ty->base, PersFn->base, NumClauses));
}
LandingPadInst ^IRBuilder::CreateLandingPad(Type ^Ty, Value ^PersFn, unsigned NumClauses, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return LandingPadInst::_wrap(base->CreateLandingPad(Ty->base, PersFn->base, NumClauses, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateIsNull(Value ^Arg)
{
	return Value::_wrap(base->CreateIsNull(Arg->base));
}
Value ^IRBuilder::CreateIsNull(Value ^Arg, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateIsNull(Arg->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateIsNotNull(Value ^Arg)
{
	return Value::_wrap(base->CreateIsNotNull(Arg->base));
}
Value ^IRBuilder::CreateIsNotNull(Value ^Arg, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateIsNotNull(Arg->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreatePtrDiff(Value ^LHS, Value ^RHS)
{
	return Value::_wrap(base->CreatePtrDiff(LHS->base, RHS->base));
}
Value ^IRBuilder::CreatePtrDiff(Value ^LHS, Value ^RHS, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreatePtrDiff(LHS->base, RHS->base, ctx.marshal_as<const char *>(Name)));
}
Value ^IRBuilder::CreateVectorSplat(unsigned NumElts, Value ^V)
{
	return Value::_wrap(base->CreateVectorSplat(NumElts, V->base));
}
Value ^IRBuilder::CreateVectorSplat(unsigned NumElts, Value ^V, System::String ^Name)
{
	msclr::interop::marshal_context ctx;
	return Value::_wrap(base->CreateVectorSplat(NumElts, V->base, ctx.marshal_as<const char *>(Name)));
}
