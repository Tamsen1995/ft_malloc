/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:29:13 by tbui              #+#    #+#             */
/*   Updated: 2018/06/25 18:29:15 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

static	void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putnbr(int n)
{
	unsigned int nbr;

	nbr = n;
	if (n < 0)
	{
		nbr = -n;
		ft_putchar('-');
	}
	if (nbr < 10)
		ft_putchar(nbr + '0');
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}
