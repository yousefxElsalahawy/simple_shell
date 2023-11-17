





#include "shell.h"

/**
 * reset_buffer - This function resets the buffer
 * @_buff_: This pointer refers to the buffer
 *
 * Return: Nothing (void function)
 */
void reset_buffer(char **_buff_)
{
	/* Use if statement */
	if (!_buff_ || !*_buff_)
		return;
	/* Use if statement */
	if (*_buff_)
	{
		free(*_buff_);
		*_buff_ = NULL;
	}
	signal(SIGINT, sgn_Her_);
}

/**
 * input_reader - This function reads input
 * @_data_: This pointer refers to the _data_ struct
 * @_buff_: This pointer refers to the buffer
 * @len_p: This pointer refers to the length
 *
 * Return: Number of bytes read
 */
ssize_t input_reader(info_t *_data_, char **_buff_, size_t *len_p)
{
	ssize_t _fpp_ = 0;

	/* Use conditional compilation */
#if USE_GETLINE
	_fpp_ = getline(_buff_, len_p, stdin);
#else
	_fpp_ = _gt_lne_(_data_, _buff_, len_p);
#endif
	/* Return the number of bytes read */
	return (_fpp_);
}

/**
 * input_processor - This function processes input
 * @_buff_: This pointer refers to the buffer
 * @_fpp_: This pointer refers to the length
 *
 * Return: Nothing (void function)
 */
void input_processor(char **_buff_, ssize_t *_fpp_)
{
	/* Use if statement */
	if (!_buff_ || !*_buff_ || !_fpp_)
		return;

	do {
		(*_buff_)[*_fpp_ - 1] = '\0';
		(*_fpp_)--;
	} while (*_fpp_ > 0 && (*_buff_)[*_fpp_ - 1] == '\n');
}

/**
 * command_chain_hdlr - This function hdls command chains
 * @_data_: This pointer refers to the _data_ struct
 * @_buff_: This pointer refers to the buffer
 * @_long_: This pointer refers to the length
 * @_fpp_: This pointer refers to the length
 *
 * Return: Nothing (void function)
 */
void command_chain_hdlr(info_t *_data_,
		char **_buff_, size_t *_long_, ssize_t _fpp_)
{
	/* Use if statement */
	if (!_data_ || !_buff_ || !*_buff_ || !_long_)
		return;

	/* Use do statement */
	do {
		_data_->linecount_flag = 1;
		_rmove_com_(*_buff_);

		_buld_hstry_lst_(_data_, *_buff_, _data_->histcount++);
		*_long_ = _fpp_;

		_data_->cmd_buf = _buff_;
	} while (_data_->linecount_flag == 0);
}

/**
 * input_buf - This function hdls input buffers
 * @_data_: This pointer refers to the _data_ struct
 * @_buff_: This pointer refers to the buffer
 * @_long_: This pointer refers to the length
 *
 * Return: Number of bytes read
 */
ssize_t input_buf(info_t *_data_, char **_buff_, size_t *_long_)
{
	ssize_t _fpp_ = 0;
	size_t len_p = 0;

	/* Use if statement */
	if (!*_long_)
	{
		reset_buffer(_buff_);
		_fpp_ = input_reader(_data_, _buff_, &len_p);

		if (_fpp_ > 0)
		{
			/*use if */
			input_processor(_buff_, &_fpp_);
			command_chain_hdlr(_data_, _buff_, _long_, _fpp_);
		}
	}
	/* Return the number of bytes read */
	return (_fpp_);
}







