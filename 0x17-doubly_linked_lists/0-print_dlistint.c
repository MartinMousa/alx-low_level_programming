#include "lists.h"

/**
 * print_dlistint - Prints all the elements of a dlistint_t list.
 * @h: The dlistint_t to be printed.
 *
 * Return: The number of nodes in the list.
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h) /* check if node is NULL */
	{
		printf("%d\n", h->n); /* print current node */
		count++; /* update counter */
		h = h->next; /* move to next node */
	}

	return (count);
}
