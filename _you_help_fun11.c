





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
	return (_CHEcK_chARs_(_coco_, _dlm_));
	/* Returns 1 if is delimiter, 0 if not */
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




