

#include "shell.h"



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




