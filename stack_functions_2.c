#include "monty.h"
/**
 * add - add bewtween top
 * @top: top of the stack
 * @n: the value on the top
 */
void add(stack_t **top, __attribute__((unused))unsigned int n)
{
	int temp = 0;

	if (!(*top) || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lineNum);
		exit(EXIT_FAILURE);
	}

	temp = (*top)->n;
	(*top)->next->n = (*top)->next->n + temp;
	pop(top, lineNum);
}
/**
 * sub - sub bewtween top
 * @top: top of the stack
 * @n: the value on the top
 */
void sub(stack_t **top, __attribute__((unused))unsigned int n)
{
	int temp = 0;

	if (!(*top) || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lineNum);
		exit(EXIT_FAILURE);
	}

	temp = (*top)->n;
	(*top)->next->n = (*top)->next->n - temp;
	pop(top, lineNum);
}
/**
 * _div - divide bewtween top
 * @top: top of the stack
 * @n: the value on the top
 */
void _div(stack_t **top, __attribute__((unused))unsigned int n)
{
	int temp = 0;

	if (!(*top) || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", lineNum);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineNum);
		exit(EXIT_FAILURE);
	}

	temp = (*top)->n;
	(*top)->next->n = (*top)->next->n / temp;
	pop(top, lineNum);
}
/**
 * _mul - divide bewtween top
 * @top: top of the stack
 * @n: the value on the top
 */
void _mul(stack_t **top, __attribute__((unused))unsigned int n)
{
	int temp = 0;

	if (!(*top) || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", lineNum);
		exit(EXIT_FAILURE);
	}

	temp = (*top)->n;
	(*top)->next->n = (*top)->next->n * temp;
	pop(top, lineNum);
}
/**
 * _mod - brings the mod bewtween top
 * @top: top of the stack
 * @n: the value on the top
 */
void _mod(stack_t **top, __attribute__((unused))unsigned int n)
{
	int temp = 0;

	if (!(*top) || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", lineNum);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineNum);
		exit(EXIT_FAILURE);
	}

	temp = (*top)->n;
	(*top)->next->n = (*top)->next->n % temp;
	pop(top, lineNum);
}
