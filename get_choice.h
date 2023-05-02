#ifndef GET_CHOICE_H
#define GET_CHOICE_H
#define MAX_COLS 3
#define MAX_ROWS 10
#define MAX_STRING_LEN 128
#define GREEN_BACKGROUND "\x1b[42m"
#define RESET_BACKGROUND "\x1b[49m"

int get_choice(int num_choices, char choices[][128]);
int *get_table_choice(int num_rows, int num_cols, char choices[][MAX_COLS][MAX_STRING_LEN]);

#endif