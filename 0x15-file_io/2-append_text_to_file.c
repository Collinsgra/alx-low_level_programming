#include "main.h"

/**
 * appends_txt_to_file - appends txt to end of file
 * @filename - name file
 * @text_content - Null terminated to be added at the end of the file
 * Return: 1 if success else -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fo, n_chars, kw;

	if (!filename)
		return (-1);

	fo = open(filename, O_WRONLY | O_APPEND);

	if (fo == -1)
		return (-1);
	if (text_content)
	{
		for (n_chars = 0; text_content[n_chars]; n_chars++);

		kw = write(fo, text_content, n_chars);

		if ( kw == -1)
			return (-1);
	}


	close(fo);

	return (1);
}
