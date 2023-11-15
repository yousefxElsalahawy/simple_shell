





#include "shell.h"

/**
 * get_dir - This function gets the directory.
 * @_data_: This pointer refers to the _data_ structure.
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
 * @dir: This variable is the directory.
 *
 * Return: The allocated buffer or NULL if allocation fails.
 */
char *allocate_buf(char *dir)
{
	/*declaration*/
	char *_buff_ = dir ? malloc(sizeof(char) *
			(_str_len_(dir) + _str_len_(HIST_FILE) + 2)) : NULL;

	if (_buff_)
		_buff_[0] = 0;
	/* Return the allocated buffer or NULL if allocation fails */
	return (_buff_);
}

/**
 * _gt_hstry_fle_ - This function gets the history file.
 * @_data_: This pointer refers to the _data_ structure.
 *
 * Return: The history file or NULL if not found.
 */
char *_gt_hstry_fle_(info_t *_data_)
{
	/*declaration*/
	char *dir = get_dir(_data_);
	char *_buff_ = allocate_buf(dir);

	if (!_buff_)
	{
		/* Return NULL if buffer allocation fails */
		return (NULL);
	}
	_str_cpy(_buff_, dir);
	_str_catt_(_buff_, "/");
	_str_catt_(_buff_, HIST_FILE);
	/* Return the history file or NULL if not found */
	return (_buff_);
}

/**
 * open_file - This function opens a file.
 * @filename: The name of the file to open.
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
 * @_nde_: The list _nde_ containing the strings to write.
 * @_fl_dir_: The file descriptor.
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


