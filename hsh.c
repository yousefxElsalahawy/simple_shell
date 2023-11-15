




#include "shell.h"

/**
 * ask_user - This function prompts the user for input
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: void
 */
void ask_user(info_t *_data_)
{
	if (_inter_active(_data_)) /*use if */
		_put_ss_("$ ");
	_e_put_char_(BUF_FLUSH);
}

/**
 * _hdl_iinput_ - This function hdls user input
 * @_data_: This pointer refers to parameter and _data_ Struct
 * @_av: This pointer refers to Argument
 * @r: This pointer refers to read _vle_
 * @_ret_: This pointer refers to crafty_blt_in return _vle_
 *
 * Return: void
 */
void _hdl_iinput_(info_t *_data_, char **_av, ssize_t *r, int *_ret_)
{
	_clr_inf_(_data_);
	ask_user(_data_);
	*r = gt_userinpt_(_data_);
	if (*r != -1) /*use if */
	{
		_st_nf_(_data_, _av);
		*_ret_ = find_blt_in(_data_);
		if (*_ret_ == -1) /*use if */
			_find_cmmd_(_data_);
	}
	else
		_pputt_char(_inter_active(_data_) ? '\n' : ' ');
	_fr_nf_(_data_, 0);
}

/**
 * hdl_exit - This function hdls exit scenarios
 * @_data_: This pointer refers to parameter and _data_ Struct
 * @_ret_: This is the return _vle_ of the crafty_blt_in function
 *
 * Return: void
 */
void hdl_exit(info_t *_data_, int _ret_)
{
	if (_ret_ == -2) /*use if */
	{
		exit(_data_->err_num == -1 ? _data_->status : _data_->err_num);
	}
	if (!_inter_active(_data_) && _data_->status) /*use if */
		exit(_data_->status);
}

/**
 * cleanup - This function cleans up the _data_ struct
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: void
 */
void cleanup(info_t *_data_)
{
	_fr_nf_(_data_, 1);
	_wrt_hstry_(_data_);
}

/**
 * _clever_hsh_ - This function is the main shell loop
 * @_data_: This pointer refers to parameter and _data_ Struct
 * @_av: This pointer refers to Argument
 *
 * Return: _ret_ (success or error code)
 */
int _clever_hsh_(info_t *_data_, char **_av)
{
	ssize_t r = 0;
	int _ret_ = 0;

	do { /*use loop */
		_hdl_iinput_(_data_, _av, &r, &_ret_);
	} while (r != -1 && _ret_ != -2);

	hdl_exit(_data_, _ret_);
	cleanup(_data_);

	return (_ret_); /* Returns the return _vle_ of the crafty_blt_in function */
}

/**
 * initialize_blt_in_table - This function initializes the crafty_blt_in table
 *
 * Return: blt_intbl (pointer to the crafty_blt_in table)
 */
_cunning_table *initialize_blt_in_table(void)
{
	static _cunning_table blt_intbl[] = {
		{"exit", _you_ext_},
		{"env", _mEnv},
		{"help", _you_hlp_},
		{"history", _you_hstry_},
		{"setenv", _my_Set_env_},
		{"unsetenv", _mUnsetenv},
		{"cd", _you_cdd_},
		{"alias", _you_als_},
		{NULL, NULL}
	};
	return (blt_intbl); /* Returns a pointer to the crafty_blt_in table */
}

/**
 * exec_blt_in - This function execs a crafty_blt_in command
 * @_data_: This pointer refers to parameter and _data_ Struct
 * @blt_intbl: This pointer refers to the crafty_blt_in table
 * @_OK_: This is the _indx_ of the crafty_blt_in command in the table
 *
 * Return: blt_intbl[_OK_]._operat_(_data_) (success or error code)
 */
int exec_blt_in(info_t *_data_, _cunning_table *blt_intbl, int _OK_)
{
	_data_->line_count++;
	return (blt_intbl[_OK_]._operat_(_data_));
	/* Returns the return _vle_ of the crafty_blt_in function */
}

/**
 * find_blt_in - This function finds a crafty_blt_in command
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: built_in_ret (success or error code)
 */
