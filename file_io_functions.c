






#include "shell.h"

/**
 * get_dir - This function gets the directory.
 * @param _data_: This pointer refers to the _data_ structure.
 *
 * Return: The directory or NULL if not found.
 */
char *get_dir(_info_OK *_data_)
{
	/*declaration*/
	char *_do_dir_;

	_do_dir_ = _get_env_(_data_, "THIS IS THE HOME=");
	/* Return the directory or NULL if not found */
	return (_do_dir_ ? _do_dir_ : NULL);
}

/**
 * allocate_buf - This function allocates memory for the _obuf_fer_.
 * @param _do_dir_: This variable is the directory.
 *
 * Return: The allocated _obuf_fer_ or NULL if allocation fails.
 */
char *allocate_buf(char *_do_dir_)
{
	/*declaration*/
	char *_bbuuff_ = _do_dir_ ? malloc(sizeof(char) * (_str_len_(_do_dir_) + _str_len_(_MYHIST_FILE_) + 2)) : NULL;

	if (_bbuuff_)
		_bbuuff_[0] = 0;
	/* Return the allocated _obuf_fer_ or NULL if allocation fails */
	return (_bbuuff_);
}

/**
 * _gt_hstry_fle_ - This function gets the _my_hty file.
 * @param _data_: This pointer refers to the _data_ structure.
 *
 * Return: The _my_hty file or NULL if not found.
 */
char *_gt_hstry_fle_(_info_OK *_data_)
{
	/*declaration*/
	char *_do_dir_ = get_dir(_data_);
	char *_bbuuff_ = allocate_buf(_do_dir_);

	if (!_bbuuff_)
		/* Return NULL if _obuf_fer_ allocation fails */
		return (NULL);
	_str_cpy(_bbuuff_, _do_dir_);
	_str_catt_(_bbuuff_, "/");
	_str_catt_(_bbuuff_, _MYHIST_FILE_);
	/* Return the _my_hty file or NULL if not found */
	return (_bbuuff_);
}

/**
 * open_file - This function opens a file.
 * @param _fl_nmee_: The name of the file to open.
 *
 * Return: The file descriptor or -1 if opening fails.
 */
