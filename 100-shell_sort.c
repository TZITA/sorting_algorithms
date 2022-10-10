#include "sort.h"

/**
 * shell_sort - Sorts using shell sorting algorithm
 *
 * @array: Array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t k_gap = 1;
	size_t i;
	size_t j;
	int tmp;

	if (array == NULL || size < 2)
		return;
	while (k_gap < size / 3)
		k_gap = k_gap * 3 + 1;
	while (k_gap > 0)
	{
		for (i = k_gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= k_gap && array[j - k_gap]; j -= k_gap)
				array[j] = array[j - k_gap];
			array[j] = tmp;
		}
		k_gap = (k_gap - 1) / 3;
		print_array(array, size);
	}
}
