#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: the head of the linked list
 * @line_number: the line number in the file
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);

		free(info.line);
		fclose(info.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