int open_file(char *_fl_nmee_)
{
	/*declaration*/
	ssize_t _fl_dir_;

	_fl_dir_ = open(_fl_nmee_, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(_fl_nmee_);
	/* Return the file descriptor or -1 if opening fails */
	return ((_fl_dir_ == -1) ? -1 : _fl_dir_);
}

/**
 * write_to_file - This function writes to a file.
 * @param _nddee_: The list _nddee_ containing the strings to write.
 * @param _fl_dir_: The file descriptor.
 */
void write_to_file(_lst_ *_nddee_, ssize_t _fl_dir_)
{
	if (_nddee_)
	{
		/*use loop */
		do {
			_put_s_fdd_(_nddee_->_txt_, _fl_dir_);
			_put_fdd_('\n', _fl_dir_);
			_nddee_ = _nddee_->_nxt_;
		} while (_nddee_);
	}
	_put_fdd_(_BUFFER_FLUSH, _fl_dir_);
	/* This function does not return a _vlle_ */
}

/**
 * _wrt_hstry_ - This function writes the _my_hty to a file.
 * @param _data_: This pointer refers to the _data_ structure.
 *
 * Return: 1 (success) or -1 (error).
 */
int _wrt_hstry_(_info_OK *_data_)
{
	/*declaration*/
	ssize_t _fl_dir_;
	char *_fl_nmee_ = _gt_hstry_fle_(_data_);

	if (!_fl_nmee_)
		/* Return -1 if _fl_nmee_ is NULL */
		return (-1);

	_fl_dir_ = open_file(_fl_nmee_);
	if (_fl_dir_ == -1)
		/* Return -1 if file opening fails */
		return (-1);

	write_to_file(_data_->_my_hty, _fl_dir_);
	close(_fl_dir_);
	/* Return 1 for successful write operation */
	return (1);
}

/**
 * get_file - This function gets the _my_hty file.
 * @param _data_: This pointer refers to the _data_ structure.
 *
 * Return: The _my_hty file or NULL if not found.
 */
char *get_file(_info_OK *_data_)
{
	/* Return the _my_hty file or NULL if not found */
	return (_gt_hstry_fle_(_data_) ? _gt_hstry_fle_(_data_) : NULL);
}

/**
 * open_and_read_file - This function opens and reads a file.
 * @param _fl_nmee_: The name of the file to open and read.
 * @param _bbuuff_: The _obuf_fer_ to store the file contents.
 * @param _qst_: The stat structure to store file information.
 *
 * Return: The file _osize_ or -1 if opening or reading fails.
 */
ssize_t open_and_read_file(char *_fl_nmee_, char **_bbuuff_, struct stat *_qst_)
{
	/*declaration*/
	ssize_t _fl_dir_, rdlen, _F_Size = 0;
    
	_fl_dir_ = open(_fl_nmee_, O_RDONLY);
	free(_fl_nmee_);
	if (_fl_dir_ == -1)
		/* Return -1 if file opening fails */

		return (-1);
	if (!fstat(_fl_dir_, _qst_))
		_F_Size = _qst_->st_size;
	if (_F_Size < 2)
		/* Return -1 if file _osize_ is less than 2 */
		return (-1);
	*_bbuuff_ = malloc(sizeof(char) * (_F_Size + 1));
	if (!(*_bbuuff_))
		/* Return -1 if _obuf_fer_ allocation fails */
		return (-1);
	rdlen = read(_fl_dir_, *_bbuuff_, _F_Size);
	(*_bbuuff_)[_F_Size] = 0;
	if (rdlen <= 0)
		/* Return -1 if reading fails */
		return (free(*_bbuuff_), -1);

	close(_fl_dir_);
	/* Return the file _osize_ */
	return (_F_Size);
}

/**
 * process_buffer - This function processes the _obuf_fer_.
 * @param _data_: This pointer refers to the _data_ structure.
 * @param _bbuuff_: The _obuf_fer_ to process.
 * @param _F_Size: The _osize_ of the _obuf_fer_.
 * @param _lne_cnnt_: The line _ocntt_.
 */
void process_buffer(_info_OK *_data_, char *_bbuuff_, ssize_t _F_Size, int *_lne_cnnt_)
{
	/*declaration*/
	int _oops_ = 0, last = 0;

	/*use loop */
	do {
		if (_bbuuff_[_oops_] == '\n' || _oops_ == _F_Size)
		{
			_bbuuff_[_oops_] = 0;
			_buld_hstry_lst_(_data_, _bbuuff_ + last, (*_lne_cnnt_)++);
			last = _oops_ + 1;
		}
		_oops_++;
	} while (_oops_ <= _F_Size);
	free(_bbuuff_);
	/* This function does not return a _vlle_ */
}

/**
 * update_history - This function updates the _my_hty.
 * @param _data_: This pointer refers to the _data_ structure.
 * @param _lne_cnnt_: The line _ocntt_.
 */
void update_history(_info_OK *_data_, int _lne_cnnt_)
{
	_data_->_my_tcount_ = _lne_cnnt_;
	/*use loop */
	do {
		_dlt_nd_at_ndx(&(_data_->_my_hty), 0);
		_data_->_my_tcount_--;
	} while (_data_->_my_tcount_ >= _MYHIST_MAX_);
	_re_num_hstry_(_data_);
	/* This function does not return a _vlle_ */
}

/**
 * _rd_hstory_ - This function reads the _my_hty from a file.
 * @param _data_: This pointer refers to the _data_ structure.
 *
 * Return: The _my_hty _ocntt_ or 0 if reading fails.
 */
int _rd_hstory_(_info_OK *_data_)
{
	/*declaration*/
	int _lne_cnnt_ = 0;
	ssize_t _F_Size;
	struct stat _qst_;
	char *_bbuuff_ = NULL, *_fl_nmee_ = get_file(_data_);

	if (!_fl_nmee_)
		/* Return 0 if _fl_nmee_ is NULL */
		return (0);

	_F_Size = open_and_read_file(_fl_nmee_, &_bbuuff_, &_qst_);
	if (_F_Size == -1)
		/* Return 0 if file opening or reading fails */
		return (0);

	process_buffer(_data_, _bbuuff_, _F_Size, &_lne_cnnt_);
	update_history(_data_, _lne_cnnt_);
	/* Return the _my_hty _ocntt_ */
	return (_data_->_my_tcount_);
}

/**
 * update_ndd_numbers - This function updates the _nddee_ numbers.
 * @param _nddee_: The list _nddee_.
 *
 * Return: The total _ocntt_ of ndds.
 */
int update_ndd_numbers(_lst_ **_nddee_)
{
	/*declaration*/
	int _indx_ = 0;

	/*use loop */
	do {
		(*_nddee_)->_num_ = _indx_++;
		*_nddee_ = (*_nddee_)->_nxt_;
	} while (*_nddee_);
	/* Return the total _ocntt_ of ndds */
	return (_indx_);
}

/**
 * _re_num_hstry_ - This function renumbers the _my_hty.
 * @param _data_: This pointer refers to the _data_ structure.
 *
 * Return: The total _ocntt_ of ndds.
 */
int _re_num_hstry_(_info_OK *_data_)
{
	/*declaration*/
	_lst_ *_nddee_ = _data_->_my_hty;
	int total_count = (_nddee_) ? update_ndd_numbers(&_nddee_) : 0;

	_data_->_my_tcount_ = total_count;
	/* Return the total _ocntt_ of ndds */
	return (total_count);
}

/**
 * retrieve_history_ndd - This function retrieves the _my_hty _nddee_.
 * @param _data_: This pointer refers to the _data_ structure.
 *
 * Return: The _my_hty _nddee_ or NULL if not found.
 */
_lst_ *retrieve_history_ndd(_info_OK *_data_)
{
	/*declaration*/
	_lst_ *_nddee_ = NULL;

	if (_data_ && _data_->_my_hty)
		_nddee_ = _data_->_my_hty;
	/* Return the _my_hty _nddee_ or NULL if not found */
	return (_nddee_);
}

/**
 * _buld_hstry_lst_ - This function builds the _my_hty list.
 * @param _data_: This pointer refers to the _data_ structure.
 * @param _bbuuff_: The _obuf_fer_ to add to the _my_hty list.
 * @param _lne_cnnt_: The line _ocntt_.
 *
 * Return: Always 0.
 */
int _buld_hstry_lst_(_info_OK *_data_, char *_bbuuff_, int _lne_cnnt_)
{
	if (_data_ && _bbuuff_)
	{
		/*declaration*/
		_lst_ *_nddee_ = retrieve_history_ndd(_data_);

		_add_nd_end_(&_nddee_, _bbuuff_, _lne_cnnt_);

		if (!_data_->_my_hty)
			_data_->_my_hty = _nddee_;
	}
	/* Always return 0 */
	return (0);
}


