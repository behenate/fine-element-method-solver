cmake_minimum_required(VERSION 3.21)
project(Finite_Element_Method_Project)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_INCLUDE_PATH boost)
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
        functions/GaussElimination.cpp headers/GaussElimination.h
        boost/iostreams/device/file_descriptor.hpp
        boost/iostreams/stream.hpp
        boost/version.hpp
        boost/utility.hpp
        boost/tuple/tuple.hpp
        boost/filesystem.hpp
    headers/gnuplot-iostream.h
)
