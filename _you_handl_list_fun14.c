


#include "shell.h"

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




