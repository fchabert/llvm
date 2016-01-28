//===-- MCS51SelectionDAGInfo.h - MCS51 SelectionDAG Info -----*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines the MCS51 subclass for TargetSelectionDAGInfo.
//
//===----------------------------------------------------------------------===//

#ifndef MCS51SELECTIONDAGINFO_H
#define MCS51SELECTIONDAGINFO_H

#include "llvm/Target/TargetSelectionDAGInfo.h"

namespace llvm {

class MCS51TargetMachine;

class MCS51SelectionDAGInfo : public TargetSelectionDAGInfo {
public:
  explicit MCS51SelectionDAGInfo(const MCS51TargetMachine &TM);
  ~MCS51SelectionDAGInfo();
};

}

#endif
