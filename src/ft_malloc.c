#include "../includes/ft_malloc.h"

t_memory glob_memory = {0, 0, 0, 0};

/*
** Finds a block of the size indicated by the user
** If this can't be done then the heap / linked list is to be extended
*/

// t_block find_block(t_block *last, size_t size)
// {
// 	t_block b = base; // this is to be a global variable
// 	while (b && !(b->free && b->size >= size))
// 	{
// 		*last = b;
// 		b = b->next;
// 	}
// 	return (b);
// }

t_mem_group *new_mem_group(t_mem_group *current, size_t size)
{
	t_mem_group *mem_group;
	t_block *tmp_block;

	mem_group = mmap(NULL, size, PROT, ANON, -1, 0);
	mem_group->size = size - sizeof(t_mem_group);
	mem_group->mem = (void *)mem_group + sizeof(t_mem_group);
	mem_group->next = NULL;
	tmp_block = mem_group->mem;
	tmp_block->ptr = (void *)tmp_block + sizeof(t_block);
	tmp_block->free = TRUE;
	tmp_block->next = NULL;
	tmp_block->size = mem_group->size - sizeof(t_block);
	if (current)
		printf("\nIf the current is present, then add the newly allocated mem_group to the next pointer of it.\n");
	return (mem_group);
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

		// initiate a small group size
		glob_memory.sml = new_mem_group(NULL, sz);
		// multiply the sz by 128
		sz = sz * 128;
		glob_memory.med = new_mem_group(NULL, sz);

		// initiate a medium group size

		printf("\n%d\n\n%d\n", (int)size, sz); // TESTING
	}

	// point a block towards the memory of a mem group

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