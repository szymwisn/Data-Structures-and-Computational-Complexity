cmake_minimum_required(VERSION 3.13)
project(241269)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(241269 main.h main.cpp Table.cpp Table.h Menu.cpp Menu.h List.cpp List.h Heap.cpp Heap.h Test.cpp Test.h)