#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in a linked dlistint_t list.
 * @h: The dlistint_t to be printed.
 *
 * Return: The number of nodes in the list.
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h) /* check if node is NULL */
	{
		count++; /* update counter */
		h = h->next; /* move to next node */
	}

	return (count);
}
