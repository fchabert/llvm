//==- MCS51FrameLowering.h - Define frame lowering for MCS51 --*- C++ -*--==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
//
//
//===----------------------------------------------------------------------===//

#ifndef MCS51_FRAMEINFO_H
#define MCS51_FRAMEINFO_H

#include "MCS51.h"
#include "MCS51Subtarget.h"
#include "llvm/Target/TargetFrameLowering.h"

namespace llvm {
  class MCS51Subtarget;

class MCS51FrameLowering : public TargetFrameLowering {
protected:
  const MCS51Subtarget &STI;

public:
  explicit MCS51FrameLowering(const MCS51Subtarget &sti)
    : TargetFrameLowering(TargetFrameLowering::StackGrowsDown, 2, -2), STI(sti) {
  }

  /// emitProlog/emitEpilog - These methods insert prolog and epilog code into
  /// the function.
  void emitPrologue(MachineFunction &MF) const;
  void emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const;

  void eliminateCallFramePseudoInstr(MachineFunction &MF,
                                     MachineBasicBlock &MBB,
                                     MachineBasicBlock::iterator I) const;

  bool spillCalleeSavedRegisters(MachineBasicBlock &MBB,
                                 MachineBasicBlock::iterator MI,
                                 const std::vector<CalleeSavedInfo> &CSI,
                                 const TargetRegisterInfo *TRI) const;
  bool restoreCalleeSavedRegisters(MachineBasicBlock &MBB,
                                   MachineBasicBlock::iterator MI,
                                   const std::vector<CalleeSavedInfo> &CSI,
                                   const TargetRegisterInfo *TRI) const;

  bool hasFP(const MachineFunction &MF) const;
  bool hasReservedCallFrame(const MachineFunction &MF) const;
  void processFunctionBeforeFrameFinalized(MachineFunction &MF,
                                       RegScavenger *RS = NULL) const;
};

} // End llvm namespace

#endif
