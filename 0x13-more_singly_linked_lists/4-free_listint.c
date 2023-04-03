#include "lists.h"
#include <stdlib.h>

/*
 * free_listint - functions that frees a listint_t list.
 *
 * @head: the head
 *
 * Return: NULL if failed
 */
void free_listint(listint_t *head)
{
	listint_t *next;


	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
