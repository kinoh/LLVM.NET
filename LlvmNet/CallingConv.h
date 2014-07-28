#pragma once
#include "llvm/IR/CallingConv.h"

namespace LLVM
{

public ref class CallingConv
{
public:
	enum class ID
	{
		C = 0,
		Fast = 8,
		Cold = 9,
		GHC = 10,
		HiPE = 11,
		FirstTargetCC = 64,
		X86_StdCall = 64,
		X86_FastCall = 65,
		ARM_APCS = 66,
		ARM_AAPCS = 67,
		ARM_AAPCS_VFP = 68,
		MSP430_INTR = 69,
		X86_ThisCall = 70,
		PTX_Kernel = 71,
		PTX_Device = 72,
		MBLAZE_INTR = 73,
		MBLAZE_SVOL = 74,
		SPIR_FUNC = 75,
		SPIR_KERNEL = 76,
		Intel_OCL_BI = 77

	};

public:
};

}
