#include "core/communication/socket.h"
#include "core/http/request.h"

int main() {
    int port = 80;
    bool running = true;
    int sock_fd = createSocket(port);
    handleRequests(sock_fd, &running, handleHttpRequest);
    closeSocket(sock_fd);

    return 0;
}
