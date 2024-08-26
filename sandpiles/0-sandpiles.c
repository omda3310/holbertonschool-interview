#include <stdio.h>
#include "sandpiles.h"


/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid to be printed
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: First sandpile grid
 * @grid2: Second sandpile grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	while (!is_stable(grid1))
	{
		print_grid(grid1);
		topple(grid1);
	}
}

/**
 * is_stable - Checks if a sandpile is stable
 * @grid: Sandpile grid to check
 *
 * Return: 1 if stable, 0 if not
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * topple - Topples the sandpile until it becomes stable
 * @grid: Sandpile grid to topple
 */
void topple(int grid[3][3])
{
	int i, j;
	int temp_grid[3][3] = {0};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				temp_grid[i][j] -= 4;
				if (i - 1 >= 0)
					temp_grid[i - 1][j] += 1;
				if (i + 1 < 3)
					temp_grid[i + 1][j] += 1;
				if (j - 1 >= 0)
					temp_grid[i][j - 1] += 1;
				if (j + 1 < 3)
					temp_grid[i][j + 1] += 1;
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] += temp_grid[i][j];
		}
	}
}
