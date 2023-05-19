#include "lists.h"

/**
 * dlistint_len - returns no of elements in d-linked lists
 * @h: lists header
 * Return: no of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	int add_up = 0;


	if (h == NULL)
		return (add_up);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		add_up++;
		h = h->next;
	}

	return (add_up);
}
