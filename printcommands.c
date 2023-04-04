#include "monty.h"

/**
 * pall - Prints the whole stack
 * @stack: Double pointer to top of stack
 * @linenum: Line number in the bytecode file
 *
 * Return: Void
 */

void pall(stack_t **stack, unsigned int linenum)
{
	stack_t *temp;

	(void) linenum;
/* No need to check for stack == NULL since it is always initialized */
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the top value of the stack with a new line
 * @stack: Double pointer to top of stack
 * @linenum: Line number in the bytecode file
 *
 * Return: Void
 */

void pint(stack_t **stack, unsigned int linenum)
{
	if (*stack == NULL) /* No need to check for stack == NULL */
		error2(1, linenum);
	printf("%d\n", (*stack)->n);
}
