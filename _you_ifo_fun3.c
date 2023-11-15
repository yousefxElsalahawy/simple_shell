


#include "shell.h"


/**
 * exterminate_cmd_buf_and_arg - This function
 * frees the command buffer and argument in the _data_ struct
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
 * eradicate_environ_and_cmd_buf -
 * This function frees the environment and command buffer in the _data_ struct
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




