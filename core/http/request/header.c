//
// Created by Kilian Markgraf on 26.06.25.
//

#include "header.h"

#include <stdio.h>

#include "../../util/read.h"

void parseHttpHeaders(int socketFd) {
    size_t bufferSize = 2;

    readUntilClear(socketFd);
}
