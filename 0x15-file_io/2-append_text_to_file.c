#include "main.h"

/**
 * append_text_to_file - Appends text in the end of file.
 * @filename: pointes to the name of file.
 * @text_content: string is add in the end of the file.
 * 
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int m, x, ln = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (ln = 0; text_content[ln];)
			ln++;
	}

	m = open(filename, O_WRONLY | O_APPEND);
	x = write(m, text_content, ln);

	if (m == -1 || x == -1)
		return (-1);

	close(m);

	return (1);
}
