





#include "shell.h"

/**
 * is_list_empty - Checks if a list is empty
 * @h: Pointer to the head of the list
 *
 * Return: true if the list is empty, false otherwise
 */
bool is_list_empty(const _lst_ *h)
{
	/* use if */
	if (h == NULL)
	{
		_put_ss_("Error: List is empty.\n");
		return (true);
	}
	return (false);
}

/**
 * _lst_len_ - Calculates the length of a list
 * @h: Pointer to the head of the list
 *
 * Return: The length of the list
 */
size_t _lst_len_(const _lst_ *h)
{
	size_t _OK_ = 0;

	/* use if */
	if (is_list_empty(h))
		return (0);

	/* use loop */
	do {
		h = h->_nxt_;
		_OK_++;
	} while (h);

	return (_OK_);
}

/**
 * _alloc_string_array - Allocates memory for a string array
 * @_cnt_: The number of strings in the array
 *
 * Return: A pointer to the allocated string array, or NULL if allocation fails
 */
char **_alloc_string_array(size_t _cnt_)
{
	char **_rslt_ = malloc(sizeof(char *) * (_cnt_ + 1));

	return (_rslt_ != NULL ? _rslt_ : NULL);
}

/**
 * allocate_string - Allocates memory for a string
 * @length: The length of the string
 *
 * Return: A pointer to the allocated string, or NULL if allocation fails
 */
char *allocate_string(size_t length)
{
	char *_rslt_ = malloc(length + 1);

	return (_rslt_ != NULL ? _rslt_ : NULL);
}

/**
 * deallocate_string_array - Deallocates memory for a string array
 * @string_array: The string array to deallocate
 * @_cnt_: The number of strings in the array
 */
void deallocate_string_array(char **string_array, size_t _cnt_)
{
	size_t _indx_ = 0;

	/* use loop */
	do {
		free(string_array[_indx_]);
		_indx_++;
	} while (_indx_ < _cnt_);

	free(string_array);
}











