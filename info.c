




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
 * clear_info_pth_argc - This function clears the pth and argument _cnt_ in the _data_ struct
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
 * allocate_argv - This function allocates memory for arguments in the _data_ struct
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
 * _rplce_nf_ - This function replaces aliases and variables in the _data_ struct
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

/**
 * exterminate_cmd_buf_and_arg - This function frees the command buffer and argument in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vle_ (void function)
 */
void exterminate_cmd_buf_and_arg(info_t *_data_)
{
	if (!_data_->cmd_buf) /*use if */
		free(_data_->arg);
}

/**
 * decimate_lists - This function frees the lists in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vle_ (void function)
 */
void decimate_lists(info_t *_data_)
{
	int case_num = 1;

	switch (case_num) /* use switch*/
	{
		case 1:
			if (_data_->env) /*use if */
				_ree_lst_(&(_data_->env));
			/* fall through */
		case 2:
			if (_data_->history)
				_ree_lst_(&(_data_->history));
			/* fall through */
		case 3:
			if (_data_->alias) /*use if */
				_ree_lst_(&(_data_->alias));
			break;
	}
}
/**
 * eradicate_environ_and_cmd_buf - This function frees the environment and command buffer in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vle_ (void function)
 */
void eradicate_environ_and_cmd_buf(info_t *_data_)
{
	_fun_free_(_data_->environ);
	_data_->environ = NULL;
	_bfun_free_((void **)_data_->cmd_buf);

	if (_data_->readfd > 2) /*use if */
		close(_data_->readfd);
	_pputt_char(BUF_FLUSH);
}

/**
 * _fr_nf_ - This function frees all the fields in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 * @all: This variable is used to determine if all fields should be freed
 *
 * No return _vle_ (void function)
 */
void _fr_nf_(info_t *_data_, int all)
{
	obliterate_argv(_data_);
	annihilate_pth(_data_);
	if (all) /*use if */
	{
		exterminate_cmd_buf_and_arg(_data_);
		decimate_lists(_data_);
		eradicate_environ_and_cmd_buf(_data_);
	}
	/* The function returns here */
}


