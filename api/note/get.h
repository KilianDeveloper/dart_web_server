//
// Created by Kilian Markgraf on 09.07.25.
//


#ifndef GET_H
#define GET_H

#include "../../core/http/response/build.h"

static const char GET_NOTE[] = "^\\/notes\\/[0-9]*$";

struct HttpResponse getNote(char* path, char* pathLength, char *headers, size_t headersLength, char *body, size_t bodyLength);

#endif //GET_H
