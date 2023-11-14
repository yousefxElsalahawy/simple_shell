





#include "shell.h"

/**
 * reset_buffer - This function resets the _obuf_fer_
 * @_data_: This pointer refers to the _data_ struct
 * @_bbuuff_: This pointer refers to the _obuf_fer_
 *
 * Return: Nothing (void function)
 */
void reset_buffer(__attribute__((unused)) _info_OK *_data_, char **_bbuuff_)
{
    /* Use if statement */
    if (*_bbuuff_)
    {
        free(*_bbuuff_);
        *_bbuuff_ = NULL;
    }
    signal(SIGINT, sgn_Her_);
}

/**
 * input_reader - This function reads input
 * @_data_: This pointer refers to the _data_ struct
 * @_bbuuff_: This pointer refers to the _obuf_fer_
 * @_len_op_: This pointer refers to the _olent_
 *
 * Return: Number of bytes read
 */
ssize_t input_reader(_info_OK *_data_, char **_bbuuff_, size_t *_len_op_)
{
    ssize_t _oorr = 0;

    /* Use conditional compilation */
#if _USE_GETLINE_
    _oorr = getline(_bbuuff_, _len_op_, stdin);
#else
    _oorr = _gt_lne_(_data_, _bbuuff_, _len_op_);
#endif

    /* Return the number of bytes read */
    return (_oorr);
}

/**
 * input_processor - This function processes input
 * @_data_: This pointer refers to the _data_ struct
 * @_bbuuff_: This pointer refers to the _obuf_fer_
 * @_oorr: This pointer refers to the _olent_
 *
 * Return: Nothing (void function)
 */
void input_processor(_info_OK *_data_, char **_bbuuff_, ssize_t *_oorr)
{
    /* Use if statement */
    (*_bbuuff_)[*_oorr - 1] == '\n' ? (*_bbuuff_)[--(*_oorr)] = '\0' : 0;

    _data_->_flag_mycount_ = 1;
    _rmove_com_(*_bbuuff_);
    _buld_hstry_lst_(_data_, *_bbuuff_, _data_->_my_tcount_++);
}

/**
 * command_chain_hdlr - This function hdls command chains
 * @_data_: This pointer refers to the _data_ struct
 * @_bbuuff_: This pointer refers to the _obuf_fer_
 * @_len_: This pointer refers to the _olent_
 * @_oorr: This pointer refers to the _olent_
 *
 * Return: Nothing (void function)
 */
void command_chain_hdlr(_info_OK *_data_, char **_bbuuff_, size_t *_len_, ssize_t _oorr)
{
    *_len_ = _oorr;
    _data_->_cmdd_buff_ = _bbuuff_;
}

/**
 * input_buf - This function hdls input buffers
 * @_data_: This pointer refers to the _data_ struct
 * @_bbuuff_: This pointer refers to the _obuf_fer_
 * @_len_: This pointer refers to the _olent_
 *
 * Return: Number of bytes read
 */
ssize_t input_buf(_info_OK *_data_, char **_bbuuff_, size_t *_len_)
{
    ssize_t _oorr = 0;
    size_t _len_op_ = 0;

    /* Use if statement */
    if (!*_len_)
    {
        reset_buffer(_data_, _bbuuff_);
        _oorr = input_reader(_data_, _bbuuff_, &_len_op_);
        if (_oorr > 0)
        {
            input_processor(_data_, _bbuuff_, &_oorr);
            command_chain_hdlr(_data_, _bbuuff_, _len_, _oorr);
        }
    }
    /* Return the number of bytes read */
    return (_oorr);
}

/**
 * hdl_input - This function hdls input
 * @_data_: This pointer refers to the _data_ struct
 * @_bbuuff_: This pointer refers to the _obuf_fer_
 * @_len_: This pointer refers to the _olent_
 *
 * Return: Number of bytes read or -1 if error
 */
ssize_t hdl_input(_info_OK *_data_, char **_bbuuff_, size_t *_len_)
{
    ssize_t _oorr;

    _pputt_char(_BUFFER_FLUSH);

    _oorr = input_buf(_data_, _bbuuff_, _len_);

    /* Return the number of bytes read or -1 if error */
    return ((_oorr == -1) ? -1 : _oorr);
}

/**
 * init_iterator - This function initializes the iterator
 * @_oops_: This pointer refers to the _osize_
 * @j: This pointer refers to the _osize_
 * @_bbuuff_: This pointer refers to the _obuf_fer_
 * @_oqo_: This pointer refers to the pointer
 *
 * Return: Nothing (void function)
 */
