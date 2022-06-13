#include "main.h"
/**
 * _realloc - allocates mem and sets values to 0
 * @ptr: ptr to prev allocated mem
 * @oldsize: size prev alloc
 * @newsize: new size to alloc
 * Return: ptr to realloc mem
 */
void *_realloc(void *ptr, unsigned int oldsize, unsigned int newsize)
{
	void *p;
	unsigned int j;

	if (newsize == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (newsize == oldsize)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(newsize);
		if (p == NULL)
			return (NULL);
		else
			return (p);
	}

	p = malloc(newsize);
	if (p == NULL)
		return (NULL);
	for (j = 0; j < oldsize && j < newsize; j++)
		*((char *)p + j) = *((char *)ptr + j);
	free(ptr);

	return (p);
}
