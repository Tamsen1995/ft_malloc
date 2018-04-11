#include "../includes/ft_malloc.h"

/*
** checks to see whether the given pointer 
** is actually in the pre_allocated memory zone or not
*/

T_BOOL check_pointer(void *ptr)
{
	t_block *tmp_block;

	tmp_block = NULL;
	if (!ptr)
		return (FALSE);
	if (((void *)glob_memory.sml <= ptr) && (ptr <= (void *)(glob_memory.sml + glob_memory.sml->size)))
		return (TRUE);
	else if (((void *)glob_memory.med <= ptr) && (ptr <= (void *)(glob_memory.med + glob_memory.med->size)))
		return (TRUE);
	tmp_block = glob_memory.large;
	while (tmp_block)
	{
		if (((void *)tmp_block <= ptr) && (ptr <= (void *)(tmp_block + tmp_block->size)))
			return (TRUE);
		tmp_block = tmp_block->next;
	}
	return (FALSE);
}

void *ft_realloc(void *ptr, size_t size)
{
	t_block *old_block;
	t_block *new_block;

	new_block = NULL;
	old_block = NULL;
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