



#include "shell.h"


/**
 * _put_ss_ - This function prnts a string
 * @_txt_: This pointer refers to the string to prnt
 */
void _put_ss_(char *_txt_)
{
	char *end = _txt_;

	/* use loop */
	while (*end)
		++end;
	/* use if */
	if (_txt_)
	{
		_prnt_char(_txt_, end);
	}
	else
	{
		return;
	}
}

/**
 * write_buffer - This function writes a buffer to the standard output
 * @_buff_: This pointer refers to the buffer to write
 * @_OK_: This pointer refers to the current _indx_ in the buffer
 */
void write_buffer(char *_buff_, int *_OK_)
{
	write(1, _buff_, *_OK_);
	*_OK_ = 0;
}

/**
 * add_to_buffer - This function adds a character to a buffer
 * @_buff_: This pointer refers to the buffer to add to
 * @_OK_: This pointer refers to the current _indx_ in the buffer
 * @_coco_: This variable is the character to add
 */
void add_to_buffer(char *_buff_, int *_OK_, char _coco_)
{
	_buff_[(*_OK_)++] = _coco_;
}

/**
 * _pputt_char - This function writes a character to the standard output
 * @_coco_: This variable is the character to write
 *
 * Return: 1 (success)
 */
int _pputt_char(char _coco_)
{
	static int _OK_;
	static char _buff_[WRITE_BUF_SIZE];

	/* use if */
	if (_coco_ == BUF_FLUSH || _OK_ >= WRITE_BUF_SIZE)
	{
		write_buffer(_buff_, &_OK_);
	}
	else
	{
		add_to_buffer(_buff_, &_OK_, _coco_);
	}
	/* This function returns 1 on success */
	return (1);
}



