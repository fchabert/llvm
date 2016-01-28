//===-- MCS51TargetMachine.cpp - Define TargetMachine for MCS51 ---------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Top-level implementation for the MCS51 target.
//
//===----------------------------------------------------------------------===//

#include "MCS51TargetMachine.h"
#include "MCS51.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/PassManager.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

extern "C" void LLVMInitializeMCS51Target() {
  // Register the target.
  RegisterTargetMachine<MCS51TargetMachine> X(TheMCS51Target);
}

MCS51TargetMachine::MCS51TargetMachine(const Target &T,
                                         StringRef TT,
                                         StringRef CPU,
                                         StringRef FS,
                                         const TargetOptions &Options,
                                         Reloc::Model RM, CodeModel::Model CM,
                                         CodeGenOpt::Level OL)
  : LLVMTargetMachine(T, TT, CPU, FS, Options, RM, CM, OL),
    Subtarget(TT, CPU, FS),
    // FIXME: Check DataLayout string.
    DL("e-p:16:16:16-i8:8:8-i16:16:16-i32:16:32-n8:16"),
    InstrInfo(*this), TLInfo(*this), TSInfo(*this),
    FrameLowering(Subtarget) {
  initAsmInfo();
}

namespace {
/// MCS51 Code Generator Pass Configuration Options.
class MCS51PassConfig : public TargetPassConfig {
public:
  MCS51PassConfig(MCS51TargetMachine *TM, PassManagerBase &PM)
    : TargetPassConfig(TM, PM) {}

  MCS51TargetMachine &getMCS51TargetMachine() const {
    return getTM<MCS51TargetMachine>();
  }

  virtual bool addInstSelector();
  virtual bool addPreEmitPass();
};
} // namespace

TargetPassConfig *MCS51TargetMachine::createPassConfig(PassManagerBase &PM) {
  return new MCS51PassConfig(this, PM);
}

bool MCS51PassConfig::addInstSelector() {
  // Install an instruction selector.
  addPass(createMCS51ISelDag(getMCS51TargetMachine(), getOptLevel()));
  return false;
}

bool MCS51PassConfig::addPreEmitPass() {
  // Must run branch selection immediately preceding the asm printer.
  addPass(createMCS51BranchSelectionPass());
  return false;
}
