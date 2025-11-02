#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list.
 * @list: Pointer to the pointer to the head of the list.
 * @node_a: The first node (will become the second node).
 * @node_b: The second node (will become the first node).
 *
 * Description: Swaps node_a and node_b, where node_a is
 * assumed to be before node_b.
 */
void swap_nodes(listint_t **list, listint_t *node_a, listint_t *node_b)
{
	listint_t *temp_a = node_a;
	listint_t *iter_b = node_b;

	/* Re-link 'temp_a's next to 'iter_b's next */
	temp_a->next = iter_b->next;
	if (iter_b->next != NULL)
		iter_b->next->prev = temp_a;

	/* Re-link 'iter_b's prev to 'temp_a's prev */
	iter_b->prev = temp_a->prev;
	if (temp_a->prev != NULL)
		temp_a->prev->next = iter_b;
	else
		/* 'iter_b' is now the new head of the list */
		*list = iter_b;

	/* Link 'iter_b' and 'temp_a' together */
	iter_b->next = temp_a;
	temp_a->prev = iter_b;
}

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

	/* 1. Check for edge cases */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* 2. Start from the second node (first node is sorted) */
	current = (*list)->next;

	while (current != NULL)
	{
		/* 'iter' is the node we are currently inserting */
		iter = current;
		/* Advance 'current' before 'iter' is moved */
		current = current->next;
		/* 'temp' is the node in the sorted list to compare against */
		temp = iter->prev;

		/* 3. Inner loop: move 'iter' backward into its correct position */
		while (temp != NULL && temp->n > iter->n)
		{
			/*
			 * 'temp' is the node in the sorted list.
			 * 'iter' is the node we are inserting.
			 * We swap 'temp' and 'iter'
			 */
			swap_nodes(list, temp, iter);

			/* 7. Print the list after the swap */
			print_list(*list);

			/* 8. Move 'temp' backward for the next comparison */
			temp = iter->prev;
		}
	}
}

