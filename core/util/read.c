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

//TODO check types
//TODO error on multiple request
void readLine(const int socketFd, char* buffer, size_t* bufferLength) {
    int size = 0;
    do {
        size_t _bufferLength = *bufferLength;
        ssize_t bytesRead = read(socketFd, &buffer[_bufferLength - 2], 2);
        if (bytesRead == -1) {
            break;
        }
        if (bytesRead == 0) {
            size++;
            continue;
        }
        *bufferLength += (size_t)bytesRead;
        char *temp = realloc(buffer, *bufferLength);
        if (temp == NULL) {
            return;
        }//TODO abbruchbedingung
        buffer = temp;
        size++;
    } while (buffer[*bufferLength - 3] != '\n');
}
