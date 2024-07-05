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
	right_size = size - mid;
	int *left_arr, *right_arr;

	if (size < 2)
		return;

	left_arr = (int *)malloc(left_size * sizeof(int));
	right_arr = (int *)malloc(right_size * sizeof(int));

	if (left_arr == NULL || right_arr == NULL)
	{
		free(left_arr);
		free(right_arr);
		return;
	}

	for (i = 0; i < left_size; i++)
		left_arr[i] = array[i];
	for (i = 0; i < right_size; i++)
		right_arr[i] = array[i + mid];

	merge_sort(left_arr, left_size);
	merge_sort(right_arr, right_size);
	merge(array, left_arr, left_size, right_arr, right_size);

	free(left_arr);
	free(right_arr);
}
