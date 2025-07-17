//
// Created by Kilian Markgraf on 17.07.25.
//

#include "endpoints.h"

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

const Endpoint *findEndpoint(char *method, size_t methodLength, char *path, size_t pathLength) {
    for (int endpointIndex = 0; endpointIndex < sizeof(endpoints) / sizeof(Endpoint); endpointIndex++) {
        const Endpoint *endpoint = &endpoints[endpointIndex];
        if (strcmp(endpoints[endpointIndex].method, method) != 0) {
            continue;
        }

        int isSameEndpoint = 1;
        int i = 0;
        while (i < pathLength && i < endpoint->pathLength && endpoint->path[i] != '{') {
            if (endpoint->path[i] != path[i]) {
                isSameEndpoint = 0;
                break;
            }
            i++;
        }
        //TODO check if provided is longer (test with /notes12345 -> this should not work)


        if (isSameEndpoint) {
            return endpoint;
        }
    }
    return NULL;
}
