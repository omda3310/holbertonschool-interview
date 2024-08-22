#ifndef SORT_H
#define SORT_H

#include <stddef.h>

int get_max(int *array, size_t size);
void counting_sort(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

#endif
