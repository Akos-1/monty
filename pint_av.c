#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number in the file
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
