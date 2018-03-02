#include <stdio.h>
#include <string.h>
/**
/ I\O program #2
/ based off of r/dailyprogrammer's challenge #16
/ C programming language.
/ Matthew Yu
/ 12/26/17
/
/ This program will asks for two strings, and removes any characters in the first
/ string that is present in the second. Outputs the first string.
**/
int main()
{
    char string1[50], string2[50], thisChar;
    int loop = 0;
    printf("Enter String 1.\n");
    fgets(string1, sizeof(string1), stdin);
    printf("Enter String 2.\n ");
    fgets(string2, sizeof(string2), stdin);
    while(loop < strlen(string2))
    {
        thisChar = string2[loop];
        for(int i = 0; i < strlen(string1); i++)
        {
            if(thisChar == string1[i])
            {
                for(int j = i; j < strlen(string1); j++)
                    string1[j] = string1[j+1];
                i--;
            }
        }

        loop++;
    }
    printf("Result: %s", string1);
    return 0;
}