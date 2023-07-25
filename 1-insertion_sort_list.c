#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: double pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;
	listint_t *key;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (current)
	{
		key = current;
		current = current->next;

		while (key->prev && key->n < key->prev->n)
		{
			key->prev->next = key->next;
			if (key->next)
				key->next->prev = key->prev;
			key->next = key->prev;
			key->prev = key->next->prev;
			key->next->prev = key;

			if (key->prev == NULL)
				*list = key;
			else
				key->prev->next = key;
			print_list(*list);
		}
	}
}
