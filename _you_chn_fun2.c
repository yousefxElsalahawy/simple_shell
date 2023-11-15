#include "shell.h"


/**
 * _gett_ndd_ - Retrieves a _nde_ from the alias list
 * @_data_: This pointer refers to the parameter struct
 *
 * Return: _Nde_ if found, NULL otherwise
 */
_lst_ *_gett_ndd_(info_t *_data_)
{
	/* Use if */
	if (!_data_)
		return (NULL);

	return (node_starts_with(_data_->alias, _data_->argv[0], '='));
	/* Returns _nde_ if found, NULL otherwise */
}

/**
 * get_new_p - Retrieves a new pointer from the _nde_
 * @_nde_: This pointer refers to the _nde_
 *
 * Return: New pointer if found, NULL otherwise
 */
char *get_new_p(_lst_ *_nde_)
{
	/* Declaration */
	char *_oops_;

	/* Use if */
	if (!_nde_)
		return (NULL);

	_oops_ = _str_n_chr(_nde_->_txt_, '=');

	return (_oops_ ? _str_dupp_(_oops_ + 1) : NULL);
	/* Returns new pointer if found, NULL otherwise */
}

/**
 * replace_alias - Replaces the alias
 * in the argv[0] with the _vle_ from the alias list
 * @_data_: This pointer refers to the parameter struct
 *
 * Return: 1 if alias is replaced, 0 otherwise
 */
int replace_alias(info_t *_data_)
{
	/* Declaration */
	int _OK_ = 0;
	_lst_ *_nde_;
	char *_oops_;

	/* Use if */
	if (!_data_)
		return (0);

	/* Use loop */
	do {
		_nde_ = _gett_ndd_(_data_);

		/* Use if */
		if (!_nde_)
			return (0);

		_oops_ = get_new_p(_nde_);

		/* Use if */
		if (!_oops_)
			return (0);
		free(_data_->argv[0]);
		_data_->argv[0] = _oops_;
		_OK_++;
	} while (_OK_ < 10 && _data_->argv[0] == NULL);

	return (_data_->argv[0] != NULL);
	/* Returns 1 if alias is replaced, 0 otherwise */
}

/**
 * chk_variable_type - Checks the _style of
 * the variable in argv[_OK_]
 * @_data_: This pointer refers to the parameter struct
 * @_OK_: This variable refers to the _indx_ of argv
 *
 * Return: 0 if not a variable,
 * 1 if status variable, 2 if PID variable, 3 otherwise
 */
int chk_variable_type(info_t *_data_, int _OK_)
{
	/* Use if */
	if (_data_->argv[_OK_][0] != '$' || !_data_->argv[_OK_][1])
		return (0);
	else if (!_str_cmpp_(_data_->argv[_OK_], "$?"))
		return (1);
	else if (!_str_cmpp_(_data_->argv[_OK_], "$$"))
		return (2);
	else
		return (3);
	/* Returns 0 if not a variable, 1, 2 , 3  */
}

/**
 * replace_string_with_value - Replaces the string in argv[_OK_] with the _vle_
 * @_data_: This pointer refers to the parameter struct
 * @_OK_: This variable refers to the _indx_ of argv
 * @_vle_: This variable refers to the _vle_ to replace with
 *
 * Return: Nothing (void function)
 */
void replace_string_with_value(info_t *_data_, int _OK_, int _vle_)
{
	_rplce_str_(&(_data_->argv[_OK_]), _str_dupp_(cnvrt_nmbr_(_vle_, 10, 0)));
}



