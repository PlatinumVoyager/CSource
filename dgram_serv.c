#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define MYPORT "4950"
#define MAXBUFFLEN 100

void *get_in_addr(struct sockaddr *sa);

int main(void)
{
    int sockfd, fcntl_chk;
    struct addrinfo hints, *servinfo, *p;

    int rv, numbytes;

    struct sockaddr_storage their_addr;
    char buffer[MAXBUFFLEN];

    socklen_t addr_len;
    char s[INET_ADDRSTRLEN];

    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE;

    if ((rv = getaddrinfo(NULL, MYPORT, &hints, &servinfo)) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return -1;
    }

    for (p = servinfo; p != NULL; p = p->ai_next)
    {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
        {
            perror("listener: socket");
            continue;
        }

        // dont let the kernel set the socket to blocking: set socket to non-blocking
        fcntl_chk = fcntl(sockfd, F_SETFL, O_NONBLOCK);
       
        if (fcntl_chk == EAGAIN)
        {
            fprintf(stderr, "socket opts: failed to set socket to O_NONBLOCK");
            continue;
        }

        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1)
        {
            close(sockfd);

            perror("listener: bind");
            continue;
        }

        break;
    }

    if (p == NULL)
    {
        perror("listener: failed to bind to socket");
        return 2;
    }

    freeaddrinfo(servinfo);

    puts("listener: waiting to recvfrom...");

    addr_len = sizeof(their_addr);
    if ((numbytes = recvfrom(sockfd, buffer, MAXBUFFLEN-1, 0, (struct sockaddr*)&their_addr, &addr_len)) == -1)
    {
        perror("recvfrom");
        exit(1);
    }

    printf("listener: got packet from %s\n", inet_ntop(their_addr.ss_family, get_in_addr((struct sockaddr*)&their_addr), s, sizeof(s)));
    printf("listener: packet is %d bytes long\n", numbytes);

    buffer[numbytes] = '\0';
    printf("listener: packet contains \'%s\'\n", buffer);

    close(sockfd);

    return 0;
}

void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET)
    {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}