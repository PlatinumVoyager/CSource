#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define SERV_PORT "60950"
#define BACKLOG 500

int main(void)
{
    int status;

    struct addrinfo hints, *res;
    int sockfd, new_fd;

    struct sockaddr_storage target;
    socklen_t addr_size;

    memset(&hints, 0, sizeof(hints));





    return 0;
}