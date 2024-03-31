#include "monty.h"
meta_t meta = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n"); //print error to stderr
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r"); //read file where argv[1] is the file name, and r is the mode - read. You can only read a file that exist otherwise Null is returned
	meta.file = file; //assign the read file/or file to meta (which is an extension of meta_t struct )
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]); //Test for Null files
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file); //Get the content of the file
		meta.content = content; //assign the content
		counter++; //increase counter to repeat the loop. 
		if (read_line > 0)
		{
			execute(content, &stack, counter, file); //run execute if content line above 0
		}
		free(content); //free content from memory
	}
	free_stack(stack); //free stack from memory
	fclose(file); //close file
return (0);
}
