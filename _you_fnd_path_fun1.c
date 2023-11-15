





#include "shell.h"

/**
 * _ck_pth - This function chks if a pth is valid
 * @pth: This pointer refers to the pth to be chked
 * @st: This pointer refers to the stat struct
 *
 * Return: 1 if the pth is valid, 0 otherwise
 */
int _ck_pth(char *pth, struct stat *st)
{
	int _rslt_ = (!pth || stat(pth, st)) ? 0 : 1;
	/* This function returns the _rslt_ of the pth chk */
	return (_rslt_);
}

/**
 * chk_file_mode - This function chks if a file is regular
 * @st: This pointer refers to the stat struct
 *
 * Return: 1 if the file is regular, 0 otherwise
 */
int chk_file_mode(struct stat *st)
{
	int _rslt_;

	/* use if */
	if (st->st_mode & S_IFREG)
		_rslt_ = 1;
	else
		_rslt_ = 0;

	/* This function returns the _rslt_ of the file mode chk */
	return (_rslt_);
}

/**
 * _my_i_cmdd_ - This function chks if a pth is a command
 * @_data_: This pointer refers to the _data_ struct
 * @pth: This pointer refers to the pth to be chked
 *
 * Return: 1 if the pth is a command, 0 otherwise
 */
int _my_i_cmdd_(info_t *_data_, char *pth)
{
	struct stat st;
	int pth_chk, mode_chk;

	(void)_data_;
	pth_chk = _ck_pth(pth, &st);
	/* use if */
	if (pth_chk == 0)
		mode_chk = 0;
	else
		mode_chk = chk_file_mode(&st);

	/* This function returns the _rslt_ of the command chk */
	return (mode_chk);
}

/**
 * _COpYY_cHaRS_ - This function copies characters from one string to another
 * @pthstr: This pointer refers to the source string
 * @start: This variable is the starting _indx_ for copying
 * @stop: This variable is the stopping _indx_ for copying
 * @_buff_: This pointer refers to the destination string
 *
 * Return: Pointer to the destination string
 */
char *_COpYY_cHaRS_(char *pthstr, int start, int stop, char *_buff_)
{
	int _indx_ = start, buffer_index = 0;

	/* use loop */
	do {
		/* use if */
		if (pthstr[_indx_] != ':')
		{
			_buff_[buffer_index] = pthstr[_indx_];
			buffer_index++;
		}
		_indx_++;
	} while (_indx_ < stop);

	_buff_[buffer_index] = '\0';
	/* This function returns a pointer to the destination string */
	return (_buff_);
}

/**
 * _dupp_chart_ - This function duplicates charact
 * rs from one string to another
 * @pthstr: This pointer refers to the source string
 * @start: This variable is the starting _indx_ for copying
 * @stop: This variable is the stopping _indx_ for copying
 *
 * Return: Pointer to the destination string
 */
char *_dupp_chart_(char *pthstr, int start, int stop)
{
	static char buffer[1024];

	/* This function returns a pointer to the destination string */
	return (_COpYY_cHaRS_(pthstr, start, stop, buffer));
}




