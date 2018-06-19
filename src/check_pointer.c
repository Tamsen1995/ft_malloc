#include "../includes/ft_malloc.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}


T_BOOL check_blk_addresses(void *ptr, t_mem_group *tmp_group)
{
	char ptr_addr[20];
	char blk_ptr_addr[20];
	t_block *tmp_block;

	tmp_block = NULL;
	ft_itoa_hex((uint64_t)ptr, 1, ptr_addr);
	while (tmp_group)
	{
		tmp_block = tmp_group->mem;
		while (tmp_block)
		{
			ft_itoa_hex((uint64_t)tmp_block->ptr, 1, blk_ptr_addr);
			if (ft_strcmp(ptr_addr, blk_ptr_addr) == 0)
				return (TRUE);
			tmp_block = tmp_block->next;
		}
		tmp_group = tmp_group->next;
	}
	return (FALSE);
}

/*
** checks to see whether the given pointer 
** is actually in the pre_allocated memory zone or not
*/

T_BOOL check_pointer(void *ptr)
{
	char ptr_addr[20];
	char blk_ptr_addr[20];
	t_block *tmp_block;
	t_mem_group *tmp_group;

	if (!ptr)
		return (FALSE);
	tmp_group = choose_zone(Small);
	if (check_blk_addresses(ptr, tmp_group) == TRUE)
		return (TRUE);
	tmp_group = choose_zone(Medium);
	if (check_blk_addresses(ptr, tmp_group) == TRUE)
		return (TRUE);
	tmp_block = glob_memory.large;
	while (tmp_block)
	{
		ft_itoa_hex((uint64_t)tmp_block->ptr, 1, blk_ptr_addr);
		if (ft_strcmp(ptr_addr, blk_ptr_addr) == 0)
			return (TRUE);
		tmp_block = tmp_block->next;
	}
	return (FALSE);
}
