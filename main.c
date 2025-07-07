#include "core/network/socket.h"
#include "core/http/handle.h"

int main() {
    const int port = 80;
    const bool running = true;

    const int sockFd = createSocket(port);
    handleRequests(sockFd, &running, handleHttpRequest);
    closeSocket(sockFd);

    return 0;
}
