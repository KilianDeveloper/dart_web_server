//
// Created by Kilian Markgraf on 25.06.25.
//

#ifndef REQUEST_H
#define REQUEST_H
#include <stdio.h>
#include <netinet/in.h>

void handleHttpRequest(int sock_fd, struct sockaddr_in client_addr, socklen_t client_addr_len);

#endif //REQUEST_H
