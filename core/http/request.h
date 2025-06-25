//
// Created by Kilian Markgraf on 25.06.25.
//

#ifndef REQUEST_H
#define REQUEST_H
#include <netinet/in.h>

void handleHttpRequest(int socketFd, struct sockaddr_in clientAddress, socklen_t clientAddressLength);

#endif //REQUEST_H
