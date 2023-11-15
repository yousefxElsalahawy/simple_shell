






#include "shell.h"


/**
 * _pop_string_array - Populates a string array with strings from a list
 * @_nde_: Pointer to the head of the list
 * @string_array: The string array to populate
 *
 * Return: The populated string array, or NULL if allocation fails
 */
char **_pop_string_array(_lst_ *_nde_, char **string_array)
{
	size_t _indx_ = 0;
	char *string;

	/* use loop */
	do {
		string = allocate_string(_str_len_(_nde_->_txt_));
		if (!string)
		{
			deallocate_string_array(string_array, _indx_);
			return (NULL);
		}
		string = _str_cpy(string, _nde_->_txt_);
		string_array[_indx_] = string;
		_nde_ = _nde_->_nxt_;
		_indx_++;
	} while (_nde_);
	string_array[_indx_] = NULL;

	return (string_array);
}

/**
 * _lst_to_strng_ - Converts a list of strings to a string array
 * @head: Pointer to the head of the list
 *
 * Return: The string array, or NULL if allocation fails
 */
char **_lst_to_strng_(_lst_ *head)
{
	size_t _cnt_ = _lst_len_(head);
	char **string_array;

	string_array = (!head || !_cnt_) ? NULL : _alloc_string_array(_cnt_);
	if (!string_array)
		return (NULL);

	string_array = _pop_string_array(head, string_array);
	return (string_array);
}

/**
 * _Print_The_Node_ - Prints the contents of a list _nde_
 * @_nde_: Pointer to the list _nde_
 * @_OK_: Pointer to the _indx_ counter
 */
void _Print_The_Node_(const _lst_ *_nde_, size_t *_OK_)
{
	_put_ss_(cnvrt_nmbr_(_nde_->_num_, 10, 0));
	_pputt_char(':');
	_pputt_char(' ');
	_put_ss_(_nde_->_txt_ ? _nde_->_txt_ : "(nil)");
	_put_ss_("\n");
	(*_OK_)++;
}

/**
 * traverse_list - Traverses a list and applies a function to each _nde_
 * @h: Pointer to the head of the list
 * @_operat_: Pointer to the function to apply to each _nde_
 *
 * Return: The number of nodes traversed
 */
size_t traverse_list(const _lst_ *h, void (*_operat_)(const _lst_*, size_t*))
{
	size_t _OK_ = 0;
	const _lst_ *current = h;

	/* use loop */
	do {
		_operat_(current, &_OK_);
		current = current->_nxt_;
	} while (current);

	return (_OK_);
}

/**
 * prnt_list - Prints the contents of a list
 * @h: Pointer to the head of the list
 *
 * Return: The number of nodes prnted
 */
size_t prnt_list(const _lst_ *h)
{
	size_t _OK_ = traverse_list(h, _Print_The_Node_);

	return (_OK_);
}








