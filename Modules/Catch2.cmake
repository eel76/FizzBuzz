if (TARGET Catch2)
  return ()
endif ()

file (DOWNLOAD https://github.com/catchorg/Catch2/releases/download/v2.1.1/catch.hpp "${CMAKE_CURRENT_BINARY_DIR}/include/catch.hpp")
add_library(Catch2 INTERFACE)
target_include_directories (Catch2 INTERFACE "${CMAKE_CURRENT_BINARY_DIR}/include")
