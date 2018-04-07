#ifndef FT_MALLOC_H
#define FT_MALLOC_H

#define PROT PROT_READ | PROT_WRITE
#define ANON MAP_PRIVATE | MAP_ANONYMOUS
//# define BLOCK_SIZE sizeof(struct s_block)

#include "./libft.h"

typedef struct s_mem_group
{
	void *mem;
	size_t size;
	struct s_mem_group *next;
} t_mem_group;

typedef struct s_block
{
	size_t size;
	struct s_block *next;
	T_BOOL free;
	void *ptr;
} t_block;

typedef struct s_memory
{
	char *init;
	t_mem_group *sml;
	t_mem_group *med;
	t_block *large;
} t_memory;

extern t_memory glob_memory;

#endif
