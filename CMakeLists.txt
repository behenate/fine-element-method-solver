cmake_minimum_required(VERSION 3.21)
project(Finite_Element_Method_Project)

set(CMAKE_CXX_STANDARD 23)
include_directories(functions headers)

add_executable(
        Finite_Element_Method_Project
        main.cpp
        functions/BL.cpp
        functions/e.cpp
        functions/Gaussian_Quadrature.cpp
        functions/xi.cpp
        headers/BL.h
        headers/e.h
        headers/Gaussian_Quadrature.h
        headers/xi.h
        functions/GaussElimination.cpp headers/GaussElimination.h)
