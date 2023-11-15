




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














/**
 * _gett_ndd_ - Retrieves a _nde_ from the alias list
 * @_data_: This pointer refers to the parameter struct
 *
 * Return: _Nde_ if found, NULL otherwise
 */
_lst_ *_gett_ndd_(info_t *_data_)
{
	/* Use if */
	if (!_data_)
		return (NULL);

	return (node_starts_with(_data_->alias, _data_->argv[0], '='));
	/* Returns _nde_ if found, NULL otherwise */
}

/**
 * get_new_p - Retrieves a new pointer from the _nde_
 * @_nde_: This pointer refers to the _nde_
 *
 * Return: New pointer if found, NULL otherwise
 */
char *get_new_p(_lst_ *_nde_)
{
	/* Declaration */
	char *_oops_;

	/* Use if */
	if (!_nde_)
		return (NULL);

	_oops_ = _str_n_chr(_nde_->_txt_, '=');

	return (_oops_ ? _str_dupp_(_oops_ + 1) : NULL);
	/* Returns new pointer if found, NULL otherwise */
}

/**
 * replace_alias - Replaces the alias
 * in the argv[0] with the _vle_ from the alias list
 * @_data_: This pointer refers to the parameter struct
 *
 * Return: 1 if alias is replaced, 0 otherwise
 */
int replace_alias(info_t *_data_)
{
	/* Declaration */
	int _OK_ = 0;
	_lst_ *_nde_;
	char *_oops_;

	/* Use if */
	if (!_data_)
		return (0);

	/* Use loop */
	do {
		_nde_ = _gett_ndd_(_data_);

		/* Use if */
		if (!_nde_)
			return (0);

		_oops_ = get_new_p(_nde_);

		/* Use if */
		if (!_oops_)
			return (0);
		free(_data_->argv[0]);
		_data_->argv[0] = _oops_;
		_OK_++;
	} while (_OK_ < 10 && _data_->argv[0] == NULL);

	return (_data_->argv[0] != NULL);
	/* Returns 1 if alias is replaced, 0 otherwise */
}

/**
 * chk_variable_type - Checks the _style of
 * the variable in argv[_OK_]
 * @_data_: This pointer refers to the parameter struct
 * @_OK_: This variable refers to the _indx_ of argv
 *
 * Return: 0 if not a variable,
 * 1 if status variable, 2 if PID variable, 3 otherwise
 */
int chk_variable_type(info_t *_data_, int _OK_)
{
	/* Use if */
	if (_data_->argv[_OK_][0] != '$' || !_data_->argv[_OK_][1])
		return (0);
	else if (!_str_cmpp_(_data_->argv[_OK_], "$?"))
		return (1);
	else if (!_str_cmpp_(_data_->argv[_OK_], "$$"))
		return (2);
	else
		return (3);
	/* Returns 0 if not a variable, 1, 2 , 3  */
}

/**
 * replace_string_with_value - Replaces the string in argv[_OK_] with the _vle_
 * @_data_: This pointer refers to the parameter struct
 * @_OK_: This variable refers to the _indx_ of argv
 * @_vle_: This variable refers to the _vle_ to replace with
 *
 * Return: Nothing (void function)
 */
void replace_string_with_value(info_t *_data_, int _OK_, int _vle_)
{
	_rplce_str_(&(_data_->argv[_OK_]), _str_dupp_(cnvrt_nmbr_(_vle_, 10, 0)));
}

/**
 * _get_ndd_ - Retrieves a _nde_ from the environment list
 * @_data_: This pointer refers to the parameter struct
 * @_OK_: This variable refers to the _indx_ of argv
 *
 * Return: _Nde_ if found, NULL otherwise
 */
_lst_ *_get_ndd_(info_t *_data_, int _OK_)
{
	return (node_starts_with(_data_->env,
				&_data_->argv[_OK_][1], '='));
	/* Returns _nde_ if found, NULL otherwise */
}

/**
 * replace_with_nd_value - Replaces the string in
 * argv[_OK_] with the _vle_ from the _nde_
 * @_data_: This pointer refers to the parameter struct
 * @_OK_: This variable refers to the _indx_ of argv
 * @_nde_: This pointer refers to the _nde_
 *
 * Return: Nothing (void function)
 */
void replace_with_nd_value(info_t *_data_, int _OK_, _lst_ *_nde_)
{
	_rplce_str_(&(_data_->argv[_OK_]),
			_str_dupp_(_str_n_chr(_nde_->_txt_, '=') + 1));
}

/**
 * replace_with_empty_string - Replaces the
 * string in argv[_OK_] with an empty string
 * @_data_: This pointer refers to the parameter struct
 * @_OK_: This variable refers to the _indx_ of argv
 *
 * Return: Nothing (void function)
 */
void replace_with_empty_string(info_t *_data_, int _OK_)
{
	_rplce_str_(&_data_->argv[_OK_], _str_dupp_(""));
}


/**
 * rplce_vrs_ - Replaces the variables in argv with their corresponding values
 * @_data_: This pointer refers to the parameter struct
 *
 * Return: 0 (void function)
 */
int rplce_vrs_(info_t *_data_)
{
	/* Declaration */
	int _OK_ = 0;
	_lst_ *_nde_;
	int var_type;

	/* Use loop */
	do {
		var_type = chk_variable_type(_data_, _OK_);

		/* Use switch */
		switch (var_type)
		{
			case 0:
				_OK_++;
				continue;
			case 1:
				replace_string_with_value(_data_, _OK_, _data_->status);
				break;
			case 2:
				if (kill(getpid(), 0) == 0)
				{
					replace_string_with_value(_data_, _OK_, getpid());
				}
				else
				{
					replace_with_empty_string(_data_, _OK_);
				}
				break;
			case 3:
				_nde_ = _get_ndd_(_data_, _OK_);
				if (_nde_)
					replace_with_nd_value(_data_, _OK_, _nde_);
				else
					replace_with_empty_string(_data_, _OK_);
				break;
		}
		_OK_++;
	} while (_data_->argv[_OK_]);

	return (0); /* Returns 0 (void function) */
}

/**
 * _rplce_str_ - Replaces old string with new string
 * @old: This pointer refers to the old string
 * @new: This pointer refers to the new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int _rplce_str_(char **old, char *new)
{
	/* Use if */
	if (old == NULL || new == NULL)
	{
		_put_ss_("Error: Null pointer passed to _rplce_str_\n");
		return (0); /* Returns 0 if either old or new is NULL */
	}
	if (*old != new)
	{
		free(*old);
		*old = new;
	}
	return (1); /* Returns 1 if replaced */
}

