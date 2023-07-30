#include "monty.h"
/**
 * main - entry point
 * @argc: command line arguments
 * @argv: pointer to an array
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t buffersize = 0;
	unsigned int line_number = 1;
	stack_t *temp;
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &buffersize, file) != -1)
	{
		process_line(line, line_number, &stack);
		line_number++;
	}
	free(line);
	fclose(file);
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	return (EXIT_SUCCESS);
}
