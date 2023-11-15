




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









