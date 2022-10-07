#include "sort.h"

/**
 * insertin_sort - Insertion sorting algorithm
 * 
 * @list: List to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	const int i;
	const int j;
	const int k;
	const int len = sizeof(list) / sizeof(list[0])

	for (i = 0; i < len; i++)
	{
		j = list[i]->n;
		k = i - 1;

		while (k >= 0 && list[k]->n > j)
		{
			list[k + 1] = list[k];
			k = k - 1;
		}
		list[k + 1]->n = j;
	}
}
