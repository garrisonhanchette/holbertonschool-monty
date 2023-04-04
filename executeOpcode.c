#include "monty.h"

/**
 * openOpcode - Opens file with Opcode
 * @opcode: opcode string from bytecode file
 *
 * Return: Void
 */

void openOpcode(char *opcode)
{
	int check;
	FILE *file;

	if (opcode == NULL)
		error(3, opcode);

	check = access(opcode, R_OK);

	if (check == -1)
		error(3, opcode);

	file = fopen(opcode, "r");

	if (file == NULL)
		error(3, opcode);

	readFile(file);

	fclose(file);
}

/**
 * readFile - Reads the bytecode file line by line
 * @file: pointer to file
 *
 * Return: Void
 */

void readFile(FILE *file)
{
	int lineNum;
	char *line;
	size_t n;

	line = NULL;
	n = 0;

	if (file == NULL)
		error(3, "opcode");

	for (lineNum = 1; getline(&line, &n, file) != -1; lineNum++)
	{
		readLine(line, lineNum);
	}
	free(line);
}

/**
 * readLine - Tokenizes line to get function
 * @line: string line from bytecode file
 * @lineNum: line number in bytedcode file
 *
 * Return: 0 on success
 */

int readLine(char *line, int lineNum)
{
	char *opcode;
	char *value;

	if (line == NULL)
		error(2);

	opcode = strtok(line, " \t\n\a");

	if (opcode == NULL)
		return (0);

	value = strtok(NULL, " \t\a\n");

	findFunc(opcode, value, lineNum);

	return (0);
}

/**
 * findFunc - Finds function that matches opcode
 * @opcode: opcode from bytecode file
 * @num: number given to operation(only push)
 * @line: Line number in bytecode file
 *
 * Return: Void
 */

void findFunc(char *opcode, char *num, int line)
{
	int i, errorFlag;

	instruction_t funcList[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", multiply},
		{"mod", modulo},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (errorFlag = 1, i = 0; funcList[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, funcList[i].opcode) == 0)
