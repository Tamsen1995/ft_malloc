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

void defragment(t_block *block_list)
{
	t_block *tmp_block;

	tmp_block = block_list;
	while (tmp_block && tmp_block->next)
	{
		if (tmp_block->free == TRUE && tmp_block->next->free == TRUE)
		{
			tmp_block->size = tmp_block->size + tmp_block->next->size + sizeof(t_block);
			tmp_block->next = tmp_block->next->next;
		}
		tmp_block = tmp_block->next;
	}
}

/*
** splits a block to make a new one
** then points the old one to new block and returns the old one
*/

t_block *split_block(t_block *current, size_t size)
{
	t_block *new;

	new = (void *)current->ptr + size;
	new->ptr = (void *)new + sizeof(t_block);
	new->free = TRUE;
	new->size = current->size - size - sizeof(t_block);
	current->size = current->size - new->size - sizeof(t_block);
	current->free = FALSE;
	if (current->next)
		new->next = current->next;
	current->next = new;
	return (current);
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
	{
		tmp_block->free = FALSE;
		return (tmp_block);
	}
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
		defragment(tmp_block);
		while (tmp_block && (tmp_block->size < size + sizeof(t_block) || tmp_block->free == FALSE))
			tmp_block = tmp_block->next;
		if (tmp_block->size > size + sizeof(t_block) || tmp_block->size == size)
		{
			return (return_block(tmp_block, size));
		}
		else
			extend_heap(tmp_group, size);
		tmp_group = tmp_group->next;
	}
	return (NULL);
}