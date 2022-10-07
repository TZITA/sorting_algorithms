#include "sort.h"

/**
 * selection|_sort - Sorting algorithms using Selection sort algorithm
 *
 * @array: Array to be sorted
 * @size: The number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t min;
	size_t tmp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
