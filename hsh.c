





#include "shell.h"

/**
 * ask_user - This function prompts the user for input
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: void
 */
void ask_user(_info_OK *_data_)
{
	if (_inter_active(_data_)) /*use if */
		_put_ss_("$ ");
	_e_put_char_(_BUFFER_FLUSH);
}

/**
 * _hdl_iinput_ - This function hdls user input
 * @_data_: This pointer refers to parameter and _data_ Struct
 * @_aav_: This pointer refers to Argument
 * @_oorr: This pointer refers to read _vlle_
 * @_bltin_rt_: This pointer refers to crafty_builtin return _vlle_
 *
 * Return: void
 */
void _hdl_iinput_(_info_OK *_data_, char **_aav_, ssize_t *_oorr, int *_bltin_rt_)
{
	_clr_inf_(_data_);
	ask_user(_data_);
	*_oorr = gt_userinpt_(_data_);
	if (*_oorr != -1) /*use if */
	{
		_st_nf_(_data_, _aav_);
		*_bltin_rt_ = find_operation(_data_);
		if (*_bltin_rt_ == -1) /*use if */
			_find_cmmd_(_data_);
	}
	else
		_pputt_char(_inter_active(_data_) ? '\n' : ' ');
	_fr_nf_(_data_, 0);
}

/**
 * hdl_exit - This function hdls exit scenarios
 * @_data_: This pointer refers to parameter and _data_ Struct
 * @_bltin_rt_: This is the return _vlle_ of the crafty_builtin function
 *
 * Return: void
 */
void hdl_exit(_info_OK *_data_, int _bltin_rt_)
{
	if (_bltin_rt_ == -2) 
	{
        /*use if */
		exit(_data_->_num_error_ == -1 ? _data_->_cmdd_status_ : _data_->_num_error_);
	}
	if (!_inter_active(_data_) && _data_->_cmdd_status_) /*use if */
		exit(_data_->_cmdd_status_);
}

/**
 * cleanup_clever_ - This function cleans up the _data_ struct
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: void
 */
void cleanup_clever_(_info_OK *_data_)
{
	_fr_nf_(_data_, 1);
	_wrt_hstry_(_data_);
}

/**
 * hsh - This function is the main shell loop
 * @_data_: This pointer refers to parameter and _data_ Struct
 * @_aav_: This pointer refers to Argument
 *
 * Return: _bltin_rt_ (success or error code)
 */
int hsh(_info_OK *_data_, char **_aav_)
{
	ssize_t _oorr = 0;
	int _bltin_rt_ = 0;

	do { /*use loop */
		_hdl_iinput_(_data_, _aav_, &_oorr, &_bltin_rt_);
	} while (_oorr != -1 && _bltin_rt_ != -2);

	hdl_exit(_data_, _bltin_rt_);
	cleanup_clever_(_data_);

	return (_bltin_rt_);
    /* Returns the return _vlle_ of the crafty_builtin function */
}

/**
 * initialize_builtin_table - This function initializes
 * the crafty_builtin table
 *
 * Return: builtintbl (pointer to the crafty_builtin table)
 */
_cunning_table *initialize_builtin_table(void)
{
	static _cunning_table builtintbl[] = {
		{"exit", _you_ext_},
		{"_my_env", _mEnv},
		{"help", _you_hlp_},
		{"_my_hty", _you_hstry_},
		{"setenv", _mSetenv},
		{"unsetenv", _mUnsetenv},
		{"cd", _you_cdd_},
		{"_alias_nd_", _you_als_},
		{NULL, NULL}
	};
	return (builtintbl);
    /* Returns a pointer to the crafty_builtin table */
}

/**
 * _execute_operation - This function executes a crafty_builtin command
 * @_data_: This pointer refers to parameter and _data_ Struct
 * @builtintbl: This pointer refers to the crafty_builtin table
 * @_oops_: This is the _indx_ of the crafty_builtin command in the table
 *
 * Return: builtintbl[_oops_]._operat_(_data_) (success or error code)
 */
int _execute_operation(_info_OK *_data_, _cunning_table *builtintbl, int _oops_)
{
	_data_->_my_line_count++;
	return (builtintbl[_oops_]._operat_(_data_));
    /* Returns the return _vlle_ of the crafty_builtin function */
}

/**
 * find_operation - This function finds a crafty_builtin command
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: built_in_ret (success or error code)
 */
int find_operation(_info_OK *_data_)
{
	int _oops_ = 0;
	int built_in_ret = -1;
	_cunning_table *builtintbl = initialize_builtin_table();

	while (builtintbl[_oops_]._style && built_in_ret == -1) /*use loop */
	{
		built_in_ret = (_str_cmpp_(_data_->_arguv_[0],
					builtintbl[_oops_]._style) == 0) ?
			_execute_operation(_data_, builtintbl, _oops_) : -1;
		_oops_++;
	}
	return (built_in_ret);
    /* Returns the return _vlle_ of the crafty_builtin function */
}


