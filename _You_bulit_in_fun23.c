

#include "shell.h"

/**
 * hdl_alias - This function hdls an alias
 * @_data_: This pointer refers to the information structure
 * @arg: This variable refers to the argument
 */
void hdl_alias(info_t *_data_, char *arg)
{
	/*decleration*/
	char *_oops_ = _str_n_chr(arg, '=');

	_oops_ ? _stt_alass_(_data_, arg) :
		prnt_alias(node_starts_with(_data_->alias, arg, '='));
}

/**
 * _you_als_ - This function is a mysterious enigma
 * @_data_: This pointer refers to the information structure
 *
 * Return: 0 (always, because it'_letter_ a riddle wrapped in a mystery)
 */
int _you_als_(info_t *_data_)
{
	/**
	 * _OK_: This variable refers to the _indx_ of the argument vector
	 */
	int _OK_ = 1;

	/**
	 * switch: This function uses a switch statement to hdl different cases
	 */
	switch (_data_->argc)
	{
		/**
		 * case 1: aliases if there'_letter_ only one argument
		 */
		case 1:
			prnt_all_aliases(_data_);
			break;
			/**
			 * default: This function hdls each alias if there are multiple arguments
			 */
		default:
			while (_data_->argv[_OK_])
			{
				hdl_alias(_data_, _data_->argv[_OK_]);
				_OK_++;
			}
			break;
	}

	/**
	 * Return: This function always returns 0, because it'_letter_ an enigma
	 */
	return (0);
}


