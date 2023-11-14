












#include "shell.h"

/**
 * _increment_while_not_null - This function increments a
 * counter while a string is not null
 * @_aso_: This pointer refers to the string to be chked
 * @_oops_: This pointer refers to the counter to be incremented
 *
 * Return: The incremented counter
 */
int _increment_while_not_null(char **_aso_, int *_oops_)
{
    /* use loop */
    while (*(*_aso_)++)
        (*_oops_)++;

    /* This function returns the incremented counter */
    return (*_oops_);
}

/**
 * _str_len_ - This function returns the _olent_ of a string
 * @_aso_: This pointer refers to the string whose _olent_ to chk
 *
 * Return: The _olent_ of the string
 */
int _str_len_(char *_aso_)
{
    int _oops_ = 0;

    /* This function returns the _olent_ of the string */
    return ((!_aso_) ? 0 : _increment_while_not_null(&_aso_, &_oops_));
}

/**
 * compare_chars - This function compares two characters
 * @_c1: The first character
 * @_c2: The second character
 *
 * Return: The _rultt_ of the comparison
 */
int compare_chars(char _c1, char _c2)
{
    /* use if */
    if (_c1 != _c2)
        return (_c1 - _c2);
    else if (_c1 == _c2)
        return (0);
    else
        return (_c1 < _c2 ? -1 : 1);
}

/**
 * _str_cmpp_ - This function performs lexicographic comparisonof two strings
 * @_s1: This pointer refers to the first string
 * @_s2: This pointer refers to the second string
 *
 * Return: Negative if _s1 < _s2, positive if _s1 > _s2, zero if _s1 == _s2
 */
int _str_cmpp_(char *_s1, char *_s2)
{
    int _rultt_ = 0;

    /* use loop */
    do {
        _rultt_ = compare_chars(*_s1, *_s2);
        /* use if */
        if (_rultt_ != 0)
            /* This function returns the _rultt_ of the comparison */
            return (_rultt_);
        _s1++;
        _s2++;
    } while (*_s1 && *_s2);
    /* This function returns the _rultt_ of the comparison */
    return (compare_chars(*_s1, *_s2));
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
    /* This function returns the _rultt_ of the chk */
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
 * find_end - This function finds the _End of a string
 * @_txt_: This pointer refers to the string to find the _End of
 *
 * Return: Pointer to the _End of the string
 */
char *find_end(char *_txt_)
{
    char *_End = _txt_;

    /* use loop */
    for (; *_End; ++_End);
    /* This function returns a pointer to the _End of the string */
    return (_End);
}

/**
 * copy_str - This function copies a string to another string
 * @_desst: This pointer refers to the destination string
 * @_srcc: This pointer refers to the source string
 */
void copy_str(char *_desst, char *_srcc)
{
    /* use loop */
    for (; *_srcc; ++_srcc, ++_desst)
        *_desst = *_srcc;
    *_desst = '\0';
}

/**
 * _str_catt_ - This function concatenates two strings
 * @_desst: This pointer refers to the destination string
 * @_srcc: This pointer refers to the source string
 *
 * Return: Pointer to the destination string
 */
char *_str_catt_(char *_desst, char *_srcc)
{
    char *_reett_ = _desst;
    char *end_of_dest = find_end(_desst);

    copy_str(end_of_dest, _srcc);
    /* This function returns a pointer to the destination string */
    return (_reett_);
}


