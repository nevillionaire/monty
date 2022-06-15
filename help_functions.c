#include "monty.h"
/**
 * free_dlistint - frees a list
 * @head: head of the list
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp = NULL;

	temp = head;

	if (head == NULL)
		return;

	while (temp->next)
	{
		temp = temp->next;
		free(temp->prev);
	}
	free(temp);
}
/**
 * isInteger - verify if a string is integer
 * @string: string to verify
 *
 * Return: 0 if it is
 */
int isInteger(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		if (string[i] == '-' && i == 0)
			i++;
		if (string[i] > '9' || string[i] < '0')
			return (1);
		i++;
	}
	return (0);
}
/**
 * _atoi - turn a string into integer
 * @s: string to convert
 *
 * Return: integer
 */
unsigned int _atoi(char *s)
{
	int i = 0;
	unsigned int result = 0;
	int negative = 0;

	if (s == NULL)
	{
		return (result);
	}
	while (s[i] != '\0')
	{
		if (s[i] == '-')
			negative++;
		if (s[i] >= '0' && s[i] <= '9')
		{
			result = result * 10 + s[i] - '0';
			if (s[i + 1] < '0' || s[i + 1] > '9')
			{
				break;
			}
		}
		if (s[i] > '9' && s[i] < 0)
			return (0);
		i++;
	}
	if (result != 0 && (negative % 2 != 0 || negative == 1))
		result = result * -1;
	return (result);
}
