//
// Created by Kilian Markgraf on 07.07.25.
//

#include "build.h"

#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define HEADER_UTIL_CHARS 4
#define START_UTIL_CHARS 4

char *buildHttpResponse(struct HttpResponse *httpResponse, size_t *responseSize) {
    size_t startLineSize = httpResponse->startLine.httpVersionSize + httpResponse->startLine.statusTextSize +
                           START_UTIL_CHARS;
    if (httpResponse->startLine.statusCode >= 100) {
        startLineSize += 3;
    } else if (httpResponse->startLine.statusCode >= 100) {
        startLineSize += 2;
    } else {
        startLineSize += 1;
    }

    size_t headersSize = 0;
    for (int i = 0; i <= httpResponse->headers.size; i++) {
        headersSize += strlen(httpResponse->headers.keys[i]) + strlen(httpResponse->headers.values[i]) +
                HEADER_UTIL_CHARS;
    }

    const size_t bodySize = httpResponse->body.size + 1;

    char *response = malloc(startLineSize + bodySize + headersSize);
    size_t currentChar = 0;

    sprintf(response, "%s %d %s\r\n", httpResponse->startLine.httpVersion, httpResponse->startLine.statusCode,
            httpResponse->startLine.statusText);
    currentChar += startLineSize;

    for (int i = 0; i < httpResponse->headers.size; i++) {
        sprintf(response + currentChar, "%s: %s\r\n", httpResponse->headers.keys[i],
                httpResponse->headers.values[i]);

        currentChar += strlen(httpResponse->headers.keys[i]) + strlen(httpResponse->headers.values[i]) +
                HEADER_UTIL_CHARS;
    }

    sprintf(response + currentChar, "\r\n%s", httpResponse->body.content);

    currentChar += httpResponse->body.size + 1;
    *responseSize = currentChar;

    return response;
}
