/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defragment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:57:57 by tbui              #+#    #+#             */
/*   Updated: 2018/06/25 17:57:59 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

/*
** This traverses the memory blocks in order to defragment the memory
** starts from the beginning of the list and the traverses the entire memory
*/

void		defragment(t_block *block_list)
{
	t_block *tmp_block;

	tmp_block = block_list;
	while (tmp_block && tmp_block->next)
	{
		if (tmp_block && tmp_block->free == TRUE && \
		tmp_block->next && tmp_block->next->free == TRUE)
		{
			tmp_block->size = tmp_block->size + \
			tmp_block->next->size + sizeof(t_block);
			tmp_block->next = tmp_block->next->next;
			if (!tmp_block->next)
				break ;
		}
		tmp_block = tmp_block->next;
	}
}
