#include "sort.h"

/**
 * counting_sort - Sorting using counting algorithms
 *
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
	int i, max;
	int *count = NULL;
	int *cp = NULL;
	size_t j, tmp, ttl = 0;

	if (array == NULL || size < 2)
		return;
	cp = malloc(sizeof(int) * size);
	if (cp == NULL)
		return;
	for (j = 0, max = 0; j < size; j++)
	{
		cp[j] = array[j];
		if (array[j] > max)
			max = array[j];
	}
	count  = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(cp);
		return;
	}
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[array[j]] += 1;
	for (i = 0; i <= max; i++)
	{
		tmp = count[i];
		count[i] = ttl;
		ttl += tmp;
	}
	for (j = 0; j < size; j++)
	{
		array[count[cp[j]]] = cp[j];
		count[cp[j]] += 1;
	}
	print_array(count, max + 1);
	free(count);
	free(cp);
}
