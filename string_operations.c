#include "monty.h"
 
/**
 * _nop - doesn’t do anything.
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
void _nop(stack_t **stack, unsigned int line_number);
{
 
}
 
/**
 * _pchar -  prints the char at the top of the stack,
 * followed by a new line.
 * The integer stored at the top of the stack is treated as
 * the ascii value of the character to be printed.
 * If the value is not in the ascii table handle error with _error(11)
 * If the stack is empty, handle error with _error(12)
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
void _pchar(stack_t **stack, unsigned int line_number);
{
 
}
 
/**
 * _pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * The integer stored in each element of the stack is treated as
 * the ascii value of the character to be printed.
 * The string stops when either:
 * - the stack is over
 * - the value of the element is 0
 * - the value of the element is not in the ascii table
 * If the stack is empty, print only a new line
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
void _pstr(stack_t **stack, unsigned int line_number);
{
 
 
}
