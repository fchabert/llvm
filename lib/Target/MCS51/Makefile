##===- lib/Target/MCS51/Makefile --------------------------*- Makefile -*-===##
# 
#                     The LLVM Compiler Infrastructure
#
# This file is distributed under the University of Illinois Open Source 
# License. See LICENSE.TXT for details.
# 
##===----------------------------------------------------------------------===##

LEVEL = ../../..
LIBRARYNAME = LLVMMCS51CodeGen
TARGET = MCS51

# Make sure that tblgen is run, first thing.
BUILT_SOURCES = MCS51GenRegisterInfo.inc MCS51GenInstrInfo.inc \
		MCS51GenAsmWriter.inc \
		MCS51GenDAGISel.inc MCS51GenCallingConv.inc \
		MCS51GenSubtargetInfo.inc

DIRS = InstPrinter TargetInfo MCTargetDesc

include $(LEVEL)/Makefile.common

