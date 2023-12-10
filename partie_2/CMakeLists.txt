cmake_minimum_required(VERSION 3.26)
project(Agenda_C_partie_2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Agenda_C_partie_2 main.c
        cell.c
        list.c
        timer.c)
