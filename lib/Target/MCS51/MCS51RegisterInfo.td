//===-- MCS51RegisterInfo.td - MCS51 Register defs -------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Declarations that describe the MCS51 register file
//===----------------------------------------------------------------------===//

class MCS51Reg<bits<4> num, string n> : Register<n> {
  field bits<4> Num = num;
  let Namespace = "MCS51";
}

//===----------------------------------------------------------------------===//
//  Registers
//===----------------------------------------------------------------------===//

// Rx 8b registers

def R0  : MCS51Reg<0,  "r0">;
def R1  : MCS51Reg<1,  "r1">;
def R2  : MCS51Reg<2,  "r2">;
def R3  : MCS51Reg<3,  "r3">;
def R4  : MCS51Reg<4,  "r4">;
def R5  : MCS51Reg<5,  "r5">;
def R6  : MCS51Reg<6,  "r6">;
def R7  : MCS51Reg<7,  "r7">;

def RxRegs : RegisterClass<"MCS51", [i8], 8, (sequence "R%u", 0, 7)>;

// Special 8b registers

def A  : MCS51Reg<8,  "a">;
def B  : MCS51Reg<9,  "b">;

def SP  : MCS51Reg<10,  "sp">;

def SFRRegs : RegisterClass<"MCS51", [i8], 8, (add A, B, SP)>;

// 16b data register

def DP  : MCS51Reg<12,  "dp">;

def DPRegs : RegisterClass<"MCS51", [i16], 16, (add DP)>;

