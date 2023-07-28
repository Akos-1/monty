#include "monty.h"
void process_instruct(char *instruction, int line_number, int *stack, int *begin)
{
	if (strcmp(instruction, "pint") == 0)
	{
		pint(stack, *begin);
	}
	else if (strcmp(instruction, "push") == 0)
	{
		char *value_str = strtok(NULL, " ");

		if (value_str == NULL)
		{
			fprintf(stderr, "Error: Missing value for push instruction at line %d.\n", line_number);
			exit(EXIT_FAILURE);
		}
		int value = atoi(value_str);

		push(value, stack, begin);
	}
	else
	{
		fprintf(stderr, "Error: Unknown instruction '%s' at line %d.\n", instruction, line_number);
		exit(EXIT_FAILURE);
	}
}

void monty(char *file_path, int *stack, int *begin)
{
	FILE *file = fopen(file_path, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file '%s'.\n", file_path);
		exit(EXIT_FAILURE);
	}

	char line[100];
	int line_number = 0;

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		char *instruction = strtok(line, " \t\n");

		if (instruction != NULL && instruction[0] != '#')
		{
			process_instruction(instruction, line_number, stack, begin);
		}
	}
	fclose(file);
}
