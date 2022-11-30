#include <stdio.h>
#include <xlsxwriter.h>

int main(void)
{
    lxw_workbook *wb = workbook_new("properties.xlsx");
    lxw_worksheet *ws = workbook_add_worksheet(wb, NULL);

    // define properties structure
    lxw_doc_properties properties, *p_cpy;

    p_cpy = &properties;

    (*p_cpy).title = "This is an example spreadsheet";
    (*p_cpy).subject = "With document properties";
    (*p_cpy).author = "Some author";
    (*p_cpy).manager = "Dr. Some doctor";
    (*p_cpy).company = "of wolves";
    (*p_cpy).category = "Example spreadsheets";
    (*p_cpy).keywords = "sample, example, properties";
    (*p_cpy).comments = "created with libxlsxwriter";
    (*p_cpy).status = "Quo";

    // set properties
    workbook_set_properties(wb, &p_cpy);

    worksheet_set_column(ws, 0, 0, 50, NULL);
    worksheet_write_string(ws, 0, 0, "Select 'Workbook Properties' to see properties", NULL);

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