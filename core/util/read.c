//
// Created by Kilian Markgraf on 29.06.25.
//

#include "read.h"

//
// Created by Kilian Markgraf on 26.06.25.
//

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_READS 100

//TODO check types
//TODO error on multiple request

size_t max(const size_t a, const size_t b)
{
    return a > b ? a : b;
}


char *readUntil(const int socketFd, const char separator, size_t *bufferLength) {
    *bufferLength = 2;
    char *buffer = malloc(*bufferLength);
    if (!buffer) {
        return NULL;
    }
    do {
        const ssize_t bytesRead = read(socketFd, buffer + *bufferLength - 2, 1);
        if (bytesRead == -1) {
            break;
        }
        if (bytesRead == 0) {
            if (*bufferLength == 2) {
                free(buffer);
                *bufferLength = 0;
                return NULL;
            }

            return buffer;
        }
        *bufferLength += 1;
        char *temp = realloc(buffer, *bufferLength);
        if (temp == NULL) {
            free(buffer);
            return NULL;
        }
        buffer = temp;
    } while (buffer[max(*bufferLength - 3, 0)] != separator);

    *bufferLength = *bufferLength > 2 ? *bufferLength - 2 : 1;

    char *temp = realloc(buffer, *bufferLength);
    if (!temp) {
        free(buffer);
        return NULL;
    }
    buffer = temp;
    buffer[(*bufferLength) - 1] = '\0';
    return buffer;
}

void readUntilClear(const int socketFd) {
    char buffer[1024];
    ssize_t bytesRead;
    do {
        bytesRead = read(socketFd, buffer, sizeof(buffer));
    } while (bytesRead > 0);
}
