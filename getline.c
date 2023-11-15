





#include "shell.h"

/**
 * reset_buffer - This function resets the buffer
 * @_data_: This pointer refers to the _data_ struct
 * @_buff_: This pointer refers to the buffer
 *
 * Return: Nothing (void function)
 */
void reset_buffer(__attribute__((unused)) info_t *_data_, char **_buff_)
{
	/* Use if statement */
	if (*_buff_)
	{
		free(*_buff_);
		*_buff_ = NULL;
	}
	signal(SIGINT, sgn_Her_);
}

/**
 * input_reader - This function reads input
 * @_data_: This pointer refers to the _data_ struct
 * @_buff_: This pointer refers to the buffer
 * @len_p: This pointer refers to the length
 *
 * Return: Number of bytes read
 */
ssize_t input_reader(info_t *_data_, char **_buff_, size_t *len_p)
{
	ssize_t r = 0;

	/* Use conditional compilation */
#if USE_GETLINE
	r = getline(_buff_, len_p, stdin);
#else
	r = _gt_lne_(_data_, _buff_, len_p);
#endif

	/* Return the number of bytes read */
	return (r);
}

/**
 * input_processor - This function processes input
 * @_data_: This pointer refers to the _data_ struct
 * @_buff_: This pointer refers to the buffer
 * @r: This pointer refers to the length
 *
 * Return: Nothing (void function)
 */
void input_processor(info_t *_data_, char **_buff_, ssize_t *r)
{
	/* Use if statement */
	(*_buff_)[*r - 1] == '\n' ? (*_buff_)[--(*r)] = '\0' : 0;

	_data_->linecount_flag = 1;
	_rmove_com_(*_buff_);
	_buld_hstry_lst_(_data_, *_buff_, _data_->histcount++);
}

/**
 * command_chain_hdlr - This function hdls command chains
 * @_data_: This pointer refers to the _data_ struct
 * @_buff_: This pointer refers to the buffer
 * @_long_: This pointer refers to the length
 * @r: This pointer refers to the length
 *
 * Return: Nothing (void function)
 */
void command_chain_hdlr(info_t *_data_, char **_buff_,
		size_t *_long_, ssize_t r)
{
	*_long_ = r;
	_data_->cmd_buf = _buff_;
}

/**
 * input_buf - This function hdls input buffers
 * @_data_: This pointer refers to the _data_ struct
 * @_buff_: This pointer refers to the buffer
 * @_long_: This pointer refers to the length
 *
 * Return: Number of bytes read
 */
ssize_t input_buf(info_t *_data_, char **_buff_, size_t *_long_)
{
	ssize_t r = 0;
	size_t len_p = 0;

	/* Use if statement */
	if (!*_long_)
	{
		reset_buffer(_data_, _buff_);
		r = input_reader(_data_, _buff_, &len_p);
		if (r > 0)
		{
			input_processor(_data_, _buff_, &r);
			command_chain_hdlr(_data_, _buff_, _long_, r);
		}
	}
	/* Return the number of bytes read */
	return (r);
}

/**
 * hdl_input - This function hdls input
 * @_data_: This pointer refers to the _data_ struct
 * @_buff_: This pointer refers to the buffer
 * @_long_: This pointer refers to the length
 *
 * Return: Number of bytes read or -1 if error
 */
ssize_t hdl_input(info_t *_data_, char **_buff_, size_t *_long_)
{
	ssize_t r;

	_pputt_char(BUF_FLUSH);

	r = input_buf(_data_, _buff_, _long_);

	/* Return the number of bytes read or -1 if error */
	return ((r == -1) ? -1 : r);
}

/**
 * init_iterator - This function initializes the iterator
 * @_OK_: This pointer refers to the size
 * @_go_: This pointer refers to the size
 * @_buff_: This pointer refers to the buffer
 * @_oops_: This pointer refers to the pointer
 *
 * Return: Nothing (void function)
 */
void init_iterator(size_t *_OK_, size_t *_go_, char *_buff_, char **_oops_)
{
	*_go_ = *_OK_; /* init new iterator to current _buff_ position */
	*_oops_ = _buff_ + *_OK_; /* get pointer for return */
}

