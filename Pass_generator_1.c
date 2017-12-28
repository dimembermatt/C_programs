#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
/ Password Generator program #1
/ based off of r/dailyprogrammer's challenge #4
/ C
/ Matthew Yu
/ 12/28/17
/
/ This program will ask for the length of the password that the user wants,
/ as well as how many passwords the user wants generated.
**/

void genPass(int lengthPass);

int main()
{
  char endch = 'n';
  srand(time(0));
  do{
    int lengthPass, numPass;
    // password length prompt.
    while (1)
    {
      printf("How many characters do you want your password to be? ");
      if(scanf("%u", &lengthPass) <= 0)
        lengthPass = 0;
      if(lengthPass > 0 && lengthPass <= 25)
         break;
      else
         printf("Invalid input, try again.\n");
    }
    // password number prompt.
    while (1)
    {
      printf("How many passwords do you want to generate? ");
      scanf("%u", &numPass);
      if(numPass > 0 && numPass <= 10)
        break;
      else
        printf("Invalid input, try again.\n");
    }
    // function call.
    while(numPass > 0)
    {
      genPass(lengthPass);
      printf("\n");
      numPass --;
    }
    // exit routine.
    int num = 0;
    printf("Enter '1' to exit, or another key to continue.");
    scanf("%u", &num);
      //scanf("%c", endch);
      //printf("%s\n", endch);
    if(num == 1)
      exit(0);

  } while(1);
  return 1;
}

/**
*  genPass generates a password from an input
*  length with chars 0-10, A-Z, and a-z.
*  @param lengthPass length of password
*  precondition: lengthPass > 0
**/
void genPass(int lengthPass)
{
  printf("\nYour password is: ");
  while(lengthPass > 0)
  {
    int rand_num = rand();
    int result = rand_num % 62;
    //printf("%c\t\t//", result);
    if(result >=0 && result <10)
      result = result + 48;
    else if(result >=10 && result <36)
      result = result + 55;
    else if(result >=36 && result <62)
      result = result + 61;
    else
      printf("Password generated is out of bounds.");
    printf("%c", result);
    lengthPass --;
  }
}
