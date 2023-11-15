



#include "shell.h"


/**
 * _you_hlp_ - This function provides help
 * @_data_: This pointer refers to the information structure
 *
 * Return: Always 0
 */
int _you_hlp_(info_t *_data_)
{
	char **arg_array = _data_->argv;

	if (arg_array != NULL)
	{
		prnt_help_message(_data_);
	}

	return (0);
}

/**
 * prnt_help_message - This function prnts help message
 * @_data_: This pointer refers to the information structure
 */
void prnt_help_message(info_t *_data_)
{
	_put_ss_("this Function do Not Work Yet Implemented. \n");

	if (_data_ != NULL)
	{
		int _OK_ = 0;

		while (_data_->argv[_OK_] != NULL)
		{
			_put_ss_(_data_->argv[_OK_]);
			_OK_++;
		}
	}
}

/**
 * _get_cur_dir - This function gets the current directory
 * @buffer: This variable refers to the buffer for the directory pth
 *
 * Return: Current directory pth
 */
char *_get_cur_dir(char *buffer)
{
	char *_letter_ = getcwd(buffer, 1024);

	if (!_letter_)
		_put_ss_("getcwd is failure  here\n");
	return (_letter_);
}

/**
 * _chng_dir_ - This function changes the directory
 * @_data_: This pointer refers to the information structure
 * @_letter_: This variable refers to the current directory pth
 * @dir: This variable refers to the directory to change to
 *
 * Return: Change directory status
 */
int _chng_dir_(info_t *_data_, char *_letter_, char *dir)
{
	/*decleration*/
	int chdir_ret;

	/*use if */
	if (!_data_->argv[1])
	{
		dir = dir ? dir : _get_envv_(_data_, "this is the PWD=");
		dir = dir ? dir : "/";
		chdir_ret = chdir(dir);
	}
	else if (_str_cmpp_(_data_->argv[1], "-") == 0)
	{
		dir = _get_envv_(_data_, "this is the OLDPWD=");

		if (!dir)
		{
			_put_ss_(_letter_);
			_pputt_char('\n');
			return (1);
		}
		_put_ss_(dir), _pputt_char('\n');
		dir = dir ? dir : "/";
		chdir_ret = chdir(dir);
	}
	else
		chdir_ret = chdir(_data_->argv[1]);
	return (chdir_ret);
}




