include_directories( ${CMAKE_CURRENT_BINARY_DIR}/.. ${CMAKE_CURRENT_SOURCE_DIR}/.. )

add_llvm_library(LLVMMCS51AsmPrinter
  MCS51InstPrinter.cpp
  )

add_dependencies(LLVMMCS51AsmPrinter MCS51CommonTableGen)
