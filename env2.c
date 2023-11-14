


#include "shell.h"

/**
 * refresh_environ - This function refreshes the environment
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: _data_->_env_you_ (success)
 */
char **refresh_environ(_info_OK *_data_)
{
   /* Check if _data_->_my_env is not NULL */
   if (_data_->_my_env)
   {
       /* Convert list to strings */
       _data_->_env_you_ = _lst_to_strng_(_data_->_my_env);
       /* Reset _myenv_edit_ _flg_ */
       _data_->_myenv_edit_ = 0;
   }
   /* Return the refreshed environment */
   return (_data_->_env_you_);
}

/**
 * _gtt_envrnn_ - This function gets the environment
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: refresh_environ(_data_) or _env_you_ (success)
 */
char **_gtt_envrnn_(_info_OK *_data_)
{
   /* Check if _data_->_my_env is not NULL */
   if (_data_->_my_env)
   {
       /* Convert list to strings */
       _data_->_env_you_ = _lst_to_strng_(_data_->_my_env);
       /* Reset _myenv_edit_ _flg_ */
       _data_->_myenv_edit_ = 0;
   }
   /* Return the refreshed environment */
   return (_data_->_env_you_);
}

/**
 * get_starting_string - This function gets the starting string
 * @_nddee_: This pointer refers to the _nddee_
 * @_ovvrr_: This variable is used for some specific purpose
 *
 * Return: _start_wh_(_nddee_->_txt_, _ovvrr_) (success)
 */
char *get_starting_string(_lst_ *_nddee_, char *_ovvrr_)
{
   /* Return the _rultt_ of _start_wh_ function */
   return (_start_wh_(_nddee_->_txt_, _ovvrr_));
}

/**
 * reset_environment - This function resets the environment
 * @_data_: This pointer refers to the _data_ Struct
 * @_oops_: This variable is used for some specific purpose
 * @_nddee_: This pointer refers to the _nddee_
 *
 * Return: _myenv_edit_ (success)
 */
int reset_environment(_info_OK *_data_, size_t *_oops_, _lst_ **_nddee_)
{
   /* Delete _nddee_ at _indx_ _oops_ and return the _rultt_ */
   int _myenv_edit_ = _dlt_nd_at_ndx(&(_data_->_my_env), *_oops_);

   /* Reset _oops_ and _nddee_ */
   *_oops_ = 0;
   *_nddee_ = _data_->_my_env;

   /* Return the _rultt_ of _myenv_edit_ */
   return (_myenv_edit_);
}

/**
 * _Un_Set_env_ - This function unsets the environment variable
 * @_data_: This pointer refers to the _data_ Struct
 * @_ovvrr_: This variable is used for some specific purpose
 *
 * Return: reset_environment or _data_->_myenv_edit_ (success)
 */
int _Un_Set_env_(_info_OK *_data_, char *_ovvrr_)
{
   /* Initialize _nddee_ and _oops_ */
   _lst_ *_nddee_ = _data_->_my_env;
   size_t _oops_ = 0;
   char *_oqo_;

   /* Check if _nddee_ or _ovvrr_ is NULL */
   if (!_nddee_ || !_ovvrr_)
       return (0);

   /* Loop through the ndds */
   do {
       _oqo_ = get_starting_string(_nddee_, _ovvrr_);

       /* Check if _oqo_ is not NULL and the first character is '=' */
       if (_oqo_ && *_oqo_ == '=')
           /* Reset the environment and return the _rultt_ */
           return (reset_environment(_data_, &_oops_, &_nddee_));

       _nddee_ = _nddee_->_nxt_;
       _oops_++;
   } while (_nddee_);

   /* Return the _rultt_ of _myenv_edit_ */
   return (_data_->_myenv_edit_);
}

/**
 * create_buf - This function creates a _obuf_fer_
 * @_ovvrr_: This variable is used for some specific purpose
 * @_vlle_: This variable is used for some specific purpose
 *
 * Return: _bbuuff_ (success)
 */
char *create_buf(char *_ovvrr_, char *_vlle_)
{
  /* Allocate memory for _bbuuff_ */
  char *_bbuuff_ = malloc(_str_len_(_ovvrr_) + _str_len_(_vlle_) + 2);

  /* Check if _bbuuff_ is not NULL */
  if (_bbuuff_)
  {

      _str_cpy(_bbuuff_, _ovvrr_);
      /* Concatenate '=' to _bbuuff_ */
      _str_catt_(_bbuuff_, "=");

      _str_catt_(_bbuuff_, _vlle_);
  }
  /* Return _bbuuff_ */
  return (_bbuuff_);
}

/**
 * find_var_in_env - This function finds a variable in the environment
 * @_nddee_: This pointer refers to the _nddee_
 * @_ovvrr_: This variable is used for some specific purpose
 * @_bbuuff_: This variable is used for some specific purpose
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: _nddee_ or NULL (success)
 */
_lst_ *find_var_in_env(_lst_ *_nddee_, char *_ovvrr_, char *_bbuuff_, _info_OK *_data_)
{
  char *_oqo_;

  /* Check if _nddee_ is not NULL */
  if (_nddee_)
  {
      /* Loop through the ndds */
      do {

          _oqo_ = _start_wh_(_nddee_->_txt_, _ovvrr_);

          /* Check if _oqo_ is not NULL and the first character is '=' */
          if (_oqo_ && *_oqo_ == '=')
          {
              /* Free _nddee_->_txt_ */
              free(_nddee_->_txt_);

              _nddee_->_txt_ = _bbuuff_;
              /* Set _myenv_edit_ to 1 */
              _data_->_myenv_edit_ = 1;
              /* Return _nddee_ */
              return (_nddee_);
          }

          _nddee_ = _nddee_->_nxt_;
      } while (_nddee_);
  }
  /* Return NULL */
  return (NULL);
}

/**
 * add_ndd_and_free_buf - This function adds a _nddee_ and frees the _obuf_fer_
 * @_my_env: This pointer refers to the Environment
 * @_bbuuff_: This variable is used for some specific purpose
 * @_data_: This pointer refers to the _data_ Struct
 *
 * Return: None
 */
void add_ndd_and_free_buf(_lst_ **_my_env, char *_bbuuff_, _info_OK *_data_)
{
  /* Add _nddee_ to the _End of _my_env */
  _add_nd_end_(_my_env, _bbuuff_, 0);

  free(_bbuuff_);
  /* Set _myenv_edit_ to 1 */
  _data_->_myenv_edit_ = 1;
}

/**
 * _set_ev_ - This function sets the environment variable
 * @_data_: This pointer refers to the _data_ Struct
 * @_ovvrr_: This variable is used for some specific purpose
 * @_vlle_: This variable is used for some specific purpose
 *
 * Return: 0 (success), 1 (error)
 */
int _set_ev_(_info_OK *_data_, char *_ovvrr_, char *_vlle_)
{
  /* Initialize _bbuuff_ */
  char *_bbuuff_;
  /* Initialize _nddee_ */
  _lst_ *_nddee_;


  if (!_ovvrr_ || !_vlle_)
      return (0);

  /* Create _bbuuff_ */
  _bbuuff_ = create_buf(_ovvrr_, _vlle_);
  /* Check if _bbuuff_ is NULL */
  if (!_bbuuff_)
      return (1);


  _nddee_ = find_var_in_env(_data_->_my_env, _ovvrr_, _bbuuff_, _data_);

  /* Check if _nddee_ is not NULL */
  return (_nddee_ ? 0 : (add_ndd_and_free_buf(&(_data_->_my_env), _bbuuff_, _data_), 0));
}




