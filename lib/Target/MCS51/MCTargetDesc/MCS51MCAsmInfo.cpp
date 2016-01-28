//===-- MCS51MCAsmInfo.cpp - MCS51 asm properties -----------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the declarations of the MCS51MCAsmInfo properties.
//
//===----------------------------------------------------------------------===//

#include "MCS51MCAsmInfo.h"
#include "llvm/ADT/StringRef.h"
using namespace llvm;

void MCS51MCAsmInfo::anchor() { }

MCS51MCAsmInfo::MCS51MCAsmInfo(StringRef TT) {
  PointerSize = CalleeSaveStackSlotSize = 2;

  PrivateGlobalPrefix = ".L";
  WeakRefDirective ="\t.weak\t";
  CommentString = ";";

  AlignmentIsInBytes = false;
  AllowNameToStartWithDigit = true;
  UsesELFSectionDirectiveForBSS = true;
}
