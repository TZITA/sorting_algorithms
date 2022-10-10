#include "sort.h"

/**
 * shell_sort - Sorts using shell sorting algorithm
 *
 * @array: Array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t knuth = 1;
	size_t sm;
	size_t i;
	size_t j;
	int tmp;

	if (size < 2)
		return;
	while (knuth < size)
		knuth = knuth * 3 + 1;
	while (knuth > 1)
	{
		knuth = (knuth -1) / 3;
		for (i = 0; i < size - 1; i++)
		{
			sm = i;
			for (j = i + knuth; j < size; j += knuth)
			{
				if (array[j] < array[sm])
					sm = j;
			}
		}
		tmp = array[sm];
		array[sm] = array[i];
		array[i] = tmp;
	}
	print_array(array, size);
}
