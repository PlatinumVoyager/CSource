#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <arpa/inet.h>

char ip[13];
char subnet_mask[13];

bpf_u_int32 ip_int32; // ip address as integer
bpf_u_int32 subnet_mask_int32; // subnet mask as integer

int lookup_ret_code;

char *device;
char error_buffer[PCAP_ERRBUF_SIZE];

// build struct to store IP and subnet mask information
struct in_addr address;

int main(void)
{
    // lookup device;
    device = pcap_lookupdev(error_buffer);

    if (device == NULL)
    {
        fprintf(stderr, "Error locating interface. No such device exists.\n");
        return 1;
    }

    // get the device info
    lookup_ret_code = pcap_lookupnet(
        device,
        &ip_int32,
        &subnet_mask_int32,
        error_buffer
    );

    if (lookup_ret_code == -1) // if we failed to get information about the device
    {
        fprintf(stderr, "ERROR = %s\n", error_buffer);
        return 1;
    }

    // translate IP address into human readable form
    address.s_addr = ip_int32;

    strcpy(ip, inet_ntoa(address));
    if (ip == NULL)
    {
        perror("inet_ntoa\n");
        return 1;
    }

    // translate subnet mask into human readable form
    address.s_addr = subnet_mask_int32;

    strcpy(subnet_mask_int32, inet_ntoa(address));
    if (subnet_mask == NULL)
    {
        perror("inet_ntoa\n");
        return 1;
    }

    printf("Device: %s\nIP Address: %s\n, Subnet Mask: %s\n", device, ip, subnet_mask);

    return 0;
}



