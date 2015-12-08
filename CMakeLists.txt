cmake_minimum_required(VERSION 2.8)

project(algorithms C CXX)

include_directories(include)

file(GLOB SOURCES src/*.cpp)

add_library(algs ${SOURCES})

add_executable(test_list test/test_list.cpp)
target_link_libraries(test_list algs)

add_executable(test_hash test/test_hash.cpp)
target_link_libraries(test_hash algs)
