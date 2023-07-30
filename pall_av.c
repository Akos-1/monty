#include "monty.h"
/**
 * pall - displays all elements of the stack
 * @stack: stack
 * Return: nothing
 */
void pall(stack_t **stack)
{
	stack_t *present;

	for (present = *stack; present != NULL; present = present->next)
	{
		printf("%d\n", present->n);
	}
}
