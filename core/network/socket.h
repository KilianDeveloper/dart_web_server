//
// Created by Kilian Markgraf on 25.06.25.
//
#pragma once

#include "stdbool.h"
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SOCKET_H
#define SOCKET_H

/**
 * Handle the incoming requests for a socket
 * @param socketFd the socket file descriptor to listen to
 * @param running A pointer to a value, if the handling should still run
 * @param onRequest A pointer to a procedure, that handles a request on the given file-descriptor
 */
void handleRequests(int socketFd, const bool* running, int (*onRequest)(int, struct sockaddr_in, socklen_t));

/**
 * Create a new socket for duplex-communication,
 * @param port The port where the socket should be accessible
 * @return The file-descriptor for the new created socket or a negative value if there was an error
 */
int createSocket(int port);

/**
 * Close a socket
 * @param socketFd the file-descriptor for the socket
 */
void closeSocket(int socketFd);

#endif //SOCKET_H
