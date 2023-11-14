#include "shell.h"

/**
 * is_null - Checks if a pointer is null.
 * @ptr: Address of the pointer to check.
 *
 * Return: 1 if the pointer is null, otherwise 0.
 */
int is_null(void **ptr)
{
	/*use if */
	return (!ptr || !*ptr ? 1 : 0);
}

/**
 * free_and_nullify - Frees a pointer and sets it to NULL.
 * @ptr: Address of the pointer to free.
 */
void free_and_nullify(void **ptr)
{
	/*free for ptr */
	free(*ptr);
	*ptr = NULL;
}

/**
 * bfree - Frees a pointer and sets it to NULL if it is not null.
 * @ptr: Address of the pointer to free.
 *
 * Return: 1 if the pointer was freed, otherwise 0.
 */
int bfree(void **ptr)
{
	/*use if */
	return (is_null(ptr) ? 0 : (free_and_nullify(ptr), 1));
}

