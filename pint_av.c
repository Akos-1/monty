#include "monty.h"

/**
 * pint - prints the top of the stack's value
 * @stack: double pointer to stack's top
 * @line_number: the line number present in the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", top_node->n);
}
