cmake_minimum_required(VERSION 3.20)
project(naiveRSA)
set(CMAKE_CXX_STANDARD 14)
set(cmake_build_type DEBUG)

add_executable(naiveRSA main.cpp include/BigInteger.cpp)