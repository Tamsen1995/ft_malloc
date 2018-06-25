#include "../includes/ft_malloc.h"

void free(void *ptr)
{
	t_block *tmp_block;

	tmp_block = NULL;
	if (!check_pointer(ptr))
		return;
	tmp_block = ptr - sizeof(t_block);
	tmp_block->free = TRUE;
	defragment(tmp_block);

}