void init_iterator(size_t *_oops_, size_t *j, char *_bbuuff_, char **_oqo_)
{
    *j = *_oops_; /* init _nww_ iterator to current _bbuuff_ position */
    *_oqo_ = _bbuuff_ + *_oops_; /* get pointer for return */
}

/**
 * iterate_to_semicolon_or_end - This function iterates to semicolon or _End
 * @_data_: This pointer refers to the _data_ struct
 * @_bbuuff_: This pointer refers to the _obuf_fer_
 * @j: This pointer refers to the _osize_
 * @_len_: This pointer refers to the _olent_
 *
 * Return: Nothing (void function)
 */
void iterate_to_semicolon_or_end(_info_OK *_data_, char *_bbuuff_, size_t *j, size_t _len_)
{
    /*use loop */
    do {
        if (_s_chn_(_data_, _bbuuff_, j))
            break;
        (*j)++;
    } while (*j < _len_); /* iterate to semicolon or _End */
}

/**
 * hdl_chain - This function hdls chains
 * @_data_: This pointer refers to the _data_ struct
 * @_bbuuff_: This pointer refers to the _obuf_fer_
 * @_oops_: This pointer refers to the _osize_
 * @j: This pointer refers to the _osize_
 * @_len_: This pointer refers to the _olent_
 * @_oqo_: This pointer refers to the pointer
 *
 * Return: Nothing (void function)
 */
void hdl_chain(_info_OK *_data_, char *_bbuuff_, size_t *_oops_, size_t *j, size_t _len_, char **_oqo_)
{
    init_iterator(_oops_, j, _bbuuff_, _oqo_);
    chk_chain(_data_, _bbuuff_, j, *_oops_, _len_);
    iterate_to_semicolon_or_end(_data_, _bbuuff_, j, _len_);
}

/**
 * _RESet_BuFFer_ - This function resets the _obuf_fer_
 * @_data_: This pointer refers to the _data_ struct
 * @_oops_: This pointer refers to the _osize_
 * @_len_: This pointer refers to the _olent_
 *
 * Return: Nothing (void function)
 */
void _RESet_BuFFer_(_info_OK *_data_, size_t *_oops_, size_t *_len_)
{
    *_oops_ = *_len_ = 0; /* reset position and _olent_ */
    _data_->_cmdd_buff_shape_ = _CMDD_NORMAL_;
}

/**
 * gt_userinpt_ - This function gets input
 * @_data_: This pointer refers to the _data_ struct
 *
 * Return: _olent_ of current command or -1 if error
 */
ssize_t gt_userinpt_(_info_OK *_data_)
{
    static char *_bbuuff_; /* the ';' command chain _obuf_fer_ */
    static size_t _oops_, j, _len_;
    char **buf_p = &(_data_->_argu_), *_oqo_;

    ssize_t _oorr = hdl_input(_data_, &_bbuuff_, &_len_);

    if (_oorr == -1)
		/* Return -1 if error */
		return (-1);

    if (_len_)	/* we have commands left in the chain _obuf_fer_ */
    {
        hdl_chain(_data_, _bbuuff_, &_oops_, &j, _len_, &_oqo_);

        _oops_ = j + 1; /* increment past nulled ';'' */
        if (_oops_ >= _len_) /* reached _End of _obuf_fer_? */
            _RESet_BuFFer_(_data_, &_oops_, &_len_);

        *buf_p = _oqo_;
		/* pass back pointer to current command position */

        /* Return _olent_ of current command */
        return (_str_len_(_oqo_)); 
    }

    *buf_p = _bbuuff_; /* else not a chain, pass back
	_obuf_fer_ from _gt_lne_() */
    /* Return _olent_ of _obuf_fer_ from _gt_lne_() */
    return (_oorr); 
}

/**
 * _red_buff_ - reads a _obuf_fer_
 * @_data_: parameter struct
 * @_bbuuff_: _obuf_fer_
 * @_oops_: _osize_
 *
 * Return: _oorr
 */
ssize_t read_from_fd(_info_OK *_data_, char *_bbuuff_)
{
	ssize_t _oorr;

	_oorr = read(_data_->_read_fd_, _bbuuff_, _SIZE_BUFF_READ);
	/* Return the number of bytes read or -1 if error */
	return ((_oorr >= 0) ? _oorr : -1);
}

ssize_t _red_buff_(_info_OK *_data_, char *_bbuuff_, size_t *_oops_)
{
	ssize_t _oorr = 0;

	/* Use if statement */
	if (!*_oops_)
	{
		_oorr = read_from_fd(_data_, _bbuuff_);
		*_oops_ = (_oorr >= 0) ? _oorr : 0;
	}

	/* Return the number of bytes read or -1 if error */
	return (_oorr);
}

