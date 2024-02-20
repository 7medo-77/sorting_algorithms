#include "sort.h"
#include <stdio.h>

/**
 * print_Range - Prints a range of elements in an array
 * Return: Nothing
 * -------------------------
 * Prototype: void print_Range(int *array, int start, int end);
 * --------------------------
 * @array: The array to print
 * @start: The first element to print
 * @end: The last element to print
 * --------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */
void print_Range(int *array, int start, int end)
{
	int i;

	for (i = start; i <= end; i++)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * swap_Elements - Swaps two elements in an array
 * Return: Nothing
 * --------------------------
 * Prototype: void swap_Elements(int *array, int index1, int index2, int dir);
 * --------------------------
 * @array: The array to swap elements in
 * @index1: The index of the first element to swap
 * @index2: The index of the second element to swap
 * @dir: The direction of the swap
 * --------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */
void swap_Elements(int *array, int index1, int index2, int dir)
{
	int temp;

	if (dir == (array[index1] > array[index2]))
	{
		temp = array[index1];
		array[index1] = array[index2];
		array[index2] = temp;
	}
}

/**
 * merge_Bitonic - Merges two sorted arrays into a single sorted array
 * Return: Nothing
 * --------------------------
 * Prototype: void merge_Bitonic(int *array, int low, int size, int dir);
 * --------------------------
 * @array: The array to merge
 * @low: The lowest index of the array
 * @size: The size of the array
 * @dir: The direction of the merge
 * @arraySize: The size of the array
 * -------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
*/
void merge_Bitonic(int *array, int low, int size, int dir, const int arraySize)
{
	int k = size, i = low;

	if (size > 1)
	{
		k = size / 2;

		for (i = low; i < low + k; i++)
			swap_Elements(array, i, i + k, dir);

		merge_Bitonic(array, low, k, dir, arraySize);
		merge_Bitonic(array, low + k, k, dir, arraySize);
	}
}

/**
 * segmentate_Sort - Sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * --------------------------
 * Prototype: void segmentate_Sort(int *array, int low, int size, int dir);
 * -------------------------
 * @array: The array to be sorted
 * @low: The lowest index of the array
 * @size: The size of the array
 * @dir: The direction of the merge
 * @arraySize: The size of the array
 * -------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */
void segmentate_Sort(int *array, int low, int size,
int dir, const int arraySize)
{
	int k = size;

	if (size > 1)
	{
		if (dir == 1)
			printf("Merging [%d/%d] (UP):\n", size, arraySize);
		if (dir == 0)
			printf("Merging [%d/%d] (DOWN):\n", size, arraySize);
		print_Range(array, low, low + k - 1);

		k = size / 2;
		segmentate_Sort(array, low, k, 1, arraySize);
		segmentate_Sort(array, low + k, k, 0, arraySize);

		merge_Bitonic(array, low, size, dir, arraySize);
		if (dir == 1)
		{
			printf("Result [%d/%d] (UP):\n", size, arraySize);
			print_Range(array, low, low + 2 * k - 1);
		}
		if (dir == 0)
		{
			printf("Result [%d/%d] (DOWN):\n", size, arraySize);
			print_Range(array, low, low + 2 * k - 1);
		}
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * --------------------------
 * Prototype: void bitonic_sort(int *array, size_t size);
 * --------------------------
 * @array: The array to be sorted
 * @size: The size of the array
 * --------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */

void bitonic_sort(int *array, size_t size)
{
	int up = 1;
	const int arraySize = (int)size;

	if (size < 2 || !array)
		return;

	segmentate_Sort(array, 0, (int)size, up, arraySize);
}
