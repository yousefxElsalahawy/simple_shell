

#include "shell.h"


/**
 * chk_operator - Checks if current char in _obuf_fer_ is a chain delimeter
 * @_data_: This pointer refers to the parameter struct
 * @_bbuuff_: This pointer refers to the char _obuf_fer_
 * @j: This variable refers to the current position in _bbuuff_
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int chk_operator(_info_OK *_data_, char *_bbuuff_, size_t *j)
{
    /* Declaration */
    if (!_bbuuff_)
        return (0);

    /* Use switch */
    switch (_bbuuff_[*j])
    {
        case '|':
            /* Check for logical OR operator */
            if (_bbuuff_[*j + 1] == '|')
            {
                _bbuuff_[*j] = 0;
                (*j)++;
                _data_->_cmdd_buff_shape_ = _CMDD_OR_;

                return (1); /* Returns 1 if logical OR operator is found */
            }
            break;
        case '&':
            /* Check for logical AND operator */
            if (_bbuuff_[*j + 1] == '&')
            {
                _bbuuff_[*j] = 0;
                (*j)++;
                _data_->_cmdd_buff_shape_ = _CMDD_ANDD_;
                return (1); /* Returns 1 if logical AND operator is found */
            }
            break;
        case ';':
            /* Check for command chain operator */
            _bbuuff_[*j] = 0;
            _data_->_cmdd_buff_shape_ = _CMDD_CHN_;
            return (1); /* Returns 1 if command chain operator is found */
        default:
            break;
    }
    return (0); /* Returns 0 if no operator is found */
}

/**
 * _s_chn_ - Checks if the position has changed, indicating an operator was found
 * @_data_: This pointer refers to the parameter struct
 * @_bbuuff_: This pointer refers to the char _obuf_fer_
 * @_oqo_: This variable refers to the current position in _bbuuff_
 *
 * Return: 1 if position has changed, 0 otherwise
 */
int _s_chn_(_info_OK *_data_, char *_bbuuff_, size_t *_oqo_)
{
    /* Declaration */
    size_t j;

    j = *_oqo_;

    /* Use loop */
    *_oqo_ = j + chk_operator(_data_, _bbuuff_, &j);

    /* Use if */
    return ((*_oqo_ > j) ? 1 : 0);
    /* Returns 1 if position has changed, 0 otherwise */
}

/**
 * chk_condition - Checks the condition of the command _obuf_fer_ _style
 * @_data_: This pointer refers to the parameter struct
 *
 * Return: 1 if condition is met, 0 otherwise
 */
int chk_condition(_info_OK *_data_)
{
    return ((_data_->_cmdd_buff_shape_ == _CMDD_ANDD_ && _data_->_cmdd_status_) ||
            (_data_->_cmdd_buff_shape_ == _CMDD_OR_ && !_data_->_cmdd_status_)); /* Returns 1 if condition is met, 0 otherwise */
}

/**
 * _upd_buffer_and_index -this Updates the _obuf_fer_ and _indx_ based on the condition
 * @_data_: This pointer refers to the parameter struct
 * @_bbuuff_: This pointer refers to the char _obuf_fer_
 * @_indx_: This variable refers to the current position in _bbuuff_
 * @_len_: This variable refers to the _olent_ of the _obuf_fer_
 *
 * Return: Nothing (void function)
 */
void _upd_buffer_and_index(_info_OK *_data_, char *_bbuuff_,
        size_t *_indx_, size_t _len_)
{
    /* Declaration */
    int condition = chk_condition(_data_);

    /* Use if */
    _bbuuff_[*_indx_] = condition ? 0 : _bbuuff_[*_indx_];

    /* Use loop */
    *_indx_ = condition ? _len_ : *_indx_;
}

/**
 * chk_chain - Checks the chain and updates the _obuf_fer_ and _indx_
 * @_data_: This pointer refers to the parameter struct
 * @_bbuuff_: This pointer refers to the char _obuf_fer_
 * @_oqo_: This variable refers to the current position in _bbuuff_
 * @_oops_: This variable is unused
 * @_len_: This variable refers to the _olent_ of the _obuf_fer_
 *
 * Return: Nothing (void function)
 */
