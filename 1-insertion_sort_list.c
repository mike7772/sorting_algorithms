#include "sort.h"

/**
  * insertion_sort_list - Sorts an doubly linked list
  * of integers in ascending order using
  * the Insertion sort algorithm.
  * @list: The doubly linked list to sort
  *
  * Return: Nothing!
  */
void insertion_sort_list(listint_t **list)
{
	bool flag = false;
	listint_t *tmp = NULL, *aux = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	tmp = *list;
	while (tmp->next)
	{
		if (tmp->n > tmp->next->n)
		{
			tmp->next->prev = tmp->prev;
			if (tmp->next->prev)
				tmp->prev->next = tmp->next;
			else
				*list = tmp->next;

			tmp->prev = tmp->next;
			tmp->next = tmp->next->next;
			tmp->prev->next = tmp;
			if (tmp->next)
				tmp->next->prev = tmp;

			tmp = tmp->prev;
			print_list(*list);

			if (tmp->prev && tmp->prev->n > tmp->n)
			{
				if (!flag)
					aux = tmp->next;
				flag = true;
				tmp = tmp->prev;
				continue;
			}
		}
		if (!flag)
			tmp = tmp->next;
		else
			tmp = aux, flag = false;
	}
}
