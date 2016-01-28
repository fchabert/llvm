add_llvm_library(LLVMMCS51Desc
  MCS51MCTargetDesc.cpp
  MCS51MCAsmInfo.cpp
  )

add_dependencies(LLVMMCS51Desc MCS51CommonTableGen)
