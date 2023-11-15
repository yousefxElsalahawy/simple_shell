





#include "shell.h"

/**
 * reset_buffer - This function resets the buffer
 * @_data_: This pointer refers to the _data_ struct
 * @_buff_: This pointer refers to the buffer
 *
 * Return: Nothing (void function)
 */
void reset_buffer(__attribute__((unused)) info_t *_data_, char **_buff_)
{
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
	ssize_t r = 0;

	/* Use conditional compilation */
#if USE_GETLINE
	r = getline(_buff_, len_p, stdin);
#else
	r = _gt_lne_(_data_, _buff_, len_p);
#endif

	/* Return the number of bytes read */
	return (r);
}

/**
 * input_processor - This function processes input
 * @_data_: This pointer refers to the _data_ struct
 * @_buff_: This pointer refers to the buffer
 * @r: This pointer refers to the length
 *
 * Return: Nothing (void function)
 */
void input_processor(info_t *_data_, char **_buff_, ssize_t *r)
{
	/* Use if statement */
	(*_buff_)[*r - 1] == '\n' ? (*_buff_)[--(*r)] = '\0' : 0;

	_data_->linecount_flag = 1;
	_rmove_com_(*_buff_);
	_buld_hstry_lst_(_data_, *_buff_, _data_->histcount++);
}

/**
 * command_chain_hdlr - This function hdls command chains
 * @_data_: This pointer refers to the _data_ struct
 * @_buff_: This pointer refers to the buffer
 * @_long_: This pointer refers to the length
 * @r: This pointer refers to the length
 *
 * Return: Nothing (void function)
 */
void command_chain_hdlr(info_t *_data_, char **_buff_, size_t *_long_, ssize_t r)
{
	*_long_ = r;
	_data_->cmd_buf = _buff_;
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
	ssize_t r = 0;
	size_t len_p = 0;

	/* Use if statement */
	if (!*_long_)
	{
		reset_buffer(_data_, _buff_);
		r = input_reader(_data_, _buff_, &len_p);
		if (r > 0)
		{
			input_processor(_data_, _buff_, &r);
			command_chain_hdlr(_data_, _buff_, _long_, r);
		}
	}
	/* Return the number of bytes read */
	return (r);
}






