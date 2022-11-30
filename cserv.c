#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netdb.h>
#include <netinet/in.h>

#define MYPORT "3490"
#define BACKLOG 10 // up to 10 connections qeued

int main(void)
{   
    int status;

    // "hints" struct that "hints" at what type of socket it is
    struct addrinfo hints, *res;
    int sockfd, new_fd;

    struct sockaddr_storage their_addr;
    socklen_t addr_size;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    
    // AI_PASSIVE -
    // indicates that the returned socket address structure is intended for use in a call to bind
    hints.ai_flags = AI_PASSIVE;

    if ((status = getaddrinfo(NULL, MYPORT, &hints, &res)) != 0)
    {
        fprintf(stderr, "Failed to get address");
        return -1;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, 0); // res->ai_protocol
    
    if ((status = bind(sockfd, res->ai_addr, res->ai_addrlen)) != 0)
    {
        fprintf(stderr, "Failed to bind to %s\n", MYPORT);
        return -1;
    }

    // try to listen
    listen(sockfd, BACKLOG);

    printf("++ Waiting for connections :: %s\n", MYPORT);

    // accept incoming connections
    addr_size = sizeof(their_addr);
    new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);

    // ready to communicate over new socket (send, recv)

    // shutdown(0) further receives are disallowed
    // shutdown(1) further sends are disallowed
    // shutdown(2) further sends and receives are disallowed
    // shutdown() - doesnt close the socket, only changes the behavior

    // close(new_fd) - closes file descriptor (socket)
    return 0;
}