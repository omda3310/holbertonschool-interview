#include <stdio.h>
#include <math.h>

#include "menger.h"

/*
* draw_sponge - draw one level of sponge
* @level: level of sponge
* @x: row index
* @y: column index
*/

void draw_sponge(int level, int x, int y)
{
/**
Calculate the size of the current level sponge
*/
int size = pow(3, level);

if (level == 0)
{
    printf("#");
}
else
{
    /**
    Check if current position is the center of the sponge
    */
    if (x >= size / 3 && x < 2 * size / 3 && y >= size / 3 && y < 2 * size / 3)
    {
        printf(" ");
    }
    else
    {
        draw_sponge(level - 1, x % (size / 3), y % (size / 3));
    }
}
}

/**
* menger - create sponge
* @level: level of sponge
*/

void menger(int level)
{
if (level < 0)
{
return;
}

int size1 = pow(3, level);
int i, j;

/**
Draw the Menger Sponge
*/
for (i = 0; i < size1; i++)
{
    for (j = 0; j < size1; j++)
    {
        draw_sponge(level, i, j);
    }
    printf("\n");
}
}
