/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:31:01 by tbui              #+#    #+#             */
/*   Updated: 2018/06/25 18:31:03 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void			*realloc(void *ptr, size_t size)
{
	t_block		*old_block;
	t_block		*new_block;

	new_block = NULL;
	old_block = NULL;
	if (!ptr)
		return (malloc(size));
	if (!check_pointer(ptr))
		return (NULL);
	old_block = (void *)ptr - sizeof(t_block);
	new_block = find_block(size);
	if (size < old_block->size)
		new_block->ptr = ft_memcpy(new_block->ptr, \
		old_block->ptr, size);
	else
		new_block->ptr = ft_memcpy(new_block->ptr, \
		old_block->ptr, old_block->size);
	return (new_block->ptr);
}
