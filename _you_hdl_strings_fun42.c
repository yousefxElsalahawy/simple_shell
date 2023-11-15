

#include "shell.h"



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
 * input_checker - This function checks the input parameters
 * @_txt_: This pointer refers to the input text
 * @_do_: This pointer refers to the delimiter
 * @numwords: This variable is used to store the number of words in the text
 *
 * Return: 0 if successful, -1 if there is an error
 */
int input_checker(char **_txt_, char **_do_, int *numwords)
{
	int condition1 = !*_txt_ || !(*_txt_)[0];
	int condition2 = !*_do_;
	int condition3 = !(*numwords = lexeme_counter(*_txt_, *_do_));

	/* use if */
	if (condition1)
	{
		/* This function returns -1 if there is an error */
		return (-1);
	}
	if (condition2)
		*_do_ = " ";
	if (condition3)
		/* This function returns -1 if there is an error */
		return (-1);
	/* This function returns 0 if successful */
	return (0);
}

/**
 * memory_allocator_and_word_copier -
 * This function allocates memory and copies words
 * @_txt_: This pointer refers to the input text
 * @_do_: This pointer refers to the delimiter
 * @numwords: This variable is used to store the number
 * of words in the text
 *
 * Return: pointer to the 2D array of words if successful,
 * NULL if there is an error
 */
char **memory_allocator_and_word_copier(char *_txt_, char *_do_, int numwords)
{
	int _OK_ = 0, _go_ = 0, _koK_;
	int condition;
	char **_letter_ = _mem_allocate_(numwords);


	/* use loop */
	do {
		while (delimiter_detector(_txt_[_OK_], _do_))
			_OK_++;
		_koK_ = lexeme_length_finder(_txt_, _do_, _OK_);
		/* use if */

		condition = !(_letter_[_go_] = word_allocator(_koK_));
		if (condition)
		{
			memory_liberator(_letter_, _go_);
			/* This function returns NULL if there is an error */
			return (NULL);
		}
		lexeme_copier(_letter_[_go_], _txt_ + _OK_, _koK_);
		_OK_ += _koK_;
	} while (_go_++, _go_ < numwords);
	_letter_[_go_] = NULL;
	/* This function returns pointer to the 2D array of words if successful */
	return (_letter_);
}

/**
 * _str_foo_ - This function splits the input text into words
 * @_txt_: This pointer refers to the input text
 * @_do_: This pointer refers to the delimiter
 *
 * Return: pointer to the 2D array of words if successful,
 * NULL if there is an error
 */
char **_str_foo_(char *_txt_, char *_do_)
{
	int numwords;
	char **_letter_;
	int condition;

	condition = input_checker(&_txt_, &_do_, &numwords);

	switch (condition)
	{
		case -1:
			/* This function returns NULL if there is an error */
			return (NULL);
		default:
			_letter_ = memory_allocator_and_word_copier(_txt_, _do_, numwords);
			/* This functiarray of words if successful */
			return (_letter_);
	}
}














