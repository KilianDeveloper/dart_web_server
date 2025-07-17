//
// Created by Kilian Markgraf on 25.06.25.
//

#include "handle.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "endpoints.h"
#include "../core/http/response//build.h"

#include "string.h"
#include "../core/http/request/start.h"
#include "../core/network/address.h"
#include "../core/http/response/header.h"
#include "../core/network/socket.h"

int handleHttpRequest(int socketFd, struct sockaddr_in clientAddress, socklen_t clientAddressLength) {
    struct IpV4Address address = networkToHostAddress(clientAddress.sin_addr.s_addr, clientAddress.sin_port);
    char *ip = addressToString(address);

    size_t methodSize = 2, pathSize = 2;
    char *method = parseHttpMethod(socketFd, &methodSize);

    char *path = parseHttpPath(socketFd, &pathSize);

    Endpoint *endpoint = findEndpoint(method, methodSize, path, pathSize);

    printf("Request started from %s\n", ip);
    fflush(stdout);
    free(ip);

    struct HttpResponse response;

    response.body.size = 0;
    response.body.content = malloc(1);
    if (!response.body.content) {
        return -1;
    }
    char bodySize[8] = {0};
    char *body = "Hello World!";
    sprintf(bodySize, "%lu", strlen(body));

    response.body.content = body;
    response.body.size = strlen(body) + 1;

    char *httpVersion = "HTTP/1.1";
    char *statusText = "OK";

    response.startLine.httpVersion = httpVersion;
    response.startLine.httpVersionSize = strlen(httpVersion);
    response.startLine.statusCode = 200;
    response.startLine.statusText = statusText;

    response.startLine.statusTextSize = strlen(statusText);
    response.headers.size = 0;
    addHeader(&response.headers, "Content-Length", bodySize);
    addHeader(&response.headers, "Content-Type", "text/html");

    size_t size = 0;
    char *c = buildHttpResponse(&response, &size);

    ssize_t written = write(socketFd, c, size);
    //TODO check if closecon
    return CLOSE_CON;
}
