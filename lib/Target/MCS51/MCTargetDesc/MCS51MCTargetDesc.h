//===-- MCS51MCTargetDesc.h - MCS51 Target Descriptions -------*- C++ -*-===//
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

#ifndef MCS51MCTARGETDESC_H
#define MCS51MCTARGETDESC_H

namespace llvm {
class Target;

extern Target TheMCS51Target;

} // End llvm namespace

// Defines symbolic names for MCS51 registers.
// This defines a mapping from register name to register number.
#define GET_REGINFO_ENUM
#include "MCS51GenRegisterInfo.inc"

// Defines symbolic names for the MCS51 instructions.
#define GET_INSTRINFO_ENUM
#include "MCS51GenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "MCS51GenSubtargetInfo.inc"

#endif
