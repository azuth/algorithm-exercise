project (algorithm-exercise)

cmake_minimum_required (VERSION 2.6)

# GTest
ADD_SUBDIRECTORY ("gtest")
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(CPP_COMPILER_FLAGS " -Wall -Wextra -pedantic -g0 -std=c++11 -O3")
add_definitions("${CPP_COMPILER_FLAGS}")

add_subdirectory("src")
