#include "monty.h"
int lineNum = 0;
/**
 * parseLine - parse a sinlge line from a file
 * @buffer: line of the file
 *
 * Return: token
 */
char *parseLine(char *buffer)
{
	char *script = NULL;

	script = strtok(buffer, " \n\t");
	if (script == NULL)
		return (NULL);

	return (script);
}
/**
 * parser - parse a buffer
 * @fileName: nome of the file to open
 * @top: top of the stack
 */
void parser(char *fileName, stack_t **top)
{
	size_t bufSize = 0;
	char *script = NULL;
	char *buffer = NULL;
	void (*get)(stack_t **, unsigned int);
	FILE *file = fopen(fileName, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fileName);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &bufSize, file) != -1)
	{
		script = parseLine(buffer);
		if (script == NULL || strcmp(script, "nop") == 0
		|| script[0] == '#')
		{
			lineNum++;
			continue;
		}
		lineNum++;
		get = get_function(script);
		if (get == NULL)
		{
			fclose(file);
			free_dlistint(*top);
			fprintf(stderr, "L%d: unknown instruction %s\n", lineNum, script);
			exit(EXIT_FAILURE);
		}
		get(top, lineNum);
	}
	free(buffer);
	free_dlistint(*top);
	if (fclose(file) == -1)
		exit(-1);
}
