#include "monty.h"
/**
 * pchar - prints the ascii value of the top
 * @top: top of the stack
 * @n: the value on the top
 */
void pchar(stack_t **top, __attribute__((unused))unsigned int n)
{
	char character = 'a';

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNum);
		exit(EXIT_FAILURE);
	}
	if (isprint((*top)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNum);
		exit(EXIT_FAILURE);
	}
	character = (*top)->n;

	printf("%c\n", character);
}
/**
 * pstr - prints the ascii value of the entire stack
 * @top: top of the stack
 * @n: the value on the top
 */
void pstr(stack_t **top, __attribute__((unused))unsigned int n)
{
	stack_t *temp = NULL;

	temp = (*top);

	while (temp)
	{
		if (temp->n == 0)
			break;
		if (isprint(temp->n) == 0)
			break;
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
/**
 * rolt - The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one
 * @top: top of the stack
 * @n: the value on the top
 */
void rotl(stack_t **top, __attribute__((unused))unsigned int n)
{
	stack_t *temp = NULL;
	stack_t *firstTemp = NULL;

	if (!*top)
		return;

	temp = (*top);
	firstTemp = (*top);

	while (temp->next)
		temp = temp->next;

	*top = firstTemp->next;
	firstTemp->next->prev = NULL;

	temp->next = firstTemp;
	firstTemp->next = NULL;
}
