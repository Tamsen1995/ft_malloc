#include "../includes/ft_malloc.h"

/*
** shows the status of the allocation zones

	TINY : 0xA0000
	0xA0020 - 0xA004A : 42 bytes
	0xA006A - 0xA00BE : 84 bytes
	SMALL : 0xAD000
	0xAD020 - 0xADEAD : 3725 bytes
	LARGE : 0xB0000
	0xB0020 - 0xBBEEF : 48847 bytes
	Total : 52698 bytes
*/

t_block *choose_zone(enum mem_zone zone)
{
	t_block *tmp_block;

	tmp_block = NULL;
	if (zone == Small)
	{
		ft_putstr("TINY : ");
		ft_put_addr((void *)glob_memory.sml);
		tmp_block = glob_memory.sml->mem;
	}
	else if (zone == Medium)
	{
		ft_putstr("SMALL : ");
		ft_put_addr((void *)glob_memory.med);
		tmp_block = glob_memory.med->mem;
	}
	return (tmp_block);
}

void show_alloc_zone(enum mem_zone zone)
{
	t_block *tmp_block;

	tmp_block = choose_zone(zone);
	while (tmp_block)
	{
		ft_put_addr((void *)tmp_block->ptr);
		ft_putstr(" - ");
		ft_put_addr((void *)tmp_block->next);
		ft_putstr(" : ");
		printf("%lu bytes\n", tmp_block->size);
		if (tmp_block->free == TRUE)
			ft_putendl("block status: FREE\n");
		else
			ft_putendl("block status: NOT FREE\n");
		tmp_block = tmp_block->next;
	}
}

void show_alloc_mem()
{
	t_block *tmp_block;

	show_alloc_zone(Small);
	show_alloc_zone(Medium);
	ft_putstr("\nLARGE : ");
	tmp_block = glob_memory.large;
	while (tmp_block)
	{
		printf("%p - ", tmp_block->ptr);
		printf("%p : ", tmp_block->next);
		printf("%lu bytes\n", tmp_block->size);
		if (tmp_block->free == TRUE)
			ft_putendl("block status: FREE\n");
		else
			ft_putendl("block status: NOT FREE\n");
		tmp_block = tmp_block->next;
	}
}