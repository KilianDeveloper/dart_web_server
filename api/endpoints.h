//
// Created by Kilian Markgraf on 17.07.25.
//

#ifndef ENDPOINTS_H
#define ENDPOINTS_H
#include <stddef.h>

typedef struct HttpResponse (*RequestHandler)(char *path, char *pathLength, char *headers, size_t headersLength,
                                              char *body, size_t bodyLength);

typedef struct {
    char *method;
    size_t methodLength;
    char *pathPattern;
    size_t pathPatternLength;
    RequestHandler handler;
} Endpoint;

const Endpoint *findEndpoint(char *method, size_t methodLength, char *path, size_t pathLength);

#endif //ENDPOINTS_H
