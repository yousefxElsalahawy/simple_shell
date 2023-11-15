

#include "shell.h"

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


