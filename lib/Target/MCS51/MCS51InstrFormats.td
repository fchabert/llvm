//===-- MCS51InstrFormats.td - MCS51 Instruction Formats -*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Instruction format superclass
//===----------------------------------------------------------------------===//

class MCS51Inst<int sz, dag outs, dag ins, string asmstr, list<dag> pattern>
  : Instruction
{
  let Namespace = "MCS51";

  field bits<24> Inst;

  dag OutOperandList = outs;
  dag InOperandList = ins;

  let AsmString = asmstr;
  let Pattern = pattern;
  let Itinerary = itin;
  let Size = sz;

  field bits<16> SoftFail = 0;
}

//===----------------------------------------------------------------------===//
// Instruction formats
//===----------------------------------------------------------------------===//

// First byte formats

class OpcByteInst<bits<5=8> opc, int sz, dag outs, dag ins, string asmstr, list<dag> pattern>
  : MCS51Inst<sz, outs, ins, asmstr, pattern> {
  let Inst{7-0} = opc;
}

class RnByteInst<bits<5> opc, int sz, dag outs, dag ins, string asmstr, list<dag> pattern>
  : MCS51Inst<sz, outs, ins, asmstr, pattern> {
  bits<3> rn;

  let Inst{2-0} = rn;
  let Inst{7-3} = opc;
}

class RiByteInst<bits<7> opc, int sz, dag outs, dag ins, string asmstr, list<dag> pattern>
  : MCS51Inst<sz, outs, ins, asmstr, pattern> {
  bits<1> ri;

  let Inst{0} = ri;
  let Inst{7-1} = opc;
}

// Complete formats

class OpcInst<bits<8> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : OpcByteInst<1, outs, ins, asmstr, pattern>;
// NOP
// RET
// RETI
// CPL C
// CLR C
// SETB C
// RR A
// INC A
// RRC A
// DEC A
// RL A
// RCL A
// SWAP A
// DA  A
// CPL A
// CLR A
// MOVC A, @A+PC
// MOVC A, @A+DPTR
// MOVX A, @DPTR
// MOVX @DPTR, A
// JMP  @A+DPTR
// INC DPTR
// MUL AB
// DIV AB

class RnInst<bits<5> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : RnByteInst<opc, 1, outs, ins, asmstr, pattern>;
// INC Rn
// DEC Rn
// ADD A, Rn
// ADDC A, Rn
// ORL A, Rn
// ANL A, Rn
// XRL A, Rn
// XCH A, Rn
// SUBB A, Rn
// MOV A, Rn
// MOV Rn, A

class RiInst<bits<7> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : RiByteInst<opc, 1, outs, ins, asmstr, pattern>;
// INC Ri
// DEC Ri
// ADD A, Ri
// ADDC A, Ri
// ORL A, Ri
// ANL A, Ri
// XRL A, Ri
// XCH A, Ri
// SUBB A, Ri
// MOV A, Ri
// MOVX A, Ri
// XCHD  A, Ri
// MOVX Ri, A
// MOV Ri, A

class ImmInst<bits<8> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : OpcByteInst<opc, 2, outs, ins, asmstr, pattern> {
  bits<8> imm;

  let Inst{15-8} = imm;
}
// ADD A, #immediate
// ADDC A, #immediate
// ORL A, #immediate
// ANL A, #immediate
// XRL A, #immediate
// MOV A, #immediate
// SUBB A, #immediate

class RnImmInst<bits<5> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : RnByteInst<opc, 2, outs, ins, asmstr, pattern> {
  bits<8> imm;

  let Inst{15-8} = imm;
}
// MOV Rn, #immediate

class RiImmInst<bits<7> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : RiByteInst<opc, 2, outs, ins, asmstr, pattern> {
  bits<8> imm;

  let Inst{15-8} = imm
}
// MOV Ri, #immediate

class OffInst<bits<8> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : OpcByteInst<opc, 2, outs, ins, asmstr, pattern> {
  bits<8> off;

  let Inst{15-8} = off;
}
// SJMP offset
// JC offset
// JNC offset
// JZ offset
// JNZ offset

class Addr11Inst<bits<5> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : MCS51Inst<2, outs, ins, asmstr, pattern> {
  bits<11> addr;

