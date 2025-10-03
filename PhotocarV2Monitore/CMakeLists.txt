cmake_minimum_required(VERSION 3.26)
project(.)

set(CMAKE_CXX_STANDARD 14)

include_directories(..)

add_executable(PhotocarV2Test
        PhotocarV2Monitore.ino
        Carcontrol.hh
        Carcontrol.cpp
        ../main.cc)
