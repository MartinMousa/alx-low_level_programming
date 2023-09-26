#include "lists.h"

/**
 *  return the number of elements in a linked lists
 * 
 *
 * Return: number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t num = 0;

	for (; h != NULL; h = h->next)
		num++;

	return (num);
}
