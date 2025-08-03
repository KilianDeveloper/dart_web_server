//
// Created by Kilian Markgraf on 03.08.25.
//

#include "notFound.h"
#include<malloc.h>
#include <string.h>
#include "../../core/http/response/header.h"

struct HttpResponse generateNotFound() {
    struct HttpResponse response;

    response.body.size = 0;
    char bodySize[8] = {0};
    char *body = NOT_FOUND_MESSAGE;
    sprintf(bodySize, "%lu", strlen(body));

    response.body.content = body;
    response.body.size = strlen(body) + 1;

    char *httpVersion = "HTTP/1.1";
    char *statusText = "Not Found";

    response.startLine.httpVersion = httpVersion;
    response.startLine.httpVersionSize = strlen(httpVersion);
    response.startLine.statusCode = 404;
    response.startLine.statusText = statusText;

    response.startLine.statusTextSize = strlen(statusText);
    response.headers.size = 0;
    addHeader(&response.headers, "Content-Length", bodySize);
    addHeader(&response.headers, "Content-Type", "text/html");

    return response;
}
