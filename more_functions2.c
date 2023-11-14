







#include "shell.h"

/**
 * process_plus_sign - This function processes plus signs in a string
 * @_letter_: This pointer refers to the string to be processed
 *
 * Return: Pointer to the first character after the plus signs
 */
char *process_plus_sign(char *_letter_)
{
	char *_oops_ = _letter_; /* This pointer refers to the string _letter_ */

	/* use loop */
	do {
		_oops_++;
	} while (*_oops_ == '+');

	/*returns a pointer to first character after plus signs */
	return (_oops_);
}

/**
 * process_digits - This function processes digits in a string
 * @_letter_: This pointer refers to the string to be processed
 *
 * Return: The processed number if successful, -1 otherwise
 */
unsigned long int process_digits(char *_letter_)
{
	unsigned long int _rslt_ = 0;
	char current_char = *_letter_;

	/* use loop */
	do {
		/* use if */
		if (current_char >= '0' && current_char <= '9')
		{
			_rslt_ = (_rslt_ << 3) + (_rslt_ << 1) + (current_char - '0');
			/* use if */
			if (_rslt_ > INT_MAX)
				/* This function returns -1 if the _rslt_ is greater than INT_MAX */
				return (-1);
		}
		else
			/* This function returns -1 if the current character is not a digit */
			return (-1);

		current_char = *(++_letter_);
	} while (current_char != '\0');

	/* This function returns the processed number */
	return (_rslt_);
}

/**
 * _fun_err_atoi_ - This function converts a string to an integer
 * @_letter_: This pointer refers to the string to be converted
 *
 * Return: The converted number if successful, -1 otherwise
 */
int _fun_err_atoi_(char *_letter_)
{
	_letter_ = process_plus_sign(_letter_);

	/* This function returns the _rslt_ of process_digits */
	return (process_digits(_letter_));
}

/**
 * prnt_message - This function prnts a message
 * @message: This pointer refers to the message to be prnted
 */
void prnt_message(char *message)
{
	_ee_put_(message);
	_ee_put_(": ");
}

/**
 * prnt_error_part1 - This function prnts the first part of an error message
 * @_data_: This pointer refers to the _data_ struct
 */
void prnt_error_part1(info_t *_data_)
{
	prnt_message(_data_->fname);
}

/**
 * prnt_error_part2 - This function prnts the second part of an error message
 * @_data_: This pointer refers to the _data_ struct
 */
void prnt_error_part2(info_t *_data_)
{
	_prnt_dir_(_data_->line_count, STDERR_FILENO);
	_ee_put_(": ");
}

/**
 * prnt_error_part3 - This function prnts the third part of an error message
 * @_data_: This pointer refers to the _data_ struct
 * @estr: This pointer refers to the error string
 */
void prnt_error_part3(info_t *_data_, char *estr)
{
	prnt_message(_data_->argv[0]);
	prnt_message(estr);
}

/**
 * _prnt_err_ - This function prnts an error message
 * @_data_: This pointer refers to the _data_ struct
 * @estr: This pointer refers to the error string
 */
void _prnt_err_(info_t *_data_, char *estr)
{
	prnt_error_part1(_data_);
	prnt_error_part2(_data_);
	prnt_error_part3(_data_, estr);
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
 * @_cnt_: This pointer refers to the _cnt_
 *
 * Return: The absolute _vle_ of the input
 */
unsigned int hdl_abs(int input, int
		(*__putchar)(char), int *_cnt_)
{
	unsigned int _abs_;

	/* use if */
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		(*_cnt_)++;
	}
	else
		_abs_ = input;

	/* This function returns absolute _vle_ of input */
	return (_abs_);
}

/**
 * @abs_: This variable is the absolute _vle_ of the input
 *
 * Return: The current _vle_
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
	/* This function returns the current _vle_ */
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
 * cnvrt_nmbr_ - converter function, a clone of itoa
 * @_num_: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
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

/**
 * hdl_negative_sign - This function h
 * ls the negative _sgn_ of a number
 * @_pttr_: This pointer refers to
 * he location in the buffer where the _rslt_ is stored
 * @_sgn_: This variable is the _sgn_ of the number
 */
void hdl_negative_sign(char **_pttr_, char _sgn_)
{
	/* use if */
	if (_sgn_)
		*--(*_pttr_) = _sgn_;
}

/**
 * cnvrt_nmbr_ - This function con
 * verts a number to a string in a specified base
 * @_num_: This variable is the number to be converted
 * @base: This variable is the base to convert to
 * @flags: This variable is the flags for conversion
 *
 * Return: Pointer to the converted number string
 */
char *cnvrt_nmbr_(long int _num_, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char _sgn_ = 0;
	char *_pttr_;
	unsigned long n;

	array = hdl_sign(_num_, flags, &n, &_sgn_);
	_pttr_ = &buffer[49];
	*_pttr_ = '\0';

	/* use loop */
	do {
		convert_base(&n, base, &_pttr_, array);
	} while (n != 0);

	hdl_negative_sign(&_pttr_, _sgn_);

	/* This function returns a pointer to the converted number string */
	return (_pttr_);
}

/**
 * set_to_null - This function sets all characters in a string to '\0'
 * @_oops_: This pointer refers to the string to be set to null
 */
void set_to_null(char *_oops_)
{
	/* use loop */
	do {
		*_oops_ = '\0';
		_oops_++;
	} while (*_oops_ != '\0');
}

/**
 * _rmove_com_ - This function removes comments from a string
 * @_buff_: This pointer refers to the string to remove comments from
 */
void _rmove_com_(char *_buff_)
{
	char *_oops_ = _buff_;

	/* use loop */
	do {
		/* use if */
		if (*_oops_ == '#' && (_oops_ == _buff_ || *(_oops_ - 1) == ' '))
			set_to_null(_oops_);
		else
			_oops_++;
	} while (*_oops_ != '\0');
}


