#include "sort.h"

/**
 * swap_c - swaps a node
 *
 * @list: list
 * @node: node to swap
 */
void swap_c(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}


/**
 * cocktail_sort_list - Sorts using the cocktail sorting algorithm
 *
 * @list: A doubly-linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	char s = 1;
	listint_t *tmp;

	if (list == NULL || *list == NULL)
		return;
	tmp = *list;
	while (s != 0)
	{
		s = 0;
		while (tmp->next != NULL)
		{
			if (tmp->next->n < tmp->n)
			{
				swap_c(list, tmp);
				s = 1;
				print_list(*list);
			}
			else
				tmp = tmp->next;
		}
		if (s == 0)
			break;
		s = 0;
		while (tmp->prev != NULL)
		{
			if (tmp->prev->n > tmp->n)
			{
				swap_c(list, tmp->prev);
				s = 1;
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
	}
}
