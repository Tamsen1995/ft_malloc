/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:37:04 by tbui              #+#    #+#             */
/*   Updated: 2018/06/25 18:37:06 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"
#define M (1024 * 1024)

int		main(void)
{
	char		*addr1;
	char		*addr2;
	char		*addr3;

	addr1 = (char *)malloc(16 * M);
	strcpy(addr1, "Bonjours\n");
	print(addr1);
	addr2 = (char *)malloc(16 * M);
	addr3 = (char *)realloc(addr1, 128 * M);
	addr3[127 * M] = 42;
	print(addr3);
	return (0);
}
