



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








