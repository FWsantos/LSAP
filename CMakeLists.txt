cmake_minimum_required(VERSION 3.0.0)
project(LSAP VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(LSAP main.cpp LSAP.h LSAP.cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
