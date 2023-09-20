#include "monty.h"

/**
 * rotl - rotates the stack to the top..
 * @stack: the head of the linked list.
 * @line_number: the line number in the line
 * Return: void.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1, *tmp2 = *stack;

	(void)line_number;

	if (!(*stack) || !(*stack)->next)
		return;

	tmp1 = (*stack)->next;
	tmp1->prev = NULL;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;

	tmp2->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp2;
	(*stack) = tmp1;
}

/**
 * rotr - rotates the stack to the bottom..
 * @stack: the head of the linked list.
 * @line_number: the line number in the line
 * Return: void.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;

	if (!*stack || !(*stack)->next)
		return;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	*stack = tmp;
}
