

#include "shell.h"

/**
 * _ck_pth - This function chks if a _my_pth_ is valid
 * @_my_pth_: This pointer refers to the _my_pth_ to be chked
 * @_qst_: This pointer refers to the stat struct
 *
 * Return: 1 if the _my_pth_ is valid, 0 otherwise
 */
int _ck_pth(char *_my_pth_, struct stat *_qst_)
{
    int _rultt_ = (!_my_pth_ || stat(_my_pth_, _qst_)) ? 0 : 1;
    /* This function returns the _rultt_ of the _my_pth_ chk */
    return (_rultt_);
}

/**
 * chk_file_mode - This function chks if a file is regular
 * @_qst_: This pointer refers to the stat struct
 *
 * Return: 1 if the file is regular, 0 otherwise
 */
int chk_file_mode(struct stat *_qst_)
{
    int _rultt_;

    /* use if */
    if (_qst_->st_mode & S_IFREG)
        _rultt_ = 1;
    else
        _rultt_ = 0;

    /* This function returns the _rultt_ of the file mode chk */
    return (_rultt_);
}

/**
 * _my_i_cmdd_ - This function chks if a _my_pth_ is a command
 * @_data_: This pointer refers to the _data_ struct
 * @_my_pth_: This pointer refers to the _my_pth_ to be chked
 *
 * Return: 1 if the _my_pth_ is a command, 0 otherwise
 */
int _my_i_cmdd_(_info_OK *_data_, char *_my_pth_)
{
    struct stat _qst_;
    int pth_chk, mode_chk;

    (void)_data_;
    pth_chk = _ck_pth(_my_pth_, &_qst_);
    /* use if */
    if (pth_chk == 0)
        mode_chk = 0;
    else
        mode_chk = chk_file_mode(&_qst_);

    /* This function returns the _rultt_ of the command chk */
    return (mode_chk);
}

/**
 * _COpYY_cHaRS_ - This function copies characters from one
 * string to another
 * @pthstr: This pointer refers to the source string
 * @_sstrtt_: This variable is the starting _indx_ for copying
 * @_sososo: This variable is the stopping _indx_ for copying
 * @_bbuuff_: This pointer refers to the destination string
 *
 * Return: Pointer to the destination string
 */
char *_COpYY_cHaRS_(char *pthstr, int _sstrtt_, int _sososo, char *_bbuuff_)
{
    int _indx_ = _sstrtt_, buffer_index = 0;

    /* use loop */
    do {
        /* use if */
        if (pthstr[_indx_] != ':') {
            _bbuuff_[buffer_index] = pthstr[_indx_];
            buffer_index++;
        }
        _indx_++;
    } while (_indx_ < _sososo);

    _bbuuff_[buffer_index] = '\0';
    /* This function returns a pointer to the destination string */
    return (_bbuuff_);
}

/**
 * _dupp_chart_ - This function duplicates characters from
 * one string to another
 * @pthstr: This pointer refers to the source string
 * @_sstrtt_: This variable is the starting _indx_ for copying
 * @_sososo: This variable is the stopping _indx_ for copying
 *
 * Return: Pointer to the destination string
 */
char *_dupp_chart_(char *pthstr, int _sstrtt_, int _sososo)
{
    static char _obuf_fer_[1024];

    /* This function returns a pointer to the destination string */
    return (_COpYY_cHaRS_(pthstr, _sstrtt_, _sososo, _obuf_fer_));
}

/**
 * chk_cmd - This function chks if a command is valid
 * @_data_: This pointer refers to the _data_ struct
 * @_ccmmdd_: This pointer refers to the command to be chked
 *
 * Return: Pointer to the command if it is valid, NULL otherwise
 */
char *chk_cmd(_info_OK *_data_, char *_ccmmdd_)
{
    /* This function returns a pointer to the command if it is valid */
    return (((_str_len_(_ccmmdd_) > 2) && _start_wh_(_ccmmdd_, "./") && _my_i_cmdd_(_data_, _ccmmdd_)) ? _ccmmdd_ : NULL);
}

/**
 * build_pth - This function builds a _my_pth_ from a base
 * my_pth_ and a command
 * @_my_pth_: This pointer refers to the base _my_pth_
 * @_ccmmdd_: This pointer refers to the command
 *
 * Return: Pointer to the built _my_pth_
 */
char *build_pth(char *_my_pth_, char *_ccmmdd_)
{
    /* use if */
    if (!*_my_pth_)
        _str_catt_(_my_pth_, _ccmmdd_);
    else {
        _str_catt_(_my_pth_, "/");
        _str_catt_(_my_pth_, _ccmmdd_);
    }
    /* This function returns a pointer to the built _my_pth_ */
    return (_my_pth_);
}

/**
 * find_cmd_in_pth - This function finds a command in a _my_pth_
 * @_data_: This pointer refers to the _data_ struct
 * @pthstr: This pointer refers to the _my_pth_ string
 * @_ccmmdd_: This pointer refers to the command to be found
 * @_oops_: This variable is the current _indx_ in the _my_pth_ string
 * @curr_pos: This variable is the current position in the _my_pth_ string
 *
 * Return: Pointer to the command if it is found, NULL otherwise
 */
char *find_cmd_in_pth(_info_OK *_data_, char *pthstr, char *_ccmmdd_, int _oops_, int curr_pos)
{
    char *_my_pth_;

    /* use loop */
    do {
        /* use if */
        if (!pthstr[_oops_] || pthstr[_oops_] == ':') {
            _my_pth_ = _dupp_chart_(pthstr, curr_pos, _oops_);
            _my_pth_ = build_pth(_my_pth_, _ccmmdd_);
            if (_my_i_cmdd_(_data_, _my_pth_))
                /* This function returns a pointer to thecommand if it is found */
                return (_my_pth_);
            curr_pos = _oops_;
        }
        _oops_++;
    } while (pthstr[_oops_]);
    /* This function returns NULL if the command is not found */
    return (NULL);
}

/**
 * _fnd_pth_ - This function finds a _my_pth_ for a command
 * @_data_: This pointer refers to the _data_ struct
 * @pthstr: This pointer refers to the _my_pth_ string
 * @_ccmmdd_: This pointer refers to the command to find the _my_pth_ for
 *
 * Return: Pointer to the _my_pth_ if it is found, NULL otherwise
 */
char *_fnd_pth_(_info_OK *_data_, char *pthstr, char *_ccmmdd_)
{
    int _oops_ = 0, curr_pos = 0;
    char *_my_pth_ = chk_cmd(_data_, _ccmmdd_);

    /* This function returns a pointer to the _my_pth_ if it is found */
    return ((_my_pth_) ? _my_pth_ : (pthstr ? find_cmd_in_pth(_data_, pthstr, _ccmmdd_, _oops_, curr_pos) : NULL));
}


