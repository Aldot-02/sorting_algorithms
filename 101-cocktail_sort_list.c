#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - swap a node with its previous node
 * @node: node to swap
 * @list: list of nodes
 *
 * Return: pointer to the node that was swapped in
 */
listint_t *swap_nodes(listint_t *node, listint_t **list)
{
	listint_t *prev_node = node->prev, *current_node = node;

	prev_node->next = current_node->next;
	if (current_node->next)
		current_node->next->prev = prev_node;
	current_node->next = prev_node;
	current_node->prev = prev_node->prev;
	prev_node->prev = current_node;
	if (current_node->prev)
		current_node->prev->next = current_node;
	else
		*list = current_node;
	return (current_node);
}

/**
 * cocktail_sort_list - sort a doubly linked list using the
 * cocktail sort algorithm
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	node = *list;
	while (swapped == 1)
	{
		swapped = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_nodes(node->next, list);
				swapped = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_nodes(node, list);
				swapped = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
