#ifndef FT_MALLOC_H
#define FT_MALLOC_H

# define SML 512
# define MED 4096
# define PROT PROT_READ | PROT_WRITE
# define ANON MAP_PRIVATE | MAP_ANONYMOUS
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

void *ft_malloc(size_t size);
void *ft_realloc(void *ptr, size_t size);
t_block *find_block(size_t size);
t_block *split_block(t_block *current, size_t size);
void extend_heap(t_mem_group *mem_group, size_t size);
t_block *return_block(t_block *tmp_block, size_t size);
void show_alloc_mem();


#endif
