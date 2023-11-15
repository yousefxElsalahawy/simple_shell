

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





