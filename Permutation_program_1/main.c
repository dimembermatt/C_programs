#include <stdio.h>
#include <string.h>

/**
/ Permutation program #1
/ based off of r/dailyprogrammer's challenge #12
/ C programming language.
/ Matthew Yu
/ 12/29/17
/ permute code and solution: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
/ educational purposes only.
/ This program will prompt for a string and will output all possible permutations of the string.
**/

void permute(char *pString, int startIndex, int endIndex);
void swap(char *char1, char *char2);

int main()
{
    char exitV[] = "exit";
    int out = 1;
    do{
        char string[50], sub[50];
        int f=0;
        printf("Enter a String. \n");
        fgets(string, sizeof(string), stdin);
        //string[50] = 'helloWorld';
        while(f < strlen(string)-1)
        {
            sub[f] = string[f];
            f++;
        }
        sub[f] = '\0';
        if(strlen(sub) == 0)
            printf("null string.\n");
        else if(!strcmp(exitV, sub))
        {
            out = 0;
        }
        else
            permute(sub, 0, strlen(sub)-1);
    }while(out);
    return 0;
}
/**
 * permute takes the char array string and prints out all permutations of the array.
 * @param pString[] input string
 * @param startIndex starting index
 * @param endIndex ending index
 */
void permute(char *pString, int startIndex, int endIndex)
{
    if(startIndex == endIndex)
    {
        printf("%s\n", pString);
    }
    else
    {
        for(int i = startIndex; i <= endIndex; i++)
        {
            swap((pString+startIndex), (pString+i));
            permute(pString, startIndex+1, endIndex);
            swap((pString+startIndex), (pString+i));
        }
    }
}
/**
 * swap swaps the address pointers for two characters in memory.
 * @param char1 address of character 1
 * @param char2 address of character 2
 */
void swap(char *char1, char *char2)
{
    char str = *char1;
    *char1 = *char2;
    *char2 = str;
}