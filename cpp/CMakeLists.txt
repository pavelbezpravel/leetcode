cmake_minimum_required(VERSION 3.22)
project(leetcode LANGUAGES CXX)

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/conan.cmake)
conan_cmake_autodetect(settings)
conan_cmake_install(
    PATH_OR_REFERENCE ${CMAKE_SOURCE_DIR}
    INSTALL_FOLDER ${CMAKE_BINARY_DIR}
    BUILD missing
    REMOTE conancenter
    SETTINGS ${settings}
    ENV "CONAN_CMAKE_GENERATOR=${CMAKE_GENERATOR}"
    CONF "tools.cmake.cmaketoolchain:generator=${CMAKE_GENERATOR}"
)
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

# TODO [pavelbezpravel]: support Clang and MSVC.
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    include(cmake/flags.compiler.gnu.cmake)
endif()


find_package(GTest 1.14.0 EXACT REQUIRED)

enable_testing()
include(CTest)
cmake_policy(SET CMP0057 NEW)  # https://gitlab.kitware.com/cmake/cmake/issues/18198
include(GoogleTest)

add_subdirectory(src)
