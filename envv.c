




#include "shell.h"

/**
 * validate_inputs - This function validates the inputs
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: 0 (success), 1 (error)
 */
int validate_inputs(info_t *_data_)
{
	if (_data_ == NULL || _data_->env == NULL)
	{
		puts("Error: This is Invalid inputs.");
		return (1); /* Return 1 if inputs are invalid */
	}
	return (0); /* Return 0 if inputs are valid */
}

/**
 * prnt_env - This function prnts the environment
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: _rslt_ of the prnt operation
 */
int prnt_env(info_t *_data_)
{
	int _rslt_ = prnt_list_str(_data_->env);

	if (_rslt_ != 0)
	{
		puts("Error: Failed to prnt Environment Variables.");
	}
	return (_rslt_); /* Return the _rslt_ of the prnt operation */
}

/**
 * _mEnv - This function hdls the myenv command
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: 0 (success), 1 (error)
 */
int _mEnv(info_t *_data_)
{
	int validationResult = validate_inputs(_data_);
	int prntResult = prnt_env(_data_);

	if (validationResult != 0)
	{
		return (validationResult);
		/* Return the _rslt_ of the validation */
	}


	return (prntResult == 0 ? 0 : 1);
	/* Return the _rslt_ of the prnt operation */
}




/**
 * strange_starts - This function chks if a string starts with a specific name
 * @current_nd: This pointer refers to the current _nde_ in the list
 * @name: This variable is used to specify the name to chk
 *
 * Return: pointer to the start of the string if
 * t starts with the name, NULL otherwise
 */
char *strange_starts(_lst_ *current_nd,
		const char *name)
{
	char *_oops_ = _start_wh_(current_nd->_txt_, name);

	return ((_oops_ && *_oops_) ? _oops_ : NULL);
	/* Return  if it starts with the name, NULL otherwise */
}

/**
 * innovative_search - This function performs
 * search in the list
 * @_nde_: This pointer refers to the _nde_ in the list
 * @name: This variable is used to spe
 * ify the name to search for
 *
 * Return: pointer to the found element, NULL if not found
 */
char *innovative_search(_lst_ *_nde_, const char *name)
{
	char *_oops_ = NULL;
	_lst_ *current_nd = _nde_;

	while (current_nd != NULL) /*use loop */
	{
		_oops_ = strange_starts(current_nd, name);
		if (_oops_)
			break;

		current_nd = current_nd->_nxt_;
	}

	return (_oops_);
	/* Return pointer to the found element, NULL if not found */
}

/**
 * _get_envv_ - This function gets the environment variable
 * @_data_: This pointer refers to the _data_ Struct
 * @name: This variable is used
 * to specify the name of the environment variable
 *
 * Return: pointer to the environment variable
 * NULL if not found
 */
char *_get_envv_(info_t *_data_, const char *name)
{
	return ((_data_ != NULL && name != NULL) ?
			innovative_search(_data_->env, name) : NULL);
	/* Return pointer to the able, NULL if not found */
}




/**
 * validate_args - This function validates the arguments
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: 0 (success), 1 (error)
 */
int validate_args(info_t *_data_)
{
	const int expected_argc = 3;

	return ((_data_->argc != expected_argc) ?
			(_ee_put_("This is Wrong Number of Arguments\n"), 1) : 0);
	/* Return 0 if the number of arguments is correct, 1 otherwise */
}

/**
 * _my_Set_env_ - This function sets the envi
 * onment variable
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: 0 (success), 1 (error)
 */
int _my_Set_env_(info_t *_data_)
{
	int validation = validate_args(_data_);

	if (validation)
		return (validation); /* Return the _rslt_ of the validation */

	return ((_set_ev_(_data_, _data_->argv[1], _data_->argv[2]) == 0) ? 0 : 1);
	/* Return 0 if the environment variable is set successfully, 1 otherwise */
}

/**
 * chk_argc - This function chks the number of arguments
 * @_data_: This pointer refers o the Itnfo Struct
 *
 * Return: 0 (success), 1 (error)
 */
int chk_argc(info_t *_data_)
{
	return ((_data_->argc == 1) ? (_ee_put_("Too few arguments.\n"), 1) : 0);
	/* Return 0 if the number of arguments is correct, 1 otherwise */
}



/**
 * _mUnsetenv - This function unsets the environment variable
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: 0 (success), 1 (error)
 */
int _mUnsetenv(info_t *_data_)
{
	int validation = chk_argc(_data_);
	int _OK_;

	if (validation)
		return (validation);
	/* Return the _rslt_ of the validation */

	_OK_ = 1;
	do {
		_Un_Set_env_(_data_, _data_->argv[_OK_]);
		_OK_++;
	} while (_data_->argc <= _OK_);

	return (0);
	/* Return 0 if the envi unset successfully */
}

/**
 * create_env_nd - This function creates a new environment _nde_
 *
 * Return: pointer to the new _nde_
 */
_lst_ *create_env_nd(void)
{
	size_t _OK_ = 0;
	_lst_ *_nde_ = NULL;

	if (environ[_OK_])
	{
		do {
			_add_nd_end_(&_nde_, environ[_OK_], 0);
			_OK_++;
		} while (environ[_OK_]);
	}

	return (_nde_); /* Return pointer to the new _nde_ */
}

/**
 * _pop_env_lst_ - This function populates the environment list
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: 0 (success), 1 (error)
 */
int _pop_env_lst_(info_t *_data_)
{
	_data_->env = create_env_nd();

	return ((_data_->env != NULL) ? 0 : 1);
	/* Return 0 if the environment list is populated successfully, 1 otherwise */
}


