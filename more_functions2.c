#include "shell.h"

/**
 * process_plus_sign - This function processes plus signs in a string
 * @s: This pointer refers to the string to be processed
 *
 * Return: Pointer to the first character after the plus signs
 */
char *process_plus_sign(char *s)
{
    char *p = s; /* This pointer refers to the string s */

    /* use loop */
    do {
        p++;
    } while (*p == '+');

    /* This function returns a pointer to the first character after the plus signs */
    return (p);
}

/**
 * process_digits - This function processes digits in a string
 * @s: This pointer refers to the string to be processed
 *
 * Return: The processed number if successful, -1 otherwise
 */
unsigned long int process_digits(char *s)
{
    unsigned long int result = 0;
    char current_char = *s;

    /* use loop */
    do {
        /* use if */
        if (current_char >= '0' && current_char <= '9')
        {
            result = (result << 3) + (result << 1) + (current_char - '0');
            /* use if */
            if (result > INT_MAX)
                /* This function returns -1 if the result is greater than INT_MAX */
                return (-1);
        }
        else
            /* This function returns -1 if the current character is not a digit */
            return (-1);

        current_char = *(++s);
    } while (current_char != '\0');

    /* This function returns the processed number */
    return (result);
}

/**
 * _erratoi - This function converts a string to an integer
 * @s: This pointer refers to the string to be converted
 *
 * Return: The converted number if successful, -1 otherwise
 */
int _erratoi(char *s)
{
    s = process_plus_sign(s);

    /* This function returns the result of process_digits */
    return (process_digits(s));
}

/**
 * print_message - This function prints a message
 * @message: This pointer refers to the message to be printed
 */
void print_message(char *message)
{
    _eputs(message);
    _eputs(": ");
}

/**
 * print_error_part1 - This function prints the first part of an error message
 * @info: This pointer refers to the Info struct
 */
void print_error_part1(info_t *info)
{
    print_message(info->fname);
}

/**
 * print_error_part2 - This function prints the second part of an error message
 * @info: This pointer refers to the Info struct
 */
void print_error_part2(info_t *info)
{
    print_d(info->line_count, STDERR_FILENO);
    _eputs(": ");
}

/**
 * print_error_part3 - This function prints the third part of an error message
 * @info: This pointer refers to the Info struct
 * @estr: This pointer refers to the error string
 */
void print_error_part3(info_t *info, char *estr)
{
    print_message(info->argv[0]);
    print_message(estr);
}

/**
 * print_error - This function prints an error message
 * @info: This pointer refers to the Info struct
 * @estr: This pointer refers to the error string
 */
void print_error(info_t *info, char *estr)
{
    print_error_part1(info);
    print_error_part2(info);
    print_error_part3(info, estr);
}

/**
 * handle_putchar - This function handles putchar
 * @fd: This variable is the file descriptor
 *
 * Return: 1 if fd is STDERR_FILENO, 0 otherwise
 */
int handle_putchar(int fd)
{
    /* This function returns 1 if fd is STDERR_FILENO, 0 otherwise */
    return ((fd == STDERR_FILENO) ? 1 : 0);
}

/**
 * handle_abs - This function handles absolute values
 * @input: This variable is the input
 * @__putchar: This pointer refers to the putchar function
 * @count: This pointer refers to the count
 *
 * Return: The absolute value of the input
 */
unsigned int handle_abs(int input, int (*__putchar)(char), int *count)
{
    unsigned int _abs_;

    /* use if */
    if (input < 0)
    {
        _abs_ = -input;
        __putchar('-');
        (*count)++;
    }
    else
        _abs_ = input;

    /* This function returns the absolute value of the input */
    return (_abs_);
}

/**
 * @abs_: This variable is the absolute value of the input
 *
 * Return: The current value
 */
