#include "monty.h"
 
/**
 * _add - adds the top two elements of the stack.
 * If the stack contains less than two elements, handle error
 * with _error(8).
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;

	if (*stack == NULL || stack == NULL || (*stack)->next == NULL)
		_error1(9, line_number);
	new->next->n += new->n;
	*stack = (*new).next;
	(*stack)->prev = NULL;
}
