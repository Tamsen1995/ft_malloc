#include "../includes/ft_malloc.h"

/*
** chooses the appropiate memory zone
** for the sought after allocation size.
*/

t_mem_group *choose_mem_group(size_t size)
{
	if (size <= SML)
		return (glob_memory.sml);
	else if (size <= MED)
		return (glob_memory.med);
	return (NULL);
}

t_block *large_size(size_t size)
{
	t_block *new_block;
	t_block *tmp_block;

	tmp_block = glob_memory.large;
	new_block = mmap(NULL, size + sizeof(t_block), PROT, ANON, -1, 0);
	new_block->ptr = (void *)new_block + sizeof(t_block);
	new_block->free = FALSE;
	new_block->size = size;
	if (!glob_memory.large)
	{
		glob_memory.large = new_block;
		return (new_block);
	}
	else
	{
		while (tmp_block->next)
			tmp_block = tmp_block->next;
		tmp_block->next = new_block;
		return (new_block);
	}
}

/*
** returns either a block of exactly the size looked for
** within the heap, or splits a block which is bigger
** and then returns.
*/

t_block *return_block(t_block *tmp_block, size_t size)
{
	if (tmp_block->size > size + sizeof(t_block))
		return (split_block(tmp_block, size));
	else if (tmp_block->size == size)
		return (tmp_block);
	return (NULL);
}

/*
** the size parameter implies the sought 
** after size for the memory allocation
*/

t_block *find_block(size_t size)
{
	t_block *tmp_block;
	t_mem_group *tmp_group;

	tmp_group = NULL;
	if (size <= SML || size <= MED)
		tmp_group = choose_mem_group(size);
	else
		return (large_size(size));
	while (tmp_group)
	{
		tmp_block = tmp_group->mem;
		// TODO : Degfragment the blocks here.
		while (tmp_block && (tmp_block->size < size + sizeof(t_block) || tmp_block->free == FALSE))
			tmp_block = tmp_block->next;
		if (tmp_block->size > size + sizeof(t_block) || tmp_block->size == size)
			return (return_block(tmp_block, size));
		else
			extend_heap(tmp_group, size);
		tmp_group = tmp_group->next;
	}
	return (NULL);
}