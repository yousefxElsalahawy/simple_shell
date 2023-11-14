

#include "shell.h"

/**
 * is_list_empty - Checks if a list is empty
 * @h: Pointer to the _ohadd_ of the list
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
 * _lst_len_ - Calculates the _olent_ of a list
 * @h: Pointer to the _ohadd_ of the list
 *
 * Return: The _olent_ of the list
 */
size_t _lst_len_(const _lst_ *h)
{
	size_t _oops_ = 0;

	/* use if */
	if (is_list_empty(h))
		return (0);

	/* use loop */
	do {
		h = h->_nxt_;
		_oops_++;
	} while (h);

	return (_oops_);
}

/**
 * _alloc_string_array - Allocates memory for a string array
 * @_ocntt_: The number of strings in the array
 *
 * Return: A pointer to the allocated string array, or NULL if allocation fails
 */
char **_alloc_string_array(size_t _ocntt_)
{
	char **_rultt_ = malloc(sizeof(char *) * (_ocntt_ + 1));

    /*return null or  result*/
	return (_rultt_ != NULL ? _rultt_ : NULL);
}

/**
 * allocate_string - Allocates memory for a string
 * @_olent_: The _olent_ of the string
 *
 * Return: A pointer to the allocated string, or NULL if allocation fails
 */
char *allocate_string(size_t _olent_)
{
	char *_rultt_ = malloc(_olent_ + 1);

    /*return null or  result*/

	return (_rultt_ != NULL ? _rultt_ : NULL);
}

/**
 * deallocate_string_array - Deallocates memory for a string array
 * @_ostr_arryy_: The string array to deallocate
 * @_ocntt_: The number of strings in the array
 */
void deallocate_string_array(char **_ostr_arryy_, size_t _ocntt_)
{
	size_t _indx_ = 0;

	/* use loop */
	do {
		free(_ostr_arryy_[_indx_]);
		_indx_++;
	} while (_indx_ < _ocntt_);

	free(_ostr_arryy_);
}

/**
 * _pop_string_array - Populates a string array with strings from a list
 * @_nddee_: Pointer to the _ohadd_ of the list
 * @_ostr_arryy_: The string array to populate
 *
 * Return: The populated string array, or NULL if allocation fails
 */
char **_pop_string_array(_lst_ *_nddee_, char **_ostr_arryy_)
{
	size_t _indx_ = 0;
	char *string;

	/* use loop */
	do {
		string = allocate_string(_str_len_(_nddee_->_txt_));
		if (!string)
		{
			deallocate_string_array(_ostr_arryy_, _indx_);
			return (NULL);
		}
		string = _str_cpy(string, _nddee_->_txt_);
		_ostr_arryy_[_indx_] = string;
		_nddee_ = _nddee_->_nxt_;
		_indx_++;
	} while (_nddee_);
	_ostr_arryy_[_indx_] = NULL;

	return (_ostr_arryy_);
}

/**
 * _lst_to_strng_ - Converts a list of strings to a string array
 * @_ohadd_: Pointer to the _ohadd_ of the list
 *
 * Return: The string array, or NULL if allocation fails
 */
char **_lst_to_strng_(_lst_ *_ohadd_)
{
	size_t _ocntt_ = _lst_len_(_ohadd_);
	char **_ostr_arryy_;

	_ostr_arryy_ = (!_ohadd_ || !_ocntt_) ? NULL : _alloc_string_array(_ocntt_);
	if (!_ostr_arryy_)
		return (NULL);

	_ostr_arryy_ = _pop_string_array(_ohadd_, _ostr_arryy_);
	return (_ostr_arryy_);
}

/**
 * _Print_The_Node_ - Prints the contents of a list _nddee_
 * @_nddee_: Pointer to the list _nddee_
 * @_oops_: Pointer to the _indx_ counter
 */
void _Print_The_Node_(const _lst_ *_nddee_, size_t *_oops_)
{
	_put_ss_(cnvrt_nmbr_(_nddee_->_num_, 10, 0));
	_pputt_char(':');
	_pputt_char(' ');
	_put_ss_(_nddee_->_txt_ ? _nddee_->_txt_ : "(nil)");
	_put_ss_("\n");
	(*_oops_)++;
}

