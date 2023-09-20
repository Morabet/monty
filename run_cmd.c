#include "monty.h"

/**
 * run_cmd - to run the commands in the monty file.
 * @head: head to the srack or queue?
 * @f: poiter to the file.
 * @line: string pointer to a line from the file.
 * @line_number: an integer to hold the number of line in the file
 * Return: 0 if Success, else 1
 */
int run_cmd(stack_t **head, FILE *f, char *line, unsigned int line_number)
{
	char *opc;
	int i = 0;
	instruction_t ops[] = {
		{"stack", switch_stack}, {"queue", switch_queue},
		{"push", push}, {"pop", pop}, {"pall", pall_stack},
		{"pint", pint}, {"swap", swap}, {"add", add},
		{"sub", sub}, {"div", f_div}, {"mul", mul},
		{"mod", mod}, {"pchar", pchar}, {"pstr", pstr},
		{"rotl", rotl}, {"rotr", rotr},
		{NULL, NULL}
	};

	opc = strtok(line, " \t\n");
	if (opc && opc[0] == '#')
		return (1);

	info.arg = strtok(NULL, " \t\n");

	while (opc && ops[i].opcode)
	{
		if (strcmp(opc, "nop") == 0)
			return (0);

		if (strcmp(ops[i].opcode, opc) == 0)
		{
			ops[i].f(head, line_number);
			return (0);
		}
		i++;
	}

	if (opc && !ops[i].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opc);
		free(line);
		free_stack(head);
		fclose(f);
		exit(EXIT_FAILURE);
	}
	return (1);
}
