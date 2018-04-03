#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "./libft.h"

typedef struct s_block *t_block;

struct s_block 
{
	size_t size;
	t_block next;
	int free;
};

#endif
