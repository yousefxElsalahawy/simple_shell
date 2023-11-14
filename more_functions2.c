#include "shell.h"

/**
 * process_plus_sign - This function processes plus signs in a string
 * @_aso_: This pointer refers to the string to be processed
 *
 * Return: Pointer to the first character after the plus signs
 */
char *process_plus_sign(char *_aso_)
{
    char *_oqo_ = _aso_; /* This pointer refers to the string _aso_ */

    /* use loop */
    do {
        _oqo_++;
    } while (*_oqo_ == '+');

    /* This function returns a pointer */
    return (_oqo_);
}

/**
 * process_digits - This function processes digits in a string
 * @_aso_: This pointer refers to the string to be processed
 *
 * Return: The processed number if successful, -1 otherwise
 */
unsigned long int process_digits(char *_aso_)
{
    unsigned long int _rultt_ = 0;
    char current_char = *_aso_;

    /* use loop */
    do {
        /* use if */
        if (current_char >= '0' && current_char <= '9')
        {
            _rultt_ = (_rultt_ << 3) + (_rultt_ << 1) + (current_char - '0');
            /* use if */
            if (_rultt_ > INT_MAX)
                /* This function returns -1 if the _rultt_ is greater than INT_MAX */
                return (-1);
        }
        else
            /* This function returns -1 if the current character is not a digit */
            return (-1);

        current_char = *(++_aso_);
    } while (current_char != '\0');

    /* This function returns the processed number */
    return (_rultt_);
}

/**
 * _fun_err_atoi_ - This function converts a string to an integer
 * @_aso_: This pointer refers to the string to be converted
 *
 * Return: The converted number if successful, -1 otherwise
 */
int _fun_err_atoi_(char *_aso_)
{
    _aso_ = process_plus_sign(_aso_);

    /* This function returns the _rultt_ of process_digits */
    return (process_digits(_aso_));
}

/**
 * print_message - This function prints a message
 * @message: This pointer refers to the message to be printed
 */
void print_message(char *message)
{
    _ee_put_(message);
    _ee_put_(": ");
}

/**
 * print_error_part1 - This function prints the first par
 * of an error message
 * @_data_: This pointer refers to the _data_ struct
 */
void print_error_part1(_info_OK *_data_)
{
    print_message(_data_->_fil_name_);
}

/**
 * print_error_part2 - This function prints the second part
 * of an error message
 * @_data_: This pointer refers to the _data_ struct
 */
void print_error_part2(_info_OK *_data_)
{
    _prnt_dir_(_data_->_my_line_count, STDERR_FILENO);
    _ee_put_(": ");
}

/**
 * print_error_part3 - This function prints the third part
 * of an error message
 * @_data_: This pointer refers to the _data_ struct
 * @_oeo_str: This pointer refers to the error string
 */
void print_error_part3(_info_OK *_data_, char *_oeo_str)
{
    print_message(_data_->_arguv_[0]);
    print_message(_oeo_str);
}

/**
 * print_error - This function prints an error message
 * @_data_: This pointer refers to the _data_ struct
 * @_oeo_str: This pointer refers to the error string
 */
void print_error(_info_OK *_data_, char *_oeo_str)
{
    print_error_part1(_data_);
    print_error_part2(_data_);
    print_error_part3(_data_, _oeo_str);
}

/**
 * hdl_putchar - This function hdls putchar
 * @_fl_dir_: This variable is the file descriptor
 *
 * Return: 1 if _fl_dir_ is STDERR_FILENO, 0 otherwise
 */
int hdl_putchar(int _fl_dir_)
{
    /* This function returns 1 if _fl_dir_ is STDERR_FILENO, 0 otherwise */
    return ((_fl_dir_ == STDERR_FILENO) ? 1 : 0);
}

/**
 * hdl_abs - This function hdls absolute values
 * @input: This variable is the input
 * @__putchar: This pointer refers to the putchar function
 * @_ocntt_: This pointer refers to the _ocntt_
 *
 * Return: The absolute _vlle_ of the input
 */
unsigned int hdl_abs(int input, int (*__putchar)(char), int *_ocntt_)
{
    unsigned int _abs_;

    /* use if */
    if (input < 0)
    {
        _abs_ = -input;
        __putchar('-');
        (*_ocntt_)++;
    }
    else
        _abs_ = input;

    /* This function returns the absolute _vlle_ of the input */
    return (_abs_);
}

/**
 * @abs_: This variable is the absolute _vlle_ of the input
 *
 * Return: The current _vlle_
 */
int hdl_current(unsigned int _abs_, int (*__putchar)(char), int *_ocntt_)
{
    int _oops_ = 1000000000;
    unsigned int current = _abs_;

    /* use loop */
    do {
        /* use if */
        if (_abs_ / _oops_)
        {
            __putchar('0' + current / _oops_);
            (*_ocntt_)++;
        }
        current %= _oops_;
        _oops_ /= 10;
    } while (_oops_ > 1);
    /* This function returns the current _vlle_ */
    return (current);
}

