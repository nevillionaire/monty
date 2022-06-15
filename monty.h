fndef _MONTY_H_
#define _MONTY_H_
/*LIBRERIES*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

extern int lineNum;
/**
 *  * struct stack_s - doubly linked list representation of a stack (or queue)
 *   * @n: integer
 *    * @prev: points to the previous element of the stack (or queue)
 *     * @next: points to the next element of the stack (or queue)
 *      *
 *       * Description: doubly linked list node structure
 *        * for stack, queues, LIFO, FIFO
 *         */
typedef struct stack_s
{
			int n;
					struct stack_s *prev;
							struct stack_s *next;
} stack_t;
/**
 *  * struct instruction_s - opcode and its function
 *   * @opcode: the opcode
 *    * @f: function to handle the opcode
 *     *
 *      * Description: opcode and its function
 *       * for stack, queues, LIFO, FIFO
 *        */
typedef struct instruction_s
{
			char *opcode;
				void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*PROTOTYPES*/
void parser(char *buffer, stack_t **top);
void (*get_function(char *script))(stack_t **top, unsigned int arg);
void *_calloc(unsigned int nmemb, unsigned int size);
void push(stack_t **top, unsigned int n);
void pint(stack_t **top, __attribute__((unused))unsigned int n);
void pall(stack_t **top, unsigned int n);
void swap(stack_t **top, __attribute__((unused))unsigned int n);
void _div(stack_t **top, __attribute__((unused))unsigned int n);
void _mul(stack_t **top, __attribute__((unused))unsigned int n);
void _mod(stack_t **top, __attribute__((unused))unsigned int n);
void pstr(stack_t **top, __attribute__((unused))unsigned int n);
void pop(stack_t **top, __attribute__((unused))unsigned int n);
void add(stack_t **top, __attribute__((unused))unsigned int n);
void pchar(stack_t **top, __attribute__((unused))unsigned int n);
void rotl(stack_t **top, __attribute__((unused))unsigned int n);
void sub(stack_t **top, __attribute__((unused))unsigned int n);
void free_dlistint(stack_t *head);
stack_t *getNewNode(int n);
char *parseLine(char *buffer);
unsigned int _atoi(char *s);
int isInteger(char *string);

#endif /*_MONTY_H_*/
