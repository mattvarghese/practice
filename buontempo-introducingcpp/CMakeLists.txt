cmake_minimum_required(VERSION 3.20)
project(BuontempoIntroducingCPP)

# Place this at the top of your CMakeLists.txt (below the project name)
# This injects these flags into EVERY target compiled in this directory tree
# add_compile_options(-Wall -Wextra -Wpedantic)
add_compile_options(-Wall)

# Force debug symbols for seamless VSCode visual step-through
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Strict C++23 standard configuration
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Enforces clean, portable ISO C++ over GNU variations
set(CMAKE_CXX_EXTENSIONS OFF)

# ==============================================================================
# GoogleTest (gtest) Infrastructure Setup via FetchContent
# ==============================================================================
include(FetchContent)

# Declare the remote GitHub repository metadata for GoogleTest
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  # v1.15.2 is a modern, stable release fully compatible with C++23/26
  GIT_TAG        v1.15.2 
)

# Forcing gtest to link against the standard library's shared runtime flags.
# This prevents windows/linux compiler symbol mismatch warnings down the line.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Download and make the GoogleTest targets available to our build engine
FetchContent_MakeAvailable(googletest)

# ==============================================================================
# Test Engine Initialization (Must happen before add_test calls!)
# ==============================================================================
include(CTest)
enable_testing()

# ==============================================================================
# Executable Targets & Verification Suites
# ==============================================================================

# Example Target: Registering your first tracking file from the book
# (Swap out 'chapter1_intro.cpp' with whatever file name you create first)
# add_executable(ch1_intro chapter1_intro.cpp)


# Two Sum Automated Unit Test Suite
# Compiles BOTH your implementation file and the test definitions into the test executable
add_executable(00_two_sum_test 00_two_sum.cpp 00_two_sum_test.cpp)

# Link the core GoogleTest library and its standard main entry point runner
target_link_libraries(00_two_sum_test gtest_main)

# Register the test binary target as an official CTest runnable entity
add_test(NAME TwoSumTest COMMAND 00_two_sum_test)

# --- Hello World Standalone App ---
# This generates the isolated './01_hello_world' and './01_hello_world_cout' binaries used below
add_executable(01_hello_world 01_hello_world.cpp)
add_executable(01_hello_world_cout 01_hello_world_cout.cpp)


# --- Hello World Integration Test Suite ---
# Compiles ONLY the test logic so we don't trigger duplicate main() definition conflicts
add_executable(01_hello_world_test 01_hello_world_test.cpp)
target_link_libraries(01_hello_world_test gtest_main)

# Tells CMake that the test executable depends on the app binaries being built first
add_dependencies(01_hello_world_test 01_hello_world)
add_dependencies(01_hello_world_test 01_hello_world_cout)

# Register the test binary target as an official CTest runnable entity
add_test(NAME HelloWorldTest COMMAND 01_hello_world_test)
