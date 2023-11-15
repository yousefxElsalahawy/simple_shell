








#include "shell.h"

/**
 * is_null - Checks if a pointer is null.
 * @_pttr_: Address of the pointer to chk.
 *
 * Return: 1 if the pointer is null, otherwise 0.
 */
int is_null(void **_pttr_)
{
	/*use if */
	return (!_pttr_ || !*_pttr_ ? 1 : 0);
}

/**
 * free_and_nullify - Frees a pointer and sets it to NULL.
 * @_pttr_: Address of the pointer to free.
 */
void free_and_nullify(void **_pttr_)
{
	/*free for _pttr_ */
	free(*_pttr_);
	*_pttr_ = NULL;
}

/**
 * _bfun_free_ - Frees a pointer and sets it to NULL if it is not null.
 * @_pttr_: Address of the pointer to free.
 *
 * Return: 1 if the pointer was freed, otherwise 0.
 */
int _bfun_free_(void **_pttr_)
{
	/*use if */
	return (is_null(_pttr_) ? 0 : (free_and_nullify(_pttr_), 1));
}




