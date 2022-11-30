#include <stdio.h>
#include <xlsxwriter.h>

struct expense
{
    char item[32];
    int cost;
};

struct expense expenses[] = {
    {"Rent", 1000},
    {"Gas", 100},
    {"Food", 300},
    {"Gym", 50},
};


int main(void)
{
    lxw_workbook *wb = workbook_new("set_expense.xlsx");
    lxw_worksheet *ws = workbook_add_worksheet(wb, NULL);

    // start from the first cell
    int row = 0;
    int col = 0;

    for (int row = 0; row < 4; row++)
    {
        worksheet_write_string(ws, row, col, expenses[row].item, NULL);
        worksheet_write_number(ws, row, col + 1, expenses[row].cost, NULL);
    }

    worksheet_write_string(ws, row, col, "Total: ", NULL);
    worksheet_write_string(ws, row, col + 1, "=SUM(B1:B4)", NULL);

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