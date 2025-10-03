cmake_minimum_required(VERSION 3.26)
project(PhotocarV2Monitore)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PhotocarV2Test
        PhotocarV2Monitore/PhotocarV2Monitore.ino
        PhotocarV2Monitore/Carcontrol.hh
        PhotocarV2Monitore/Carcontrol.cpp
        main.cc)
