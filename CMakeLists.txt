cmake_minimum_required(VERSION 3.3)
project(facebook_hacker_cup_2018)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall -O2")

file(GLOB sources "*/*.cpp")
foreach(src ${sources})
  get_filename_component(id ${src} NAME_WE)
  add_executable(${id} ${src})
endforeach()
