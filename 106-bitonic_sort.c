#include "sort.h"

/**
 * b_cmp - sorts in bitonic sort
 *
 * @up: direction
 * @array: Array
 * @size: size
 */
void b_cmp(char up, int *array, size_t size)
{
	size_t i;
	size_t j;
	int swap;

	j = size / 2;
	for (i = 0; i < j; i++)
	{
		if ((array[i] > array[i + j]) == up)
		{
			swap = array[i];
			array[i] = array[i + j];
			array[i + j] = swap;
		}
	}
}

/**
 * b_merge - recursively merge
 * @up: direction
 * @array: Array
 * @size: size
 */
void b_merge(char up, int *array, size_t size)
{
	if (size < 2)
		return;
	b_cmp(up, array, size);
	b_merge(up, array, size / 2);
	b_merge(up, array + (size / 2), size / 2);
}


/**
 * bit_s - recursive function
 *
 * @up: direction
 * @array: Array
 * @size: size
 * @ttl: total size
 */
void bit_s(char up, int *array, size_t size, size_t ttl)
{
	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, ttl, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
	bit_s(1, array, size / 2, ttl);
	bit_s(0, array + (size / 2), size / 2, ttl);
	b_merge(up, array, size);
	printf("Result [%lu/%lu] (%s):\n", size, ttl, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
}


/**
 * bitonic_sort - sorts
 *
 * @array: Array
 * @size: size
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bit_s(1, array, size, size);
}
