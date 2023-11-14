




#include "shell.h"

/**
 * _eputchar_loop - This function prints a character to the standard error
 * @_txt_: This pointer refers to the string to be printed
 * @_oops_: This variable is used as the _indx_ for the string
 */
void _eputchar_loop(char *_txt_, int _oops_)
{
	int j = _oops_; /*declaration*/

	if (_txt_[j] != '\0') /*use if*/
	{
		_e_put_char_(_txt_[j]);
		_eputchar_loop(_txt_, j + 1);
	}
}

/**
 * _ee_put_ - This function prints a string to the standard error
 * @_txt_: This pointer refers to the string to be printed
 */
void _ee_put_(char *_txt_)
{
	char *_tmpp_ = _txt_; /*declaration*/

	if (!_tmpp_)
		return;
	_eputchar_loop(_tmpp_, 0);
}

/**
 * _buffer_flush - This function flushes the _obuf_fer_
 * @_bbuuff_: This pointer refers to the _obuf_fer_ to be flushed
 * @_oops_: This variable is used as the _indx_ for the _obuf_fer_
 */
void _buffer_flush(char *_bbuuff_, int *_oops_)
{
	int j = *_oops_; /*declaration*/

	if (_oops_ == NULL) /*use if*/
		return;

	write(2, _bbuuff_, j);
	*_oops_ = 0;
}

/**
 * _e_put_char_ - This function writes a character to the _obuf_fer_
 * @_coco_c: This variable is the character to be written
 *
 * Return: 1 (success)
 */
int _e_put_char_(char _coco_c)
{
	static int _oops_; /*declaration*/
	static char _bbuuff_[_SIZE_BUFF_WRITE]; /*declaration*/
	char _tmpp_ = _coco_c; /*declaration*/

	if (_tmpp_ == _BUFFER_FLUSH || _oops_ >= _SIZE_BUFF_WRITE) /*use if*/
		_buffer_flush(_bbuuff_, &_oops_);

	if (_tmpp_ != _BUFFER_FLUSH) /*use if*/
		_bbuuff_[_oops_++] = _tmpp_;
	return (1); /*returns 1 on success*/
}

/**
 * _write_to_buffer - This function writes to a _obuf_fer_
 * @buf_ptr: This pointer refers to the _obuf_fer_ pointer
 * @_buff_end: This pointer refers to the _End of the _obuf_fer_
 * @_fl_dir_: This variable is the file descriptor
 */
void _write_to_buffer(char **buf_ptr, char *_buff_end, int _fl_dir_)
{
	int _ocntt_ = *buf_ptr - _buff_end; /*declaration*/

	if (_ocntt_ > 0) /*use if*/
	{
		write(_fl_dir_, _buff_end, _ocntt_);

		*buf_ptr = _buff_end;
	}
}

/**
 * _put_fdd_ - This function writes a character to a file descriptor
 * @_coco_c: This variable is the character to be written
 * @_fl_dir_: This variable is the file descriptor
 *
 * Return: 1 (success)
 */
int _put_fdd_(char _coco_c, int _fl_dir_)
{
	static char _bbuuff_[_SIZE_BUFF_WRITE]; /*declaration*/
	static char *buf_ptr = _bbuuff_; /*declaration*/

	if (_coco_c == _BUFFER_FLUSH || buf_ptr >= _bbuuff_ + _SIZE_BUFF_WRITE) /*use if*/
	{
		_write_to_buffer(&buf_ptr, _bbuuff_, _fl_dir_);
	}
	else
	{
		*buf_ptr = _coco_c;
		buf_ptr++;
	}
	return (1); /*returns 1 on success*/
}

/**
 * _putfd_loop - This function writes a string to a file descriptor
 * @_txt_: This pointer refers to the string to be written
 * @_fl_dir_: This variable is the file descriptor
 * @_oops_: This variable is used as the _indx_ for the string
 *
 * Return: _oops_ (the number of characters written)
 */
int _putfd_loop(char **_txt_, int _fl_dir_, int _oops_)
{
	if (!**_txt_) /*use if*/
		return (_oops_);

	_oops_ += _put_fdd_(**_txt_, _fl_dir_);
	(*_txt_)++;
	return (_putfd_loop(_txt_, _fl_dir_, _oops_));
	/*returns the number of characters written*/
}

/**
 * _put_s_fdd_ - This function writes a string to a file descriptor
 * @_txt_: This pointer refers to the string to be written
 * @_fl_dir_: This variable is the file descriptor
 *
 * Return: the number of characters written, or 0 if the string is NULL
 */
int _put_s_fdd_(char *_txt_, int _fl_dir_)
{
	return (_txt_ ? _putfd_loop(&_txt_, _fl_dir_, 0) : 0);

	/*returns the number of characters written, or 0 if the string is NULL*/
}

