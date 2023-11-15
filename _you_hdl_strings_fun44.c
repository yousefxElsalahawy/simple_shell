



#include "shell.h"


/**
 * reserve_lexeme - This function reserves memory for a lexeme
 * @_koK_: This variable is the extent of the lexeme
 *
 * Return: Pointer to the reserved memory
 */
char *reserve_lexeme(int _koK_)
{
	char *lexeme = malloc((_koK_ + 1) * sizeof(char));

	/* This function returns a pointer to the reserved memory */
	return (lexeme);
}

/**
 * relinquish_memory - This function relinquishes
 * memory of a 2D array of characters
 * @_letter_: This pointer refers to the 2D array to relinquish memory of
 * @_go_: This variable is the number of lexemes
 */
void relinquish_memory(char **_letter_, int _go_)
{
	int _koK_;

	/* use loop */
	for (_koK_ = 0; _koK_ < _go_; _koK_++)
		free(_letter_[_koK_]);
	free(_letter_);
}

/**
 * replicate_lexeme - This function replicates a lexeme
 * to a 2D array of characters
 * @_letter_: This pointer refers to the 2D array to replicate the lexeme to
 * @_txt_: This pointer refers to the string to replicate the lexeme from
 * @_go_: This variable is the _indx_ of the lexeme in the 2D array
 * @_koK_: This variable is the extent of the lexeme
 * @_OK_: This pointer refers to the _indx_ of the lexeme in the string
 */
void replicate_lexeme(char **_letter_, char *_txt_,
		int _go_, int _koK_, int *_OK_)
{
	int m = 0;

	/* use loop */
	do {
		_letter_[_go_][m] = _txt_[(*_OK_)++];
	} while (++m < _koK_);
	_letter_[_go_][m] = 0;
}

/**
 * _str_foo2_ - This function splits a string into words
 * @_txt_: This pointer refers to the string to split
 * @_do_: This variable is the delimiter
 *
 * Return: Pointer to the 2D array of words, NULL  fails
 */
char **_str_foo2_(char *_txt_, char _do_)
{
	int _OK_ = 0, _go_ = 0, _koK_, lexemeCount;
	char **_letter_;

	if (is_str_void_or_vacant(_txt_))
		/* This function returns NULL if the string is null or empty */
		return (NULL);

	lexemeCount = tally_lexemes(_txt_, _do_);
	if (lexemeCount == 0)
		/* This function returns NULL if there are no lexemes in the string */
		return (NULL);
	_letter_ = reserve_memory(lexemeCount);
	if (!_letter_)
		/* This function returns NULL if memory allocation fails */
		return (NULL);
	/* use loop */
	do {
		_OK_ = bypass_separators(_txt_, _do_, _OK_);
		_koK_ = determine_lexeme_extent(_txt_, _do_, _OK_);
		_letter_[_go_] = reserve_lexeme(_koK_);
		if (!_letter_[_go_])
		{
			relinquish_memory(_letter_, _go_);
			/* This function returns NULL if memory allocation fails */
			return (NULL);
		}
		replicate_lexeme(_letter_, _txt_, _go_, _koK_, &_OK_);
	} while (++_go_ < lexemeCount);
	_letter_[_go_] = NULL;
	/* This function returns a pointer to the 2D array of words */
	return (_letter_);
}





