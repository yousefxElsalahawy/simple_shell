#include "shell.h"

/**
 * check_path - This function checks if a path is valid
 * @path: This pointer refers to the path to be checked
 * @st: This pointer refers to the stat struct
 *
 * Return: 1 if the path is valid, 0 otherwise
 */
int check_path(char *path, struct stat *st)
{
    int result = (!path || stat(path, st)) ? 0 : 1;
    /* This function returns the result of the path check */
    return (result);
}

/**
 * check_file_mode - This function checks if a file is regular
 * @st: This pointer refers to the stat struct
 *
 * Return: 1 if the file is regular, 0 otherwise
 */
int check_file_mode(struct stat *st)
{
    int result;

    /* use if */
    if (st->st_mode & S_IFREG)
        result = 1;
    else
        result = 0;

    /* This function returns the result of the file mode check */
    return (result);
}

/**
 * is_cmd - This function checks if a path is a command
 * @info: This pointer refers to the info struct
 * @path: This pointer refers to the path to be checked
 *
 * Return: 1 if the path is a command, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
    struct stat st;
    int path_check, mode_check;

    (void)info;
    path_check = check_path(path, &st);
    /* use if */
    if (path_check == 0)
        mode_check = 0;
    else
        mode_check = check_file_mode(&st);

    /* This function returns the result of the command check */
    return (mode_check);
}

/**
 * _COpYY_cHaRS_ - This function copies characters from one string to another
 * @pathstr: This pointer refers to the source string
 * @start: This variable is the starting index for copying
 * @stop: This variable is the stopping index for copying
 * @buf: This pointer refers to the destination string
 *
 * Return: Pointer to the destination string
 */
char *_COpYY_cHaRS_(char *pathstr, int start, int stop, char *buf)
{
    int index = start, buffer_index = 0;

    /* use loop */
    do {
        /* use if */
        if (pathstr[index] != ':') {
            buf[buffer_index] = pathstr[index];
            buffer_index++;
        }
        index++;
    } while (index < stop);

    buf[buffer_index] = '\0';
    /* This function returns a pointer to the destination string */
    return (buf);
}

/**
 * dup_chars - This function duplicates characters from one string to another
 * @pathstr: This pointer refers to the source string
 * @start: This variable is the starting index for copying
 * @stop: This variable is the stopping index for copying
 *
 * Return: Pointer to the destination string
 */
char *dup_chars(char *pathstr, int start, int stop)
{
    static char buffer[1024];

    /* This function returns a pointer to the destination string */
    return (_COpYY_cHaRS_(pathstr, start, stop, buffer));
}

/**
 * check_cmd - This function checks if a command is valid
 * @info: This pointer refers to the info struct
 * @cmd: This pointer refers to the command to be checked
 *
 * Return: Pointer to the command if it is valid, NULL otherwise
 */
char *check_cmd(info_t *info, char *cmd)
{
    /* This function returns a pointer to the command if it is valid */
    return (((_strlen(cmd) > 2) && starts_with(cmd, "./") && is_cmd(info, cmd)) ? cmd : NULL);
}

/**
 * build_path - This function builds a path from a base path and a command
 * @path: This pointer refers to the base path
 * @cmd: This pointer refers to the command
 *
 * Return: Pointer to the built path
 */
char *build_path(char *path, char *cmd)
{
    /* use if */
    if (!*path)
        _strcat(path, cmd);
    else {
        _strcat(path, "/");
        _strcat(path, cmd);
    }
    /* This function returns a pointer to the built path */
    return (path);
}

/**
 * find_cmd_in_path - This function finds a command in a path
 * @info: This pointer refers to the info struct
 * @pathstr: This pointer refers to the path string
 * @cmd: This pointer refers to the command to be found
 * @i: This variable is the current index in the path string
 * @curr_pos: This variable is the current position in the path string
 *
 * Return: Pointer to the command if it is found, NULL otherwise
 */
char *find_cmd_in_path(info_t *info, char *pathstr, char *cmd, int i, int curr_pos)
{
    char *path;

    /* use loop */
    do {
        /* use if */
        if (!pathstr[i] || pathstr[i] == ':') {
            path = dup_chars(pathstr, curr_pos, i);
            path = build_path(path, cmd);
            if (is_cmd(info, path))
                /* This function returns a pointer to the command if it is found */
                return (path);
            curr_pos = i;
        }
        i++;
    } while (pathstr[i]);
    /* This function returns NULL if the command is not found */
    return (NULL);
}

/**
 * find_path - This function finds a path for a command
 * @info: This pointer refers to the info struct
 * @pathstr: This pointer refers to the path string
 * @cmd: This pointer refers to the command to find the path for
 *
 * Return: Pointer to the path if it is found, NULL otherwise
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
    int i = 0, curr_pos = 0;
    char *path = check_cmd(info, cmd);

    /* This function returns a pointer to the path if it is found */
    return ((path) ? path : (pathstr ? find_cmd_in_path(info, pathstr, cmd, i, curr_pos) : NULL));
}
