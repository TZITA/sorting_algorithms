#include "sort.h"

/**
 * p10 - power of 10
 * @power: power
 *
 * Return: digit power of 10
 */
size_t p10(size_t power)
{
	size_t i;
	size_t res = 1;

	for (i = 0; i < power; i++)
		res *= 10;
	return (res);
}

/**
 * c_sort - sorts
 * @array: ARRAY
 * @size: size
 * @digit: digit
 *
 * Return: 1 or 0.
 */
size_t c_sort(int *array, size_t size, size_t digit)
{
	int *cp = NULL;
	size_t i, j;
	size_t tmp, dp1, dp2;
	size_t ttl = 0;
	size_t sort = 0;
	int count[10] = {0};

	dp2 = p10(digit - 1);
	dp1 = dp2 * 10;
	cp = malloc(sizeof(int) * size);
	if (cp == NULL)
		exit(99);
	for (j = 0; j < size; j++)
	{
		cp[j] = array[j];
		if (array[j] / dp1 != 0)
			sort = 1;
	}
	for (i = 0; i < 10; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[(array[j] % dp1) / dp2] += 1;
	for (i = 0; i < 10; i++)
	{
		tmp = count[i];
		count[i] = ttl;
		ttl += tmp;
	}
	for (j = 0; j < size; j++)
	{
		array[count[(cp[j] % dp1) / dp2]] = cp[j];
		count[(cp[j] % dp1) / dp2] += 1;
	}
	free(cp);
	return (sort);
}

/**
 * radix_sort - sorts using radix sorting algorithm
 *
 * @array: Array to be sorted
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	size_t i, s = 1;

	if (array == NULL || size < 2)
		return;
	for (i = 1; s == 1; i++)
	{
		s = c_sort(array, size, i);
		print_array(array, size);
	}
}
