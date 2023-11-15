

#include "shell.h"


/**
 * _wrt_hstry_ - This function writes the history to a file.
 * @_data_: This pointer refers to the _data_ structure.
 *
 * Return: 1 (success) or -1 (error).
 */
int _wrt_hstry_(info_t *_data_)
{
	/*declaration*/
	ssize_t _fl_dir_;
	char *filename = _gt_hstry_fle_(_data_);

	if (!filename)
	{
		/* Return -1 if filename is NULL */
		return (-1);
	}
	_fl_dir_ = open_file(filename);
	if (_fl_dir_ == -1)
	{
		/* Return -1 if file opening fails */
		return (-1);
	}
	write_to_file(_data_->history, _fl_dir_);
	close(_fl_dir_);
	/* Return 1 for successful write operation */
	return (1);
}

/**
 * get_file - This function gets the history file.
 * @_data_: This pointer refers to the _data_ structure.
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
 * @filename: The name of the file to open and read.
 * @_buff_: The buffer to store the file contents.
 * @st: The stat structure to store file information.
 *
 * Return: The file size or -1 if opening or reading fails.
 */
ssize_t open_and_read_file(char *filename, char **_buff_, struct stat *st)
{
	/*declaration*/
	ssize_t _fl_dir_, rdlen, fsize = 0;

	/*use loop */
	_fl_dir_ = open(filename, O_RDONLY);
	free(filename);
	if (_fl_dir_ == -1)
	{
		/* Return -1 if file opening fails */
		return (-1);
	}
	if (!fstat(_fl_dir_, st))
		fsize = st->st_size;
	if (fsize < 2)
	{
		/* Return -1 if file size is less than 2 */
		return (-1);
	}
	*_buff_ = malloc(sizeof(char) * (fsize + 1));
	if (!(*_buff_))
	{
		/* Return -1 if buffer allocation fails */
		return (-1);
	}
	rdlen = read(_fl_dir_, *_buff_, fsize);
	(*_buff_)[fsize] = 0;
	if (rdlen <= 0)
	{
		/* Return -1 if reading fails */
		return (free(*_buff_), -1);
	}
	close(_fl_dir_);
	/* Return the file size */
	return (fsize);
}

/**
 * process_buffer - This function processes the buffer.
 * @_data_: This pointer refers to the _data_ structure.
 * @_buff_: The buffer to process.
 * @fsize: The size of the buffer.
 * @_line_cnt_: The line _cnt_.
 */
void process_buffer(info_t *_data_, char *_buff_,
	ssize_t fsize, int *_line_cnt_)
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
	} while (fsize <= _OK_);
	free(_buff_);
	/* This function does not return a _vle_ */
}

/**
 * update_history - This function updates the history.
 * @_data_: This pointer refers to the _data_ structure.
 * @_line_cnt_: The line _cnt_.
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



