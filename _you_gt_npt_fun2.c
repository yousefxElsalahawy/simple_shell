


#include "shell.h"

/**
 * hdl_input - This function hdls input
 * @_data_: This pointer refers to the _data_ struct
 * @_buff_: This pointer refers to the buffer
 * @_long_: This pointer refers to the length
 *
 * Return: Number of bytes read or -1 if error
 */
ssize_t hdl_input(info_t *_data_, char **_buff_, size_t *_long_)
{
	ssize_t r;

	_pputt_char(BUF_FLUSH);

	r = input_buf(_data_, _buff_, _long_);

	/* Return the number of bytes read or -1 if error */
	return ((r == -1) ? -1 : r);
}

/**
 * init_iterator - This function initializes the iterator
 * @_OK_: This pointer refers to the size
 * @_go_: This pointer refers to the size
 * @_buff_: This pointer refers to the buffer
 * @_oops_: This pointer refers to the pointer
 *
 * Return: Nothing (void function)
 */
void init_iterator(size_t *_OK_, size_t *_go_, char *_buff_, char **_oops_)
{
	*_go_ = *_OK_; /* init new iterator to current _buff_ position */
	*_oops_ = _buff_ + *_OK_; /* get pointer for return */
}

/**
 * iterate_to_semicolon_or_end - This function iterates to semicolon or end
 * @_data_: This pointer refers to the _data_ struct
 * @_buff_: This pointer refers to the buffer
 * @_go_: This pointer refers to the size
 * @_long_: This pointer refers to the length
 *
 * Return: Nothing (void function)
 */
void iterate_to_semicolon_or_end(info_t *_data_,
		char *_buff_, size_t *_go_, size_t _long_)
{
	/*use loop */
	do {
		if (_s_chn_(_data_, _buff_, _go_))
			break;
		(*_go_)++;
	} while (*_go_ < _long_); /* iterate to semicolon or end */
}

/**
 * hdl_chain - This function hdls chains
 * @_data_: This pointer refers to the _data_ struct
 * @_buff_: This pointer refers to the buffer
 * @_OK_: This pointer refers to the size
 * @_go_: This pointer refers to the size
 * @_long_: This pointer refers to the length
 * @_oops_: This pointer refers to the pointer
 *
 * Return: Nothing (void function)
 */
void hdl_chain(info_t *_data_, char *_buff_,
		size_t *_OK_, size_t *_go_, size_t _long_, char **_oops_)
{
	init_iterator(_OK_, _go_, _buff_, _oops_);
	chk_chain(_data_, _buff_, _go_, *_OK_, _long_);
	iterate_to_semicolon_or_end(_data_, _buff_, _go_, _long_);
}

/**
 * _RESet_BuFFer_ - This function resets the buffer
 * @_data_: This pointer refers to the _data_ struct
 * @_OK_: This pointer refers to the size
 * @_long_: This pointer refers to the length
 *
 * Return: Nothing (void function)
 */
void _RESet_BuFFer_(info_t *_data_, size_t *_OK_, size_t *_long_)
{
	*_OK_ = *_long_ = 0; /* reset position and length */
	_data_->cmd_buf_type = CMD_NORM;
}























