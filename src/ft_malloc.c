#include "../includes/ft_malloc.h"


// 1 t_block find_block (t_block *last , size_t size ){
// 2 t_block b=base;
// 3 while (b && !(b->free && b->size >= size )) {
// 4 *last = b;
// 5 b = b->next;
// 6 }
// 7 return (b);
// 8 }


/*
** Finds a block of the size indicated by the user
** If this can't be done then the heap / linked list is to be extended
*/
// t_block find_block (t_block *last , size_t size )


int main(int ac, char **argv)
{
	int i;
	int nb;
	char c;
	char *str;

	nb = atoi(argv[2]);
	c = argv[1][0];
	str = (char *)mmap(0, nb + 1, PROT, ANON, -1, 0);

	i = 0;
	ac = 0;
	while (i < nb)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	printf("%s\n", str);
	return (0);
}