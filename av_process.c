#include "monty.h"

/**
 * process_line - Processes a line from the Monty file.
 * @line: The line to be processed in the Monty file .
 * @line_number: The present line number.
 * @stack: Double pointer to the stack.
 *
 * Return: void
 */
void process_line(const char *line, unsigned int line_number, stack_t **stack)
{
	char *opcode, *argument;
	int num = 0;

	opcode = strtok((char *)line, " \t\n");
	if (opcode == NULL)
		return;

	if (strcmp(opcode, "push") == 0)
	{
		argument = strtok(NULL, " \t\n");
		if (argument == NULL || !is_number(argument))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

		num = atoi(argument);
		push(stack, num);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

