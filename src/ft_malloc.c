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

/*
** splits a block to make a new one
** then points the old one to new block and return the old one
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

void extend_heap(t_mem_group *mem_group, size_t size)
{
	size_t sz;

	sz = getpagesize() * 13;
	if (size <= SML)
		new_mem_group(mem_group, sz);
	else if (size <= MED)
		new_mem_group(mem_group, sz * 128);
}

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
	// else
	// 	return (large_size(size));
	while (tmp_group)
	{
		tmp_block = tmp_group->mem;
		while (tmp_block && (tmp_block->size < size + sizeof(t_block) || tmp_block->free == FALSE))
			tmp_block = tmp_block->next;
		if (tmp_block->size > size + sizeof(t_block))
			return (split_block(tmp_block, size));
		else if (tmp_block->size == size)
			return (tmp_block);
		else
			extend_heap(tmp_group, size);
		tmp_group = tmp_group->next;
	}
	return (NULL);
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

int main(void)
{
	char *str;
	int i;
	int nbr;

	nbr = 4000;
	i = 0;
	str = (char *)ft_malloc(nbr);
	while (i < nbr)
	{
		str[i] = 'i';
		i++;
	}
	str[i] = '\0';
	ft_putstr(str);
	return (0);
}