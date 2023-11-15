







#include "shell.h"


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












