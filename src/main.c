#include "../includes/ft_malloc.h"

void ft_free(void *ptr)
{
	t_block *tmp_block;

	tmp_block = NULL;
	if (!check_pointer(ptr))
	{
		ft_putendl("Please provide a valid pointer.");
		return;
	}
	tmp_block = (void *)ptr - sizeof(t_block);
	tmp_block->free = TRUE;
	defragment(tmp_block);
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

	ft_free(str);

	show_alloc_mem(); // TESTING
	//ft_putstr(str);   // TESTING
	return (0);
}