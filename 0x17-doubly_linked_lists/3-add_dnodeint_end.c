#include "lists.h"

/**
 * add_dnodeint_end - adds new-node
 *
 * @head: list's header
 * @n: elements value
 * Return: the address of new elemet
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *h, *node_new;


	node_new = malloc(sizeof(dlistint_t));
	if (node_new == NULL)
		return (NULL);

	node_new->n = n;
	node_new->next = NULL;

	h = *head;

	if (h != NULL)
	{
		while (h->next != NULL)
			h = h->next;
		h->next = node_new;
	}
	else
	{
		*head = node_new;
	}

	node_new->prev = h;

	return (node_new);
}
