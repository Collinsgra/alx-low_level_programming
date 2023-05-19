#include "lists.h"

/**
 * add_dnodeint - adds new node
 *
 * @head: lists header
 * @n: element-value
 * Return: new address for thr element
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *node_new, *h;

	node_new = malloc(sizeof(dlistint_t));
	if (node_new == NULL)
		return (NULL);

	node_new->n = n;
	node_new->prev = NULL;
	h = *head;

	if (h != NULL)
	{
		while (h->prev != NULL)
			h = h->prev;
	}

	node_new->next = h;

	if (h != NULL)
		h->prev = node_new;

	*head = node_new;

	return (node_new);
}
