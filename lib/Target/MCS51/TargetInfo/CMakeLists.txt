include_directories( ${CMAKE_CURRENT_BINARY_DIR}/.. ${CMAKE_CURRENT_SOURCE_DIR}/.. )

add_llvm_library(LLVMMCS51Info
  MCS51TargetInfo.cpp
  )

add_dependencies(LLVMMCS51Info MCS51CommonTableGen)
