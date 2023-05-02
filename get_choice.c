#include <conio.h>
#include <stdio.h>
#include <string.h>

#define ARROW_UP 72

int get_choice(int num_choices, char choices[][128])
{
  int choice = 0;

  // Add "No choice" option to the end of the choices array
  strcpy(choices[num_choices], "No choice");

  while (1)
  {
    // Display choices
    for (int i = 0; i < num_choices + 1; i++)
    {
      if (i == choice)
        printf("\033[32m> \033[0m");
      else
        printf("  ");
      printf("%s\n", choices[i]);
    }

    // Get user input
    int input = getch();

    if (input == '\r')
    {
      if (choice == num_choices)
        return -1;
      else
        return choice;
    }
    else if (input == -32)
      input = getch();

    if (input == 72)
    {
      if (choice == 0)
        choice = num_choices;
      else
        choice--;
    }
    else if (input == 80)
    {
      if (choice == num_choices)
        choice = 0;
      else
        choice++;
    }

    // Clear previous choices
    for (int i = 0; i < num_choices + 1; i++)
      printf("\033[A\033[2K");
  }
}
