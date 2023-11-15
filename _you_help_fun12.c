





#include "shell.h"

/**
 * _you_alpha_ - Checks if a character is alphabetic
 * @_coco_: Character to chk
 *
 * Return: 1 (is alphabetic), 0 (is not alphabetic)
 */
int _you_alpha_(int _coco_)
{
	if (_islower(_coco_) || _isupper(_coco_)) /*use if */
		return (1); /* Returns 1 if character is alphabetic */
	else
		return (0); /* Returns 0 if character is not alphabetic */
}

/**
 * process_sign - Processes the _sgn_ of a number
 * @_letter_: Character to chk
 * @_sgn_: Current _sgn_
 *
 * Return: -1 (negative), 1 (positive)
 */
int process_sign(char _letter_, int _sgn_)
{
	return ((_letter_ == '-') ? _sgn_ * -1 : _sgn_); /*use if */
}

/**
 * process_digit - Processes a digit character
 * @_letter_: Character to chk
 * @_rslt_: Current _rslt_
 * @_flg_: _Flg_ for processing
 *
 * Return: Updated _rslt_
 */
unsigned int process_digit(char _letter_, unsigned int _rslt_, int *_flg_)
{
	if (_letter_ >= '0' && _letter_ <= '9') /*use if */
	{
		*_flg_ = 1;
		_rslt_ = _rslt_ * 10 + (_letter_ - '0');
	}
	else if (*_flg_ == 1) /*use if */
		*_flg_ = 2;
	return (_rslt_); /* Returns updated _rslt_ */
}

/**
 * _fun_atoi_ - Converts a string to an integer
 * @_letter_: String to convert
 *
 * Return: Converted integer
 */
int _fun_atoi_(char *_letter_)
{
	int _OK_ = 0, _sgn_ = 1, _flg_ = 0;
	unsigned int _rslt_ = 0;

	do {
		_sgn_ = process_sign(_letter_[_OK_], _sgn_); /*use if */
		_rslt_ = process_digit(_letter_[_OK_], _rslt_, &_flg_); /*use if */
		_OK_++;
	} while (_letter_[_OK_] != '\0' && _flg_ != 2); /*use loop */

	return ((_sgn_ == -1) ? -_rslt_ : _rslt_); /* Returns converted integer */
}



