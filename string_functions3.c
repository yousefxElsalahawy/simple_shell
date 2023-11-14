
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
    int _oops_ = 0;

    /* use loop */
    while (_srcc[_oops_] != '\0' && _oops_ < n - 1)
    {
        _desst[_oops_] = _srcc[_oops_];
        _oops_++;
    }
    _desst[_oops_] = '\0';

    /* This function returns a pointer to the destination string */
    return (_desst);
}

/**
 * _fll_remain_wth_nll - This function fills the remaining characters of a string with null
 * @_desst: This pointer refers to the string to fill
 * @_sstrtt_: This variable is the starting _indx_ to fill
 * @n: This variable is the maximum number of characters to fill
 *
 * Return: Pointer to the filled string
 */
char *_fll_remain_wth_nll(char *_desst, int _sstrtt_, int n)
{
    int j = _sstrtt_;

    /* use loop */
    do {
        _desst[j] = '\0';
        j++;
    } while (j < n);

    /* This function returns a pointer to the filled string */
    return _desst;
}

/**
 * _strr_ncpy_ - This function copies a string to another string
 * @_desst: This pointer refers to the destination string
 * @_srcc: This pointer refers to the source string
 * @n: This variable is the maximum number of characters to copy
 *
 * Return: Pointer to the destination string
 */
char *_strr_ncpy_(char *_desst, char *_srcc, int n)
{
    char *_aso_ = _desst;
    int _oops_;

    _aso_ = _copy_chars_(_aso_, _srcc, n);

    _oops_ = _str_len_(_aso_);

    _aso_ = (_oops_ < n) ? _fll_remain_wth_nll(_aso_, _oops_, n) : _aso_;
    /* This function returns a pointer to the destination string */
    return (_aso_);
}

/**
 * find_length - This function finds the _olent_ of a string
 * @_txt_: This pointer refers to the string to find the _olent_ of
 *
 * Return: The _olent_ of the string
 */
int find_length(char *_txt_)
{
    int _oops_ = 0;

    /* use loop */
    do {
        _oops_++;
    } while (_txt_[_oops_] != '\0');
    /* This function returns the _olent_ of the string */
    return (_oops_ - 1);
}

/**
 * cpy_chars - This function copies a string to another string
 * @_desst: This pointer refers to the destination string
 * @_srcc: This pointer refers to the source string
 * @_sstrtt_: This variable is the starting _indx_ to copy
 * @n: This variable is the maximum number of characters to copy
 */
void cpy_chars(char *_desst, char *_srcc, int _sstrtt_, int n)
{
    int j = 0;

    /* use loop */
    do {
        _desst[_sstrtt_ + j] = _srcc[j];
        j++;
    } while (_srcc[j] != '\0' && j < n);

    _desst[_sstrtt_ + j] = (j < n) ? '\0' : _desst[_sstrtt_ + j];
}

/**
 * chk_char - This function chks if a character is equal to another character
 * @_aso_: This pointer refers to the character to chk
 * @_coco_c: This variable is the character to compare with
 *
 * Return: Pointer to the character if it is equal to the other character, NULL otherwise
 */
char *chk_char(char *_aso_, char _coco_c)
{
    /*returns a pointer to the character if it is equal to the other character */
    return ((*_aso_ == _coco_c) ? _aso_ : NULL);
}

/**
 * _str_n_chr - This function finds the first occurrence of a character in a string
 * @_aso_: This pointer refers to the string to search
 * @_coco_c: This variable is the character to find
 *
 * Return: Pointer to the first occurrence of the character,
 * NULL if the character is not found
 */
char *_str_n_chr(char *_aso_, char _coco_c)
{
    char *_rultt_ = NULL;

    /* use loop */
    do {
        _rultt_ = chk_char(_aso_, _coco_c);

        /* use if */
        if (_rultt_ != NULL)
            /* This function returns a pointer to the first occurrence of the character */
            return (_rultt_);

    } while (*_aso_++ != '\0');

    /* This function returns NULL if the character is not found */
    return (_rultt_);
}


