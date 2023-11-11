#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: A double pointer to a doubly linked list.
 * @idx: The index to insert the new node.
 * @n: The data to insert at idx.
 *
 * Return: Null if list is empty, else the address of the new node.
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current;
	unsigned int count = 0;

	if (h == NULL) /* check pointer */
		return (NULL);

	new_node = malloc(sizeof(dlistint_t)); /* allocate memory */
	if (new_node == NULL) /* malloc check */
		return (NULL);

	new_node->n = n; /* update node member */

	if (idx == 0) /* assign new_node as head */
	{
		new_node->next = *h;
		if (*h != NULL)
			(*h)->prev = new_node;
		*h = new_node; /* update head of list to new_node */
		return (new_node);
	}

	current = *h; /* temporarily store current node */
	while (current != NULL && count < idx - 1) /* find valid idx */
	{
		current = current->next; /* move to next node */
		count++; /* count nodes */
	}

	if (current == NULL) /* if idx is invalid and current is last node */
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = current->next; /* update *next of new node */
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
	current->next = new_node; /* update *next of current node */
	new_node->prev = current; /* update *prev of new node */
	return (new_node);
}
