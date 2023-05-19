#include "lists.h"

/**
 * get_dnodeint_at_index - returns the node
 *
 * @head: lists header
 * @index: index of the node
 * Return: if the node does not exist, return NULL
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int c;

	if (head == NULL)
		return (NULL);

	while (head->prev != NULL)
		head = head->prev;

	c = 0;

	while (head != NULL)
	{
		if (c == index)
			break;
		head = head->next;
		c++;
	}
	return (head);
}
