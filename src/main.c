#include "../includes/ft_malloc.h"

int main(void)
{
	char *str;
	int i;
	int nbr;
	int nbr2;

	nbr = 5000;
	nbr2 = 7000;
	i = 0;

	i = 0;
	str = (char *)ft_malloc(nbr);
	while (i < nbr)
	{
		str[i] = 'i';
		i++;
	}
	str[i] = '\0';

	str = (char *)ft_realloc(str, nbr2);

	ft_putstr(str);
	return (0);
}