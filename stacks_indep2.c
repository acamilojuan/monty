#include "monty.h"
/**
 * _pchar - prints the value at the top of the stack, followed
 * by a new line.
 * If the stack is empty for pint, handle error with _error(7).
 * @stack: Double pointer to the top of the stack.
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || stack == NULL)
		_error1(7, line_number);
	if (isalpha((*stack)->n) == 0) /*case not letter of alpha*/
		_error1()
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
 * @head: Double pointer to the top of the stack.
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
void _rotl(stack_t **head, unsigned int line_number)
{
	stack_t *new = *head;

	(void)line_number;

	if ((*head)->next != NULL || stack != NULL || *stack != NULL)
	{
		*stack = (*stack)->next;
		while (new->next != NULL)
			new = new->next;
		(*head)->prev->next = NULL;
		new->next = (*head)->prev;
		(*head)->prev->prev = new;
		(*head)->prev = NULL;
	}
}
/**
 * _rotr - Function to rotate the stack to the bottom.
 * @head: Double pointer to the top of the stack.
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
void _rotr(stack_t **head, unsigned int line_number)
{
	stack_t *new = *head;

	(void)line_number;

	if ((*head)->next != NULL || stack != NULL || *stack != NULL)
	{
		while ((*head)->next != NULL)
			*head = (*head)->next;
		(*head)->prev->next = NULL;
		(*head)->prev = NULL;
		new->prev = *head;
		(*head)->next = new;
	}
}
