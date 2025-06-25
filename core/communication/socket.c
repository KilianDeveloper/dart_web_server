#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include "socket.h"
#include "../error.h"

int createSocket(int port) {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        printError("socket()");
        return -1;
    }

    const int val = 1;
    setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    struct sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int ret = bind(sock_fd, (struct sockaddr *) &addr, sizeof(addr));
    if (ret < 0) {
        printError("bind()");
        return -2;
    }
    printf("socket: bind success\n");
    ret = listen(sock_fd, SOMAXCONN);
    if (ret < 0) {
        printError("bind()");
        return -3;
    }
    printf("socket: listening for requests on port %d...\n", port);

    return sock_fd;
}

void handleRequests(int sock_fd, const bool* running, void (*onRequest)(int, struct sockaddr_in, socklen_t client_len)) {
    while (*running) {
        struct sockaddr_in client_addr = {};
        socklen_t client_addr_len = sizeof(client_addr);
        int conn_fd = accept(sock_fd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (conn_fd < 0) {
            continue;
        }
        (*onRequest)(conn_fd, client_addr, client_addr_len);
        printf("%u\n", client_addr.sin_addr.s_addr);

        close(conn_fd);
    }
}

void closeSocket(const int sock_fd) {
    close(sock_fd);
}
