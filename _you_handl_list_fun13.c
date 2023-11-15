




#include "shell.h"

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












