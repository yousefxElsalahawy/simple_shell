




#include "shell.h"

/**
 * clear_info_arg - This function clears the arguments in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vlle_ (void function)
 */
void clear_info_arg(_info_OK *_data_)
{
	_data_->_arguv_ = NULL; /*use if */
	_data_->_argu_ = NULL;
}

/**
 * clear_info_pth_argc - This function clears the _my_pth_ and argument _ocntt_ in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vlle_ (void function)
 */
void clear_info_pth_argc(_info_OK *_data_)
{
	_data_->_argu_c_ = 0;
	_data_->_my_pth_ = NULL;
}

/**
 * _clr_inf_ - This function clears _All the fields in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vlle_ (void function)
 */
void _clr_inf_(_info_OK *_data_)
{
	clear_info_pth_argc(_data_);
	clear_info_arg(_data_);
}

/**
 * set_fname - This function sets the _fl_nmee_ in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 * @_aav_: This pointer refers to Argument Vector
 *
 * No return _vlle_ (void function)
 */
void set_fname(_info_OK *_data_, char **_aav_)
{
	char *_fl_nmee_ = _aav_[0];
	_data_->_fil_name_ = _fl_nmee_;
}

/**
 * allocate_argv - This function allocates memory for arguments in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vlle_ (void function)
 */
void allocate_argv(_info_OK *_data_)
{
	char **arguments = malloc(sizeof(char *) * 2);

	if (arguments) /*use if */
	{
		arguments[0] = _str_dupp_(_data_->_argu_);
		arguments[1] = NULL;
	}
	_data_->_arguv_ = arguments;
}

/**
 * set_argv - This function sets the arguments in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vlle_ (void function)
 */
void set_argv(_info_OK *_data_)
{
	int _oops_ = 0;
	char **_arguv_ = NULL;

	if (_data_->_argu_) /*use if */
	{
		_arguv_ = _str_foo(_data_->_argu_, " \t");
		if (!_arguv_) /*use if */
		{
			allocate_argv(_data_);
		}
		else
		{
			while (_arguv_ && _arguv_[_oops_]) /*use loop */
			{
				_oops_++;
			}
			_data_->_arguv_ = _arguv_;
		}
		_data_->_argu_c_ = _oops_;
	}
}

/**
 * _rplce_nf_ - This function replaces aliases and variables in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vlle_ (void function)
 */
void _rplce_nf_(_info_OK *_data_)
{
	_rplce_als_(_data_);
	rplce_vrs_(_data_);
}

/**
 * _st_nf_ - This function sets _All the fields in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 * @_aav_: This pointer refers to Argument Vector
 *
 * No return _vlle_ (void function)
 */
void _st_nf_(_info_OK *_data_, char **_aav_)
{
	set_fname(_data_, _aav_);
	set_argv(_data_);
	_rplce_nf_(_data_);
}

/**
 * obliterate_argv - This function frees the arguments in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vlle_ (void function)
 */
void obliterate_argv(_info_OK *_data_)
{
	_fun_free_(_data_->_arguv_);
	_data_->_arguv_ = NULL;
}

/**
 * annihilate_pth - This function clears the _my_pth_ in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vlle_ (void function)
 */
void annihilate_pth(_info_OK *_data_)
{
	_data_->_my_pth_ = NULL;

}

/**
 * exterminate_cmd_buf_and_arg - This function frees the command _obuf_fer_ and argument in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vlle_ (void function)
 */
void exterminate_cmd_buf_and_arg(_info_OK *_data_)
{
	if (!_data_->_cmdd_buff_) /*use if */
		free(_data_->_argu_);
}

/**
 * decimate_lists - This function frees the lists in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vlle_ (void function)
 */
void decimate_lists(_info_OK *_data_)
{
	int case_num = 1;

	switch (case_num) /* use switch*/
	{
	case 1:
		if (_data_->_my_env) /*use if */
			_ree_lst_(&(_data_->_my_env));
		/* fall through */
	case 2:
		if (_data_->_my_hty)
			_ree_lst_(&(_data_->_my_hty));
		/* fall through */
	case 3:
		if (_data_->_alias_nd_) /*use if */
			_ree_lst_(&(_data_->_alias_nd_));
		break;
	}
}
/**
 * eradicate_environ_and_cmd_buf - This function frees the environment and command _obuf_fer_ in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 *
 * No return _vlle_ (void function)
 */
void eradicate_environ_and_cmd_buf(_info_OK *_data_)
{
	_fun_free_(_data_->_env_you_);
	_data_->_env_you_ = NULL;
	_bfun_free_((void **)_data_->_cmdd_buff_);

	if (_data_->_read_fd_ > 2) /*use if */
		close(_data_->_read_fd_);
	_pputt_char(_BUFFER_FLUSH);
}

/**
 * _fr_nf_ - This function frees _All the fields in the _data_ struct
 * @_data_: This pointer refers to the _data_ Struct
 * @_All: This variable is used to determine if _All fields should be freed
 *
 * No return _vlle_ (void function)
 */
void _fr_nf_(_info_OK *_data_, int _All)
{
	obliterate_argv(_data_);
	annihilate_pth(_data_);
	if (_All) /*use if */
	{
		exterminate_cmd_buf_and_arg(_data_);
		decimate_lists(_data_);
		eradicate_environ_and_cmd_buf(_data_);
	}
     /* The function returns here */
}



