#include "monty.h"
/**
 * _pint - prints the value at the top of the stack, followed
 * by a new line.
 * If the stack is empty for pint, handle error with _error(7).
 * @stack: Double pointer to the top of the stack.
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL || stack == NULL)
		_error1(7, line_number);
	fprintf(stdout, "%d\n", (*stack)->n);
}
/**
 * _pop - removes the top element of the stack.
 * If the stack is empty for pop, handle error with _error(8).
 * @stack: Double pointer to the top of the stack.
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (*stack == NULL || stack == NULL)
		_error1(8, line_number);
	new = (*stack)->next;
	free(*stack);
	*stack = new;
}

/**
 * _swap - swaps the top two elements of the stack.
 * If the stack contains less than two elements, handle error
 * with _error(8).
 * @stack: Double pointer to the top of the stack.
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;
	int aux = 0;

	if (*stack == NULL || stack == NULL || (*stack)->next == NULL)
		_error1(9, line_number);
	aux = (*stack)->n;
	(*stack)->n = new->next->n;
	new->next->n = aux;
}
