#include "shell.h"


/**
 * create_buf - This function creates a buffer
 * @_Var_: This variable is used for some specific purpose
 * @_vle_: This variable is used for some specific purpose
 *
 * Return: _buff_ (success)
 */
char *create_buf(char *_Var_, char *_vle_)
{
	/* Allocate memory for _buff_ */
	char *_buff_ = malloc(_str_len_(_Var_) + _str_len_(_vle_) + 2);

	/* Check if _buff_ is not NULL */
	if (_buff_)
	{
		/* Copy _Var_ to _buff_ */
		_str_cpy(_buff_, _Var_);
		/* Concatenate '=' to _buff_ */
		_str_catt_(_buff_, "=");
		/* Concatenate _vle_ to _buff_ */
		_str_catt_(_buff_, _vle_);
	}
	/* Return _buff_ */
	return (_buff_);
}

/**
 * find_var_in_env - This function finds a variable in the environment
 * @_nde_: This pointer refers to the _Nde_
 * @_Var_: This variable is used for some specific purpose
 * @_buff_: This variable is used for some specific purpose
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: _nde_ or NULL (success)
 */
_lst_ *find_var_in_env(_lst_ *_nde_, char *_Var_, char *_buff_, info_t *_data_)
{
	char *_oops_;

	/* Check if _nde_ is not NULL */
	if (_nde_)
	{
		/* Loop through the nodes */
		do {
			/* Get the starting string */
			_oops_ = _start_wh_(_nde_->_txt_, _Var_);

			/* Check if _oops_ is not NULL and the first character is '=' */
			if (_oops_ && *_oops_ == '=')
			{
				/* Free _nde_->_txt_ */
				free(_nde_->_txt_);
				/* Assign _buff_ to _nde_->_txt_ */
				_nde_->_txt_ = _buff_;
				/* Set env_changed to 1 */
				_data_->env_changed = 1;
				/* Return _nde_ */
				return (_nde_);
			}
			/* Move to the _nxt_ _nde_ */
			_nde_ = _nde_->_nxt_;
		} while (_nde_);
	}
	/* Return NULL */
	return (NULL);
}

/**
 * add_nd_and_free_buf - This function adds a _nde_ and frees the buffer
 * @env: This pointer refers to the Environment
 * @_buff_: This variable is used for some specific purpose
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: None
 */
void add_nd_and_free_buf(_lst_ **env, char *_buff_, info_t *_data_)
{
	/* Add _nde_ to the end of env */
	_add_nd_end_(env, _buff_, 0);
	/* Free _buff_ */
	free(_buff_);
	/* Set env_changed to 1 */
	_data_->env_changed = 1;
}

/**
 * _set_ev_ - This function sets the environment variable
 * @_data_: This pointer refers to the _data_ Struct
 * @_Var_: This variable is used for some specific purpose
 * @_vle_: This variable is used for some specific purpose
 *
 * Return: 0 (success), 1 (error)
 */
int _set_ev_(info_t *_data_, char *_Var_, char *_vle_)
{
	/* Initialize _buff_ */
	char *_buff_;
	/* Initialize _nde_ */
	_lst_ *_nde_;

	/* Check if _Var_ or _vle_ is NULL */
	if (!_Var_ || !_vle_)
		return (0);

	/* Create _buff_ */
	_buff_ = create_buf(_Var_, _vle_);
	/* Check if _buff_ is NULL */
	if (!_buff_)
		return (1);

	/* Find _Var_ in env */
	_nde_ = find_var_in_env(_data_->env, _Var_, _buff_, _data_);

	/* Check if _nde_ is not NULL */
	return (_nde_ ? 0 : (add_nd_and_free_buf(&(_data_->env), _buff_, _data_), 0));
}





