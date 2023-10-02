#include "main.h"

/**
 * append_text_to_file - Appends text in the end of file.
 * @flname: pointes to the name of file.
 * @txt_conte: string is add in the end of the file.
 * 
 * Return: If the function fails or flname is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *flname, char *txt_conte)
{
	int m, x, ln = 0;

	if (flname == NULL)
		return (-1);

	if (txt_conte != NULL)
	{
		for (ln = 0; txt_conte[ln];)
			ln++;
	}

	m = open(flname, O_WRONLY | O_APPEND);
	x = write(m, txt_conte, ln);

	if (m == -1 || x == -1)
		return (-1);

	close(m);

	return (1);
}
