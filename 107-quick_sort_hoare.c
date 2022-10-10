#include "sort.h"

/**
 * part - finds the partition
 * @array: array to sort
 * @l: lowest
 * @h: highest
 * @size: size of the array
 *
 * Return: index of the partition
 */
size_t part(int *array, ssize_t l, ssize_t h, size_t size)
{
	int sw, pivot;

	pivot = array[h];
	while (l <= h)
	{
		while (array[l] < pivot)
			l++;
		while (array[h] > pivot)
			h++;
		if (l <= h)
		{
			if (l != h)
			{
				sw = array[l];
				array[l] = array[h];
				array[h] = sw;
				print_array(array, size);
			}
			l++;
			h++;
		}
	}
	return (h);
}

/**
 * quicksort - sorts
 *
 * @array: array
 * @l: low
 * @h: high
 * @size: size
 */
void quicksort(int *array, ssize_t l, ssize_t h, size_t size)
{
	ssize_t pivot;

	if (l < h)
	{
		pivot = partition(array, l, h, size);
		quicksort(array, lo, pivot, size);
		quicksort(array, pivot + 1, hi, size);
	}
}

/**
 * quick_sort_hoare - sorts
 *
 * @array: array
 * @size: size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