  let Inst{15-8} = addr{7-0};
  let Inst{7-5} = addr{10-8};
  let Inst{4-0} = opc;
}
// AJMP addr11
// ACALL addr11

class DirInst<bits<8> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : OpcByteInst<opc, 2, outs, ins, asmstr, pattern> {
  bits<8> dir;

  let Inst{15-8} = dir;
}
// INC direct
// DEC direct
// PUSH direct
// POP direct
// ADD A, direct
// ADDC A, direct
// ORL A, direct
// ANL A, direct
// XRL A, direct
// SUBB A, direct
// XCH A, direct
// MOV A, direct
// ORL direct, A
// ANL direct, A
// XRL direct, A
// MOV direct, A

class DirInst<bits<8> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : OpcByteInst<opc, 2, outs, ins, asmstr, pattern> {
  bits<8> bit;

  let Inst{15-8} = bit;
}
// MOV bit, C
// ORL C, bit
// ANL C, bit
// MOV C, bit
// ORL C, /bit
// ANL C, /bit
// CPL bit
// CLR bit
// SETB bit

class RnDirInst<bits<5> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : RnByteInst<opc, 2, outs, ins, asmstr, pattern> {
  bits<8> dir;

  let Inst{15-8} = dir;
}
// MOV direct, Rn
// MOV Rn, direct

class RiDirInst<bits<7> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : RiByteInst<opc, 2, outs, ins, asmstr, pattern> {
  bits<8> dir;

  let Inst{15-8} = dir;
}
// MOV direct, Ri
// MOV Ri, direct

class RnOffInst<bits<5> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : RnByteInst<opc, 2, outs, ins, asmstr, pattern> {
  bits<8> off;

  let Inst{15-8} = off;
}
// DJNZ Rn, offset

class Addr16Inst<bits<8> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : OpcByteInst<opc, 3, outs, ins, asmstr, pattern> {
  bits<16> addr;

  let Inst{23-8} = addr;
}
// LJMP addr16
// LCALL addr16

class BitOffInst<bits<8> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : OpcByteInst<opc, 3, outs, ins, asmstr, pattern> {
  bits<8> bit;
  bits<8> off;

  let Inst{23-16} = off;
  let Inst{15-8} = bit;
}
// JBC bit, offset
// JB bit, offset
// JNB bit, offset

class DirImmInst<bits<8> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : OpcByteInst<opc, 3, outs, ins, asmstr, pattern> {
  bits<8> dir;
  bits<8> imm;

  let Inst{23-16} = imm;
  let Inst{15-8} = dir;
}
// ORL direct, #immediate
// ANL direct, #immediate
// XRL direct, #immediate
// MOV direct, #immediate

class DirDirInst<bits<8> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : OpcByteInst<opc, 3, outs, ins, asmstr, pattern> {
  bits<8> dir;
  bits<8> dir;

  let Inst{23-16} = dir;
  let Inst{15-8} = dir;
}
// MOV direct, direct

class Imm16Inst<bits<8> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : OpcByteInst<opc, 3, outs, ins, asmstr, pattern> {
  bits<16> imm;

  let Inst{23-8} = imm;
}
// MOV DPTR, #immediate

class ImmOffInst<bits<8> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : OpcByteInst<opc, 3, outs, ins, asmstr, pattern> {
  bits<8> imm;
  bits<8> off;

  let Inst{23-16} = off;
  let Inst{15-8} = imm;
}
// CJNE A, #immediate, offset

class RnImmOffInst<bits<8> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : RnByteInst<opc, 3, outs, ins, asmstr, pattern> {
  bits<8> imm;
  bits<8> off;

  let Inst{23-16} = off;
  let Inst{15-8} = imm;
}
// CJNE Rn, #immediate, offset

class RiImmOffInst<bits<8> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : RiByteInst<opc, 3, outs, ins, asmstr, pattern> {
  bits<8> imm;
  bits<8> off;

  let Inst{23-16} = off;
  let Inst{15-8} = imm;
}
// CJNE Ri, #immediate, offset

class DirOffInst<bits<8> opc, dag outs, dag ins, string asmstr, list<dag> pattern>
  : OpcByteInst<opc, 3, outs, ins, asmstr, pattern> {
  bits<8> dir;
  bits<8> off;

  let Inst{23-16} = off;
  let Inst{15-8} = dir;
}
// CJNE A, direct, offset
// DJNZ  direct, offset
