#include "Operator.h"
#include "Value.h"
#include "Instruction.h"
#include "Constants.h"
#include "Operator.h"
#include "Type.h"

using namespace LLVM;

Operator::Operator(llvm::Operator *base)
	: base(base)
	, User(base)
{
}
inline Operator ^Operator::_wrap(llvm::Operator *base)
{
	return base ? gcnew Operator(base) : nullptr;
}
Operator::!Operator()
{
}
Operator::~Operator()
{
	this->!Operator();
}
unsigned Operator::getOpcode()
{
	return base->getOpcode();
}
unsigned Operator::getOpcode(Value ^V)
{
	return llvm::Operator::getOpcode(V->base);
}
inline bool Operator::classof(Instruction ^instruction)
{
	return llvm::Operator::classof(instruction->base);
}
inline bool Operator::classof(ConstantExpr ^expr)
{
	return llvm::Operator::classof(expr->base);
}
inline bool Operator::classof(Value ^V)
{
	return llvm::Operator::classof(V->base);
}


OverflowingBinaryOperator::OverflowingBinaryOperator(llvm::OverflowingBinaryOperator *base)
	: base(base)
	, Operator(base)
{
}
inline OverflowingBinaryOperator ^OverflowingBinaryOperator::_wrap(llvm::OverflowingBinaryOperator *base)
{
	return base ? gcnew OverflowingBinaryOperator(base) : nullptr;
}
OverflowingBinaryOperator::!OverflowingBinaryOperator()
{
}
OverflowingBinaryOperator::~OverflowingBinaryOperator()
{
	this->!OverflowingBinaryOperator();
}
bool OverflowingBinaryOperator::hasNoUnsignedWrap()
{
	return base->hasNoUnsignedWrap();
}
bool OverflowingBinaryOperator::hasNoSignedWrap()
{
	return base->hasNoSignedWrap();
}
inline bool OverflowingBinaryOperator::classof(Instruction ^I)
{
	return llvm::OverflowingBinaryOperator::classof(I->base);
}
inline bool OverflowingBinaryOperator::classof(ConstantExpr ^CE)
{
	return llvm::OverflowingBinaryOperator::classof(CE->base);
}
inline bool OverflowingBinaryOperator::classof(Value ^V)
{
	return llvm::OverflowingBinaryOperator::classof(V->base);
}


PossiblyExactOperator::PossiblyExactOperator(llvm::PossiblyExactOperator *base)
	: base(base)
	, Operator(base)
{
}
inline PossiblyExactOperator ^PossiblyExactOperator::_wrap(llvm::PossiblyExactOperator *base)
{
	return base ? gcnew PossiblyExactOperator(base) : nullptr;
}
PossiblyExactOperator::!PossiblyExactOperator()
{
}
PossiblyExactOperator::~PossiblyExactOperator()
{
	this->!PossiblyExactOperator();
}
bool PossiblyExactOperator::isExact()
{
	return base->isExact();
}
bool PossiblyExactOperator::isPossiblyExactOpcode(unsigned OpC)
{
	return llvm::PossiblyExactOperator::isPossiblyExactOpcode(OpC);
}
inline bool PossiblyExactOperator::classof(ConstantExpr ^CE)
{
	return llvm::PossiblyExactOperator::classof(CE->base);
}
inline bool PossiblyExactOperator::classof(Instruction ^I)
{
	return llvm::PossiblyExactOperator::classof(I->base);
}
inline bool PossiblyExactOperator::classof(Value ^V)
{
	return llvm::PossiblyExactOperator::classof(V->base);
}


FastMathFlags::FastMathFlags(llvm::FastMathFlags *base)
	: base(base)
	, constructed(false)
{
}
inline FastMathFlags ^FastMathFlags::_wrap(llvm::FastMathFlags *base)
{
	return base ? gcnew FastMathFlags(base) : nullptr;
}
FastMathFlags::!FastMathFlags()
{
	if (constructed)
	{
		delete base;
	}
}
FastMathFlags::~FastMathFlags()
{
	this->!FastMathFlags();
}
FastMathFlags::FastMathFlags()
	: base(new llvm::FastMathFlags())
	, constructed(true)
{
}
bool FastMathFlags::any()
{
	return base->any();
}
void FastMathFlags::clear()
{
	base->clear();
}
bool FastMathFlags::noNaNs()
{
	return base->noNaNs();
}
bool FastMathFlags::noInfs()
{
	return base->noInfs();
}
bool FastMathFlags::noSignedZeros()
{
	return base->noSignedZeros();
}
bool FastMathFlags::allowReciprocal()
{
	return base->allowReciprocal();
}
bool FastMathFlags::unsafeAlgebra()
{
	return base->unsafeAlgebra();
}
void FastMathFlags::setNoNaNs()
{
	base->setNoNaNs();
}
void FastMathFlags::setNoInfs()
{
	base->setNoInfs();
}
void FastMathFlags::setNoSignedZeros()
{
	base->setNoSignedZeros();
}
void FastMathFlags::setAllowReciprocal()
{
	base->setAllowReciprocal();
}
void FastMathFlags::setUnsafeAlgebra()
{
	base->setUnsafeAlgebra();
}


