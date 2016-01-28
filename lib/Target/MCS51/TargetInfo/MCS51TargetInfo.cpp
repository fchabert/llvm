//===-- MCS51TargetInfo.cpp - MCS51 Target Implementation ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "MCS51.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

Target llvm::TheMCS51Target;

extern "C" void LLVMInitializeMCS51TargetInfo() { 
  RegisterTarget<Triple::mcs51> 
    X(TheMCS51Target, "mcs51", "MCS51 [experimental]");
}
