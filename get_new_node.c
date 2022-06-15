#include "monty.h"
/**
 * getNewNode - create a new node using malloc
 * @n: value of the new node
 *
 * Return: the new node
 */
stack_t *getNewNode(int n)
{
	stack_t *newNode = NULL;

	newNode = (stack_t *)malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = n;
	newNode->next = NULL;
	newNode->prev = NULL;

	return (newNode);
}
