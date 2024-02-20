#include "deck.h"

/**
 * compare_Strings - Compare two strings
 * Return: 0 if they are equal, 1 if str1 > str2, -1 if str1 < str2
 * -----------------------------
 * Prototype: int compare_Strings(char *str1, const char *str2);
 * --------------------------
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 * --------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */

int compare_Strings(char *str1, const char *str2)
{
	while (*str1 != '\0')
	{
		if (*str2 == '\0')
			return (*str1);
		if (*str2 > *str1)
			return (*str1 - *str2);
		if (*str1 > *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str2 != '\0')
		return (*str2);
	return (0);
}

/**
 * swap_Nodes - Swap two nodes in a deck
 * Return: Nothing
 * -------------------------
 * Prototype: void swap_Nodes(deck_node_t **node, deck_node_t **deck);
 * -------------------------
 * @node: The node to swap
 * @deck: The deck to swap the node in
 * -------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
*/
void swap_Nodes(deck_node_t **node, deck_node_t **deck)
{
	deck_node_t *temp = *node, *temp2, *temp3;

	if (!(*node)->prev)
		*deck = (*node)->next;

	temp = temp3 = *node;
	temp2 = temp->next;

	temp->next = temp2->next;
	temp3 = temp->prev;
	temp->prev = temp2;
	temp2->next = temp;
	temp2->prev = temp3;

	if (temp2->prev)
		temp2->prev->next = temp2;

	if (temp->next)
		temp->next->prev = temp;

	*node = temp2;
}

/**
 * get_Card_Value - Get the value of a card
 * Return: The value of the card
 * --------------------------
 * Prototype: int get_Card_Value(deck_node_t *cardNode);
 * --------------------------
 * @cardNode: The node of the card
 * --------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */
int get_Card_Value(deck_node_t *cardNode)
{
	char *cardNumbers[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
					 "Jack", "Queen", "King"};
	int value, i;
	const char *cardNum;

	cardNum = cardNode->card->value;
	for (i = 0; i < 13; i++)
		if (!compare_Strings(cardNumbers[i], cardNum))
		{
			i++;
			break;
		}

	value = i + (cardNode->card->kind) * 13;

	return (value);
}

/**
 * sort_deck - Sort the deck of cards
 * Return: Nothing
 * -------------------------
 * Prototype: void sort_deck(deck_node_t **deck);
 * -------------------------
 * @deck: The pointer to the head of the deck
 * -------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *head, *tailback, *aux;

	if (!deck || !(*deck) || (!((*deck)->prev) && !((*deck)->next)))
		return;

	head = *deck;
	while (head && head->next)
	{
		if (get_Card_Value(head) > get_Card_Value(head->next))
		{
			aux = head;

			swap_Nodes(&aux, deck);
			head = aux;
			tailback = aux;

			while (tailback && tailback->prev)
			{
				if (get_Card_Value(tailback) < get_Card_Value(tailback->prev))
				{
					aux = tailback->prev;

					swap_Nodes(&(aux), deck);

					tailback = aux->next;
				}

				tailback = tailback->prev;
			}
		}
		head = head->next;
	}
}
