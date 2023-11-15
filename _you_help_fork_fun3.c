



#include "shell.h"


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












