//
// Created by Kilian Markgraf on 03.08.25.
//

#include "send.h"

#include<unistd.h>

#include "build.h"

void sendHttpResponse(int socketFd, struct HttpResponse *response) {
    size_t size = 0;
    const char *responseString = buildHttpResponse(response, &size);

    ssize_t written = write(socketFd, responseString, size);
    while (written < size) {
        written += write(socketFd, responseString + written, size - written);
    }
}
