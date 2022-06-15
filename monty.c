#include "monty.h"
/**
 * main - read a file and interpret its scripts
 * @argc: number of arguments passed to the program
 * @argv: 2d array of strings containing every argument
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int fd = 0;
	stack_t *head = NULL;

	if (argc != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	parser(argv[1], &head);

	close(fd);
	return (EXIT_SUCCESS);
}
