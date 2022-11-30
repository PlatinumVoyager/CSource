#include <stdio.h>
#include <xlsxwriter.h>

int main(void)
{
    lxw_workbook *wb = workbook_new("format_num.xlsx");
    lxw_worksheet *ws = workbook_add_worksheet(wb, NULL);

    // widen the first column
    worksheet_set_column(ws, 0, 0, 30, NULL);

    // add some formats
    lxw_format *fmt = workbook_add_format(wb);
    lxw_format *fmt2 = workbook_add_format(wb);
    lxw_format *fmt3 = workbook_add_format(wb);
    lxw_format *fmt4 = workbook_add_format(wb);
    lxw_format *fmt5 = workbook_add_format(wb);
    lxw_format *fmt6 = workbook_add_format(wb);
    lxw_format *fmt7 = workbook_add_format(wb);
    lxw_format *fmt8 = workbook_add_format(wb);
    lxw_format *fmt9 = workbook_add_format(wb);
    lxw_format *fmt10 = workbook_add_format(wb);
    lxw_format *fmt11 = workbook_add_format(wb);

    // set number formats
    format_set_num_format(fmt, "0.000");
    format_set_num_format(fmt2, "#,##0");
    format_set_num_format(fmt3, "#,##0.00");
    format_set_num_format(fmt4, "0.00");
    format_set_num_format(fmt5, "mm/dd/yy");
    format_set_num_format(fmt6, "mmm d yyyy");
    format_set_num_format(fmt7, "d mmmm yyyy");
    format_set_num_format(fmt8, "dd/mm/yyyy hh:mm AM/PM");
    format_set_num_format(fmt9, "0 \"dollar and\" .00\" cents\"");

    // write data using the formats
    worksheet_write_number(ws, 0, 0, 3.1415926, NULL);
    worksheet_write_number(ws, 1, 0, 3.1415926, fmt);
    worksheet_write_number(ws, 2, 0, 1234.56, fmt2);
    worksheet_write_number(ws, 3, 0, 1234.56, fmt3);
    worksheet_write_number(ws, 4, 0, 49.99, fmt4);
    worksheet_write_number(ws, 5, 0, 36892.521, fmt5);
    worksheet_write_number(ws, 6, 0, 36892.521, fmt6);
    worksheet_write_number(ws, 7, 0, 36892.521, fmt7);
    worksheet_write_number(ws, 8, 0, 36892.521, fmt8);
    worksheet_write_number(ws, 9, 0, 1.87, fmt9);

    // show limited conditional number formats
    format_set_num_format(fmt10, "[Green]General;[Red]-General;General");

    worksheet_write_number(ws, 10, 0, 123, fmt10);
    worksheet_write_number(ws, 11, 0, -45, fmt10);
    worksheet_write_number(ws, 12, 0, 0, fmt10);

    // format a zip code
    format_set_num_format(fmt11, "0000");
    worksheet_write_number(ws, 13, 0, 1209, fmt11);

    lxw_error error = workbook_close(wb);
    if (error)
    {
        fprintf(stderr, "failed to close workbook: %d = %s\n",
            error, lxw_strerror(error));

        return error;
    }

    puts("finished");

    return 0;
}