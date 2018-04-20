cmake_minimum_required(VERSION 3.10)
project(lab_transformer)

set(CMAKE_CXX_STANDARD 11)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

add_executable(lab_transformer main.cpp transformer.cpp transformer.h FeatureTemplate.cpp FeatureTemplate.h)

