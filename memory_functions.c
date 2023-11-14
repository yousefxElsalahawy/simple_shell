



#include "shell.h"

/**
 * fillMemory - Fills memory with a constant byte.
 * @_aso_: The pointer to the memory area.
 * @_abo_: The byte to fill *_aso_ with.
 * @n: The amount of bytes to be filled.
 * @_oops_: The _indx_ variable used for iteration.
 *
 * Return: A pointer to the memory area _aso_.
 */
void fillMemory(char *_aso_, char _abo_, unsigned int n, unsigned int _oops_)
{
    do {
        _aso_[_oops_] = _abo_;
        _oops_++;
    } while (_oops_ < n);
    /* use loop */
}

/**
 * _mem_sett_ - Fills memory with a constant byte.
 * @_aso_: The pointer to the memory area.
 * @_abo_: The byte to fill *_aso_ with.
 * @n: The amount of bytes to be filled.
 *
 * Return: A pointer to the memory area _aso_.
 */
char *_mem_sett_(char *_aso_, char _abo_, unsigned int n)
{
    unsigned int _oops_ = 0;

    if (n > 0)
        fillMemory(_aso_, _abo_, n, _oops_);

    return _aso_;
    /* use if */
}

/**
 * freeArray - Frees a string of strings.
 * @apopo_: String of strings.
 * @_oops_: The _indx_ variable used for iteration.
 */
void freeArray(char **apopo_, int _oops_)
{
    for (; apopo_[_oops_] != NULL; _oops_++)
        free(apopo_[_oops_]);
    /* use loop */
}

/**
 * _fun_free_ - Frees a string of strings.
 * @apopo_: String of strings.
 */
void _fun_free_(char **apopo_)
{
    char **a = apopo_;
    int _oops_ = 0;

    if (apopo_ == NULL)
        return;

    freeArray(apopo_, _oops_);

    free(a);
    a = NULL;
    /* use loop */
}

/**
 * allocate_memory - Allocates a block of memory.
 * @_osize_: The _osize_ of the memory block to allocate.
 *
 * Return: A pointer to the allocated memory block.
 */
void *allocate_memory(unsigned int _osize_)
{
    char *_oqo_ = malloc(_osize_);

    return ((!_oqo_) ? NULL : _oqo_);
    /* use if */
}

/**
 * copy_memory - Copies memory from one location to another.
 * @_pttr_: Pointer to the source memory location.
 * @_oqo_: Pointer to the destination memory location.
 * @_osize_: The _osize_ of the memory block to copy.
 */
void copy_memory(void *_pttr_, char *_oqo_, unsigned int _osize_)
{
    do {
        _osize_--;
        _oqo_[_osize_] = ((char *)_pttr_)[_osize_];
    } while (_osize_ > 0);
    free(_pttr_);
    /* use loop */
}

/**
 * _rea_lloc_ - Reallocates a block of memory.
 * @_pttr_: Pointer to the previous malloc'ated block.
 * @old_size: Byte _osize_ of the previous block.
 * @new_size: Byte _osize_ of the _nww_ block.
 *
 * Return: Pointer to the reallocated memory block.
 */
void *_rea_lloc_(void *_pttr_, unsigned int old_size, unsigned int new_size)
{
    char *_oqo_;

    /* use switch */
    switch (new_size)
    {
        case 0:
            free(_pttr_);
            return NULL;
        default:
            if (!_pttr_)
                return allocate_memory(new_size);

            if (new_size == old_size)
                return _pttr_;

            _oqo_ = allocate_memory(new_size);
            if (!_oqo_)
                return NULL;

            copy_memory(_pttr_, _oqo_, (old_size < new_size) ? old_size : new_size);
            return _oqo_;
    }
}



