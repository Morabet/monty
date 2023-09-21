#include "monty.h"

/**
 * push_stack - push to the stack
 * @stack: head to the linked list.
 * @value: the argument to push
 * Return: void
 */
void push_stack(stack_t **stack, int value)
{
	stack_t *node = NULL, *tmp;

	tmp = *stack;
	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(0);
	}

	if (tmp)
		tmp->prev = node;
	node->n = value;
	node->next = *stack;
	node->prev = NULL;
	*stack = node;
}

/**
 * push_queue - push to the queue
 * @queue: head to the linked list.
 * @value: the argument to push
 * Return: void
 */
void push_queue(stack_t **queue, int value)
{
	stack_t *rear, *node = NULL;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(0);
	}
	node->n = value;
	node->next = NULL;

	if (!*queue)
	{
		node->prev = NULL;
		*queue = node;
	}
	else
	{
		rear = *queue;
		while (rear->next)
			rear = rear->next;

		node->prev = rear;
		rear->next = node;
	}
}

/**
 * push - push an int to the stack or queue
 * @head: head to the stack or queue
 * @line_number: the number of the line in the file.
 * Return: void.
 */
void push(stack_t **head, unsigned int line_number)
{
	int value, i = 0, flag = 0;

	if (info.arg)
	{
		if (info.arg[0] == '-')
			i++;
		for (; info.arg[i] != '\0'; i++)
		{
			if (info.arg[i] > 57 || info.arg[i] < 48)
				flag = 1; }
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(info.file);
			free(info.line);
			free_stack(head);
			exit(EXIT_FAILURE); 
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);

		free(info.line);
		fclose(info.file);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	value = atoi(info.arg);

	if (info.type == 0)
		push_stack(head, value);
	else
		push_queue(head, value);
}
