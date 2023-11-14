





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
 * lexeme_length_finder - This function finds the length of a lexeme in a string
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

/**
 * word_allocator - This function allocates memory for a word
 * @_koK_: This variable is the length of the word
 *
 * Return: Pointer to the allocated memory, NULL if memory allocation fails
 */
char *word_allocator(int _koK_)
{
	char *word = (char *)malloc((_koK_ + 1) * sizeof(char));

	/* This function returns a pointer to the allocated memory */
	return (word ? word : NULL);
}

/**
 * lexeme_copier - This function copies a lexeme to another string
 * @dest: This pointer refers to the destination string
 * @src: This pointer refers to the source string
 * @_long_: This variable is the length of the lexeme
 */
void lexeme_copier(char *dest, char *src, int _long_)
{
	int m = 0;

	/* use loop */
	do {
		dest[m] = src[m];
	} while (++m < _long_);
	dest[m] = '\0';
}

/**
 * _str_foo_ - This function splits a string into words
 * @_txt_: This pointer refers to the string to split
 * @_do_: This pointer refers to the string of delimiters
 *
 * Return: Pointer to the 2D array of words, NULL if the string is empty or memory allocation fails
 */
char **_str_foo_(char *_txt_, char *_do_)
{
	int _OK_ = 0, _go_ = 0, _koK_, numwords;

	char **_letter_;

	if (!_txt_ || !_txt_[0] || !(_do_ = _do_ ? _do_ : " ") ||
			!(numwords = lexeme_counter(_txt_, _do_)) || !(_letter_ = _mem_allocate_(numwords)))
		/* This function returns NULL if the string is empty or memory allocation fails */
		return (NULL);

	/* use loop */
	do {
		while (delimiter_detector(_txt_[_OK_], _do_))
			_OK_++;
		_koK_ = lexeme_length_finder(_txt_, _do_, _OK_);
		if (!(_letter_[_go_] = word_allocator(_koK_)))
		{
			memory_liberator(_letter_, _go_);
			/* This function returns NULL if memory allocation fails */
			return (NULL);
		}
		lexeme_copier(_letter_[_go_], _txt_ + _OK_, _koK_);
		_OK_ += _koK_;
	} while (_go_++, _go_ < numwords);

	_letter_[_go_] = NULL;
	/* This function returns a pointer to the 2D array of words */
	return (_letter_);
}

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
 * tally_lexemes - This function counts the number of lexemes in a string
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
 * bypass_separators - This function bypasses separators in a string
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
 * determine_lexeme_extent - This function determines the extent of a lexeme in a string
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
	while (_txt_[_OK_ + _koK_] != _do_ && _txt_[_OK_ + _koK_] && _txt_[_OK_ + _koK_] != _do_)
		_koK_++;
	/* This function returns the extent of the lexeme */
	return (_koK_);
}

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
 * relinquish_memory - This function relinquishes memory of a 2D array of characters
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
 * replicate_lexeme - This function replicates a lexeme to a 2D array of characters
 * @_letter_: This pointer refers to the 2D array to replicate the lexeme to
 * @_txt_: This pointer refers to the string to replicate the lexeme from
 * @_go_: This variable is the _indx_ of the lexeme in the 2D array
 * @_koK_: This variable is the extent of the lexeme
 * @_OK_: This pointer refers to the _indx_ of the lexeme in the string
 */
void replicate_lexeme(char **_letter_, char *_txt_, int _go_, int _koK_, int *_OK_)
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