/**
 * increment_line_count - This function increments the line _ocntt_
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: void
 */
void increment_line_count(_info_OK *_data_)
{
	_data_->_flag_mycount_ == 1 ? (_data_->_my_line_count++,
			_data_->_flag_mycount_ = 0) : 0;
}

/**
 * count_non_delim - This function counts non-delimiter characters
 * @_data_: This pointer refers to parameter and _data_ Struct
 * @_kok_: This pointer refers to the _ocntt_ of non-delimiter characters
 *
 * Return: void
 */
void count_non_delim(_info_OK *_data_, int *_kok_)
{
	int _oops_ = 0;

	while (_data_->_argu_[_oops_]) /*use loop */
	{
		if (!_my_delm(_data_->_argu_[_oops_], " \t\n")) /*use if */
			*_kok_ += 1;
		_oops_++;
	}
}

/**
 * hdl_pth_found - This function hdls the scenario when a _my_pth_ is found
 * @_data_: This pointer refers to parameter and _data_ Struct
 * @_my_pth_: This pointer refers to the found _my_pth_
 *
 * Return: void
 */
void hdl_pth_found(_info_OK *_data_, char *_my_pth_)
{
	if (_my_pth_) /*use if */
	{
		_data_->_my_pth_ = _my_pth_;
		_forkK_comm_(_data_);
	}
}

/**
 * hdl_pth_not_found - This function hdls the scenario when a _my_pth_ is not found
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: void
 */
void hdl_pth_not_found(_info_OK *_data_)
{
	/*usef if*/
	if ((_inter_active(_data_) || _get_env_(_data_, "_my_pth_=")
				|| _data_->_arguv_[0][0] == '/') && _my_i_cmdd_(_data_, _data_->_arguv_[0])) /*use if */
		_forkK_comm_(_data_);
	else if (*(_data_->_argu_) != '\n') /*use if */
	{
		_data_->_cmdd_status_ = 127;
		print_error(_data_, "the command is not found\n");
	}
}

/**
 * _find_cmmd_ - This function finds a command in _my_pth_
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: void
 */
void _find_cmmd_(_info_OK *_data_)
{
	char *_my_pth_ = NULL;
	int _kok_ = 0, _oops_ = 0;

	_data_->_my_pth_ = _data_->_arguv_[0];
	increment_line_count(_data_);
	count_non_delim(_data_, &_kok_);
	if (!_kok_) /*use if */
		return;

	do { /*use loop */
		_my_pth_ = _fnd_pth_(_data_, _get_env_(_data_, "_my_pth_="), _data_->_arguv_[0]);
		_oops_++;
	} while (!_my_pth_ && _oops_ < 2); /*use loop */

	_my_pth_ ? hdl_pth_found(_data_, _my_pth_) : hdl_pth_not_found(_data_);
}

/**
 * hdl_fork_error - This function hdls fork errors
 * @_child_pidd_: This is the process ID of the child process
 *
 * Return: void
 */
void hdl_fork_error(pid_t _child_pidd_)
{
	_child_pidd_ == -1 ? (perror("Error:"), exit(1)) : (void)_child_pidd_;
}

/**
 * hdl_exec_error - This function hdls exec errors
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: void
 */
void hdl_exec_error(_info_OK *_data_)
{
	execve(_data_->_my_pth_, _data_->_arguv_, _gtt_envrnn_(_data_)) == -1 ?
		(_fr_nf_(_data_, 1), errno == EACCES ?
		exit(126) : exit(1)) : (void)_data_;
}

/**
 * hdl_child_process - This function hdls child process scenarios
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: void
 */
void hdl_child_process(_info_OK *_data_)
{
	hdl_exec_error(_data_);
}

/**
 * hdl_parent_process - This function hdls parent process scenarios
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: void
 */
void hdl_parent_process(_info_OK *_data_)
{
	do { /*use loop */
		wait(&(_data_->_cmdd_status_));
	} while (!WIFEXITED(_data_->_cmdd_status_));

	_data_->_cmdd_status_ = WEXITSTATUS(_data_->_cmdd_status_);
	_data_->_cmdd_status_ == 126 ? print_error(_data_, "Permission denied\n") : (void)_data_;
}

/**
 * _forkK_comm_ - This function forks a an exec thread to run _ccmmdd_
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: void
 */
void _forkK_comm_(_info_OK *_data_)
{
	/*decleration*/
	pid_t _child_pidd_ = fork();

	hdl_fork_error(_child_pidd_);
	_child_pidd_ == 0 ? hdl_child_process(_data_) : hdl_parent_process(_data_);
}



