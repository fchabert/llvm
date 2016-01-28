//===-- MCS51RegisterInfo.h - MCS51 Register Information Impl -*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the MCS51 implementation of the MRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TARGET_MCS51REGISTERINFO_H
#define LLVM_TARGET_MCS51REGISTERINFO_H

#include "llvm/Target/TargetRegisterInfo.h"

#define GET_REGINFO_HEADER
#include "MCS51GenRegisterInfo.inc"

namespace llvm {

class TargetInstrInfo;
class MCS51TargetMachine;

struct MCS51RegisterInfo : public MCS51GenRegisterInfo {
private:
  MCS51TargetMachine &TM;

public:
  MCS51RegisterInfo(MCS51TargetMachine &tm);

  /// Code Generation virtual methods...
  const uint16_t *getCalleeSavedRegs(const MachineFunction *MF = 0) const;
};

} // end namespace llvm

#endif // LLVM_TARGET_MCS51REGISTERINFO_H
