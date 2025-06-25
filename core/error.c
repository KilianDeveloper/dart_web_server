//
// Created by Kilian Markgraf on 25.06.25.
//

#include "error.h"
#include "stdio.h"
#include "stdlib.h"

void killProcess(const char *why) {
    fprintf(stderr, why);
    exit(1);
}

void printError(const char *why) {
    fprintf(stderr, why);
}
