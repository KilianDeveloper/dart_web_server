//
// Created by Kilian Markgraf on 25.06.25.
//

#include "handle.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "response/build.h"

#include "string.h"
#include "request/start.h"
#include "../network/address.h"
#include "response/header.h"

int handleHttpRequest(int socketFd, struct sockaddr_in clientAddress, socklen_t clientAddressLength) {
    struct IpV4Address address = networkToHostAddress(clientAddress.sin_addr.s_addr, clientAddress.sin_port);
    char *ip = addressToString(address);

    char *method = parseHttpMethod(socketFd);

    printf("Request started from %s\n", ip);
    fflush(stdout);
    free(ip);

    struct HttpResponse response;

    response.body.size = 0;
    response.body.content = malloc(1);
    if (!response.body.content) {
        return -1;
    }
    char* body = "buttonHello World!";

    response.body.content = body;
    response.body.size = strlen(body) + 1;

    char* httpVersion = "HTTP/1.1";
    char* statusText = "OK";

    response.startLine.httpVersion = httpVersion;
    response.startLine.httpVersionSize = strlen(httpVersion);
    response.startLine.statusCode = 200;
    response.startLine.statusText = statusText;

    response.startLine.statusTextSize = strlen(statusText);
    response.headers.size = 0;
    addHeader(&response.headers, "Content-Length", "12");
    addHeader(&response.headers, "Content-Type", "text/html");

    size_t size = 0;
    char* c = buildHttpResponse(&response, &size);

    ssize_t written = write(socketFd, c, size);
    //TODO check if closecon
    return CLOSE_CON;
}
