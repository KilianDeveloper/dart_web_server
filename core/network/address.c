//
// Created by Kilian Markgraf on 25.06.25.
//

#include "address.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/_endian.h>

struct IpV4Address networkToHostAddress(const unsigned long networkIp, const unsigned short networkPort) {
    struct IpV4Address ipv4IntToAddress = {};
    ipv4IntToAddress.port = ntohs(networkPort);

    unsigned long rotated = networkIp;
    for (int i = 0; i < 4; i++) {
        short byte = ((short) rotated) & 0xff;
        ipv4IntToAddress.segments[i] = byte;
        rotated = rotated >> 8;
    }
    return ipv4IntToAddress;
}

char *addressToString(const struct IpV4Address address) {
    int length = sizeof(char) * 15;
    char *ipFormatted = malloc(length);
    snprintf(ipFormatted, length, "%hd.%hd.%hd.%hd:%hu", address.segments[0], address.segments[1], address.segments[2],
             address.segments[3], address.port);
    return ipFormatted;
}
