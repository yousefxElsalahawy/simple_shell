




#include "shell.h"


/**
 * chk_operator - Checks if current char in buffer is a chain delimeter
 * @_data_: This pointer refers to the parameter struct
 * @_buff_: This pointer refers to the char buffer
 * @_go_: This variable refers to the current position in _buff_
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int chk_operator(info_t *_data_, char *_buff_, size_t *_go_)
{
	/* Declaration */
	if (!_buff_)
		return (0);

	/* Use switch */
	switch (_buff_[*_go_])
	{
		case '|':
			/* Check for logical OR operator */
			if (_buff_[*_go_ + 1] == '|')
			{
				_buff_[*_go_] = 0;
				(*_go_)++;
				_data_->cmd_buf_type = CMD_OR;

				return (1); /* Returns 1 if logical OR operator is found */
			}
			break;
		case '&':
			/* Check for logical AND operator */
			if (_buff_[*_go_ + 1] == '&')
			{
				_buff_[*_go_] = 0;
				(*_go_)++;
				_data_->cmd_buf_type = CMD_AND;
				return (1); /* Returns 1 if logical AND operator is found */
			}
			break;
		case ';':
			/* Check for command chain operator */
			_buff_[*_go_] = 0;
			_data_->cmd_buf_type = CMD_CHAIN;
			return (1); /* Returns 1 if command chain operator is found */
		default:
			break;
	}
	return (0); /* Returns 0 if no operator is found */
}

/**
 * _s_chn_ - Checks if the position has changed,
 * indicating an operator was found
 * @_data_: This pointer refers to the parameter struct
 * @_buff_: This pointer refers to the char buffer
 * @_oops_: This variable refers to the current position in _buff_
 *
 * Return: 1 if position has changed, 0 otherwise
 */
int _s_chn_(info_t *_data_, char *_buff_, size_t *_oops_)
{
	/* Declaration */
	size_t _go_;

	_go_ = *_oops_;

	/* Use loop */
	*_oops_ = _go_ + chk_operator(_data_, _buff_, &_go_);

	/* Use if */
	return ((*_oops_ > _go_) ? 1 : 0);
	/* Returns 1 if position has changed, 0 otherwise */
}

/**
 * chk_condition - Checks the condition of the command buffer _style
 * @_data_: This pointer refers to the parameter struct
 *
 * Return: 1 if condition is met, 0 otherwise
 */
int chk_condition(info_t *_data_)
{
	return ((_data_->cmd_buf_type == CMD_AND && _data_->status) ||
			(_data_->cmd_buf_type == CMD_OR && !_data_->status));
	/* Returns 1 if condition is met, 0 otherwise */
}

/**
 * update_buffer_and_index - Updates the
 * buffer and _indx_ based on the condition
 * @_data_: This pointer refers to the parameter struct
 * @_buff_: This pointer refers to the char buffer
 * @_indx_: This variable refers to the current position in _buff_
 * @_long_: This variable refers to the length of the buffer
 *
 * Return: Nothing (void function)
 */
void update_buffer_and_index(info_t *_data_, char *_buff_,
		size_t *_indx_, size_t _long_)
{
	/* Declaration */
	int condition = chk_condition(_data_);

	/* Use if */
	_buff_[*_indx_] = condition ? 0 : _buff_[*_indx_];

	/* Use loop */
	*_indx_ = condition ? _long_ : *_indx_;
}

/**
 * chk_chain - Checks the chain and updates the buffer and _indx_
 * @_data_: This pointer refers to the parameter struct
 * @_buff_: This pointer refers to the char buffer
 * @_oops_: This variable refers to the current position in _buff_
 * @_OK_: This variable is unused
 * @_long_: This variable refers to the length of the buffer
 *
 * Return: Nothing (void function)
 */
void chk_chain(info_t *_data_, char *_buff_,
		size_t *_oops_, __attribute__((unused)) size_t _OK_, size_t _long_)
{
	/* Declaration */
	size_t _go_ = *_oops_;

	/* Call the function to update the buffer and _indx_ */
	update_buffer_and_index(_data_, _buff_, &_go_, _long_);

	/* Use loop */
	*_oops_ = _go_;
}



