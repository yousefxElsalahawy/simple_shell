





#include "shell.h"

/**
 * _put_fdd_ - This function writes a character to a file descriptor
 * @_coco_: This variable is the character to be written
 * @_fl_dir_: This variable is the file descriptor
 *
 * Return: 1 (success)
 */
int _put_fdd_(char _coco_, int _fl_dir_)
{
	static char _buff_[WRITE_BUF_SIZE]; /*declaration*/
	static char *buf_ptr = _buff_; /*declaration*/

	if (_coco_ == BUF_FLUSH || buf_ptr >= _buff_ + WRITE_BUF_SIZE) /*use if*/
	{
		_write_to_buffer(&buf_ptr, _buff_, _fl_dir_);
	}
	else
	{
		*buf_ptr = _coco_;
		buf_ptr++;
	}
	return (1); /*returns 1 on success*/
}

/**
 * _putfd_loop - This function writes a string to a file descriptor
 * @_txt_: This pointer refers to the string to be written
 * @_fl_dir_: This variable is the file descriptor
 * @_OK_: This variable is used as the _indx_ for the string
 *
 * Return: _OK_ (the number of characters written)
 */
int _putfd_loop(char **_txt_, int _fl_dir_, int _OK_)
{
	if (!**_txt_) /*use if*/
		return (_OK_);
	_OK_ += _put_fdd_(**_txt_, _fl_dir_);
	(*_txt_)++;
	return (_putfd_loop(_txt_, _fl_dir_, _OK_));
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



