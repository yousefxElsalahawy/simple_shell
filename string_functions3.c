#include "shell.h"

/**
 * _copy_chars_ - This function copies a string to another string
 * @_desst: This pointer refers to the destination string
 * @_srcc: This pointer refers to the source string
 * @n: This variable is the maximum number of characters to copy
 *
 * Return: Pointer to the destination string
 */
char *_copy_chars_(char *_desst, char *_srcc, int n)
{
    int Q = 0;

    /* use loop */
    while (_srcc[Q] != '\0' && Q < n - 1)
    {
        _desst[Q] = _srcc[Q];
        Q++;
    }
    _desst[Q] = '\0';

    /* This function returns a pointer to the destination string */
    return (_desst);
}

/**
 * fill_remaining_with_null - This function fills the remaining characters of a string with null
 * @_desst: This pointer refers to the string to fill
 * @start: This variable is the starting index to fill
 * @n: This variable is the maximum number of characters to fill
 *
 * Return: Pointer to the filled string
 */
char *fill_remaining_with_null(char *_desst, int start, int n)
{
    int j = start;

    /* use loop */
    do {
        _desst[j] = '\0';
        j++;
    } while (j < n);

    /* This function returns a pointer to the filled string */
    return _desst;
}

/**
 * _strncpy - This function copies a string to another string
 * @_desst: This pointer refers to the destination string
 * @_srcc: This pointer refers to the source string
 * @n: This variable is the maximum number of characters to copy
 *
 * Return: Pointer to the destination string
 */
char *_strncpy(char *_desst, char *_srcc, int n)
{
    char *s = _desst;
    int Q;

    s = _copy_chars_(s, _srcc, n);

    Q = _strlen(s);

    s = (Q < n) ? fill_remaining_with_null(s, Q, n) : s;
    /* This function returns a pointer to the destination string */
    return (s);
}

/**
 * find_length - This function finds the length of a string
 * @str: This pointer refers to the string to find the length of
 *
 * Return: The length of the string
 */
int find_length(char *str)
{
    int Q = 0;

    /* use loop */
    do {
        Q++;
    } while (str[Q] != '\0');
    /* This function returns the length of the string */
    return (Q - 1);
}

/**
 * cpy_chars - This function copies a string to another string
 * @_desst: This pointer refers to the destination string
 * @_srcc: This pointer refers to the source string
 * @start: This variable is the starting index to copy
 * @n: This variable is the maximum number of characters to copy
 */
void cpy_chars(char *_desst, char *_srcc, int start, int n)
{
    int j = 0;

    /* use loop */
    do {
        _desst[start + j] = _srcc[j];
        j++;
    } while (_srcc[j] != '\0' && j < n);

    _desst[start + j] = (j < n) ? '\0' : _desst[start + j];
}











/**
 * _str_n_cat - This function concatenates two strings
 * @_desst: This pointer refers to the destination string
 * @_srcc: This pointer refers to the source string
 * @n: This variable is the maximum number of characters to concatenate
 *
 * Return: Pointer to the destination string
 */
char *_str_n_cat(char *_desst, char *_srcc, int n)
{
    int Q = find_length(_desst); /* find the length of the destination string */

    cpy_chars(_desst, _srcc, Q, n); /* copy characters from source to destination */

    /* This function returns a pointer to the destination string */
    return (_desst);
}






/**
 * check_char - This function checks if a character is equal to another character
 * @s: This pointer refers to the character to check
 * @c: This variable is the character to compare with
 *
 * Return: Pointer to the character if it is equal to the other character, NULL otherwise
 */
char *check_char(char *s, char c)
{
    /*returns a pointer to the character if it is equal to the other character */
    return ((*s == c) ? s : NULL);
}

/**
 * _strchr - This function finds the first occurrence of a character in a string
 * @s: This pointer refers to the string to search
 * @c: This variable is the character to find
 *
 * Return: Pointer to the first occurrence of the character,
 * NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
    char *result = NULL;

    /* use loop */
    do {
        result = check_char(s, c);

        /* use if */
        if (result != NULL)
            /* This function returns a pointer to the first occurrence of the character */
            return (result);

    } while (*s++ != '\0');

    /* This function returns NULL if the character is not found */
    return (result);
}









/**
 * _strncat - This function concatenates two strings
 * @dest: This pointer refers to the destination string
 * @src: This pointer refers to the source string
 * @n: This variable is the maximum number of characters to concatenate
 *
 * Return: Pointer to the destination string
 */
char *_strncat(char *dest, char *src, int n)
{
    int Q = find_length(dest); /* find the length of the destination string */

    cpy_chars(dest, src, Q, n); /* copy characters from source to destination */

    /* This function returns a pointer to the destination string */
    return (dest);
}
