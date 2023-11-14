





#include "shell.h"

/**
 * is_list_empty - Checks if a list is empty
 * @h: Pointer to the head of the list
 *
 * Return: true if the list is empty, false otherwise
 */
bool is_list_empty(const _lst_ *h)
{
	/* use if */
	if (h == NULL)
	{
		_put_ss_("Error: List is empty.\n");
		return (true);
	}
	return (false);
}

/**
 * _lst_len_ - Calculates the length of a list
 * @h: Pointer to the head of the list
 *
 * Return: The length of the list
 */
size_t _lst_len_(const _lst_ *h)
{
	size_t _OK_ = 0;

	/* use if */
	if (is_list_empty(h))
		return (0);

	/* use loop */
	do {
		h = h->_nxt_;
		_OK_++;
	} while (h);

	return (_OK_);
}

/**
 * _alloc_string_array - Allocates memory for a string array
 * @_cnt_: The number of strings in the array
 *
 * Return: A pointer to the allocated string array, or NULL if allocation fails
 */
char **_alloc_string_array(size_t _cnt_)
{
	char **_rslt_ = malloc(sizeof(char *) * (_cnt_ + 1));

	return (_rslt_ != NULL ? _rslt_ : NULL);
}

/**
 * allocate_string - Allocates memory for a string
 * @length: The length of the string
 *
 * Return: A pointer to the allocated string, or NULL if allocation fails
 */
char *allocate_string(size_t length)
{
	char *_rslt_ = malloc(length + 1);

	return (_rslt_ != NULL ? _rslt_ : NULL);
}

/**
 * deallocate_string_array - Deallocates memory for a string array
 * @string_array: The string array to deallocate
 * @_cnt_: The number of strings in the array
 */
void deallocate_string_array(char **string_array, size_t _cnt_)
{
	size_t _indx_ = 0;

	/* use loop */
	do {
		free(string_array[_indx_]);
		_indx_++;
	} while (_indx_ < _cnt_);

	free(string_array);
}

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



/**
 * chk_prefix_and_condition - Check if the string starts with
 *  given prefix and condition
 * @_nde_: The _nde_ containing the string to chk
 * @prefix: The prefix to chk for
 * @_coco_: The condition character to chk against (-1 if no condition)
 *
 * Return: The pointer to the start of the string
 * if the condition is met, otherwise NULL
 */
char *chk_prefix_and_condition(_lst_ *_nde_, char *prefix, char _coco_)
{
	/*Check if the string starts with the given prefix*/
	char *_oops_ = _start_wh_(_nde_->_txt_, prefix);

	/*Return the pointer if the condition is met, otherwise return NULL*/
	return ((_oops_ && ((_coco_ == -1) || (*_oops_ == _coco_))) ? _oops_ : NULL);
}

/**
 * node_starts_with - Find the first _nde_ in the list that starts with
 * given prefix and condition
 * @_nde_: The head of the list
 * @prefix: The prefix to chk for
 * @_coco_: The condition character to chk against (-1 if no condition)
 *
 * Return: The first _nde_ that starts with the prefix and meets the condition, otherwise NULL
 */
_lst_ *node_starts_with(_lst_ *_nde_, char *prefix, char _coco_)
{
	char *_oops_ = NULL;

	if (_nde_ != NULL)
	{
		do {
			/*Check if the _nde_ starts with the given prefix and condition*/
			_oops_ = chk_prefix_and_condition(_nde_, prefix, _coco_);
			if (_oops_ != NULL)
				return (_nde_);
			_nde_ = _nde_->_nxt_;
		} while (_nde_);
	}
	return (NULL);
}

/**
 * chk_ndd - Check the _indx_ of a given _nde_ in the list
 * @head: The head of the list
 * @_nde_: The _nde_ to chk the _indx_ for
 * @_OK_: The current _indx_ of the _nde_
 *
 * Return: The _indx_ of the _nde_ in the list, or -1 if not found
 */
ssize_t chk_ndd(_lst_ *head, _lst_ *_nde_, size_t *_OK_)
{
	do {
		/*Check if the current _nde_ is equal to the given _nde_*/
		if (head == _nde_)
			return (*_OK_);

		head = head->_nxt_;
		(*_OK_)++;
	} while (head != NULL);

	return (-1);
}

/**
 * _gt_nde_indx_ - Get the _indx_ of a given _nde_ in the list
 * @head: The head of the list
 * @_nde_: The _nde_ to get the _indx_ for
 *
 * Return: The _indx_ of the _nde_ in the list, or -1 if not found
 */
ssize_t _gt_nde_indx_(_lst_ *head, _lst_ *_nde_)
{
	size_t _OK_ = 0;

	/*Check the _indx_ of the given _nde_ in the list*/
	return ((head == NULL) ? -1 : chk_ndd(head, _nde_, &_OK_));
}