/**
 * hdl_last_digit - This function hdls the last digit of the current _vlle_
 * @current: This variable is the current _vlle_
 * @__putchar: This pointer refers to the putchar function
 * @_ocntt_: This pointer refers to the _ocntt_
 */
void hdl_last_digit(unsigned int current,
        int (*__putchar)(char), int *_ocntt_)
{
    __putchar('0' + current);
    (*_ocntt_)++;
}

/**
 * _prnt_dir_ - This function prints the input _vlle_
 * @input: This variable is the input _vlle_
 * @_fl_dir_: This variable is the file descriptor
 *
 * Return: The _ocntt_ of printed characters
 */
int _prnt_dir_(int input, int _fl_dir_)
{
    int (*__putchar)(char) = _pputt_char;
    int _ocntt_ = 0;
    unsigned int _abs_, current;

    int is_stderr = hdl_putchar(_fl_dir_);

    __putchar = is_stderr ? _e_put_char_ : _pputt_char;
    _abs_ = hdl_abs(input, __putchar, &_ocntt_);
    current = hdl_current(_abs_, __putchar, &_ocntt_);
    hdl_last_digit(current, __putchar, &_ocntt_);

    /*returns the _ocntt_ of printed characters */
    return (_ocntt_);
}

/**
 * cnvrt_nmbr_ - converter function, a clone of itoa
 * @_num_: number
 * @base: base
 * @_oflgs_: argument _oflgs_
 *
 * Return: string
 */
char *hdl_sign(long int _num_, int _oflgs_,
        unsigned long *n, char *_ssgnn_)
{
    (!(_oflgs_ & _CONV_UNSIGNED_) && _num_ < 0) ?
        (*n = -_num_, *_ssgnn_ = '-') : (*n = _num_, *_ssgnn_ = 0);
    /* This function returns a string of digits in the specified base */
    return ((_oflgs_ & _CONV_LOWERCASE_) ? "0123456789abcdef" :
            "0123456789ABCDEF");
}

/**
 * convert_base - This function converts a number from
 * base 10 to another base
 * @n: This pointer refers to the number to be converted
 * @base: This variable is the base to convert to
 * @_pttr_: This pointer refers to the location in the
 * _obuf_fer_ where the _rultt_ is stored
 * @array: This pointer refers to the array of character
 *  used for conversion
 */
void convert_base(unsigned long *n, int base, char **_pttr_, char *array)
{
    /* use loop */
    do {
        *--(*_pttr_) = array[*n % base];
        *n /= base;
    } while (*n != 0);
}

/**
 * hdl_negative_sign - This function hdls the negative _ssgnn_ of a number
 * @_pttr_: This pointer refers to the location in the
 * _obuf_fer_ where the _rultt_ is stored
 * @_ssgnn_: This variable is the _ssgnn_ of the number
 */
void hdl_negative_sign(char **_pttr_, char _ssgnn_)
{
    /* use if */
    if (_ssgnn_)
        *--(*_pttr_) = _ssgnn_;
}

/**
 * cnvrt_nmbr_ - This function converts a number to a string
 * in a specified base
 * @_num_: This variable is the number to be converted
 * @base: This variable is the base to convert to
 * @_oflgs_: This variable is the _oflgs_ for conversion
 *
 * Return: Pointer to the converted number string
 */
char *cnvrt_nmbr_(long int _num_, int base, int _oflgs_)
{
    static char *array;
    static char _obuf_fer_[50];
    char _ssgnn_ = 0;
    char *_pttr_;
    unsigned long n;

    array = hdl_sign(_num_, _oflgs_, &n, &_ssgnn_);
    _pttr_ = &_obuf_fer_[49];
    *_pttr_ = '\0';

    /* use loop */
    do {
        convert_base(&n, base, &_pttr_, array);
    } while (n != 0);

    hdl_negative_sign(&_pttr_, _ssgnn_);

    /* This function returns a pointer to the converted number string */
    return (_pttr_);
}

/**
 * set_to_null - This function sets _All characters in a string to '\0'
 * @_oqo_: This pointer refers to the string to be set to null
 */
void set_to_null(char *_oqo_)
{
    /* use loop */
    do {
        *_oqo_ = '\0';
        _oqo_++;
    } while (*_oqo_ != '\0');
}

/**
 * _rmove_com_ - This function removes comments from a string
 * @_bbuuff_: This pointer refers to the string to remove comments from
 */
void _rmove_com_(char *_bbuuff_)
{
    char *_oqo_ = _bbuuff_;

    /* use loop */
    do {
        /* use if */
        if (*_oqo_ == '#' && (_oqo_ == _bbuuff_ || *(_oqo_ - 1) == ' '))
            set_to_null(_oqo_);
        else
            _oqo_++;
    } while (*_oqo_ != '\0');
}


