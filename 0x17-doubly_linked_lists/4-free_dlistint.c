#include "lists.h"

/**
 * free_dlistint - Frees a dlistint_t list.
 * @head:A doubly linked list.
 *
 * Return: Void.
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	while (head != NULL) /* traverse nodes */
	{
		tmp = head; /* temporarily store current head */
		head = head->next; /* move head to next node */
		free(tmp); /* free tmp */
	}
}
