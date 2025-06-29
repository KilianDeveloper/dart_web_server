//
// Created by Kilian Markgraf on 26.06.25.
//

#include "header.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../util/read.h"

/*

void parseHeader(int socketFd) {

}

 */
void parseHeader(int socketFd) {
    size_t bufferSize = 2;

    char* buffer = malloc(sizeof(char) * 2);
    if (buffer == NULL) {
        return;
    }
    readLine(socketFd, buffer, &bufferSize);
    free(buffer);
    /*char* buffer = malloc(sizeof(char) * 2);
    if (buffer == NULL) {
        return;
    }

    ssize_t bufferSize = 2;
    int size = 0;
    do {
        ssize_t bytesRead = read(socketFd, &buffer[bufferSize - 2], 2);
        if (bytesRead == -1) {
            break;
        }
        if (bytesRead == 0) {
            size++;
            continue;
        }
        bufferSize += bytesRead;
        char *temp = realloc(buffer, bufferSize);
        if (temp == NULL) {
            return;
        }
        buffer = temp;
        size++;
    } while (buffer[bufferSize - 3] != '\n');
    free(buffer);*/
}