int find_blt_in(info_t *_data_)
{
	int _OK_ = 0;
	int built_in_ret = -1;
	_cunning_table *blt_intbl = initialize_blt_in_table();

	while (blt_intbl[_OK_]._style && built_in_ret == -1) /*use loop */
	{
		built_in_ret = (_str_cmpp_(_data_->argv[0],
					blt_intbl[_OK_]._style) == 0) ?
			exec_blt_in(_data_, blt_intbl, _OK_) : -1;
		_OK_++;
	}
	return (built_in_ret);
	/* Returns the return _vle_ of the crafty_blt_in function */
}


/**
 * increment_line_count - This function increments the line _cnt_
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: void
 */
void increment_line_count(info_t *_data_)
{
	_data_->linecount_flag == 1 ? (_data_->line_count++,
			_data_->linecount_flag = 0) : 0;
}

/**
 * count_non_delim - This function counts non-delimiter characters
 * @_data_: This pointer refers to parameter and _data_ Struct
 * @_koK_: This pointer refers to the _cnt_ of non-delimiter characters
 *
 * Return: void
 */
void count_non_delim(info_t *_data_, int *_koK_)
{
	int _OK_ = 0;

	while (_data_->arg[_OK_]) /*use loop */
	{
		if (!_my_delm(_data_->arg[_OK_], " \t\n")) /*use if */
			*_koK_ += 1;
		_OK_++;
	}
}

/**
 * hdl_pth_found - This function hdls the scenario when a pth is found
 * @_data_: This pointer refers to parameter and _data_ Struct
 * @pth: This pointer refers to the found pth
 *
 * Return: void
 */
void hdl_pth_found(info_t *_data_, char *pth)
{
	if (pth) /*use if */
	{
		_data_->pth = pth;
		_forkK_comm_(_data_);
	}
}

/**
 * hdl_pth_not_found - This function hdls the scenario when a pth is not found
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: void
 */
void hdl_pth_not_found(info_t *_data_)
{
	/*usef if*/
	if ((_inter_active(_data_) || _get_envv_(_data_,
					"PATH=")
				|| _data_->argv[0][0] == '/')
			&& _my_i_cmdd_(_data_, _data_->argv[0])) /*use if */
		_forkK_comm_(_data_);
	else if (*(_data_->arg) != '\n') /*use if */
	{
		_data_->status = 127;
		_prnt_err_(_data_, "not found\n");
	}
}

/**
 * _find_cmmd_ - This function finds a command in PATH
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: void
 */
void _find_cmmd_(info_t *_data_)
{
	char *pth = NULL;
	int _koK_ = 0, _OK_ = 0;

	_data_->pth = _data_->argv[0];
	increment_line_count(_data_);
	count_non_delim(_data_, &_koK_);
	if (!_koK_) /*use if */
		return;

	do { /*use loop */
		pth = find_pth(_data_, _get_envv_(_data_, "PATH="), _data_->argv[0]);
		_OK_++;
	} while (!pth && _OK_ < 2); /*use loop */

	pth ? hdl_pth_found(_data_, pth) : hdl_pth_not_found(_data_);
}

/**
 * hdl_fork_error - This function hdls fork errors
 * @child_pid: This is the process ID of the child process
 *
 * Return: void
 */
void hdl_fork_error(pid_t child_pid)
{
	child_pid == -1 ? (perror("Error:"), exit(1)) : (void)child_pid;
}

/**
 * hdl_exec_error - This function hdls exec errors
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: void
 */
void hdl_exec_error(info_t *_data_)
{
	execve(_data_->pth, _data_->argv, _gtt_envrnn_(_data_)) == -1 ?
		(_fr_nf_(_data_, 1), errno == EACCES ?
		 exit(126) : exit(1)) : (void)_data_;
}

/**
 * hdl_child_process - This function hdls child process scenarios
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: void
 */
void hdl_child_process(info_t *_data_)
{
	hdl_exec_error(_data_);
}

/**
 * hdl_parent_process - This function hdls parent process scenarios
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: void
 */
void hdl_parent_process(info_t *_data_)
{
	do { /*use loop */
		wait(&(_data_->status));
	} while (!WIFEXITED(_data_->status));

	_data_->status = WEXITSTATUS(_data_->status);
	_data_->status == 126 ?
		_prnt_err_(_data_, "Permission denied\n") : (void)_data_;
}

/**
 * _forkK_comm_ - This function forks a an exec thread to run _Cmd
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: void
 */
void _forkK_comm_(info_t *_data_)
{
	/*decleration*/
	pid_t child_pid = fork();

	hdl_fork_error(child_pid);
	child_pid == 0 ? hdl_child_process(_data_) : hdl_parent_process(_data_);
}



