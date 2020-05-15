#include "monty.h"

/**
 * _push - pushes an element to the stack.
 * sets the format of the data to a stack (LIFO).
 * This is the default behavior of the program.
 * When switching mode:
 * The top of the stack becomes the front of the queue
 * The front of the queue becomes the top of the stack
 * If parameter given to push is not an integer, handle error with _error(5).
 * If there is no argument given to push, handle error with _error(6).
 * @stack: double pointer to the node of the stack
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
void _push_stack(stack_t **stack,
__attribute__((unused))unsigned int line_number)
{
	stack_t *new_node;
	int i = 0, number_int;

	if (var_global.number == NULL)
	{
		printf("%s hola\n", var_global.number);
		free_nodes(*stack);
		_error1(6, line_number);
	}
	for (i = 0; var_global.number[i] != '\0'; i++)
	{
		if (i == 0 && var_global.number[i] == 45)
			continue;
		else if (var_global.number[i] >= 48 && var_global.number[i] <= 57)
			continue;
		else
		{
			free_nodes(*stack);
			_error1(5, line_number);
		}
	}
	/*To check if parameter given to push is negative.*/
	if (var_global.number[0] == '-')
		number_int = atoi(var_global.number) * (-1);
	else
		number_int = atoi(var_global.number);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		free_nodes(*stack);
		_error1(4);
	}
	new_node->n = number_int;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * _push - pushes an element to the stack.
 * If parameter given to push is not an integer, handle error with _error(5).
 * If there is no argument given to push, handle error with _error(6).
 * @:
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
/*void _push_queue(stack_t **new_node, unsigned int line_number)
{
	stack_t *aux_node;

	if (!new_node)
		_error1(4);

 Edge case when the doubly linked list is NULL
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	first_node = head;
	head = *new_node;
	new_node->next = first_node;
	first_node->prev = new_node;
}*/

/**
 * _pall - prints all the values on the stack, starting
 * from the top of the stack.
 * If the stack is empty, don’t print anything.
 * @stack: double pointer to the node of the stack
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
void _pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *aux_printer;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	aux_printer = *stack;
	while (aux_printer != NULL)
	{
		if (aux_printer->n != '\0')
		{
			printf("%d\n", aux_printer->n);
		}
		aux_printer = aux_printer->next;
	}
}

/**
 * _pint - prints the value at the top of the stack, followed
 * by a new line.
 * If the stack is empty for pint, handle error with _error(7).
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
/*void _pint(stack_t **stack, unsigned int line_number)
{

}*/

/**
 * _pop - removes the top element of the stack.
 * If the stack is empty for pop, handle error with _error(8).
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
/*void _pop(stack_t **stack, unsigned int line_number)
{

}*/

/**
 * _swap - swaps the top two elements of the stack.
 * If the stack contains less than two elements, handle error
 * with _error(8).
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
/*void _swap(stack_t **stack, unsigned int line_number)
{

}*/