void chk_chain(_info_OK *_data_, char *_bbuuff_,
        size_t *_oqo_, __attribute__((unused)) size_t _oops_, size_t _len_)
{
    /* Declaration */
    size_t j = *_oqo_;

    /* Call the function to update the _obuf_fer_ and _indx_ */
    _upd_buffer_and_index(_data_, _bbuuff_, &j, _len_);

    /* Use loop */
    *_oqo_ = j;
}














/*****************************************/
/**
 * _gett_ndd_ - Retrieves a _nddee_ from the _alias_nd_ list
 * @_data_: This pointer refers to the parameter struct
 *
 * Return: _nddee_ if found, NULL otherwise
 */
_lst_ *_gett_ndd_(_info_OK *_data_)
{
    /* Use if */
    if (!_data_)
        return (NULL);

    return (_nde_strt_wth_(_data_->_alias_nd_, _data_->_arguv_[0], '=')); /* Returns _nddee_ if found, NULL otherwise */
}

/**
 * get_new_p - Retrieves a _nww_ pointer from the _nddee_
 * @_nddee_: This pointer refers to the _nddee_
 *
 * Return: _nww_ pointer if found, NULL otherwise
 */
char *get_new_p(_lst_ *_nddee_)
{
    /* Declaration */
    char *_oqo_;

    /* Use if */
    if (!_nddee_)
        return (NULL);

    _oqo_ = _str_n_chr(_nddee_->_txt_, '=');

    return (_oqo_ ? _str_dupp_(_oqo_ + 1) : NULL); /* Returns _nww_ pointer if found, NULL otherwise */
}

/**
 * _rplce_als_ - Replaces the _alias_nd_ in the _arguv_[0] with the _vlle_ from the _alias_nd_ list
 * @_data_: This pointer refers to the parameter struct
 *
 * Return: 1 if _alias_nd_ is replaced, 0 otherwise
 */
int _rplce_als_(_info_OK *_data_)
{
    /* Declaration */
    int _oops_ = 0;
    _lst_ *_nddee_;
    char *_oqo_;

    /* Use if */
    if (!_data_)
        return (0);

    /* Use loop */
    do {
        _nddee_ = _gett_ndd_(_data_);

        /* Use if */
        if (!_nddee_)
            return (0);

        _oqo_ = get_new_p(_nddee_);

        /* Use if */
        if (!_oqo_)
            return (0);
        free(_data_->_arguv_[0]);
        _data_->_arguv_[0] = _oqo_;
        _oops_++;
    } while (_oops_ < 10 && _data_->_arguv_[0] == NULL);

    return (_data_->_arguv_[0] != NULL); /* Returns 1 if _alias_nd_ is replaced, 0 otherwise */
}

/**
 * _chk_var_type - Checks the _style of the variable in _arguv_[_oops_]
 * @_data_: This pointer refers to the parameter struct
 * @_oops_: This variable refers to the _indx_ of _arguv_
 *
 * Return: 0 if not a variable, 1 if _cmdd_status_ variable, 2 if PID variable, 3 otherwise
 */
int _chk_var_type(_info_OK *_data_, int _oops_)
{
    /* Use if */
    if (_data_->_arguv_[_oops_][0] != '$' || !_data_->_arguv_[_oops_][1])
        return 0;
    else if (!_str_cmpp_(_data_->_arguv_[_oops_], "$?"))
        return 1;
    else if (!_str_cmpp_(_data_->_arguv_[_oops_], "$$"))
        return 2;
    else
        return 3; /* Returns 0 if not a variable, 1 if _cmdd_status_ variable, 2 if PID variable, 3 otherwise */
}

/**
 * _rep_str_with_value - Replaces the string in _arguv_[_oops_] with the _vlle_
 * @_data_: This pointer refers to the parameter struct
 * @_oops_: This variable refers to the _indx_ of _arguv_
 * @_vlle_: This variable refers to the _vlle_ to replace with
 *
 * Return: Nothing (void function)
 */
