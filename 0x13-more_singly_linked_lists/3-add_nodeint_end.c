#include "lists.h"

/*
 * add_nodeint_end - functions that adds new node at the end of a listint_int list.
 * @head - double pointer
 * @n - integer
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;
	listint_t *the_endline;


	if (head == NULL)
		return (NULL);
	new_node =  malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	the_endline = *head;
	while (the_endline->next != NULL)
	{
		the_endline = the_endline->next;
	}
	the_endline->next = new_node;
	return (new_node);
}
