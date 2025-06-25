//
// Created by Kilian Markgraf on 25.06.25.
//

#include "protocol.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/_endian.h>

struct IpV4Address ipv4IntToAddress(unsigned long ip) {
    struct IpV4Address ipv4IntToAddress = {};

    unsigned long rotated = ip;
    for (int i = 0; i < 4; i++) {
        short byte = ((short) rotated) & 0xff;
        ipv4IntToAddress.segments[i] = byte;
        rotated = rotated >> 8;
    }
    return ipv4IntToAddress;
}

char* ipv4ToString(struct IpV4Address ip) {
    int length = sizeof(char) * 15;
    char* ipFormatted = malloc(length);
    snprintf(ipFormatted, length ,"%hd.%hd.%hd.%hd", ip.segments[0], ip.segments[1], ip.segments[2], ip.segments[3]);
    return ipFormatted;
}
