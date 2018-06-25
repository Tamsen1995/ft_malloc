#include "../includes/ft_malloc.h"

/*
** The realloc() function tries to change the size of the 
** allocation pointed to by ptr to size, and returns ptr.  
** If there is not enough room to enlarge the memory allocation
** pointed to by ptr, realloc() creates a new allocation, 
** copies as much of the old data pointed to by ptr as will fit to the new allocation, frees the old allocation, and
** returns a pointer to the allocated memory.  
** If ptr is NULL, realloc() is identical to a call to malloc() for size bytes.  If size is zero and ptr is not NULL, a new, minimum
** sized object is allocated and the original object is freed.  
** When extending a region allocated with calloc(3), realloc(3) does not guarantee that the additional memory is also
** zero-filled.
*/

void *realloc(void *ptr, size_t size)
{
	t_block *old_block;
	t_block *new_block;

	new_block = NULL;
	old_block = NULL;
	if (!ptr)
		return (malloc(size));
	if (!check_pointer(ptr))
		return (NULL);
	old_block = (void *)ptr - sizeof(t_block);
	new_block = find_block(size);
	if (size < old_block->size)
		new_block->ptr = ft_memcpy(new_block->ptr, old_block->ptr, size);
	else
		new_block->ptr = ft_memcpy(new_block->ptr, old_block->ptr, old_block->size);
	return (new_block->ptr);
}