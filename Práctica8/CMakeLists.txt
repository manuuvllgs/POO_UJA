cmake_minimum_required(VERSION 3.28)
project(project_pr8)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project_pr8
        Cofre.cpp
        Cofre.h
        Item.cpp
        Item.h
        main.cpp
        Bloque.cpp
        Filete.cpp
        Espada.cpp
        ItemApilable.cpp
        EmptyContainer.cpp
        ItemUsable.cpp)
