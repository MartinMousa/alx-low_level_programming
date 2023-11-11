#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 * @head: A Doubly linked list.
 * @index: The nth node to access.
 *
 * Return: NULL if node is empty, else the nth node.
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0;

	if (head == NULL) /* check if list is empty */
		return (0);

	while (head != NULL) /* traverse list */
	{
		if (count == index)
		{
			return (head);
		}
		else
		{
			count++; /* update counter */
			head = head->next; /* move to next node */
		}
	}

	return (NULL);
}
