#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int dc);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *bfr;

	bfr = malloc(sizeof(char) * 1024);

	if (bfr == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (bfr);
}

/**
 * close_file - Closes file descriptors.
 * @dc: The file descriptor to be closed.
 */
void close_file(int dc)
{
	int z;

	z = close(dc);

	if (z == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close dc %d\n", dc);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int fmor, xo, i, w;
	char *bfr;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_fmor file_xo\n");
		exit(97);
	}

	bfr = create_buffer(argv[2]);
	fmor = open(argv[1], O_RDONLY);
	i = read(fmor, bfr, 1024);
	xo = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (fmor == -1 || i == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(bfr);
			exit(98);
		}

		w = write(xo, bfr, i);
		if (xo == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write xo %s\n", argv[2]);
			free(bfr);
			exit(99);
		}

		i = read(fmor, bfr, 1024);
		xo = open(argv[2], O_WRONLY | O_APPEND);

	} while (i > 0);

	free(bfr);
	close_file(fmor);
	close_file(xo);

	return (0);
}
