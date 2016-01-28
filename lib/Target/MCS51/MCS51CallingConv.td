//==- MCS51CallingConv.td - Calling Conventions for MCS51 -*- tablegen -*-==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This describes the calling conventions for MCS51 architecture.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// MCS51 Return Value Calling Convention
//===----------------------------------------------------------------------===//

// 1-bit values    Carry
// 8-bit values    R1
// 16-bit values   R3:R2
// 24-bit values   R3:R2:R1
// 32-bit values   R5:R4:R3:R2

def RetCC_MCS51 : CallingConv<[
  // i8 are returned in register R1
  CCIfType<[i8], CCAssignToReg<[R1]>>,
]>;

//===----------------------------------------------------------------------===//
// MCS51 Argument Calling Conventions
//===----------------------------------------------------------------------===//

// 1-bit values    B.0, B.1, B.2, B.3, B.4, B.5, B.6, B.7
// 8-bit values    R1, R2, R3, R4, R5
// 16-bit values   R3:R2 or R5:R4
// 24-bit values   R3:R2:R1
// 32-bit values   R5:R4:R3:R2

def CC_MCS51 : CallingConv<[
  // Pass by value if the byval attribute is given
  CCIfByVal<CCPassByVal<1, 1>>,

  // The first 4 integer arguments of non-varargs functions are passed in
  // integer registers.
  CCIfNotVarArg<CCIfType<[i8], CCAssignToReg<[R1, R2, R3, R4, R5]>>>,

  // Integer values get stored in stack slots
  CCIfType<[i8], CCAssignToStack<1, 1>>
]>;
