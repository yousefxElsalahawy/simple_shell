


#include "shell.h"


/**
 * create_env_nd - This function creates a new environment _nde_
 *
 * Return: pointer to the new _nde_
 */
_lst_ *create_env_nd(void)
{
	size_t _OK_ = 0;
	_lst_ *_nde_ = NULL;

	if (environ[_OK_])
	{
		do {
			_add_nd_end_(&_nde_, environ[_OK_], 0);
			_OK_++;
		} while (environ[_OK_]);
	}

	return (_nde_); /* Return pointer to the new _nde_ */
}

/**
 * _pop_env_lst_ - This function populates the environment list
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: 0 (success), 1 (error)
 */
int _pop_env_lst_(info_t *_data_)
{
	_data_->env = create_env_nd();

	return ((_data_->env != NULL) ? 0 : 1);
	/* Return 0 if the environment list is populated successfully, 1 otherwise */
}



