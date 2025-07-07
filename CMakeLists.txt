cmake_minimum_required(VERSION 3.16.3)
project(dart_backend C)

set(CMAKE_C_STANDARD 11)

add_executable(dart_backend main.c
        core/network/socket.c
        core/network/socket.h
        core/error.c
        core/error.h
        core/http/handle.c
        core/http/handle.h
        core/network/address.c
        core/network/address.h
        core/http/request/header.c
        core/http/request/header.h
        core/util/read.c
        core/util/read.h
        core/http/request/start.c
        core/http/request/start.h
        core/http/response/build.c
        core/http/response/build.h
        core/http/response/header.c
        core/http/response/header.h
)
