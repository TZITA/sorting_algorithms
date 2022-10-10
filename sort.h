#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/*Given structure.*/
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous node
 * @next: Pointer to the next node
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*Given functions.*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*Sorting algorithms prototypes.*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/*Quick sort helper functions.*/
void swap(int *a, int *b);
int part(int *array, size_t size, int l, int h);
void quick_recur(int *array, size_t size, int l, int h);

/*Advanced tasks prototypes.*/
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);

#endif /*End of the sort header.*/
