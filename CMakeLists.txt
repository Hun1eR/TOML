#-------------------------------------------------------------------------------------------
# Compile with GCC:
#   rm -rf build && CC=gcc CXX=g++ cmake -B build && cmake --build build --parallel $(nproc)
#
# Compile with Intel C++ Compiler:
#   rm -rf build && CC=icc CXX=icpc cmake -B build && cmake --build build --parallel $(nproc)
#
# Compile with Clang:
#   rm -rf build && CC=clang CXX=clang++ cmake -B build && cmake --build build --parallel $(nproc)
#-------------------------------------------------------------------------------------------


#-------------------------------------------------------------------------------------------
# Project configuration.
#-------------------------------------------------------------------------------------------

# Require a minimum version of cmake.
cmake_minimum_required(VERSION 3.13.5 FATAL_ERROR)

# Set the name of the project.
project("toml")

# Options
option(OPT_DEBUG "Build with debugging information and runtime checks." OFF)
option(OPT_NO_RTTI "Disable RTTI support." OFF)
option(OPT_NO_EXCEPTIONS "Disable exception handling table generation." OFF)
option(OPT_RUN_CPPCHECK "Run Cppcheck (static code analysis tool)." OFF)
option(OPT_RUN_CLANG_TIDY "Run clang-tidy checks." OFF)

# Linking options
option(OPT_LINK_C "Linking with libc library." ON)
option(OPT_LINK_M "Linking with libm library." ON)
option(OPT_LINK_DL "Linking with libdl library." ON)
option(OPT_LINK_LIBGCC "Static linking with libgcc library." ON)
option(OPT_LINK_LIBSTDC "Static linking with libstdc++ library." ON)

# Set the search path for CMake modules to be loaded by the include()
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(Tools)
include(Cppcheck)
include(ClangTidy)

# Add a library target to be built from the source files.
add_library(${CMAKE_PROJECT_NAME} SHARED)

# Set policies
cmake_policy(SET CMP0017 NEW)
cmake_policy(SET CMP0018 NEW)
cmake_policy(SET CMP0063 NEW)
cmake_policy(SET CMP0065 NEW)
cmake_policy(SET CMP0069 NEW)
cmake_policy(SET CMP0077 NEW)
cmake_policy(SET CMP0092 NEW)

# Cotire
include(Cotire)

# Settings
set(CMAKE_RULE_MESSAGES ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)

set_build_type()
set_output_binary_name()
set_default_parallel_jobs()
set_binary_output_directory("bin")


#-------------------------------------------------------------------------------------------
# Add include directories.
#-------------------------------------------------------------------------------------------

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    "sdk/cssdk/include"
    "sdk/metamod/include"
    "sdk/amxx/include"
    "toml/include"
)

# Set the SYSTEM flag to suppress -Weffc++ warnings.
target_include_directories(${CMAKE_PROJECT_NAME} SYSTEM PRIVATE "deps/toml11/include")


#-------------------------------------------------------------------------------------------
# Add source files.
#-------------------------------------------------------------------------------------------

find_source_files("sdk/metamod/src" sources_list)
find_source_files("sdk/amxx/src" sources_list)
find_source_files("toml/src" sources_list)
target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${sources_list})


#-------------------------------------------------------------------------------------------
# Set definitions.
#-------------------------------------------------------------------------------------------

include(Definitions)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    REHLDS_FIXES
    REGAMEDLL_FIXES
    REGAMEDLL_API
    REGAMEDLL_ADD
)


#-------------------------------------------------------------------------------------------
# Set compiler flags.
#-------------------------------------------------------------------------------------------

target_compile_features(${CMAKE_PROJECT_NAME} PUBLIC cxx_std_17)

include(CheckIPOSupported)
check_ipo_supported() # Fatal error if IPO is not supported.

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    VISIBILITY_INLINES_HIDDEN ON
    CXX_VISIBILITY_PRESET hidden
    INTERPROCEDURAL_OPTIMIZATION_DEBUG OFF
    INTERPROCEDURAL_OPTIMIZATION_RELEASE ON
    INTERPROCEDURAL_OPTIMIZATION_MINSIZEREL ON
    INTERPROCEDURAL_OPTIMIZATION_RELWITHDEBINFO OFF
)

if (${CMAKE_CXX_COMPILER_ID} MATCHES "GNU")
    include(GCC)
elseif(${CMAKE_CXX_COMPILER_ID} MATCHES "Intel")
    include(Intel)
elseif(${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
    include(Clang)
endif()
