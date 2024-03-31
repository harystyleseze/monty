#include "monty.h"
/**
 * push_func - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void push_func(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (meta.arg)
	{
		if (meta.arg[0] == '-')
			j++;
		for (; meta.arg[j] != '\0'; j++)
		{
			if (meta.arg[j] > 57 || meta.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(meta.file);
			free(meta.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(meta.file);
		free(meta.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(meta.arg);
	if (meta.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
