#include "monty.h"

/**
 * pstr -  prints the string starting at the top of
 *		the stack, followed by a new line.
 * @stack: the head of the linked list.
 * @line_number: the line number in the line
 * Return: void.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pstr, stack empty\n", line_number);

		free(info.line);
		free_stack(stack);
		fclose(info.file);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	while (tmp)
	{
		if (tmp->n <= 0 || tmp->n > 127)
			break;

		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
