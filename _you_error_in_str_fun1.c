





#include "shell.h"

/**
 * _eputchar_loop - This function prnts a character to the standard error
 * @_txt_: This pointer refers to the string to be prnted
 * @_OK_: This variable is used as the _indx_ for the string
 */
void _eputchar_loop(char *_txt_, int _OK_)
{
	int _go_ = _OK_; /*declaration*/

	if (_txt_[_go_] != '\0') /*use if*/
	{
		_e_put_char_(_txt_[_go_]);
		_eputchar_loop(_txt_, _go_ + 1);
	}
}

/**
 * _ee_put_ - This function prnts a string to the standard error
 * @_txt_: This pointer refers to the string to be prnted
 */
void _ee_put_(char *_txt_)
{
	char *_tmp_ = _txt_; /*declaration*/

	if (!_tmp_)
		return;
	_eputchar_loop(_tmp_, 0);
}

/**
 * _buffer_flush - This function flushes the buffer
 * @_buff_: This pointer refers to the buffer to be flushed
 * @_OK_: This variable is used as the _indx_ for the buffer
 */
void _buffer_flush(char *_buff_, int *_OK_)
{
	int _go_ = *_OK_; /*declaration*/

	if (_OK_ == NULL) /*use if*/
		return;

	write(2, _buff_, _go_);
	*_OK_ = 0;
}

/**
 * _e_put_char_ - This function writes a character to the buffer
 * @_coco_: This variable is the character to be written
 *
 * Return: 1 (success)
 */
int _e_put_char_(char _coco_)
{
	static int _OK_; /*declaration*/
	static char _buff_[WRITE_BUF_SIZE]; /*declaration*/
	char _tmp_ = _coco_; /*declaration*/

	if (_tmp_ == BUF_FLUSH || _OK_ >= WRITE_BUF_SIZE) /*use if*/
		_buffer_flush(_buff_, &_OK_);

	if (_tmp_ != BUF_FLUSH) /*use if*/
		_buff_[_OK_++] = _tmp_;
	return (1); /*returns 1 on success*/
}

/**
 * _write_to_buffer - This function writes to a buffer
 * @buf_ptr: This pointer refers to the buffer pointer
 * @buf_end: This pointer refers to the end of the buffer
 * @_fl_dir_: This variable is the file descriptor
 */
void _write_to_buffer(char **buf_ptr, char *buf_end, int _fl_dir_)
{
	int _cnt_ = *buf_ptr - buf_end; /*declaration*/

	if (_cnt_ > 0) /*use if*/
	{
		write(_fl_dir_, buf_end, _cnt_);

		*buf_ptr = buf_end;
	}
}







