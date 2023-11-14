#include "shell.h"

/**
 * interactive - Checks if the shell is interactive
 * @info: This pointer refers to the Info Struct
 *
 * Return: 1 (interactive), 0 (non-interactive)
 */
int interactive(info_t *info)
{
	int result;
	int is_interactive = isatty(STDIN_FILENO); /*use if */

	int is_readfd_valid = info->readfd <= 2; /*use if */

	result = is_interactive && is_readfd_valid; /*use if */

	return (result); /* Returns 1 if interactive, 0 if not */
}

/**
 * _CHEcK_chARs_ - Checks if a character is in a string
 * @c: Character to check
 * @temp: String to check in
 *
 * Return: 1 (character is in string), 0 (character is not in string)
 */
int _CHEcK_chARs_(char c, char *temp)
{
	while (*temp) /*use loop */
	{
		if (c == *temp++) /*use if */
		{
			return (1); /* Returns 1 if character is in string */
		}
	}
	return (0); /* Returns 0 if character is not in string */
}

/**
 * is_delim - Checks if a character is a delimiter
 * @c: Character to check
 * @delim: Delimiter to check against
 *
 * Return: 1 (is delimiter), 0 (is not delimiter)
 */
int is_delim(char c, char *delim)
{
	return (_CHEcK_chARs_(c, delim)); /* Returns 1 if is delimiter, 0 if not */
}

/**
 * _islower - Checks if a character is lowercase
 * @c: Character to check
 *
 * Return: 1 (is lowercase), 0 (is not lowercase)
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z') /*use if */
		return (1); /* Returns 1 if character is lowercase */
	else
		return (0); /* Returns 0 if character is not lowercase */
}

/**
 * _isupper - Checks if a character is uppercase
 * @c: Character to check
 *
 * Return: 1 (is uppercase), 0 (is not uppercase)
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z') /*use if */
		return (1); /* Returns 1 if character is uppercase */
	else
		return (0); /* Returns 0 if character is not uppercase */
}

/**
 * _isalpha - Checks if a character is alphabetic
 * @c: Character to check
 *
 * Return: 1 (is alphabetic), 0 (is not alphabetic)
 */
int _isalpha(int c)
{
	if (_islower(c) || _isupper(c)) /*use if */
		return (1); /* Returns 1 if character is alphabetic */
	else
		return (0); /* Returns 0 if character is not alphabetic */
}

/**
 * process_sign - Processes the sign of a number
 * @s: Character to check
 * @sign: Current sign
 *
 * Return: -1 (negative), 1 (positive)
 */
int process_sign(char s, int sign)
{
	return ((s == '-') ? sign * -1 : sign); /*use if */
}

/**
 * process_digit - Processes a digit character
 * @s: Character to check
 * @result: Current result
 * @flag: Flag for processing
 *
 * Return: Updated result
 */
unsigned int process_digit(char s, unsigned int result, int *flag)
{
	if (s >= '0' && s <= '9') /*use if */
	{
		*flag = 1;
		result = result * 10 + (s - '0');
	}
	else if (*flag == 1) /*use if */
		*flag = 2;
	return (result); /* Returns updated result */
}

/**
 * _atoi - Converts a string to an integer
 * @s: String to convert
 *
 * Return: Converted integer
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, flag = 0;
	unsigned int result = 0;

	do {
		sign = process_sign(s[i], sign); /*use if */
		result = process_digit(s[i], result, &flag); /*use if */
		i++;
	} while (s[i] != '\0' && flag != 2); /*use loop */

	return ((sign == -1) ? -result : result); /* Returns converted integer */
}

