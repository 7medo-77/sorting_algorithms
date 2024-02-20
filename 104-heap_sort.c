#include "sort.h"

/**
 * swap_values - Swaps two values in an array.
 * Return: Nothing
 * --------------------------
 * Prototype: void swap_values(int *array, int index1,
 * int index2, const int print_size);
 * -----------------------
 * @array: The array to swap values in.
 * @index1: The index of the first value to swap.
 * @index2: The index of the second value to swap.
 * @print_size: The constant size for printing arrays.
 * --------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */
void swap_values(int *array, int index1, int index2, const int print_size)
{
	int temp;
	(void)print_size;

	if (index1 != index2)
	{
		temp = array[index1];
		array[index1] = array[index2];
		array[index2] = temp;
		print_array(array, (size_t)print_size);
	}
}

/**
 * find_largest_element - Finds the largest element in an array.
 * ----------------------
 * Prototype: void find_largest_element(int *array, size_t size, int index);
 * ---------------------
 * @array: The array to search.
 * @size: The size of the array.
 * @index: The index of the largest element.
 * @print_size: The constant size for printing arrays.
 * ----------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */
void find_largest_element(int *array, size_t size,
int index, const int print_size)
{
	int largest = index;
	int left = (2 * index) + 1;
	int right = (2 * index) + 2;

	if (left < (int)size && array[left] > array[largest])
		largest = left;

	if (right < (int)size && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		swap_values(array, index, largest, print_size);
		find_largest_element(array, size, largest, print_size);
	}
}

/**
 * heap_sort - Sorts an array using heap sort.
 * ----------------------
 * Prototype: void heap_sort(int *array, size_t size);
 * ----------------------
 * @array: The array to sort.
 * @size: The size of the array.
 * --------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */

void heap_sort(int *array, size_t size)
{
	const int print_size = (const int)size;
	int i;

	if (size < 2 || !array)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		find_largest_element(array, size, i, print_size);

	for (i = size - 1; i >= 0; i--)
	{
		swap_values(array, 0, i, print_size);
		find_largest_element(array, i, 0, print_size);
	}
}
