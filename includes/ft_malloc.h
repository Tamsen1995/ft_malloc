#ifndef FT_MALLOC_H
#define FT_MALLOC_H

#define SML 512
#define MED 4096
#define PROT PROT_READ | PROT_WRITE
#define ANON MAP_PRIVATE | MAP_ANONYMOUS
//# define BLOCK_SIZE sizeof(struct s_block)

#include "./libft.h"

enum mem_zone
{
	Small,
	Medium,
	Large,
};

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
	char init;
	t_mem_group *sml;
	t_mem_group *med;
	t_block *large;
} t_memory;

void ft_free(void *ptr);
extern t_memory glob_memory;
void print(char *s);
void *ft_memcpy(void *dest, const void *src, size_t size);
void ft_putendl(char const *s);
void *ft_malloc(size_t size);
t_mem_group *choose_zone(enum mem_zone zone);
void *ft_realloc(void *ptr, size_t size);
t_block *find_block(size_t size);
t_block *split_block(t_block *current, size_t size);
void extend_heap(t_mem_group *mem_group, size_t size);
t_block *return_block(t_block *tmp_block, size_t size);
T_BOOL check_pointer(void *ptr);
void defragment(t_block *block_list);
void ft_put_addr(void *addr);
void show_alloc_mem();
void ft_itoa_hex(uint64_t n, int is_upcase, char *buff);

#endif
