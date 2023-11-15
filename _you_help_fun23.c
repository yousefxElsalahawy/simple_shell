



#include "shell.h"


/**
 * hdl_current - This function handles the current value
 * @_abs_: This variable is the absolute value of the input
 * @__putchar: This pointer refers to a function that puts a character
 * @_cnt_: This pointer refers to the count
 *
 * Return: The current value
 */
int hdl_current(unsigned int _abs_, int (*__putchar)(char), int *_cnt_)
{
	int _OK_ = 1000000000;
	unsigned int current = _abs_;

	/* use loop */
	do {
		/* use if */
		if (_abs_ / _OK_)
		{
			__putchar('0' + current / _OK_);
			(*_cnt_)++;
		}
		current %= _OK_;
		_OK_ /= 10;
	} while (_OK_ > 1);
	/* This function returns the current value */
	return (current);
}
/**
 * hdl_last_digit - This function hdls the last digit of the current _vle_
 * @current: This variable is the current _vle_
 * @__putchar: This pointer refers to the putchar function
 * @_cnt_: This pointer refers to the _cnt_
 */
void hdl_last_digit(unsigned int current,
		int (*__putchar)(char), int *_cnt_)
{
	__putchar('0' + current);
	(*_cnt_)++;
}

/**
 * _prnt_dir_ - This function prnts the input _vle_
 * @input: This variable is the input _vle_
 * @_fl_dir_: This variable is the file descriptor
 *
 * Return: The _cnt_ of prnted characters
 */
int _prnt_dir_(int input, int _fl_dir_)
{
	int (*__putchar)(char) = _pputt_char;
	int _cnt_ = 0;
	unsigned int _abs_, current;

	int is_stderr = hdl_putchar(_fl_dir_);

	__putchar = is_stderr ? _e_put_char_ : _pputt_char;
	_abs_ = hdl_abs(input, __putchar, &_cnt_);
	current = hdl_current(_abs_, __putchar, &_cnt_);
	hdl_last_digit(current, __putchar, &_cnt_);

	/*returns the _cnt_ of prnted characters */
	return (_cnt_);
}

/**
 * hdl_sign - This function handles the sign of
 * a number and returns a string of digits in the specified base
 * @_num_: This variable is the number to handle
 * @flags: This variable is used to determine the base of the returned string
 * @n: This pointer refers to the absolute value of the number
 * @_sgn_: This pointer refers to the sign of the number
 *
 * Return: A string of digits in the specified base
 */
char *hdl_sign(long int _num_, int flags,
		unsigned long *n, char *_sgn_)
{
	(!(flags & CONVERT_UNSIGNED) && _num_ < 0) ?
		(*n = -_num_, *_sgn_ = '-') : (*n = _num_, *_sgn_ = 0);
	/* This function returns a string of digits in the specified base */
	return ((flags & CONVERT_LOWERCASE) ? "0123456789abcdef" :
			"0123456789ABCDEF");
}

/**
 * convert_base - This function converts a
 * number from base 10 to another base
 * @n: This pointer refers to the number to be converted
 * @base: This variable is the base to convert to
 * @_pttr_: This pointer refers to the location in
 * the buffer where the _rslt_ is stored
 * @array: This pointer refers to the array of characters used for conversion
 */
void convert_base(unsigned long *n, int base, char **_pttr_, char *array)
{
	/* use loop */
	do {
		*--(*_pttr_) = array[*n % base];
		*n /= base;
	} while (*n != 0);
}








