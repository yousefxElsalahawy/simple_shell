





#include "shell.h"

/**
 * _you_hstry_ - This function prnts the history of commands
 * @_data_: This pointer refers to the information structure
 *
 * Return: 0 (success)
 */
int _you_hstry_(info_t *_data_)
{
	/*decleration*/
	_lst_ *_tmp_ = _data_->history;

	prnt_list(_tmp_);

	return (0);
}

/**
 * find_equal_sign - This function finds the equal _sgn_ in a string
 * @_txt_: This variable refers to the string to be searched
 *
 * Return: pointer to the equal _sgn_ or NULL
 */
char *find_equal_sign(char *_txt_)
{
	/*decleration*/

	char *_oops_ = _str_n_chr(_txt_, '=');


	return (_oops_ ? _oops_ : NULL);
}

/**
 * _del_alias_ndd - This function deletes an alias _nde_
 * @_data_: This pointer refers to the information structure
 * @_txt_: This variable refers to the string to be deleted
 *
 * Return: 1 if _nde_ not found, else 0
 */
int _del_alias_ndd(info_t *_data_, char *_txt_)
{
	/*decleration*/

	int _indx_ = _gt_nde_indx_(_data_->alias,
			node_starts_with(_data_->alias, _txt_, -1));

	return (_indx_ >= 0 ? _dlt_nd_at_ndx(&(_data_->alias), _indx_) : 1);
}

/**
 * _unstt_alas_ - This function unsets an alias
 * @_data_: This pointer refers to the information structure
 * @_txt_: This variable refers to the string to be unset
 *
 * Return: _rslt_ of _del_alias_ndd
 */
int _unstt_alas_(info_t *_data_, char *_txt_)
{
	/*decleration*/

	int ret;
	char *_oops_, _coco_;

	_oops_ = find_equal_sign(_txt_);
	if (!_oops_)
		return (1);

	_coco_ = *_oops_;
	*_oops_ = 0;
	do {
		ret = _del_alias_ndd(_data_, _txt_);
	} while (ret == 0);
	*_oops_ = _coco_;
	return (ret);
}

/**
 * find_equal_sign_in_nd - This function finds the equal _sgn_ in a _nde_
 * @_nde_: This pointer refers to the _nde_ to be searched
 *
 * Return: pointer to the equal _sgn_ or NULL
 */
char *find_equal_sign_in_nd(_lst_ *_nde_)
{
	return (_nde_ ? _str_n_chr(_nde_->_txt_, '=') : NULL);
}

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

/**
 * hdl_alias - This function hdls an alias
 * @_data_: This pointer refers to the information structure
 * @arg: This variable refers to the argument
 */
void hdl_alias(info_t *_data_, char *arg)
{
	/*decleration*/
	char *_oops_ = _str_n_chr(arg, '=');

	_oops_ ? _stt_alass_(_data_, arg) :
		prnt_alias(node_starts_with(_data_->alias, arg, '='));
}

/**
 * _you_als_ - This function is a mysterious enigma
 * @_data_: This pointer refers to the information structure
 *
 * Return: 0 (always, because it'_letter_ a riddle wrapped in a mystery)
 */
int _you_als_(info_t *_data_)
{
	/**
	 * _OK_: This variable refers to the _indx_ of the argument vector
	 */
	int _OK_ = 1;

	/**
	 * switch: This function uses a switch statement to hdl different cases
	 */
	switch (_data_->argc)
	{
		/**
		 * case 1: aliases if there'_letter_ only one argument
		 */
		case 1:
			prnt_all_aliases(_data_);
			break;
			/**
			 * default: This function hdls each alias if there are multiple arguments
			 */
		default:
			while (_data_->argv[_OK_])
			{
				hdl_alias(_data_, _data_->argv[_OK_]);
				_OK_++;
			}
			break;
	}

	/**
	 * Return: This function always returns 0, because it'_letter_ an enigma
	 */
	return (0);
}


