#include "monty.h"

/**
 * sub - subtracts the top element of the stack
 *		from the second top element of the stack.
 * @stack: the head of the linked list.
 * @line_number: the line number in the file
 * Return: void.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);

		free(info.line);
		fclose(info.file);
		free_stack(stack);

		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;

	free(tmp);
}
