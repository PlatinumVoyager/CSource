#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pcap.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>

// start
void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header);

char *dev;
char err_buff[PCAP_ERRBUF_SIZE];

int main(void)
{
    pcap_t *handle;
    const u_char *packet;

    struct pcap_pkthdr packet_header;
    
    int packet_count_limit = 1;
    int timeout_limit = 10000; // milliseconds, 10 seconds

    dev = "en1";

    handle = pcap_open_live(
        dev, 
        BUFSIZ, 
        packet_count_limit,
        timeout_limit,
        err_buff
    );

    if ((pcap_set_promisc(handle, 1)) != 0) // init PROMISC_MODE
    {
        fprintf(stderr, "Failed to set PROMISC_MODE on %s\n", dev);
    
    } else { printf("// SET PROMISC_MODE on IFACE \"%s\"\n", dev); }

    // capture one packet
    if ((packet = pcap_next(handle, &packet_header)) == NULL)
    {
        fprintf(stderr, "Failed to obtain packet struct. Could not process NULL packet (0)\n");
        exit(2);
    }
    
    // print packet info
    print_packet_info(packet, packet_header);

    return 0;
}

void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header)
{
    int cap_len, hdr_len;

    hdr_len = packet_header.caplen;
    cap_len = packet_header.len;

    printf("Packet capture length => %d\nPacket total => %d\n", hdr_len, cap_len);

    return NULL;
}

// end