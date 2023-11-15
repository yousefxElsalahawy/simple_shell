





#include "shell.h"

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


