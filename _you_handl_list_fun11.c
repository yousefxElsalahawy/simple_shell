






#include "shell.h"

/**
 * _gen_unique_ndd - This function generates a unique _nde_
 *
 * Return: new_nd (success), NULL (error)
 */
_lst_ *_gen_unique_ndd(void)
{
	/*use malloc*/
	_lst_ *new_nd = (_lst_ *)malloc(sizeof(_lst_));

	/*use if*/
	return ((!new_nd) ? NULL :
			(_lst_ *)_mem_sett_((void *)new_nd, 0, sizeof(_lst_)));
}

/**
 * _pop_ndd_data - This function populates a _nde_ with data
 * @_nde_: This pointer refers to the _nde_ to be populated
 * @_txt_: This string is used as the data for the _nde_
 * @_num_: This integer is used as the _indx_ for the _nde_
 *
 * Return: void
 */
void _pop_ndd_data(_lst_ *_nde_, const char *_txt_, int _num_)
{
	/*use if*/
	if (_nde_)
	{
		_nde_->_num_ = _num_;
		_nde_->_txt_ = _txt_ ? strdup(_txt_) : NULL;
		/*use if*/
		if (_txt_ && !_nde_->_txt_)
		{
			free(_nde_);
			_nde_ = NULL;
		}
	}
}

/**
 * link_new_head - This function links a new head to a list
 * @head: This pointer refers to the head of the list
 * @new_head: This pointer refers to the new head to be linked
 *
 * Return: void
 */
void link_new_head(_lst_ **head, _lst_ *new_head)
{
	/*use if*/
	if (new_head && head)
	{
		new_head->_nxt_ = *head;
		*head = new_head;
	}
}

/**
 * _add_nd_ - This function adds a _nde_ to a list
 * @head: This pointer refers to the head of the list
 * @_txt_: This string is used as the data for the _nde_
 * @_num_: This integer is used as the _indx_ for the _nde_
 *
 * Return: new_head (success), NULL (error)
 */
_lst_ *_add_nd_(_lst_ **head, const char *_txt_, int _num_)
{
	/*use if*/
	if (head)
	{
		_lst_ *new_head = _gen_unique_ndd();

		/*use if*/
		if (new_head)
		{
			_pop_ndd_data(new_head, _txt_, _num_);
			link_new_head(head, new_head);
		}
		/*use return*/
		return (new_head);
	}
	/*use return*/
	return (NULL);
}

/**
 * create_new_nd - This function creates a new _nde_
 * @_txt_: This string is used as the data for the _nde_
 * @_num_: This integer is used as the _indx_ for the _nde_
 *
 * Return: new_nd (success), NULL (error)
 */
_lst_ *create_new_nd(const char *_txt_, int _num_)
{
	/*use malloc*/
	_lst_ *new_nd = (_lst_ *)malloc(sizeof(_lst_));

	/*use if*/
	if (new_nd == NULL)
		/*use return*/
		return (NULL);
	new_nd->_num_ = _num_;
	new_nd->_txt_ = _txt_ ? _str_dupp_(_txt_) : NULL;
	/*use if*/
	if (_txt_ && !new_nd->_txt_)
	{
		free(new_nd);
		/*use return*/
		return (NULL);
	}
	new_nd->_nxt_ = NULL;
	/*use return*/
	return (new_nd);
}






