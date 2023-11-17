#include "shell.h"




/**
 * buffer_reader - This function reads from a file
 * descriptor into a buffer
 * @_data_: This pointer refers to an info_t stru
 * ct containing the file descriptor
 * @_buff_: This pointer refers to the buf
 * fer where the read data will be stored
 * @_long_: This variable is used to store the length of the data read
 *
 * Return: The number of bytes read,
 * or -1 if an error occurred during the read operation
 */
ssize_t buffer_reader(info_t *_data_, char *_buff_,
		size_t *_long_)
{
	ssize_t _savar_ = 0;
	/* This variable is used to store the result of the read operation */

	/* Use if statement */
	if (!*_long_)
	{
		_savar_ = read(_data_->readfd, _buff_, READ_BUF_SIZE);
		/* Perform the read operation */
		*_long_ = (_savar_ >= 0) ? _savar_ : 0;
		/* Store the length of the data read */
	}

	/* Return the number of bytes read or -1 if error */
	return (_savar_);
}
/**
 * locate_newline - This function locates a newline
 * @_buff_: This pointer refers to the buffer
 * @_OK_: This pointer refers to the size
 *
 * Return: Pointer to newline or NULL
 */
char *locate_newline(char *_buff_, size_t _OK_)
{
	/* Use while loop */
	while (_buff_[_OK_])
	{
		if (_buff_[_OK_] == '\n')
			return (_buff_ + _OK_);
		_OK_++;
	}

	/* Return NULL if no newline found */
	return (NULL);
}

/**
 * memory_allocator - This function allocates memory
 * @_oops_: This pointer refers to the old buffer
 * @_letter_: This pointer refers to the size
 * @_koK_: This pointer refers to the size
 *
 * Return: Pointer to newly allocated memory
 */
char *memory_allocator(char *_oops_, size_t _letter_, size_t _koK_)
{
	char *_onw_oop;

	/* Allocate memory */
	_onw_oop = malloc(_letter_ + _koK_ + 1);
	if (!_onw_oop)
		return (NULL);

	/* Use if statement */
	if (_oops_)
	{
		_strr_ncpy_(_onw_oop, _oops_, _letter_);
		free(_oops_);
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
void buffer_copier(char *_onw_oop, char *_buff_, size_t _OK_,
		size_t _koK_, size_t _letter_)
{
	/*use if*/

	_letter_ ? _str_n_cat(_onw_oop, _buff_ + _OK_, _koK_ - _OK_)
		: _strr_ncpy_(_onw_oop, _buff_ + _OK_, _koK_ - _OK_ + 1);
}


