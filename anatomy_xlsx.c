#include <stdio.h>
#include <xlsxwriter.h>

int main(void)
{
    // create a new workbook
    lxw_workbook *wb = workbook_new("anatomy_xlsx.xlsx");

    // add a new worksheet
    lxw_worksheet *ws = workbook_add_worksheet(wb, "Demo");

    // add another workbook, leave default name: Sheet2
    lxw_worksheet *ws2 = workbook_add_worksheet(wb, NULL);

    // add cell formats
    lxw_format *mft = workbook_add_format(wb); // bold format
    lxw_format *mft2 = workbook_add_format(wb);

    // set bold property for the first format
    format_set_bold(mft);

    // set number format for the second format
    format_set_num_format(mft2, "$#,##0.00");

    // widen first column to make the text clearer
    worksheet_write_string(ws, 0, 0, "Peach", NULL);
    worksheet_write_string(ws, 1, 0, "Plum", NULL);

    // write formatted data
    worksheet_write_string(ws, 2, 0, "Pear", mft);

    // formats can be reused
    worksheet_write_string(ws, 3, 0, "Persimmon", mft);

    // write some numbers
    worksheet_write_number(ws, 5, 0, 123, NULL);
    worksheet_write_number(ws, 6, 0, 4567.55, mft2);

    // write to the second worksheet
    worksheet_write_string(ws2, 0, 0, "Some text here", mft);

    // close workbook, save and free memory
    lxw_error error = workbook_close(wb);
    if (error)
    {
        fprintf(stderr, "error in workbook_close()\n \
            error: %d = %s\n", error, lxw_strerror(error));

        return error;
    }

    puts("finished");

    return 0;
}