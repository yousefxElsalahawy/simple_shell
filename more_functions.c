





#include "shell.h"

/**
 * _inter_active - Checks if the shell is _inter_active
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: 1 (_inter_active), 0 (non-_inter_active)
 */
int _inter_active(info_t *_data_)
{
	int _rslt_;
	int is_interactive = isatty(STDIN_FILENO); /*use if */

	int is_readfd_valid = _data_->readfd <= 2; /*use if */

	_rslt_ = is_interactive && is_readfd_valid; /*use if */

	return (_rslt_); /* Returns 1 if _inter_active, 0 if not */
}

/**
 * _CHEcK_chARs_ - Checks if a character is in a string
 * @_coco_: Character to chk
 * @_tmp_: String to chk in
 *
 * Return: 1 (character is in string), 0 (character is not in string)
 */
int _CHEcK_chARs_(char _coco_, char *_tmp_)
{
	while (*_tmp_) /*use loop */
	{
		if (_coco_ == *_tmp_++) /*use if */
		{
			return (1); /* Returns 1 if character is in string */
		}
	}
	return (0); /* Returns 0 if character is not in string */
}

/**
 * _my_delm - Checks if a character is a delimiter
 * @_coco_: Character to chk
 * @_dlm_: Delimiter to chk against
 *
 * Return: 1 (is delimiter), 0 (is not delimiter)
 */
int _my_delm(char _coco_, char *_dlm_)
{
	return (_CHEcK_chARs_(_coco_, _dlm_)); /* Returns 1 if is delimiter, 0 if not */
}

/**
 * _islower - Checks if a character is lowercase
 * @_coco_: Character to chk
 *
 * Return: 1 (is lowercase), 0 (is not lowercase)
 */
int _islower(int _coco_)
{
	if (_coco_ >= 'a' && _coco_ <= 'z') /*use if */
		return (1); /* Returns 1 if character is lowercase */
	else
		return (0); /* Returns 0 if character is not lowercase */
}

/**
 * _isupper - Checks if a character is uppercase
 * @_coco_: Character to chk
 *
 * Return: 1 (is uppercase), 0 (is not uppercase)
 */
int _isupper(int _coco_)
{
	if (_coco_ >= 'A' && _coco_ <= 'Z') /*use if */
		return (1); /* Returns 1 if character is uppercase */
	else
		return (0); /* Returns 0 if character is not uppercase */
}

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


