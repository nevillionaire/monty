#include "monty.h"
/**
 * get_function - get the correct function based on script.
 * @script: script passed by getting every line of a file
 * and parse.
 *
 * Return: the correct function
 */
void (*get_function(char *script))(stack_t **top, unsigned int arg)
{
	int i = 0;

	instruction_t obtain[] = {
		{"push", push},
		{"pint", pint},
		{"pall", pall},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{NULL, NULL}
	};

	while (obtain[i].opcode != NULL)
	{
		if (strcmp(script, obtain[i].opcode) == 0)
			break;
		i++;
	}

	return (obtain[i].f);
}
