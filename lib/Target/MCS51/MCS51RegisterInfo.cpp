//===-- MCS51RegisterInfo.cpp - MCS51 Register Information --------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the MCS51 implementation of the TargetRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "MCS51-reg-info"

#include "MCS51RegisterInfo.h"
#include "MCS51.h"
#include "MCS51MachineFunctionInfo.h"
#include "MCS51TargetMachine.h"
#include "llvm/ADT/BitVector.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"

#define GET_REGINFO_TARGET_DESC
#include "MCS51GenRegisterInfo.inc"

using namespace llvm;

MCS51RegisterInfo::MCS51RegisterInfo(MCS51TargetMachine &tm)
  : MCS51GenRegisterInfo(), TM(tm) {
}

const uint16_t*
MCS51RegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  static const uint16_t CalleeSavedRegs[] = { MCS51::R6, MCS51::R7, 0 };
  return CalleeSavedRegs;
}
