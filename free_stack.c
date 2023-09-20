#include "monty.h"

/**
 * free_stack - free a stack
 * @stack: pointer to the head of the list
 * Return : void.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = NULL;

	if (*stack)
	{
		while (*stack)
		{
			tmp = *stack;
			*stack = (*stack)->next;
			free(tmp);
		}
		*stack = NULL;
	}
}
