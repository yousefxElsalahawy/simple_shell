




#include "shell.h"

/**
 * hdl_asm - This function performs some operation on file descriptor
 * @_fl_dir_: Pointer to the file descriptor
 *
 * This function uses inline assembly to perform some operation on file descriptor.
 * It moves the _vlle_ of the file descriptor to a register and adds 3 to it.
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
 * @ac: Argument _ocntt_
 * @_aav_: Argument vector
 * @_fl_dir_: Pointer to the file descriptor
 * @_data_: Pointer to the _info_OK struct
 *
 * Return: 0 on success, EXIT_FAILURE on error
 */
int hdl_file_open(int ac, char **_aav_, int *_fl_dir_, _info_OK *_data_)
{
    /* use if to chk the argument _ocntt_ */
    if (ac != 2)
		return (0);

    *_fl_dir_ = open(_aav_[1], O_RDONLY);

    /* use if to chk if the file was opened successfully */
    if (*_fl_dir_ != -1)
	{
        _data_->_read_fd_ = *_fl_dir_;
        return (0);
    }

    _ee_put_(_aav_[0]);
    _ee_put_(": 0: There are wrong, Can't Open it");
    _ee_put_(_aav_[1]);
    _e_put_char_('\n');
    _e_put_char_(_BUFFER_FLUSH);

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
 * @_data_: Pointer to the _info_OK struct
 *
 */
void hdl_info(_info_OK *_data_)
{
    /* use loop to populate the environment list */
    _pop_env_lst_(_data_);
    /* use loop to read the _my_hty */
    _rd_hstory_(_data_);
}

/**
 * main - Entry point
 * @ac: Argument _ocntt_
 * @_aav_: Argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int ac, char **_aav_)
{
	/*decleration*/
	_info_OK _data_[] = { _MY_INFO_INIT_ };
	int _fl_dir_ = 2;

	hdl_asm(&_fl_dir_);
	/*use if */
	if (hdl_file_open(ac, _aav_, &_fl_dir_, _data_) == EXIT_FAILURE)
        return (EXIT_FAILURE);

	hdl_info(_data_);
	hsh(_data_, _aav_);

	return (EXIT_SUCCESS);
}



