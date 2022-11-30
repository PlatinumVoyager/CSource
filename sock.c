#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define INET_ADDRSTRLEN 20

char ip4[INET_ADDRSTRLEN];
struct sockaddr_in sa;

int getaddr_info(const char *node, const char *service,
                const struct addrinfo *hints,
                struct addrinfo **res);

inet_ntop(AF_INET, &(sa.sin_addr), ip4, INET_ADDRSTRLEN);

int main(void)
{
    int status;

    struct addrinfo hints;
    struct addrinfo *servinfo;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((status = getaddr_info(NULL, "3490", &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddr_info error: %s\n", gai_strerror(status));
        exit(1);
    }

    freeaddrinfo(servinfo);

    return 0;
}
