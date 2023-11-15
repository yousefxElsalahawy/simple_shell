





#include "shell.h"


/**
 * chk_cmd - This function chks if a command is valid
 * @_data_: This pointer refers to the _data_ struct
 * @_Cmd: This pointer refers to the command to be chked
 *
 * Return: Pointer to the command if it is valid, NULL otherwise
 */
char *chk_cmd(info_t *_data_, char *_Cmd)
{
	/* This function returns a pointer to the command if it is valid */
	return (((_str_len_(_Cmd) > 2) && _start_wh_
				(_Cmd, "./") && _my_i_cmdd_(_data_, _Cmd)) ? _Cmd : NULL);
}

/**
 * build_pth - This function builds a pth from a base pth and a command
 * @pth: This pointer refers to the base pth
 * @_Cmd: This pointer refers to the command
 *
 * Return: Pointer to the built pth
 */
char *build_pth(char *pth, char *_Cmd)
{
	/* use if */
	if (!*pth)
		_str_catt_(pth, _Cmd);
	else
	{
		_str_catt_(pth, "/");
		_str_catt_(pth, _Cmd);
	}
	/* This function returns a pointer to the built pth */
	return (pth);
}

/**
 * find_cmd_in_pth - This function finds a command in a pth
 * @_data_: This pointer refers to the _data_ struct
 * @pthstr: This pointer refers to the pth string
 * @_Cmd: This pointer refers to the command to be found
 * @_OK_: This variable is the current _indx_ in the pth string
 * @curr_pos: This variable is the current position in the pth string
 *
 * Return: Pointer to the command if it is found, NULL otherwise
 */
char *find_cmd_in_pth(info_t *_data_,
		char *pthstr, char *_Cmd, int _OK_, int curr_pos)
{
	char *pth;

	/* use loop */
	do {
		/* use if */
		if (!pthstr[_OK_] || pthstr[_OK_] == ':')
		{
			pth = _dupp_chart_(pthstr, curr_pos, _OK_);
			pth = build_pth(pth, _Cmd);
			if (_my_i_cmdd_(_data_, pth))
			{
				/* This function returns a pointer to the command if it is found */
				return (pth);
			}
			curr_pos = _OK_;
		}
		_OK_++;
	} while (pthstr[_OK_]);
	/* This function returns NULL if the command is not found */
	return (NULL);
}

/**
 * find_pth - This function finds a pth for a command
 * @_data_: This pointer refers to the _data_ struct
 * @pthstr: This pointer refers to the pth string
 * @_Cmd: This pointer refers to the command to find the pth for
 *
 * Return: Pointer to the pth if it is found, NULL otherwise
 */
char *find_pth(info_t *_data_, char *pthstr, char *_Cmd)
{
	int _OK_ = 0, curr_pos = 0;
	char *pth = chk_cmd(_data_, _Cmd);

	/* This function returns a pointer to the pth if it is found */
	return ((pth) ? pth : (pthstr ?
				find_cmd_in_pth(_data_, pthstr, _Cmd, _OK_, curr_pos) : NULL));
}



