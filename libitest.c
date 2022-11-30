#include <stdio.h>
#include <stdlib.h>
#include <libimobiledevice/libimobiledevice.h>

static char *udid = NULL;

int main(void)
{
    idevice_t device = NULL;

    // IDEVICE_LOOKUP_PREFER_NETWORK
    if (idevice_new_with_options(&device, NULL, IDEVICE_LOOKUP_USBMUX) != IDEVICE_E_SUCCESS)
    {
        fprintf(stderr, "ERROR: No USB devices attached\n");
        return -1;
    }

    puts("++ Attempting to get device UDID...");
    if (idevice_get_udid(device, &udid) != IDEVICE_E_SUCCESS)
    {
        fprintf(stderr, "ERROR: Unable to get device UDID\n");

        idevice_free(device);
        return -1;
    }

    printf("Connected with UDID: %s\n", udid);

    idevice_free(device);
    free(udid);

    return 0;
}