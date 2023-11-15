






#include "shell.h"

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













