#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all the data (n) of a dlistint_t
 *               linked list.
 * @head: A linked list.
 *
 * Return: 0 if list empty, else sum of data.
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n; /* sum data */
		head = head->next; /* move to next node */
	}

	return (sum);
}
