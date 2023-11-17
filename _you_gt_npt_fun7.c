#include "shell.h"









/**
 * sgn_Her_ - blocks ctrl-_coco_
 * @sig_num: the signal number
 *
 * Return: void
 */
void sgn_Her_(__attribute__((unused))int sig_num)
{
	/*decleration*/
	char *output = "\n$ ";

	if (output)
	{
		do {
			_pputt_char(*output == '\n' ? '\n' : *output == '$' ? '$' : ' ');
			output++;
		} while (*output);
	}
	_pputt_char(BUF_FLUSH);
}












































