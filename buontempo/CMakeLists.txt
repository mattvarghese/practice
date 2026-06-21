cmake_minimum_required(VERSION 3.20)
project(BuontempoIntroducingCPP)

# Compiler flags
add_compile_options(
    -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wold-style-cast -Wunused -Werror
)

# Debug and Coverage settings
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(--coverage)
    add_link_options(--coverage)
endif()

# C++23 standard configuration
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ==============================================================================
# Executable Targets
# ==============================================================================

# 00 Two Sum
add_executable(00_two_sum 00_two_sum.cpp)

# 01 Hello World variants
add_executable(01_hello_world 01_hello_world.cpp)
add_executable(01_hello_world_cout 01_hello_world_cout.cpp)

# 02 Input Practice
add_executable(02_input 02_input.cpp)
add_executable(02_input_experiment 02_input_experiment.cpp)

# 05 Stock Prices
add_executable(05_main 05_main.cpp 05_input.cpp)
