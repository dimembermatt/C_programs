#include <stdio.h>
#include <ctype.h>
/**
/ Cipher program #1
/ based off of r/dailyprogrammer's challenge #3
/ C programming language.
/ Matthew Yu
/ 12/28/17
/ ERR - IO doesn't work. problems with buffer? etc, abandoned.
/ This program will prompt for a message to be encrypted or decrypted.
/ It uses an alphabetical caesar cipher and can ignore numbers,
/ symbols, and whitespace.
**/
#define SHIFT 1
#define msgLength 250

void encrypt();
void decrypt();

int main()
{
    char response, buffFill;
    do{
        printf("Would you like to encrypt or decrypt a message? 'E' for encrypt or 'D' for decrypt. 'A' to exit. ");
        response = (char) getchar();
        buffFill = (char) getchar();
        if(response != 'A')
        {
            if(response == 'E')
                encrypt();
            else if(response == 'D')
                decrypt();
            else
            {
                printf("Invalid response.\n");
            }
            response = '\0';
        }
    }while(response != 'A');
    return 1;
}
/**
*  encrypt takes a String input as a series of chars with \n terminator
*  and adds SHIFT to the ascii value of each char until the entire substring
*  is encrypted. It then returns the array of chars.
**/
void encrypt()
{
    char buff[msgLength], currentChar;
    int i = 0;
    printf("Please enter a message to encrypt. ");
    fgets(buff, msgLength, stdin);
    while(buff[i] != '\n')
    {
      currentChar = buff[i];
      if((currentChar >= 'a' && currentChar <= 'z') || (currentChar >= 'A' && currentChar <= 'Z'))
      {
          currentChar = (char) tolower(currentChar);
          if(currentChar >= 'a' && currentChar < 'z')
          {
              currentChar = currentChar + SHIFT;
              buff[i] = currentChar;
          }
          else if(currentChar == 'z')
          {
              //or some letter at the beginning of the alphabet based on SHIFT
              currentChar = 'a';
              buff[i] = currentChar;
          }
      }else if(currentChar != (' ') && currentChar != ('!') && currentChar != ('?') && currentChar != ('.') && currentChar != (','))
      {
          for(int j = i+1; buff[j] != NULL; j++)
              buff[j-1] = buff[j];
          i --;
      }else;
      i++;
      //printf("%c", currentChar);
    }
    buff[i] = '\0';
    printf("%s\n", buff);
}

/**
*  decrypt takes a String input as a series of chars with \n terminator
*  and removes SHIFT to the ascii value of each char until the entire substring
*  is encrypted. It then returns the array of chars.
*  @param stringArray char array of input
*  return stringArray char array of input
**/
void decrypt()
{
    char buff[msgLength], currentChar;
    int i = 0;
    printf("Please enter a message to decrypt. ");
    fgets(buff, msgLength, stdin);
    while(buff[i] != '\n')
    {
        currentChar = buff[i];
        if((currentChar >= 'a' && currentChar <= 'z') || (currentChar >= 'A' && currentChar <= 'Z'))
        {
            currentChar = (char) tolower(currentChar);
            if(currentChar > 'a' && currentChar <= 'z')
            {
                currentChar = currentChar - SHIFT;
                buff[i] = currentChar;
            }
            else if(currentChar == 'a')
            {
                //or some letter at the beginning of the alphabet based on SHIFT
                currentChar = 'z';
                buff[i] = currentChar;
            }
        }else if(currentChar != (' ') && currentChar != ('!') && currentChar != ('?') && currentChar != ('.') && currentChar != (','))
        {
            for(int j = i+1; buff[j] != NULL; j++)
                buff[j-1] = buff[j];
            i --;
        }else;
        i++;
    }
    buff[i] = '\0';
    printf("%s\n", buff);
}

