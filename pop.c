#include "monty.h"
/**
 * pop_func - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pop_func(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(meta.file);
		free(meta.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
