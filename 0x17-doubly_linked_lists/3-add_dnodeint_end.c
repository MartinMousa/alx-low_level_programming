#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list.
 * @head: A pointer to the head node of the dlistint_t.
 * @n: The data to be input in the node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *tmp; /* declare a new nodes */

	new_node = malloc(sizeof(dlistint_t)); /* allocate memory */
	if (new_node == NULL) /* malloc check */
		return (NULL);

	new_node->n = n; /* set node value */
	new_node->next = NULL;

	if (*head == NULL) /* if no list nodes, set new_node to beginning */
	{
		*head = new_node;
	}
	else /* iterate till last node */
	{
		tmp = *head; /* temporarily store head pointer */

		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new_node; /* update *next of last node */
		new_node->prev = tmp; /* update *prev to the previous last node */
	}

	return (new_node);
}
