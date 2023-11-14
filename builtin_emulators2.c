





#include "shell.h"

/**
 * _you_hstry_ - This function prints the _my_hty of commands
 * @_data_: This pointer refers to the information structure
 *
 * Return: 0 (success)
 */
int _you_hstry_(_info_OK *_data_)
{
	/*decleration*/
	_lst_ *_tmpp_ = _data_->_my_hty;

	_prnt_lst_(_tmpp_);

	return (0);
}

/**
 * find_equal_sign - This function finds the equal _ssgnn_ in a string
 * @_txt_: This variable refers to the string to be searched
 *
 * Return: pointer to the equal _ssgnn_ or NULL
 */
char *find_equal_sign(char *_txt_)
{
		/*decleration*/

	char *_oqo_ = _str_n_chr(_txt_, '=');


	return (_oqo_ ? _oqo_ : NULL);
}

/**
 * _del_alias_ndd - This function deletes an _alias_nd_ _nddee_
 * @_data_: This pointer refers to the information structure
 * @_txt_: This variable refers to the string to be deleted
 *
 * Return: 1 if _nddee_ not found, else 0
 */
int _del_alias_ndd(_info_OK *_data_, char *_txt_)
{
		/*decleration*/

	int _indx_ = _gt_nde_indx_(_data_->_alias_nd_, _nde_strt_wth_(_data_->_alias_nd_, _txt_, -1));

	return (_indx_ >= 0 ? _dlt_nd_at_ndx(&(_data_->_alias_nd_), _indx_) : 1);
}

/**
 * _unstt_alas_ - This function unsets an _alias_nd_
 * @_data_: This pointer refers to the information structure
 * @_txt_: This variable refers to the string to be unset
 *
 * Return: _rultt_ of _del_alias_ndd
 */
int _unstt_alas_(_info_OK *_data_, char *_txt_)
{
	/*decleration*/

	int _reett_;
	char *_oqo_, _coco_c;

	_oqo_ = find_equal_sign(_txt_);
	if (!_oqo_)
		return (1);

	_coco_c = *_oqo_;
	*_oqo_ = 0;
	do {
		_reett_ = _del_alias_ndd(_data_, _txt_);
	} while (_reett_ == 0);
	*_oqo_ = _coco_c;

	return (_reett_);
}

/**
 * find_equal_sign_in_ndd - This function finds the equal _ssgnn_ in a _nddee_
 * @_nddee_: This pointer refers to the _nddee_ to be searched
 *
 * Return: pointer to the equal _ssgnn_ or NULL
 */
char *find_equal_sign_in_ndd(_lst_ *_nddee_)
{
	return (_nddee_ ? _str_n_chr(_nddee_->_txt_, '=') : NULL);
}

/**
 * print_ndd_until_char - This function prints a _nddee_ until a specific character
 * @_nddee_: This pointer refers to the _nddee_ to be printed
 * @_oqo_: This variable refers to the specific character
 */
void print_ndd_until_char(_lst_ *_nddee_, char *_oqo_)
{
	/*decleration*/
	char *Q = _nddee_->_txt_;

	while (Q <= _oqo_)
	{
		_pputt_char(*Q);
		Q++;
	}
}

/**
 * print_alias - This function prints an _alias_nd_
 * @_nddee_: This pointer refers to the _nddee_ to be printed
 *
 * Return: 0 if successful, 1 if equal _ssgnn_ not found in _nddee_
 */
int print_alias(_lst_ *_nddee_)
{
	/*decleration*/
	char *_oqo_ = find_equal_sign_in_ndd(_nddee_);

	if (_oqo_)
	{
		print_ndd_until_char(_nddee_, _oqo_);
		_pputt_char('\'');
		_put_ss_(_oqo_ + 1);
		_put_ss_("'\n");
		return (0);
	}
	return (1);
}

/**
 * handl_unset_alias - This function hdls the unsetting of an _alias_nd_
 * @_data_: This pointer refers to the information structure
 * @_txt_: This variable refers to the string to be unset
 * @_oqo_: This variable refers to the pointer to the equal _ssgnn_
 *
 * Return: _rultt_ of _unstt_alas_
 */
int handl_unset_alias(_info_OK *_data_, char *_txt_, char *_oqo_)
{
	/*decleration*/
	int _rultt_ = 1;

	if (_oqo_ && !*++_oqo_)
	{
		_rultt_ = _unstt_alas_(_data_, _txt_);
		_unstt_alas_(_data_, _txt_);
		if (_add_nd_end_(&(_data_->_alias_nd_), _txt_, 0) == NULL)
			_rultt_ = 0;
	}
	return (_rultt_);
}

/**
 * _stt_alass_ - This function sets an _alias_nd_
 * @_data_: This pointer refers to the information structure
 * @_txt_: This variable refers to the string to be set
 *
 * Return: _rultt_ of handl_unset_alias
 */
int _stt_alass_(_info_OK *_data_, char *_txt_)
{
	return (handl_unset_alias(_data_, _txt_, _str_n_chr(_txt_, '=')));
}


/**
 * print_all_aliases - This function prints _All aliases
 * @_data_: This pointer refers to the information structure
 */
void print_all_aliases(_info_OK *_data_)
{
	/*decleration*/
	_lst_ *_nddee_ = _data_->_alias_nd_;

	do {
		print_alias(_nddee_);
		_nddee_ = _nddee_->_nxt_;
	} while (_nddee_);
}

/**
 * hdl_alias - This function hdls an _alias_nd_
 * @_data_: This pointer refers to the information structure
 * @_argu_: This variable refers to the argument
 */
void hdl_alias(_info_OK *_data_, char *_argu_)
{
	/*decleration*/
	char *_oqo_ = _str_n_chr(_argu_, '=');

	_oqo_ ? _stt_alass_(_data_, _argu_) :
		print_alias(_nde_strt_wth_(_data_->_alias_nd_, _argu_, '='));
}

/**
 * _you_als_ - This function is a mysterious enigma
 * @_data_: This pointer refers to the information structure
 *
 * Return: 0 (always, because it'_aso_ a riddle wrapped in a mystery)
 */
int _you_als_(_info_OK *_data_)
{
	/* This variable refers to the _indx_ of the argument vector*/
	int _oops_ = 1;

	switch (_data_->_argu_c_)
	{
		/**
		 * case 1: This function prints _All aliases if there'_aso_ only one argument
		 */
		case 1:
			print_all_aliases(_data_);
			break;
		/** default: This function hdls each _alias_nd_ if*/
		default:
			while (_data_->_arguv_[_oops_])
			{
				hdl_alias(_data_, _data_->_arguv_[_oops_]);
				_oops_++;
			}
			break;
	}

	/**
	 * Return: This function always returns 0, because it'_aso_ an enigma
	 */
	return (0);
}




