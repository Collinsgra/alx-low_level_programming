#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node-index
 * @head: lists header
 * @index: new node index
 * Return: 1 on succeess, -1 on fail
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *div1, *div2;
	unsigned int c;

	div1 = *head;

	if (div1 != NULL)
		while (div1->prev != NULL)
			div1 = div1->prev;

	c = 0;

	while (div1 != NULL)
	{
		if (c == index)
		{
			if (c == 0)
			{
				*head = div1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				div2->next = div1->next;

				if (div1->next != NULL)
					div1->next->prev = div2;
			}

			free(div1);
			return (1);
		}
		div2 = div1;
		div1 = div1->next;
		c++;
	}

	return (-1);
}