/**
 * iterate_to_semicolon_or_end - This function iterates to semicolon or end
 * @_data_: This pointer refers to the _data_ struct
 * @_buff_: This pointer refers to the buffer
 * @_go_: This pointer refers to the size
 * @_long_: This pointer refers to the length
 *
 * Return: Nothing (void function)
 */
void iterate_to_semicolon_or_end(info_t *_data_,
		char *_buff_, size_t *_go_, size_t _long_)
{
	/*use loop */
	do {
		if (_s_chn_(_data_, _buff_, _go_))
			break;
		(*_go_)++;
	} while (*_go_ < _long_); /* iterate to semicolon or end */
}

/**
 * hdl_chain - This function hdls chains
 * @_data_: This pointer refers to the _data_ struct
 * @_buff_: This pointer refers to the buffer
 * @_OK_: This pointer refers to the size
 * @_go_: This pointer refers to the size
 * @_long_: This pointer refers to the length
 * @_oops_: This pointer refers to the pointer
 *
 * Return: Nothing (void function)
 */
void hdl_chain(info_t *_data_, char *_buff_,
		size_t *_OK_, size_t *_go_, size_t _long_, char **_oops_)
{
	init_iterator(_OK_, _go_, _buff_, _oops_);
	chk_chain(_data_, _buff_, _go_, *_OK_, _long_);
	iterate_to_semicolon_or_end(_data_, _buff_, _go_, _long_);
}

/**
 * _RESet_BuFFer_ - This function resets the buffer
 * @_data_: This pointer refers to the _data_ struct
 * @_OK_: This pointer refers to the size
 * @_long_: This pointer refers to the length
 *
 * Return: Nothing (void function)
 */
void _RESet_BuFFer_(info_t *_data_, size_t *_OK_, size_t *_long_)
{
	*_OK_ = *_long_ = 0; /* reset position and length */
	_data_->cmd_buf_type = CMD_NORM;
}

/**
 * gt_userinpt_ - This function gets input
 * @_data_: This pointer refers to the _data_ struct
 *
 * Return: Length of current command or -1 if error
 */
ssize_t gt_userinpt_(info_t *_data_)
{
	static char *_buff_; /* the ';' command chain buffer */
	char **buf_p = &(_data_->arg), *_oops_;
	static size_t _OK_, _go_, _long_;
	ssize_t r = hdl_input(_data_, &_buff_, &_long_);


	if (r == -1)
	{
		/* Return -1 if error */
		return (-1);
	}
	if (_long_)
	{
		/* we have commands left in the chain buffer */
		hdl_chain(_data_, _buff_, &_OK_, &_go_, _long_, &_oops_);

		_OK_ = _go_ + 1;
		/* increment past nulled ';'' */
		if (_long_ >= _OK_)
		{
			/* reached end of buffer? */
			_RESet_BuFFer_(_data_, &_OK_, &_long_);
		}
		*buf_p = _oops_;
		/* pass back pointer to current command position */

		/* Return length of current command */
		return (_str_len_(_oops_));
	}

	*buf_p = _buff_; /* else not a chain, pass back buffer from _gt_lne_() */
	/* Return length of buffer from _gt_lne_() */
	return (r);
}

/**
 * _rd_buff_ - reads a buffer
 * @_data_: parameter struct
 * @_buff_: buffer
 * @_OK_: size
 *
 * Return: r
 */
ssize_t read_from_fd(info_t *_data_, char *_buff_)
{
	ssize_t r;

	r = read(_data_->readfd, _buff_, READ_BUF_SIZE);
	/* Return the number of bytes read or -1 if error */
	return ((r >= 0) ? r : -1);
}

ssize_t _rd_buff_(info_t *_data_, char *_buff_, size_t *_OK_)
{
	ssize_t r = 0;

	/* Use if statement */
	if (!*_OK_)
	{
		r = read_from_fd(_data_, _buff_);
		*_OK_ = (r >= 0) ? r : 0;
	}

	/* Return the number of bytes read or -1 if error */
	return (r);
}

