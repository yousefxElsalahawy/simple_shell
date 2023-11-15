

#include "shell.h"

/**
 * refresh_environ - This function refreshes the environment
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: _data_->environ (success)
 */
char **refresh_environ(info_t *_data_)
{
	/* Check if _data_->env is not NULL */
	if (_data_->env)
	{
		/* Convert list to strings */
		_data_->environ = _lst_to_strng_(_data_->env);
		/* Reset env_changed _flg_ */
		_data_->env_changed = 0;
	}
	/* Return the refreshed environment */
	return (_data_->environ);
}

/**
 * _gtt_envrnn_ - This function gets the environment
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: refresh_environ(_data_) or environ (success)
 */
char **_gtt_envrnn_(info_t *_data_)
{
	/* Check if _data_->env is not NULL */
	if (_data_->env)
	{
		/* Convert list to strings */
		_data_->environ = _lst_to_strng_(_data_->env);
		/* Reset env_changed _flg_ */
		_data_->env_changed = 0;
	}
	/* Return the refreshed environment */
	return (_data_->environ);
}

/**
 * get_starting_string - This function gets the starting string
 * @_nde_: This pointer refers to the _Nde_
 * @_Var_: This variable is used for some specific purpose
 *
 * Return: _start_wh_(_nde_->_txt_, _Var_) (success)
 */
char *get_starting_string(_lst_ *_nde_, char *_Var_)
{
	/* Return the _rslt_ of _start_wh_ function */
	return (_start_wh_(_nde_->_txt_, _Var_));
}

/**
 * reset_environment - This function resets the environment
 * @_data_: This pointer refers to the _data_ Struct
 * @_OK_: This variable is used for some specific purpose
 * @_nde_: This pointer refers to the _Nde_
 *
 * Return: env_changed (success)
 */
int reset_environment(info_t *_data_, size_t *_OK_, _lst_ **_nde_)
{
	/* Delete _nde_ at _indx_ _OK_ and return the _rslt_ */
	int env_changed = _dlt_nd_at_ndx(&(_data_->env), *_OK_);

	/* Reset _OK_ and _nde_ */
	*_OK_ = 0;
	*_nde_ = _data_->env;

	/* Return the _rslt_ of env_changed */
	return (env_changed);
}

/**
 * _Un_Set_env_ - This function unsets the environment variable
 * @_data_: This pointer refers to the _data_ Struct
 * @_Var_: This variable is used for some specific purpose
 *
 * Return: reset_environment(_data_, &_OK_, &_nde_)
 * or _data_->env_changed (success)
 */
int _Un_Set_env_(info_t *_data_, char *_Var_)
{
	/* Initialize _nde_ and _OK_ */
	_lst_ *_nde_ = _data_->env;
	size_t _OK_ = 0;
	char *_oops_;

	/* Check if _nde_ or _Var_ is NULL */
	if (!_nde_ || !_Var_)
		return (0);

	/* Loop through the nodes */
	do {
		/* Get the starting string */
		_oops_ = get_starting_string(_nde_, _Var_);

		/* Check if _oops_ is not NULL and the first character is '=' */
		if (_oops_ && *_oops_ == '=')
			/* Reset the environment and return the _rslt_ */
			return (reset_environment(_data_, &_OK_, &_nde_));

		/* Move to the _nxt_ _nde_ and increment _OK_ */
		_nde_ = _nde_->_nxt_;
		_OK_++;
	} while (_nde_);

	/* Return the _rslt_ of env_changed */
	return (_data_->env_changed);
}



