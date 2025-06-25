//
// Created by Kilian Markgraf on 25.06.25.
//

#include "request.h"

#include "../../../../../../Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdlib.h"
#include "../communication/protocol.h"

void handleHttpRequest(int sock_fd, struct sockaddr_in client_addr, socklen_t client_addr_len) {
    struct IpV4Address address =  ipv4IntToAddress(client_addr.sin_addr.s_addr);
    char* ip = ipv4ToString(address);
    //TODO port
    printf("Request started from %s:%hu\n", ip, client_addr.sin_port);
    free(ip);
}
