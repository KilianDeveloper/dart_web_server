//
// Created by Kilian Markgraf on 25.06.25.
//

#ifndef PROTOCOL_H
#define PROTOCOL_H

struct IpV4Address {
    short segments[4];
};

char* ipv4ToString(struct IpV4Address ip);
struct IpV4Address ipv4IntToAddress(unsigned long ip);
#endif //PROTOCOL_H
