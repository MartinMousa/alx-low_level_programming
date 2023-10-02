#include "main.h"

/**
 * createfile - Createsfile.
 * @flnm: point name of file for creatation.
 * @txt__cont: point le str write file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *flnm, char *txt__cont)
{
	int fwd, wxw, berlen = 0;

	if (flnm == NULL)
		return (-1);

	if (txt__cont != NULL)
	{
		for (berlen = 0; txt__cont[berlen];)
			berlen++;
	}

	fwd = open(flnm, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wxw = write(fwd, txt__cont, berlen);

	if (fwd == -1 || wxw == -1)
		return (-1);

	close(fwd);

	return (1);
}
