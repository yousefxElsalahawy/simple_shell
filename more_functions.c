





#include "shell.h"

/**
 * _inter_active - Checks if the shell is _inter_active
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: 1 (_inter_active), 0 (non-_inter_active)
 */
int _inter_active(_info_OK *_data_)
{
	int _rultt_;
	int is_interactive = isatty(STDIN_FILENO); /*use if */

	int is_readfd_valid = _data_->_read_fd_ <= 2; /*use if */

	_rultt_ = is_interactive && is_readfd_valid; /*use if */

	return (_rultt_); /* Returns 1 if _inter_active, 0 if not */
}

/**
 * _CHEcK_chARs_ - Checks if a character is in a string
 * @_coco_c: Character to chk
 * @_tmpp_: String to chk in
 *
 * Return: 1 (character is in string), 0 (character is not in string)
 */
int _CHEcK_chARs_(char _coco_c, char *_tmpp_)
{
	while (*_tmpp_) /*use loop */
	{
		if (_coco_c == *_tmpp_++) /*use if */
		{
			return (1); /* Returns 1 if character is in string */
		}
	}
	return (0); /* Returns 0 if character is not in string */
}

/**
 * _my_delm - Checks if a character is a delimiter
 * @_coco_c: Character to chk
 * @delim: Delimiter to chk against
 *
 * Return: 1 (is delimiter), 0 (is not delimiter)
 */
int _my_delm(char _coco_c, char *delim)
{
	return (_CHEcK_chARs_(_coco_c, delim)); /* Returns 1 if is delimiter, 0 if not */
}

/**
 * _islower - Checks if a character is lowercase
 * @_coco_c: Character to chk
 *
 * Return: 1 (is lowercase), 0 (is not lowercase)
 */
int _islower(int _coco_c)
{
	if (_coco_c >= 'a' && _coco_c <= 'z') /*use if */
		return (1); /* Returns 1 if character is lowercase */
	else
		return (0); /* Returns 0 if character is not lowercase */
}

/**
 * _isupper - Checks if a character is uppercase
 * @_coco_c: Character to chk
 *
 * Return: 1 (is uppercase), 0 (is not uppercase)
 */
int _isupper(int _coco_c)
{
	if (_coco_c >= 'A' && _coco_c <= 'Z') /*use if */
		return (1); /* Returns 1 if character is uppercase */
	else
		return (0); /* Returns 0 if character is not uppercase */
}

/**
 * _you_alpha_ - Checks if a character is alphabetic
 * @_coco_c: Character to chk
 *
 * Return: 1 (is alphabetic), 0 (is not alphabetic)
 */
int _you_alpha_(int _coco_c)
{
	if (_islower(_coco_c) || _isupper(_coco_c)) /*use if */
		return (1); /* Returns 1 if character is alphabetic */
	else
		return (0); /* Returns 0 if character is not alphabetic */
}

/**
 * process_sign - Processes the _ssgnn_ of a number
 * @_aso_: Character to chk
 * @_ssgnn_: Current _ssgnn_
 *
 * Return: -1 (negative), 1 (positive)
 */
int process_sign(char _aso_, int _ssgnn_)
{
	return ((_aso_ == '-') ? _ssgnn_ * -1 : _ssgnn_); /*use if */
}

/**
 * process_digit - Processes a digit character
 * @_aso_: Character to chk
 * @_rultt_: Current _rultt_
 * @_flg_: _flg_ for processing
 *
 * Return: Updated _rultt_
 */
unsigned int process_digit(char _aso_, unsigned int _rultt_, int *_flg_)
{
	if (_aso_ >= '0' && _aso_ <= '9') /*use if */
	{
		*_flg_ = 1;
		_rultt_ = _rultt_ * 10 + (_aso_ - '0');
	}
	else if (*_flg_ == 1) /*use if */
		*_flg_ = 2;
	return (_rultt_); /* Returns updated _rultt_ */
}

/**
 * _fun_atoi_ - Converts a string to an integer
 * @_aso_: String to convert
 *
 * Return: Converted integer
 */
int _fun_atoi_(char *_aso_)
{
	int _oops_ = 0, _ssgnn_ = 1, _flg_ = 0;
	unsigned int _rultt_ = 0;

	do {
		_ssgnn_ = process_sign(_aso_[_oops_], _ssgnn_); /*use if */
		_rultt_ = process_digit(_aso_[_oops_], _rultt_, &_flg_);
        /*use if */
		_oops_++;
	} while (_aso_[_oops_] != '\0' && _flg_ != 2);
    /*use loop */

	return ((_ssgnn_ == -1) ? -_rultt_ : _rultt_);
    /* Returns converted integer */
}





