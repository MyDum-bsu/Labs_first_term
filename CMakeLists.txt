cmake_minimum_required(VERSION 3.20)
project(Labs_first_term)

set(CMAKE_CXX_STANDARD 14)

add_executable(Labs_first_term lab4.8A.cpp lab4.8B.cpp test4.8.cpp lab4.8A.h test4.8.cpp lab4.8B.h)

project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run test4.8.cpp lab4.8A.h lab4.8B.h lab4.8A.cpp lab4.8B.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)