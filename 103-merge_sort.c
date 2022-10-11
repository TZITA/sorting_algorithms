#include "sort.h"

/**
 * Merge - sorts
 *
 * @str: starting
 * @mid: middle
 * @end: end
 * @dest: destination
 * @src: source
 */
void Merge(size_t str, size_t mid, size_t end, int *dest, int *src)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[Left]: ");
	print_array(src + str, mid - str);
	printf("[right]: ");
	print_array(src + mid, end - mid);
	i = str;
	j = mid;
	for (k = str; k < end; k++)
	{
		if (i < mid && (j >= end || src[i] <= src[j]))
		{
			dest[k] = src[i];
			i++;
		}
		else
		{
			dest[k] = src[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + str, end - str);
}

/**
 * Split_M - recursively splits
 *
 * @str: start
 * @end: end
 * @array: Array
 * @cp: copy of array
 */
void Split_M(size_t str, size_t end, int *array, int *cp)
{
	size_t mid;

	if (end - str < 2)
		return;
	mid = (str + end) / 2;
	Split_M(str, mid, array, cp);
	Split_M(mid, end, array, cp);
	Merge(str, mid, end, array, cp);
	for (mid = str; mid < end; mid++)
	{
		cp[mid] = array[mid];
	}
}

/**
 * merge_sort - sorts using merge sorting algorithm
 *
 * @array: Array to be sorted
 * @size: Number of element in the array
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *cp;

	if (array == NULL || size < 2)
		return;
	cp = malloc(sizeof(int) * size);
	if (cp == NULL)
		return;
	for (i = 0; i < size; i++)
		cp[i] = array[i];
	Split_M(0, size, array, cp);
	free(cp);
}
