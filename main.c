






#include "shell.h"

/**
 * hdl_asm - This function performs some operation on file descriptor
 * @_fl_dir_: Pointer to the file descriptor
 *
 * This function uses inline assembly to perform some operation on file descriptor.
 * It moves the _vle_ of the file descriptor to a register and adds 3 to it.
 */
void hdl_asm(int *_fl_dir_)
{
	/* use asm to perform some operation on the file descriptor */
	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (_fl_dir_)
			: "r" (_fl_dir_));
}

/**
 * hdl_file_open - This function hdls opening a file
 * @ac: Argument _cnt_
 * @_av: Argument vector
 * @_fl_dir_: Pointer to the file descriptor
 * @_data_: Pointer to the info_t struct
 *
 * Return: 0 on success, EXIT_FAILURE on error
 */
int hdl_file_open(int ac, char **_av, int *_fl_dir_, info_t *_data_)
{
	/* use if to chk the argument _cnt_ */
	if (ac != 2)
		return (0);

	*_fl_dir_ = open(_av[1], O_RDONLY);

	/* use if to chk if the file was opened successfully */
	if (*_fl_dir_ != -1)
	{
		_data_->readfd = *_fl_dir_;
		return (0);
	}

	_ee_put_(_av[0]);
	_ee_put_(": 0: There are wrong, Can't Open it");
	_ee_put_(_av[1]);
	_e_put_char_('\n');
	_e_put_char_(BUF_FLUSH);

	/* use switch to hdl different error cases */
	switch (errno)
	{
		case EACCES:
			exit(126);
		case ENOENT:
			exit(127);
		default:
			return (EXIT_FAILURE);
	}
}

/**
 * hdl_info - This function hdls some information
 * @_data_: Pointer to the info_t struct
 *
 */
void hdl_info(info_t *_data_)
{
	/* use loop to populate the environment list */
	_pop_env_lst_(_data_);
	/* use loop to read the history */
	_rd_hstory_(_data_);
}

/**
 * main - Entry point
 * @ac: Argument _cnt_
 * @_av: Argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int ac, char **_av)
{
	/*decleration*/
	info_t _data_[] = { INFO_INIT };
	int _fl_dir_ = 2;

	hdl_asm(&_fl_dir_);
	/*use if */
	if (hdl_file_open(ac, _av, &_fl_dir_, _data_) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	hdl_info(_data_);
	_clever_hsh_(_data_, _av);

	return (EXIT_SUCCESS);
}

