/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:21:48 by tbui              #+#    #+#             */
/*   Updated: 2018/06/25 18:21:50 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void					*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t				i;
	unsigned char		*src_cpy;
	unsigned char		*dst_cpy;

	src_cpy = (unsigned char *)src;
	dst_cpy = (unsigned char *)dest;
	i = 0;
	while (i < size)
	{
		dst_cpy[i] = src_cpy[i];
		i++;
	}
	dst_cpy[i] = '\0';
	return (dst_cpy);
}
