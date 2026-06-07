cmake_minimum_required(VERSION 3.20)
project(LeetCode_CPP)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_STANDARD 23)

# Download Catch2 header automatically if not present
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.10 # Stable v2 is header-only
)
FetchContent_MakeAvailable(Catch2)

# Target for Add Two Numbers
add_executable(l00001_two_sum_test l00001_two_sum_test.cpp)
target_link_libraries(l00001_two_sum_test Catch2::Catch2)