/**
 * _gt_lne_ - gets the _nxt_ line of input from STDIN
 * @_data_: parameter struct
 * @_pttr_: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated _pttr_ buffer if not NULL
 *
 * Return: _letter_
 */
ssize_t buffer_reader(info_t *_data_, char *_buff_, size_t *_long_)
{
	ssize_t r = 0;

	/* Use if statement */
	if (!*_long_)
	{
		r = read(_data_->readfd, _buff_, READ_BUF_SIZE);
		*_long_ = (r >= 0) ? r : 0;
	}

	/* Return the number of bytes read or -1 if error */
	return (r);
}

char *locate_newline(char *_buff_, size_t _OK_)
{
	/* Return the position of the newline character or NULL if not found */
	return (_str_n_chr(_buff_ + _OK_, '\n'));
}

char *memory_allocator(char *_oops_, size_t _letter_, size_t _koK_)
{
	char *new_p;

	new_p = _rea_lloc_(_oops_, _letter_, _letter_ ?
			_letter_ + _koK_ : _koK_ + 1);

	if (!new_p) /* MALLOC FAILURE! */
	{
		if (_oops_)
			free(_oops_);
		/* Return NULL if memory allocation fails */
		return (NULL);
	}
	/* Return the newly allocated memory */
	return (new_p);
}

/**
 * buffer_copier - This function copies the buffer
 * @new_p: This pointer refers to the new buffer
 * @_buff_: This pointer refers to the buffer
 * @_OK_: This pointer refers to the size
 * @_koK_: This pointer refers to the size
 * @_letter_: This pointer refers to the size
 *
 * Return: Nothing (void function)
 */
void buffer_copier(char *new_p, char *_buff_,
		size_t _OK_, size_t _koK_, size_t _letter_)
{
	/*use if*/

	_letter_ ? _str_n_cat(new_p, _buff_ + _OK_, _koK_ - _OK_) :
		_strr_ncpy_(new_p, _buff_ + _OK_, _koK_ - _OK_ + 1);
}

/**
 * _gt_lne_ - This function gets the _nxt_ line of input from STDIN
 * @_data_: parameter struct
 * @_pttr_: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated _pttr_ buffer if not NULL
 *
 * Return: _letter_
 */
int _gt_lne_(info_t *_data_, char **_pttr_, size_t *length)
{
	/*decleration*/
	size_t _koK_;
	static size_t _OK_, _long_;
	ssize_t r = 0, _letter_ = 0;
	char *_oops_ = NULL, *new_p = NULL, *_coco_;
	static char _buff_[READ_BUF_SIZE];

	_oops_ = *_pttr_;

	if (_oops_ && length)
		_letter_ = *length;

	if (_long_ == _OK_)
		_OK_ = _long_ = 0;

	r = buffer_reader(_data_, _buff_, &_long_);
	if (r == -1 || (r == 0 && _long_ == 0))
		/* Return -1 if error */
		return (-1);

	_coco_ = locate_newline(_buff_, _OK_);
	_koK_ = _coco_ ? 1 + (unsigned int)(_coco_ - _buff_) : _long_;
	new_p = memory_allocator(_oops_, _letter_, _koK_);

	if (!new_p)
		/* Return -1 if memory allocation fails */
		return (-1);

	buffer_copier(new_p, _buff_, _OK_, _koK_, _letter_);

	_letter_ += _koK_ - _OK_;
	_OK_ = _koK_;
	_oops_ = new_p;

	if (length)
		*length = _letter_;

	*_pttr_ = _oops_;
	/* Return the size of the new line */
	return (_letter_);
}

/**
 * sgn_Her_ - blocks ctrl-_coco_
 * @sig_num: the signal number
 *
 * Return: void
 */
void sgn_Her_(__attribute__((unused))int sig_num)
{
	/*decleration*/
	char *output = "\n$ ";

	if (output)
	{
		do {
			_pputt_char(*output == '\n' ? '\n' : *output == '$' ? '$' : ' ');
			output++;
		} while (*output);
	}
	_pputt_char(BUF_FLUSH);
}


