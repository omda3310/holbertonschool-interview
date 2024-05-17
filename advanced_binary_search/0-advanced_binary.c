#include <stdio.h>
#include "search_algos.h"


/**
 * print_array - Prints an array
 * @array: The array to print
 * @start: Starting index to print from
 * @end: Ending index to print to
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t i;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i < end)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_search_recursive - Search first occur
 * @array: The array to print
 * @value: search value
 * @left: Starting index to print from
 * @right: Ending index to print to
 * Return: return first occur
 */

int binary_search_recursive(
	int *array, int value, size_t left, size_t right)
	{
	size_t mid;

	if (left > right)
		return (-1);
	mid = left + (right - left) / 2;
	print_array(array, left, right);
	if (array[mid] == value && (mid == 0 || array[mid - 1] != value))
		return (mid);

	if (array[mid] < value)
		return (binary_search_recursive(array, value, mid + 1, right));
	else
		return (binary_search_recursive(array, value, left, mid));
}

/**
 * advanced_binary - recursive function
 * @array: The array to print
 * @size: size of array
 * @value: search value
 * return: index or -1
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (binary_search_recursive(array, value, 0, size - 1));
}
