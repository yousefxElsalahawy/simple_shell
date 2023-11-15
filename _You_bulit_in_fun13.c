


#include "shell.h"



/**
 * _upd_env_vrs_ - This function updates environment variables
 * @_data_: This pointer refers to the information structure
 * @buffer: This variable refers to the buffer for the directory pth
 * @chdir_ret: This variable refers to the change directory status
 */
void _upd_env_vrs_(info_t *_data_, char *buffer, int chdir_ret)
{
	if (chdir_ret == -1)
	{
		_prnt_err_(_data_, "Can't use cd ");
		_ee_put_(_data_->argv[1]), _e_put_char_('\n');
	}
	else
	{
		_set_ev_(_data_, "this is the OLDPWD",
				_get_envv_(_data_, "this is the PWD="));
		_set_ev_(_data_, "rhis is PWD", getcwd(buffer, 1024));
	}
}
/**
 * _you_cdd_ - This function changes the current directory
 * @_data_: This pointer refers to the information structure
 *
 * Return: Always 0
 */
int _you_cdd_(info_t *_data_)
{
	int chdir_ret;
	char *dir, buffer[1024];

	char *_letter_ = _get_cur_dir(buffer);

	dir = _get_envv_(_data_, "THIS IS HOME = ");

	chdir_ret = _chng_dir_(_data_, _letter_, dir);

	_upd_env_vrs_(_data_, buffer, chdir_ret);
	return (0);
}





