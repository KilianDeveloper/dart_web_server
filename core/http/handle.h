//
// Created by Kilian Markgraf on 25.06.25.
//

#ifndef REQUEST_H
#define REQUEST_H
#include <netinet/in.h>

#define CLOSE_CON 1

int handleHttpRequest(int socketFd, struct sockaddr_in clientAddress, socklen_t clientAddressLength);

#endif //REQUEST_H
