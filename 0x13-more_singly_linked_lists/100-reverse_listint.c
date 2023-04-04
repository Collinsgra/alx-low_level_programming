#include "lists.h"

/**
 * reverse_listint - reverses a listint_t
 * @head: double pointer
 *Return: pointer to the first node
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *before, *next;


	if (head == NULL || *head == NULL)
		return (NULL);
	if ((*head)->next == NULL)
		return (*head);
	before = NULL;
	while (*head != NULL)
	{
		next = (*head)->next;
		(*head)->next = before;
		before = *head;
		*head = next;
	}
	*head = before;
	return (*head);
}
