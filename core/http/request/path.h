//
// Created by Kilian Markgraf on 09.07.25.
//

#ifndef PATH_H
#define PATH_H

int isValidPath(const char *path);

int pathHasBase(const char *path, const char *base);

char* toRelativePath(char *buffer, size_t* bufferLength);

#endif //PATH_H
