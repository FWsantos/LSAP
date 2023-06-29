cmake_minimum_required(VERSION 3.0.0)
project(LSAP VERSION 0.1.0)

include(CTest)
include(CPack)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

set(headers
    include/LSAP.h
    include/Preprocess.h
    include/Utils.h
    include/Tests.h
    include/Types.h
    )

set(sources
    src/LSAP.cpp
    src/Hungarian_v2.cpp
    src/Preprocess.cpp
    src/Utils.cpp
    src/Tests.cpp
    )

add_executable(LSAP ${headers} ${sources} main.cpp)
