cmake_minimum_required(VERSION 3.20)
project(naiveRSA)

set(CMAKE_CXX_STANDARD 14)
set(cmake_build_type RELEASE)

set(CMAKE_C_FLAGS_RELEASE = -O1 -DNDEBUG)

include_directories(.)

add_executable(naiveRSA
        main.cpp
        include/BigInteger.h
        include/BigInteger.cpp)