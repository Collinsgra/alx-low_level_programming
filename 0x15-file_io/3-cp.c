#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void stats_checker(int stat, int fd, char *filename, char mode);
/**
 * main - copies the stuff to another file
 * @argc: argst counter
 * @argv: args passed through thr prog
 *
 * Return: 1 on success,
 */
int main(int argc, char *argv[])
{
	int src, distribut, got_read = 1024, wrote, src_srclose, distribut_fung;
	unsigned int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s", "Usage: cp file_from file_to\n");
		exit(97);
	}
	src = open(argv[1], O_RDONLY);
	stats_checker(src, -1, argv[1], 'O');
	distribut = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	stats_checker(distribut, -1, argv[2], 'W');
	while (got_read == 1024)
	{
		got_read = read(src, buffer, sizeof(buffer));
		if (got_read == -1)
			stats_checker(-1, -1, argv[1], 'O');
		wrote = write(distribut, buffer, got_read);
		if (wrote == -1)
			stats_checker(-1, -1, argv[2], 'W');
	}
	src_srclose = close(src);
	stats_checker(src_srclose, src, NULL, 'C');
	distribut_fung = close(distribut);
	stats_checker(distribut_fung, distribut, NULL, 'C');
	return (0);
}

/**
 * stats_checker - checks a file if open | closed
 * @stat: descrip of open fle
 * @filename: namefile
 * @mode: open or close
 * @fd: file purpose
 *
 * Return: void
 */
void stats_checker(int stat, int fd, char *filename, char mode)
{
	if (mode == 'C' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
	else if (mode == 'O' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	else if (mode == 'W' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
}
