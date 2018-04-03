#include "../includes/ft_malloc.h"

/*
** Finds a block of the size indicated by the user
** If this can't be done then the heap / linked list is to be extended
*/

// t_block find_block(t_block *last, size_t size)
// {
// 	t_block b = base; // this is to be a global variable
// 	while (b && !(b->free && b->size >= size))
// 	{
// 		*last = b;
// 		b = b->next;
// 	}
// 	return (b);
// }

void *ft_malloc(size_t size)
{
	void *ptr;

	ptr = mmap(0, size + 1, PROT, ANON, -1, 0);

	return (ptr);
}

int main(int ac, char **argv)
{
	char *str;
	char c;
	int i;
	int nb;

	ac = 0; // TESTING
	c = argv[1][0];
	nb = atoi(argv[2]);
	str = (char *)ft_malloc((size_t)nb);
	i = 0;
	while (i < nb)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	printf("%s\n", str); // TESTING
	return (0);
}