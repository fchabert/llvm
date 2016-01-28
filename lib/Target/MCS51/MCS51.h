//==-- MCS51.h - Top-level interface for MCS51 representation --*- C++ -*-==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the entry points for global functions defined in
// the LLVM MCS51 backend.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TARGET_MCS51_H
#define LLVM_TARGET_MCS51_H

#include "MCTargetDesc/MCS51MCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace MCS51CC {
  // MCS51 specific condition code.
  enum CondCodes {
    COND_E  = 0,  // aka COND_Z
    COND_NE = 1,  // aka COND_NZ
    COND_HS = 2,  // aka COND_C
    COND_LO = 3,  // aka COND_NC
    COND_GE = 4,
    COND_L  = 5,

    COND_INVALID = -1
  };
}

namespace llvm {
  class MCS51TargetMachine;
  class FunctionPass;
  class formatted_raw_ostream;

  FunctionPass *createMCS51ISelDag(MCS51TargetMachine &TM,
                                    CodeGenOpt::Level OptLevel);

  FunctionPass *createMCS51BranchSelectionPass();

} // end namespace llvm;

#endif
