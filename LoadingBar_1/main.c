#include <stdio.h>
#include <limits.h>

/**
 * Loading Bar #1
 * C
 * @author: Matthew Yu
 * @version 1.0
 *
 *
 * Simple IO program experimenting with carriage returns to create a loading bar.
 */

void wait();
int main()
{
    char ellipses[3][3] = {{'.', '.', '.'}, {' ', '.', '.'}, {' ', ' ', '.'}};
    printf("Hello, World!\n");
    for(int y = 0; y < 3; y++)
    {
        printf("Loading%c%c%c\r", ellipses[0][y], ellipses[1][y], ellipses[2][y]);
        wait();
    }
    printf("loading complete!\n");

    return 0;
}

void wait()
{
    for(unsigned int i = 0; i < UINT_MAX/2; i++);
}