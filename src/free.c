#include "../includes/ft_malloc.h"

void print(char *s)
{
	write(1, s, strlen(s));
}

void free(void *ptr)
{
	t_block *tmp_block;

	tmp_block = NULL;
	if (!ptr)
	{
		return;
	}
	tmp_block = ptr - sizeof(t_block);
	tmp_block->free = TRUE;
//	defragment(tmp_block);
}
