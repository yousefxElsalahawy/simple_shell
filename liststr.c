






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

/**
 * find_last_nd - This function finds the last _nde_ in a list
 * @_nde_: This pointer refers to the _nde_ to start from
 *
 * Return: _nde_ (success), NULL (error)
 */
_lst_ *find_last_nd(_lst_ *_nde_)
{
	/*use if*/
	if (_nde_)
	{
		/*use loop*/
		while (_nde_->_nxt_)
		{
			_nde_ = _nde_->_nxt_;
		}
	}
	/*use return*/
	return (_nde_);
}

/**
 * link_new_nd_to_end - This function links a new _nde_ to the end of a list
 * @_nde_: This pointer refers to the _nde_ to be linked
 * @new_nd: This pointer refers to the new _nde_ to be linked
 *
 * Return: void
 */
void link_new_nd_to_end(_lst_ *_nde_, _lst_ *new_nd)
{
	/*use if*/
	if (_nde_)
	{
		_nde_->_nxt_ = new_nd;
	}
}
/**
 * _add_nd_end_ - This function adds a _nde_ to the end of a list
 * @head: This pointer refers to the head of the list
 * @_txt_: This string is used as the data for the _nde_
 * @_num_: This integer is used as the _indx_ for the _nde_
 *
 * Return: new_nd (success), NULL (error)
 */
_lst_ *_add_nd_end_(_lst_ **head, const char *_txt_, int _num_)
{
	_lst_ *new_nd = create_new_nd(_txt_, _num_);
	_lst_ *last_nd;

	/*use if*/
	if (!new_nd)
		/*use return*/
		return (NULL);

	last_nd = find_last_nd(*head);

	/*use if*/
	if (last_nd)
	{
		link_new_nd_to_end(last_nd, new_nd);
	}
	else
	{
		*head = new_nd;
	}
	/*use return*/
	return (new_nd);
}

/**
 * prnt_ndd - This function prnts a _nde_
 * @_nde_: This pointer refers to the _nde_ to be prnted
 *
 * Return: void
 */
void prnt_ndd(const _lst_ *_nde_)
{
	char *str_to_prnt = "(nil)";

	/*use if*/
	if (_nde_ && _nde_->_txt_)
		str_to_prnt = (char *)_nde_->_txt_;

	_put_ss_(str_to_prnt);
	_put_ss_("\n");
}

/**
 * prnt_list_str - This function prnts the string of a list
 * @h: This pointer refers to the head of the list
 *
 * Return: _OK_ (success), 0 (error)
 */
size_t prnt_list_str(const _lst_ *h)
{
	size_t _OK_ = 0;
	const _lst_ *current_nd = h;

	/*use if*/
	if (!h)
		/*use return*/
		return (0);
	do {
		prnt_ndd(current_nd);
		current_nd = current_nd->_nxt_;
		_OK_++;
	} while (current_nd);

	/*use return*/
	return (_OK_);
}

/**
 * is_head_null - This function chks if the head of a list is null
 * @head: This pointer refers to the head of the list
 *
 * Return: 1 (success), 0 (error)
 */
int is_head_null(_lst_ **head)
{
	/*use if*/
	return ((!head || !*head) ? 0 : 1);
}

/**
 * delete_ndd - This function deletes a _nde_
 * @_nde_: This pointer refers to the _nde_ to be deleted
 *
 * Return: void
 */
void delete_ndd(_lst_ **_nde_)
{
	free((*_nde_)->_txt_);
	free(*_nde_);
	*_nde_ = NULL;
}

/**
 * delete_head_nd - This function deletes the head _nde_ of a list
 * @head: This pointer refers to the head of the list
 *
 * Return: void
 */
void delete_head_nd(_lst_ **head)
{
	_lst_ *temp_nd = *head;

	*head = (*head)->_nxt_;
	delete_ndd(&temp_nd);
}

/**
 * delete_index_nd - This function deletes a _nde_ at a specific _indx_
 * @_nde_: This pointer refers to the _nde_ to be deleted
 * @prev_nd: This pointer refers to the previous _nde_
 *
 * Return: void
 */
void delete_index_nd(_lst_ **_nde_, _lst_ *prev_nd)
{
	prev_nd->_nxt_ = (*_nde_)->_nxt_;
	delete_ndd(_nde_);
}

/**
 * iterate_through_nds - This function iterates through nodes of a list
 * @head: This pointer refers to the head of the list
 * @_indx_: This integer is used as the _indx_ for the _nde_
 *
 * Return: 1 (success), 0 (error)
 */
int iterate_through_nds(_lst_ **head, unsigned int _indx_)
{
	_lst_ *current_nd = *head, *prev_nd = NULL;
	unsigned int counter = 0;

	/*use if*/
	if (current_nd)
	{
		/*use loop*/
		do {
			/*use if*/
			if (counter++ == _indx_)
			{
				delete_index_nd(&current_nd, prev_nd);
				/*use return*/
				return (1);
			}
			prev_nd = current_nd;
			current_nd = current_nd->_nxt_;
		} while (current_nd);
	}
	/*use return*/
	return (0);
}



/**
 * _dlt_nd_at_ndx - This function deletes a _nde_ at a specific _indx_
 * @head: This pointer refers to the head of the list
 * @_indx_: This integer is used as the _indx_ for the _nde_
 *
 * Return: 1 (success), 0 (error)
 */
int _dlt_nd_at_ndx(_lst_ **head, unsigned int _indx_)
{
	/*use if*/
	if (!is_head_null(head))
		/*use return*/
		return (0);

	/*use if*/
	if (_indx_ == 0)
	{
		delete_head_nd(head);
		/*use return*/
		return (1);
	}
	else
	{
		/*use return*/
		return (iterate_through_nds(head, _indx_));
	}
}

/**
 * annihilate_nd - This function annihilates a _nde_
 * @_nde_: This pointer refers to the _nde_ to be annihilated
 *
 * Return: void
 */
void annihilate_nd(_lst_ *_nde_)
{
	/*use if*/
	if (_nde_)
	{
		free(_nde_->_txt_);
		free(_nde_);
	}
}

/**
 * fetch_next_in_line - This function fetches the _nxt_ _nde_ in line
 * @_nde_: This pointer refers to the _nde_ to start from
 *
 * Return: _nde_ (success), NULL (error)
 */
_lst_ *fetch_next_in_line(_lst_ *_nde_)
{
	/*use if*/
	return (_nde_ ? _nde_->_nxt_ : NULL);
}

/**
 * _ree_lst_ - This function frees a list
 * @head_ptr: This pointer refers to the head of the list
 *
 * Return: void
 */
void _ree_lst_(_lst_ **head_ptr)
{
	_lst_ *_nde_, *next_nd;

	/*use if*/
	if (!head_ptr)
		return;

	_nde_ = *head_ptr;
	/*use if*/
	if (_nde_)
	{
		/*use loop*/
		do {
			next_nd = fetch_next_in_line(_nde_);
			annihilate_nd(_nde_);
			_nde_ = next_nd;
		} while (_nde_);
	}

	*head_ptr = NULL;
}



