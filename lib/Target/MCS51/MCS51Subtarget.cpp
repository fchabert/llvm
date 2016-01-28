//===-- MCS51Subtarget.cpp - MCS51 Subtarget Information ----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the MCS51 specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#include "MCS51Subtarget.h"
#include "MCS51.h"
#include "llvm/Support/TargetRegistry.h"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "MCS51GenSubtargetInfo.inc"

using namespace llvm;

void MCS51Subtarget::anchor() { }

MCS51Subtarget::MCS51Subtarget(const std::string &TT,
                                 const std::string &CPU,
                                 const std::string &FS) :
  MCS51GenSubtargetInfo(TT, CPU, FS) {
  std::string CPUName = "generic";

  // Parse features string.
  ParseSubtargetFeatures(CPUName, FS);
}
