#include <stdio.h>
#include <conio.h>
#include "get_choice.h"

int main()
{
  int choice;
  char choices[][128] = {"This is choice 1", "This is choice 2", "This is choice 3", "This is choice 4", "This is choice 5", "This is choice 6", "This is choice 7"};

  choice = get_choice(7, choices);

  if (choice == -1)
  {
    printf("Exiting...\n");
    return 0;
  }
  else
    printf("You chose: %s\n", choices[choice]);
}