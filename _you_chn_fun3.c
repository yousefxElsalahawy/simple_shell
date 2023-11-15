#include "shell.h"













/**
 * _get_ndd_ - Retrieves a _nde_ from the environment list
 * @_data_: This pointer refers to the parameter struct
 * @_OK_: This variable refers to the _indx_ of argv
 *
 * Return: _Nde_ if found, NULL otherwise
 */
_lst_ *_get_ndd_(info_t *_data_, int _OK_)
{
	return (node_starts_with(_data_->env,
				&_data_->argv[_OK_][1], '='));
	/* Returns _nde_ if found, NULL otherwise */
}

/**
 * replace_with_nd_value - Replaces the string in
 * argv[_OK_] with the _vle_ from the _nde_
 * @_data_: This pointer refers to the parameter struct
 * @_OK_: This variable refers to the _indx_ of argv
 * @_nde_: This pointer refers to the _nde_
 *
 * Return: Nothing (void function)
 */
void replace_with_nd_value(info_t *_data_, int _OK_, _lst_ *_nde_)
{
	_rplce_str_(&(_data_->argv[_OK_]),
			_str_dupp_(_str_n_chr(_nde_->_txt_, '=') + 1));
}

/**
 * replace_with_empty_string - Replaces the
 * string in argv[_OK_] with an empty string
 * @_data_: This pointer refers to the parameter struct
 * @_OK_: This variable refers to the _indx_ of argv
 *
 * Return: Nothing (void function)
 */
void replace_with_empty_string(info_t *_data_, int _OK_)
{
	_rplce_str_(&_data_->argv[_OK_], _str_dupp_(""));
}


/**
 * rplce_vrs_ - Replaces the variables in argv with their corresponding values
 * @_data_: This pointer refers to the parameter struct
 *
 * Return: 0 (void function)
 */
int rplce_vrs_(info_t *_data_)
{
	/* Declaration */
	int _OK_ = 0;
	_lst_ *_nde_;
	int var_type;

	/* Use loop */
	do {
		var_type = chk_variable_type(_data_, _OK_);

		/* Use switch */
		switch (var_type)
		{
			case 0:
				_OK_++;
				continue;
			case 1:
				replace_string_with_value(_data_, _OK_, _data_->status);
				break;
			case 2:
				if (kill(getpid(), 0) == 0)
				{
					replace_string_with_value(_data_, _OK_, getpid());
				}
				else
				{
					replace_with_empty_string(_data_, _OK_);
				}
				break;
			case 3:
				_nde_ = _get_ndd_(_data_, _OK_);
				if (_nde_)
					replace_with_nd_value(_data_, _OK_, _nde_);
				else
					replace_with_empty_string(_data_, _OK_);
				break;
		}
		_OK_++;
	} while (_data_->argv[_OK_]);

	return (0); /* Returns 0 (void function) */
}

/**
 * _rplce_str_ - Replaces old string with new string
 * @old: This pointer refers to the old string
 * @new: This pointer refers to the new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int _rplce_str_(char **old, char *new)
{
	/* Use if */
	if (old == NULL || new == NULL)
	{
		_put_ss_("Error: Null pointer passed to _rplce_str_\n");
		return (0); /* Returns 0 if either old or new is NULL */
	}
	if (*old != new)
	{
		free(*old);
		*old = new;
	}
	return (1); /* Returns 1 if replaced */
}


