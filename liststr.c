



#include "shell.h"

/**
 * _gen_unique_ndd - This function generates a unique _nddee_
 *
 * Return: new_ndd (success), NULL (error)
 */
_lst_ *_gen_unique_ndd(void)
{
	/*use malloc*/
	_lst_ *new_ndd = (_lst_ *)malloc(sizeof(_lst_));

	/*use if*/
	return ((!new_ndd) ? NULL :
			(_lst_ *)_mem_sett_((void *)new_ndd, 0, sizeof(_lst_)));
}

/**
 * _pop_ndd_data - This function populates a _nddee_ with data
 * @_nddee_: This pointer refers to the _nddee_ to be populated
 * @_txt_: This string is used as the data for the _nddee_
 * @_num_: This integer is used as the _indx_ for the _nddee_
 *
 * Return: void
 */
void _pop_ndd_data(_lst_ *_nddee_, const char *_txt_, int _num_)
{
	/*use if*/
	if (_nddee_)
	{
		_nddee_->_num_ = _num_;
		_nddee_->_txt_ = _txt_ ? strdup(_txt_) : NULL;
		/*use if*/
		if (_txt_ && !_nddee_->_txt_)
		{
			free(_nddee_);
			_nddee_ = NULL;
		}
	}
}

/**
 * link_new_head - This function links a _nww_ _ohadd_ to a list
 * @_ohadd_: This pointer refers to the _ohadd_ of the list
 * @_nw_hd_: This pointer refers to the _nww_ _ohadd_ to be linked
 *
 * Return: void
 */
void link_new_head(_lst_ **_ohadd_, _lst_ *_nw_hd_)
{
	/*use if*/
	if (_nw_hd_ && _ohadd_)
	{
		_nw_hd_->_nxt_ = *_ohadd_;
		*_ohadd_ = _nw_hd_;
	}
}

/**
 * _add_nd_ - This function adds a _nddee_ to a list
 * @_ohadd_: This pointer refers to the _ohadd_ of the list
 * @_txt_: This string is used as the data for the _nddee_
 * @_num_: This integer is used as the _indx_ for the _nddee_
 *
 * Return: _nw_hd_ (success), NULL (error)
 */
_lst_ *_add_nd_(_lst_ **_ohadd_, const char *_txt_, int _num_)
{
	/*use if*/
	if (_ohadd_)
	{
		_lst_ *_nw_hd_ = _gen_unique_ndd();

		/*use if*/
		if (_nw_hd_)
		{
			_pop_ndd_data(_nw_hd_, _txt_, _num_);
			link_new_head(_ohadd_, _nw_hd_);
		}
		/*use return*/
		return (_nw_hd_);
	}
	/*use return*/
	return (NULL);
}

/**
 * create_new_ndd - This function creates a _nww_ _nddee_
 * @_txt_: This string is used as the data for the _nddee_
 * @_num_: This integer is used as the _indx_ for the _nddee_
 *
 * Return: new_ndd (success), NULL (error)
 */
_lst_ *create_new_ndd(const char *_txt_, int _num_)
{
	/*use malloc*/
	_lst_ *new_ndd = (_lst_ *)malloc(sizeof(_lst_));

	/*use if*/
	if (new_ndd == NULL)
		/*use return*/
		return (NULL);
	new_ndd->_num_ = _num_;
	new_ndd->_txt_ = _txt_ ? _str_dupp_(_txt_) : NULL;
	/*use if*/
	if (_txt_ && !new_ndd->_txt_)
	{
		free(new_ndd);
		/*use return*/
		return (NULL);
	}
	new_ndd->_nxt_ = NULL;
	/*use return*/
	return (new_ndd);
}

/**
 * find_last_ndd - This function finds the last _nddee_ in a list
 * @_nddee_: This pointer refers to the _nddee_ to _sstrtt_ from
 *
 * Return: _nddee_ (success), NULL (error)
 */
_lst_ *find_last_ndd(_lst_ *_nddee_)
{
	/*use if*/
	if (_nddee_)
	{
		/*use loop*/
		while (_nddee_->_nxt_)
		{
			_nddee_ = _nddee_->_nxt_;
		}
	}
	/*use return*/
	return (_nddee_);
}

/**
 * link_new_ndd_to_end - This function links a _nww_ _nddee_ to the _End of a list
 * @_nddee_: This pointer refers to the _nddee_ to be linked
 * @new_ndd: This pointer refers to the _nww_ _nddee_ to be linked
 *
 * Return: void
 */
void link_new_ndd_to_end(_lst_ *_nddee_, _lst_ *new_ndd)
{
	/*use if*/
	if (_nddee_)
	{
		_nddee_->_nxt_ = new_ndd;
	}
}
/**
 * _add_nd_end_ - This function adds a _nddee_ to the _End of a list
 * @_ohadd_: This pointer refers to the _ohadd_ of the list
 * @_txt_: This string is used as the data for the _nddee_
 * @_num_: This integer is used as the _indx_ for the _nddee_
 *
 * Return: new_ndd (success), NULL (error)
 */
_lst_ *_add_nd_end_(_lst_ **_ohadd_, const char *_txt_, int _num_)
{
	_lst_ *new_ndd = create_new_ndd(_txt_, _num_);
	_lst_ *last_ndd;

	/*use if*/
	if (!new_ndd)
		/*use return*/
		return (NULL);

	last_ndd = find_last_ndd(*_ohadd_);

	/*use if*/
	if (last_ndd)
	{
		link_new_ndd_to_end(last_ndd, new_ndd);
	}
	else
	{
		*_ohadd_ = new_ndd;
	}
	/*use return*/
	return (new_ndd);
}

