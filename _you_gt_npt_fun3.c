#include "shell.h"








/**
 * _hnde_inut_ - This function handles the input
 * @_data_: This pointer refers to the _data_ struct
 * @_buff_: This pointer refers to the buffer
 * @_long_: This pointer refers to the size
 *
 * Return: Result of hdl_input function
 */
ssize_t _hnde_inut_(info_t *_data_, char **_buff_, size_t *_long_)
{
	/*use if*/
	return (hdl_input(_data_, _buff_, _long_));
}

/**
 * _hnde_chin_ - This function handles the chain buffer
 * @_data_: This pointer refers to the _data_ struct
 * @_buff_: This pointer refers to the buffer
 * @_OK_: This pointer refers to the size
 * @_go_: This pointer refers to the size
 * @_long_: This pointer refers to the size
 * @_oops_: This pointer refers to the old buffer
 *
 * Return: Length of current command
 */
ssize_t _hnde_chin_(info_t *_data_, char **_buff_,
		size_t *_OK_, size_t *_go_, size_t *_long_, char **_oops_)
{
	/*use if*/
	hdl_chain(_data_, *_buff_, _OK_, _go_, *_long_, _oops_);

	*_OK_ = *_go_ + 1; /* increment past nulled ';'' */

	if (*_OK_ >= *_long_)
	{
		/* reached end of buffer? */
		_RESet_BuFFer_(_data_, _OK_, _long_);
	}
	/* Return length of current command */
	return (_str_len_(*_oops_));
}

/**
 * gt_userinpt_ - This function gets input
 * @_data_: This pointer refers to the _data_ struct
 *
 * Return: Length of current command or -1 if error
 */

ssize_t gt_userinpt_(info_t *_data_)
{
	static char *_buff_;
	/* the ';' command chain buffer */
	static size_t _OK_, _go_, _long_;

	/*Initialize _oops_ to NU    LL*/
	char **buf_p = &(_data_->arg), *_oops_ = NULL;

	ssize_t r = _hnde_inut_(_data_, &_buff_, &_long_);

	if (r == -1)
		/* Return -1 if error */
		return (-1);

	if (_long_)     /* we have commands left in the chain buffer */
	{
		*buf_p = _oops_; /* pass back pointer to current command position */

		/* Return length of current command */
		return (_hnde_chin_(_data_, &_buff_, &_OK_, &_go_, &_long_, buf_p));
	}

	*buf_p = _buff_;
	/* else not a chain, pass back buffer from _gt_lne_() */

	/* Return length of buffer from _gt_lne_() */
	return (r);
}
