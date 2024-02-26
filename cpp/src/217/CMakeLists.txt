cmake_minimum_required(VERSION 3.22)
project(contains-duplicate LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(contains-duplicate contains_duplicate.cpp)
target_compile_options(contains-duplicate
    PRIVATE
        ${PAVELBEZPRAVEL_LEETCODE_CXX_COMPILER_FLAGS}
)
target_link_libraries(contains-duplicate
    PRIVATE
        GTest::gtest_main
)
gtest_discover_tests(contains-duplicate)
