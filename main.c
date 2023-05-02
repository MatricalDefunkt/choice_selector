#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "get_choice.h"

int main()
{
  int *choice;
  char choices[][3][128] = {
      {"Choice 1", "Choice 2", "Choice 3"},
      {"Choice 4", "Choice 5", "Choice 6"},
      {"Choice 7", "Choice 8", "Choice 9"}};

  choice = get_table_choice(3, 3, choices);

  if (choice[0] == -1)
    printf("No choice selected");
  else
    printf("Choice selected: %s", choices[choice[0]][choice[1]]);
}