/**
 * print_ndd - This function prints a _nddee_
 * @_nddee_: This pointer refers to the _nddee_ to be printed
 *
 * Return: void
 */
void print_ndd(const _lst_ *_nddee_)
{
	char *str_to_print = "(nil)";

	/*use if*/
	if (_nddee_ && _nddee_->_txt_)
		str_to_print = (char *)_nddee_->_txt_;

	_put_ss_(str_to_print);
	_put_ss_("\n");
}

/**
 * print_list_str - This function prints the string of a list
 * @h: This pointer refers to the _ohadd_ of the list
 *
 * Return: _oops_ (success), 0 (error)
 */
size_t print_list_str(const _lst_ *h)
{
	size_t _oops_ = 0;
	const _lst_ *current_ndd = h;

	/*use if*/
	if (!h)
		/*use return*/
		return (0);
	do {
		print_ndd(current_ndd);
		current_ndd = current_ndd->_nxt_;
		_oops_++;
	} while (current_ndd);

	/*use return*/
	return (_oops_);
}

/**
 * is_head_null - This function chks if the _ohadd_ of a list is null
 * @_ohadd_: This pointer refers to the _ohadd_ of the list
 *
 * Return: 1 (success), 0 (error)
 */
int is_head_null(_lst_ **_ohadd_)
{
	/*use if*/
	return ((!_ohadd_ || !*_ohadd_) ? 0 : 1);
}

/**
 * delete_ndd - This function deletes a _nddee_
 * @_nddee_: This pointer refers to the _nddee_ to be deleted
 *
 * Return: void
 */
void delete_ndd(_lst_ **_nddee_)
{
	free((*_nddee_)->_txt_);
	free(*_nddee_);
	*_nddee_ = NULL;
}

/**
 * delete_head_ndd - This function deletes the _ohadd_ _nddee_ of a list
 * @_ohadd_: This pointer refers to the _ohadd_ of the list
 *
 * Return: void
 */
void delete_head_ndd(_lst_ **_ohadd_)
{
	_lst_ *temp_ndd = *_ohadd_;

	*_ohadd_ = (*_ohadd_)->_nxt_;
	delete_ndd(&temp_ndd);
}

/**
 * delete_index_ndd - This function deletes a _nddee_ at a specific _indx_
 * @_nddee_: This pointer refers to the _nddee_ to be deleted
 * @prev_ndd: This pointer refers to the previous _nddee_
 *
 * Return: void
 */
void delete_index_ndd(_lst_ **_nddee_, _lst_ *prev_ndd)
{
	prev_ndd->_nxt_ = (*_nddee_)->_nxt_;
	delete_ndd(_nddee_);
}

/**
 * iterate_through_ndds - This function iterates through ndds of a list
 * @_ohadd_: This pointer refers to the _ohadd_ of the list
 * @_indx_: This integer is used as the _indx_ for the _nddee_
 *
 * Return: 1 (success), 0 (error)
 */
int iterate_through_ndds(_lst_ **_ohadd_, unsigned int _indx_)
{
	_lst_ *current_ndd = *_ohadd_, *prev_ndd = NULL;
	unsigned int counter = 0;

	/*use if*/
	if (current_ndd)
	{
		/*use loop*/
		do {
			/*use if*/
			if (counter++ == _indx_)
			{
				delete_index_ndd(&current_ndd, prev_ndd);
				/*use return*/
				return (1);
			}
			prev_ndd = current_ndd;
			current_ndd = current_ndd->_nxt_;
		} while (current_ndd);
	}
	/*use return*/
	return (0);
}



/**
 * _dlt_nd_at_ndx - This function deletes a _nddee_ at a specific _indx_
 * @_ohadd_: This pointer refers to the _ohadd_ of the list
 * @_indx_: This integer is used as the _indx_ for the _nddee_
 *
 * Return: 1 (success), 0 (error)
 */
int _dlt_nd_at_ndx(_lst_ **_ohadd_, unsigned int _indx_)
{
	/*use if*/
	if (!is_head_null(_ohadd_))
		/*use return*/
		return (0);

	/*use if*/
	if (_indx_ == 0)
	{
		delete_head_ndd(_ohadd_);
		/*use return*/
		return (1);
	}
	else
	{
		/*use return*/
		return (iterate_through_ndds(_ohadd_, _indx_));
	}
}

/**
 * annihilate_ndd - This function annihilates a _nddee_
 * @_nddee_: This pointer refers to the _nddee_ to be annihilated
 *
 * Return: void
 */
void annihilate_ndd(_lst_ *_nddee_)
{
	/*use if*/
	if (_nddee_)
	{
		free(_nddee_->_txt_);
		free(_nddee_);
	}
}

/**
 * fetch_next_in_line - This function fetches the _nxt_ _nddee_ in line
 * @_nddee_: This pointer refers to the _nddee_ to _sstrtt_ from
 *
 * Return: _nddee_ (success), NULL (error)
 */
_lst_ *fetch_next_in_line(_lst_ *_nddee_)
{
	/*use if*/
	return (_nddee_ ? _nddee_->_nxt_ : NULL);
}

/**
 * _ree_lst_ - This function frees a list
 * @_hd_ptr_: This pointer refers to the _ohadd_ of the list
 *
 * Return: void
 */
void _ree_lst_(_lst_ **_hd_ptr_)
{
	_lst_ *_nddee_, *next_ndd;

	/*use if*/
	if (!_hd_ptr_)
		return;

	_nddee_ = *_hd_ptr_;
	/*use if*/
	if (_nddee_)
	{
		/*use loop*/
		do {
			next_ndd = fetch_next_in_line(_nddee_);
			annihilate_ndd(_nddee_);
			_nddee_ = next_ndd;
		} while (_nddee_);
	}

	*_hd_ptr_ = NULL;
}


