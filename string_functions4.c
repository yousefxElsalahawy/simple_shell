#include "shell.h"

/**
 * delimiter_detector - This function checks if a character is a delimiter
 * @c: This variable is the character to check
 * @d: This pointer refers to the string of delimiters
 *
 * Return: 1 if the character is a delimiter, 0 otherwise
 */
int delimiter_detector(char c, char *d)
{
	char *temp = d;

	/* use loop */
	do {
		if (c == *temp)
			/* This function returns 1 if the character is a delimiter */
			return (1);
	} while (*temp++);

	/* This function returns 0 if the character is not a delimiter */
	return (0);
}

/**
 * lexeme_counter - This function counts the number of lexemes in a string
 * @str: This pointer refers to the string to count lexemes in
 * @d: This pointer refers to the string of delimiters
 *
 * Return: The number of lexemes in the string
 */
int lexeme_counter(char *str, char *d)
{
	int i = 0, numwords = 0;

	/* use loop */
	while (str[i] != '\0')
	{
		if (!delimiter_detector(str[i], d) &&
			(delimiter_detector(str[i + 1], d) || !str[i + 1]))
			numwords++;
		i++;
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
	char **s = (char **)malloc((1 + numwords) * sizeof(char *));

	/* This function returns a pointer to the allocated memory */
	return (s ? s : NULL);
}

/**
 * lexeme_length_finder - This function finds the length of a lexeme in a string
 * @str: This pointer refers to the string to find the lexeme length in
 * @d: This pointer refers to the string of delimiters
 * @i: This variable is the starting index of the lexeme
 *
 * Return: The length of the lexeme
 */
int lexeme_length_finder(char *str, char *d, int i)
{
	int k = 0;

	/* use loop */
	while (str[i + k] && !delimiter_detector(str[i + k], d))
		k++;
	/* This function returns the length of the lexeme */
	return (k);
}

/**
 * memory_liberator - This function frees a 2D array of characters
 * @s: This pointer refers to the 2D array to free
 * @j: This variable is the number of words to free
 */
void memory_liberator(char **s, int j)
{
	/* use loop */
	do {
		free(s[j]);
	} while (j--);

	free(s);
}

/**
 * word_allocator - This function allocates memory for a word
 * @k: This variable is the length of the word
 *
 * Return: Pointer to the allocated memory, NULL if memory allocation fails
 */
char *word_allocator(int k)
{
	char *word = (char *)malloc((k + 1) * sizeof(char));

	/* This function returns a pointer to the allocated memory */
	return (word ? word : NULL);
}

/**
 * lexeme_copier - This function copies a lexeme to another string
 * @dest: This pointer refers to the destination string
 * @src: This pointer refers to the source string
 * @len: This variable is the length of the lexeme
 */
void lexeme_copier(char *dest, char *src, int len)
{
	int m = 0;

	/* use loop */
	do {
		dest[m] = src[m];
	} while (++m < len);
	dest[m] = '\0';
}

/**
 * strtow - This function splits a string into words
 * @str: This pointer refers to the string to split
 * @d: This pointer refers to the string of delimiters
 *
 * Return: Pointer to the 2D array of words, NULL if the string is empty or memory allocation fails
 */
char **strtow(char *str, char *d)
{
	int i = 0, j = 0, k, numwords;

	char **s;

	if (!str || !str[0] || !(d = d ? d : " ") ||
		!(numwords = lexeme_counter(str, d)) || !(s = _mem_allocate_(numwords)))
		/* This function returns NULL if the string is empty or memory allocation fails */
		return (NULL);

	/* use loop */
	do {
		while (delimiter_detector(str[i], d))
			i++;
		k = lexeme_length_finder(str, d, i);
		if (!(s[j] = word_allocator(k)))
		{
			memory_liberator(s, j);
			/* This function returns NULL if memory allocation fails */
			return (NULL);
		}
		lexeme_copier(s[j], str + i, k);
		i += k;
	} while (j++, j < numwords);

	s[j] = NULL;
	/* This function returns a pointer to the 2D array of words */
	return (s);
}

/**
 * is_str_void_or_vacant - This function checks if a string is null or empty
 * @str: This pointer refers to the string to check
 *
 * Return: 1 if the string is null or empty, 0 otherwise
 */
int is_str_void_or_vacant(char *str)
{
	/* This function returns 1 if the string is null or empty */
	return ((str == NULL || str[0] == 0) ? 1 : 0);
}

/**
 * tally_lexemes - This function counts the number of lexemes in a string
 * @str: This pointer refers to the string to count lexemes in
 * @d: This variable is the delimiter
 *
 * Return: The number of lexemes in the string
 */
int tally_lexemes(char *str, char d)
{
	int i = 0, lexemeCount = 0;

	/* use loop */
	do {
		if ((str[i] != d && str[i + 1] == d) ||
			(str[i] != d && !str[i + 1]) || str[i + 1] == d)
			lexemeCount++;
		i++;
	} while (str[i] != '\0');

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
	char **s = malloc((1 + lexemeCount) * sizeof(char *));

	/* This function returns a pointer to the reserved memory */
	return (s);
}

/**
 * bypass_separators - This function bypasses separators in a string
 * @str: This pointer refers to the string to bypass separators in
 * @d: This variable is the delimiter
 * @i: This variable is the starting index to bypass separators from
 *
 * Return: The index after the last separator
 */
int bypass_separators(char *str, char d, int i)
{
	/* use loop */
	while (str[i] == d && str[i] != d)
		i++;
	/* This function returns the index after the last separator */
	return (i);
}

/**
 * determine_lexeme_extent - This function determines the extent of a lexeme in a string
 * @str: This pointer refers to the string to determine the lexeme extent in
 * @d: This variable is the delimiter
 * @i: This variable is the starting index of the lexeme
 *
 * Return: The extent of the lexeme
 */
int determine_lexeme_extent(char *str, char d, int i)
{
	int k = 0;

	/* use loop */
	while (str[i + k] != d && str[i + k] && str[i + k] != d)
		k++;
	/* This function returns the extent of the lexeme */
	return (k);
}

/**
 * reserve_lexeme - This function reserves memory for a lexeme
 * @k: This variable is the extent of the lexeme
 *
 * Return: Pointer to the reserved memory
 */
char *reserve_lexeme(int k)
{
	char *lexeme = malloc((k + 1) * sizeof(char));

	/* This function returns a pointer to the reserved memory */
	return (lexeme);
}

/**
 * relinquish_memory - This function relinquishes memory of a 2D array of characters
 * @s: This pointer refers to the 2D array to relinquish memory of
 * @j: This variable is the number of lexemes
 */
void relinquish_memory(char **s, int j)
{
	int k;

	/* use loop */
	for (k = 0; k < j; k++)
		free(s[k]);
	free(s);
}

/**
 * replicate_lexeme - This function replicates a lexeme to a 2D array of characters
 * @s: This pointer refers to the 2D array to replicate the lexeme to
 * @str: This pointer refers to the string to replicate the lexeme from
 * @j: This variable is the index of the lexeme in the 2D array
 * @k: This variable is the extent of the lexeme
 * @i: This pointer refers to the index of the lexeme in the string
 */
void replicate_lexeme(char **s, char *str, int j, int k, int *i)
{
	int m = 0;

	/* use loop */
	do {
		s[j][m] = str[(*i)++];
	} while (++m < k);
	s[j][m] = 0;
}

/**
 * strtow2 - This function splits a string into words
 * @str: This pointer refers to the string to split
 * @d: This variable is the delimiter
 *
 * Return: Pointer to the 2D array of words, NULL  fails
 */
char **strtow2(char *str, char d)
{
	int i = 0, j = 0, k, lexemeCount;
	char **s;

	if (is_str_void_or_vacant(str))
		/* This function returns NULL if the string is null or empty */
		return (NULL);

	lexemeCount = tally_lexemes(str, d);
	if (lexemeCount == 0)
		/* This function returns NULL if there are no lexemes in the string */
		return (NULL);
	s = reserve_memory(lexemeCount);
	if (!s)
		/* This function returns NULL if memory allocation fails */
		return (NULL);
	/* use loop */
	do {
		i = bypass_separators(str, d, i);
		k = determine_lexeme_extent(str, d, i);
		s[j] = reserve_lexeme(k);
		if (!s[j])
		{
			relinquish_memory(s, j);
			/* This function returns NULL if memory allocation fails */
			return (NULL);
		}
		replicate_lexeme(s, str, j, k, &i);
	} while (++j < lexemeCount);
	s[j] = NULL;
	/* This function returns a pointer to the 2D array of words */
	return (s);
}
