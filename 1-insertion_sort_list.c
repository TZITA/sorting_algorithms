#include "sort.h"

/**
 * insertion_sort_list - Insertion sorting algorithm
 *
 * @list: List to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *swap_n, *next_n;

	if (list == NULL || *list == NULL)
		return;
	swap_n = (*list)->next;
	while (swap_n != NULL)
	{
		next_n = swap_n->next;
		while (swap_n->prev != NULL && swap_n->prev->n > swap_n->n)
		{
			swap_n->prev->next = swap_n->next;
			if (swap_n->next != NULL)
				swap_n->next->prev = swap_n->prev;
			swap_n->next = swap_n->prev;
			swap_n->prev = swap_n->next->prev;
			swap_n->next->prev = swap_n;
			if (swap_n->prev == NULL)
				*list = swap_n;
			else
				swap_n->prev->next = swap_n;
			print_list(*list);
		}
		swap_n = next_n;
	}
}
