#include "../includes/ft_malloc.h"

void free(void *ptr)
{
	t_block *tmp_block;

	tmp_block = NULL;
	if (!ptr)
	{
		ft_putendl("Please provide a valid pointer.");
		return;
	}
	tmp_block = (void *)ptr - sizeof(t_block);
	tmp_block->free = TRUE;
	defragment(tmp_block);

}