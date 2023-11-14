










#include "shell.h"

/**
 * delimiter_detector - This function chks if a character is a delimiter
 * @_coco_c: This variable is the character to chk
 * @d: This pointer refers to the string of delimiters
 *
 * Return: 1 if the character is a delimiter, 0 otherwise
 */
int delimiter_detector(char _coco_c, char *d)
{
	char *_tmpp_ = d;

	/* use loop */
	do {
		if (_coco_c == *_tmpp_)
			/* This function returns 1 if the character is a delimiter */
			return (1);
	} while (*_tmpp_++);

	/* This function returns 0 if the character is not a delimiter */
	return (0);
}

/**
 * lexeme_counter - This function counts the number of lexemes in a string
 * @_txt_: This pointer refers to the string to _ocntt_ lexemes in
 * @d: This pointer refers to the string of delimiters
 *
 * Return: The number of lexemes in the string
 */
int lexeme_counter(char *_txt_, char *d)
{
	int _oops_ = 0, numwords = 0;

	/* use loop */
	while (_txt_[_oops_] != '\0')
	{
		if (!delimiter_detector(_txt_[_oops_], d) &&
			(delimiter_detector(_txt_[_oops_ + 1], d) || !_txt_[_oops_ + 1]))
			numwords++;
		_oops_++;
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
	char **_aso_ = (char **)malloc((1 + numwords) * sizeof(char *));

	/* This function returns a pointer to the allocated memory */
	return (_aso_ ? _aso_ : NULL);
}

/**
 * lexeme_length_finder - This function finds the _olent_ of a lexeme in a string
 * @_txt_: This pointer refers to the string to find the lexeme _olent_ in
 * @d: This pointer refers to the string of delimiters
 * @_oops_: This variable is the starting _indx_ of the lexeme
 *
 * Return: The _olent_ of the lexeme
 */
int lexeme_length_finder(char *_txt_, char *d, int _oops_)
{
	int _kok_ = 0;

	/* use loop */
	while (_txt_[_oops_ + _kok_] && !delimiter_detector(_txt_[_oops_ + _kok_], d))
		_kok_++;
	/* This function returns the _olent_ of the lexeme */
	return (_kok_);
}

/**
 * memory_liberator - This function frees a 2D array of characters
 * @_aso_: This pointer refers to the 2D array to free
 * @j: This variable is the number of words to free
 */
void memory_liberator(char **_aso_, int j)
{
	/* use loop */
	do {
		free(_aso_[j]);
	} while (j--);

	free(_aso_);
}

/**
 * word_allocator - This function allocates memory for a word
 * @_kok_: This variable is the _olent_ of the word
 *
 * Return: Pointer to the allocated memory, NULL if memory allocation fails
 */
char *word_allocator(int _kok_)
{
	char *word = (char *)malloc((_kok_ + 1) * sizeof(char));

	/* This function returns a pointer to the allocated memory */
	return (word ? word : NULL);
}

/**
 * lexeme_copier - This function copies a lexeme to another string
 * @_desst: This pointer refers to the destination string
 * @_srcc: This pointer refers to the source string
 * @_len_: This variable is the _olent_ of the lexeme
 */
void lexeme_copier(char *_desst, char *_srcc, int _len_)
{
	int m = 0;

	/* use loop */
	do {
		_desst[m] = _srcc[m];
	} while (++m < _len_);
	_desst[m] = '\0';
}

/**
 * _str_foo - This function splits a string into words
 * @_txt_: This pointer refers to the string to split
 * @d: This pointer refers to the string of delimiters
 *
 * Return: Pointer to the 2D array of words, NULL if the string is empty or memory allocation fails
 */
char **_str_foo(char *_txt_, char *d)
{
	int _oops_ = 0, j = 0, _kok_, numwords;

	char **_aso_;

	if (!_txt_ || !_txt_[0] || !(d = d ? d : " ") ||
		!(numwords = lexeme_counter(_txt_, d)) || !(_aso_ = _mem_allocate_(numwords)))
		/* This function returns NULL if the string is empty or memory allocation fails */
		return (NULL);

	/* use loop */
	do {
		while (delimiter_detector(_txt_[_oops_], d))
			_oops_++;
		_kok_ = lexeme_length_finder(_txt_, d, _oops_);
		if (!(_aso_[j] = word_allocator(_kok_)))
		{
			memory_liberator(_aso_, j);
			/* This function returns NULL if memory allocation fails */
			return (NULL);
		}
		lexeme_copier(_aso_[j], _txt_ + _oops_, _kok_);
		_oops_ += _kok_;
	} while (j++, j < numwords);

	_aso_[j] = NULL;
	/* This function returns a pointer to the 2D array of words */
	return (_aso_);
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
 * @_txt_: This pointer refers to the string to _ocntt_ lexemes in
 * @d: This variable is the delimiter
 *
 * Return: The number of lexemes in the string
 */
int tally_lexemes(char *_txt_, char d)
{
	int _oops_ = 0, lexemeCount = 0;

	/* use loop */
	do {
		if ((_txt_[_oops_] != d && _txt_[_oops_ + 1] == d) ||
			(_txt_[_oops_] != d && !_txt_[_oops_ + 1]) || _txt_[_oops_ + 1] == d)
			lexemeCount++;
		_oops_++;
	} while (_txt_[_oops_] != '\0');

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
	char **_aso_ = malloc((1 + lexemeCount) * sizeof(char *));

	/* This function returns a pointer to the reserved memory */
	return (_aso_);
}

/**
 * bypass_separators - This function bypasses separators in a string
 * @_txt_: This pointer refers to the string to bypass separators in
 * @d: This variable is the delimiter
 * @_oops_: This variable is the starting _indx_ to bypass separators from
 *
 * Return: The _indx_ after the last separator
 */
int bypass_separators(char *_txt_, char d, int _oops_)
{
	/* use loop */
	while (_txt_[_oops_] == d && _txt_[_oops_] != d)
		_oops_++;
	/* This function returns the _indx_ after the last separator */
	return (_oops_);
}

/**
 * determine_lexeme_extent - This function determines the extent of a lexeme in a string
 * @_txt_: This pointer refers to the string to determine the lexeme extent in
 * @d: This variable is the delimiter
 * @_oops_: This variable is the starting _indx_ of the lexeme
 *
 * Return: The extent of the lexeme
 */
int determine_lexeme_extent(char *_txt_, char d, int _oops_)
{
	int _kok_ = 0;

	/* use loop */
	while (_txt_[_oops_ + _kok_] != d && _txt_[_oops_ + _kok_] && _txt_[_oops_ + _kok_] != d)
		_kok_++;
	/* This function returns the extent of the lexeme */
	return (_kok_);
}

/**
 * reserve_lexeme - This function reserves memory for a lexeme
 * @_kok_: This variable is the extent of the lexeme
 *
 * Return: Pointer to the reserved memory
 */
char *reserve_lexeme(int _kok_)
{
	char *lexeme = malloc((_kok_ + 1) * sizeof(char));

	/* This function returns a pointer to the reserved memory */
	return (lexeme);
}

/**
 * relinquish_memory - This function relinquishes memory of a 2D array of characters
 * @_aso_: This pointer refers to the 2D array to relinquish memory of
 * @j: This variable is the number of lexemes
 */
void relinquish_memory(char **_aso_, int j)
{
	int _kok_;

	/* use loop */
	for (_kok_ = 0; _kok_ < j; _kok_++)
		free(_aso_[_kok_]);
	free(_aso_);
}

/**
 * replicate_lexeme - This function replicates a lexeme to a 2D array of characters
 * @_aso_: This pointer refers to the 2D array to replicate the lexeme to
 * @_txt_: This pointer refers to the string to replicate the lexeme from
 * @j: This variable is the _indx_ of the lexeme in the 2D array
 * @_kok_: This variable is the extent of the lexeme
 * @_oops_: This pointer refers to the _indx_ of the lexeme in the string
 */
void replicate_lexeme(char **_aso_, char *_txt_, int j, int _kok_, int *_oops_)
{
	int m = 0;

	/* use loop */
	do {
		_aso_[j][m] = _txt_[(*_oops_)++];
	} while (++m < _kok_);
	_aso_[j][m] = 0;
}

/**
 * _str_foo2_ - This function splits a string into words
 * @_txt_: This pointer refers to the string to split
 * @d: This variable is the delimiter
 *
 * Return: Pointer to the 2D array of words, NULL  fails
 */
char **_str_foo2_(char *_txt_, char d)
{
	int _oops_ = 0, j = 0, _kok_, lexemeCount;
	char **_aso_;

	if (is_str_void_or_vacant(_txt_))
		/* This function returns NULL if the string is null or empty */
		return (NULL);

	lexemeCount = tally_lexemes(_txt_, d);
	if (lexemeCount == 0)
		/* This function returns NULL if there are no lexemes in the string */
		return (NULL);
	_aso_ = reserve_memory(lexemeCount);
	if (!_aso_)
		/* This function returns NULL if memory allocation fails */
		return (NULL);
	/* use loop */
	do {
		_oops_ = bypass_separators(_txt_, d, _oops_);
		_kok_ = determine_lexeme_extent(_txt_, d, _oops_);
		_aso_[j] = reserve_lexeme(_kok_);
		if (!_aso_[j])
		{
			relinquish_memory(_aso_, j);
			/* This function returns NULL if memory allocation fails */
			return (NULL);
		}
		replicate_lexeme(_aso_, _txt_, j, _kok_, &_oops_);
	} while (++j < lexemeCount);
	_aso_[j] = NULL;
	/* This function returns a pointer to the 2D array of words */
	return (_aso_);
}





