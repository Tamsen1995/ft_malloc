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

void show_alloc_mem()
{
	t_block *tmp_block;

	ft_putstr("TINY : ");
	printf("%p\n", glob_memory.sml); // to be refactored
	tmp_block = glob_memory.sml->mem;
	while (tmp_block)
	{
		printf("%p - ", tmp_block->ptr);
		printf("%p : ", tmp_block->next);
		printf("%lu bytes\n", tmp_block->size);
		if (tmp_block->free == TRUE)
			ft_putendl("block status: FREE");
		else
			ft_putendl("block status: NOT FREE");
		tmp_block = tmp_block->next;
	}

	ft_putstr("\nSMALL : ");
	printf("%p\n", glob_memory.sml); // to be refactored

	tmp_block = glob_memory.med->mem;
	while (tmp_block)
	{
		printf("%p - ", tmp_block->ptr);
		printf("%p : ", tmp_block->next);
		printf("%lu bytes\n", tmp_block->size);
		if (tmp_block->free == TRUE)
			ft_putendl("block status: FREE");
		else
			ft_putendl("block status: NOT FREE");
		tmp_block = tmp_block->next;
	}

	ft_putstr("\nLARGE : ");
	printf("%p\n", glob_memory.sml); // to be refactored
	tmp_block = glob_memory.large;
	while (tmp_block)
	{
		printf("%p - ", tmp_block->ptr);
		printf("%p : ", tmp_block->next);
		printf("%lu bytes\n", tmp_block->size);
		if (tmp_block->free == TRUE)
			ft_putendl("block status: FREE");
		else
			ft_putendl("block status: NOT FREE");
		tmp_block = tmp_block->next;
	}
}

int main(void)
{
	char *str;
	int i;
	int nbr;
	int nbr2;

	nbr = 200;
	nbr2 = 180;
	i = 0;

	i = 0;

	str = (char *)ft_malloc(nbr + 1);
	while (i < nbr)
	{
		str[i] = 'i';
		i++;
	}
	str[i] = '\0';
	str = (char *)ft_realloc(str, nbr2 + 1);
	show_alloc_mem(); // TESTING
	//ft_putstr(str);   // TESTING
	return (0);
}