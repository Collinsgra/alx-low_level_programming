#include "lists.h"

/**
 * sum_dlistint - returns of data
 *
 * @head: lists header
 * Return: addition of data
 */
int sum_dlistint(dlistint_t *head)
{
	int addi;

	addi = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;

		while (head != NULL)
		{
			addi += head->n;
			head = head->next;
		}
	}

	return (addi);
}
