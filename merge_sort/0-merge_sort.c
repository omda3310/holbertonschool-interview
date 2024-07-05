#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - merge an array of integers
 *
 * @array: The array to be printed
 * @right: The right array to be printed
 * @left: The left array to be printed
 * @right_size: Number of elements in right @array
 * @left_size: Number of elements in left @array
 */

void merge(int *array, int *left, int left_size, int *right, int right_size)
{
	int i, j, k;

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	i = j = k = 0;
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < left_size)
		array[k++] = left[i++];

	while (j < right_size)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, left_size + right_size);
}

/**
 * merge_sort - sort an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	size_t i, mid, left_size, right_size;
	mid = size / 2;
	left_size = mid;
	right_size = size - mid;*

	if (size < 2)
		return;

	int *left = (int *)malloc(left_size * sizeof(int));
	int *right = (int *)malloc(right_size * sizeof(int));

	if (left == NULL || right == NULL)
	{
		free(left);
		free(right);
		return;
	}

	for (i = 0; i < left_size; i++)
		left[i] = array[i];
	for (i = 0; i < right_size; i++)
		right[i] = array[i + mid];

	merge_sort(left, left_size);
	merge_sort(right, right_size);
	merge(array, left, left_size, right, right_size);

	free(left);
	free(right);
}
