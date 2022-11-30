#include <stdio.h>
#include <xlsxwriter.h>

int main(void)
{
    lxw_workbook *wb = workbook_new("fonts.xlsx");
    lxw_worksheet *ws = workbook_add_worksheet(wb, NULL);

    // widen the first column
    worksheet_set_column(ws, 0, 0, 20, NULL);

    // set formats for textual updates
    lxw_format *fmt = workbook_add_format(wb);
    lxw_format *fmt2 = workbook_add_format(wb);
    lxw_format *fmt3 = workbook_add_format(wb);

    // set basic formats
    format_set_bold(fmt);
    format_set_italic(fmt2);

    // set bold and italic for format3
    format_set_bold(fmt3); format_set_italic(fmt3);

    // write some formatted strings
    worksheet_write_string(ws, 0, 0, "This is bold", fmt);
    worksheet_write_string(ws, 1, 0, "This is italic", fmt2);
    worksheet_write_string(ws, 2, 0, "This is bold and italic", fmt3);

    lxw_error error = workbook_close(wb);
    if (error)
    {
        fprintf(stderr, "failed to close workbook\n%d = %s\n",
            error, lxw_strerror(error));

        return error;
    }

    puts("finished");

    return 0;
}