void _rep_str_with_value(_info_OK *_data_, int _oops_, int _vlle_)
{
    _rplce_str_(&(_data_->_arguv_[_oops_]), _str_dupp_(cnvrt_nmbr_(_vlle_, 10, 0)));
}

/**
 * _get_ndd_ - Retrieves a _nddee_ from the environment list
 * @_data_: This pointer refers to the parameter struct
 * @_oops_: This variable refers to the _indx_ of _arguv_
 *
 * Return: _nddee_ if found, NULL otherwise
 */
_lst_ *_get_ndd_(_info_OK *_data_, int _oops_)
{
    return _nde_strt_wth_(_data_->_my_env, &_data_->_arguv_[_oops_][1], '='); /* Returns _nddee_ if found, NULL otherwise */
}

/**
 * _rep_with_node_value - Replaces the string in _arguv_[_oops_] with the _vlle_ from the _nddee_
 * @_data_: This pointer refers to the parameter struct
 * @_oops_: This variable refers to the _indx_ of _arguv_
 * @_nddee_: This pointer refers to the _nddee_
 *
 * Return: Nothing (void function)
 */
void _rep_with_node_value(_info_OK *_data_, int _oops_, _lst_ *_nddee_)
{
    _rplce_str_(&(_data_->_arguv_[_oops_]), _str_dupp_(_str_n_chr(_nddee_->_txt_, '=') + 1));
}

/**
 * _rep_with_empty_str - Replaces the string in _arguv_[_oops_] with an empty string
 * @_data_: This pointer refers to the parameter struct
 * @_oops_: This variable refers to the _indx_ of _arguv_
 *
 * Return: Nothing (void function)
 */
void _rep_with_empty_str(_info_OK *_data_, int _oops_)
{
    _rplce_str_(&_data_->_arguv_[_oops_], _str_dupp_(""));
}


/**
 * rplce_vrs_ - Replaces the variables in _arguv_ with their corresponding values
 * @_data_: This pointer refers to the parameter struct
 *
 * Return: 0 (void function)
 */
int rplce_vrs_(_info_OK *_data_)
{
    /* Declaration */
    int _oops_ = 0;
    _lst_ *_nddee_;
    int var_type;

    /* Use loop */
    do {
        var_type = _chk_var_type(_data_, _oops_);

        /* Use switch */
        switch (var_type)
        {
        case 0:
            _oops_++;
            continue;
        case 1:
            _rep_str_with_value(_data_, _oops_, _data_->_cmdd_status_);
            break;
        case 2:
            if (kill(getpid(), 0) == 0)
			{
                _rep_str_with_value(_data_, _oops_, getpid());
            }
			else
			{
                _rep_with_empty_str(_data_, _oops_);
            }
            break;
        case 3:
            _nddee_ = _get_ndd_(_data_, _oops_);
            if (_nddee_)
                _rep_with_node_value(_data_, _oops_, _nddee_);
            else
                _rep_with_empty_str(_data_, _oops_);
            break;
        }
        _oops_++;
    } while (_data_->_arguv_[_oops_]);

    return (0); /* Returns 0 (void function) */
}

/**
 * _rplce_str_ - Replaces _aodd_ string with _nww_ string
 * @_aodd_: This pointer refers to the _aodd_ string
 * @_nww_: This pointer refers to the _nww_ string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int _rplce_str_(char **_aodd_, char *_nww_)
{
    /* Use if */
    if (_aodd_ == NULL || _nww_ == NULL)
    {
        _put_ss_("Error: Null pointer passed to _rplce_str_\n");
        return (0); /* Returns 0 if either _aodd_ or _nww_ is NULL */
    }
    if (*_aodd_ != _nww_)
    {
        free(*_aodd_);
        *_aodd_ = _nww_;
    }
    return (1); /* Returns 1 if replaced */
}



