cmake_minimum_required(VERSION 3.18)
project(lab61)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab61 main.cpp)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(lab61 PUBLIC OpenMP::OpenMP_CXX)
endif()