#include "monty.h"

/**
 * open_file -  function that opens a file
 * @filename: is a pointer to the name of the file to be opened.
 * Return: void.
 */
void open_file(char *filename)
{
	FILE *fd;

	/*if filename is NULL or  If it’s not possible to open or read the file.*/
	if (!filename)
		_error(2, filename);
	/*OPEN a file in the address filename in READONLY mode.*/
	fd = fopen(filename, "r");
	/*if the file can not be opened or read, error handling (2)*/
	if (fd == NULL)
		_error(2, filename);
	/*READ, the file already opened*/
	read_file(fd);
	/*CLOSE, closes a file descriptor, so that it is not reused in the future*/
	fclose(fd);
}

/**
 * read_file -  function that reads a text file
 * and prints it to the POSIX standard output.
 * @fd: is a pointer to the name of the file to be opened.
 * Return: void.
 */
void read_file(FILE *fd)
{
	char *buffer = NULL;
	int line_number = 1;
	size_t len;
	ssize_t read;
	int data_format;

	/*if the file can not be opened or read, error handling (2)*/
	if (fd == NULL)
		_error(2, filename);
	/*reading an entire line from the file*/
	while ((read = getline(&buffer, &len, fd)) != EOF)
		data_format = line_interpreter(buffer,line_number, data_format);

	free(buffer);
}


void line_interpreter(char *buffer, int line_number, int data_format)
{

		opcode = strtok(buffer," \n\r\a\t");
		if (opcode)
		{
			get_function(opecode, line_number);
		}
}




{
	ssize_t file_descriptor = -1, file_position = 0;
	char *temp_buffer;
	size_t lenght_tempbuff = 0;

	/*if filename is NULL return 0*/
	if (!filename)
		return (0);
	/*Create a temporal buffer to store the data and place on it*/
	temp_buffer = malloc(sizeof(char) * letters);
	if (!temp_buffer)
		return (0);
	/*OPEN a file in the address filename in READONLY mode.*/
	file_descriptor = open(filename, O_RDONLY);
	/*if the file can not be opened or read, return 0*/
	if (file_descriptor == -1)
	{
		free(temp_buffer);
		return (0);
	}
	/*READ, where letters is the number of letters it should read and print*/
	file_position = read(file_descriptor, temp_buffer, letters);
	/*if the file can not be opened or read, return 0*/
	if (file_position == -1)
	{
		free(temp_buffer);
		return (0);
	}
	/*Finding the lenght of the new temporal buffer*/
	while (temp_buffer && temp_buffer[lenght_tempbuff])
		lenght_tempbuff++;
	/*WRITE, writes up to number of bytes (lenght_tempbuff) from the buffer*/
	/*pointed temp_buffer to the STDOUT_FILENO (standard output).*/
	file_position = write(STDOUT_FILENO, temp_buffer, lenght_tempbuff);
	free(temp_buffer);
	/*CLOSE, closes a file descriptor, so that it is not and may be reused.*/
	close(file_descriptor);
	/*if write fails or does not write the expected amount of bytes, return 0*/
	if (file_position == -1)
		return (0);
	return (file_position);
}

/**
 * get_function - checks character to an array of structs.
 * If a successful match is found, the matching function.XCy
 * @s: The incoming character to be evalued by Michael.
 * Return: pointer to a function to format specifier
 */
void *get_function(char *opcode, int line_number)
{
	format_t formats[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"nop", _nop},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};

	int i;

	for (i = 0; formats[i].type != NULL; i++)
	{
		if (*s == *formats[i].type)
			return (formats[i].func);
	}
	exit(1);
}


