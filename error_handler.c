#include "monty.h"

/**
* _error1 - function that prints the error messages
* depending on the error_code provided
* (1) If the user doesn't give any file or more than one argument is sent.
* (2): If it’s not possible to open or read the file.
* (3): If the file contains an invalid instruction.
* (4): If the program can’t malloc anymore.
* (5): If parameter given to push is not an integer.
* (6): If there is no argument given to push.
* @error_code: Type of error to be handled
* Return: void.
*/
void _error1(int error_code, ...)
{
	va_list args;
	int line_number;
	char *opcode_type;
	char *file_name;

	va_start(args, error_code);
	switch (error_code)
	{
		case 1:
			printf("USAGE: monty file\n");
			break;
		case 2:
			file_name = va_arg(args, char *);
			printf("Error: Can't open file %s\n", file_name);
			break;
		case 3:
			line_number =  va_arg(args, int);
			opcode_type = va_arg(args, char *);
			printf("L%d: unknown instruction\n", line_number, opcode_type);
			break;
		case 4:
			printf("Error: malloc failed\n");
			break;
		case 5:
			printf("L%d: usage: push integer\n", va_arg(args, int));
			break;
		case 6:
			printf("L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
* _error2 - function that prints the error messages
* depending on the error_code provided
* (7): If the stack is empty for pint.
* (8): If the stack is empty for pop.
* (9): If the stack contains less than two elements.
* (10): If the top element of the stack is 0, div or mod by 0 is not allowed.
* (11): If the value in the node is not in the ascii table.
* (12): If the stack is empty for pchar.
* @error_code: Type of error to be handled
* Return: void.
*/
void _error2(int error_code, ...)
{
	va_list args;

	va_start(args, error_code);
	line_number =  va_arg(args, int);
	opcode_type = va_arg(args, char *);
	switch (error_code)
	{
		case 7:
			printf("L%d: can't pint, stack empty\n", va_arg(args, int));
			break;
		case 8:
			printf("L%d: can't pop an empty stack\n", va_arg(args, int));
			break;
		case 9:
			line_number =  va_arg(args, int);
			opcode_type = va_arg(args, char *);
			printf("L%d: can't %s, stack too short\n", line_number, opcode_type);
			break;
		case 10:
			printf("L%d: division by zero\n", va_arg(args, unsigned int));
			break;
		case 11:
			printf("L%d: can't pchar, value out of range\n", va_arg(args, int));
			break;
		case 12:
			printf("L%d: can't pchar, stack empty\n", va_arg(args, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
