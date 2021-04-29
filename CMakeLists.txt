cmake_minimum_required(VERSION 3.17)
project(Project3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project3 mstprimtest.cpp Edge.cpp Edge.h Graph.cpp Graph.h Vertex.cpp Vertex.h MinHeap.cpp MinHeap.h illegal_exception.cpp illegal_exception.h)