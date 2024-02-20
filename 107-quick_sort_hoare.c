#include "sort.h"

/**
 * exchange - Exchange two elements in an array
 * Return: Nothing
 * -----------------------
 * Prototype: void exchange(int *array, int index1, int index2);
 * -----------------------
 * @array: The array to exchange elements in
 * @index1: The index of the first element to exchange
 * @index2: The index of the second element to exchange
 * -----------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */
void exchange(int *array, int index1, int index2)
{
	int temp;

	temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

/**
 * divide - Divides an array into two subarrays
 * Return: The index of the pivot
 * -----------------------
 * Prototype: int divide(int *array, int start, int end, size_t size);
 * -----------------------
 * @array: The array to be divided
 * @start: The index of the first element in the array
 * @end: The index of the last element in the array
 * @size: The size of the array
 * -----------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */
int divide(int *array, int start, int end, size_t size)
{
	int i, j, pivot = array[end];

	for (i = start, j = end; 1; i++, j--)
	{
		while (array[i] < pivot)
			i++;

		while (array[j] > pivot)
			j--;

		if (i >= j)
			return (i);
		exchange(array, i, j);
		print_array(array, size);
	}
}

/**
 * quicksort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * -------------------------
 * Prototype: void quicksort(int *array, int start, int end, size_t size);
 * -----------------------
 * @array: The array to be sorted
 * @start: Lowest index of split
 * @end: high index of split
 * @size: The size of the array
 * -------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */
void quicksort(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = divide(array, start, end, size);
		quicksort(array, start, pivot - 1, size);
		quicksort(array, pivot, end, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * --------------------------
 * Prototype: void quick_sort_hoare(int *array, size_t size);
 * --------------------------
 * @array: The array to be sorted
 * @size: The size of the array
 * -------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
