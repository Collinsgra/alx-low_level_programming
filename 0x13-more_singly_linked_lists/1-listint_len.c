#include "lists.h"

/*
 * listint_len - number of elements in listint_t list.
 * @h: points to the head file
 *
 * Return: number of the elements
 */
size_t listint_len(const listint_t *h)
{
	size_t counter = 0;


	while (h != NULL)
	{
		h = h->next;
		counter++;
	}

	return(counter);
}
