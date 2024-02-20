#include <stdlib.h>
#include "sort.h"

/**
 * distribute_digits - auxiliary function of radix sort
 * -------------------------
 * prototype: void distribute_digits(int *arr,
 * int **buffer, int size, int digit);
 * -------------------------
 * @array: array of data to be sorted
 * @buffer: array of arrays to be sorted
 * @size: size of the array
 * @digit: digit to be sorted
 * -------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */
void distribute_digits(int *array, int **buffer, int size, int digit)
{
	int i, j, num, digit_count = 10;
	int count_array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int count_array2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < size; i++)
	{
		num = array[i];
		for (j = 0; j < digit; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		buffer[num][count_array[num]] = array[i];
		count_array[num] += 1;
	}

	for (i = 0, j = 0; i < digit_count; i++)
	{
		while (count_array[i] > 0)
		{
			array[j] = buffer[i][count_array2[i]];
			count_array2[i] += 1, count_array[i] -= 1;
			j++;
		}
	}

	print_array(array, size);
}

/**
 * count_digits - auxiliary function of radix sort
 * -------------------------
 * prototype: void count_digits(int *arr, int size, int digit);
 * -------------------------
 * @array: array of data to be sorted
 * @size: size of data
 * @digit: Current digit to distribute
 * -------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */
void count_digits(int *array, int size, int digit)
{
	int count_array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i, j, num, digit_count = 10, **buffer;

	for (i = 0; i < size; i++)
	{
		num = array[i];
		for (j = 0; j < digit; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		count_array[num] += 1;
	}

	if (count_array[0] == size)
		return;

	buffer = malloc(sizeof(int *) * 10);
	if (!buffer)
		return;

	for (i = 0; i < digit_count; i++)
		if (count_array[i] != 0)
			buffer[i] = malloc(sizeof(int) * count_array[i]);


	distribute_digits(array, buffer, size, digit);

	count_digits(array, size, digit + 1);

	for (i = 0; i < digit_count; i++)
		if (count_array[i] > 0)
			free(buffer[i]);
	free(buffer);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the radix sort algorithm
 * -------------------------
 * Prototype: void radix_sort(int *array, size_t size);
 * -----------------------
 * @array: The array to be sorted
 * @size: The size of the array
 * -------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */

void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	count_digits(array, size, 1);
}
