#include <stdlib.h>
#include <stdio.h>
#include <pcap/pcap.h>

char *dev;
char err_buff[PCAP_ERRBUF_SIZE];

int i = 0;
pcap_if_t *alldevs, *d;

int main(void)
{
    if (pcap_findalldevs(&alldevs, err_buff) == -1)
    {
        fprintf(stderr, "Error listing devices; None found...\n");
        exit(1);
    }

    // display devices
    for (d = alldevs; d; d = d->next)
    {
        printf("%d. %s\n", ++i, d->name);
        if (d->description)
        {
            printf("(%s)\n", d->description);
        } else { printf("\tNo description available...\n"); }
    }

    return 0;
}