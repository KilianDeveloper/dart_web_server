cmake_minimum_required(VERSION 3.16.3)
project(dart_backend C)

set(CMAKE_C_STANDARD 11)

add_executable(dart_backend main.c
        core/communication/socket.c
        core/communication/socket.h
        core/error.c
        core/error.h
        core/http/request.c
        core/http/request.h
        core/communication/protocol.c
        core/communication/protocol.h
)
