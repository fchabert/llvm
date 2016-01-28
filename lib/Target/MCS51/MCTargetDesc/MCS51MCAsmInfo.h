//===-- MCS51MCAsmInfo.h - MCS51 asm properties --------------*- C++ -*--===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the declaration of the MCS51MCAsmInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef MCS51TARGETASMINFO_H
#define MCS51TARGETASMINFO_H

#include "llvm/MC/MCAsmInfo.h"

namespace llvm {
  class StringRef;

  class MCS51MCAsmInfo : public MCAsmInfo {
    virtual void anchor();
  public:
    explicit MCS51MCAsmInfo(StringRef TT);
  };

} // namespace llvm

#endif
