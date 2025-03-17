cmake_minimum_required(VERSION 3.10.0)
project(leetcode VERSION 1.0.0)

include(CTest)
enable_testing()

set(DCMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

include_directories(Solutions)

add_executable(main main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
