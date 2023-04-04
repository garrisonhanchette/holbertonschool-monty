#include "monty.h"

/**
 * error - Prints error messages and exits
 * @errorCase: Different cases for errors
 * (1) - Invalid command
 * (2) - malloc failed
 * (3) - Invalid instruction in file
 * (4) - File not open or readable
 * (5) - No integer given to push
 *
 * Return: Void
 */

void error(int errorCase, ...)
{
	va_list ag;
	char *op;
	int linenum;

	va_start(ag, errorCase);
	if (errorCase == 1)
		fprintf(stderr, "USAGE: monty file\n");
	else if (errorCase == 2)
		fprintf(stderr, "Error: malloc failed\n");
	else if (errorCase == 3)
		fprintf(stderr, "Error: Can't open file %s\n", va_arg(ag, char *));
	else if (errorCase == 4)
	{
		linenum = va_arg(ag, int);
		op = va_arg(ag, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", linenum, op);
	}
	else if (errorCase == 5)
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
	freeNodes(&head);
	exit(EXIT_FAILURE);
}

/**
 * error2 - Prints more error messages and exits
 * @errorCase: Different cases for errors
 * (1) - pint error - stack empty
 * (2) - pop error - stack empty
 * (3) - swap error - stack too short
 * (4) - add error - stack too short
 * (5) - sub error - stack too short
 *
 * Return: Void
 */

void error2(int errorCase, ...)
{
	va_list ag;
	int linenum;

	va_start(ag, errorCase);
	if (errorCase == 1)
	{
		linenum = va_arg(ag, int);
		fprintf(stderr, "L%d: can't pint, stack empty\n", linenum);
	}
	else if (errorCase == 2)
	{
		linenum = va_arg(ag, int);
		fprintf(stderr, "L%d: can't pop an empty stack\n", linenum);
	}
	else if (errorCase == 3)
	{
		linenum = va_arg(ag, int);
		fprintf(stderr, "L%d: can't swap, stack too short\n", linenum);
	}
	else if (errorCase == 4)
	{
		linenum = va_arg(ag, int);
		fprintf(stderr, "L%d: can't add, stack too short\n", linenum);
	}
	else if (errorCase == 5)
	{
		linenum = va_arg(ag, int);
		fprintf(stderr, "L%d: can't sub, stack too short\n", linenum);
	}
