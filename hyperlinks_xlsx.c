#include <stdio.h>
#include <xlsxwriter.h>

int main(void)
{
    lxw_workbook *wb = workbook_new("hyperlinks.xlsx");
    lxw_worksheet *ws = workbook_add_worksheet(wb, NULL);

    // set default URL format
    lxw_format *urlfmt = workbook_get_default_url_format(wb);

    // create user defined link format
    lxw_format *red_fmt = workbook_add_format(wb);
    format_set_underline(red_fmt, LXW_UNDERLINE_SINGLE);
    format_set_font_color(red_fmt, LXW_COLOR_RED);

    worksheet_set_column(ws, 0, 0, 30, NULL);

    // write a hyperlink
    worksheet_write_url(ws, 0, 0, "http://somesite.com.github.xyz", NULL);
    
    // write a url, overwrite the displayed string
    worksheet_write_url(ws, 2, 0, "http://libwriter.netz.com", NULL);
    worksheet_write_string(ws, 2, 0, "Read the documentation", urlfmt);

    // url with a different format
    worksheet_write_url(ws, 4, 0, "http://somesite.com.pz", red_fmt);

    // mail hyperlink
    worksheet_write_url(ws, 6, 0, "mailto:someemail@somedomain.org", NULL);

    // write a mail hyperlink and overwrite it
    worksheet_write_url(ws, 8, 0, "mailto:someemail@gal.com", NULL);
    worksheet_write_string(ws, 8, 0, "www.google.com", urlfmt);

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