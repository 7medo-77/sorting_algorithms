#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/* 0. Bubble sort */
void bubble_sort(int *array, size_t size);
void swap(int *a, int *b);
/* 1. Insertion sort */
void insertion_sort_list(listint_t **list);
/* 2. Selection sort */
void selection_sort(int *array, size_t size);
/* 3. Quick sort */
void quick_sort(int *array, size_t size);
void quick_sort_recursion(int *array, ssize_t low, ssize_t high, size_t size);
size_t partition(int *array, ssize_t low, ssize_t high, size_t size);
void swap(int *a, int *b);
/* 100. Shell sort */
void shell_sort(int *array, size_t size);
void shell_sort_recursion(int *array, ssize_t size, ssize_t gap);
/* 101. Cocktail sort */
void cocktail_sort_list(listint_t **list);
size_t calculate_list_length(listint_t *head);
void swap_2(const int *firstElement, const int *secondElement);
/* 102. Counting sort */
void counting_sort(int *array, size_t size);
/* 103. Merge sort */
void merge_sort(int *array, size_t size);
/* 104. Heap sort */
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t index);
void print_array_2(const int *array, size_t size);
/* 105. Radix sort */
void distribute_digits(int *array, int **buffer, int size, int digit);
void count_digits(int *array, int size, int digit);
void radix_sort(int *array, size_t size);
/* 106. Bitonic sort */
void bitonic_sort(int *array, size_t size);
void bitonic_sort_recursion(int *array,
ssize_t low, ssize_t high, size_t size);
void swap_Elements(int *array, int i, int j, int dir);
/* 107. Quick Sort - Hoare Partition scheme */
void exchange(int *array, int index1, int index2);
int divide(int *array, int start, int end, size_t size);
void quicksort(int *array, int start, int end, size_t size);
void quick_sort_hoare(int *array, size_t size);


#endif
