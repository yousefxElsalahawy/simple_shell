



#include "shell.h"

/**
 * alien_translator - This function translates alien language
 * @_txt_: This variable refers to the alien string to be translated
 *
 * Return: Translated integer _vle_
 */
int alien_translator(char *_txt_)
{
	return (atoi(_txt_));
}

/**
 * interstellar_communicator - This function communicates interstellar messages
 * @_data_: This pointer refers to the information structure
 * @message: This variable refers to the message to be communicated
 */
void interstellar_communicator(info_t *_data_, char *message)
{
	_data_->status = 2;
	_ee_put_(message);
	_ee_put_(_data_->argv[1]);
	_e_put_char_('\n');
}

/**
 * galactic_chker - This function chks galactic conditions
 * @_data_: This pointer refers to the information structure
 *
 * Return: Exit chk status
 */
int galactic_chker(info_t *_data_)
{
	int exitchk = alien_translator(_data_->argv[1]);

	return ((exitchk == -1) ?
			(interstellar_communicator(_data_, "Illegal number: "), 1) : exitchk);
}

/**
 * cosmic_status_setter - This function sets cosmic status
 * @_data_: This pointer refers to the information structure
 * @exitchk: This variable refers to the exit chk status
 */
void cosmic_status_setter(info_t *_data_, int exitchk)
{
	_data_->err_num = exitchk;
}

/**
 * _you_ext_ - This function exits the shell
 * @_data_: This pointer refers to the information structure
 *
 * Return: Exit status
 */
int _you_ext_(info_t *_data_)
{
	int exitchk;

	if (_data_->argv[1])  /* If there is an exit argument */
	{
		exitchk = galactic_chker(_data_);
		switch (exitchk)
		{
			case 1:
				return (1);
			default:
				cosmic_status_setter(_data_, exitchk);
				return (-2);
		}
	}
	else
	{
		_data_->err_num = -1;
		return (-2);
	}
}



