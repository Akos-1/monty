#include "monty.h"
/**
 * swap - interchange the top two elements
 * @stack: double pointer to the top of the stack
 * @line_number: line number that contains the swap opcode
 * Return: 0 if successful or 1 if not
 */
int swap(stack_t **stack, unsigned int line_number)
{
	int temp;
        stack_t *first_node = *stack;
        stack_t *second_node = (*stack)->next;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Error: L%d: can't swap, stack too short\n", line_number);
		return (1);
	}
	temp = first_node->n;
	first_node->n = second_node->n;
	second_node->n = temp;
	return (0);
}
