//===-- MCS51SelectionDAGInfo.cpp - MCS51 SelectionDAG Info -------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the MCS51SelectionDAGInfo class.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "MCS51-selectiondag-info"
#include "MCS51TargetMachine.h"
using namespace llvm;

MCS51SelectionDAGInfo::MCS51SelectionDAGInfo(const MCS51TargetMachine &TM)
  : TargetSelectionDAGInfo(TM) {
}

MCS51SelectionDAGInfo::~MCS51SelectionDAGInfo() {
}
