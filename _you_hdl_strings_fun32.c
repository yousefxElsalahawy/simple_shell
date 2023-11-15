



#include "shell.h"

/**
 * chk_char - This function chks if a character is equal to another character
 * @_letter_: This pointer refers to the character to chk
 * @_coco_: This variable is the character to compare with
 *
 * Return: Pointer to the character if it is
 * equal to the other character, NULL otherwise
 */
char *chk_char(char *_letter_, char _coco_)
{
	/*returns a pointer to the character if it is equal to the other character */
	return ((*_letter_ == _coco_) ? _letter_ : NULL);
}

/**
 * _str_n_chr - This function finds the first
 * occurrence of a character in a string
 * @_letter_: This pointer refers to the string to search
 * @_coco_: This variable is the character to find
 *
 * Return: Pointer to the first occurrence of the character,
 * NULL if the character is not found
 */
char *_str_n_chr(char *_letter_, char _coco_)
{
	char *_rslt_ = NULL;

	/* use loop */
	do {
		_rslt_ = chk_char(_letter_, _coco_);

		/* use if */
		if (_rslt_ != NULL)
			/* This functionence of the character */
			return (_rslt_);

	} while (*_letter_++ != '\0');

	/* This function returns NULL if the character is not found */
	return (_rslt_);
}









/**
 * _str_n_cat - This function concatenates two strings
 * @dest: This pointer refers to the destination string
 * @src: This pointer refers to the source string
 * @n: This variable is the maximum number of characters to concatenate
 *
 * Return: Pointer to the destination string
 */
char *_str_n_cat(char *dest, char *src, int n)
{
	int Q = find_length(dest); /* find the length of the destination string */

	cpy_chars(dest, src, Q, n); /* copy characters from source to destination */

	/* This function returns a pointer to the destination string */
	return (dest);
}