/**
 * _gt_lne_ - gets the _nxt_ line of input from STDIN
 * @_data_: parameter struct
 * @_pttr_: address of pointer to _obuf_fer_, preallocated or NULL
 * @_olent_: _osize_ of preallocated _pttr_ _obuf_fer_ if not NULL
 *
 * Return: _aso_
 */
ssize_t buffer_reader(_info_OK *_data_, char *_bbuuff_, size_t *_len_)
{
	ssize_t _oorr = 0;

	/* Use if statement */
	if (!*_len_)
	{
		_oorr = read(_data_->_read_fd_, _bbuuff_, _SIZE_BUFF_READ);
		*_len_ = (_oorr >= 0) ? _oorr : 0;
	}

	/* Return the number of bytes read or -1 if error */
	return (_oorr);
}

char *locate_newline(char *_bbuuff_, size_t _oops_)
{
	/* Return the position of the newline character or NULL if not found */
	return (_str_n_chr(_bbuuff_ + _oops_, '\n'));
}

char *memory_allocator(char *_oqo_, size_t _aso_, size_t _kok_)
{
	char *new_p;

	new_p = _rea_lloc_(_oqo_, _aso_, _aso_ ? _aso_ + _kok_ : _kok_ + 1	);

	if (!new_p) /* MALLOC FAILURE! */
	{
		if (_oqo_)
			free(_oqo_);
		/* Return NULL if memory allocation fails */
		return (NULL);
	}
	/* Return the newly allocated memory */
	return (new_p);
}

/**
 * buffer_copier - This function copies the _obuf_fer_
 * @new_p: This pointer refers to the _nww_ _obuf_fer_
 * @_bbuuff_: This pointer refers to the _obuf_fer_
 * @_oops_: This pointer refers to the _osize_
 * @_kok_: This pointer refers to the _osize_
 * @_aso_: This pointer refers to the _osize_
 *
 * Return: Nothing (void function)
 */
void buffer_copier(char *new_p, char *_bbuuff_, size_t _oops_, size_t _kok_, size_t _aso_)
{
	/*use if*/

	_aso_ ? _str_n_cat(new_p, _bbuuff_ + _oops_, _kok_ - _oops_) : _strr_ncpy_(new_p, _bbuuff_ + _oops_, _kok_ - _oops_ + 1);
}

/**
 * _gt_lne_ - This function gets the _nxt_ line of input from STDIN
 * @_data_: parameter struct
 * @_pttr_: address of pointer to _obuf_fer_, preallocated or NULL
 * @_olent_: _osize_ of preallocated _pttr_ _obuf_fer_ if not NULL
 *
 * Return: _aso_
 */
int _gt_lne_(_info_OK *_data_, char **_pttr_, size_t *_olent_)
{
	/*decleration*/
	ssize_t _oorr = 0, _aso_ = 0;
	char *_oqo_ = NULL, *new_p = NULL, *_coco_c;
	size_t _kok_;
	static char _bbuuff_[_SIZE_BUFF_READ];
	static size_t _oops_, _len_;

	_oqo_ = *_pttr_;

	if (_oqo_ && _olent_)
		_aso_ = *_olent_;

	if (_oops_ == _len_)
		_oops_ = _len_ = 0;

	_oorr = buffer_reader(_data_, _bbuuff_, &_len_);
	if (_oorr == -1 || (_oorr == 0 && _len_ == 0))
		/* Return -1 if error */
		return (-1);

	_coco_c = locate_newline(_bbuuff_, _oops_);
	_kok_ = _coco_c ? 1 + (unsigned int)(_coco_c - _bbuuff_) : _len_;
	new_p = memory_allocator(_oqo_, _aso_, _kok_);

	if (!new_p)
		/* Return -1 if memory allocation fails */
		return (-1);

	buffer_copier(new_p, _bbuuff_, _oops_, _kok_, _aso_);

	_aso_ += _kok_ - _oops_;
	_oops_ = _kok_;
	_oqo_ = new_p;

	if (_olent_)
		*_olent_ = _aso_;

	*_pttr_ = _oqo_;
	/* Return the _osize_ of the _nww_ line */
	return (_aso_);
}

/**
 * sgn_Her_ - blocks ctrl-_coco_c
 * @_sig_nmm_: the signal number
 *
 * Return: void
 */
void sgn_Her_(__attribute__((unused))int _sig_nmm_)
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
	_pputt_char(_BUFFER_FLUSH);
}


