#include <stdio.h>
#include <conio.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "get_choice.h"

int *get_table_choice(int num_rows, int num_cols, char choices[][MAX_COLS][128])
{
  int *choice = (int *)malloc(sizeof(int) * 2);
  choice[0] = 0;
  choice[1] = 0;

  if (num_rows > 10 || num_cols > 3)
  {
    // Use errno to set error code
    errno = EINVAL;
    printf("Error: Number of rows and columns must be less than 10");
  }

  if (num_rows < 1 || num_cols < 1)
  {
    // Use errno to set error code
    errno = EINVAL;
    printf("Error: Number of rows and columns must be greater than 0");
  }

  // Subtract 1 from num_cols and num_rows to account for the fact that arrays start at 0
  num_cols--;
  num_rows--;

  while (1)
  {
    // Display choices
    for (int i = 0; i < num_rows + 1; i++)
    {
      for (int j = 0; j < num_cols + 1; j++)
      {
        if (i == choice[0] && j == choice[1])
        {
          printf(GREEN_BACKGROUND);
          printf("\t");
          printf("%s", choices[i][j]);
          printf(RESET_BACKGROUND);
        }
        else
        {
          printf("\t");
          printf("%s", choices[i][j]);
        }
      }
      printf("\n");
    }

    // Get user input
    int input = getch();

    if (input == 27)
    {
      choice[0] = -1;
      choice[1] = -1;
      return choice;
    }
    else if (input == '\r')
    {
      return choice;
    }
    else if (input == -32)
      input = getch();

    if (input == 72)
    {
      if (choice[0] == 0)
        choice[0] = num_rows;
      else
        choice[0]--;
    }
    else if (input == 80)
    {
      if (choice[0] == num_rows)
        choice[0] = 0;
      else
        choice[0]++;
    }
    else if (input == 75)
    {
      if (choice[1] == 0)
        choice[1] = num_cols;
      else
        choice[1]--;
    }
    else if (input == 77)
    {
      if (choice[1] == num_cols)
        choice[1] = 0;
      else
        choice[1]++;
    }

    // Clear previous choices
    for (int i = 0; i < num_rows + 1; i++)
      printf("\033[A\033[2K");
  }
}