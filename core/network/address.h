//
// Created by Kilian Markgraf on 25.06.25.
//

#ifndef ADDRESS_H
#define ADDRESS_H

struct IpV4Address {
    short segments[4];
    unsigned short port;
};

/**
 * Convert the given address into a string
 */
char* addressToString(struct IpV4Address address);

/**
 * Convert the given ip and port into a readable IpV4Address
 * @param networkIp the ip as a long in network byte order
 * @param networkPort the port as a short in network byte order
 * @return a more readable address in host byte order and a splitted ip-address
 */
struct IpV4Address networkToHostAddress(unsigned long networkIp, unsigned short networkPort);
#endif //ADDRESS_H
