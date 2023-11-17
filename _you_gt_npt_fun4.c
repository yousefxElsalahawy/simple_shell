#include "shell.h"
/**
 * read_from_fd - This function reads from a file descriptor into a buffer
 * @_data_: This pointer refers to an
 * nfo_t struct containing the file descriptor
 * @_buff_: This pointer refers t
 * the buffer where the read data will be stored
 *
 * This function uses the read
 * system call to read from a file descriptor into a buffer.
 * The result of the read operation is stored in the variable r.
 *
 * Return: The number of bytes read,
 * or -1 if an error occurred during the read operation
 */
ssize_t read_from_fd(info_t *_data_, char *_buff_)
{
	ssize_t r;

	r = read(_data_->readfd, _buff_, READ_BUF_SIZE);
	/* Return the number of bytes read or -1 if error */
	return ((r >= 0) ? r : -1);
}

/**
 * _rd_buff_ - This function reads a buffer and checks for any errors
 * @_data_: This pointer refers to the data structure
 * @_buff_: This pointer refers to the b
 * ffer where the read data will be stored
 * @_OK_: This variable is used to store the length of the data read
 *Return: The number of bytes read,
 or -1 if an error occurred during the read operation
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
