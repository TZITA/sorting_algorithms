#include "sort.h"

/**
 * swap - Swaps two integers
 *
 * @a: one int
 * @b: second int
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * part - Divides the array(or sub array) into two partitions
 * @array: Array to partition
 * @l: Lower end of the array
 * @h: Higher end of the array
 *
 * Return: i.
 */
int part(int *array, size_t size, int l, int h)
{
	int *pivot;
	int i;
	int j;

	pivot = array + h;
	for (i = j = l; j < h; j++)
	{
		if (array[j] <= *pivot)
		{
			if (i < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_recur - Recursive function
 *
 * @array: Array to sort
 * @l: Lower end 
 * @h: Higher end
 */
void quick_recur(int *array, size_t size, int l, int h)
{
	int part_t;

	if (h - l > 0)
	{
		part_t = part(array, size, l, h);
		quick_recur(array, size, l, part_t - 1);
		quick_recur(array, size, part_t + 1, h);
	}
}

/**
 * quick_sort - Sorting algorithm using quick sort algorithm
 * @array: The array to be sorted.
 * @size: The number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_recur(array, size, 0, size - 1);
}