FPMathOperator::FPMathOperator(llvm::FPMathOperator *base)
	: base(base)
	, Operator(base)
{
}
inline FPMathOperator ^FPMathOperator::_wrap(llvm::FPMathOperator *base)
{
	return base ? gcnew FPMathOperator(base) : nullptr;
}
FPMathOperator::!FPMathOperator()
{
}
FPMathOperator::~FPMathOperator()
{
	this->!FPMathOperator();
}
bool FPMathOperator::hasUnsafeAlgebra()
{
	return base->hasUnsafeAlgebra();
}
bool FPMathOperator::hasNoNaNs()
{
	return base->hasNoNaNs();
}
bool FPMathOperator::hasNoInfs()
{
	return base->hasNoInfs();
}
bool FPMathOperator::hasNoSignedZeros()
{
	return base->hasNoSignedZeros();
}
bool FPMathOperator::hasAllowReciprocal()
{
	return base->hasAllowReciprocal();
}
FastMathFlags ^FPMathOperator::getFastMathFlags()
{
	return FastMathFlags::_wrap(&base->getFastMathFlags());
}
float FPMathOperator::getFPAccuracy()
{
	return base->getFPAccuracy();
}
inline bool FPMathOperator::classof(Instruction ^I)
{
	return llvm::FPMathOperator::classof(I->base);
}
inline bool FPMathOperator::classof(Value ^V)
{
	return llvm::FPMathOperator::classof(V->base);
}


AddOperator::AddOperator(llvm::AddOperator *base)
	: base(base)
{
}
inline AddOperator ^AddOperator::_wrap(llvm::AddOperator *base)
{
	return base ? gcnew AddOperator(base) : nullptr;
}
AddOperator::!AddOperator()
{
}
AddOperator::~AddOperator()
{
	this->!AddOperator();
}


SubOperator::SubOperator(llvm::SubOperator *base)
	: base(base)
{
}
inline SubOperator ^SubOperator::_wrap(llvm::SubOperator *base)
{
	return base ? gcnew SubOperator(base) : nullptr;
}
SubOperator::!SubOperator()
{
}
SubOperator::~SubOperator()
{
	this->!SubOperator();
}


MulOperator::MulOperator(llvm::MulOperator *base)
	: base(base)
{
}
inline MulOperator ^MulOperator::_wrap(llvm::MulOperator *base)
{
	return base ? gcnew MulOperator(base) : nullptr;
}
MulOperator::!MulOperator()
{
}
MulOperator::~MulOperator()
{
	this->!MulOperator();
}


ShlOperator::ShlOperator(llvm::ShlOperator *base)
	: base(base)
{
}
inline ShlOperator ^ShlOperator::_wrap(llvm::ShlOperator *base)
{
	return base ? gcnew ShlOperator(base) : nullptr;
}
ShlOperator::!ShlOperator()
{
}
ShlOperator::~ShlOperator()
{
	this->!ShlOperator();
}


SDivOperator::SDivOperator(llvm::SDivOperator *base)
	: base(base)
{
}
inline SDivOperator ^SDivOperator::_wrap(llvm::SDivOperator *base)
{
	return base ? gcnew SDivOperator(base) : nullptr;
}
SDivOperator::!SDivOperator()
{
}
SDivOperator::~SDivOperator()
{
	this->!SDivOperator();
}


UDivOperator::UDivOperator(llvm::UDivOperator *base)
	: base(base)
{
}
inline UDivOperator ^UDivOperator::_wrap(llvm::UDivOperator *base)
{
	return base ? gcnew UDivOperator(base) : nullptr;
}
UDivOperator::!UDivOperator()
{
}
UDivOperator::~UDivOperator()
{
	this->!UDivOperator();
}


AShrOperator::AShrOperator(llvm::AShrOperator *base)
	: base(base)
{
}
inline AShrOperator ^AShrOperator::_wrap(llvm::AShrOperator *base)
{
	return base ? gcnew AShrOperator(base) : nullptr;
}
AShrOperator::!AShrOperator()
{
}
AShrOperator::~AShrOperator()
{
	this->!AShrOperator();
}


LShrOperator::LShrOperator(llvm::LShrOperator *base)
	: base(base)
{
}
inline LShrOperator ^LShrOperator::_wrap(llvm::LShrOperator *base)
{
	return base ? gcnew LShrOperator(base) : nullptr;
}
LShrOperator::!LShrOperator()
{
}
LShrOperator::~LShrOperator()
{
	this->!LShrOperator();
}


GEPOperator::GEPOperator(llvm::GEPOperator *base)
	: base(base)
{
}
inline GEPOperator ^GEPOperator::_wrap(llvm::GEPOperator *base)
{
	return base ? gcnew GEPOperator(base) : nullptr;
}
GEPOperator::!GEPOperator()
{
}
GEPOperator::~GEPOperator()
{
	this->!GEPOperator();
}
bool GEPOperator::isInBounds()
{
	return base->isInBounds();
}
Value ^GEPOperator::getPointerOperand()
{
	return Value::_wrap(base->getPointerOperand());
}
unsigned GEPOperator::getPointerOperandIndex()
{
	return llvm::GEPOperator::getPointerOperandIndex();
}
Type ^GEPOperator::getPointerOperandType()
{
	return Type::_wrap(base->getPointerOperandType());
}
unsigned GEPOperator::getPointerAddressSpace()
{
	return base->getPointerAddressSpace();
}
unsigned GEPOperator::getNumIndices()
{
	return base->getNumIndices();
}
bool GEPOperator::hasIndices()
{
	return base->hasIndices();
}
bool GEPOperator::hasAllZeroIndices()
{
	return base->hasAllZeroIndices();
}
bool GEPOperator::hasAllConstantIndices()
{
	return base->hasAllConstantIndices();
}
