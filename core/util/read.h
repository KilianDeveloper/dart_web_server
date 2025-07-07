//
// Created by Kilian Markgraf on 29.06.25.
//

#ifndef READ_H
#define READ_H

#include <stdio.h>

char* readUntil(int socketFd, char separator, size_t* bufferLength);

void readUntilClear(int socketFd);


#endif //READ_H
