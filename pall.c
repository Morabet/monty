#include "monty.h"
/**
 * pall - display the stack following the rule of LIFO
 * @stack: pointer to the header of the linked list.
 * @line_number: the number of the line uin the file
 *
 * Return: void.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

