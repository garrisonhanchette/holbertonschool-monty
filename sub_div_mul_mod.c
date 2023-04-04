#include "monty.h"

/**
 * sub - Subtracts the top value from the second value on the stack
 * @stack: double pointer to stack
 * @linenum: Line number in bytecode file
 *
 * Return: Void
 */

void sub(stack_t **stack, unsigned int linenum)
{
	int delta;

	if (*stack == NULL || (*stack)->next == NULL) /* No need to check for stack == NULL */
	{
		error2(5, linenum);
	}

	delta = (*stack)->next->n - (*stack)->n; /* No need to use extra variable */
	pop(stack, linenum); /* No need to free manually */
	(*stack)->n = delta;
}

/**
 * divide - Divides the second value by the top value on the stack
 * @stack: double pointer to stack
 * @linenum: Line number in bytecode file
 *
 * Return: Void
 */

void divide(stack_t **stack, unsigned int linenum)
{
	int answer;

	if (*stack == NULL || (*stack)->next == NULL) /* No need to check for stack == NULL */
	{
		error3(2, linenum);
	}

	if ((*stack)->n == 0)
		error3(1, linenum);

	answer = (*stack)->next->n / (*stack)->n; /* No need to use extra variable */
	pop(stack, linenum); /* No need to free manually */
	(*stack)->n = answer;
}

/**
 * multiply - Multiplies the top value and the second value on the stack
 * @stack: double pointer to stack
 * @linenum: Line number in bytecode file
 *
 * Return: Void
 */

void multiply(stack_t **stack, unsigned int linenum)
{
	int answer;

	if (*stack == NULL || (*stack)->next == NULL) /* No need to check for stack == NULL */
	{
		error3(3, linenum);
	}

	answer = (*stack)->next->n * (*stack)->n; /* No need to use extra variable */
	pop(stack, linenum); /* No need to free manually */
	(*stack)->n = answer;
}

/**
 * modulo - Modulo of the second value by the top value on the stack
 * @stack: double pointer to stack
 * @linenum: Line number in bytecode file
 *
 * Return: Void
 */

void modulo(stack_t **stack, unsigned int linenum)
{
	int answer;

	if (*stack == NULL || (*stack)->next == NULL) /* No need to check for stack == NULL */
	{
		error3(4, linenum);
	}

	if ((*stack)->n == 0)
	{
		error3(1, linenum);
	}

	answer = (*stack)->next->n % (*stack)->n; /* No need to use extra variable */
	pop(stack, linenum); /* No need to free manually */
	(*stack)->n = answer;
}
