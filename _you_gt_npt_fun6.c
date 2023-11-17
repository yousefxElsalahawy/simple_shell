#include "shell.h"




/**
 * _bffer_rder_ad_chckr_ - This function reads the
 * uffer and checks for any errors
 * @_data_: This pointer refers to the data structure
 * @_buff_: This variable is used to store the buffer
 * @_long_: This variable is used to store the length of the buffer
 *
 * Return: -1 (error), or the result of the buffer reader
 */
ssize_t _bffer_rder_ad_chckr_(info_t *_data_, char *_buff_, size_t *_long_)
{
	ssize_t _savar_ = buffer_reader(_data_, _buff_, _long_);

	/*use if */
	if (_savar_ == -1 || (_savar_ == 0 && *_long_ == 0))
	{
		/* Return -1 if error */
		return (-1);
	}
	return (_savar_); /* Returns the result of the buffer reader */
}

/**
 * _memy_alloca_nd_cppy_ - This function allocates memory and copies the buffer
 * @_oops_: This pointer refers to the original buffer
 * @_letter_: This variable is used to store the length of the original buffer
 * @_koK_: This variable is used to store the length of the new buffer
 * @_buff_: This variable is used to store the buffer
 * @_OK_: This variable is used to store the length of the buffer
 *
 * Return: NULL (error), or the new buffer
 */
char *_memy_alloca_nd_cppy_(char *_oops_, size_t _letter_,
		size_t _koK_, char *_buff_, size_t _OK_)
{
	char *_onw_oop = memory_allocator(_oops_, _letter_, _koK_);

	/*use if */
	if (!_onw_oop)
		/* Return NULL if memory allocation fails */
		return (NULL);
	buffer_copier(_onw_oop, _buff_, _OK_, _koK_, _letter_);
	return (_onw_oop); /* Returns the new buffer */
}

/**
 * _up_dte_vles_ - This function updates the values of the variables
 * @_oops_: This pointer refers to the original buffer
 * @_letter_: This variable is used to store the length of the original buffer
 * @_OK_: This variable is used to store the length of the buffer
 * @_koK_: This variable is used to store the length of the new buffer
 * @length: This variable is used to store the length of the new buffer
 *
 * Return: void
 */
void _up_dte_vles_(char **_oops_, size_t *_letter_,
		size_t *_OK_, size_t _koK_, char **_onw_oop, size_t *length)
{
	*_letter_ += _koK_ - *_OK_;
	/*use if */
	*_OK_ = _koK_;
	*_oops_ = *_onw_oop;


	if (length)
		*length = *_letter_;
}


/**
 * _gt_lne_ - This function gets a line from the buffer
 * @_data_: This pointer refers to the data structure
 * @_pttr_: This pointer refers to the pattern
 * @length: This variable is used to store the length of the new buffer
 *
 * Return: -1 (error), or the size of the new line
 */
int _gt_lne_(info_t *_data_, char **_pttr_, size_t *length)
{
	/*declaration*/
	static size_t _OK_, _long_;
	ssize_t _savar_ = 0;
	size_t _letter_ = 0;

	char *_oops_ = NULL, *_onw_oop = NULL, *_coco_;
	static char _buff_[READ_BUF_SIZE];
	size_t _koK_;

	_oops_ = *_pttr_;

	if (_oops_ && length)
	{
		/*use if */
		_letter_ = *length;
	}
	if (_long_ == _OK_)
	{
		/*use if*/
		_OK_ = _long_ = 0;
	}
	_savar_ = _bffer_rder_ad_chckr_(_data_, _buff_, &_long_);
	if (_savar_ == -1)
	{
		return (-1);
		/* Returns -1 if there is an error */
	}
	_coco_ = locate_newline(_buff_, _OK_);
	_koK_ = _coco_ ? 1 + (unsigned int)(_coco_ - _buff_) : _long_;
	_onw_oop = _memy_alloca_nd_cppy_(_oops_, _letter_, _koK_, _buff_, _OK_);
	if (!_onw_oop)
	{
		return (-1);
		/* Returns -1 if there is an error */
	}
	_up_dte_vles_(&_oops_, &_letter_, &_OK_, _koK_, &_onw_oop, length);
	*_pttr_ = _oops_;
	/* Return the size of the new line */
	return (_letter_); /* Returns the size of the new line */
}



