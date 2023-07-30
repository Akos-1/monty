#include "monty.h"
#include <stdlib.h>

/**
 * push - push elements onto a stack
 * @stack: stack unto the pushing elements
 * @value: element's value pushed unto the stack
 * Return: nothing
 */
void push(stack_t **stack, int value)
{

	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}


	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;


	if (*stack)
		(*stack)->prev = new_node;


	*stack = new_node;
}
