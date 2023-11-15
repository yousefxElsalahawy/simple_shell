



#include "shell.h"


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



