



#include "shell.h"

/**
 * alien_translator - This function translates alien language
 * @_txt_: This variable refers to the alien string to be translated
 *
 * Return: Translated integer _vle_
 */
int alien_translator(char *_txt_)
{
	return (atoi(_txt_));
}

/**
 * interstellar_communicator - This function communicates interstellar messages
 * @_data_: This pointer refers to the information structure
 * @message: This variable refers to the message to be communicated
 */
void interstellar_communicator(info_t *_data_, char *message)
{
	_data_->status = 2;
	_ee_put_(message);
	_ee_put_(_data_->argv[1]);
	_e_put_char_('\n');
}

/**
 * galactic_chker - This function chks galactic conditions
 * @_data_: This pointer refers to the information structure
 *
 * Return: Exit chk status
 */
int galactic_chker(info_t *_data_)
{
	int exitchk = alien_translator(_data_->argv[1]);

	return ((exitchk == -1) ? (interstellar_communicator(_data_, "Illegal number: "), 1) : exitchk);
}

/**
 * cosmic_status_setter - This function sets cosmic status
 * @_data_: This pointer refers to the information structure
 * @exitchk: This variable refers to the exit chk status
 */
void cosmic_status_setter(info_t *_data_, int exitchk)
{
	_data_->err_num = exitchk;
}

/**
 * _you_ext_ - This function exits the shell
 * @_data_: This pointer refers to the information structure
 *
 * Return: Exit status
 */
int _you_ext_(info_t *_data_)
{
	int exitchk;

	if (_data_->argv[1])  /* If there is an exit argument */
	{
		exitchk = galactic_chker(_data_);
		switch (exitchk) {
			case 1:
				return (1);
			default:
				cosmic_status_setter(_data_, exitchk);
				return (-2);
		}
	}
	else
	{
		_data_->err_num = -1;
		return (-2);
	}
}

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
		_set_ev_(_data_, "this is the OLDPWD", _get_envv_(_data_, "this is the PWD="));
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




