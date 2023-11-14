





#include "shell.h"

/**
 * get_dir - This function gets the directory.
 * @param _data_: This pointer refers to the _data_ structure.
 *
 * Return: The directory or NULL if not found.
 */
char *get_dir(info_t *_data_)
{
	/*declaration*/
	char *dir;
	dir = _get_envv_(_data_, "THIS IS THE HOME=");
	/* Return the directory or NULL if not found */
	return (dir ? dir : NULL);
}

/**
 * allocate_buf - This function allocates memory for the buffer.
 * @param dir: This variable is the directory.
 *
 * Return: The allocated buffer or NULL if allocation fails.
 */
char *allocate_buf(char *dir)
{
	/*declaration*/
	char *_buff_ = dir ? malloc(sizeof(char) * (_str_len_(dir) + _str_len_(HIST_FILE) + 2)) : NULL;
	if (_buff_)
		_buff_[0] = 0;
	/* Return the allocated buffer or NULL if allocation fails */
	return (_buff_);
}

/**
 * _gt_hstry_fle_ - This function gets the history file.
 * @param _data_: This pointer refers to the _data_ structure.
 *
 * Return: The history file or NULL if not found.
 */
char *_gt_hstry_fle_(info_t *_data_)
{
	/*declaration*/
	char *dir = get_dir(_data_);
	char *_buff_ = allocate_buf(dir);
	if (!_buff_)
		/* Return NULL if buffer allocation fails */
		return (NULL);
	_str_cpy(_buff_, dir);
	_str_catt_(_buff_, "/");
	_str_catt_(_buff_, HIST_FILE);
	/* Return the history file or NULL if not found */
	return (_buff_);
}

/**
 * open_file - This function opens a file.
 * @param filename: The name of the file to open.
 *
 * Return: The file descriptor or -1 if opening fails.
 */
int open_file(char *filename)
{
	/*declaration*/
	ssize_t _fl_dir_;
	_fl_dir_ = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	/* Return the file descriptor or -1 if opening fails */
	return ((_fl_dir_ == -1) ? -1 : _fl_dir_);
}

/**
 * write_to_file - This function writes to a file.
 * @param _nde_: The list _nde_ containing the strings to write.
 * @param _fl_dir_: The file descriptor.
 */
void write_to_file(_lst_ *_nde_, ssize_t _fl_dir_)
{
	if (_nde_)
	{
		/*use loop */
		do {
			_put_s_fdd_(_nde_->_txt_, _fl_dir_);
			_put_fdd_('\n', _fl_dir_);
			_nde_ = _nde_->_nxt_;
		} while (_nde_);
	}
	_put_fdd_(BUF_FLUSH, _fl_dir_);
	/* This function does not return a _vle_ */
}

/**
 * _wrt_hstry_ - This function writes the history to a file.
 * @param _data_: This pointer refers to the _data_ structure.
 *
 * Return: 1 (success) or -1 (error).
 */
int _wrt_hstry_(info_t *_data_)
{
	/*declaration*/
	ssize_t _fl_dir_;
	char *filename = _gt_hstry_fle_(_data_);
	if (!filename)
		/* Return -1 if filename is NULL */
		return (-1);
	_fl_dir_ = open_file(filename);
	if (_fl_dir_ == -1)
		/* Return -1 if file opening fails */
		return (-1);
	write_to_file(_data_->history, _fl_dir_);
	close(_fl_dir_);
	/* Return 1 for successful write operation */
	return (1);
}

/**
 * get_file - This function gets the history file.
 * @param _data_: This pointer refers to the _data_ structure.
 *
 * Return: The history file or NULL if not found.
 */
char *get_file(info_t *_data_)
{
	/* Return the history file or NULL if not found */
	return (_gt_hstry_fle_(_data_) ? _gt_hstry_fle_(_data_) : NULL);
}

/**
 * open_and_read_file - This function opens and reads a file.
 * @param filename: The name of the file to open and read.
 * @param _buff_: The buffer to store the file contents.
 * @param st: The stat structure to store file information.
 *
 * Return: The file size or -1 if opening or reading fails.
 */
ssize_t open_and_read_file(char *filename, char **_buff_, struct stat *st)
{
	/*declaration*/
	ssize_t _fl_dir_, rdlen, fsize = 0;
	_fl_dir_ = open(filename, O_RDONLY);
	free(filename);
	if (_fl_dir_ == -1)
		/* Return -1 if file opening fails */
		return (-1);
	if (!fstat(_fl_dir_, st))
		fsize = st->st_size;
	if (fsize < 2)
		/* Return -1 if file size is less than 2 */
		return (-1);
	*_buff_ = malloc(sizeof(char) * (fsize + 1));
	if (!(*_buff_))
		/* Return -1 if buffer allocation fails */
		return (-1);
	rdlen = read(_fl_dir_, *_buff_, fsize);
	(*_buff_)[fsize] = 0;
	if (rdlen <= 0)
		/* Return -1 if reading fails */
		return (free(*_buff_), -1);
	close(_fl_dir_);
	/* Return the file size */
	return (fsize);
}

/**
 * process_buffer - This function processes the buffer.
 * @param _data_: This pointer refers to the _data_ structure.
 * @param _buff_: The buffer to process.
 * @param fsize: The size of the buffer.
 * @param _line_cnt_: The line _cnt_.
 */
void process_buffer(info_t *_data_, char *_buff_, ssize_t fsize, int *_line_cnt_)
{
	/*declaration*/
	int _OK_ = 0, last = 0;
	/*use loop */
	do {
		if (_buff_[_OK_] == '\n' || _OK_ == fsize)
		{
			_buff_[_OK_] = 0;
			_buld_hstry_lst_(_data_, _buff_ + last, (*_line_cnt_)++);
			last = _OK_ + 1;
		}
		_OK_++;
	} while (_OK_ <= fsize);
	free(_buff_);
	/* This function does not return a _vle_ */
}

/**
 * update_history - This function updates the history.
 * @param _data_: This pointer refers to the _data_ structure.
 * @param _line_cnt_: The line _cnt_.
 */
void update_history(info_t *_data_, int _line_cnt_)
{
	_data_->histcount = _line_cnt_;
	/*use loop */
	do {
		_dlt_nd_at_ndx(&(_data_->history), 0);
		_data_->histcount--;
	} while (_data_->histcount >= HIST_MAX);
	_re_num_hstry_(_data_);
	/* This function does not return a _vle_ */
}

/**
 * _rd_hstory_ - This function reads the history from a file.
 * @param _data_: This pointer refers to the _data_ structure.
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
 * @param _nde_: The list _nde_.
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
 * @param _data_: This pointer refers to the _data_ structure.
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
 * @param _data_: This pointer refers to the _data_ structure.
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
 * @param _data_: This pointer refers to the _data_ structure.
 * @param _buff_: The buffer to add to the history list.
 * @param _line_cnt_: The line _cnt_.
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


