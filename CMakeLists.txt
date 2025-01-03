cmake_minimum_required(VERSION 3.26)
project(3d_raytracer_cpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(includes)

add_executable(3d_raytracer_cpp src/main.cpp src/intersection.cpp src/math.cpp src/canvas.cpp src/ray.cpp src/sphere.cpp
               src/world.cpp src/light.cpp src/material.cpp src/lighting.cpp)