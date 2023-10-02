#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read the text in the file STDOUT.
 * @fnme: text file is to read
 * @lett: number of lett is to read
 * Return: stw- number of bytes read and printed
 *        zero stwhen func not work or fnme is NULL.
 */
ssize_t read_textfile(const char *fnme, size_t lett)
{
	char *bfui;
	ssize_t stf;
	ssize_t stw;
	ssize_t stt;

	stf = open(fnme, O_RDONLY);
	if (stf == -1)
		return (0);
	bfui = malloc(sizeof(char) * lett);
	stt = read(stf, bfui, lett);
	stw = write(STDOUT_FILENO, bfui, stt);

	free(bfui);
	close(stf);
	return (stw);
}
