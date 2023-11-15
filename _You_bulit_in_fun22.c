


#include "shell.h"

/**
 * prnt_nd_until_char - This function prnts a _nde_ until a specific character
 * @_nde_: This pointer refers to the _nde_ to be prnted
 * @_oops_: This variable refers to the specific character
 */
void prnt_nd_until_char(_lst_ *_nde_, char *_oops_)
{
	/*decleration*/
	char *a = _nde_->_txt_;

	while (a <= _oops_)
	{
		_pputt_char(*a);
		a++;
	}
}

/**
 * prnt_alias - This function prnts an alias
 * @_nde_: This pointer refers to the _nde_ to be prnted
 *
 * Return: 0 if successful, 1 if equal _sgn_ not found in _nde_
 */
int prnt_alias(_lst_ *_nde_)
{
	/*decleration*/
	char *_oops_ = find_equal_sign_in_nd(_nde_);

	if (_oops_)
	{
		prnt_nd_until_char(_nde_, _oops_);
		_pputt_char('\'');
		_put_ss_(_oops_ + 1);
		_put_ss_("'\n");
		return (0);
	}
	return (1);
}

/**
 * hdl_unset_alias - This function hdls the unsetting of an alias
 * @_data_: This pointer refers to the information structure
 * @_txt_: This variable refers to the string to be unset
 * @_oops_: This variable refers to the pointer to the equal _sgn_
 *
 * Return: _rslt_ of _unstt_alas_
 */
int hdl_unset_alias(info_t *_data_, char *_txt_, char *_oops_)
{
	/*decleration*/
	int _rslt_ = 1;

	if (_oops_ && !*++_oops_)
	{
		_rslt_ = _unstt_alas_(_data_, _txt_);
		_unstt_alas_(_data_, _txt_);
		if (_add_nd_end_(&(_data_->alias), _txt_, 0) == NULL)
			_rslt_ = 0;
	}
	return (_rslt_);
}

/**
 * _stt_alass_ - This function sets an alias
 * @_data_: This pointer refers to the information structure
 * @_txt_: This variable refers to the string to be set
 *
 * Return: _rslt_ of hdl_unset_alias
 */
int _stt_alass_(info_t *_data_, char *_txt_)
{
	return (hdl_unset_alias(_data_, _txt_, _str_n_chr(_txt_, '=')));
}


/**
 * prnt_all_aliases - This function prnts all aliases
 * @_data_: This pointer refers to the information structure
 */
void prnt_all_aliases(info_t *_data_)
{
	/*decleration*/
	_lst_ *_nde_ = _data_->alias;

	do {
		prnt_alias(_nde_);
		_nde_ = _nde_->_nxt_;
	} while (_nde_);
}







