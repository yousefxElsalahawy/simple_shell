

#include "shell.h"

/**
 * delimiter_detector - This function chks if a character is a delimiter
 * @_coco_: This variable is the character to chk
 * @_do_: This pointer refers to the string of delimiters
 *
 * Return: 1 if the character is a delimiter, 0 otherwise
 */
int delimiter_detector(char _coco_, char *_do_)
{
	char *_tmp_ = _do_;

	/* use loop */
	do {
		if (_coco_ == *_tmp_)
			/* This function returns 1 if the character is a delimiter */
			return (1);
	} while (*_tmp_++);

	/* This function returns 0 if the character is not a delimiter */
	return (0);
}

/**
 * lexeme_counter - This function counts the number of lexemes in a string
 * @_txt_: This pointer refers to the string to _cnt_ lexemes in
 * @_do_: This pointer refers to the string of delimiters
 *
 * Return: The number of lexemes in the string
 */
int lexeme_counter(char *_txt_, char *_do_)
{
	int _OK_ = 0, numwords = 0;

	/* use loop */
	while (_txt_[_OK_] != '\0')
	{
		if (!delimiter_detector(_txt_[_OK_], _do_) &&
				(delimiter_detector(_txt_[_OK_ + 1], _do_) || !_txt_[_OK_ + 1]))
			numwords++;
		_OK_++;
	}
	/* This function returns the number of lexemes in the string */
	return (numwords);
}

/**
 * _mem_allocate_ - This function allocates memory for a 2D array of characters
 * @numwords: This variable is the number of words to allocate memory for
 *
 * Return: Pointer to the allocated memory, NULL if memory allocation fails
 */
char **_mem_allocate_(int numwords)
{
	char **_letter_ = (char **)malloc((1 + numwords) * sizeof(char *));

	/* This function returns a pointer to the allocated memory */
	return (_letter_ ? _letter_ : NULL);
}

/**
 * lexeme_length_finder - This function finds the
 * length of a lexeme in a string
 * @_txt_: This pointer refers to the string to find the lexeme length in
 * @_do_: This pointer refers to the string of delimiters
 * @_OK_: This variable is the starting _indx_ of the lexeme
 *
 * Return: The length of the lexeme
 */
int lexeme_length_finder(char *_txt_, char *_do_, int _OK_)
{
	int _koK_ = 0;

	/* use loop */
	while (_txt_[_OK_ + _koK_] && !delimiter_detector(_txt_[_OK_ + _koK_], _do_))
		_koK_++;
	/* This function returns the length of the lexeme */
	return (_koK_);
}

/**
 * memory_liberator - This function frees a 2D array of characters
 * @_letter_: This pointer refers to the 2D array to free
 * @_go_: This variable is the number of words to free
 */
void memory_liberator(char **_letter_, int _go_)
{
	/* use loop */
	do {
		free(_letter_[_go_]);
	} while (_go_--);

	free(_letter_);
}










