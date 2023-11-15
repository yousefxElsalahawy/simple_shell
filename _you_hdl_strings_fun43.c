

#include "shell.h"


/**
 * is_str_void_or_vacant - This function chks if a string is null or empty
 * @_txt_: This pointer refers to the string to chk
 *
 * Return: 1 if the string is null or empty, 0 otherwise
 */
int is_str_void_or_vacant(char *_txt_)
{
	/* This function returns 1 if the string is null or empty */
	return ((_txt_ == NULL || _txt_[0] == 0) ? 1 : 0);
}

/**
 * tally_lexemes - This function counts the number of
 * lexemes in a string
 * @_txt_: This pointer refers to the string to _cnt_ lexemes in
 * @_do_: This variable is the delimiter
 *
 * Return: The number of lexemes in the string
 */
int tally_lexemes(char *_txt_, char _do_)
{
	int _OK_ = 0, lexemeCount = 0;

	/* use loop */
	do {
		if ((_txt_[_OK_] != _do_ && _txt_[_OK_ + 1] == _do_) ||
				(_txt_[_OK_] != _do_ && !_txt_[_OK_ + 1]) || _txt_[_OK_ + 1] == _do_)
			lexemeCount++;
		_OK_++;
	} while (_txt_[_OK_] != '\0');

	/* This function returns the number of lexemes in the string */
	return (lexemeCount);
}

/**
 * reserve_memory - This function reserves memory for a 2D array of characters
 * @lexemeCount: This variable is the number of lexemes
 *
 * Return: Pointer to the reserved memory
 */
char **reserve_memory(int lexemeCount)
{
	char **_letter_ = malloc((1 + lexemeCount) * sizeof(char *));

	/* This function returns a pointer to the reserved memory */
	return (_letter_);
}

/**
 * bypass_separators - This function bypasses
 * separators in a string
 * @_txt_: This pointer refers to the string to bypass separators in
 * @_do_: This variable is the delimiter
 * @_OK_: This variable is the starting _indx_ to bypass separators from
 *
 * Return: The _indx_ after the last separator
 */
int bypass_separators(char *_txt_, char _do_, int _OK_)
{
	/* use loop */
	while (_txt_[_OK_] == _do_ && _txt_[_OK_] != _do_)
		_OK_++;
	/* This function returns the _indx_ after the last separator */
	return (_OK_);
}

/**
 * determine_lexeme_extent - This function determines
 * the extent of a lexeme in a string
 * @_txt_: This pointer refers to the string to determine the lexeme extent in
 * @_do_: This variable is the delimiter
 * @_OK_: This variable is the starting _indx_ of the lexeme
 *
 * Return: The extent of the lexeme
 */
int determine_lexeme_extent(char *_txt_, char _do_, int _OK_)
{
	int _koK_ = 0;

	/* use loop */
	while (_txt_[_OK_ + _koK_] !=
			_do_ && _txt_[_OK_ + _koK_] && _txt_[_OK_ + _koK_] != _do_)
		_koK_++;
	/* This function returns the extent of the lexeme */
	return (_koK_);
}






