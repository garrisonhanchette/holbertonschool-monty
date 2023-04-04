#include "monty.h"

/**
 * push - Pushes a node to the stack
 * @newNode: Pointer to new node
 * @linenum: Line number in bytecode file
 *
 * Return: Void
 */

void push(stack_t **newNode, __attribute__((unused))unsigned int linenum)
{
	stack_t *temp;

	if (*newNode == NULL) /* No need to check for newNode == NULL */
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head =  *newNode;
		return;
	}
	temp = head;
	head = *newNode;
	head->next = temp;
	temp->prev = head;
}

/**
 * pop - Pops a node from the top of the stack
 * @stack: Double pointer to stack
 * @linenum: Line number in bytecode file
 *
 * Return: Void
 */

void pop(stack_t **stack, unsigned int linenum)
{
	stack_t *temp;

	if (*stack == NULL) /* No need to check for stack == NULL */
	{
		error2(2, linenum);
	}

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * swap - Swaps the top two nodes on the stack
 * @stack: Double pointer to stack
 * @linenum: Line number in bytecode file
 *
 * Return: Void
 */

void swap(stack_t **stack, unsigned int linenum)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL) /* No need to check for stack == NULL */
	{
		error2(3, linenum);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * add - Adds the values of the top two nodes on the stack
 * @stack: Double pointer to stack
 * @linenum: Line number in bytecode file
 *
 * Return: Void
 */

void add(stack_t **stack, unsigned int linenum)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL) /* No need to check for stack == NULL */
	{
		error2(4, linenum);
	}

	sum = (*stack)->n + (*stack)->next->n; /* No need to use extra variable */
	pop(stack, linenum); /* No need to free manually */
	(*stack)->n = sum;
}

/**
 * nop - Does nothing
 * @stack: Double pointer to stack
 * @linenum: Line number in bytecode file
 *
 * Return: Void
 */

void nop(stack_t **stack, unsigned int linenum)
{
	(void) stack; /* No need to check for stack == NULL */
	(void) linenum; /* No need to check for linenum */
}
