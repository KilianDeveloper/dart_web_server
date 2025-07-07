//
// Created by Kilian Markgraf on 07.07.25.
//

#include "header.h"
#include <string.h>

int addHeader(struct HttpHeaders* headers, char key[MAX_HEADER_KEY_SIZE], char value[MAX_HEADER_VALUE_SIZE]) {
    if (headers->size >= MAX_HEADERS) {
        return -1;
    }

    memcpy(headers->keys[headers->size], key, MAX_HEADER_KEY_SIZE);
    memcpy(headers->values[headers->size], value, MAX_HEADER_KEY_SIZE);

    headers->size++;
    return 0;
}
