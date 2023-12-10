cmake_minimum_required(VERSION 3.26)
project(Agenda_C_partie_3 C)

set(CMAKE_C_STANDARD 11)

add_executable(Agenda_C_partie_3 main.c
        agenda.c
        cell.c
        contact.c
        genericity.c
        list.c
        rdv.c
        timer.c)
