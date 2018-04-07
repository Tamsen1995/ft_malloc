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
		printf("\nIf the current is present, then add the newly allocated mem_group to the next pointer of it.\n");
	return (mem_group);
}

void find_block(size_t size)
{
	t_block *tmp_block;
	t_mem_group *tmp_mem_group;

	tmp_block = glob_memory.sml->mem;
	tmp_mem_group = glob_memory.sml;
	// higher level iteration which will
	// go through the mem_group (actual heap)
	while (tmp_mem_group)
	{
		// iterating until a block of an appropiate
		// size has been found
		while (tmp_block && (tmp_block->size < size + sizeof(t_block) || tmp_block->free == FALSE))
			tmp_block = tmp_block->next;
		tmp_mem_group = tmp_mem_group->next;

		// TODO : Implement all the functions in the printf strings
		if (tmp_block->size > size)
			split_block(tmp_block);
		else if (tmp_block->size == size)
			printf("\nreturn the block\n");
		else
			printf("extend the heap");
	}

	// if a block of a bigger size has been found then split the memory

	// if it is the same size then return

	printf("\n%lu\n", glob_memory.sml->size);								// TESTING
	printf("\ntmp_block->size: %lu\nsize: %lu\n\n", tmp_block->size, size); // TESTING
}

void *ft_malloc(size_t size)
{
	void *ptr;
	int sz;

	ptr = NULL;
	sz = 0;
	// initialize memory zones
	if (!glob_memory.init)
	{
		sz = getpagesize() * 13;
		glob_memory.sml = new_mem_group(NULL, sz);
		sz = sz * 128;
		glob_memory.med = new_mem_group(NULL, sz);
	}

	// block finding function
	find_block(size);

	// find a block of the appropiate size or bigger

	// if the block is bigger then split the block.

	return (ptr);
}

// struct t_block *allocate_block()
// {

// }

int main(void)
{
	char *str;

	str = (char *)ft_malloc(10);
	return (0);
}