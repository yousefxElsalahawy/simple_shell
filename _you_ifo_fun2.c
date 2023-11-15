





#include "shell.h"

/**
 * set_argv - This function sets the arguments in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vle_ (void function)
 */
void set_argv(info_t *_data_)
{
	int _OK_ = 0;
	char **argv = NULL;

	if (_data_->arg) /*use if */
	{
		argv = _str_foo_(_data_->arg, " \t");
		if (!argv) /*use if */
		{
			allocate_argv(_data_);
		}
		else
		{
			while (argv && argv[_OK_]) /*use loop */
			{
				_OK_++;
			}
			_data_->argv = argv;
		}
		_data_->argc = _OK_;
	}
}

/**
 * _rplce_nf_ - This function replaces
 * aliases and variables in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vle_ (void function)
 */
void _rplce_nf_(info_t *_data_)
{
	replace_alias(_data_);
	rplce_vrs_(_data_);
}

/**
 * _st_nf_ - This function sets all the fields in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 * @_av: This pointer refers to Argument Vector
 *
 * No return _vle_ (void function)
 */
void _st_nf_(info_t *_data_, char **_av)
{
	set_fname(_data_, _av);
	set_argv(_data_);
	_rplce_nf_(_data_);
}

/**
 * obliterate_argv - This function frees the arguments in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vle_ (void function)
 */
void obliterate_argv(info_t *_data_)
{
	_fun_free_(_data_->argv);
	_data_->argv = NULL;
}

/**
 * annihilate_pth - This function clears the pth in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vle_ (void function)
 */
void annihilate_pth(info_t *_data_)
{
	_data_->pth = NULL;

}


