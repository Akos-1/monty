#include "monty.h"
/**
 * main - starting point
 * @argc: command line arguments
 * @argv: pointer to an array
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	int stack[STACK_SIZE];
	int begin = -1;

	monty(argv[1], stack, &begin);

	return (0);
}
