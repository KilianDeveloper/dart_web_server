#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include "socket.h"
#include "../error.h"
#include <fcntl.h>

int createSocket(int port) {
    int socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd < 0) {
        printError("socket()");
        return -1;
    }

    const int val = 1;
    setsockopt(socketFd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    struct sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int ret = bind(socketFd, (struct sockaddr *) &addr, sizeof(addr));
    if (ret < 0) {
        printError("bind()");
        return -2;
    }
    printf("socket: bind success\n");
    ret = listen(socketFd, SOMAXCONN);
    if (ret < 0) {
        printError("bind()");
        return -3;
    }
    printf("socket: listening for requests on port %d...\n", port);

    return socketFd;
}

int handleRequestAsync(const int connectionFd, const struct sockaddr_in clientAddress, const socklen_t clientAddressLength,
                        void (*onRequest)(int, struct sockaddr_in, socklen_t)) {
    const pid_t childPid = fork();
    if (childPid < 0) {
        return -1;
    }

    if (childPid == 0) {
        printf("fork\n");
        (*onRequest)(connectionFd, clientAddress, clientAddressLength);

        return 0;
    }
    close(connectionFd);

    return 0;
}

void handleRequests(int socketFd, const bool *running, void (*onRequest)(int, struct sockaddr_in, socklen_t)) {
    while (*running) {
        struct sockaddr_in client_addr = {};
        socklen_t client_addr_len = sizeof(client_addr);
        const int conn_fd = accept(socketFd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (conn_fd < 0) {
            continue;
        }

        //set socket to be non-blocking
        int flags = fcntl(conn_fd, F_GETFL, 0);
        if (flags == -1) return;
        fcntl(conn_fd, F_SETFL, flags | O_NONBLOCK);

        handleRequestAsync(conn_fd, client_addr, client_addr_len, onRequest);
    }
}


void closeSocket(const int socketFd) {
    close(socketFd);
}
