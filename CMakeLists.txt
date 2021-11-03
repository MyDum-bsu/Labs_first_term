cmake_minimum_required(VERSION 3.20)
project(Labs_first_term)

set(CMAKE_CXX_STANDARD 14)

add_executable(Labs_first_term quadratic_equations.cpp quadratic_equations.h main.cpp)

project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run quadratic_equations.cpp quadratic_equations.h main.cpp tests.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)