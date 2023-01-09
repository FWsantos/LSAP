cmake_minimum_required(VERSION 3.0.0)
project(LSAP VERSION 0.1.0)

include(CTest)
include(CPack)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

set(headers
    include/LSAP.h
    )

set(sources
    src/LSAP.cpp
    )

add_executable(LSAP ${headers} ${sources} main.cpp)
