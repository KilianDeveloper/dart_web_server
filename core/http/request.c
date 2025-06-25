//
// Created by Kilian Markgraf on 25.06.25.
//

#include "request.h"

#include <stdio.h>
#include <stdlib.h>

#include "../network/address.h"

void handleHttpRequest(int socketFd, struct sockaddr_in clientAddress, socklen_t clientAddressLength) {
    struct IpV4Address address = networkToHostAddress(clientAddress.sin_addr.s_addr, clientAddress.sin_port);
    char *ip = addressToString(address);

    printf("Request started from %s\n", ip);
    free(ip);
}
