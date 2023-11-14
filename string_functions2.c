






#include "shell.h"

/**
 * _copy - This function copies a string to another string recursively
 * @dest: This pointer refers to the destination string
 * @src: This pointer refers to the source string
 * @_OK_: This variable is the current _indx_ in the source string
 *
 * Return: Pointer to the destination string
 */
char *_copy(char *dest, char *src, int _OK_)
{
	/* use if */
	if (src[_OK_])
	{
		dest[_OK_] = src[_OK_];
		return _copy(dest, src, _OK_ + 1);
	}
	dest[_OK_] = 0;
	/* This function returns a pointer to the destination string */
	return (dest);
}

/**
 * _str_cpy - This function copies a string to another string
 * @dest: This pointer refers to the destination string
 * @src: This pointer refers to the source string
 *
 * Return: Pointer to the destination string
 */
char *_str_cpy(char *dest, char *src)
{
	/* This function returns a pointer to the destination string */
	return ((dest == src || src == 0) ? dest : _copy(dest, src, 0));
}

/**
 * _strlen___ - This function returns the length of a string
 * @_txt_: This pointer refers to the string whose length to chk
 *
 * Return: The length of the string
 */
int _strlen___(const char *_txt_)
{
	int length = 0;
	const char *_letter_ = _txt_ ? _txt_ : "";

	/* use loop */
	while (*_letter_)
	{
		length++;
		_letter_++;
	}
	/* This function returns the length of the string */
	return (length);
}

/**
 * _str_dupp_ - This function duplicates a string
 * @_txt_: This pointer refers to the string to duplicate
 *
 * Return: Pointer to the duplicated string
 */
char *_str_dupp_(const char *_txt_)
{
	int length = _strlen___(_txt_);
	char *ret = (char *) malloc(sizeof(char) * (length + 1));

	/* use if */
	if (ret)
	{
		char *_oops_ = ret;
		const char *_letter_ = _txt_ ? _txt_ : "";

		/* use loop */
		while (*_letter_)
		{
			*_oops_ = *_letter_;
			_oops_++;
			_letter_++;
		}
		*_oops_ = '\0';
	}
	/* This function returns a pointer to the duplicated string */
	return (ret);
}

/**
 * _prnt_char - This function prnts a character
 * @_txt_: This pointer refers to the character to prnt
 * @end: This pointer refers to the end of the string
 */
void _prnt_char(char *_txt_, char *end)
{
	/* use if */
	if (_txt_ != end)
	{
		_pputt_char(*_txt_);
		_prnt_char(_txt_ + 1, end);
	}
}

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


