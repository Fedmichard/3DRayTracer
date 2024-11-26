cmake_minimum_required(VERSION 3.26)
project(3d_raytracer_cpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(includes)

add_executable(3d_raytracer_cpp src/main.cpp src/math.cpp)