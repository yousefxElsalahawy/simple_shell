



#include "shell.h"


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
 * Return: The first _nde_ that starts with
 * the prefix and meets the condition, otherwise NULL
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




