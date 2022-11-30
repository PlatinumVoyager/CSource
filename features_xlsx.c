#include <stdio.h>
#include <xlsxwriter.h>

int main(void)
{
    lxw_workbook *wb = workbook_new("workbook1.xlsx");
    lxw_worksheet *ws = workbook_add_worksheet(wb, NULL);

    // add a format
    lxw_format *fmt = workbook_add_format(wb);

    format_set_bold(fmt);

    // change column width for clarity
    worksheet_set_column(ws, 0, 0, 20, NULL);

    worksheet_write_string(ws, 0, 0, "Hello", NULL);

    // text with formatting
    worksheet_write_string(ws, 1, 0, "World", fmt);

    // write some numbers
    worksheet_write_number(ws, 2, 0, 123, NULL);
    worksheet_write_number(ws, 3, 0, 123.456, NULL);

    // insert an image
    worksheet_insert_image(ws, 1, 2, "download.jpeg");

    lxw_error error = workbook_close(wb);
    if (error)
    {
        fprintf("error: workbook_close()\n\
            Failed to close workbook: %d = %s\n", error, lxw_strerror(error));
    
        return error;
    }

    puts("finished");

    return 0;
}