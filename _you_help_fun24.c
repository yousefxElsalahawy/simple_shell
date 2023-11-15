




#include "shell.h"


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



