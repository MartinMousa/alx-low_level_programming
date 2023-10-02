#include "main.h"

/**
 * create file - Creates file.
 * @flnm: point name of file for creatation.
 * @txt_cot: point le str write file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *flnm, char *txt_cot)
{
	int df, x, bl = 0;

	if (flnm == NULL)
		return (-1);

	if (txt_cot != NULL)
	{
		for (bl = 0; txt_cot[bl];)
			bl++;
	}

	df = open(flnm, O_CREAT | O_RDWR | O_TRUNC, 0600);
	x = write(df, txt_cot, bl);

	if (df == -1 || x == -1)
		return (-1);

	close(df);

	return (1);
}
