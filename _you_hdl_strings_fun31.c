

#include "shell.h"

/**
 * _copy_chars_ - This function copies a string to another string
 * @_desst: This pointer refers to the destination string
 * @_srcc: This pointer refers to the source string
 * @n: This variable is the maximum number of characters to copy
 *
 * Return: Pointer to the destination string
 */
char *_copy_chars_(char *_desst, char *_srcc, int n)
{
	int Q = 0;

	/* use loop */
	while (_srcc[Q] != '\0' && Q < n - 1)
	{
		_desst[Q] = _srcc[Q];
		Q++;
	}
	_desst[Q] = '\0';

	/* This function returns a pointer to the destination string */
	return (_desst);
}

/**
 * fill_remaining_with_null - This function fills
 * the remaining characters of a string with null
 * @_desst: This pointer refers to the string to fill
 * @start: This variable is the starting _indx_ to fill
 * @n: This variable is the maximum number of characters to fill
 *
 * Return: Pointer to the filled string
 */
char *fill_remaining_with_null(char *_desst, int start, int n)
{
	int _go_ = start;

	/* use loop */
	do {
		_desst[_go_] = '\0';
		_go_++;
	} while (_go_ < n);

	/* This function returns a pointer to the filled string */
	return (_desst);
}

/**
 * _strr_ncpy_ - This function copies a string to another string
 * @_desst: This pointer refers to the destination string
 * @_srcc: This pointer refers to the source string
 * @n: This variable is the maximum number of characters to copy
 *
 * Return: Pointer to the destination string
 */
char *_strr_ncpy_(char *_desst, char *_srcc, int n)
{
	char *_letter_ = _desst;
	int Q;

	_letter_ = _copy_chars_(_letter_, _srcc, n);

	Q = _str_len_(_letter_);

	_letter_ = (n < Q) ?
		fill_remaining_with_null(_letter_, Q, n) : _letter_;
	/* This function returns a pointer to the destination string */
	return (_letter_);
}

/**
 * find_length - This function finds the length of a string
 * @_txt_: This pointer refers to the string to find the length of
 *
 * Return: The length of the string
 */
int find_length(char *_txt_)
{
	int Q = 0;

	/* use loop */
	do {
		Q++;
	} while (_txt_[Q] != '\0');
	/* This function returns the length of the string */
	return (Q - 1);
}

/**
 * cpy_chars - This function copies a string to another string
 * @_desst: This pointer refers to the destination string
 * @_srcc: This pointer refers to the source string
 * @start: This variable is the starting _indx_ to copy
 * @n: This variable is the maximum number of characters to copy
 */
void cpy_chars(char *_desst, char *_srcc, int start, int n)
{
	int _go_ = 0;

	/* use loop */
	do {
		_desst[start + _go_] = _srcc[_go_];
		_go_++;
	} while (_srcc[_go_] != '\0' && _go_ < n);

	_desst[start + _go_] = (_go_ < n) ? '\0' : _desst[start + _go_];
}








