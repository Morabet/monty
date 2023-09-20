#include "monty.h"

/**
 * pint - prints the value at the top of the stack.
 * @stack: the pointer to the head of the list
 * @line_number: the line number in the file
 * Return: void.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(info.line);

		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
