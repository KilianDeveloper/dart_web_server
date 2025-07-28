//
// Created by Kilian Markgraf on 17.07.25.
//

#include "endpoints.h"

#include <regex.h>
#include <string.h>

#include "../core/http/request/start.h"
#include "note/get.h"

static const Endpoint endpoints[] = {
    {
        METHOD_GET,
        strlen(METHOD_GET),
        GET_NOTE,
        strlen(GET_NOTE),
        getNote
    }
};

int isSameEndpoint(char *path, char *pattern) {
    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED | REG_NOSUB);
    int compared = regexec(&regex, path, 0, NULL, 0);
    return !compared;
}

const Endpoint *findEndpoint(char *method, size_t methodLength, char *path, size_t pathLength) {
    for (int endpointIndex = 0; endpointIndex < sizeof(endpoints) / sizeof(Endpoint); endpointIndex++) {
        const Endpoint *endpoint = &endpoints[endpointIndex];
        if (strcmp(endpoints[endpointIndex].method, method) != 0) {
            continue;
        }
        int pathMatches = isSameEndpoint(path, endpoint->pathPattern);

        if (pathMatches) {
            return endpoint;
        }
    }
    return NULL;
}
