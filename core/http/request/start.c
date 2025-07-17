//
// Created by Kilian Markgraf on 26.06.25.
//

#include "start.h"

#include <errno.h>
#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "path.h"
#include "../../util/read.h"

int isValidMethod(const char *method) {
    return strcmp(method, METHOD_GET) == 0 || strcmp(method, METHOD_POST) == 0 || strcmp(method, METHOD_PUT) == 0 ||
           strcmp(method, METHOD_HEAD) == 0 || strcmp(method, METHOD_OPTIONS) == 0 || strcmp(method, METHOD_PATCH) == 0
           || strcmp(method, METHOD_DELETE) == 0;
}

char *parseHttpMethod(const int socketFd, size_t *bufferLength) {
    char *methodBuffer = readUntil(socketFd, ' ', bufferLength);

    if (!isValidMethod(methodBuffer)) {
        free(methodBuffer);
        return NULL;
    }
    return methodBuffer;
}

char *parseHttpPath(const int socketFd, size_t *bufferLength) {
    char *methodBuffer = readUntil(socketFd, ' ', bufferLength);

    if (!isValidPath(methodBuffer)) {
        free(methodBuffer);
        return NULL;
    }

    char *temp = toRelativePath(methodBuffer, bufferLength);
    if (!temp) {
        free(methodBuffer);
        return NULL;
    }
    return temp;
}

void parsePath(int socketFd) {
    size_t methodSize = 2;

    char *methodBuffer = readUntil(socketFd, ' ', &methodSize);
    readUntilClear(socketFd);

    if (methodBuffer != NULL) {
        free(methodBuffer);
    }
    printf("Method parsed from %s\n", methodBuffer);
}
