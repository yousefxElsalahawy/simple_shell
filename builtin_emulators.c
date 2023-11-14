




#include "shell.h"

/**
 * alien_translator - This function translates alien language
 * @_txt_: This variable refers to the alien string to be translated
 *
 * Return: Translated integer _vlle_
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
void interstellar_communicator(_info_OK *_data_, char *message)
{
    _data_->_cmdd_status_ = 2;
    _ee_put_(message);
    _ee_put_(_data_->_arguv_[1]);
    _e_put_char_('\n');
}

/**
 * galactic_chker - This function chks galactic conditions
 * @_data_: This pointer refers to the information structure
 *
 * Return: Exit chk _cmdd_status_
 */
int galactic_chker(_info_OK *_data_)
{
    int _ext_chk_ = alien_translator(_data_->_arguv_[1]);

    return ((_ext_chk_ == -1) ? (interstellar_communicator(_data_, "Illegal number: "), 1) : _ext_chk_);
}

/**
 * cosmic_status_setter - This function sets cosmic _cmdd_status_
 * @_data_: This pointer refers to the information structure
 * @_ext_chk_: This variable refers to the exit chk _cmdd_status_
 */
void cosmic_status_setter(_info_OK *_data_, int _ext_chk_)
{
    _data_->_num_error_ = _ext_chk_;
}

/**
 * _you_ext_ - This function exits the shell
 * @_data_: This pointer refers to the information structure
 *
 * Return: Exit _cmdd_status_
 */
int _you_ext_(_info_OK *_data_)
{
    int _ext_chk_;

    if (_data_->_arguv_[1])  /* If there is an exit argument */
    {
        _ext_chk_ = galactic_chker(_data_);
        switch (_ext_chk_) {
            case 1:
                return (1);
            default:
                cosmic_status_setter(_data_, _ext_chk_);
                return (-2);
        }
    }
    else
    {
        _data_->_num_error_ = -1;
        return (-2);
    }
}

/**
 * _you_hlp_ - This function provides help
 * @_data_: This pointer refers to the information structure
 *
 * Return: Always 0
 */
int _you_hlp_(_info_OK *_data_)
{
    char **_ar_arry_ = _data_->_arguv_;

    if (_ar_arry_ != NULL)
    {
        print_help_message(_data_);
    }

    return (0);
}

/**
 * print_help_message - This function prints help message
 * @_data_: This pointer refers to the information structure
 */
void print_help_message(_info_OK *_data_)
{
    _put_ss_("this Function do Not Work Yet Implemented. \n");

    if (_data_ != NULL)
    {
        int _oops_ = 0;

        while (_data_->_arguv_[_oops_] != NULL)
        {
            _put_ss_(_data_->_arguv_[_oops_]);
            _oops_++;
        }
    }
}

/**
 * _get_cur_dir - This function gets the current directory
 * @_obuf_fer_: This variable refers to the _obuf_fer_ for the directory _my_pth_
 *
 * Return: Current directory _my_pth_
 */
char *_get_cur_dir(char *_obuf_fer_)
{
    char *_aso_ = getcwd(_obuf_fer_, 1024);

    if (!_aso_)
        _put_ss_("getcwd is failure  here\n");
    return (_aso_);
}

/**
 * _chng_dir_ - This function changes the directory
 * @_data_: This pointer refers to the information structure
 * @_aso_: This variable refers to the current directory _my_pth_
 * @_do_dir_: This variable refers to the directory to change to
 *
 * Return: Change directory _cmdd_status_
 */
int _chng_dir_(_info_OK *_data_, char *_aso_, char *_do_dir_)
{
	/*decleration*/
    int _chdr_rrt_;

	/*use if */
    if (!_data_->_arguv_[1])
    {
        _do_dir_ = _do_dir_ ? _do_dir_ : _get_env_(_data_, "this is the PWD=");
        _do_dir_ = _do_dir_ ? _do_dir_ : "/";
        _chdr_rrt_ = chdir(_do_dir_);
    }
    else if (_str_cmpp_(_data_->_arguv_[1], "-") == 0)
    {
        _do_dir_ = _get_env_(_data_, "this is the OLDPWD=");

        if (!_do_dir_)
        {
            _put_ss_(_aso_);
            _pputt_char('\n');
            return (1);
        }
        _put_ss_(_do_dir_), _pputt_char('\n');
        _do_dir_ = _do_dir_ ? _do_dir_ : "/";
        _chdr_rrt_ = chdir(_do_dir_);
    }
    else
        _chdr_rrt_ = chdir(_data_->_arguv_[1]);
    return (_chdr_rrt_);
}











/**
 * _upd_env_vrs_ - This function updates environment variables
 * @_data_: This pointer refers to the information structure
 * @_obuf_fer_: This variable refers to the _obuf_fer_ for the directory _my_pth_
 * @_chdr_rrt_: This variable refers to the change directory _cmdd_status_
 */
void _upd_env_vrs_(_info_OK *_data_, char *_obuf_fer_, int _chdr_rrt_)
{
	if (_chdr_rrt_ == -1)
	{
		print_error(_data_, "Can't use cd ");
		_ee_put_(_data_->_arguv_[1]), _e_put_char_('\n');
	}
	else
	{
		_set_ev_(_data_, "this is the OLDPWD", _get_env_(_data_, "this is the PWD="));
		_set_ev_(_data_, "rhis is PWD", getcwd(_obuf_fer_, 1024));
	}
}
/**
 * _you_cdd_ - This function changes the current directory
 * @_data_: This pointer refers to the information structure
 *
 * Return: Always 0
 */
int _you_cdd_(_info_OK *_data_)
{
    int _chdr_rrt_;
    char *_do_dir_, _obuf_fer_[1024];

    char *_aso_ = _get_cur_dir(_obuf_fer_);

    _do_dir_ = _get_env_(_data_, "THIS IS HOME = ");

    _chdr_rrt_ = _chng_dir_(_data_, _aso_, _do_dir_);

    _upd_env_vrs_(_data_, _obuf_fer_, _chdr_rrt_);
    return (0);
}

