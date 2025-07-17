//
// Created by Kilian Markgraf on 30.06.25.
//

#ifndef METHOD_H
#define METHOD_H

#define METHOD_GET "GET"
#define METHOD_POST "POST"
#define METHOD_DELETE "DELETE"
#define METHOD_PUT "PUT"
#define METHOD_PATCH "PATCH"
#define METHOD_HEAD "HEAD"
#define METHOD_OPTIONS "OPTIONS"
#include <stddef.h>

char *parseHttpMethod(int socketFd, size_t *bufferLength);

char *parseHttpPath(int socketFd, size_t *bufferLength);


#endif //METHOD_H
