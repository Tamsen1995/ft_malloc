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

void print(char *s)
{
	write(1, s, strlen(s));
}

int main()
{
	char *addr;
//	char *ptr;
	int i;

	i = 0;
	addr = ft_malloc(16);
//	ft_free(NULL);
//	ft_free((void *)addr);
//	if (!(ptr = ft_realloc((void *)addr, 10)))
//		print("Bonjours\n");
	while (i < 10)
	{
		addr[i] = 'p';
		i++;
	}
	//print(addr); // TESTING
	
}
