#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <poll.h>

#define PORT "9034"

int get_listener_socket(void);
void *get_in_addr(struct sockaddr *sa);

void add_to_pfds(struct pollfd *pfds[], int new_fd, int *fd_count, int *fd_size);
void del_from_pfds(struct pollfd pfds[], int i, int *fd_count);

int main()
{
    int listener, new_fd;

    struct sockaddr_storage remote_addr;
    socklen_t addrlen;

    char buffer[256];
    char remoteIP[INET_ADDRSTRLEN];

    int fd_count = 0;
    int fd_size = 5;

    struct pollfd *pfds = malloc(fd_size * sizeof(*pfds));

    // setup socket
    listener = get_listener_socket();

    if (listener == -1)
    {
        fprintf(stderr, "error getting listening socket\n");
        exit(1);
    }

    // add the listener to set
    pfds[0].fd = listener;
    pfds[0].events = POLLIN;

    fd_count = 1;

    for (;;)
    {
        int poll_count = poll(pfds, fd_count, 0);

        if (poll_count == -1)
        {
            perror("poll");
            exit(1);
        }

        for (int i = 0; i < fd_count; i++)
        {
            // check for read
            if (pfds[i].revents & POLLIN)
            {
                if (pfds[i].fd == listener)
                {
                    addrlen = sizeof(remote_addr);
                    new_fd = accept(listener, (struct sockaddr *)&remote_addr, &addrlen);

                    if (new_fd == -1)
                    {
                        perror("accept");
                    
                    } else {
                        add_to_pfds(&pfds, new_fd, &fd_count, &fd_size);

                        printf("pollserver: new connection from %s on socket %d\n", inet_ntop(remote_addr.ss_family, get_in_addr((struct sockaddr*)&remote_addr), remoteIP, INET_ADDRSTRLEN), new_fd);
                    }
                } else {
                    // not listener; regular client
                    int nbytes = recv(pfds[i].fd, buffer, sizeof(buffer), 0);
                    int sender_fd = pfds[i].fd;

                    if (nbytes == 0)
                    {
                        // got error on connection closed by client
                        if (nbytes <= 0)
                        {
                            // connection closed
                            printf("pollserver: socket %d hung up\n", sender_fd);

                        } else {
                            perror("recv");
                        }

                        close(pfds[i].fd);
                        del_from_pfds(pfds, i, &fd_count);
                    
                    } else {
                        // accquire data from client
                        for (int j = 0; j < fd_count; j++)
                        {
                            int dest_fd = pfds[j].fd;
                            
                            if (dest_fd != listener && dest_fd != sender_fd)
                            {
                                if (send(dest_fd, buffer, nbytes, 0) == -1)
                                {
                                    perror("send");
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

int get_listener_socket(void)
{
    int listener;
    int yes = 1;
    int rv;

    struct addrinfo hints, *ai, *p;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((rv = getaddrinfo(NULL, PORT, &hints, &ai)) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = ai; p != NULL; p = p->ai_next)
    {
        listener = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (listener < 0)
        {
            continue;
        }

        // set socket options
        setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
        if (bind(listener, p->ai_addr, p->ai_addrlen) < 0)
        {
            close(listener);
            continue;
        }

        break;
    }

    // didnt get bound
    if (p == NULL)
    {
        return -1;
    }

    freeaddrinfo(ai);

    if (listen(listener, 10) == -1)
    {
        return -1;
    }

    return listener;
}

void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET)
    {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    
    } else {
        fprintf(stderr, "failed to return struct. IPv4 only!\n");
        exit(1);
    }
}

void add_to_pfds(struct pollfd *pfds[], int new_fd, int *fd_count, int *fd_size)
{
    // add more space in the pfds array
    if (*fd_count  == *fd_size)
    {
        *fd_size *= 2;
        *pfds = realloc(*pfds, sizeof(**pfds) * (*fd_size));
    }

    (*pfds)[*fd_count].fd = new_fd;
    (*pfds)[*fd_count].events = POLLIN;

    (*fd_count)++;
}

void del_from_pfds(struct pollfd pfds[], int i, int *fd_count)
{
    pfds[i] = pfds[*fd_count-1];

    (*fd_count)--;
}