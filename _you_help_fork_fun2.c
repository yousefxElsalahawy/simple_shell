


#include "shell.h"


/**
 * initialize_blt_in_table - This function initializes the crafty_blt_in table
 *
 * Return: blt_intbl (pointer to the crafty_blt_in table)
 */
_cunning_table *initialize_blt_in_table(void)
{
	static _cunning_table blt_intbl[] = {
		{"exit", _you_ext_},
		{"env", _mEnv},
		{"help", _you_hlp_},
		{"history", _you_hstry_},
		{"setenv", _my_Set_env_},
		{"unsetenv", _mUnsetenv},
		{"cd", _you_cdd_},
		{"alias", _you_als_},
		{NULL, NULL}
	};
	return (blt_intbl); /* Returns a pointer to the crafty_blt_in table */
}

/**
 * exec_blt_in - This function execs a crafty_blt_in command
 * @_data_: This pointer refers to parameter and _data_ Struct
 * @blt_intbl: This pointer refers to the crafty_blt_in table
 * @_OK_: This is the _indx_ of the crafty_blt_in command in the table
 *
 * Return: blt_intbl[_OK_]._operat_(_data_) (success or error code)
 */
int exec_blt_in(info_t *_data_, _cunning_table *blt_intbl, int _OK_)
{
	_data_->line_count++;
	return (blt_intbl[_OK_]._operat_(_data_));
	/* Returns the return _vle_ of the crafty_blt_in function */
}

/**
 * find_blt_in - This function finds a crafty_blt_in command
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: built_in_ret (success or error code)
 */
int find_blt_in(info_t *_data_)
{
	int _OK_ = 0;
	int built_in_ret = -1;
	_cunning_table *blt_intbl = initialize_blt_in_table();

	while (blt_intbl[_OK_]._style && built_in_ret == -1) /*use loop */
	{
		built_in_ret = (_str_cmpp_(_data_->argv[0],
					blt_intbl[_OK_]._style) == 0) ?
			exec_blt_in(_data_, blt_intbl, _OK_) : -1;
		_OK_++;
	}
	return (built_in_ret);
	/* Returns the return _vle_ of the crafty_blt_in function */
}


/**
 * increment_line_count - This function increments the line _cnt_
 * @_data_: This pointer refers to parameter and _data_ Struct
 *
 * Return: void
 */
void increment_line_count(info_t *_data_)
{
	_data_->linecount_flag == 1 ? (_data_->line_count++,
			_data_->linecount_flag = 0) : 0;
}

/**
 * count_non_delim - This function counts non-delimiter characters
 * @_data_: This pointer refers to parameter and _data_ Struct
 * @_koK_: This pointer refers to the _cnt_ of non-delimiter characters
 *
 * Return: void
 */
void count_non_delim(info_t *_data_, int *_koK_)
{
	int _OK_ = 0;

	while (_data_->arg[_OK_]) /*use loop */
	{
		if (!_my_delm(_data_->arg[_OK_], " \t\n")) /*use if */
			*_koK_ += 1;
		_OK_++;
	}
}








