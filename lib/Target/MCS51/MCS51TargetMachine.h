//===-- MCS51TargetMachine.h - Define TargetMachine for MCS51 -*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the MCS51 specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//


#ifndef LLVM_TARGET_MCS51_TARGETMACHINE_H
#define LLVM_TARGET_MCS51_TARGETMACHINE_H

#include "MCS51FrameLowering.h"
#include "MCS51ISelLowering.h"
#include "MCS51InstrInfo.h"
#include "MCS51RegisterInfo.h"
#include "MCS51SelectionDAGInfo.h"
#include "MCS51Subtarget.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/Target/TargetFrameLowering.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {

/// MCS51TargetMachine
///
class MCS51TargetMachine : public LLVMTargetMachine {
  MCS51Subtarget        Subtarget;
  const DataLayout       DL;       // Calculates type size & alignment
  MCS51InstrInfo        InstrInfo;
  MCS51TargetLowering   TLInfo;
  MCS51SelectionDAGInfo TSInfo;
  MCS51FrameLowering    FrameLowering;

public:
  MCS51TargetMachine(const Target &T, StringRef TT,
                      StringRef CPU, StringRef FS, const TargetOptions &Options,
                      Reloc::Model RM, CodeModel::Model CM,
                      CodeGenOpt::Level OL);

  virtual const TargetFrameLowering *getFrameLowering() const {
    return &FrameLowering;
  }
  virtual const MCS51InstrInfo *getInstrInfo() const  { return &InstrInfo; }
  virtual const DataLayout *getDataLayout() const     { return &DL;}
  virtual const MCS51Subtarget *getSubtargetImpl() const { return &Subtarget; }

  virtual const TargetRegisterInfo *getRegisterInfo() const {
    return &InstrInfo.getRegisterInfo();
  }

  virtual const MCS51TargetLowering *getTargetLowering() const {
    return &TLInfo;
  }

  virtual const MCS51SelectionDAGInfo* getSelectionDAGInfo() const {
    return &TSInfo;
  }
  virtual TargetPassConfig *createPassConfig(PassManagerBase &PM);
}; // MCS51TargetMachine.

} // end namespace llvm

#endif // LLVM_TARGET_MCS51_TARGETMACHINE_H
