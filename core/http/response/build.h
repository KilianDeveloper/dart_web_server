//
// Created by Kilian Markgraf on 07.07.25.
//

#ifndef BUILD_H
#define BUILD_H
#include <stddef.h>

#define MAX_HEADERS 40
#define MAX_HEADER_KEY_SIZE 1024
#define MAX_HEADER_VALUE_SIZE 1024

struct HttpStartLine {
    char *httpVersion;
    size_t httpVersionSize;

    unsigned short statusCode;

    char *statusText;
    size_t statusTextSize;
};

struct HttpHeaders {
    char keys[MAX_HEADERS][MAX_HEADER_KEY_SIZE];
    char values[MAX_HEADERS][MAX_HEADER_KEY_SIZE];

    size_t size;
};

struct HttpBody {
    char *content;
    size_t size;
};

/**
 * A struct for representing a response sent back by the server
 */
struct HttpResponse {
    struct HttpStartLine startLine;
    struct HttpHeaders headers;
    struct HttpBody body;
};

char* buildHttpResponse(struct HttpResponse *httpResponse, size_t *responseSize);

#endif //BUILD_H
