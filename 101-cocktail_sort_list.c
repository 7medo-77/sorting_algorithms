#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_elements - Swaps two elements in a doubly linked list
 * Return: Nothing
 * -------------------------
 * Prototype: void swap_elements(listint_t **head,
 * listint_t *elem1, listint_t *elem2);
 * -------------------------
 * @head: The pointer to the head of the list
 * @elem1: The first element to swap
 * @elem2: The second element to swap
 * -------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */
void swap_elements(listint_t **head, listint_t *elem1, listint_t *elem2)
{
	if (elem1->prev)
		elem1->prev->next = elem2;
	else
		*head = elem2;

	if (elem2->next)
		elem2->next->prev = elem1;

	elem1->next = elem2->next;
	elem2->prev = elem1->prev;
	elem1->prev = elem2;
	elem2->next = elem1;

	if (elem1->next)
		elem1->next->prev = elem1;
}

/**
 * bubble_up - Bubbles up the element in the list
 * Return: Nothing
 * -------------------------
 * Prototype: void bubble_up(listint_t **list,
 * listint_t **left_bound, listint_t *right_bound, int *swapped);
 * -------------------------
 * @list: The pointer to the head of the list
 * @left_bound: The pointer to the left bound of the list
 * @right_bound: The pointer to the right bound of the list
 * @swapped: The pointer to the swapped variable
 * -------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */

void bubble_up(listint_t **list, listint_t **left_bound,
listint_t *right_bound, int *swapped)
{
	*swapped = 0;
	*left_bound = (*list);
	while ((*left_bound)->next != right_bound)
	{
		if ((*left_bound)->n > (*left_bound)->next->n)
		{
			swap_elements(list, *left_bound, (*left_bound)->next);
			print_list(*list);
			*swapped = 1;
		}
		else
		{
			*left_bound = (*left_bound)->next;
		}
	}
}

/**
 * bubble_down - Bubbles down the element in the list
 * Return: Nothing
 * -------------------------
 * Prototype: void bubble_down(listint_t **list,
 * listint_t **left_bound, int *swapped);
 * -------------------------
 * @list: The pointer to the head of the list
 * @left_bound: The pointer to the left bound of the list
 * @swapped: The pointer to the swapped variable
 * -----------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */
void bubble_down(listint_t **list, listint_t **left_bound, int *swapped)
{
	*swapped = 0;
	while ((*left_bound)->prev != NULL)
	{
		if ((*left_bound)->n < (*left_bound)->prev->n)
		{
			swap_elements(list, (*left_bound)->prev, *left_bound);
			print_list(*list);
			*swapped = 1;
		}
		else
		{
			*left_bound = (*left_bound)->prev;
		}
	}
}

/**
 * cocktail_sort_list - Sorts a doubly linked
 * list using the cocktail sort algorithm
 * Return: Nothing
 * -------------------------
 * Prototype: void cocktail_sort_list(listint_t **list);
 * -------------------------
 * @list: The pointer to the head of the list
 * -------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *left_bound = NULL;
	listint_t *right_bound = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		bubble_up(list, &left_bound, right_bound, &swapped);
		if (!swapped)
			break;
		right_bound = left_bound;
		bubble_down(list, &left_bound, &swapped);
	}
}
