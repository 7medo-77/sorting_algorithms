#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using the insertion sort algorithm
 * --------------------------
 * Prototype: void insertion_sort_list(listint_t **list);
 * --------------------------
 * @list: The doubly linked list to be sorted
 * --------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *node_to_insert;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	/* Iterate through the list starting from the second element */
	for (
	    current_node = (*list)->next;
	    current_node != NULL;
	    current_node = current_node->next)
	{
		node_to_insert = current_node;
		/* Move the current node backwards through the sorted portion */
		while (
		    node_to_insert->prev != NULL
		    && node_to_insert->prev->n > node_to_insert->n)
		{
			/* Swap the current node with the one before it */
			node_to_insert->prev->next = node_to_insert->next;
			if (node_to_insert->next != NULL)
				node_to_insert->next->prev = node_to_insert->prev;
			node_to_insert->next = node_to_insert->prev;
			node_to_insert->prev = node_to_insert->next->prev;
			/* Update the head of the list if necessary */
			if (node_to_insert->prev != NULL)
				node_to_insert->prev->next = node_to_insert;
			else
				*list = node_to_insert;
			/* Re-link the previous node */
			node_to_insert->next->prev = node_to_insert;
			/* Print the list after each swap for visualization */
			print_list(*list);
		}
	}
}
