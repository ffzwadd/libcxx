set(LIBCXXABI_USE_LLVM_UNWINDER ON CACHE BOOL "")
set(LIBCXX_TARGET_TRIPLE "armv8-linux-gnueabihf" CACHE STRING "")
set(CMAKE_CXX_FLAGS "-mthumb" CACHE STRING "")
set(CMAKE_C_FLAGS "-mthumb" CACHE STRING "")
set(LIBCXX_ENABLE_EXCEPTIONS OFF CACHE BOOL "")
set(LIBCXXABI_ENABLE_EXCEPTIONS OFF CACHE BOOL "")
