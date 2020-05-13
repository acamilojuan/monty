#include "monty.h"

/**
 * main - program that prints its
 * name, followed by a new line.
 * @argc: argument count
 * @argv: array of strings
 * Return: 0 for success
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
		_error(1)

	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * free_nodes - function that
 * frees a doubly linked list dlist_t.
 * Return: void
 */
void free_nodes(void)
{
	stack_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		/*freeing each node allocated with malloc*/
		free(temp);
	}
	/*frees the last memory allocation*/
	free(head);
}

/**
 * add_node - function that
 * adds a new node at the beginning of a doubly linked list dlist_t.
 * @n: constant int which is the payload (data) in the new node
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_node(const int n)
{
	stack_t *new_node, *first_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		_error(4);

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

/* Edge case when the doubly linked list is NULL*/
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	first_node = *head;
	new_node->next = first_node;
	first_node->prev = new_node;
	*head = new_node;

	return (new_node);
}
