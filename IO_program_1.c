#include <stdio.h>

/**
/ I\O program #1
/ based off of r/dailyprogrammer's challenge #1
/ C programming language.
/ Matthew Yu
/ 12/26/17
/
/ This program will ask the user's name, age, and reddit username.
/ It will return in the format:
/ your name is (blank), you are (blank) years old, and your username is (blank).
**/

int main()
{
  char name[25], username[25], endch;
  int age;

  printf("What is your name? ");
  scanf("%s", &name);
  printf("What is your age? ");
  scanf("%i", &age);
  printf("What is your username? ");
  scanf("%s", &username);
  printf("Your name is %s, you are %i years old, and your username is %s.", name, age, username);
  while(endch != 'A')    // terminates if user hit enter
  {
      endch = getchar();
  }


  return 1;
}
