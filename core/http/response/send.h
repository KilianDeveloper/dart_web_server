//
// Created by Kilian Markgraf on 03.08.25.
//

#ifndef SEND_H
#define SEND_H

#include "build.h"

void sendHttpResponse(int socketFd, struct HttpResponse *response);

#endif //SEND_H
