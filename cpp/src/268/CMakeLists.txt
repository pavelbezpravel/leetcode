cmake_minimum_required(VERSION 3.22)
project(missing-number LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(missing-number missing_number.cpp)
target_link_libraries(missing-number
    PRIVATE
        GTest::gtest_main
)
gtest_discover_tests(missing-number)
