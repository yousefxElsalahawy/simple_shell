


#include "shell.h"

/**
 * clear_info_arg - This function clears the arguments in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vle_ (void function)
 */
void clear_info_arg(info_t *_data_)
{
	_data_->argv = NULL; /*use if */
	_data_->arg = NULL;
}

/**
 * clear_info_pth_argc - This function clear
 * the pth and argument _cnt_ in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vle_ (void function)
 */
void clear_info_pth_argc(info_t *_data_)
{
	_data_->argc = 0;
	_data_->pth = NULL;
}

/**
 * _clr_inf_ - This function clears all the fields in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vle_ (void function)
 */
void _clr_inf_(info_t *_data_)
{
	clear_info_pth_argc(_data_);
	clear_info_arg(_data_);
}

/**
 * set_fname - This function sets the filename in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 * @_av: This pointer refers to Argument Vector
 *
 * No return _vle_ (void function)
 */
void set_fname(info_t *_data_, char **_av)
{
	char *filename = _av[0];

	_data_->fname = filename;
}

/**
 * allocate_argv - This function allocates
 * memory for arguments in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vle_ (void function)
 */
void allocate_argv(info_t *_data_)
{
	char **arguments = malloc(sizeof(char *) * 2);

	if (arguments) /*use if */
	{
		arguments[0] = _str_dupp_(_data_->arg);
		arguments[1] = NULL;
	}
	_data_->argv = arguments;
}










