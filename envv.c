





#include "shell.h"

/**
 * validate_inputs - This function validates the inputs
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: 0 (success), 1 (error)
 */
int validate_inputs(_info_OK *_data_)
{
    if (_data_ == NULL || _data_->_my_env == NULL)
    {
        puts("Error: This is Invalid inputs.");

        return (1); /* Return 1 if inputs are invalid */
    }
    return (0); /* Return 0 if inputs are valid */
}

/**
 * print_env - This function prints the environment
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: _rultt_ of the print operation
 */
int print_env(_info_OK *_data_)
{
    int _rultt_ = print_list_str(_data_->_my_env);

    if (_rultt_ != 0)
    {
        puts("Error: Failed to print Environment Variables.");
    }
    return _rultt_; /* Return the _rultt_ of the print operation */
}

/**
 * _mEnv - This function hdls the myenv command
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: 0 (success), 1 (error)
 */
int _mEnv(_info_OK *_data_)
{
	int printResult = print_env(_data_);
    int validationResult = validate_inputs(_data_);

    if (validationResult != 0)
        return validationResult; /* Return the _rultt_ of the validation */



    return (printResult == 0 ? 0 : 1); /* Return the _rultt_ of the print operation */
}




/**
 * strange_starts - This function chks if a string starts with a specific name
 * @current_ndd: This pointer refers to the current _nddee_ in the list
 * @name: This variable is used to specify the name to chk
 *
 * Return: pointer to the _sstrtt_ of the string if it starts with the name, NULL otherwise
 */
char *strange_starts(_lst_ *current_ndd, const char *name)
{
    char *_oqo_ = _start_wh_(current_ndd->_txt_, name);

    return ((_oqo_ && *_oqo_) ? _oqo_ : NULL); /* Return pointer to the _sstrtt_ of the string if it starts with the name, NULL otherwise */
}

/**
 * innovative_search - This function performs a search in the list
 * @_nddee_: This pointer refers to the _nddee_ in the list
 * @name: This variable is used to specify the name to search for
 *
 * Return: pointer to the found element, NULL if not found
 */
char *innovative_search(_lst_ *_nddee_, const char *name)
{
    char *_oqo_ = NULL;
    _lst_ *current_ndd = _nddee_;

    while (current_ndd != NULL) /*use loop */
    {
        _oqo_ = strange_starts(current_ndd, name);
        if (_oqo_)
            break;

        current_ndd = current_ndd->_nxt_;
    }

    return _oqo_; /* Return pointer to the found element, NULL if not found */
}

/**
 * _get_env_ - This function gets the environment variable
 * @_data_: This pointer refers to the _data_ Struct
 * @name: This variable is used to specify the name of the environment variable
 *
 * Return: pointer to the environment variable, NULL if not found
 */
char *_get_env_(_info_OK *_data_, const char *name)
{
    return ((_data_ != NULL && name != NULL) ?
            innovative_search(_data_->_my_env, name) : NULL); /* Return pointer to the environment variable, NULL if not found */
}




/**
 * validate_args - This function validates the arguments
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: 0 (success), 1 (error)
 */
int validate_args(_info_OK *_data_)
{
    const int expected_argc = 3;

    return ((_data_->_argu_c_ != expected_argc) ?
            (_ee_put_("This is Wrong Number of Arguments\n"), 1) : 0); /* Return 0 if the number of arguments is correct, 1 otherwise */
}

/**
 * _mSetenv - This function sets the environment variable
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: 0 (success), 1 (error)
 */
int _mSetenv(_info_OK *_data_)
{
    int validation = validate_args(_data_);

    if (validation)
        return (validation); /* Return the _rultt_ of the validation */

    return ((_set_ev_(_data_, _data_->_arguv_[1], _data_->_arguv_[2]) == 0) ? 0 : 1); /* Return 0 if the environment variable is set successfully, 1 otherwise */
}

/**
 * chk_argc - This function chks the number of arguments
 * @_data_: This pointer refers o the Itnfo Struct
 *
 * Return: 0 (success), 1 (error)
 */
int chk_argc(_info_OK *_data_)
{
    return ((_data_->_argu_c_ == 1) ? (_ee_put_("Too few arguments.\n"), 1) : 0); /* Return 0 if the number of arguments is correct, 1 otherwise */
}



/**
 * _mUnsetenv - This function unsets the environment variable
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: 0 (success), 1 (error)
 */
int _mUnsetenv(_info_OK *_data_)
{
    int validation = chk_argc(_data_);
    int _oops_;

    if (validation)
        return (validation); /* Return the _rultt_ of the validation */

    _oops_ = 1;
    do {
        _Un_Set_env_(_data_, _data_->_arguv_[_oops_]);
        _oops_++;
    } while (_oops_ <= _data_->_argu_c_);

    return (0); /* Return 0 if the environment variable is unset successfully */
}

/**
 * create_env_ndd - This function creates a _nww_ environment _nddee_
 *
 * Return: pointer to the _nww_ _nddee_
 */
_lst_ *create_env_ndd(void)
{
    size_t _oops_ = 0;
    _lst_ *_nddee_ = NULL;

    if (_env_you_[_oops_])
    {
        do {
            _add_nd_end_(&_nddee_, _env_you_[_oops_], 0);
            _oops_++;
        } while (_env_you_[_oops_]);
    }

    return (_nddee_); /* Return pointer to the _nww_ _nddee_ */
}

/**
 * _pop_env_lst_ - This function populates the environment list
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: 0 (success), 1 (error)
 */
int _pop_env_lst_(_info_OK *_data_)
{
    _data_->_my_env = create_env_ndd();

    return ((_data_->_my_env != NULL) ? 0 : 1); /* Return 0 if the environment list is populated successfully, 1 otherwise */
}




