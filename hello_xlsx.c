#include <stdio.h>
#include <xlsxwriter.h>

int main(void)
{
    lxw_workbook *wb = workbook_new("hello_world.xlsx");
    lxw_worksheet *ws = workbook_add_worksheet(wb, NULL);

    worksheet_write_string(ws, 0, 0, "Hello", NULL);
    worksheet_write_number(ws, 1, 0, 123, NULL);

    workbook_close(wb);

    return 0;
}