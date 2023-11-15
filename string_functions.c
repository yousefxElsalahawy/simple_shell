





#include "shell.h"

/**
 * _increment_while_not_null - Th
 * s function increments a counter while a string is not null
 * @_letter_: This pointer refers to the string to be chked
 * @_OK_: This pointer refers to the counter to be incremented
 *
 * Return: The incremented counter
 */
int _increment_while_not_null(char **_letter_, int *_OK_)
{
	/* use loop */
	while (*(*_letter_)++)
		(*_OK_)++;

	/* This function returns the incremented counter */
	return (*_OK_);
}

/**
 * _str_len_ - This function returns the length of a string
 * @_letter_: This pointer refers to the string whose length to chk
 *
 * Return: The length of the string
 */
int _str_len_(char *_letter_)
{
	int _OK_ = 0;

	/* This function returns the length of the string */
	return ((!_letter_) ? 0 : _increment_while_not_null(&_letter_, &_OK_));
}

/**
 * compare_chars - This function compares two characters
 * @c1: The first character
 * @c2: The second character
 *
 * Return: The _rslt_ of the comparison
 */
int compare_chars(char c1, char c2)
{
	/* use if */
	if (c1 != c2)
		return (c1 - c2);
	else if (c1 == c2)
		return (0);
	else
		return (c1 < c2 ? -1 : 1);
}

/**
 * _str_cmpp_ - This function performs lexicographic comparison of two strings
 * @s1: This pointer refers to the first string
 * @s2: This pointer refers to the second string
 *
 * Return: Negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _str_cmpp_(char *s1, char *s2)
{
	int _rslt_ = 0;

	/* use loop */
	do {
		_rslt_ = compare_chars(*s1, *s2);
		/* use if */
		if (_rslt_ != 0)
			/* This function returns the _rslt_ of the comparison */
			return (_rslt_);
		s1++;
		s2++;
	} while (*s1 && *s2);
	/* This function returns the _rslt_ of the comparison */
	return (compare_chars(*s1, *s2));
}

/**
 * chk_chars - This function chks if two characters are equal
 * @needle: This pointer refers to the first character
 * @haystack: This pointer refers to the second character
 *
 * Return: 1 if the characters are equal, 0 otherwise
 */
int chk_chars(const char **needle, const char **haystack)
{
	/* This function returns the _rslt_ of the chk */
	return ((*(*needle)++ == *(*haystack)++) ? 1 : 0);
}

/**
 * _start_wh_ - This function chks if a string starts with a substring
 * @haystack: This pointer refers to the string to search
 * @needle: This pointer refers to the substring to find
 *
 * Return: Address of _nxt_ character of haystack or NULL
 */
char *_start_wh_(const char *haystack, const char *needle)
{
	const char *temp_needle = needle;
	const char *temp_haystack = haystack;

	/* use loop */
	do {
		/* use if */
		if (!chk_chars(&temp_needle, &temp_haystack))
			/* This function returns NULL if the substring is not found */
			return (NULL);
	} while (*temp_needle);

	/* This function returns the address of the _nxt_ character of haystack */
	return ((char *)temp_haystack);
}

/**
 * find_end - This function finds the end of a string
 * @_txt_: This pointer refers to the string to find the end of
 *
 * Return: Pointer to the end of the string
 */
char *find_end(char *_txt_)
{
	char *end = _txt_;

	/* use loop */
	for (; *end; ++end)
	{
		/*empty*/
	};
	/* This function returns a pointer to the end of the string */
	return (end);
}

/**
 * copy_str - This function copies a string to another string
 * @dest: This pointer refers to the destination string
 * @src: This pointer refers to the source string
 */
void copy_str(char *dest, char *src)
{
	/* use loop */
	for (; *src; ++src, ++dest)
		*dest = *src;
	*dest = '\0';
}

/**
 * _str_catt_ - This function concatenates two strings
 * @dest: This pointer refers to the destination string
 * @src: This pointer refers to the source string
 *
 * Return: Pointer to the destination string
 */
char *_str_catt_(char *dest, char *src)
{
	char *ret = dest;
	char *end_of_dest = find_end(dest);

	copy_str(end_of_dest, src);
	/* This function returns a pointer to the destination string */
	return (ret);
}

