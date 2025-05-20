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
        demonio.cpp
        demonio.h
        miniBoss.cpp
        miniBoss.h
        boss.cpp
        boss.h
        inventario.cpp
        inventario.h
        juego.cpp
        juego.h
        mazmorra.cpp
        mazmorra.h
        menu.cpp
        menu.h)
