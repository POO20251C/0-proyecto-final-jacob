cmake_minimum_required(VERSION 3.30)
project(GAME)

set(CMAKE_CXX_STANDARD 20)

add_executable(GAME main.cpp
        personajes.cpp
        personajes.h
        heroes.cpp
        heroes.h
        items.cpp
        items.h
        villanos.cpp
        villanos.h
        pociones.cpp
        pociones.h
        armas.cpp
        armas.h
        armadura.cpp
        armadura.h
        inventario.cpp
        inventario.h
        juego.cpp
        juego.h
        mazmorra.cpp
        mazmorra.h
        menu.cpp
        menu.h
        tienda.cpp
        tienda.h
        descanso.cpp
        descanso.h)
