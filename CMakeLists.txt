cmake_minimum_required(VERSION 3.5.0)
project(LSAP VERSION 0.1.0)

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
    src/Hungarian_n4.cpp
    src/Hungarian_n3.cpp
    src/Preprocess.cpp
    src/Utils.cpp
    src/Tests.cpp
    )

add_executable(LSAP ${headers} ${sources} main.cpp)