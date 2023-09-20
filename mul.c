#include "monty.h"

/**
 * mul -  multiplies the second top element of
 *		the stack with the top element of the stack..
 * @stack: the head of the linked list.
 * @line_number: the line number in the line
 * Return: void.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);

		free(info.line);
		free_stack(stack);
		fclose(info.file);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;

	free(tmp);
}
