#include "sort.h"

/**
  * cocktail_sort_list - Sorts a doubly linked list
  * of integers in ascending order using the
  * Cocktail Shaker sort algorithm.
  * @list: The doubly linked list to apply the cocktail sort
  *
  * Return: Nothing!
  */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr = NULL, *left_limit = NULL, *right_limit = NULL;
	int cycle_type = INCREMENT;

	if (!list || !(*list) || !(*list)->next)
		return;

	curr = *list;
	left_limit = curr;
	right_limit = get_dlistint_lelem(*list);

	while (left_limit != right_limit)
	{
		if (curr->n == curr->next->n)
			break;
		else if (curr->n > curr->next->n && cycle_type == INCREMENT)
			swap_nodes(list, curr), print_list(*list);
		else if (curr->next->n < curr->n && cycle_type == DECREMENT)
			swap_nodes(list, curr), curr = curr->prev, print_list(*list);
		else if (cycle_type == INCREMENT)
			curr = curr->next;
		else if (cycle_type == DECREMENT)
			curr = curr->prev;

		if (cycle_type == DECREMENT && curr->next == left_limit)
		{
			cycle_type = INCREMENT;
			curr = curr->next;
		}

		if (cycle_type == INCREMENT && curr->prev == right_limit)
		{
			right_limit = right_limit->prev;
			cycle_type = DECREMENT;
			curr = curr->prev;
		}
	}
}

/**
  * swap_nodes - Swap two nodes of a doubly linked list
  * @list: The double linked lists that contains the nodes
  * @node: The node to swap with the next node
  *
  * Return: Nothing!
  */
void swap_nodes(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;

	if (node->next->prev)
		node->prev->next = node->next;
	else
		*list = node->next;

	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;

	if (node->next)
		node->next->prev = node;
}

/**
  * get_dlistint_lelem - Counts the number of elements in a doubly linked list
  * @h: The double linked list to count
  *
  * Return: Number of elements in the doubly linked list
  */
listint_t *get_dlistint_lelem(listint_t *h)
{
	listint_t *curr = h;

	while (curr->next != NULL)
		curr = curr->next;

	return (curr);
}
