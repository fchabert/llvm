set(LLVM_TARGET_DEFINITIONS MCS51.td)

tablegen(LLVM MCS51GenRegisterInfo.inc -gen-register-info)
tablegen(LLVM MCS51GenInstrInfo.inc -gen-instr-info)
tablegen(LLVM MCS51GenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM MCS51GenDAGISel.inc -gen-dag-isel)
tablegen(LLVM MCS51GenCallingConv.inc -gen-callingconv)
tablegen(LLVM MCS51GenSubtargetInfo.inc -gen-subtarget)
add_public_tablegen_target(MCS51CommonTableGen)

add_llvm_target(MCS51CodeGen
  MCS51BranchSelector.cpp
  MCS51ISelDAGToDAG.cpp
  MCS51ISelLowering.cpp
  MCS51InstrInfo.cpp
  MCS51FrameLowering.cpp
  MCS51MachineFunctionInfo.cpp
  MCS51RegisterInfo.cpp
  MCS51Subtarget.cpp
  MCS51TargetMachine.cpp
  MCS51SelectionDAGInfo.cpp
  MCS51AsmPrinter.cpp
  MCS51MCInstLower.cpp
  )

add_dependencies(LLVMMCS51CodeGen MCS51CommonTableGen intrinsics_gen)

add_subdirectory(InstPrinter)
add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
