#include "sort.h"

/**
 * shift_down - fixes a heap
 * @array: Array
 * @r: root of heap
 * @end: end
 * @size: size
 */
void shift_down(int *array, size_t r, size_t end, size_t size)
{
	size_t left_child, right_child, swap;
	int tmp;

	while ((left_child = (2 * r) + 1) <= end)
	{
		swap = r;
		right_child = left_child + 1;
		if (array[swap] < array[left_child])
			swap = left_child;
		if (right_child <= end && array[swap] < array[right_child])
			swap = right_child;
		if (swap == r)
			return;
		tmp = array[r];
		array[r] = array[swap];
		array[swap] = tmp;
		print_array(array, size);
		r = swap;
	}
}

/**
 * make_heap - makes a heap of unsorted array
 *
 * @array: array
 * @size: size
 */
void make_heap(int *array, size_t size)
{
	size_t p;

	for (p = ((size - 1) - 1) / 2; 1; p--)
	{
		shift_down(array, p, size - 1, size);
		if (p == 0)
			break;
	}
}


/**
 * heap_sort - sorts using heap algorithm
 *
 * @array: Array to be sorted
 * @size: number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int tmp;

	if (array == NULL || size < 2)
		return;
	make_heap(array, size);
	end = size - 1;
	while (end > 0)
	{
		tmp = array[end];
		array[end] = array[0];
		array[0] = tmp;
		print_array(array, size);
		end--;
		shift_down(array, 0, end, size);
	}
}
