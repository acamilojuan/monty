#include "monty.h"

/**
 * _nop - swaps the top two elements of the stack.
 * If the stack contains less than two elements, handle error
 * with _error(8).
 * @stack: Double pointer to the top of the stack.
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _pchar - print the value at the top of the stack, followed
 * by a new line.
 * If the stack is empty for pint, handle error with _error(7).
 * @stack: Double pointer to the top of the stack.
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || stack == NULL)
	{
		free_nodes(*stack);
		_error2(12, line_number);
	}
	if (isalpha((*stack)->n) == 0) /*case not letter of alpha*/
		_error2(11, line_number);
	fprintf(stdout, "%c\n", (*stack)->n);
}

/**
 * _pstr - Function to print the strig starting at the top of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;

	(void)line_number;

	while (new)
	{
		if (isascii(new->n) == 0 || new->n == 0)
			break;
		fprintf(stdout, "%c", new->n);
		new = new->next;
	}
	printf("\n");
}
/**
 * _rotl - Function to rotate the stack to the top.
 * @stack: Double pointer to the top of the stack.
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;

	(void)line_number;

	if ((*stack)->next != NULL || stack != NULL || *stack != NULL)
	{
		*stack = (*stack)->next;
		while (new->next != NULL)
			new = new->next;
		(*stack)->prev->next = NULL;
		new->next = (*stack)->prev;
		(*stack)->prev->prev = (*new);
		(*stack)->prev = NULL;
	}
}
/**
 * _rotr - Function to rotate the stack to the bottom.
 * @stack: Double pointer to the top of the stack.
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;

	(void)line_number;

	if ((*stack)->next != NULL || stack != NULL || *stack != NULL)
	{
		while ((*stack)->next != NULL)
			*stack = (*stack)->next;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
		new->prev = *stack;
		(*stack)->next = *new;
	}
}
