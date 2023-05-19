#include "lists.h"

/**
 * free_dlistint - frees the dlistint_tlist
 * @head: list's head
 * Return: !return
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tenpe;

	if (head != NULL)
		while (head->prev != NULL)
			head = head->prev;

	while ((tenpe = head) != NULL)
	{
		head = head->next;
		free(tenpe);
	}
}
