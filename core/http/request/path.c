//
// Created by Kilian Markgraf on 09.07.25.
//

#include <stdlib.h>
#include <regex.h>
#include "path.h"

#include <string.h>

#define PROTOCOL_SIZE 7

int isValidPath(const char *path) {
    regex_t regex;
    regcomp(&regex, "^(.+)\\/([^\\/]+)$", 0);
    int compared = regexec(&regex, path, 0, NULL, 0);
    return compared;
}

int pathHasBase(const char *path, const char *base) {
    size_t pathSize = strlen(path);
    size_t baseSize = strlen(base);
    if (pathSize < baseSize) {
        return 1;
    }
    for (size_t i = 0; i < baseSize; i++) {
        if (path[i] != base[i]) {
            return 1;
        }
    }
    return 0;
}

int isAbsolutePath(const char *path, size_t length) {
    char expectedStart[] = "http://";
    size_t expectedLength = strlen(expectedStart);

    int isAbsolute = 1;
    for (int i = 0; i < expectedLength && i < length; i++) {
        if (path[i] != expectedStart[i]) {
            isAbsolute = 0;
            break;
        }
    }
    return isAbsolute;
}

/**
 * Extract a relative path from an absolute path
 */
char *extractRelativePath(char *buffer, size_t *bufferLength) {
    size_t hostLength = 0;

    while (buffer[PROTOCOL_SIZE + hostLength] != '/') {
        hostLength++;
    }

    const size_t sizeWithoutProtocol = *bufferLength - PROTOCOL_SIZE - hostLength;
    memcpy(buffer, buffer + PROTOCOL_SIZE + hostLength, sizeWithoutProtocol);

    char *temp = realloc(buffer, sizeWithoutProtocol);
    if (!temp) {
        return NULL;
    }
    buffer = temp;
    *bufferLength = sizeWithoutProtocol;

    return buffer;
}

char *toRelativePath(char *buffer, size_t *bufferLength) {
    if (!isAbsolutePath(buffer, *bufferLength)) {
        return buffer;
    }

    return extractRelativePath(buffer, bufferLength);
}
