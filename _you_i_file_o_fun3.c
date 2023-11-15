








#include "shell.h"

/**
 * _rd_hstory_ - This function reads the history from a file.
 * @_data_: This pointer refers to the _data_ structure.
 *
 * Return: The history _cnt_ or 0 if reading fails.
 */
int _rd_hstory_(info_t *_data_)
{
	/*declaration*/
	int _line_cnt_ = 0;
	ssize_t fsize;
	struct stat st;
	char *_buff_ = NULL, *filename = get_file(_data_);

	if (!filename)
		/* Return 0 if filename is NULL */
		return (0);
	fsize = open_and_read_file(filename, &_buff_, &st);
	if (fsize == -1)
		/* Return 0 if file opening or reading fails */
		return (0);
	process_buffer(_data_, _buff_, fsize, &_line_cnt_);
	update_history(_data_, _line_cnt_);
	/* Return the history _cnt_ */
	return (_data_->histcount);
}

/**
 * update_nd_numbers - This function updates the _nde_ numbers.
 * @_nde_: The list _nde_.
 *
 * Return: The total _cnt_ of nodes.
 */
int update_nd_numbers(_lst_ **_nde_)
{
	/*declaration*/
	int _indx_ = 0;
	/*use loop */
	do {
		(*_nde_)->_num_ = _indx_++;
		*_nde_ = (*_nde_)->_nxt_;
	} while (*_nde_);
	/* Return the total _cnt_ of nodes */
	return (_indx_);
}

/**
 * _re_num_hstry_ - This function renumbers the history.
 * @_data_: This pointer refers to the _data_ structure.
 *
 * Return: The total _cnt_ of nodes.
 */
int _re_num_hstry_(info_t *_data_)
{
	/*declaration*/
	_lst_ *_nde_ = _data_->history;
	int total_count = (_nde_) ? update_nd_numbers(&_nde_) : 0;

	_data_->histcount = total_count;
	/* Return the total _cnt_ of nodes */
	return (total_count);
}

/**
 * retrieve_history_nd - This function retrieves the history _nde_.
 * @_data_: This pointer refers to the _data_ structure.
 *
 * Return: The history _nde_ or NULL if not found.
 */
_lst_ *retrieve_history_nd(info_t *_data_)
{
	/*declaration*/
	_lst_ *_nde_ = NULL;

	if (_data_ && _data_->history)
		_nde_ = _data_->history;
	/* Return the history _nde_ or NULL if not found */
	return (_nde_);
}

/**
 * _buld_hstry_lst_ - This function builds the history list.
 * @_data_: This pointer refers to the _data_ structure.
 * @_buff_: The buffer to add to the history list.
 * @_line_cnt_: The line _cnt_.
 *
 * Return: Always 0.
 */
int _buld_hstry_lst_(info_t *_data_, char *_buff_, int _line_cnt_)
{
	if (_data_ && _buff_)
	{
		/*declaration*/
		_lst_ *_nde_ = retrieve_history_nd(_data_);

		_add_nd_end_(&_nde_, _buff_, _line_cnt_);
		if (!_data_->history)
			_data_->history = _nde_;
	}
	/* Always return 0 */
	return (0);
}




