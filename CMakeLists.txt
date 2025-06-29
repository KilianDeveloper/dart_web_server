cmake_minimum_required(VERSION 3.16.3)
project(dart_backend C)

set(CMAKE_C_STANDARD 11)

add_executable(dart_backend main.c
        core/network/socket.c
        core/network/socket.h
        core/error.c
        core/error.h
        core/http/request.c
        core/http/request.h
        core/network/address.c
        core/network/address.h
        core/http/header.c
        core/http/header.h
        core/util/read.c
        core/util/read.h
)
