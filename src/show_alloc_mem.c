/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:36:58 by tbui              #+#    #+#             */
/*   Updated: 2018/06/25 18:37:00 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_mem_group *choose_zone(enum mem_zone zone)
{
	if (zone == Small)
		return (glob_memory.sml);
	else if (zone == Medium)
		return (glob_memory.med);
	return (NULL);
}

void show_alloc_zone(enum mem_zone zone)
{
	t_block *tmp_block;
	t_mem_group *tmp_group;

	tmp_group = choose_zone(zone);
	while (tmp_group)
	{
		tmp_block = tmp_group->mem;
		while (tmp_block)
		{
			ft_put_addr((void *)tmp_block->ptr);
			ft_putstr(" - ");
			ft_put_addr((void *)tmp_block->next);
			ft_putstr(" : ");
			ft_putnbr((int)tmp_block->size);
			ft_putendl(" bytes\n");
			if (tmp_block->free == TRUE)
				ft_putendl("block status: FREE\n");
			else
				ft_putendl("block status: NOT FREE\n");
			tmp_block = tmp_block->next;
		}
		tmp_group = tmp_group->next;
	}
}

void show_alloc_mem()
{
	t_block *tmp_block;

	ft_putstr("\nTINY : ");
	show_alloc_zone(Small);
	ft_putstr("\nSMALL : ");
	show_alloc_zone(Medium);
	ft_putstr("\nLARGE : ");
	tmp_block = glob_memory.large;
	while (tmp_block)
	{
		ft_put_addr(tmp_block->ptr);
		ft_putstr(" - ");
		ft_put_addr(tmp_block->next);
		ft_putstr(" : ");
		ft_putnbr((int)tmp_block->size);
		ft_putendl(" bytes\n");
		if (tmp_block->free == TRUE)
			ft_putendl("block status: FREE\n");
		else
			ft_putendl("block status: NOT FREE\n");
		tmp_block = tmp_block->next;
	}
}
