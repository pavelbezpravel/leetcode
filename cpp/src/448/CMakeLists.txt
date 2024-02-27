cmake_minimum_required(VERSION 3.22)
project(findDisappearedNumbers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(findDisappearedNumbers find_disappeared_numbers.cpp)
target_compile_options(findDisappearedNumbers
    PRIVATE
        ${PAVELBEZPRAVEL_LEETCODE_CXX_COMPILER_FLAGS}
)
target_link_libraries(findDisappearedNumbers
    PRIVATE
        GTest::gtest_main
)
gtest_discover_tests(findDisappearedNumbers)
