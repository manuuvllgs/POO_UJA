cmake_minimum_required(VERSION 3.24)
project(g1)

set(CMAKE_CXX_STANDARD 17)

add_executable(g1.exe main.cpp Jornada.cpp Jornada.h Actividad.cpp Actividad.h Ubicacion.cpp Ubicacion.h
        Natacion.cpp
        NatacionEx.cpp)
