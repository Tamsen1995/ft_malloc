#include "../includes/ft_malloc.h"

t_memory glob_memory = {0, 0, 0, 0};

/*
** Finds a block of the size indicated by the user
** If this can't be done then the heap / linked list is to be extended
*/

t_mem_group *new_mem_group(t_mem_group *current, size_t size)
{
	t_mem_group *mem_group;
	t_block *tmp_block;

	mem_group = mmap(NULL, size, PROT, ANON, -1, 0);
	mem_group->size = size - sizeof(t_mem_group);
	mem_group->mem = (void *)mem_group + sizeof(t_mem_group);
	mem_group->next = NULL;
	// point a block towards the memory of a mem group
	tmp_block = mem_group->mem;
	tmp_block->ptr = (void *)tmp_block + sizeof(t_block);
	tmp_block->free = TRUE;
	tmp_block->next = NULL;
	tmp_block->size = mem_group->size - sizeof(t_block);
	if (current)
		current->next = mem_group;
	return (mem_group);
}


void extend_heap(t_mem_group *mem_group, size_t size)
{
	size_t sz;

	sz = getpagesize() * 13;
	if (size <= SML)
		new_mem_group(mem_group, sz);
	else if (size <= MED)
		new_mem_group(mem_group, sz * 128);
}

void *ft_malloc(size_t size)
{
	t_block *ret;
	int sz;

	sz = 0;
	if (!glob_memory.init)
	{
		sz = getpagesize() * 13;
		glob_memory.sml = new_mem_group(NULL, sz);
		sz = sz * 128;
		glob_memory.med = new_mem_group(NULL, sz);
	}
	ret = find_block(size);
	if (ret)
		return (ret->ptr);
	else
		return (NULL);
}
