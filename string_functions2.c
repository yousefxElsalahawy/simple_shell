#include "shell.h"

/**
 * _copy - This function copies a string to another string recursively
 * @dest: This pointer refers to the destination string
 * @src: This pointer refers to the source string
 * @i: This variable is the current index in the source string
 *
 * Return: Pointer to the destination string
 */
char *_copy(char *dest, char *src, int i)
{
    /* use if */
    if (src[i])
    {
        dest[i] = src[i];
        return _copy(dest, src, i + 1);
    }
    dest[i] = 0;
    /* This function returns a pointer to the destination string */
    return (dest);
}

/**
 * _strcpy - This function copies a string to another string
 * @dest: This pointer refers to the destination string
 * @src: This pointer refers to the source string
 *
 * Return: Pointer to the destination string
 */
char *_strcpy(char *dest, char *src)
{
    /* This function returns a pointer to the destination string */
    return ((dest == src || src == 0) ? dest : _copy(dest, src, 0));
}

/**
 * _strlen___ - This function returns the length of a string
 * @str: This pointer refers to the string whose length to check
 *
 * Return: The length of the string
 */
int _strlen___(const char *str)
{
    int length = 0;
    const char *s = str ? str : "";

    /* use loop */
    while (*s)
    {
        length++;
        s++;
    }
    /* This function returns the length of the string */
    return (length);
}

/**
 * _strdup - This function duplicates a string
 * @str: This pointer refers to the string to duplicate
 *
 * Return: Pointer to the duplicated string
 */
char *_strdup(const char *str)
{
    int length = _strlen___(str);
    char *ret = (char *) malloc(sizeof(char) * (length + 1));

    /* use if */
    if (ret)
    {
        char *p = ret;
        const char *s = str ? str : "";

        /* use loop */
        while (*s)
        {
            *p = *s;
            p++;
            s++;
        }
        *p = '\0';
    }
    /* This function returns a pointer to the duplicated string */
    return (ret);
}

/**
 * _print_char - This function prints a character
 * @str: This pointer refers to the character to print
 * @end: This pointer refers to the end of the string
 */
void _print_char(char *str, char *end)
{
    /* use if */
    if (str != end)
    {
        _putchar(*str);
        _print_char(str + 1, end);
    }
}

/**
 * _puts - This function prints a string
 * @str: This pointer refers to the string to print
 */
void _puts(char *str)
{
    char *end = str;

    /* use loop */
    while (*end)
        ++end;
    /* use if */
    if (str)
    {
        _print_char(str, end);
    }
    else
    {
        return;
    }
}

/**
 * write_buffer - This function writes a buffer to the standard output
 * @buf: This pointer refers to the buffer to write
 * @i: This pointer refers to the current index in the buffer
 */
void write_buffer(char *buf, int *i)
{
    write(1, buf, *i);
    *i = 0;
}

/**
 * add_to_buffer - This function adds a character to a buffer
 * @buf: This pointer refers to the buffer to add to
 * @i: This pointer refers to the current index in the buffer
 * @c: This variable is the character to add
 */
void add_to_buffer(char *buf, int *i, char c)
{
    buf[(*i)++] = c;
}

/**
 * _putchar - This function writes a character to the standard output
 * @c: This variable is the character to write
 *
 * Return: 1 (success)
 */
int _putchar(char c)
{
    static int i;
    static char buf[WRITE_BUF_SIZE];

    /* use if */
    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write_buffer(buf, &i);
    }
    else
    {
        add_to_buffer(buf, &i, c);
    }
    /* This function returns 1 on success */
    return (1);
}
