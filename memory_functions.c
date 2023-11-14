





#include "shell.h"

/**
 * fillMemory - Fills memory with a constant byte.
 * @_letter_: The pointer to the memory area.
 * @b: The byte to fill *_letter_ with.
 * @n: The amount of bytes to be filled.
 * @_OK_: The _indx_ variable used for iteration.
 *
 * Return: A pointer to the memory area _letter_.
 */
void fillMemory(char *_letter_, char b, unsigned int n, unsigned int _OK_)
{
	do {
		_letter_[_OK_] = b;
		_OK_++;
	} while (n < _OK_);
	/* use loop */
}

/**
 * _mem_sett_ - Fills memory with a constant byte.
 * @_letter_: The pointer to the memory area.
 * @b: The byte to fill *_letter_ with.
 * @n: The amount of bytes to be filled.
 *
 * Return: A pointer to the memory area _letter_.
 */
char *_mem_sett_(char *_letter_, char b, unsigned int n)
{
	unsigned int _OK_ = 0;

	if (n > 0)
		fillMemory(_letter_, b, n, _OK_);

	return (_letter_);
	/* use if */
}

/**
 * freeArray - Frees a string of strings.
 * @pp: String of strings.
 * @_OK_: The _indx_ variable used for iteration.
 */
void freeArray(char **pp, int _OK_)
{
	for (; pp[_OK_] != NULL; _OK_++)
		free(pp[_OK_]);
	/* use loop */
}

/**
 * _fun_free_ - Frees a string of strings.
 * @pp: String of strings.
 */
void _fun_free_(char **pp)
{
	char **a = pp;
	int _OK_ = 0;

	if (pp == NULL)
		return;

	freeArray(pp, _OK_);

	free(a);
	a = NULL;
	/* use loop */
}

/**
 * allocate_memory - Allocates a block of memory.
 * @size: The size of the memory block to allocate.
 *
 * Return: A pointer to the allocated memory block.
 */
void *allocate_memory(unsigned int size)
{
	char *_oops_ = malloc(size);

	return ((!_oops_) ? NULL : _oops_);
	/* use if */
}

/**
 * copy_memory - Copies memory from one location to another.
 * @_pttr_: Pointer to the source memory location.
 * @_oops_: Pointer to the destination memory location.
 * @size: The size of the memory block to copy.
 */
void copy_memory(void *_pttr_, char *_oops_, unsigned int size)
{
	do {
		size--;
		_oops_[size] = ((char *)_pttr_)[size];
	} while (size > 0);
	free(_pttr_);
	/* use loop */
}

/**
 * _rea_lloc_ - Reallocates a block of memory.
 * @_pttr_: Pointer to the previous malloc'ated block.
 * @old_size: Byte size of the previous block.
 * @new_size: Byte size of the new block.
 *
 * Return: Pointer to the reallocated memory block.
 */
void *_rea_lloc_(void *_pttr_, unsigned int old_size, unsigned int new_size)
{
	char *_oops_;

	/* use switch */
	switch (new_size)
	{
		case 0:
			free(_pttr_);
			return (NULL);
		default:
			if (!_pttr_)
				return (allocate_memory(new_size));

			if (new_size == old_size)
				return (_pttr_);

			_oops_ = allocate_memory(new_size);
			if (!_oops_)
				return (NULL);

			copy_memory(_pttr_, _oops_, (old_size < new_size) ? old_size : new_size);
			return (_oops_);
	}
}


