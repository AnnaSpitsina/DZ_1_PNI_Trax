cmake_minimum_required(VERSION 3.5)

project(DZ_1_PNI_Trax LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DZ_1_PNI_Trax main.cpp function.cpp function.h)

install(TARGETS DZ_1_PNI_Trax
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
