#include <stdio.h>
#include <stdlib.h>

/**
/ Prime numbers program #1
/ based off of r/dailyprogrammer's challenge #20
/ C programming language.
/ Matthew Yu
/ 12/29/17
/ The program asks for a number larger than 1 and will list all primes from 2 to n.
/ The algorithm used for the program is the Sieve of Eratosthenes.
**/
void sieve(int num);

int main()
{

    int out = 1;
    while(out)
    {
        char entry[50];
        int num, *retArrayPtr;
        printf("Enter a number.\n");
        fgets(entry, sizeof(entry), stdin);
        num = atoi(entry);
        if(num <= 1)
            printf("%i is an invalid value. N must be larger than 1.", num);
        else
        {
            sieve(num);
            //removed implementation of a static array and outputted results from sieve();
            out = 0;
        }
    }
    return 0;
}

void sieve(int num)
{
    int primeArray[num], base = 2, h = base;
    while(h * h <= num)
        h++;
    //mark locations of array that are not primes of x base with 1
    while(base <= h)
    {
        for(int i = base + base; i <= num; i = i + base)
        {
            primeArray[i] = 1;
        }
        base++;
    }
    //print out locations of array that are not marked (1)
    printf("Prime numbers from 2 to %i are: ", num);
    for(int j = 2; j<=num; j++)
     {
         if(primeArray[j] != 1)
         printf("%i ", j);
     }
}