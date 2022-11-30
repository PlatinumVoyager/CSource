#include <stdio.h>
#include <pcap.h>

char *device; // string for device name "en1", "wlan0", etc
char error_buffer[PCAP_ERRBUF_SIZE]; // create buffer to store error messages

int main(void)
{
    // find a device
    device = pcap_lookupdev(error_buffer);
    
    if (device == NULL) 
    {
        printf("Error finding device.\nERROR: %s\n", error_buffer);
        return 1;
    }

    printf("NIC found: %s\n", device);

    return 0;
}