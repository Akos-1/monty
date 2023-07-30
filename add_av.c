#include "monty.h"
/**
 * add - addition of the top two stack element
 * @stack: pointer
 * @line_number: the line number in which the "add" opcode is initiated
 */
void add(stack_t **stack, unsigned int line_number)
{
	int feedback;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	feedback = ((*stack)->n) + ((*stack)->next->n);
	pop(stack, line_number);
	(*stack)->n = feedback
}
