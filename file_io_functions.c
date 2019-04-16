#include "shell.h"

/**
 * append_history - adds getline input to a history file
 * @info: info
 *Return: nothin
 */

void append_history(__attribute__((unused))info_t *info)
{
	char buffer[1024];
	int line;

//	print_info(info);
// TODO	dir = _getenv(info, "HOME=");
	_strcpy(buffer, "/home/vagrant/");
	_strcat(buffer, ".simple_shell_history");
	line = read_textfile(buffer, 1024) % 4096;
	create_file(buffer, "Test history\n");
	printf("lines = %d\n", line);
}

/**
 * create_file - creates a file, or appends to an existing file
 * @filename: the name of the file to create
 * @text_content: a NULL terminated string to wtire to the file
 * Return: (1) On success, the number of letters that could be read and printed
 *        (-1) On failure (file can not be created, file can not be written,
 *             write “fails”, etc…)
 *        (-1) if filename is NULL
 */

int create_file(const char *filename, char *text_content)
{
	ssize_t fd, wrlen;
	int i = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0600);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[i])
			i++;
		wrlen = write(fd, text_content, i);
	}
	close(fd);
	if (wrlen == -1)
		return (-1);

	return (1);
}

/**
 * read_textfile - reads a text file and returns the number of lines in the file
 * @filename: the text file to be read
 * @letters: the number of letters to read
 * Return: On success, the number of letters that could be read and printed
 *         (0) if write fails or does not write the expected amount of bytes
 *         (0) if filename is NULL, or if file can not be opened or read
 */

int read_textfile(const char *filename, size_t letters)
{
	int i, linecount = 0;
	ssize_t fd, rdlen;
	char *buf;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (!buf)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buf);
		return (0);
	}
	rdlen = read(fd, buf, letters);
	if (rdlen == -1)
	{
		free(buf);
		return (0);
	}

	close(fd);
	for (i = 0; buf[i]; i++)
		if (buf[i] == '\n')
			linecount++;
	free(buf);
	return (linecount);
}

/**
 * append_history_list - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int append_history_list(info_t *info, char *buf)
{
	list_t *node = NULL;

	add_node_end(&node, buf, 0);
	info->history = node;
	return (0);
}
