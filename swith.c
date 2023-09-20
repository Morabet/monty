#include "monty.h"

/**
 * switch_stack - switch to the stack
 * @stack: the head of the list
 * @line_number: the line number in the file
 * Return: void
 */
void switch_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	info.type = 0;
}

/**
 * switch_queue - switch to the queue
 * @queue: the head of the list
 * @line_number: the line number in the file
 * Return:void
 */
void switch_queue(stack_t **queue, unsigned int line_number)
{
	(void)queue;
	(void)line_number;

	info.type = 1;
}