int handle_current(unsigned int _abs_, int (*__putchar)(char), int *count)
{
    int i = 1000000000;
    unsigned int current = _abs_;

    /* use loop */
    do {
        /* use if */
        if (_abs_ / i)
        {
            __putchar('0' + current / i);
            (*count)++;
        }
        current %= i;
        i /= 10;
    } while (i > 1);
    /* This function returns the current value */
    return (current);
}

/**
 * handle_last_digit - This function handles the last digit of the current value
 * @current: This variable is the current value
 * @__putchar: This pointer refers to the putchar function
 * @count: This pointer refers to the count
 */
void handle_last_digit(unsigned int current,
        int (*__putchar)(char), int *count)
{
    __putchar('0' + current);
    (*count)++;
}

/**
 * print_d - This function prints the input value
 * @input: This variable is the input value
 * @fd: This variable is the file descriptor
 *
 * Return: The count of printed characters
 */
int print_d(int input, int fd)
{
    int (*__putchar)(char) = _putchar;
    int count = 0;
    unsigned int _abs_, current;

    int is_stderr = handle_putchar(fd);

    __putchar = is_stderr ? _eputchar : _putchar;
    _abs_ = handle_abs(input, __putchar, &count);
    current = handle_current(_abs_, __putchar, &count);
    handle_last_digit(current, __putchar, &count);

    /*returns the count of printed characters */
    return (count);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *handle_sign(long int num, int flags,
        unsigned long *n, char *sign)
{
    (!(flags & CONVERT_UNSIGNED) && num < 0) ?
        (*n = -num, *sign = '-') : (*n = num, *sign = 0);
    /* This function returns a string of digits in the specified base */
    return ((flags & CONVERT_LOWERCASE) ? "0123456789abcdef" :
            "0123456789ABCDEF");
}

/**
 * convert_base - This function converts a number from base 10 to another base
 * @n: This pointer refers to the number to be converted
 * @base: This variable is the base to convert to
 * @ptr: This pointer refers to the location in the buffer where the result is stored
 * @array: This pointer refers to the array of characters used for conversion
 */
void convert_base(unsigned long *n, int base, char **ptr, char *array)
{
    /* use loop */
    do {
        *--(*ptr) = array[*n % base];
        *n /= base;
    } while (*n != 0);
}

/**
 * handle_negative_sign - This function handles the negative sign of a number
 * @ptr: This pointer refers to the location in the buffer where the result is stored
 * @sign: This variable is the sign of the number
 */
void handle_negative_sign(char **ptr, char sign)
{
    /* use if */
    if (sign)
        *--(*ptr) = sign;
}

/**
 * convert_number - This function converts a number to a string in a specified base
 * @num: This variable is the number to be converted
 * @base: This variable is the base to convert to
 * @flags: This variable is the flags for conversion
 *
 * Return: Pointer to the converted number string
 */
char *convert_number(long int num, int base, int flags)
{
    static char *array;
    static char buffer[50];
    char sign = 0;
    char *ptr;
    unsigned long n;

    array = handle_sign(num, flags, &n, &sign);
    ptr = &buffer[49];
    *ptr = '\0';

    /* use loop */
    do {
        convert_base(&n, base, &ptr, array);
    } while (n != 0);

    handle_negative_sign(&ptr, sign);

    /* This function returns a pointer to the converted number string */
    return (ptr);
}

/**
 * set_to_null - This function sets all characters in a string to '\0'
 * @p: This pointer refers to the string to be set to null
 */
void set_to_null(char *p)
{
    /* use loop */
    do {
        *p = '\0';
        p++;
    } while (*p != '\0');
}

/**
 * remove_comments - This function removes comments from a string
 * @buf: This pointer refers to the string to remove comments from
 */
void remove_comments(char *buf)
{
    char *p = buf;

    /* use loop */
    do {
        /* use if */
        if (*p == '#' && (p == buf || *(p - 1) == ' '))
            set_to_null(p);
        else
            p++;
    } while (*p != '\0');
}
