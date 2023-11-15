





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



