#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 *
 * @list: A pointer to a pointer to the head of the list.
 *
 * Description: Prints the list after each node swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *iter, *temp;

	/* 1. Check for edge cases: NULL list, empty list, or single-node list */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* 2. 'current' starts at the second node (first node is the sorted sublist) */
	current = (*list)->next;

	while (current != NULL)
	{
		/* 'iter' is the node we are currently inserting into the sorted part */
		iter = current;
		/* 'current' must advance *before* 'iter' is moved */
		current = current->next;

		/* 'temp' is the node in the sorted list we compare against */
		temp = iter->prev;

		/* 3. Inner loop: move 'iter' backward into its correct position */
		while (temp != NULL && temp->n > iter->n)
		{
			/*
			 * Swap 'iter' and 'temp' by re-linking pointers.
			 * We are moving 'iter' to be before 'temp'.
			 */

			/* 4. Link 'temp's next to 'iter's next */
			temp->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = temp;

			/* 5. Link 'iter's prev to 'temp's prev */
			iter->prev = temp->prev;
			if (temp->prev != NULL)
				temp->prev->next = iter;
			else
				/* 'iter' is now the new head of the list */
				*list = iter;

			/* 6. Link 'iter' and 'temp' together */
			iter->next = temp;
			temp->prev = iter;

			/* 7. Print the list after the swap */
			print_list(*list);

			/* 8. Move 'temp' backward for the next comparison */
			temp = iter->prev;
		}
	}
}
