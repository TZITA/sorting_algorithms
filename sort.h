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

/*Other helper functions*/
void swap_c(listint_t **list, listint_t *node);
void Merge(size_t str, size_t mid, size_t end, int *dest, int *src);
void Split_M(size_t str, size_t end, int *array, int *cp);
void quicksort(int *array, ssize_t l, ssize_t h, size_t size);
size_t part(int *array, ssize_t l, ssize_t h, size_t size);

/*Advanced tasks prototypes.*/
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif /*End of the sort header.*/
