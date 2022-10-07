#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 *  * main - Entry point
 *   *
 *    * Return: Always 0
 *     */
int main(void)
{
	int array[] = {526, 77, 117, 439, 50, 278, 46, 989, 676, 378};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	bubble_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
