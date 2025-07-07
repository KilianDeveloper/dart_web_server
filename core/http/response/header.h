//
// Created by Kilian Markgraf on 07.07.25.
//

#ifndef HEADER_H
#define HEADER_H
#include "build.h"

int addHeader(struct HttpHeaders* headers, char key[MAX_HEADER_KEY_SIZE], char value[MAX_HEADER_VALUE_SIZE]);

#endif //HEADER_H
