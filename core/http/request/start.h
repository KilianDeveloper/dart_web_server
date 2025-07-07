//
// Created by Kilian Markgraf on 30.06.25.
//

#ifndef METHOD_H
#define METHOD_H

#define METHOD_GET "GET"
#define METHOD_POST "POST"
#define METHOD_DELETE "DELETE"
#define METHOD_PUT "PUT"
#define METHOD_PATCH "PATCH"
#define METHOD_HEAD "HEAD"
#define METHOD_OPTIONS "OPTIONS"

char *parseHttpMethod(int socketFd);

#endif //METHOD_H
