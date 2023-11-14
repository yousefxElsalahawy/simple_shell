#include "shell.h"

/**
 * handle_asm - This function performs some operation on file descriptor
 * @fd: Pointer to the file descriptor
 *
 * This function uses inline assembly to perform some operation on file descriptor.
 * It moves the value of the file descriptor to a register and adds 3 to it.
 */
void handle_asm(int *fd)
{
    /* use asm to perform some operation on the file descriptor */
	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));
}

/**
 * handle_file_open - This function handles opening a file
 * @ac: Argument count
 * @av: Argument vector
 * @fd: Pointer to the file descriptor
 * @info: Pointer to the info_t struct
 *
 * Return: 0 on success, EXIT_FAILURE on error
 */
int handle_file_open(int ac, char **av, int *fd, info_t *info)
{
    /* use if to check the argument count */
    if (ac != 2)
		return (0);

    *fd = open(av[1], O_RDONLY);

    /* use if to check if the file was opened successfully */
    if (*fd != -1)
	{
        info->readfd = *fd;
        return (0);
    }

    _eputs(av[0]);
    _eputs(": 0: There are wrong, Can't Open it");
    _eputs(av[1]);
    _eputchar('\n');
    _eputchar(BUF_FLUSH);

    /* use switch to handle different error cases */
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
 * handle_info - This function handles some information
 * @info: Pointer to the info_t struct
 *
 */
void handle_info(info_t *info)
{
    /* use loop to populate the environment list */
    populate_env_list(info);
    /* use loop to read the history */
    read_history(info);
}

/**
 * main - Entry point
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int ac, char **av)
{
	/*decleration*/
	info_t info[] = { INFO_INIT };
	int fd = 2;

	handle_asm(&fd);
	/*use if */
	if (handle_file_open(ac, av, &fd, info) == EXIT_FAILURE)
        return (EXIT_FAILURE);
		
	handle_info(info);
	hsh(info, av);

	return (EXIT_SUCCESS);
}

