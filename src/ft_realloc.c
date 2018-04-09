#include "../includes/ft_malloc.h"

void *ft_realloc(void *ptr, size_t size)
{
	t_block *tmp_block;

	tmp_block = NULL;
	// assume that ptr is a t_block linked list
	tmp_block = (t_block *)ptr;
	while (tmp_block && (tmp_block->size < size + sizeof(t_block) || tmp_block->free == FALSE))
		tmp_block = tmp_block->next;
	
	

	// cast it as one and iterate

	// if a block of appropiate size or bigger (in relation to size_t size) can be found then
	// copy info of old pointer into new pointer
	// and return that block

	// if not, then simply allocate a new block of memory which will fit.

	return (NULL); // for now
}