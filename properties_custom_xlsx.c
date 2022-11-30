#include <stdio.h>
#include <curl/curl.h>
#include <xlsxwriter.h>

int main(void)
{
    lxw_workbook *wb = workbook_new("properties_custom.xlsx");
    lxw_worksheet *ws = workbook_add_worksheet(wb, NULL); 

    lxw_datetime dt = { 2016, 12, 12, 0, 0, 0.0 };

    // set custom document properties in the workbook
    workbook_set_custom_property_string(wb, "Checked by", "Eve");
    workbook_set_custom_property_datetime(wb, "Date completed", &dt);
    workbook_set_custom_property_number(wb, "Document number", 12345);
    workbook_set_custom_property_number(wb, "Reference number", 1.2345);
    workbook_set_custom_property_boolean(wb, "Has Review", 1);
    workbook_set_custom_property_boolean(wb, "Signed off", 0);

    // add text to the file
    worksheet_set_column(ws, 0, 0, 50, NULL);
    worksheet_write_string(ws, 0, 0,
        "Select 'Workbook Properties' to view custom properties", NULL);

    lxw_error error = workbook_close(wb);
    if (error)
    {
        fprintf(stderr, "failed to close workbook: %d = %s\n", error,
            lxw_strerror(error));

        return error;
    }

    puts("finished");

    return 0;
}