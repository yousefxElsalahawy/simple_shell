




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





