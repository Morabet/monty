#include "monty.h"

/**
 * rotl - rotates the stack to the top..
 * @stack: the head of the linked list.
 * @line_number: the line number in the line
 * Return: void.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1, *tmp2;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't rotl, stack too short\n", line_number);

		free(info.line);
		free_stack(stack);
		fclose(info.file);
		exit(EXIT_FAILURE);
	}

	if (!(*stack)->next)
		return;

	tmp1 = *stack;
	tmp2 = *stack;
	while (tmp2->next)
		tmp2 = tmp2->next;

	*stack = (*stack)->next;
	tmp2->next = tmp1;
	tmp1->next = NULL;

}

/**
 * rotr - rotates the stack to the bottom..
 * @stack: the head of the linked list.
 * @line_number: the line number in the line
 * Return: void.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1, *tmp2;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't rotr, stack too short\n", line_number);

		free(info.line);
		free_stack(stack);
		fclose(info.file);
		exit(EXIT_FAILURE);
	}

	if (!(*stack)->next)
		return;

	tmp1 = *stack;
	tmp2 = *stack;
	while (tmp1->next->next)
		tmp1 = tmp1->next;

	tmp2 = tmp1->next;
	tmp2->next = *stack;
	tmp1->next = NULL;
	*stack = tmp2;
}
