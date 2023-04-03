#include <stdio.h>
#include "lists.h"

/**
 * print_list - This prints all the elements of listint_t.
 * @h: Pointer to the head of the list_t.
 *
 *
 * Return: The number of nodes in the list_t
 *
 */
size_t print_listint(const listint_t *h)
{
	size_t number_nodes;
	number_nodes = 0;



	while (h)
	{
		number_nodes++;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (number_nodes);
}
