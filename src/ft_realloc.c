#include "../includes/ft_malloc.h"

void *ft_realloc(void *ptr, size_t size)
{
	t_block *old_block;
	t_block *new_block;

	new_block = NULL;
	old_block = (void *)ptr - sizeof(t_block);
	new_block = find_block(size);
	if (size < old_block->size)
		new_block->ptr = ft_memcpy(new_block->ptr, old_block->ptr, size);
	else
		new_block->ptr = ft_memcpy(new_block->ptr, old_block->ptr, old_block->size);



//	printf("\n\n---> %lu\n", new_block->next->size); // TESTING

	//ft_putstr((char *)new_block->ptr);

	return (new_block->ptr);
	// at the end make sure to copy the new info.
}