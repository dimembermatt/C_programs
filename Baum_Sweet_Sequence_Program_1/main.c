#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
/ Baum_Sweet_Sequence #1
/ Based off of r/dailyprogrammer's challenge #344
/ https://www.reddit.com/r/dailyprogrammer/comments/7j33iv/20171211_challenge_344_easy_baumsweet_sequence/
/ C programming language.
/ Matthew Yu
/ 1/7/18
/
/ This program has two modes, one for a single n and one for 0 - n. It asks for number n,
/ which should be >= 0, and it outputs a Baum Sweet Sequence for that number or numbers 0 - n.
/ It is recommended to not run numbers higher than a couple thousand for 0 - n. Complexity is
/ at least O(n).
**/
int BaumSweet(long n);
int main()
{
    char buff[50], * end;
    long n;
    int flag;
    printf("Hello, World!\n");
    while(1)
    {
        printf("Enter a mode. single or 1-n ('1' or '2'. 'exit' to exit.)");
        fgets(buff, sizeof(buff), stdin);
        if(buff[0] == '1')
        {
            printf("Enter a number larger than 0.('exit' to exit.)\n");
            fgets(buff, sizeof(buff), stdin);
            if(strstr(buff, "exit") != NULL)
                break;
            else
            {
                n = strtol(buff, &end, 10);
                printf("Entered: %.0d\n", n);
                flag = BaumSweet(n);
                printf("%d.\n", flag);
            }
        }
        else if(buff[0] == '2')
        {
            printf("Enter a number larger than 0.('exit' to exit.)\n");
            fgets(buff, sizeof(buff), stdin);
            if(strstr(buff, "exit") != NULL)
                break;
            else
            {
                n = strtol(buff, &end, 10);
                printf("Entered: %.0d\n", n);
                for(int i = 0; i <= n; i++)
                {
                    flag = BaumSweet(i);
                    if(i == n)
                        printf("%d.\n", flag);
                    else
                        printf("%d, ", flag);
                }
                printf("\n");
            }
        }
        else if(strstr(buff, "exit") != NULL)
            break;
        else
            printf("Invalid option.\n");

    }
    return 0;
}

/**
 * BaumSweet calculates the Baum-Sweet value of the given number.
 * @param n number to check
 * @return int flag 0 or 1
 */
int BaumSweet(long n)
{
    int counter = 0, shift = 0, ret = 1;
    if (!n)
        n = 0;
    while (n >>= 1)
        ret <<= 1;
    n = ret;
    for(shift; shift <= n; shift ++)
    {
        if((n >> shift)% 2 == 0)
            counter++;
        else
        {
            if(counter % 2 == 1)
                return 0;
            else
                counter = 0;
        }
    }
    return 1;
}