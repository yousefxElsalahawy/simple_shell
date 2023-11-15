


#include "shell.h"

/**
 * gt_userinpt_ - This function gets input
 * @_data_: This pointer refers to the _data_ struct
 *
 * Return: Length of current command or -1 if error
 */
ssize_t gt_userinpt_(info_t *_data_)
{
	static char *_buff_; /* the ';' command chain buffer */
	static size_t _OK_, _go_, _long_;
	char **buf_p = &(_data_->arg), *_oops_;

	ssize_t r = hdl_input(_data_, &_buff_, &_long_);

	if (r == -1)
		/* Return -1 if error */
		return (-1);

	if (_long_)	/* we have commands left in the chain buffer */
	{
		hdl_chain(_data_, _buff_, &_OK_, &_go_, _long_, &_oops_);

		_OK_ = _go_ + 1; /* increment past nulled ';'' */
		if (_long_ >= _OK_) /* reached end of buffer? */
			_RESet_BuFFer_(_data_, &_OK_, &_long_);

		*buf_p = _oops_; /* pass back pointer to current command position */

		/* Return length of current command */
		return (_str_len_(_oops_));
	}

	*buf_p = _buff_; /* else not a chain, pass back buffer from _gt_lne_() */
	/* Return length of buffer from _gt_lne_() */
	return (r);
}

/**
 * read_from_fd - This function reads from a file descriptor
 * @_data_: This pointer refers to the info_t struct
 * @_buff_: This pointer refers to the buffer
 * where the read data will be stored
 *
 * Return: The number of bytes read or -1 if an error occurred
 */
ssize_t read_from_fd(info_t *_data_, char *_buff_)
{
	ssize_t r;

	r = read(_data_->readfd, _buff_, READ_BUF_SIZE);
	/* Return the number of bytes read or -1 if error */
	return ((r >= 0) ? r : -1);
}

/**
 * _rd_buff_ - This function reads from a file descriptor if a condition is met
 * @_data_: This pointer refers to the info_t struct
 * @_buff_: This pointer refers to the buffer where
 * the read data will be stored
 * @_OK_: This pointer refers to a size_t variabl
 *  used as a condition for reading
 *
 * Return: The number of bytes read or -1 if an error occurred
 */
ssize_t _rd_buff_(info_t *_data_, char *_buff_, size_t *_OK_)
{
	ssize_t r = 0;

	/* Use if statement */
	if (!*_OK_)
	{
		r = read_from_fd(_data_, _buff_);
		*_OK_ = (r >= 0) ? r : 0;
	}

	/* Return the number of bytes read or -1 if error */
	return (r);
}

/**
 * buffer_reader - This function reads from a file
 * descriptor if a condition is met
 * @_data_: This pointer refers to the info_t struct
 * @_buff_: This pointer refers to the buffer
 * where the read data will be stored
 * @_long_: This pointer refers to a size_t
 * variable used as a condition for reading
 *
 * Return: The number of bytes read or -1 if an error occurred
 */
ssize_t buffer_reader(info_t *_data_, char *_buff_, size_t *_long_)
{
	ssize_t r = 0;

	/* Use if statement */
	if (!*_long_)
	{
		r = read(_data_->readfd, _buff_, READ_BUF_SIZE);
		*_long_ = (r >= 0) ? r : 0;
	}

	/* Return the number of bytes read or -1 if error */
	return (r);
}

/**
 * locate_newline - This function locates the newline character in a buffer
 * @_buff_: This pointer refers to the buffer where
 * the newline character will be searched
 * @_OK_: This size_t variable is used to offset the buffer
 *
 * Return: The position of the newline character or NULL if not found
 */
char *locate_newline(char *_buff_, size_t _OK_)
{
	/* Return the position of the newline character or NULL if not found */
	return (_str_n_chr(_buff_ + _OK_, '\n'));
}




