#include "search.h"
#include <stdlib.h>

/**
 * linear_skip - Search for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located,
 * or NULL if not present
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *list2 = list, *list1 = NULL;

    if (list == NULL)
        return NULL;

    while (list2 != NULL)
    {
        printf("Value checked at index [%lu] = [%d]\n", list2->index, list2->n);
    
        if (list2->n >= value || list2->express == NULL)
            break;

        list1 = list2;
        list2 = list2->express;
    }

    if (list2->n == value)
    {
        printf("Value found between indexes [%lu] and [%lu]\n",
               list1 == NULL ? list2->index : list1->index, list2->index);
        return list2;
    }

    printf("Value found between indexes [%lu] and [%lu]\n",
           list1 == NULL ? list2->index : list1->index, list2->index);

    while (list1 != NULL && list1->index <= list2->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", list1->index, list1->n);
  
        if (list1->n == value)
            return list1;

        list1 = list1->next;
    }

    return NULL;
}
