cmake_minimum_required(VERSION 3.17)
project(multimap)

set(CMAKE_CXX_STANDARD 20)

add_executable(multimap sources/main.cpp sources/HashMap.h sources/HashNode.h)