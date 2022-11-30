#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <cups/cups.h>

/*
    Can we use a malformed PPD file to upload to the printer, possibly
    causing a buffer overflow in where we can obtain RCE

    How can we obtain a buffer overflow?
*/

// lets mess around with OUR printer ;)

/*
    Instead of pulling down tools from an HTTP server on LAN, pull them
    from a partition on a mounted USB device

*/

char user[30];

int main(void)
{
    puts("++ CUPS import => non NULL");

    ipp_t *ippNewRequest(ipp_op_t op); // op = operation code for IPP request
    ipp_t *request = ippNewRequest(IPP_OP_GET_PRINTER_ATTRIBUTES);

    // specify printer URI to query for IPP_OP_GET_PRINTER_ATTRIBUTES
    const char *printer_uri = cupsGetOption("device-uri",
                                    dest->num_options, dest->options);

    ippAddString(request, IPP_TAG_OPERATION, IPP_TAG_URI, "printer-uri", printer_uri);
    
    if (fgets(user, sizeof(user), stdin) == NULL) {
        fprintf(stderr, "CUPS: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    static const char *const requested_attributes[] = 
    {
        "printer-state",
        "printer-state-message",
        "printer-state-reasons"
    };

    ippAddStrings(request, IPP_TAG_OPERATION, IPP_TAG_KEYWORD,
                        "requested-attributes", 3, NULL, requested_attributes);

    // send IPP request
    ipp_t *response = cupsDoRequest(http, request, resource);
    if (cupsLastError() >= IPP_STATUS_ERROR_BAD_REQUEST)
    {
        fprintf(stderr, "[CUPS][IPP] Exception: %s\n", cupsLastErrorString());
        return EXIT_FAILURE;
    }

    user[strlen(user) - 1] = '\0';

    cupsSetUser(user);
    cupsSetUserAgent("Mozilla 12.3 Gecko; 11.5 ATL; Android 7.0 S7TZ42T");
    cupsSetPasswordCB("asdfsakjdflslkfdsdf");

    if (cupsLastError() >= IPP_STATUS_ERROR_BAD_REQUEST)
    {
        fprintf(stderr, "[CUPS][ERR] Exception => %s\n", cupsLastErrorString());
    }

    ipp_attribute_t *attr;

    if ((attr = ippFindAttribute(response, "printer-state", IPP_TAG_ENUM)) != NULL)
    {
        fprintf(stderr, "[CUPS][IPP][ERR] printer-state: %s\n", ippGetInteger(attr, 0));
        return EXIT_FAILURE;
    }

    puts("++ printer-state-reasons=\n");
    for (i = 0; i < count; i++) {
        printf("\t%s", ippGetString(attr, i, NULL));
    }

    return 0;
}