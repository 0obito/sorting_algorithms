#include "sort.h"

/**
 * insertion_sort_list - a function that sorts
 * a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 *
 * @list: double pointer to
 * the list we are sorting.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = *list;
	while (current != NULL)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			temp = current->prev;

			/* Order matters broski ! Watch out !*/
			temp->next = current->next;
			current->prev = temp->prev;
			current->next = temp;
			temp->prev = current;

			if (current->prev != NULL)
				current->prev->next = current;

			if (temp->next != NULL)
				temp->next->prev = temp;

			if (current->prev == NULL)
				*list = current;

			print_list(*list);
		}
		current = current->next;
	}
}
