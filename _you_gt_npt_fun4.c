#include "shell.h"






/**
 * memory_allocator - This function allocates memory
 * @_oops_: This pointer refers to buffer
 * @_letter_: This variable is used to check if size is not zero
 * @_koK_: This variable is used to check if size is not zero
 *
 * Return: The newly allocated memory or NULL if memory allocation fails
 */
char *memory_allocator(char *_oops_, size_t _letter_, size_t _koK_)
{
	char *_onw_oop;

	_onw_oop = _rea_lloc_(_oops_, _letter_, _letter_ ?
			_letter_ + _koK_ : _koK_ + 1);

	if (!_onw_oop) /* MALLOC FAILURE! */
	{
		if (_oops_)
			free(_oops_);
		/* Return NULL if memory allocation fails */
		return (NULL);
	}
	/* Return the newly allocated memory */
	return (_onw_oop);
}
/**
 * buffer_copier - This function copies the buffer
 * @_onw_oop: This pointer refers to the new buffer
 * @_buff_: This pointer refers to the buffer
 * @_OK_: This pointer refers to the size
 * @_koK_: This pointer refers to the size
 * @_letter_: This pointer refers to the size
 *
 * Return: Nothing (void function)
 */
void buffer_copier(char *_onw_oop, char *_buff_,
		size_t _OK_, size_t _koK_, size_t _letter_)
{
	/*use if*/

	_letter_ ? _str_n_cat(_onw_oop, _buff_ + _OK_, _koK_ - _OK_) :
		_strr_ncpy_(_onw_oop, _buff_ + _OK_, _koK_ - _OK_ + 1);
}

/**
 * _gt_lne_ - This function gets the _nxt_ line of input from STDIN
 * @_data_: parameter struct
 * @_pttr_: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated _pttr_ buffer if not NULL
 *
 * Return: _letter_
 */
int _gt_lne_(info_t *_data_, char **_pttr_, size_t *length)
{
	/*decleration*/
	char *_oops_ = NULL, *_onw_oop = NULL, *_coco_;
	size_t _koK_;
	static char _buff_[READ_BUF_SIZE];
	static size_t _OK_, _long_;
	ssize_t r = 0, _letter_ = 0;

	_oops_ = *_pttr_;

	if (_oops_ && length)
		_letter_ = *length;

	if (_long_ == _OK_)
		_OK_ = _long_ = 0;

	r = buffer_reader(_data_, _buff_, &_long_);
	if (r == -1 || (r == 0 && _long_ == 0))
		/* Return -1 if error */
		return (-1);

	_coco_ = locate_newline(_buff_, _OK_);
	_koK_ = _coco_ ? 1 + (unsigned int)(_coco_ - _buff_) : _long_;
	_onw_oop = memory_allocator(_oops_, _letter_, _koK_);

	if (!_onw_oop)
		/* Return -1 if memory allocation fails */
		return (-1);

	buffer_copier(_onw_oop, _buff_, _OK_, _koK_, _letter_);

	_letter_ += _koK_ - _OK_;
	_OK_ = _koK_;
	_oops_ = _onw_oop;

	if (length)
		*length = _letter_;

	*_pttr_ = _oops_;
	/* Return the size of the new line */
	return (_letter_);
}

/**
 * sgn_Her_ - blocks ctrl-_coco_
 * @sig_num: the signal number
 *
 * Return: void
 */
void sgn_Her_(__attribute__((unused))int sig_num)
{
	/*decleration*/
	char *output = "\n$ ";

	if (output)
	{
		do {
			_pputt_char(*output == '\n' ? '\n' : *output == '$' ? '$' : ' ');
			output++;
		} while (*output);
	}
	_pputt_char(BUF_FLUSH);
}


