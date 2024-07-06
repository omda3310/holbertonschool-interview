#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - merge array of integers
 *
 * @array: The array to be printed
 * @temp: The copy of array to be printed
 * @left: first elements in @array
 * @mid: middle elements in @array
 * @right: last elements in @array
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i < mid)
		temp[k++] = array[i++];

	while (j < right)
		temp[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * top_down_split_merge - Prints an array of integers
 *
 * @array: The array to be printed
 * @temp: The copy of array to be printed
 * @left: first elements in @array
 * @right: last elements in @array
 */
void top_down_split_merge(int *array, int *temp, size_t left, size_t right)
{
	if (right - left <= 1)
		return;

	size_t mid = left + (right - left) / 2;

	top_down_split_merge(array, temp, left, mid);
	top_down_split_merge(array, temp, mid, right);
	merge(array, temp, left, mid, right);
}

/**
 * merge_sort - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	int *temp = malloc(size * sizeof(int));

	if (!temp)
		return;

	top_down_split_merge(array, temp, 0, size);

	free(temp);
}
