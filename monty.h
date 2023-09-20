#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct infos - a global variable that will hold issential data.
 * @file: pointer to the file.
 * @line: the line from the file.
 * @arg: the argument of the command.
 * @type: type of the data structure (stack by default 0), (queue is 1)
 */
typedef struct infos
{
	FILE *file;
	char *line;
	char *arg;
	int type;
} infos_t;
extern infos_t info;

/** run_cmd.c **/
int run_cmd(stack_t **head, FILE *f, char *line, unsigned int line_number);

/** push.c **/
void push_stack(stack_t **stack, int value);
void push_queue(stack_t **queue, int value);
void push(stack_t **head, unsigned int line_number);

/** pop.c **/
void pop(stack_t **stack, unsigned int line_number);

/** swap.c **/
void swap(stack_t **stack, unsigned int line_number);

/** add.c **/
void add(stack_t **stack, unsigned int line_number);

/** sub.c **/
void sub(stack_t **stack, unsigned int line_number);

/** div.c **/
void f_div(stack_t **stack, unsigned int line_number);

/** mul.c **/
void mul(stack_t **stack, unsigned int line_number);

/** mod.c **/
void mod(stack_t **stack, unsigned int line_number);

/** pchar.c **/
void pchar(stack_t **stack, unsigned int line_number);

/** pstr.c **/
void pstr(stack_t **stack, unsigned int line_number);

/** rot.c **/
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/** switch.c **/
void switch_stack(stack_t **stack, unsigned int line_number);
void switch_queue(stack_t **queue, unsigned int line_number);

/** pall.c **/
void pall(stack_t **stack, unsigned int line_number);

/** pint.c **/
void pint(stack_t **stack, unsigned int line_number);

/** free_stack.c **/
void free_stack(stack_t **stack);

/** strings.c **/
int is_valid_num(char *str);

#endif
