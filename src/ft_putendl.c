/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:41:27 by tbui              #+#    #+#             */
/*   Updated: 2018/06/25 18:41:29 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

static	void	my_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putendl(char const *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		my_putchar(s[i]);
		i++;
	}
	my_putchar('\n');
}
