#include "../includes/ft_malloc.h"

void *ft_realloc(void *ptr, size_t size)
{
	t_block *tmp_block;
	t_block *old_block;
	t_block *new_block;

	tmp_block = NULL;
	old_block = NULL;
	new_block = NULL;
	tmp_block = (void *)ptr - sizeof(t_block);
	old_block = tmp_block;
	while (tmp_block && (tmp_block->size < size + sizeof(t_block) || tmp_block->free == FALSE))
		tmp_block = tmp_block->next;
	if (tmp_block->size > size + sizeof(t_block) || tmp_block->size == size)
		new_block = return_block(tmp_block, size);

	// TODO : Refactor this somehow
	if (size < old_block->size)
		new_block->ptr = ft_memcpy(new_block->ptr, old_block->ptr, size);
	else
		new_block->ptr = ft_memcpy(new_block->ptr, old_block->ptr, old_block->size);
	return (new_block->ptr);
}