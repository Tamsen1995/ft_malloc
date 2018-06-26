/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:59:05 by tbui              #+#    #+#             */
/*   Updated: 2018/06/25 17:59:07 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void free(void *ptr)
{
	t_block *tmp_block;

	tmp_block = NULL;
	if (!check_pointer(ptr))
		return;
	tmp_block = ptr - sizeof(t_block);
	tmp_block->free = TRUE;
	defragment(tmp_block);
}
