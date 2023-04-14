#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read a text file and prints to POSIX stdout.
 * @filename: A pointer to the name file.
 * @letters: letters is the number of letters it should read and print
 *
 * Return: If the function fails or filename is NULL - 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fo, r, w;
	char *buf;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	fo = open(filename, O_RDONLY);
	r = read(o, buf, letters);
	w = write(STDOUT_FILENO, buffer, r);

	if (fo == -1 || r == -1 || w == -1 || w != r)
	{
		free(buf);
		return (0);
	}

	free(buf);
	close(fo);

	return (w);
}
