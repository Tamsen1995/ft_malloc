#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# define PROT PROT_READ|PROT_WRITE
# define ANON MAP_PRIVATE|MAP_ANONYMOUS
//# define BLOCK_SIZE sizeof(struct s_block)

# include "./libft.h"

typedef struct s_block *t_block;

struct s_block 
{
	size_t size;
	t_block next;
	int free;
};

#endif
