#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERV_PORT 59403

int sockfd;

int main(void)
{
    struct sockaddr_in server_sock;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server_sock.sin_family = AF_INET;
    server_sock.sin_port = htons(SERV_PORT);
    server_sock.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    if ((memset(server_sock.sin_zero, '\0', sizeof(server_sock.sin_zero))) != NULL)
    {
        fprintf(stderr, "Failed to setup socket struct: %s\n", strerror(errno));
        exit(1);
    }

    // ...
    bind(sockfd, (struct sockaddr *)&server_sock, sizeof(server_sock.sin_zero));

    return 0;
}