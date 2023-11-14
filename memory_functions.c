#include "shell.h"

/**
 * fillMemory - Fills memory with a constant byte.
 * @s: The pointer to the memory area.
 * @b: The byte to fill *s with.
 * @n: The amount of bytes to be filled.
 * @i: The index variable used for iteration.
 *
 * Return: A pointer to the memory area s.
 */
void fillMemory(char *s, char b, unsigned int n, unsigned int i)
{
    do {
        s[i] = b;
        i++;
    } while (i < n);
    /* use loop */
}

/**
 * _memset - Fills memory with a constant byte.
 * @s: The pointer to the memory area.
 * @b: The byte to fill *s with.
 * @n: The amount of bytes to be filled.
 *
 * Return: A pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
    unsigned int i = 0;

    if (n > 0)
        fillMemory(s, b, n, i);

    return s;
    /* use if */
}

/**
 * freeArray - Frees a string of strings.
 * @pp: String of strings.
 * @i: The index variable used for iteration.
 */
void freeArray(char **pp, int i)
{
    for (; pp[i] != NULL; i++)
        free(pp[i]);
    /* use loop */
}

/**
 * ffree - Frees a string of strings.
 * @pp: String of strings.
 */
void ffree(char **pp)
{
    char **a = pp;
    int i = 0;

    if (pp == NULL)
        return;

    freeArray(pp, i);

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
    char *p = malloc(size);

    return ((!p) ? NULL : p);
    /* use if */
}

/**
 * copy_memory - Copies memory from one location to another.
 * @ptr: Pointer to the source memory location.
 * @p: Pointer to the destination memory location.
 * @size: The size of the memory block to copy.
 */
void copy_memory(void *ptr, char *p, unsigned int size)
{
    do {
        size--;
        p[size] = ((char *)ptr)[size];
    } while (size > 0);
    free(ptr);
    /* use loop */
}

/**
 * _realloc - Reallocates a block of memory.
 * @ptr: Pointer to the previous malloc'ated block.
 * @old_size: Byte size of the previous block.
 * @new_size: Byte size of the new block.
 *
 * Return: Pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *p;

    /* use switch */
    switch (new_size)
    {
        case 0:
            free(ptr);
            return NULL;
        default:
            if (!ptr)
                return allocate_memory(new_size);

            if (new_size == old_size)
                return ptr;

            p = allocate_memory(new_size);
            if (!p)
                return NULL;

            copy_memory(ptr, p, (old_size < new_size) ? old_size : new_size);
            return p;
    }
}


