#ifndef _MONTY_H
#define _MONTY_H
 
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
 
extern stack_t *head;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
 
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
 
/*----------main--------------*/
stack_t *add_node(const int n);
void free_nodes(void);
/*-----stack_operations-------*/
void _push(stack_t **head, unsigned int line_number);
void _pall(stack_t **head, unsigned int line_number);
void _pint(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);
/*-----math_operations-------*/
void _add(stack_t **head, unsigned int line_number);
void _sub(stack_t **head, unsigned int line_number);
void _div(stack_t **head, unsigned int line_number);
void _mul(stack_t **head, unsigned int line_number);
void _mod(stack_t **head, unsigned int line_number);
/*-----string_operations-------*/
void _nop(stack_t **head, unsigned int line_number);
void _pchar(stack_t **head, unsigned int line_number);
void _pstr(stack_t **head, unsigned int line_number);
/*-----stack_operations2-------*/
void _rotl(stack_t **head, unsigned int line_number);
void _rotr(stack_t **head, unsigned int line_number);
void _stack(stack_t **head, unsigned int line_number);
void _queue(stack_t **head, unsigned int line_number);
/*-------error_handler--------*/
void _error1(int error_code, ...);
void _error2(int error_code, ...);
/**
 * (1) If the user doesn't give any file or more than one argument is sent.
 * (2): If it’s not possible to open or read the file.
 * (3): If the file contains an invalid instruction.
 * (4): If the program can’t malloc anymore.
 * (5): If parameter given to push is not an integer.
 * (6): If there is no argument given to push.
 * (7): If the stack is empty for pint.
 * (8): If the stack is empty for pop.
 * (9): If the stack contains less than 2 elements.
 * (10): If the top element of the stack is 0, div or mod by 0 is not allowed.
 * (11): If the value in the node is not in the ascii table.
 * (12): If the stack is empty for pchar.
 * /
 
 
#endif
