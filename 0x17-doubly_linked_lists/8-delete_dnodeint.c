#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node at index of a
 *                            dlistint_t linked list.
 * @head: A double pointer to a doubly linked list.
 * @index: The index to delete the new node.
 *
 * Return: 1 if success, else -1.
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *previous, *current;
	unsigned int count = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0) /* assign new head */
	{
		current = (*head)->next; /* temporarily store next node */
		if (current != NULL)
			current->prev = NULL;
		free(*head);
		*head = current; /* update head */
		return (1);
	}

	current = *head; /* temporarily store current node */
	previous = NULL; /* initialize previous */

	while (current != NULL && count < index) /* find idx */
	{
		previous = current; /* store current node as previous node */
		current = current->next; /* move to next node */
		count++; /* count nodes */
	}

	if (current == NULL) /* idx doesn't exist */
	{
		return (-1);
	}

	previous->next = current->next; /* update *next of new node */
	if (current->next != NULL)
		current->next->prev = previous; /* update *prev of new node */
	free(current); /* delete node */

	return (1);
}
