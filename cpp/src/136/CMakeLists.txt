cmake_minimum_required(VERSION 3.22)
project(single-number LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(single-number single_number.cpp)
target_compile_options(single-number
    PRIVATE
        ${PAVELBEZPRAVEL_LEETCODE_CXX_COMPILER_FLAGS}
)
target_link_libraries(single-number
    PRIVATE
        GTest::gtest_main
)
gtest_discover_tests(single-number)
