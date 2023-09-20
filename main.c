#include "monty.h"

infos_t info = {NULL, NULL, NULL, 0};

/**
 * main - entry point of the program.
 * @argc: the count of args
 * @argv: the args values
 *
 * Return: 0.
 */
int main(int argc, char **argv)
{
	stack_t *head = NULL;
	FILE *file;
	ssize_t read_line;
	char *line = NULL;
	size_t size = 0;
	unsigned int line_counter = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	info.file = file;

	while ((read_line = getline(&line, &size, file)) > 0)
	{
		info.line = line;

		run_cmd(&head, file, line, line_counter);
		line_counter++;

		free(line);
		line = NULL;
	}

	free(line);
	line = NULL;
	free_stack(&head);
	fclose(file);
	return (0);
}
