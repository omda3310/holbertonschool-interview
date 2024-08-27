#include <stdio.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the head of the list
 *
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast, *second_half, *prev_slow;
	listint_t *mid_node = NULL;
	int result = 1;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	slow = fast = prev_slow = *head;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		prev_slow = slow;
		slow = slow->next;
	}

	if (fast != NULL)
	{
		mid_node = slow;
		slow = slow->next;
	}

	second_half = slow;
	prev_slow->next = NULL;
	second_half = reverse_list(second_half);
	result = compare_lists(*head, second_half);

	second_half = reverse_list(second_half);

	if (mid_node != NULL)
	{
		prev_slow->next = mid_node;
		mid_node->next = second_half;
	}
	else
	{
		prev_slow->next = second_half;
	}

	return (result);
}

/**
 * reverse_list - reverses a singly linked list
 * @head: pointer to the head of the list
 *
 * Return: pointer to the new head (reversed list)
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL, *current = head, *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	return (prev);
}

/**
 * compare_lists - compares two linked lists for equality
 * @first: pointer to the first list
 * @second: pointer to the second list
 *
 * Return: 1 if the lists are equal, 0 otherwise
 */
int compare_lists(listint_t *first, listint_t *second)
{
	while (first != NULL && second != NULL)
	{
		if (first->n != second->n)
			return (0);
		first = first->next;
		second = second->next;
	}

	return (first == NULL && second == NULL);
}
