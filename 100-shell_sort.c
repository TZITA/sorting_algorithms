#include "sort.h"

/**
 * shell_sort - Sorts using shell sorting algorithm
 *
 * @array: Array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval;
	size_t i;
	size_t j;
	int tmp;

	for (interval = size / 2; interval > 0; interval /= 2)
	{
		for (i = interval; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= interval && array[j - interval] > tmp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
