
#include "shell.h"

/**
 * _copy - This function copies a string to another string recursively
 * @_desst: This pointer refers to the destination string
 * @_srcc: This pointer refers to the source string
 * @_oops_: This variable is the current _indx_ in the source string
 *
 * Return: Pointer to the destination string
 */
char *_copy(char *_desst, char *_srcc, int _oops_)
{
    /* use if */
    if (_srcc[_oops_])
    {
        _desst[_oops_] = _srcc[_oops_];
        return _copy(_desst, _srcc, _oops_ + 1);
    }
    _desst[_oops_] = 0;
    /* This function returns a pointer to the destination string */
    return (_desst);
}

/**
 * _str_cpy - This function copies a string to another string
 * @_desst: This pointer refers to the destination string
 * @_srcc: This pointer refers to the source string
 *
 * Return: Pointer to the destination string
 */
char *_str_cpy(char *_desst, char *_srcc)
{
    /* This function returns a pointer to the destination string */
    return ((_desst == _srcc || _srcc == 0) ? _desst : _copy(_desst, _srcc, 0));
}

/**
 * _strlen___ - This function returns the _olent_ of a string
 * @_txt_: This pointer refers to the string whose _olent_ to chk
 *
 * Return: The _olent_ of the string
 */
int _strlen___(const char *_txt_)
{
    int _olent_ = 0;
    const char *_aso_ = _txt_ ? _txt_ : "";

    /* use loop */
    while (*_aso_)
    {
        _olent_++;
        _aso_++;
    }
    /* This function returns the _olent_ of the string */
    return (_olent_);
}

/**
 * _str_dupp_ - This function duplicates a string
 * @_txt_: This pointer refers to the string to duplicate
 *
 * Return: Pointer to the duplicated string
 */
char *_str_dupp_(const char *_txt_)
{
    int _olent_ = _strlen___(_txt_);
    char *_reett_ = (char *) malloc(sizeof(char) * (_olent_ + 1));

    /* use if */
    if (_reett_)
    {
        char *_oqo_ = _reett_;
        const char *_aso_ = _txt_ ? _txt_ : "";

        /* use loop */
        while (*_aso_)
        {
            *_oqo_ = *_aso_;
            _oqo_++;
            _aso_++;
        }
        *_oqo_ = '\0';
    }
    /* This function returns a pointer to the duplicated string */
    return (_reett_);
}

/**
 * _print_char - This function prints a character
 * @_txt_: This pointer refers to the character to print
 * @_End: This pointer refers to the _End of the string
 */
void _print_char(char *_txt_, char *_End)
{
    /* use if */
    if (_txt_ != _End)
    {
        _pputt_char(*_txt_);
        _print_char(_txt_ + 1, _End);
    }
}

/**
 * _put_ss_ - This function prints a string
 * @_txt_: This pointer refers to the string to print
 */
void _put_ss_(char *_txt_)
{
    char *_End = _txt_;

    /* use loop */
    while (*_End)
        ++_End;
    /* use if */
    if (_txt_)
    {
        _print_char(_txt_, _End);
    }
    else
    {
        return;
    }
}

/**
 * write_buffer - This function writes a _obuf_fer_ to the standard output
 * @_bbuuff_: This pointer refers to the _obuf_fer_ to write
 * @_oops_: This pointer refers to the current _indx_ in the _obuf_fer_
 */
void write_buffer(char *_bbuuff_, int *_oops_)
{
    write(1, _bbuuff_, *_oops_);
    *_oops_ = 0;
}

/**
 * add_to_buffer - This function adds a character to a _obuf_fer_
 * @_bbuuff_: This pointer refers to the _obuf_fer_ to add to
 * @_oops_: This pointer refers to the current _indx_ in the _obuf_fer_
 * @_coco_c: This variable is the character to add
 */
void add_to_buffer(char *_bbuuff_, int *_oops_, char _coco_c)
{
    _bbuuff_[(*_oops_)++] = _coco_c;
}

/**
 * _pputt_char - This function writes a character to the standard output
 * @_coco_c: This variable is the character to write
 *
 * Return: 1 (success)
 */
int _pputt_char(char _coco_c)
{
    static int _oops_;
    static char _bbuuff_[_SIZE_BUFF_WRITE];

    /* use if */
    if (_coco_c == _BUFFER_FLUSH || _oops_ >= _SIZE_BUFF_WRITE)
    {
        write_buffer(_bbuuff_, &_oops_);
    }
    else
    {
        add_to_buffer(_bbuuff_, &_oops_, _coco_c);
    }
    /* This function returns 1 on success */
    return (1);
}





