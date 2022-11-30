#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <arpa/inet.h>
#include <sys/socket.h>

char ipv4[INET_ADDRSTRLEN]; // hold IPv4 string
char ipv6[INET6_ADDRSTRLEN]; // hold IPv6 string

struct sockaddr_in sa; // loaded
struct sockaddr_in6 sa6;

int main(void)
{
    sa.sin_addr.s_addr = INADDR_BROADCAST;

    inet_ntop(AF_INET, &(sa.sin_addr), ipv4, INET_ADDRSTRLEN);
    inet_ntop(AF_INET6, &(sa6.sin6_addr), ipv6, INET6_ADDRSTRLEN);

    printf("%s\n%s\n", ipv4, ipv6);

    return 0;
}