#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack: the pointer to the head of the stack
 * @line_number: the line number in the file
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);

		free(info.line);
		fclose(info.file);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
