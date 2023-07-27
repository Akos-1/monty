#include "monty.h"

void push(int value, int *stack, int *begin)
{
	if (*begin == STACK_SIZE - 1)
	{
		fprintf(stderr, "Error: Stack overflow! Cannot push element.\n");
		exit(EXIT_FAILURE);
	}
	stack[++(*begin)] = value;
}

int pop(int *stack, int *begin)
{
	if (*begin == -1)
	{
		fprintf(stderr, "Error: Stack underflow! Cannot pop element.\n");
		exit(EXIT_FAILURE);
	}
	return (stack[(*begin)--]);
}

void pint(int *stack, int begin)
{
	if (begin == -1)
	{
		fprintf(stderr, "Error: Can't pint, stack empty.\n");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", stack[begin]);
}
