#include "slide_line.h"

/**
 * slide_left - Slides and merges an array of integers to the left.
 * @line: Pointer to an array of integers.
 * @size: Number of elements in the array.
 */
void slide_left(int *line, size_t size)
{
	size_t i, j = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (j > 0 && line[j - 1] == line[i])
			{
				line[j - 1] *= 2;
				line[i] = 0;
			}
			else
			{
				if (i != j)
				{
					line[j] = line[i];
					line[i] = 0;
				}
				j++;
			}
		}
	}
}

/**
 * slide_right - Slides and merges an array of integers to the right.
 * @line: Pointer to an array of integers.
 * @size: Number of elements in the array.
 */
void slide_right(int *line, size_t size)
{
	size_t i, j = size - 1;

	for (i = size - 1; i < size; i--)
	{
		if (line[i] != 0)
		{
			if (j < size - 1 && line[j + 1] == line[i])
			{
				line[j + 1] *= 2;
				line[i] = 0;
			}
			else
			{
				if (i != j)
				{
					line[j] = line[i];
					line[i] = 0;
				}
				j--;
			}
		}
	}
}

/**
 * slide_line - Slides and merges an array of integers.
 * @line: Pointer to an array of integers.
 * @size: Number of elements in the array.
 * @direction: Direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT).
 *
 * Return: 1 on success, or 0 on failure.
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_LEFT)
		slide_left(line, size);
	else if (direction == SLIDE_RIGHT)
		slide_right(line, size);

	return (1);
}
