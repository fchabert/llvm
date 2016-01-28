//===-- MCS51MCTargetDesc.cpp - MCS51 Target Descriptions ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides MCS51 specific target descriptions.
//
//===----------------------------------------------------------------------===//

#include "MCS51MCTargetDesc.h"
#include "InstPrinter/MCS51InstPrinter.h"
#include "MCS51MCAsmInfo.h"
#include "llvm/MC/MCCodeGenInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/TargetRegistry.h"

#define GET_INSTRINFO_MC_DESC
#include "MCS51GenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "MCS51GenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "MCS51GenRegisterInfo.inc"

using namespace llvm;

static MCInstrInfo *createMCS51MCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitMCS51MCInstrInfo(X);
  return X;
}

static MCRegisterInfo *createMCS51MCRegisterInfo(StringRef TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitMCS51MCRegisterInfo(X, MCS51::PCW);
  return X;
}

static MCSubtargetInfo *createMCS51MCSubtargetInfo(StringRef TT, StringRef CPU,
                                                    StringRef FS) {
  MCSubtargetInfo *X = new MCSubtargetInfo();
  InitMCS51MCSubtargetInfo(X, TT, CPU, FS);
  return X;
}

static MCCodeGenInfo *createMCS51MCCodeGenInfo(StringRef TT, Reloc::Model RM,
                                                CodeModel::Model CM,
                                                CodeGenOpt::Level OL) {
  MCCodeGenInfo *X = new MCCodeGenInfo();
  X->InitMCCodeGenInfo(RM, CM, OL);
  return X;
}

static MCInstPrinter *createMCS51MCInstPrinter(const Target &T,
                                                unsigned SyntaxVariant,
                                                const MCAsmInfo &MAI,
                                                const MCInstrInfo &MII,
                                                const MCRegisterInfo &MRI,
                                                const MCSubtargetInfo &STI) {
  if (SyntaxVariant == 0)
    return new MCS51InstPrinter(MAI, MII, MRI);
  return 0;
}

extern "C" void LLVMInitializeMCS51TargetMC() {
  // Register the MC asm info.
  RegisterMCAsmInfo<MCS51MCAsmInfo> X(TheMCS51Target);

  // Register the MC codegen info.
  TargetRegistry::RegisterMCCodeGenInfo(TheMCS51Target,
                                        createMCS51MCCodeGenInfo);

  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheMCS51Target, createMCS51MCInstrInfo);

  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheMCS51Target,
                                    createMCS51MCRegisterInfo);

  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheMCS51Target,
                                          createMCS51MCSubtargetInfo);

  // Register the MCInstPrinter.
  TargetRegistry::RegisterMCInstPrinter(TheMCS51Target,
                                        createMCS51MCInstPrinter);
}