/**
 * traverse_list - Traverses a list and applies a function to each _nddee_
 * @h: Pointer to the _ohadd_ of the list
 * @_operat_: Pointer to the function to apply to each _nddee_
 *
 * Return: The number of ndds traversed
 */
size_t traverse_list(const _lst_ *h, void (*_operat_)(const _lst_*, size_t*))
{
	size_t _oops_ = 0;
	const _lst_ *current = h;

	/* use loop */
	do {
		_operat_(current, &_oops_);
		current = current->_nxt_;
	} while (current);

	return (_oops_);
}

/**
 * _prnt_lst_ - Prints the contents of a list
 * @h: Pointer to the _ohadd_ of the list
 *
 * Return: The number of ndds printed
 */
size_t _prnt_lst_(const _lst_ *h)
{
	size_t _oops_ = traverse_list(h, _Print_The_Node_);

	return (_oops_);
}



/**
 * chk_prefix_and_cond - Check if the string starts with
 *  given _opre_fix_ and condition
 * @_nddee_: The _nddee_ containing the string to chk
 * @_opre_fix_: The _opre_fix_ to chk for
 * @_coco_c: The condition character to chk against (-1 if no condition)
 *
 * Return: The pointer to the _sstrtt_ of the string
 * if the condition is met, otherwise NULL
 */
char *chk_prefix_and_cond(_lst_ *_nddee_, char *_opre_fix_, char _coco_c)
{
    /*Check if the string starts with the given _opre_fix_*/
    char *_oqo_ = _start_wh_(_nddee_->_txt_, _opre_fix_);

    /*Return the pointer if the condition is met, otherwise return NULL*/
    return ((_oqo_ && ((_coco_c == -1) || (*_oqo_ == _coco_c))) ? _oqo_ : NULL);
}

/**
 * _nde_strt_wth_ - Find the first _nddee_ in the list that starts with
 * given _opre_fix_ and condition
 * @_nddee_: The _ohadd_ of the list
 * @_opre_fix_: The _opre_fix_ to chk for
 * @_coco_c: The condition character to chk against (-1 if no condition)
 *
 * Return: The first _nddee_ that starts with the _opre_fix_ and meets the condition, otherwise NULL
 */
_lst_ *_nde_strt_wth_(_lst_ *_nddee_, char *_opre_fix_, char _coco_c)
{
    char *_oqo_ = NULL;

    if (_nddee_ != NULL)
    {
        do {
            /*Check if the _nddee_ starts with the given _opre_fix_ and condition*/
            _oqo_ = chk_prefix_and_cond(_nddee_, _opre_fix_, _coco_c);
            if (_oqo_ != NULL)
                return (_nddee_);
            _nddee_ = _nddee_->_nxt_;
        } while (_nddee_);
    }
    return (NULL);
}

/**
 * chk_ndd - Check the _indx_ of a given _nddee_ in the list
 * @_ohadd_: The _ohadd_ of the list
 * @_nddee_: The _nddee_ to chk the _indx_ for
 * @_oops_: The current _indx_ of the _nddee_
 *
 * Return: The _indx_ of the _nddee_ in the list, or -1 if not found
 */
ssize_t chk_ndd(_lst_ *_ohadd_, _lst_ *_nddee_, size_t *_oops_)
{
    do {
        /*Check if the current _nddee_ is equal to the given _nddee_*/
        if (_ohadd_ == _nddee_)
            return (*_oops_);

        _ohadd_ = _ohadd_->_nxt_;
        (*_oops_)++;
    } while (_ohadd_ != NULL);

    return (-1);
}

/**
 * _gt_nde_indx_ - Get the _indx_ of a given _nddee_ in the list
 * @_ohadd_: The _ohadd_ of the list
 * @_nddee_: The _nddee_ to get the _indx_ for
 *
 * Return: The _indx_ of the _nddee_ in the list, or -1 if not found
 */
ssize_t _gt_nde_indx_(_lst_ *_ohadd_, _lst_ *_nddee_)
{
    size_t _oops_ = 0;

    /*Check the _indx_ of the given _nddee_ in the list*/
    return ((_ohadd_ == NULL) ? -1 : chk_ndd(_ohadd_, _nddee_, &_oops_));
}





